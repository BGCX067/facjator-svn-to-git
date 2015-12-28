#include <FL/Fl_Button.H>
#include <FL/Fl_Hold_Browser.H>
#include <Fl/Fl_Choice.H>
#include <Fl/Fl_Menu_Item.H>
#include <Fl/Fl_Input.H>
#include <Fl/fl_ask.H>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include "ceditparam.h"
#include "../Project.hpp"
#include "../grammar/Grammar.hpp"
#include "../grammar/GrammarParam.hpp"

using namespace std;

Fl_Menu_Item ceditparam::menu_type[] = {
 {"FLOAT", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"INT", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"STRING", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

int ceditparam::ww = 330;
int ceditparam::wh = 200;

ceditparam::ceditparam() : Fl_Window(0, 0, ww, wh)
{
    accept_param_btn = new Fl_Button(ww-210, wh-35, 100, 30, "Ok");
    accept_param_btn->callback(accept_param_cb, this);
    cancel_param_btn = new Fl_Button(ww-105, wh-35, 100, 30, "Cancel");
    cancel_param_btn->callback(cancel_param_cb, this);
    name_input = new Fl_Input(110, 10, 205, 24, "Nazwa:");
    type_choice = new Fl_Choice(110, 45, 205, 24, "Typ parametru:");
    type_choice->down_box(FL_BORDER_BOX);
    type_choice->menu(menu_type);
//    type_choice->callback(type_choice_callback);
    value_input = new Fl_Input(110, 80, 205, 24, "Wartoœæ:");
    newParam = 0;
    end();
    set_modal();
}

ceditparam::ceditparam(int x, int y, int w, int h) : Fl_Window(x, y, w, h)
{
    accept_param_btn = new Fl_Button(300-210, 400-351, 100, 30, "Ok");
    accept_param_btn->callback(accept_param_cb, this);
    cancel_param_btn = new Fl_Button(300-105, 400-351, 100, 30, "Cancel");
    cancel_param_btn->callback(cancel_param_cb, this);
    newParam = 0;
    end();
    set_modal();
}

ceditparam::~ceditparam()
{
}

void ceditparam::resize(int x, int y, int w, int h)
{
    accept_param_btn->resize(w-210, h-35, 100, 30);
    cancel_param_btn->resize(w-105, h-35, 100, 30);
    Fl_Window::resize(x, y, w, h);
}

void ceditparam::accept_param_cb(Fl_Widget* w, void* p)
{
    ceditparam* wnd = static_cast<ceditparam*>(p);
    GrammarParam* existing = 0;

    if (strlen(wnd->name_input->value()) == 0)
    {
        fl_message("Nie podano nazwy parametru.");
        return;
    }
    else if (strlen(wnd->value_input->value()) == 0)
    {
        fl_message("Nie podano wartoœci parametru.");
        return;
    }
    else if ((existing = Project::get()->getGrammar()->getParam(wnd->name_input->value())) != 0 &&
        existing != wnd->newParam)
    {
        fl_message("Parametr o podanej nazwie jest juz zdefiniowany.");
        return;
    }

    if (wnd->newParam == 0)
    {
        //tworzymy nowy
        bool b = false;
        if (wnd->type_choice->value() == 0)
        {
            b = Project::get()->getGrammar()->addParam(wnd->name_input->value(),
                (float)atof(wnd->value_input->value()));
        }
        else if (wnd->type_choice->value() == 1)
        {
            b = Project::get()->getGrammar()->addParam(wnd->name_input->value(),
                atoi(wnd->value_input->value()));
        }
        else
        {
            b = Project::get()->getGrammar()->addParam(wnd->name_input->value(),
                std::string(wnd->value_input->value()));
        }
        if (!b)
        {
            fl_message("Nie uda³o siê dodaæ parametru.");
            return;
        }
        wnd->newParam = Project::get()->getGrammar()->getParam(wnd->name_input->value());
    }
    else
    {
        //zapisujemy zmiany w istniej¹cym
        wnd->newParam->setName(wnd->name_input->value());
        GrammarParamValue value;
        if (wnd->type_choice->value() == 0)
        {
            value.valueFloat = (float)atof(wnd->value_input->value());
        }
        else if (wnd->type_choice->value() == 1)
        {
            value.valueInt = atoi(wnd->value_input->value());
        }
        else
        {
            delete value.valueString;
            value.valueString = new std::string(wnd->value_input->value());
        }
        wnd->newParam->setValue(value);
    }
    wnd->hide();
}

void ceditparam::cancel_param_cb(Fl_Widget* w, void* p)
{
    ceditparam* wnd = static_cast<ceditparam*>(p);
    wnd->hide();
}

GrammarParam* ceditparam::getNewParam()
{
    return newParam;
}

void ceditparam::setEditableParam(GrammarParam* param)
{
    newParam = param;
    name_input->value(param->getName().c_str());

    std::stringstream s;
    if (param->getType() == GPT_STRING)
    {
        s << param->getValue().valueString->c_str();
        type_choice->value(2);
    }
    else if (param->getType() == GPT_FLOAT)
    {
        s << param->getValue().valueFloat;
        type_choice->value(0);
    }
    else
    {
        s << param->getValue().valueInt;
        type_choice->value(1);
    }
    type_choice->deactivate();
    value_input->value(s.str().c_str());
}
