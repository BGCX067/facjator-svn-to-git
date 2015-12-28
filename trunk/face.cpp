#include "face.h"
#include <FL/Fl.H>
#include <FL/Fl_Shared_Image.H>
#include <vlCore/VisualizationLibrary.hpp>
#include <iostream>

face_singleton::face_singleton()
{
#if _DEBUG
    m_width  = 20;
    m_height = 20;
    m_depth  = 20;
#else
    m_width  = 64;
    m_height = 64;
    m_depth  = 64;
#endif

    m_voxels = 0;

    m_raytracing = false;

    m_image  = new vl::ImagePBO;

    prepare_voxels();
}

void face_singleton::set_voxels(float* vox)
{
    memcpy(m_voxels, vox, sizeof(float)*m_width*m_height*m_depth);
    m_update = true;
}

void face_singleton::create()
{
    fl_register_images();
    vl::VisualizationLibrary::init();
}

void face_singleton::close()
{
}

void face_singleton::prepare_voxels()
{
    if (m_voxels)
      delete[] m_voxels;

    m_voxels = new float[m_width*m_height*m_depth];

    memset(m_voxels, 0, sizeof(float) * m_width * m_height * m_depth);

    set_update();
}

face_singleton &get_face()
{
    static face_singleton f;
    return f;
}
