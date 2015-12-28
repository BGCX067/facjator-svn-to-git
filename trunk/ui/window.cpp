#include "window.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../face.h"
#include "../Project.hpp"
#include "../Windows.hpp"
#include "../grammar/Script.hpp"
#include "../grammar/Grammar.hpp"
#include "ctext.h"
#include "cparams.h"
#include "../MyApplet.hpp"
#include <FL/Fl_Button.H>
#include <Fl/Fl_Input.H>
#include <vlCore/VisualizationLibrary.hpp>
#include <vlCore/VLSettings.hpp>
#include <vlGraphics/RenderingAbstract.hpp>
#include <vlGraphics/Rendering.hpp>
#include <vlGraphics/ReadPixels.hpp>

int cwindow::pos = 0;

cwindow::cwindow(int w, int h, const char* l) : Fl_Window(0, 0, w, h, l), menu(0, 0, w, 25),
    fpic(w*0.5+1, 26, w*0.25-1, h*0.3),
    rpic(w*0.75+1, 26, w*0.25-1, h*0.3),
    fmap(w*0.5+1, h*0.3+27, w*0.25-1, h*0.3, "front.jpg"),
    rmap(w*0.75+1, h*0.3+27, w*0.25-1, h*0.3, "right.jpg")
{
    text = new ctext(1, 26+h*0.6, w*0.5-1, h*0.4);
    compile_btn = new Fl_Button(w*0.5+1, 26+h*0.6, 100, 30, "Compile");
    raytrace_btn = new Fl_Button(w*0.5+1, 56+h*0.6, 100, 30, "Ray trace");
    size_input = new Fl_Input(w*0.5+1, 94+h*0.6, 100, 24, "");
    char tmp[32] = {0};
    snprintf(tmp, 10, "%d", sface.get_width());// itoa(sface.get_width(), tmp, 10);
    size_input->value(tmp);
    update_size_btn = new Fl_Button(w*0.5+1, 120+h*0.6, 100, 30, "Update size");
	reset_cam_btn = new Fl_Button(w*0.5+1, 150+h*0.6, 100, 30, "Reset camera");
	cam_nx_btn = new Fl_Button(w*0.5+1, 180+h*0.6, 50, 30, "Left");
	cam_x_btn = new Fl_Button(w*0.5+52, 180+h*0.6, 50, 30, "Right");
	cam_y_btn = new Fl_Button(w*0.5+1, 210+h*0.6, 50, 30, "Top");
	cam_ny_btn = new Fl_Button(w*0.5+52, 210+h*0.6, 50, 30, "Bottom");
	cam_z_btn = new Fl_Button(w*0.5+1, 240+h*0.6, 50, 30, "Front");
	cam_nz_btn = new Fl_Button(w*0.5+52, 240+h*0.6, 50, 30, "Back");
	cam_yp_btn = new Fl_Button(w*0.5+1, 270+h*0.6, 50, 30, "P");
	cam_ym_btn = new Fl_Button(w*0.5+52, 270+h*0.6, 50, 30, "M");
    compile_btn->callback(compile_cb, text);
    raytrace_btn->callback(raytrace_cb, text);
    update_size_btn->callback(update_size_cb, (void*)size_input);
    box3d = new vlFLTK::FLTKWindow(1, 26, w*0.5-1, h*0.6);
    params = new cparams(w*0.75+1, h*0.6+27, w*0.25-2, h-h*0.6-30);
	reset_cam_btn->callback(reset_cam_cb, (void*)box3d);
	cam_x_btn->callback(cam_pos_x_cb, (void*)box3d);
	cam_nx_btn->callback(cam_pos_nx_cb, (void*)box3d);
	cam_y_btn->callback(cam_pos_y_cb, (void*)box3d);
	cam_ny_btn->callback(cam_pos_ny_cb, (void*)box3d);
	cam_z_btn->callback(cam_pos_z_cb, (void*)box3d);
	cam_nz_btn->callback(cam_pos_nz_cb, (void*)box3d);
	cam_yp_btn->callback(cam_pos_yp_cb, (void*)box3d);
	cam_ym_btn->callback(cam_pos_ym_cb, (void*)box3d);
    end();

    Windows::scriptEditor = text;
    Windows::params = params;
    vl::globalSettings()->setVerbosityLevel(vl::VEL_VERBOSITY_DEBUG);
    vl::globalSettings()->setCheckOpenGLStates(true);
}

cwindow::~cwindow()
{
    //wyglada ze sam fltk zwalnia okna
    //delete box3d;
    //box3d = 0;
}

void cwindow::prepareWindow()
{
    box3d->prepareWindow();
    fpic.init(PID_LEFT);
    rpic.init(PID_TOP);
}

