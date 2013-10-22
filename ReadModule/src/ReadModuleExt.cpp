/**
 * @file ReadModuleExt.cpp
 * @brief ReadModule extension
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

#include <ReadModuleExt.h>
#include <iostream>
#include <unistd.h>

using namespace rur;

static int lifetime = 1000;

//! Constructor
ReadModuleExt::ReadModuleExt() {

}

//! Destructor
ReadModuleExt::~ReadModuleExt() {
	std::cout << "Deallocate object and close socket to name server" << std::endl;
}

//! Replace with your own code
void ReadModuleExt::Tick() {
	std::cout << '[' << getpid() << "] Tick " << lifetime << std::endl;

	int *value = readInput(false);
	if (value != NULL) std::cout << "Read value " << *value << std::endl;

	sleep(1);
}

//! Replace with your own code
bool ReadModuleExt::Stop() {
	if (--lifetime) {
		return false;
	}
	return true;
}

