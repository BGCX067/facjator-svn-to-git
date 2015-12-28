#pragma once

class ctext;
class cparams;
class MyApplet;

class Windows
{
private:
	Windows();

public:
    static ctext* scriptEditor;
    static cparams* params;
    static MyApplet* applet;
};
