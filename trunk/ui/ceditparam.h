#pragma once

#include <Fl/Fl_Window.H>

class Fl_Button;
class Fl_Hold_Browser;
class Fl_Choice;
class Fl_Menu_Item;
class Fl_Input;
class GrammarParam;

class ceditparam : public Fl_Window
{
public:
    ceditparam();
    ceditparam(int x, int y, int w, int h);
    ~ceditparam();

    void resize(int x, int y, int w, int h);

    GrammarParam* getNewParam();
    void setEditableParam(GrammarParam* param);

private:
    static void accept_param_cb(Fl_Widget* w, void* p);
    static void cancel_param_cb(Fl_Widget* w, void* p);

    Fl_Button* accept_param_btn;
    Fl_Button* cancel_param_btn;
    Fl_Input* name_input;
    Fl_Choice* type_choice;
    Fl_Input* value_input;
    GrammarParam* newParam;

    static Fl_Menu_Item menu_type[];
    static int ww;
    static int wh;
};
