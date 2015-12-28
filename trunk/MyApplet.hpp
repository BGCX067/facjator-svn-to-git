#pragma once
#include <iostream>
#include <vlCore/VisualizationLibrary.hpp>
#include <vlGraphics/Applet.hpp>
#include <vlGraphics/DrawPixels.hpp>
#include <vlVolume/MarchingCubes.hpp>
#include <vlGraphics/Light.hpp>
#include "face.h"

class RenderingView: public vl::Object
{
public:
    RenderingView(vl::vec3& _eye, vl::vec3& _center, vl::vec3& _up)
    {
        update(_eye, _center, _up);
    }

    void update(vl::vec3& _eye, vl::vec3& _center, vl::vec3& _up)
    {
        eye = _eye;
        center = _center;
        up = _up;
        inv_view = vl::mat4::getLookAt(eye, center, up).getInverse();
    }

    void setScreenBuffer(vl::ref<vl::ReadPixels> buffer) { screen_buffer = buffer; }

    vl::ref<vl::ReadPixels> getScreenBuffer() { return screen_buffer; }

    vl::mat4& getInvViewMatrix() { return inv_view; }

private:
    vl::vec3 eye;
    vl::vec3 center;
    vl::vec3 up;
    vl::mat4 inv_view;
    vl::ref<vl::ReadPixels> screen_buffer;
};

class MyApplet: public vl::Applet
{
public:
    MyApplet()
    {
        mThreshold = 0.44f;
        rvRight = new RenderingView(vl::vec3(10,0,0), vl::vec3(0,0,0), vl::vec3(0,1,0));
    }
    virtual void shutdown() {}

    // called once after the OpenGL window has been opened
    void initEvent()
    {
        mVolume = new vl::Volume;
        mDraw   = new vl::DrawPixels;
    }

    // called every frame
    virtual void updateEvent();

    void updateEvent(vl::ref<vl::Rendering> _rendering);

    void initViews();

    vl::ref<vl::Rendering> addRendering();
    void removeRendering(vl::ref<vl::Rendering> _rendering);

    vl::Rendering* getRendering() { return rendering()->as<vl::Rendering>(); }

protected:
    vl::ref<vl::Volume> mVolume;
    vl::ref<vl::DrawPixels> mDraw;
    vl::MarchingCubes mMarchingCubes;
    vl::ref<RenderingView> rvRight;
    std::vector<vl::ref<vl::Rendering> > mCustomRenderings;

    float mThreshold;
};
