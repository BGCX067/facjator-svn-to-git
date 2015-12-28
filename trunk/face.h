#pragma once

#include <string>
#include <vlCore/VisualizationLibrary.hpp>
#include <vlGraphics/ImagePBO.hpp>

class face_singleton
{
	private:
        int m_width;
        int m_height;
        int m_depth;

        bool m_update;

        float* m_voxels;

        bool m_raytracing;

        vl::ref<vl::ImagePBO> m_image;
        //
        vl::vec3 m_eye;
        vl::vec3 m_center;
        vl::vec3 m_up;

        int m_window_width;
        int m_window_height;

		face_singleton(const face_singleton&) {}
	public:
		face_singleton();
		~face_singleton() {}

        void set_width(int w)  { m_width  = w; prepare_voxels(); }
        void set_height(int h) { m_height = h; prepare_voxels(); }
        void set_depth(int d)  { m_depth  = d; prepare_voxels(); }

        int get_width()        { return m_width;  }
        int get_height()       { return m_height; }
        int get_depth()        { return m_depth;  }

        float* get_voxels()   { return m_voxels; }
        void set_voxels(float* vox);

        unsigned char* get_pixels(int w, int h) { m_image->allocate2D(w, h, 1, vl::IF_LUMINANCE, vl::IT_UNSIGNED_BYTE); return m_image->pixels(); }
        vl::ref<vl::ImagePBO> get_image() { return m_image; }

        void set_update()   { m_update = true;  }
        void reset_update() { m_update = false; }
        bool get_update()   { return m_update;  }

        void set_raytracing()   { m_raytracing = true;  }
        void reset_raytracing() { m_raytracing = false; }
        bool is_raytracing()    { return m_raytracing;  }

        vl::vec3& eye()    { return m_eye; }
        vl::vec3& center() { return m_center; }
        vl::vec3& up()     { return m_up; }

        int& window_width() { return m_window_width; }
        int& window_height() { return m_window_height; }

		void create();
		void close();
    private:

        void prepare_voxels();
};

face_singleton &get_face();



#define sface get_face()
