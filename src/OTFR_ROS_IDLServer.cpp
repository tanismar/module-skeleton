// This is an automatically-generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <OTFR_ROS_IDLServer.h>
#include <yarp/os/idl/WireTypes.h>



class OTFR_ROS_IDLServer_start : public yarp::os::Portable {
public:
  bool _return;
  void init();
  virtual bool write(yarp::os::ConnectionWriter& connection) YARP_OVERRIDE;
  virtual bool read(yarp::os::ConnectionReader& connection) YARP_OVERRIDE;
};

class OTFR_ROS_IDLServer_quit : public yarp::os::Portable {
public:
  bool _return;
  void init();
  virtual bool write(yarp::os::ConnectionWriter& connection) YARP_OVERRIDE;
  virtual bool read(yarp::os::ConnectionReader& connection) YARP_OVERRIDE;
};

class OTFR_ROS_IDLServer_setnumact : public yarp::os::Portable {
public:
  int32_t numAct;
  bool _return;
  void init(const int32_t numAct);
  virtual bool write(yarp::os::ConnectionWriter& connection) YARP_OVERRIDE;
  virtual bool read(yarp::os::ConnectionReader& connection) YARP_OVERRIDE;
};

class OTFR_ROS_IDLServer_verbose : public yarp::os::Portable {
public:
  bool verb;
  bool _return;
  void init(const bool verb);
  virtual bool write(yarp::os::ConnectionWriter& connection) YARP_OVERRIDE;
  virtual bool read(yarp::os::ConnectionReader& connection) YARP_OVERRIDE;
};

bool OTFR_ROS_IDLServer_start::write(yarp::os::ConnectionWriter& connection) {
  yarp::os::idl::WireWriter writer(connection);
  if (!writer.writeListHeader(1)) return false;
  if (!writer.writeTag("start",1,1)) return false;
  return true;
}

bool OTFR_ROS_IDLServer_start::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  if (!reader.readListReturn()) return false;
  if (!reader.readBool(_return)) {
    reader.fail();
    return false;
  }
  return true;
}

void OTFR_ROS_IDLServer_start::init() {
  _return = false;
}

bool OTFR_ROS_IDLServer_quit::write(yarp::os::ConnectionWriter& connection) {
  yarp::os::idl::WireWriter writer(connection);
  if (!writer.writeListHeader(1)) return false;
  if (!writer.writeTag("quit",1,1)) return false;
  return true;
}

bool OTFR_ROS_IDLServer_quit::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  if (!reader.readListReturn()) return false;
  if (!reader.readBool(_return)) {
    reader.fail();
    return false;
  }
  return true;
}

void OTFR_ROS_IDLServer_quit::init() {
  _return = false;
}

bool OTFR_ROS_IDLServer_setnumact::write(yarp::os::ConnectionWriter& connection) {
  yarp::os::idl::WireWriter writer(connection);
  if (!writer.writeListHeader(2)) return false;
  if (!writer.writeTag("setnumact",1,1)) return false;
  if (!writer.writeI32(numAct)) return false;
  return true;
}

bool OTFR_ROS_IDLServer_setnumact::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  if (!reader.readListReturn()) return false;
  if (!reader.readBool(_return)) {
    reader.fail();
    return false;
  }
  return true;
}

void OTFR_ROS_IDLServer_setnumact::init(const int32_t numAct) {
  _return = false;
  this->numAct = numAct;
}

bool OTFR_ROS_IDLServer_verbose::write(yarp::os::ConnectionWriter& connection) {
  yarp::os::idl::WireWriter writer(connection);
  if (!writer.writeListHeader(2)) return false;
  if (!writer.writeTag("verbose",1,1)) return false;
  if (!writer.writeBool(verb)) return false;
  return true;
}

bool OTFR_ROS_IDLServer_verbose::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  if (!reader.readListReturn()) return false;
  if (!reader.readBool(_return)) {
    reader.fail();
    return false;
  }
  return true;
}

void OTFR_ROS_IDLServer_verbose::init(const bool verb) {
  _return = false;
  this->verb = verb;
}

OTFR_ROS_IDLServer::OTFR_ROS_IDLServer() {
  yarp().setOwner(*this);
}
bool OTFR_ROS_IDLServer::start() {
  bool _return = false;
  OTFR_ROS_IDLServer_start helper;
  helper.init();
  if (!yarp().canWrite()) {
    yError("Missing server method '%s'?","bool OTFR_ROS_IDLServer::start()");
  }
  bool ok = yarp().write(helper,helper);
  return ok?helper._return:_return;
}
bool OTFR_ROS_IDLServer::quit() {
  bool _return = false;
  OTFR_ROS_IDLServer_quit helper;
  helper.init();
  if (!yarp().canWrite()) {
    yError("Missing server method '%s'?","bool OTFR_ROS_IDLServer::quit()");
  }
  bool ok = yarp().write(helper,helper);
  return ok?helper._return:_return;
}
bool OTFR_ROS_IDLServer::setnumact(const int32_t numAct) {
  bool _return = false;
  OTFR_ROS_IDLServer_setnumact helper;
  helper.init(numAct);
  if (!yarp().canWrite()) {
    yError("Missing server method '%s'?","bool OTFR_ROS_IDLServer::setnumact(const int32_t numAct)");
  }
  bool ok = yarp().write(helper,helper);
  return ok?helper._return:_return;
}
bool OTFR_ROS_IDLServer::verbose(const bool verb) {
  bool _return = false;
  OTFR_ROS_IDLServer_verbose helper;
  helper.init(verb);
  if (!yarp().canWrite()) {
    yError("Missing server method '%s'?","bool OTFR_ROS_IDLServer::verbose(const bool verb)");
  }
  bool ok = yarp().write(helper,helper);
  return ok?helper._return:_return;
}

