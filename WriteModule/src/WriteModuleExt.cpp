/**
 * @file WriteModuleExt.cpp
 * @brief WriteModule example
 *
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
 * Copyright © 2013 Your Name <your@email>
 *
 * @author	Your Name
 * @date	Current date
 * @company	Your Company
 * @project	Specific Software Project
 */

#include <WriteModuleExt.h>

#include <string>
#include <iostream>
#include <unistd.h>

using namespace rur;
using namespace std;

static int lifetime = 1000;

#define SHOW_YOU_ALSO_CAN_CONNECT_DIRECTLY 0

/***********************************************************************************************************************
 * Implementation
 **********************************************************************************************************************/

WriteModuleExt::WriteModuleExt() {
}

WriteModuleExt::~WriteModuleExt() {
	std::cout << "Deallocate object and close socket to name server" << endl;
}

/**
 * The write module
 */
void WriteModuleExt::Tick() {
	std::cout << '[' << getpid() << "] Tick " << lifetime << endl;
	WriteModule::Tick();
#if SHOW_YOU_ALSO_CAN_CONNECT_DIRECTLY == 1
	if (lifetime == 1000) {
		Connect("/writemodule0/output", "/readmodule0/input");
	}
#endif
	if (!(lifetime % 7)) { // every 7 ticks send a value
		int value = 666;
		if (writeOutput(value)) {
			std::cout << "Send value " << value << std::endl;
		}
	}
	sleep(1);
}

bool WriteModuleExt::Stop() {
	if (--lifetime) {
		return false;
	}
	return true;
}
