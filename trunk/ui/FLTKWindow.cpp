#include "FLTKWindow.hpp"
#ifdef WIN32
#include <windows.h>
#endif
#include <vlCore/VisualizationLibrary.hpp>
#include <vlCore/Log.hpp>
#include <vlCore/Say.hpp>
#include <vlGraphics/OpenGL.hpp>
#include <vlGraphics/Applet.hpp>
#include "../MyApplet.hpp"
#include "../Windows.hpp"
#include <algorithm>
#include <map>

#define SQR(x) ((x)*(x))

using namespace vlFLTK;
using namespace vl;

namespace
{
  bool mUpdateFlag = true;
  bool mQuitFlag = false;

  std::map<int, vl::EKey> key_translation_map;

  int key_translation_vec[] =
  {
    0,0
  };
}

//-----------------------------------------------------------------------------
void FLTKWindow::Timer_CB(void *userdata)
{
    FLTKWindow *mygl = (FLTKWindow*)userdata;
    if (!mQuitFlag)
    {
//        if (mUpdateFlag || mygl->continuousUpdate())
//        {
//            if (mygl->takesevents())
//                mygl->dispatchRunEvent();
//            mUpdateFlag = false;
//        }
        mygl->redraw();
        Fl::repeat_timeout(mygl->fps, Timer_CB, userdata);
    }
}
//-----------------------------------------------------------------------------
FLTKWindow::~FLTKWindow()
{
    mQuitFlag = true;
    destroy();
}
//-----------------------------------------------------------------------------
void FLTKWindow::destroy()
{
    /*dispatchDestroyEvent();*/
    mQuitFlag = true;
    quitApplication();
}
//-----------------------------------------------------------------------------
FLTKWindow::FLTKWindow() : Fl_Gl_Window(0, 0, 0, 0)
{
    applet = 0;
    end();
}

FLTKWindow::FLTKWindow(int x, int y, int width, int height) : Fl_Gl_Window(x, y, width, height)
{
    applet = 0;
    end();
}

void FLTKWindow::prepareWindow()
{
    vl::OpenGLContextFormat format;
    format.setDoubleBuffer(true);
    format.setRGBABits(8,8,8,8);
    format.setDepthBufferBits(24);
    format.setStencilBufferBits(8);
    format.setFullscreen(false);
    format.setMultisampleSamples(16);
    format.setMultisample(true);

    applet = new MyApplet();
    applet->initialize();
    Windows::applet = applet;

    addEventListener(applet);
    applet->getRendering()->renderer()->setRenderTarget(renderTarget());
	applet->getRendering()->camera()->viewport()->setClearColor(vl::white);
    /* define the camera position and orientation */
    sface.eye()    = vl::vec3(0,0,10); // camera position
    sface.center() = vl::vec3(0,0,0);   // point the camera is looking at
    sface.up()     = vl::vec3(0,1,0);   // up direction
    mouse_x = -1;
    mouse_y = -1;
    vl::mat4 view_mat = vl::mat4::getLookAt(sface.eye(), sface.center(), sface.up()).getInverse();
    applet->getRendering()->camera()->setViewMatrix(view_mat);

    sface.window_width()  = w();
    sface.window_height() = h();

    initFLTKWindow(0, format, x(), y(), w(), h());
}

//-----------------------------------------------------------------------------
bool FLTKWindow::initFLTKWindow(const char* title, const vl::OpenGLContextFormat& info, int x, int y, int width, int height, float _fps)
{
    fps = _fps;
    resize(x, y, width, height);
    label(title);

    mRenderTarget->setWidth(width);
    mRenderTarget->setHeight(height);

    //tworzy dane os-specific powiazane z okne (np kontekst gl)
    Fl_Gl_Window::show();

    make_current();

    int m = FL_RGB;
    if (info.rgbaBits().a())
        m |= FL_ALPHA;

    if (info.accumRGBABits().r())
        m |= FL_ACCUM;

    if (info.doubleBuffer())
        m |= FL_DOUBLE;

    if (info.multisample())
        m |= FL_MULTISAMPLE;

    if (info.depthBufferBits())
        m |= FL_DEPTH;

    if (info.stencilBufferBits())
        m |= FL_STENCIL;

    mode(m);

    initGLContext();

  // init key translation map
    for(int i=0; key_translation_vec[i]; i+=2)
        key_translation_map[ key_translation_vec[i] ] = (vl::EKey)key_translation_vec[i+1];

    dispatchInitEvent();
    dispatchResizeEvent(width, height);

    applet->initViews();

    return true;
}
//-----------------------------------------------------------------------------

