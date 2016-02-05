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

#include "DisplayEnumerator.h"

BOOL CALLBACK BU_DisplayEnumerator_Callback(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData) {
	DisplayEnumerator* displayEnumerator = (DisplayEnumerator*)dwData;

	displayEnumerator->displays.push_back(RECT(*lprcMonitor));
	return TRUE;
}

DLL_FUNCTION(DisplayEnumerator*) BU_DisplayEnumerator_Create() {
	DisplayEnumerator* displayEnumerator = new DisplayEnumerator();
	return displayEnumerator;
}

DLL_FUNCTION(void) BU_DisplayEnumerator_Destroy(DisplayEnumerator* displayEnumerator) {
	delete displayEnumerator;
}

DLL_FUNCTION(uint32_t) BU_DisplayEnumerator_Enumerate(DisplayEnumerator* displayEnumerator) {
	EnumDisplayMonitors(NULL, NULL, BU_DisplayEnumerator_Callback, (LPARAM)displayEnumerator);

	return displayEnumerator->displays.size();
}

DLL_FUNCTION(uint32_t) BU_DisplayEnumerator_Count(DisplayEnumerator* displayEnumerator) {
	return displayEnumerator->displays.size();
}

DLL_FUNCTION(void) BU_DisplayEnumerator_Retrieve(DisplayEnumerator* displayEnumerator, uint32_t index, PRECT display) {
	// Retrieve the requested index.
	auto iterator = displayEnumerator->displays.begin();
	std::advance(iterator, index);

	// Copy data.
	display->left = iterator->left;
	display->top = iterator->top;
	display->right = iterator->right;
	display->bottom = iterator->bottom;
}