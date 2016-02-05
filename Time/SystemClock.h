//	BlitzUtility - Expanding the normal Blitz functionality.
//	Copyright (C) 2015 Xaymar (Michael Fabian Dirks)
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
#include "BlitzUtility.h"
#include <chrono>

DLL_FUNCTION(std::chrono::system_clock::time_point*) BU_SystemClock_Now();
DLL_FUNCTION(void) BU_SystemClock_Destroy(std::chrono::system_clock::time_point* pThis);
DLL_FUNCTION(std::chrono::system_clock::time_point*) BU_SystemClock_FromTime(time_t* pTime);
DLL_FUNCTION(time_t*) BU_SystemClock_AsTime(std::chrono::system_clock::time_point* pThis);