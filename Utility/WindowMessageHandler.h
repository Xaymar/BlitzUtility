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

struct WindowUserData {
	HWND hwnd;

	WNDPROC oWindowProcedure;
	LONG oUserData;
	
	// WM_SIZE
	bool WindowWasResized;
	uint32_t WindowClientWidth, WindowClientHeight;

	// WM_DESTROY, WM_CLOSE
	uint32_t DestroyCount, CloseCount;
};


void BU_WindowMessageHandler_OnProcessAttach();
void BU_WindowMessageHandler_OnProcessDetach();
LRESULT CALLBACK BU_WindowMessageHandler_Procedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

DLL_FUNCTION(void) BU_WindowMessageHandler_Install(HWND hwnd);
#pragma comment(linker, "/EXPORT:BU_WindowMessageHandler_Install=_BU_WindowMessageHandler_Install@4")
DLL_FUNCTION(void) BU_WindowMessageHandler_Uninstall(HWND hwnd);
#pragma comment(linker, "/EXPORT:BU_WindowMessageHandler_Uninstall=_BU_WindowMessageHandler_Uninstall@4")
DLL_FUNCTION(uint32_t) BU_WindowMessageHandler_Message_Resize(HWND hwnd, LPPOINT point);
#pragma comment(linker, "/EXPORT:BU_WindowMessageHandler_Message_Resize=_BU_WindowMessageHandler_Message_Resize@8")
DLL_FUNCTION(uint32_t) BU_WindowMessageHandler_Message_Destroy(HWND hwnd);
#pragma comment(linker, "/EXPORT:BU_WindowMessageHandler_Message_Destroy=_BU_WindowMessageHandler_Message_Destroy@4")
DLL_FUNCTION(uint32_t) BU_WindowMessageHandler_Message_Close(HWND hwnd);
#pragma comment(linker, "/EXPORT:BU_WindowMessageHandler_Message_Close=_BU_WindowMessageHandler_Message_Close@4")