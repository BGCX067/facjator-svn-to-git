/*****************************************************************************/
/*                                                                           */
/*  Visualization Library                                                    */
/*  http://www.visualizationlibrary.com                                      */
/*                                                                           */
/*  Copyright 2005-2009 Michele Bosi, all rights are reserved                */
/*                                                                           */
/*  This file is part of Visualization Library.                              */
/*  It may only be used, modified, and distributed under the terms of the    */
/*  license specified in the LICENSE.TXT file. By continuing to use,         */
/*  modify or distribute this file you indicate that you have read the       */
/*  license and understand and accept it fully.                              */
/*                                                                           */
/*  Visualization Library is distributed in the hope that it will be useful, */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of           */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            */
/*  LICENSE.TXT file for more details.                                       */
/*                                                                           */
/*****************************************************************************/

#ifndef BaseDemo_INCLUDE_ONCE
#define BaseDemo_INCLUDE_ONCE

#include "vl/ReadPixels.hpp"
#include "vl/Time.hpp"
#include "vl/FontManager.hpp"
#include "vl/Geometry.hpp"
#include "vlut/Applet.hpp"
#include "vlut/GeometryPrimitives.hpp"

class BaseDemo: public vlut::Applet
{
public:
  BaseDemo()
  {
//    mMaxTime = 0;
//    mReadPixels = new vl::ReadPixels;
  }

  void initEvent()
  {
//    trackball()->setPivot(vl::vec3(0,0,0));
//    trackball()->setTransform(NULL);
  }
  void run() {}
  void shutdown() {}

  void keyPressEvent(unsigned short, vl::EKey key)
  {
/*
    if (key == vl::Key_F5)
    {
      mReadPixels->setup( 0, 0, openglContext()->width(), openglContext()->height(), vl::RDB_BACK_LEFT, false );
      vl::VisualizationLibrary::rendering()->renderingCallbacks()->push_back( mReadPixels.get() );
      mReadPixels->setRemoveAfterCall(true);
      vl::String filename = vl::Say( applicationName() + "-%n.jpg") << (int)vl::Time::currentTime();
      mReadPixels ->setSavePath( filename );
      vl::Log::print( vl::Say("Screenshot: '%s'\n") << filename );
    }
*/
  }

  void setMaxTime(float time) { /*mMaxTime = time;*/ }

  void runEvent()
  {
    vlut::Applet::runEvent();
/*
    if ( !mFPSTimer.isStarted() )
      mFPSTimer.start();
    else
    if (mFPSTimer.elapsed() > 1)
    {
      mFPSTimer.start();
      openglContext()->setWindowTitle( vl::Say("%s [%.1n]") << applicationName() << fps() );
      vl::Log::print( vl::Say("FPS=%.1n\n") << fps() );
    }

    if (mMaxTime != 0)
    {
      if ( !mApplicatinLifeTime.isStarted() )
        mApplicatinLifeTime.start();
      else
      if (mApplicatinLifeTime.elapsed() > mMaxTime)
        openglContext()->destroy();
    }
*/
  }

  const vl::String& applicationName() const { return mApplicationName; }
  void setApplicationName(const vl::String& app_name) { mApplicationName = app_name; }

protected:
  //vl::ref<vl::ReadPixels> mReadPixels;
  //vl::Time mApplicatinLifeTime;
  //vl::Time mFPSTimer;
  //float mMaxTime;
  vl::String mApplicationName;
};

#endif