int FLTKWindow::handle(int event)
{
    vl::EKey key = vl::Key_None;
    unsigned short unicode = 0;

    switch(event)
    {
        case FL_PUSH:
            //    ... mouse down event ...
            //    ... position in Fl::event_x() and Fl::event_y()
            if (Fl::event_button() == 1)
            {
                dispatchMouseDownEvent(vl::LeftButton, Fl::event_x(), Fl::event_y());
                if (mouse_x == -1 || mouse_y == -1)
                {
                    mouse_x = Fl::event_x();
                    mouse_y = Fl::event_y();
                }
            }
            else
            if (Fl::event_button() == 2)
                dispatchMouseDownEvent(vl::RightButton, Fl::event_x(), Fl::event_y());
            else
            if (Fl::event_button() == 3)
                dispatchMouseDownEvent(vl::MiddleButton, Fl::event_x(), Fl::event_y());
            break;
        case FL_DRAG:
            //    ... mouse moved while down event ...
            if (Fl::event_button() == 1)
            {
                if (mouse_x != -1 && mouse_y != -1)
                {
                    int dx = mouse_x - Fl::event_x();
                    int dy = mouse_y - Fl::event_y();
                    mouse_x = Fl::event_x();
                    mouse_y = Fl::event_y();

                    vl::mat4 r = vl::mat4::getRotationXYZ(vl::fRAD_TO_DEG * dy * 0.02, vl::fRAD_TO_DEG * dx * 0.02, 0);
                    sface.eye() = r * sface.eye();
                    sface.up()  = r * sface.up();

                    vl::mat4 view_mat = vl::mat4::getLookAt(sface.eye(), sface.center(), sface.up()).getInverse();
                    applet->getRendering()->camera()->setViewMatrix(view_mat);

                    redraw();
                }
            }

            break;
        case FL_RELEASE:
            //    ... mouse up event ...
            if (Fl::event_button() == 1)
            {
                dispatchMouseUpEvent(vl::LeftButton, Fl::event_x(), Fl::event_y());
                mouse_x = -1;
                mouse_y = -1;
            }
            else
            if (Fl::event_button() == 2)
                dispatchMouseUpEvent(vl::RightButton, Fl::event_x(), Fl::event_y());
            else
            if (Fl::event_button() == 3)
               dispatchMouseUpEvent(vl::MiddleButton, Fl::event_x(), Fl::event_y());
            break;
        case FL_MOVE:
            dispatchMouseMoveEvent(Fl::event_x(), Fl::event_y());
            break;
        case FL_MOUSEWHEEL:
            dispatchMouseWheelEvent(Fl::event_dx());
            break;
        case FL_FOCUS:
        case FL_UNFOCUS:
            //    ... Return 1 if you want keyboard events, 0 otherwise
            break;
        case FL_SHORTCUT:
            //    ... shortcut, key is in Fl::event_key(), ascii in Fl::event_text()
            //    ... Return 1 if you understand/use the shortcut event, 0 otherwise...
            break;
        case FL_KEYDOWN:
            if(key_translation_map.find(Fl::event_key()) != key_translation_map.end())
               key = key_translation_map[Fl::event_key()];
            else
               key = vl::Key_Unknown;

            //unicode = Fl::event_text();

            dispatchKeyPressEvent(unicode, key);
            break;

        case FL_KEYUP:
            if(key_translation_map.find(Fl::event_key()) != key_translation_map.end())
               key = key_translation_map[Fl::event_key()];
            else
               key = vl::Key_Unknown;

            //unicodeu = Fl::event_text();

            dispatchKeyReleaseEvent(unicode, key);
            break;

        case FL_CLOSE:
            mQuitFlag = true;
            break;

        default:
            // pass other events to the base class...
            return Fl_Gl_Window::handle(event);

    }

    return 1;
}

void FLTKWindow::resize(int x, int y, int w, int h)
{
    sface.window_width()  = w;
    sface.window_height() = h;
    Fl_Gl_Window::resize(x, y, w, h);
    if (applet)
        applet->getRendering()->camera()->viewport()->set(0, 0, w, h);
    dispatchResizeEvent(w, h);
    redraw();
}

//-----------------------------------------------------------------------------
void FLTKWindow::quitApplication()
{
    mQuitFlag = true;
    eraseAllEventListeners();
}
//-----------------------------------------------------------------------------
void FLTKWindow::update()
{
    mUpdateFlag = true;
}
//-----------------------------------------------------------------------------
void FLTKWindow::setWindowTitle(const char* title)
{
    label(title);
}
//-----------------------------------------------------------------------------
void FLTKWindow::swapBuffers()
{
    swap_buffers();
}
//-----------------------------------------------------------------------------
void FLTKWindow::setPosition(int x, int y)
{
    resize(x, y, w(), h());
}
//-----------------------------------------------------------------------------
void FLTKWindow::draw()
{
    if (takesevents())
        dispatchRunEvent();
}
