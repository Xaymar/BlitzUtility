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
#include <list>

struct DisplayEnumerator {
	std::list<RECT> displays;
};

// Internal Callback
BOOL CALLBACK BU_DisplayEnumerator_Callback(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData);

// Exported functions.
DLL_FUNCTION(DisplayEnumerator*) BU_DisplayEnumerator_Create();
#pragma comment(linker, "/EXPORT:BU_DisplayEnumerator_Create=_BU_DisplayEnumerator_Create@0")
DLL_FUNCTION(void) BU_DisplayEnumerator_Destroy(DisplayEnumerator* displayEnumerator);
#pragma comment(linker, "/EXPORT:BU_DisplayEnumerator_Destroy=_BU_DisplayEnumerator_Destroy@4")
DLL_FUNCTION(uint32_t) BU_DisplayEnumerator_Enumerate(DisplayEnumerator* displayEnumerator);
#pragma comment(linker, "/EXPORT:BU_DisplayEnumerator_Enumerate=_BU_DisplayEnumerator_Enumerate@4")
DLL_FUNCTION(uint32_t) BU_DisplayEnumerator_Count(DisplayEnumerator* displayEnumerator);
#pragma comment(linker, "/EXPORT:BU_DisplayEnumerator_Count=_BU_DisplayEnumerator_Count@4")
DLL_FUNCTION(void) BU_DisplayEnumerator_Retrieve(DisplayEnumerator* displayEnumerator, uint32_t index, LPRECT display);
#pragma comment(linker, "/EXPORT:BU_DisplayEnumerator_Retrieve=_BU_DisplayEnumerator_Retrieve@12")
