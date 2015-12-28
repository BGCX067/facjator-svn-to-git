#pragma once
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include <vector>
#include <string>

class ctext : public Fl_Text_Editor
{
    private:
        int changed;
        int loading;
        Fl_Text_Buffer *stylebuf;
        Fl_Text_Buffer *textbuf;

        static const Fl_Text_Display::Style_Table_Entry styletable[];
        static const char *code_keywords[];
        static const char *code_types[];

        ctext(ctext& c);

    public:
        ctext(int X, int Y, int W, int H, const char* l = 0);
        ~ctext();

        std::string get_text();
        void set_text(const std::string& _text);

        int handle(int e);

        bool isDirty;

    private:
        static void copy_cb(Fl_Widget*, void *userdata);
        static void paste_cb(Fl_Widget*, void *userdata);

        static void changed_cb(int, int nInserted, int nDeleted,int, const char*, void* v);
        static void style_unfinished_cb(int, void*);
        static void style_update(int pos, int nInserted, int nDeleted,int nRestyled, const char* deletedText, void* v);

        void changed_cb_i(int, int nInserted, int nDeleted,int, const char*, void* v);
        void style_update_i(int pos, int nInserted, int nDeleted,int nRestyled, const char* deletedText, void* v);

        void style_parse(const char *text, char *style, int length);
};
