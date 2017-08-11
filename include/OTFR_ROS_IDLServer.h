// This is an automatically-generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#ifndef YARP_THRIFT_GENERATOR_OTFR_ROS_IDLServer
#define YARP_THRIFT_GENERATOR_OTFR_ROS_IDLServer

#include <yarp/os/Wire.h>
#include <yarp/os/idl/WireTypes.h>

class OTFR_ROS_IDLServer;


class OTFR_ROS_IDLServer : public yarp::os::Wire {
public:
  OTFR_ROS_IDLServer();
  /**
   * Start the module
   * @return true/false on success/failure
   */
  virtual bool start();
  /**
   * Quit the module
   * @return true/false on success/failure
   */
  virtual bool quit();
  /**
   * Allows to modify online the number of possible actions
   * @return true/false on success/failure
   */
  virtual bool setnumact(const int32_t numAct);
  /**
   * Activates/Deactivates more verbose execution of the module.
   * @return true/false on success/failure
   */
  virtual bool verbose(const bool verb);
  virtual bool read(yarp::os::ConnectionReader& connection) YARP_OVERRIDE;
  virtual std::vector<std::string> help(const std::string& functionName="--all");
};

#endif
