#include "cmenu.h"
#include <iostream>
#include <string>
#include <FL/Fl_File_Chooser.H>
#include "window.h"
#include "../Project.hpp"
#include "../Windows.hpp"
#include "cparams.h"
#include "ctext.h"

using namespace std;

cmenu::cmenu(int x, int y, int w, int h, const char* l) : Fl_Menu_Bar(x, y, w, h, l)
{
    add("&File/&New",                 '\0',            new_cb,     this);
    add("&File/&Open",    FL_COMMAND + 'o',            open_cb,    this);
    add("&File/&Save",    FL_COMMAND + 's',            save_cb,    this);
    add("&File/Save &As", FL_COMMAND + FL_SHIFT + 's', save_as_cb, this);
    add("&Edit/&Undo",    FL_COMMAND + 'z',            undo_cb,    this);

    add("&Edit/&Redo",    FL_COMMAND + FL_SHIFT + 'z', redo_cb,    this);
    add("&Edit/Cu&t",     FL_COMMAND + 'x',            cut_cb,     this);
    add("&Edit/&Copy",    FL_COMMAND + 'c',            copy_cb,    this);
    add("&Edit/&Paste",   FL_COMMAND + 'v',            paste_cb,   this);
}

cmenu::~cmenu()
{
}

void cmenu::new_cb(Fl_Widget* w, void* p)
{
    cmenu* m = static_cast<cmenu*>(p);
    m->new_cb_i(w, p);
}

void cmenu::open_cb(Fl_Widget* w, void* p)
{
    cmenu* m = static_cast<cmenu*>(p);
    m->open_cb_i(w, p);
}

void cmenu::save_cb(Fl_Widget* w, void* p)
{
    cmenu* m = static_cast<cmenu*>(p);
    m->save_cb_i(w, p);
}

void cmenu::save_as_cb(Fl_Widget* w, void* p)
{
    cmenu* m = static_cast<cmenu*>(p);
    m->save_as_cb_i(w, p);
}

void cmenu::undo_cb(Fl_Widget* w, void* p)
{
    cmenu* m = static_cast<cmenu*>(p);
    m->undo_cb_i(w, p);
}

void cmenu::redo_cb(Fl_Widget* w, void* p)
{
    cmenu* m = static_cast<cmenu*>(p);
    m->redo_cb_i(w, p);
}

void cmenu::cut_cb(Fl_Widget* w, void* p)
{
    cmenu* m = static_cast<cmenu*>(p);
    m->cut_cb_i(w, p);
}

void cmenu::copy_cb(Fl_Widget* w, void* p)
{
    cmenu* m = static_cast<cmenu*>(p);
    m->copy_cb_i(w, p);
}

void cmenu::paste_cb(Fl_Widget* w, void* p)
{
    cmenu* m = static_cast<cmenu*>(p);
    m->paste_cb_i(w, p);
}

void cmenu::new_cb_i    (Fl_Widget*, void*)
{
    if (Project::get()->createGrammar("Nowa gramatyka"))
        cout << "new\n";
    else
        cout << "new failed\n";
    Windows::params->sync_list();
}

void cmenu::open_cb_i   (Fl_Widget*, void*)
{
    Fl_File_Chooser* fc = new Fl_File_Chooser(".","Text Files (*.txt)", Fl_File_Chooser::SINGLE, "File:");
    fc->preview(0);
    fc->show();
    while(fc->shown())
        Fl::wait();
    if (fc->value() == NULL)
	{
		fc->hide();
        Fl::flush();
        return;
	}
    std::string filename = fc->value();
    fc->hide();
    Fl::flush();
    Project::get()->load(filename);
	Project::get()->projectFile = filename;
    Windows::params->sync_list();
    cout << "open\n";
}

void cmenu::save_cb_i   (Fl_Widget*, void*)
{
	if (Project::get()->projectFile.length() > 0)
    {
        if (!Project::get()->save(Project::get()->projectFile))
            cout << "save failed\n";
    }
    else
    {
		Fl_File_Chooser* fc = new Fl_File_Chooser(".","Text Files (*.txt)", Fl_File_Chooser::CREATE |
			Fl_File_Chooser::SINGLE, "File:");
        fc->preview(0);
        fc->show();
        while(fc->shown())
            Fl::wait();
        if (fc->value() == NULL)
		{
			fc->hide();
			Fl::flush();
            return;
		}
        std::string filename = fc->value();
        fc->hide();
        Fl::flush();
        Project::get()->save(filename);
        Project::get()->projectFile = filename;
    }
    cout << "save\n";
}

void cmenu::save_as_cb_i(Fl_Widget*, void*)
{
	Fl_File_Chooser* fc = new Fl_File_Chooser(".","Text Files (*.txt)", Fl_File_Chooser::CREATE |
		Fl_File_Chooser::SINGLE, "File:");
    fc->preview(0);
    fc->show();
    while(fc->shown())
        Fl::wait();
    if (fc->value() == NULL)
	{
		fc->hide();
		Fl::flush();
        return;
	}
    std::string filename = fc->value();
    fc->hide();
    Fl::flush();
    Project::get()->save(filename);
    Project::get()->projectFile = filename;
    cout << "save as\n";
}

void cmenu::undo_cb_i   (Fl_Widget*, void*)
{
    cout << "undo\n";
}

void cmenu::redo_cb_i   (Fl_Widget*, void*)
{
    cout << "redo\n";
}

void cmenu::cut_cb_i    (Fl_Widget*, void* v)
{
    cwindow* e = (cwindow*)(((cmenu*)v)->parent());
    Fl_Text_Editor::kf_cut(0, e->text);
    cout << "cut\n";
}

void cmenu::copy_cb_i   (Fl_Widget*, void* v)
{
    cwindow* e = (cwindow*)(((cmenu*)v)->parent());
    Fl_Text_Editor::kf_copy(0, e->text);
    cout << "copy\n";
}

void cmenu::paste_cb_i  (Fl_Widget*, void* v)
{
    cwindow* e = (cwindow*)(((cmenu*)v)->parent());
    Fl_Text_Editor::kf_paste(0, e->text);
    cout << "paste\n";
}
