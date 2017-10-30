#include "imThread.h"

using namespace std;
using namespace yarp::os;

// Empty constructor
ImThread::ImThread(int period, const string &_name):RateThread(period), id(_name){}

// Initialize Variables
bool ImThread::threadInit()
{
    // Inits

    return true 
}

void ImThread::run()
{

}


void ImThread::threadRelease()
{
    printf("Closing Image Thread\n");
}
