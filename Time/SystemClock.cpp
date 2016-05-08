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

#include "SystemClock.h"

DLL_FUNCTION(std::chrono::system_clock::time_point*) BU_SystemClock_Now() {
#pragma comment(linker, "/EXPORT:BU_SystemClock_Now=_BU_SystemClock_Now@0")
	return new std::chrono::system_clock::time_point(std::chrono::system_clock::now());
}

DLL_FUNCTION(void) BU_SystemClock_Destroy(std::chrono::system_clock::time_point* pThis) {
#pragma comment(linker, "/EXPORT:BU_SystemClock_Destroy=_BU_SystemClock_Destroy@4")
	delete pThis;
}

DLL_FUNCTION(std::chrono::system_clock::time_point*) BU_SystemClock_FromTime(time_t* pTime) {
#pragma comment(linker, "/EXPORT:BU_SystemClock_FromTime=_BU_SystemClock_FromTime@4")
	return new std::chrono::system_clock::time_point(std::chrono::system_clock::from_time_t(*pTime));
}

DLL_FUNCTION(time_t*) BU_SystemClock_AsTime(std::chrono::system_clock::time_point* pThis) {
#pragma comment(linker, "/EXPORT:BU_SystemClock_AsTime=_BU_SystemClock_AsTime@4")
	return new time_t(std::chrono::system_clock::to_time_t(*pThis));
}