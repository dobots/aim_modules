/**
 * This file is created at Almende B.V. It is open-source software and part of the Common 
 * Hybrid Agent Platform (CHAP). A toolbox with a lot of open-source tools, ranging from 
 * thread pools and TCP/IP components to control architectures and learning algorithms. 
 * This software is published under the GNU Lesser General Public license (LGPL).
 *
 * It is not possible to add usage restrictions to an open-source license. Nevertheless,
 * we personally strongly object against this software being used by the military, in the
 * bio-industry, for animal experimentation, or anything that violates the Universal
 * Declaration of Human Rights.
 *
 * @author               Homer J. Simpson
 * @copyright            Springfield Power Company
 * @date                 okt 22, 2013
 * @license              State
 */

#ifndef WRITEMODULE_H_
#define WRITEMODULE_H_

#include <string>
#include <vector>
#include <string>
#include <vector>
#include <sstream>
#include <yarp/os/BufferedPort.h>
#include <yarp/os/Network.h>
#include <yarp/os/Bottle.h>

namespace rur {

struct Param {
  std::string module_id;
};

class WriteModule {
private:
  Param *cliParam;
  
  yarp::os::Network yarp;
  yarp::os::BufferedPort<yarp::os::Bottle> *portOutput;
protected:
  static const int channel_count = 1;
  const char* channel[1];
  // Write to this function and assume it ends up at some receiving module
  bool writeOutput(const int output);
  
public:
  // Default constructor
  WriteModule();
  
  // Default destructor
  virtual ~WriteModule();
  
  // Extend this with your own code, first call WriteModule::Init(name);
  void Init(std::string& name);
  
  // Function to get Param struct (to subsequently set CLI parameters)
  inline Param *GetParam() { return cliParam; }
  
  // Overwrite this function with your own code
  virtual void Tick() = 0;
  
  // Overwrite this function with your own code
  bool Stop() { return false; }
  
};
} // End of namespace

#endif // WRITEMODULE_H_
