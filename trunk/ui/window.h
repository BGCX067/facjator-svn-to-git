#pragma once

#include <FL/Fl_Window.H>
#include "cmenu.h"
#include "FLTKWindow.hpp"
#include "cpic.h"
#include "cmap.h"

class ctext;
class cparams;
class Fl_Input;
class Fl_Button;

class cwindow : public Fl_Window
{
    friend class cmenu;
    private:
        cmenu  menu;
        vlFLTK::FLTKWindow* box3d;
        cmap   fmap;  // front map
        cmap   rmap;  // right map
        ctext* text;
        cparams* params;
        Fl_Button* compile_btn;
        Fl_Button* raytrace_btn;
        Fl_Button* update_size_btn;
        Fl_Input* size_input;
		Fl_Button* reset_cam_btn;
		Fl_Button* cam_x_btn;
		Fl_Button* cam_nx_btn;
		Fl_Button* cam_y_btn;
		Fl_Button* cam_ny_btn;
		Fl_Button* cam_z_btn;
		Fl_Button* cam_nz_btn;
		Fl_Button* cam_yp_btn;
		Fl_Button* cam_ym_btn;

        static int pos;
    public:
        cpic   fpic;  // front picture
        cpic   rpic;  // right picture

        cwindow(int w, int h, const char* l);
        ~cwindow();

        void prepareWindow();

        void resize(int x, int y, int w, int h);

        void show();

    private:
        static void compile_cb(Fl_Widget*, void*);
        static void raytrace_cb(Fl_Widget*, void*);
        static void update_size_cb(Fl_Widget*, void*);
		static void reset_cam_cb(Fl_Widget*, void*);
		static void cam_pos_x_cb(Fl_Widget*, void* a);
		static void cam_pos_nx_cb(Fl_Widget*, void* a);
		static void cam_pos_y_cb(Fl_Widget*, void* a);
		static void cam_pos_ny_cb(Fl_Widget*, void* a);
		static void cam_pos_z_cb(Fl_Widget*, void* a);
		static void cam_pos_nz_cb(Fl_Widget*, void* a);
		static void cam_pos_yp_cb(Fl_Widget*, void* a);
		static void cam_pos_ym_cb(Fl_Widget*, void* a);
};
