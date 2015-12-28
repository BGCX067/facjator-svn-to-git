#include "cmap.h"
#include <iostream>
#include <FL/Fl_File_Chooser.H>
#include <FL/fl_draw.H>

using namespace std;

cmap::cmap(int x, int y, int w, int h, const char* fname) : Fl_Widget(x, y, w, h), img_src(fname)
{
    img = img_src.copy(w-5, h-5);
}

cmap::~cmap()
{
    delete img;
}

int cmap::handle(int event)
{
    switch(event)
    {
        case FL_PUSH:
//    ... mouse down event ...
//    ... position in Fl::event_x() and Fl::event_y()
        return 1;
        case FL_DRAG:
//    ... mouse moved while down event ...
        return 1;
        case FL_RELEASE:
//    ... mouse up event ...
        return 1;
        case FL_FOCUS :
        case FL_UNFOCUS :
//    ... Return 1 if you want keyboard events, 0 otherwise
        return 1;
        case FL_KEYBOARD:
//    ... keypress, key is in Fl::event_key(), ascii in Fl::event_text()
//    ... Return 1 if you understand/use the keyboard event, 0 otherwise...
        return 1;
        case FL_SHORTCUT:
//    ... shortcut, key is in Fl::event_key(), ascii in Fl::event_text()
//    ... Return 1 if you understand/use the shortcut event, 0 otherwise...
        return 1;
        default:
    // pass other events to the base class...
        return Fl_Widget::handle(event);
    }
}

void cmap::draw()
{
    Fl_Widget::draw_box(FL_EMBOSSED_BOX, FL_GRAY);
    if (img)
        img->draw(x()+3,y()+3, w(), h());
}
