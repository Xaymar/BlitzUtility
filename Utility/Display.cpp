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

#include "Display.h"

std::list<Display>* Display_List = NULL;

void Display_OnProcessAttach() {
	Display_List = new std::list<Display>();
}

void Display_OnProcessDetach() {
	Display_List->clear();
	delete Display_List;
}

DLL_EXPORT void Display_Enumerate() {
	if (Display_List == NULL)
		return;

	Display_List->clear();

	EnumDisplayMonitors(NULL, NULL, Display_EnumerateProcedure, 0);
}
#pragma comment(linker, "/EXPORT:Display_Enumerate=_Display_Enumerate@0")

BOOL CALLBACK Display_EnumerateProcedure(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData) {
	Display *thisDisplay = new Display;

	thisDisplay->left = lprcMonitor->left;
	thisDisplay->top = lprcMonitor->top;
	thisDisplay->right = lprcMonitor->right;
	thisDisplay->bottom = lprcMonitor->bottom;

	Display_List->push_back(*thisDisplay);

	return TRUE;
}

DLL_EXPORT int Display_Count() {
	return Display_List->size();
}
#pragma comment(linker, "/EXPORT:Display_Count=_Display_Count@0")

DLL_EXPORT void Display_Get(uint32_t displayId, LPRECT display) {
	if (Display_List->size() > displayId) {
		auto iterator = Display_List->begin();

		std::advance(iterator, displayId);

		if (display != NULL) {
			display->left = iterator->left;
			display->top = iterator->top;
			display->right = iterator->right;
			display->bottom = iterator->bottom;
		}
	}
}
#pragma comment(linker, "/EXPORT:Display_Get=_Display_Get@8")

