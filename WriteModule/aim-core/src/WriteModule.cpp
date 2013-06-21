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

WriteModule::WriteModule():
  cliParam(0)
{
  const char* const channel[1] = {"writeOutput"};
  cliParam = new Param();
}

WriteModule::~WriteModule() {
  delete cliParam;
}

void WriteModule::Init(std::string & name) {
  cliParam->module_id = name;
}

bool WriteModule::writeOutput(const int output) {
  return true;
}

