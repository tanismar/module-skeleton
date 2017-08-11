#OTFR_ROS.thrift

/**
* OTFR_ROS_IDLServer
*
* Interface. 
*/

struct Bottle{}
(
    yarp.name = "yarp::os::Bottle"
    yarp.includefile="yarp/os/Bottle.h"
)

service OTFR_ROS_IDLServer
{
    /**
     * Start the module
     * @return true/false on success/failure
     */
    bool start();

    /**
     * Quit the module
     * @return true/false on success/failure
     */
    bool quit();

    /**
     * Allows to modify online the number of possible actions
     * @return true/false on success/failure
     */
    bool setnumact(1: i32 numAct);

    /**
     * Activates/Deactivates more verbose execution of the module.
     * @return true/false on success/failure 
     */
    bool verbose(1:bool verb);
}
