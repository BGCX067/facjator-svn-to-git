#include "cpic.h"
#include <iostream>
#include <FL/Fl_File_Chooser.H>
#include <FL/fl_draw.H>
#include "../Windows.hpp"
#include "../MyApplet.hpp"

using namespace std;

cpic::cpic(int x, int y, int w, int h) : Fl_Widget(x, y, w, h)
{
    img = 0;
    img_src = 0;
    picid = PID_NONE;
}

cpic::~cpic()
{
}

void cpic::init(PicID _id)
{
    if (picid != PID_NONE)
    {
        Windows::applet->removeRendering(rend);
    }
    picid = _id;
    rend = Windows::applet->addRendering();

    rend->renderer()->setRenderTarget(Windows::applet->getRendering()->renderer()->renderTarget());
    rend->renderer()->renderTarget()->setWidth(w());
    rend->renderer()->renderTarget()->setHeight(h());
    rend->camera()->viewport()->setWidth(w());
    rend->camera()->viewport()->setHeight(h());
    rend->camera()->setProjectionAsPerspective();
    rend->camera()->viewport()->setClearColor(vl::gray);
    vl::mat4 view_mat = vl::mat4::getLookAt(vl::vec3(10,0,0), vl::vec3(0,0,0), vl::vec3(0,1,0)).getInverse();
    rend->camera()->setViewMatrix(view_mat);

    vl::ref<vl::RenderTarget> rt = rend->renderer()->renderTarget();
    vl::EReadDrawBuffer rdb = rt->drawBuffers()[0];
    pix = new vl::ReadPixels(0, 0, rt->width(), rt->height(), rdb, 0, false);
    if (picid == PID_LEFT)
        pix->setSavePath("left.png");
    else if (picid == PID_TOP)
        pix->setSavePath("top.png");
    rend->onFinishedCallbacks()->push_back(pix.get());
}

void cpic::resize(int x, int y, int w, int h)
{
    Fl_Widget::resize(x, y, w, h);
    if (picid != PID_NONE)
    {
//        rend->renderer()->renderTarget()->setWidth(w);
//        rend->renderer()->renderTarget()->setHeight(h);
        rend->camera()->viewport()->setWidth(w);
        rend->camera()->viewport()->setHeight(h);
        rend->camera()->setProjectionAsPerspective();

        /*rend->onFinishedCallbacks()->clear();
        vl::ref<vl::RenderTarget> rt = rend->renderer()->renderTarget();
        vl::EReadDrawBuffer rdb = rt->drawBuffers()[0];
        pix = new vl::ReadPixels(0, 0, w, h, rdb, 0, false);
        if (picid == PID_LEFT)
            pix->setSavePath("left.png");
        else if (picid == PID_TOP)
            pix->setSavePath("top.png");
        rend->onFinishedCallbacks()->push_back(pix.get());*/
    }
}

int cpic::handle(int event)
{
    switch(event)
    {
        case FL_PUSH:
//    ... mouse down event ...
//    ... position in Fl::event_x() and Fl::event_y()
        if (Fl::event_button3()) // rclick
        {
            // popup menu
            popup();
        }
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

void cpic::draw()
{
    Fl_Widget::draw_box(FL_EMBOSSED_BOX, FL_GRAY);
    if (img)
        img->draw(x()+3,y()+3, w(), h());

    if (picid != PID_NONE && pix->image() != 0)
    {
        int iw = pix->image()->width();
        int ih = pix->image()->height();
        //fl_draw_image(pix->image()->pixels() + iw * ih * 4, x(), y(), iw,
        //    ih, 4, -iw * 4);
    }
}

void cpic::popup()
{
    Fl_Menu_Item rclick_menu[] = {
        { "Load",  0, load_cb, (void*)this },
        { 0 }
    };
    const Fl_Menu_Item *m = rclick_menu->popup(Fl::event_x(), Fl::event_y(), 0, 0, 0);
    if ( m ) m->do_callback(this, m->user_data());
}

void cpic::load_cb(Fl_Widget* w, void* p)
{
    cpic* m = static_cast<cpic*>(p);
    m->load_cb_i(w, p);
}

void cpic::load_cb_i(Fl_Widget* ww, void* p)
{
    // Create the file chooser, and show it
    Fl_File_Chooser chooser(".",                        // directory
                            "*.jpg",                        // filter
                            Fl_File_Chooser::SINGLE,    // chooser type
                            "Choose a picture");        // title
    chooser.show();

    while(chooser.shown())
        { Fl::wait(); }

    // User hit cancel?
    if ( chooser.value() == NULL )
        { cout << "(User hit 'Cancel')\n"; return; }

    string file = chooser.value();

    if (img_src) delete img_src;
    if (img) delete img;

    img_src = new Fl_JPEG_Image(file.c_str());
    img = img_src->copy(w()-5, h()-5);

    redraw();
}
