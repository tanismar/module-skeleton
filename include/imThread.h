/*
 * THREAD for ROS IMAGE DISPLAY ON YARP
 * Copyright (C) 2017 iCub Facility - Istituto Italiano di Tecnologia
 * Author: Tanis Mar
 * email: tanis.mar@iit.it
 * Permission is granted to copy, distribute, and/or modify this program
 * under the terms of the GNU General Public License, version 2 or any
 * later version published by the Free Software Foundation.
 *
 * A copy of the license can be found at
 * http://www.robotcub.org/icub/license/gpl.txt
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details
*/

#ifndef __OTFRIMTHRD_H__
#define __OTFRIMTHRD_H__

// Includes
#include <iostream>
#include <yarp/os/RateThread.h>
#include <yarp/os/Network.h>

class ImThread: public yarp::os::RateThread
{
protected:

public:
    // CONSTRUCTOR
    ImThread(int period, const std::string &_cloudname);
    // INIT
    virtual bool threadInit();
    // RUN
    virtual void run();
    // RELEASE
    virtual void threadRelease();
   
};

#endif

