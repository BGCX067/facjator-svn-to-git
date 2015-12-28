#include "ctext.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <FL/Fl.H>
#include <FL/Fl_Menu_Item.H>

extern "C"
{
  int compare_keywords(const void *a, const void *b)
  {
    return (strcmp(*((const char **)a), *((const char **)b)));
  }
}

using namespace std;

const Fl_Text_Display::Style_Table_Entry ctext::styletable[] = {     // Style table
  { FL_BLACK,      FL_COURIER,        FL_NORMAL_SIZE }, // A - Plain
  { FL_DARK_GREEN, FL_COURIER_ITALIC, FL_NORMAL_SIZE }, // B - Line comments
  { FL_DARK_GREEN, FL_COURIER_ITALIC, FL_NORMAL_SIZE }, // C - Block comments
  { FL_YELLOW,     FL_COURIER,        FL_NORMAL_SIZE }, // D - Strings
  { FL_DARK_RED,   FL_COURIER,        FL_NORMAL_SIZE }, // E - Directives
  { FL_DARK_RED,   FL_COURIER_BOLD,   FL_NORMAL_SIZE }, // F - Types
  { FL_BLUE,       FL_COURIER_BOLD,   FL_NORMAL_SIZE }  // G - Keywords
};

const char *ctext::code_keywords[] =
{
  "break", "do", "end", "else", "elseif", "function", "if", "local", "not", "or", "repeat", "return", "then", "until", "while"
};

const char *ctext::code_types[] =
{
  "boolean",
  "nil",
  "number",
  "string",
  "table",
  "thread",
  "userdata"
};

ctext::ctext(int x, int y, int w, int h, const char* l) : Fl_Text_Editor(x, y, w, h, l)
{
    changed  = 0;
    loading  = 0;
    isDirty = false;

    textbuf  = new Fl_Text_Buffer();
    stylebuf = new Fl_Text_Buffer();

    buffer(textbuf);
    textbuf->add_modify_callback(style_update, this);
    textbuf->call_modify_callbacks();
    textfont(FL_COURIER);
    textsize(12);

    highlight_data(stylebuf, styletable, sizeof(styletable) / sizeof(styletable[0]), 'A', style_unfinished_cb, 0);
}

ctext::~ctext()
{
    delete textbuf;
    delete stylebuf;
}

std::string ctext::get_text()
{
    char* tmp = textbuf->text();
    std::string ret(tmp);
    free(tmp);
    return ret;
}

void ctext::set_text(const std::string& _text)
{
    textbuf->remove(0, textbuf->length());
    textbuf->insert(0, _text.c_str());
    isDirty = true;
}

int ctext::handle(int e)
{
   switch (e)
   {
       case FL_PUSH:
           // RIGHT MOUSE PUSHED? Popup menu on right click
           if (Fl::event_button() == FL_RIGHT_MOUSE)
           {
               Fl_Menu_Item rclick_menu[] = {
                  { "Copy",   0, copy_cb,  (void*)this },
                  { "Paste",  0, paste_cb, (void*)this },
                  { 0 }
               };
               const Fl_Menu_Item *m = rclick_menu->popup(Fl::event_x(), Fl::event_y(), 0, 0, 0);
               if (m) m->do_callback(0, m->user_data());
                   return(1);          // (tells caller we handled this event)
           }
           break;
       case FL_RELEASE:
           // RIGHT MOUSE RELEASED? Mask it from Fl_Input
           if (Fl::event_button() == FL_RIGHT_MOUSE)
           {
               return(1);          // (tells caller we handled this event)
           }
           break;
    }
    return(Fl_Text_Editor::handle(e));
}

void ctext::copy_cb(Fl_Widget*, void *userdata)
{
    ctext *in = (ctext*)userdata;
//    in->copy(0);    // text selection clipboard
//    in->copy(1);    // copy/paste clipboard
    Fl_Text_Editor::kf_copy(0, in);
    Fl_Text_Editor::kf_copy(1, in);
    Fl_Text_Editor::kf_copy(2, in);
}

void ctext::paste_cb(Fl_Widget*, void *userdata)
{
    ctext *in = (ctext*)userdata;
    Fl_Text_Editor::kf_paste(0, in);
    Fl_Text_Editor::kf_paste(1, in);
    Fl_Text_Editor::kf_paste(2, in);
}

void ctext::style_unfinished_cb(int, void*)
{
}

void ctext::style_update(int pos, int nInserted, int nDeleted, int nRestyled, const char * deletedText, void *cbArg)
{
  ctext* t = static_cast<ctext*>(cbArg);
  t->isDirty = true;
  t->style_update_i(pos, nInserted, nDeleted, nRestyled, deletedText, cbArg);
}