void cwindow::show()
{
    Fl_Window::show();
}

void cwindow::resize(int x, int y, int w, int h)
{
    menu.resize(menu.x(), menu.y(), w, menu.h());
    box3d->resize(box3d->x(), box3d->y(), w*0.5-1, h*0.6);
    fpic.resize(fpic.x(), fpic.y(), w*0.25-1, h*0.3);
    rpic.resize(rpic.x(), rpic.y(), w*0.25-1, h*0.3);
    fmap.resize(fmap.x(), fmap.y(), w*0.25-1, h*0.3);
    rmap.resize(rmap.x(), rmap.y(), w*0.25-1, h*0.3);
    text->resize(text->x(), text->y(), w*0.5-1,  h*0.4);
    params->resize(params->x(), params->y(), w*0.25-2, h-h*0.6-30);
    Fl_Window::resize(x, y, w, h);
}

void cwindow::compile_cb(Fl_Widget* w, void* a)
{
    sface.reset_raytracing();
    cwindow* win = (cwindow*)static_cast<ctext*>(a)->parent();
    std::string str = static_cast<ctext*>(a)->get_text();
    Project::get()->getGrammar()->getScript()->setSource(str);

    time_t start = time(NULL);
    try
    {
        if (Project::get()->getGrammar()->execute())
            std::cout << "grammar evaluation ok\n";
        else
            std::cout << "grammar evaluation failed\n";

        time_t end = time(NULL);
        std::cout.precision(4);
        std::cout << "evaluation time: " << difftime(end, start) << std::endl;
    }
    catch (std::exception& ex)
    {
        std::cout << "grammar evaluation failed\nexception: " << ex.what() << std::endl;
    }

    win->box3d->redraw();
    win->fpic.redraw();
    win->rpic.redraw();

    //if (str)
    // message box

}

void cwindow::raytrace_cb(Fl_Widget* w, void* a)
{
    sface.set_raytracing();
    cwindow* win = (cwindow*)static_cast<ctext*>(a)->parent();
    std::string str = static_cast<ctext*>(a)->get_text();
    Project::get()->getGrammar()->getScript()->setSource(str);

    try
    {
        if (Project::get()->getGrammar()->execute())
            std::cout << "grammar evaluation ok\n";
        else
            std::cout << "grammar evaluation failed\n";
    }
    catch (std::exception& ex)
    {
        std::cout << "grammar evaluation failed\nexception: " << ex.what() << std::endl;
    }

    win->box3d->redraw();

    //if (str)
    // message box
}

void cwindow::update_size_cb(Fl_Widget* w, void* a)
{
    Fl_Input* tmp = (Fl_Input*)a;
    int val = atoi(tmp->value());
    if (val != 0)
    {
        sface.set_width(val);
        sface.set_height(val);
        sface.set_depth(val);
        std::cout << "size updated to " << val << "\n";
    }
    else
        std::cout << "failed to update size\n";
}

void cwindow::reset_cam_cb(Fl_Widget*, void* a)
{
	vlFLTK::FLTKWindow* wnd = (vlFLTK::FLTKWindow*)a;
	sface.eye()    = vl::vec3(0,0,10); // camera position
    sface.center() = vl::vec3(0,0,0);   // point the camera is looking at
    sface.up()     = vl::vec3(0,1,0);   // up direction

	vl::mat4 view_mat = vl::mat4::getLookAt(sface.eye(), sface.center(), sface.up()).getInverse();
	Windows::applet->getRendering()->camera()->setViewMatrix(view_mat);
	if (wnd != 0)
		wnd->draw();
}

void cwindow::cam_pos_x_cb(Fl_Widget*, void* a)
{
	vlFLTK::FLTKWindow* wnd = (vlFLTK::FLTKWindow*)a;

    sface.center() = vl::vec3(0,0,0);   // point the camera is looking at
	sface.eye()    = vl::vec3(10,0,0); // camera position
	sface.up()     = vl::vec3(0,1,0);   // up direction

	vl::mat4 view_mat = vl::mat4::getLookAt(sface.eye(), sface.center(), sface.up()).getInverse();
	Windows::applet->getRendering()->camera()->setViewMatrix(view_mat);
	if (wnd != 0)
		wnd->draw();
}

