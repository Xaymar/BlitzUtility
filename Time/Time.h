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
#include <time.h>

DLL_FUNCTION(time_t*) BU_Time_Now();
DLL_FUNCTION(time_t*) BU_Time_Create(uint32_t seconds, uint32_t minutes, uint32_t hours, uint32_t days, uint32_t months, uint32_t years, uint32_t isDaylightSavings);
DLL_FUNCTION(void) BU_Time_Destroy(time_t* pTime);
DLL_FUNCTION(const char*) BU_Time_Format(time_t* pTime, const char* pchFormatString);