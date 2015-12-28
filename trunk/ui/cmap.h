#pragma once
#include <Fl/Fl_Widget.H>
#include <FL/Fl_JPEG_Image.H>

class cmap : public Fl_Widget
{
    private:
        Fl_JPEG_Image img_src;
        Fl_Image *img;

        int handle(int event);
        void draw();
        void popup();
        static void load_cb(Fl_Widget* w, void* p);
        inline void load_cb_i(Fl_Widget* w, void* p);
    public:
        cmap(int x, int y, int w, int h, const char* fname);
        ~cmap();
};
