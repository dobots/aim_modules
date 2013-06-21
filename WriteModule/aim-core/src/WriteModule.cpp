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
 * @author Anne C. van Rossum
 * @copyright Distributed Organisms B.V.
 * @date Mar. 27, 2013
 * @license LGPLv3
 */

#include "WriteModule.h"

using namespace rur;
using namespace yarp::os;

WriteModule::WriteModule():
  cliParam(0)
{
  const char* const channel[1] = {"writeOutput"};
  cliParam = new Param();
  portOutput = new BufferedPort<Bottle>();
}

WriteModule::~WriteModule() {
  delete cliParam;
  delete portOutput;
}

void WriteModule::Init(std::string & name) {
  cliParam->module_id = name;
  std::stringstream yarpPortName;
  yarpPortName.str(""); yarpPortName.clear();
  yarpPortName << "/writemodule" << name << "/output";
  portOutput->open(yarpPortName.str().c_str());
  
}

bool WriteModule::writeOutput(const int output) {
  Bottle &outputPrepare = portOutput->prepare();
  outputPrepare.clear();
  outputPrepare.addInt(output);
  bool forceStrict = true; // wait till previous sends are complete
  portOutput->write(forceStrict);
  return true;
}

