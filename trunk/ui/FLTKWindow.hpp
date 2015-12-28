#pragma once

#include <vlGraphics/OpenGLContext.hpp>
#include <vlCore/String.hpp>
#include <vlCore/Vector4.hpp>
#include <FL/Fl.H>
#include <FL/Fl_Gl_Window.H>
#include "../grammar/terminal.hpp"

class MyApplet;

namespace vlFLTK
{
//-----------------------------------------------------------------------------
// FLTKWindow
//-----------------------------------------------------------------------------
  /**
   * The FLTKWindow class implements an OpenGLContext using the FLTK API.
   * @note
   * FLTK notifies Unicode codes only on key-press events not on release events.
  */
  class FLTKWindow: public vl::OpenGLContext, public Fl_Gl_Window
  {
  private:
    float fps;

    int mouse_x;
    int mouse_y;

  public:
    FLTKWindow();
    FLTKWindow(int x, int y, int width, int height);
    bool initFLTKWindow(const char* title, const vl::OpenGLContextFormat& info, int x=0, int y=0, int width=640, int height=480, float _fps=1.0/24.0);
    void prepareWindow();

    ~FLTKWindow();

    static void Timer_CB(void *userdata);

    virtual void swapBuffers();

    virtual int handle(int event);

    virtual void resize(int x, int y, int w, int h);

    virtual void draw();

    void destroy();

    //! Quits the event loop
    void quitApplication();

    void setPosition(int x, int y);
    void setWindowTitle(const char* title);

    void update();

    void makeCurrent() { make_current(); }

    MyApplet* applet;
  };
}