void cwindow::cam_pos_nx_cb(Fl_Widget*, void* a)
{
	vlFLTK::FLTKWindow* wnd = (vlFLTK::FLTKWindow*)a;

    sface.center() = vl::vec3(0,0,0);   // point the camera is looking at
	sface.eye()    = vl::vec3(-10,0,0); // camera position
	sface.up()     = vl::vec3(0,1,0);   // up direction

	vl::mat4 view_mat = vl::mat4::getLookAt(sface.eye(), sface.center(), sface.up()).getInverse();
	Windows::applet->getRendering()->camera()->setViewMatrix(view_mat);
	if (wnd != 0)
		wnd->draw();
}

void cwindow::cam_pos_y_cb(Fl_Widget*, void* a)
{
	vlFLTK::FLTKWindow* wnd = (vlFLTK::FLTKWindow*)a;

    sface.center() = vl::vec3(0,0,0);   // point the camera is looking at
	sface.eye()    = vl::vec3(0,10,0); // camera position
	sface.up()     = vl::vec3(0,0,-1);   // up direction

	vl::mat4 view_mat = vl::mat4::getLookAt(sface.eye(), sface.center(), sface.up()).getInverse();
	Windows::applet->getRendering()->camera()->setViewMatrix(view_mat);
	if (wnd != 0)
		wnd->draw();
}

void cwindow::cam_pos_ny_cb(Fl_Widget*, void* a)
{
	vlFLTK::FLTKWindow* wnd = (vlFLTK::FLTKWindow*)a;

    sface.center() = vl::vec3(0,0,0);   // point the camera is looking at
	sface.eye()    = vl::vec3(0,-10,0); // camera position
	sface.up()     = vl::vec3(0,0,1);   // up direction

	vl::mat4 view_mat = vl::mat4::getLookAt(sface.eye(), sface.center(), sface.up()).getInverse();
	Windows::applet->getRendering()->camera()->setViewMatrix(view_mat);
	if (wnd != 0)
		wnd->draw();
}

void cwindow::cam_pos_z_cb(Fl_Widget*, void* a)
{
	vlFLTK::FLTKWindow* wnd = (vlFLTK::FLTKWindow*)a;

    sface.center() = vl::vec3(0,0,0);   // point the camera is looking at
	sface.eye()    = vl::vec3(0,0,10); // camera position
	sface.up()     = vl::vec3(0,1,0);   // up direction

	vl::mat4 view_mat = vl::mat4::getLookAt(sface.eye(), sface.center(), sface.up()).getInverse();
	Windows::applet->getRendering()->camera()->setViewMatrix(view_mat);
	if (wnd != 0)
		wnd->draw();
}

void cwindow::cam_pos_nz_cb(Fl_Widget*, void* a)
{
	vlFLTK::FLTKWindow* wnd = (vlFLTK::FLTKWindow*)a;

    sface.center() = vl::vec3(0,0,0);   // point the camera is looking at
	sface.eye()    = vl::vec3(0,0,-10); // camera position
	sface.up()     = vl::vec3(0,1,0);   // up direction

	vl::mat4 view_mat = vl::mat4::getLookAt(sface.eye(), sface.center(), sface.up()).getInverse();
	Windows::applet->getRendering()->camera()->setViewMatrix(view_mat);
	if (wnd != 0)
		wnd->draw();
}

void cwindow::cam_pos_yp_cb(Fl_Widget*, void* a)
{
	vlFLTK::FLTKWindow* wnd = (vlFLTK::FLTKWindow*)a;

    sface.center() = vl::vec3(0,0,0);   // point the camera is looking at
    if (pos < 360)
       pos++;
    vl::mat4 r = vl::mat4::getRotationXYZ(0, pos, 0);
    sface.eye() = r * vl::vec3(0, 0, 10);
    sface.up()  = vl::vec3(0, 1, 0);        //unicode = Fl::event_text();

	vl::mat4 view_mat = vl::mat4::getLookAt(sface.eye(), sface.center(), sface.up()).getInverse();
	Windows::applet->getRendering()->camera()->setViewMatrix(view_mat);
	if (wnd != 0)
		wnd->draw();
}

void cwindow::cam_pos_ym_cb(Fl_Widget*, void* a)
{
	vlFLTK::FLTKWindow* wnd = (vlFLTK::FLTKWindow*)a;

    sface.center() = vl::vec3(0,0,0);   // point the camera is looking at
    if (pos > 0)
       pos--;
    vl::mat4 r = vl::mat4::getRotationXYZ(0, pos, 0);
    sface.eye() = r * vl::vec3(0, 0, 10);
    sface.up()  = vl::vec3(0, 1, 0);        //unicode = Fl::event_text();

	vl::mat4 view_mat = vl::mat4::getLookAt(sface.eye(), sface.center(), sface.up()).getInverse();
	Windows::applet->getRendering()->camera()->setViewMatrix(view_mat);
	if (wnd != 0)
		wnd->draw();
}
