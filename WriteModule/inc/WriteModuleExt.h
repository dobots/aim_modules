/**
 * @file WriteModuleExt.h
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

#include <WriteModule.h>

namespace rur {

/**
 * Your Description of this module.
 */
class WriteModuleExt: public WriteModule {
public:
	//! The constructor
	WriteModuleExt();

	//! The destructor
	virtual ~WriteModuleExt();

	//! The tick function is the "heart" of your module, it reads and writes to the ports
	void Tick();

	//! As soon as Stop() returns "true", the WriteModuleMain will stop the module
	bool Stop();
};

}