void ctext::style_update_i(int        pos,        // I - Position of update
                  int        nInserted,  // I - Number of inserted chars
                  int        nDeleted,   // I - Number of deleted chars
                  int        /*nRestyled*/,  // I - Number of restyled chars
                  const char * /*deletedText*/,// I - Text that was deleted
                  void       *cbArg) {   // I - Callback data
  int   start,              // Start of text
    end;                // End of text
  char  last,               // Last style on line
    *style,             // Style data
    *text;              // Text data

  // If this is just a selection change, just unselect the style buffer...
  if (nInserted == 0 && nDeleted == 0) {
    stylebuf->unselect();
    return;
  }

  // Track changes in the text buffer...
  if (nInserted > 0) {
    // Insert characters into the style buffer...
    style = new char[nInserted + 1];
    memset(style, 'A', nInserted);
    style[nInserted] = '\0';

    stylebuf->replace(pos, pos + nDeleted, style);
    delete[] style;
  } else {
    // Just delete characters in the style buffer...
    stylebuf->remove(pos, pos + nDeleted);
  }

  // Select the area that was just updated to avoid unnecessary
  // callbacks...
  stylebuf->select(pos, pos + nInserted - nDeleted);

  // Re-parse the changed region; we do this by parsing from the
  // beginning of the previous line of the changed region to the end of
  // the line of the changed region...  Then we check the last
  // style character and keep updating if we have a multi-line
  // comment character...
  start = textbuf->line_start(pos);
//  if (start > 0) start = textbuf->line_start(start - 1);
  end   = textbuf->line_end(pos + nInserted);
  text  = textbuf->text_range(start, end);
  style = stylebuf->text_range(start, end);
  if (start==end)
    last = 0;
  else
    last  = style[end - start - 1];

//  printf("start = %d, end = %d, text = \"%s\", style = \"%s\", last='%c'...\n",
//         start, end, text, style, last);

  style_parse(text, style, end - start);

//  printf("new style = \"%s\", new last='%c'...\n",
//         style, style[end - start - 1]);

  stylebuf->replace(start, end, style);
  ((ctext *)cbArg)->redisplay_range(start, end);

  if (start==end || last != style[end - start - 1]) {
//    printf("Recalculate the rest of the buffer style\n");
    // Either the user deleted some text, or the last character
    // on the line changed styles, so reparse the
    // remainder of the buffer...
    free(text);
    free(style);

    end   = textbuf->length();
    text  = textbuf->text_range(start, end);
    style = stylebuf->text_range(start, end);

    style_parse(text, style, end - start);

    stylebuf->replace(start, end, style);
    ((ctext *)cbArg)->redisplay_range(start, end);
  }

  free(text);
  free(style);
}

void ctext::style_parse(const char *text, char *style, int length)
{
  char             current;
  int             col;
  int             last;
  char             buf[255],
             *bufptr;
  const char *temp;

  for (current = *style, col = 0, last = 0; length > 0; length --, text ++) {
    if (current == 'A') {
      // Check for directives, comments, strings, and keywords...
      if (col == 0 && *text == '#') {
        // Set style to directive
        current = 'E';
      } else if (strncmp(text, "--", 2) == 0) {
        current = 'B';
      } else if (strncmp(text, "/*", 2) == 0) {
        current = 'C';
      } else if (strncmp(text, "\\\"", 2) == 0) {
        // Quoted quote...
        *style++ = current;
        *style++ = current;
        text ++;
        length --;
        col += 2;
        continue;
      } else if (*text == '\"') {
        current = 'D';
      } else if (!last && islower(*text)) {
        // Might be a keyword...
        for (temp = text, bufptr = buf;
             islower(*temp) && bufptr < (buf + sizeof(buf) - 1);
             *bufptr++ = *temp++);

        if (!islower(*temp)) {
          *bufptr = '\0';

          bufptr = buf;

          if (bsearch(&bufptr, code_types,
                      sizeof(code_types) / sizeof(code_types[0]),
                      sizeof(code_types[0]), compare_keywords)) {
            while (text < temp) {
              *style++ = 'F';
              text ++;
              length --;
              col ++;
            }

            text --;
            length ++;
            last = 1;
            continue;
          } else if (bsearch(&bufptr, code_keywords,
                             sizeof(code_keywords) / sizeof(code_keywords[0]),
                             sizeof(code_keywords[0]), compare_keywords)) {
            while (text < temp) {
              *style++ = 'G';
              text ++;
              length --;
              col ++;
            }

            text --;
            length ++;
            last = 1;
            continue;
          }
        }
      }
    } else if (current == 'C' && strncmp(text, "*/", 2) == 0) {
      // Close a C comment...
      *style++ = current;
      *style++ = current;
      text ++;
      length --;
      current = 'A';
      col += 2;
      continue;
    } else if (current == 'D') {
      // Continuing in string...
      if (strncmp(text, "\\\"", 2) == 0) {
        // Quoted end quote...
        *style++ = current;
        *style++ = current;
        text ++;
        length --;
        col += 2;
        continue;
      } else if (*text == '\"') {
        // End quote...
        *style++ = current;
        col ++;
        current = 'A';
        continue;
      }
    }

    // Copy style info...
    if (current == 'A' && (*text == '{' || *text == '}')) *style++ = 'G';
    else *style++ = current;
    col ++;

    last = isalnum(*text) || *text == '.';

    if (*text == '\n') {
      // Reset column and possibly reset the style
      col = 0;
      if (current == 'B' || current == 'E') current = 'A';
    }
  }
}