bool OTFR_ROS_IDLServer::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  reader.expectAccept();
  if (!reader.readListHeader()) { reader.fail(); return false; }
  yarp::os::ConstString tag = reader.readTag();
  bool direct = (tag=="__direct__");
  if (direct) tag = reader.readTag();
  while (!reader.isError()) {
    // TODO: use quick lookup, this is just a test
    if (tag == "start") {
      bool _return;
      _return = start();
      yarp::os::idl::WireWriter writer(reader);
      if (!writer.isNull()) {
        if (!writer.writeListHeader(1)) return false;
        if (!writer.writeBool(_return)) return false;
      }
      reader.accept();
      return true;
    }
    if (tag == "quit") {
      bool _return;
      _return = quit();
      yarp::os::idl::WireWriter writer(reader);
      if (!writer.isNull()) {
        if (!writer.writeListHeader(1)) return false;
        if (!writer.writeBool(_return)) return false;
      }
      reader.accept();
      return true;
    }
    if (tag == "setnumact") {
      int32_t numAct;
      if (!reader.readI32(numAct)) {
        reader.fail();
        return false;
      }
      bool _return;
      _return = setnumact(numAct);
      yarp::os::idl::WireWriter writer(reader);
      if (!writer.isNull()) {
        if (!writer.writeListHeader(1)) return false;
        if (!writer.writeBool(_return)) return false;
      }
      reader.accept();
      return true;
    }
    if (tag == "verbose") {
      bool verb;
      if (!reader.readBool(verb)) {
        reader.fail();
        return false;
      }
      bool _return;
      _return = verbose(verb);
      yarp::os::idl::WireWriter writer(reader);
      if (!writer.isNull()) {
        if (!writer.writeListHeader(1)) return false;
        if (!writer.writeBool(_return)) return false;
      }
      reader.accept();
      return true;
    }
    if (tag == "help") {
      std::string functionName;
      if (!reader.readString(functionName)) {
        functionName = "--all";
      }
      std::vector<std::string> _return=help(functionName);
      yarp::os::idl::WireWriter writer(reader);
        if (!writer.isNull()) {
          if (!writer.writeListHeader(2)) return false;
          if (!writer.writeTag("many",1, 0)) return false;
          if (!writer.writeListBegin(BOTTLE_TAG_INT, static_cast<uint32_t>(_return.size()))) return false;
          std::vector<std::string> ::iterator _iterHelp;
          for (_iterHelp = _return.begin(); _iterHelp != _return.end(); ++_iterHelp)
          {
            if (!writer.writeString(*_iterHelp)) return false;
           }
          if (!writer.writeListEnd()) return false;
        }
      reader.accept();
      return true;
    }
    if (reader.noMore()) { reader.fail(); return false; }
    yarp::os::ConstString next_tag = reader.readTag();
    if (next_tag=="") break;
    tag = tag + "_" + next_tag;
  }
  return false;
}

std::vector<std::string> OTFR_ROS_IDLServer::help(const std::string& functionName) {
  bool showAll=(functionName=="--all");
  std::vector<std::string> helpString;
  if(showAll) {
    helpString.push_back("*** Available commands:");
    helpString.push_back("start");
    helpString.push_back("quit");
    helpString.push_back("setnumact");
    helpString.push_back("verbose");
    helpString.push_back("help");
  }
  else {
    if (functionName=="start") {
      helpString.push_back("bool start() ");
      helpString.push_back("Start the module ");
      helpString.push_back("@return true/false on success/failure ");
    }
    if (functionName=="quit") {
      helpString.push_back("bool quit() ");
      helpString.push_back("Quit the module ");
      helpString.push_back("@return true/false on success/failure ");
    }
    if (functionName=="setnumact") {
      helpString.push_back("bool setnumact(const int32_t numAct) ");
      helpString.push_back("Allows to modify online the number of possible actions ");
      helpString.push_back("@return true/false on success/failure ");
    }
    if (functionName=="verbose") {
      helpString.push_back("bool verbose(const bool verb) ");
      helpString.push_back("Activates/Deactivates more verbose execution of the module. ");
      helpString.push_back("@return true/false on success/failure ");
    }
    if (functionName=="help") {
      helpString.push_back("std::vector<std::string> help(const std::string& functionName=\"--all\")");
      helpString.push_back("Return list of available commands, or help message for a specific function");
      helpString.push_back("@param functionName name of command for which to get a detailed description. If none or '--all' is provided, print list of available commands");
      helpString.push_back("@return list of strings (one string per line)");
    }
  }
  if ( helpString.empty()) helpString.push_back("Command not found");
  return helpString;
}


