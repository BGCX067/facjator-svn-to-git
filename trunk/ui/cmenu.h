#pragma once
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Widget.H>

class cmenu : public Fl_Menu_Bar
{
    public:
        cmenu(int x, int y, int w, int h, const char* l = 0);
        ~cmenu();
    private:
        static void new_cb    (Fl_Widget*, void*);
        static void open_cb   (Fl_Widget*, void*);
        static void save_cb   (Fl_Widget*, void*);
        static void save_as_cb(Fl_Widget*, void*);

        static void undo_cb   (Fl_Widget*, void*);
        static void redo_cb   (Fl_Widget*, void*);
        static void cut_cb    (Fl_Widget*, void*);
        static void copy_cb   (Fl_Widget*, void*);
        static void paste_cb  (Fl_Widget*, void*);

        inline void new_cb_i    (Fl_Widget*, void*);
        inline void open_cb_i   (Fl_Widget*, void*);
        inline void save_cb_i   (Fl_Widget*, void*);
        inline void save_as_cb_i(Fl_Widget*, void*);

        inline void undo_cb_i   (Fl_Widget*, void*);
        inline void redo_cb_i   (Fl_Widget*, void*);
        inline void cut_cb_i    (Fl_Widget*, void*);
        inline void copy_cb_i   (Fl_Widget*, void*);
        inline void paste_cb_i  (Fl_Widget*, void*);

};
