/*
 * MODULE_SKELETON
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

#include <MODULE_SKELETON.h>

using namespace std;
using namespace yarp::os;
using namespace yarp::sig;
using namespace yarp::math;


/************************* RF overwrites ********************************/
/************************************************************************/
bool  MODULE_SKELETON::configure(ResourceFinder &rf)
{
    // add and initialize the port to send out the features via thrift.
    string name = rf.check("name",Value("MODULE_SKELETON")).asString().c_str();
    rf.setDefaultContext("MODULE_SKELETON");

    // Check default .ini variables
    verb = rf.check("verbose",Value(true)).asBool();

    //open ports
    bool ret = true;
    ret = ret && dataInPort.open(("/"+name+"/data:i").c_str());         // Receives data
    ret = ret && labelsInPort.open(("/"+name+"/labels:i").c_str());     // Receives labels for data
    ret = ret && labelOutPort.open(("/"+name+"/labels:o").c_str());     // Streams predicted labels

    ret = ret && imgInPort.open(("/"+name+"/img:i").c_str());           // Receives images
    ret = ret && imgOutPort.open(("/"+name+"/img:o").c_str());          // Streams images
    if (!ret){
        printf("Problems opening ports\n");
        return false;
    }

    // open rpc ports
    bool retRPC = true;
    retRPC =  retRPC && rpcInPort.open("/"+name+"/rpc:i");
    if (!retRPC){
        printf("Problems opening ports\n");
        return false;
    }
    attach(rpcInPort);

    /* Module rpc parameters */
    closing = false;

    /*Init variables*/
    activeLabel = -1;


    cout << endl << "Configuring done."<<endl;

    return true;
}

bool  MODULE_SKELETON::updateModule()
{
    // read if there is any new affordance data. If so, update aff for active label
    Bottle *affBottle = dataInPort.read(false);
    if (affBottle!=NULL){
        cout << "Affordance read" << endl;
        int act = affBottle->get(0).asInt();
        double eff = affBottle->get(1).asDouble();        
    }

    // read if there is any new label.
    Bottle *labelBottle = labelsInPort.read(false);
    if (labelBottle!=NULL){
        cout << "Label read" << endl;
        string label = labelBottle->get(0).asString();        
    }

    // Stream affordances of active label
    if (activeLabel >=0) {
        //cout << "Streaming affordance" << endl;
        Bottle &affBotOut = labelOutPort.prepare();
        affBotOut.clear();
        // Things get done here
        labelOutPort.write();
    }

    return !closing;
}


double  MODULE_SKELETON::getPeriod()
{
    return 0.1; //module periodicity (seconds)
}


bool  MODULE_SKELETON::interruptModule()
{
    closing = true;
    dataInPort.interrupt();
    labelsInPort.interrupt();
    labelOutPort.interrupt();

    imgInPort.interrupt();
    imgOutPort.interrupt();

    cout << "Ports interrupted" << endl;
    return true;
}


bool  MODULE_SKELETON::close()
{
    dataInPort.close();
    labelsInPort.close();
    labelOutPort.close();

    imgInPort.close();
    imgOutPort.close();

    cout << "Module ports closed" << endl;
    return true;
}

/**************************** THRIFT CONTROL*********************************/
bool  MODULE_SKELETON::attach(RpcServer &source)
{
    return this->yarp().attachAsServer(source);
}

/**********************************************************
                    PUBLIC METHODS
/**********************************************************/

// RPC Accesible via trhift.
/**********************************************************/
bool MODULE_SKELETON::setnumact(const int num)
{

}


/***************** MORE PUBLIC METHODS **************/

/**********************************************************/
bool MODULE_SKELETON::quit()
{
    closing = true;
    return true;
}


/**********************************************************
                    PRIVATE METHODS
/**********************************************************/

/***************** Helper Functions *************************************/
double MODULE_SKELETON::vecAvg (const vector<double>& vec )
{

}

/***************** MORE PRIVATE METHOTS**************/


/************************************************************************/
/************************************************************************/
int main(int argc, char * argv[])
{
    Network yarp;
    if (!yarp.checkNetwork())
    {
        printf("YARP server not available!\n");
        return -1;
    }

    MODULE_SKELETON module;
    ResourceFinder rf;
    rf.setDefaultContext("MODULE_SKELETON");
    rf.setDefaultConfigFile("MODULE_SKELETON.ini");
    rf.setDefault("name","MODULE_SKELETON");
    rf.setVerbose(true);
    rf.configure(argc, argv);

    cout<<"Configure and Start module..."<<endl;
    return module.runModule(rf);

}

