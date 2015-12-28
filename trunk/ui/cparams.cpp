#include <FL/Fl.h>
#include <FL/Fl_Button.H>
#include <FL/Fl_Hold_Browser.H>
#include "cparams.h"
#include "ceditparam.h"
#include "../Project.hpp"
#include "../Windows.hpp"
#include "../grammar/Grammar.hpp"
#include "../grammar/GrammarParam.hpp"

cparams::cparams(int x, int y, int w, int h) : Fl_Window(x, y, w, h)
{
    float diff = 5.0;
    float btn_w = (w-4*diff)/3.0f;
    params_list = new Fl_Hold_Browser(5, 28, w-5, h-60);
    add_param_btn = new Fl_Button(diff, 1, btn_w, 25, "Add");
    add_param_btn->callback(add_param_cb, 0);
    rem_param_btn = new Fl_Button(2*diff+btn_w, 1, btn_w, 25, "Remove");
    rem_param_btn->callback(rem_param_cb, 0);
    edit_param_btn = new Fl_Button(3*diff+2*btn_w, 1, btn_w, 25, "Edit");
    edit_param_btn->callback(edit_param_cb, 0);
    end();
}

cparams::~cparams()
{
}

void cparams::resize(int x, int y, int w, int h)
{
    float diff = 5.0;
    float btn_w = (w-4*diff)/3.0f;
    params_list->resize(5, 28, w-5, h-5);
    add_param_btn->resize(diff, 1, btn_w, 25);
    rem_param_btn->resize(2*diff+btn_w, 1, btn_w, 25);
    edit_param_btn->resize(3*diff+2*btn_w, 1, btn_w, 25);
    Fl_Window::resize(x, y, w, h);
}

void cparams::sync_list()
{
    params_list->clear();
    const Grammar::GrammarParameters& p = Project::get()->getGrammar()->getParams();
    for (Grammar::GrammarParameters::const_iterator it = p.begin(); it != p.end(); it++)
        params_list->add((*it)->toString().c_str(), *it);
}

void cparams::remove_selected()
{
    if (params_list->value())
    {
        GrammarParam* p = (GrammarParam*)params_list->data(params_list->value());
        if (p != 0)
            Project::get()->getGrammar()->removeParam(p->getName());
    }
    sync_list();
}

GrammarParam* cparams::get_selected_parameter()
{
    if (params_list->value())
    {
        GrammarParam* p = (GrammarParam*)params_list->data(params_list->value());
        return p;
    }
    else
        return 0;
}

void cparams::add_param_cb(Fl_Widget*, void*)
{
    ceditparam* wnd = new ceditparam();
    wnd->show();
    while(wnd->shown())
        Fl::wait();
    Fl::flush();
    GrammarParam* param = wnd->getNewParam();
    delete wnd;

    if (param != 0)
        Windows::params->sync_list();
}

void cparams::rem_param_cb(Fl_Widget*, void*)
{
    Windows::params->remove_selected();
}

void cparams::edit_param_cb(Fl_Widget* a, void* b)
{
    GrammarParam* p = Windows::params->get_selected_parameter();
    if (p != 0)
    {
        ceditparam* wnd = new ceditparam();
        wnd->setEditableParam(p);
        wnd->show();
        while(wnd->shown())
            Fl::wait();
        Fl::flush();
        delete wnd;

        Windows::params->sync_list();
    }
}
