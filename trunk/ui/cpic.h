#pragma once
#include <Fl/Fl_Widget.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Image.H>
#include <vlGraphics/Rendering.hpp>
#include <vlGraphics/ReadPixels.hpp>

enum PicID { PID_NONE = 0, PID_LEFT, PID_TOP };

class cpic : public Fl_Widget
{
public:
    cpic(int x, int y, int w, int h);
    ~cpic();
    void init(PicID _id);
    virtual void resize(int x, int y, int w, int h);

private:
    Fl_JPEG_Image *img_src;
    Fl_Image *img;
    PicID picid;
    vl::ref<vl::Rendering> rend;
    vl::ref<vl::ReadPixels> pix;

    int handle(int event);
    void draw();
    void popup();
    static void load_cb(Fl_Widget* w, void* p);
    inline void load_cb_i(Fl_Widget* w, void* p);
};
