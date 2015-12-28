#pragma once

#include <Fl/Fl_Window.H>

class Fl_Button;
class Fl_Hold_Browser;
class GrammarParam;

class cparams : public Fl_Window
{
public:
    cparams(int x, int y, int w, int h);
    ~cparams();

    void resize(int x, int y, int w, int h);

    void sync_list();
    void remove_selected();

    GrammarParam* get_selected_parameter();

private:
    static void add_param_cb(Fl_Widget*, void*);
    static void rem_param_cb(Fl_Widget*, void*);
    static void edit_param_cb(Fl_Widget*, void*);

    Fl_Hold_Browser *params_list;
    Fl_Button* add_param_btn;
    Fl_Button* rem_param_btn;
    Fl_Button* edit_param_btn;
};
