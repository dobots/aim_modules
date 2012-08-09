/**
 * @file BinaryStream.cpp
 * @brief 
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
 * Copyright © 2010 Anne van Rossum <anne@almende.com>
 *
 * @author  Anne C. van Rossum
 * @date    Aug 9, 2012
 * @project Replicator FP7
 * @company Almende B.V.
 * @case    Artificial Intelligence Framework
 */

#include <BinaryStream.h>

#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

/**
 * Read a new packet from the stream
 */
char* BinaryStream::Read() {
	if (!packets.empty()) {
		char *result = packets.front();
		packets.pop_front();
		return result;
	}
	do {
		Sync();
		char *packet = getLast(packet_size);
		if (check(packet)) {
			packets.push_back(packet);
		}
	}
	while (packets.empty());
	char *result = packets.front();
	packets.pop_front();
	return result;
}

void BinaryStream::Sync() {
	int ind0, ind1;
	readN(packet_size*1);
	ind1 = get_pbuf_r();
	do {
		readN(packet_size*2);
		ind0 = find(start_byte, ind1);
		ind1 = find(start_byte, ind0);
	}
	while ((ind1 - ind0) != packet_size);
	cout << "Cool found two start bytes exactly packet size from each other" << endl;
	set_pbuf_r(ind0);
}

bool BinaryStream::check(char *packet) {
	return (packet[0] == start_byte);
}
