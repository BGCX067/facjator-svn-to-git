#include "ui/window.h"
#include "face.h"
#include <iostream>

using namespace std;

int main (int argc, char ** argv)
{
    sface.create();

    cwindow window(1024, 768, "Face");
    window.resizable(window);
    window.show();
    window.prepareWindow();

    //fltk_window->initFLTKWindow("bla", format, 0, 0, 512, 512, 1.0/1.0);
    //vl::ref<vlFLTK::FLTKWindow> fltk_window = new vlFLTK::FLTKWindow("bla", 0, 0, 512, 512, 1.0/1.0);
    try
    {
        Fl::run();
    }
    catch (const char* msg)
    {
        cout << "Catch: " << msg << endl;
    }

    sface.close();

    return 0;
}
