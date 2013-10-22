/**
 * @file WriteModuleExt.cpp
 * @brief WriteModule extension
 *
 * This file is created at "Springfield Power Company". It is open-source software and part of "Project Bootstrap". 
 * This software is published under the State license (TR8OR).
 *
 * Copyright © 2013 Homer J. Simpson <chunkylover53@aol.com>
 *
 * @author                   Homer J. Simpson
 * @date                     okt 22, 2013
 * @organisation             Springfield Power Company
 * @project                  Project Bootstrap
 */

#include <WriteModuleExt.h>
#include <iostream>
#include <unistd.h>

using namespace rur;

static int lifetime = 1000;

//! Constructor
WriteModuleExt::WriteModuleExt() {

}

//! Destructor
WriteModuleExt::~WriteModuleExt() {
	std::cout << "Deallocate object and close socket to name server" << std::endl;
}

//! Replace with your own code
void WriteModuleExt::Tick() {
	std::cout << '[' << getpid() << "] Tick " << lifetime << std::endl;

	if (!(lifetime % 7)) { // every 7 ticks send a value
		int value = lifetime;
		if (writeOutput(value)) {
			std::cout << "Sent value " << value << std::endl;
		}
	}
	sleep(1);
}

//! Replace with your own code
bool WriteModuleExt::Stop() {
	if (--lifetime) {
		return false;
	}
	return true;
}

