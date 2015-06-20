//	BlitzUtility - Expanding the normal Blitz functionality.
//	Copyright (C) 2015 Project Kube (Michael Fabian Dirks)
//
//	This program is free software: you can redistribute it and/or modify
//	it under the terms of the GNU Lesser General Public License as
//	published by the Free Software Foundation, either version 3 of the 
//	License, or (at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU Lesser General Public License
//	along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

// Memory Management
#include <memory>

// Strings
#include <string>
#include <sstream>
#include <iomanip>

// Platform specific: Windows
#include <windows.h>

// Macros
#define DLL_METHOD extern "C"
#define DLL_CALL __stdcall

//Templates
template< typename T >
std::string int_to_hex(T i) {
	std::stringstream stream;
	stream
		<< std::setfill('0')
		<< std::setw(sizeof(T) * 2)
		<< std::hex
		<< i;
	return stream.str();
}

template< typename T >
T hex_to_int(std::string t) {
	T x;
	std::stringstream stream;
	stream
		<< std::hex
		<< t;
	stream
		>> x;
	return x;
}