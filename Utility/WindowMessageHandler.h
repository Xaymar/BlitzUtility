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
#include "dllmain.h"
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


void WindowMessageHandler_OnProcessAttach();
void WindowMessageHandler_OnProcessDetach();

LRESULT CALLBACK WindowMessageHandler_Procedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
DLL_EXPORT void WindowMessageHandler_Install(HWND hwnd);
DLL_EXPORT void WindowMessageHandler_Uninstall(HWND hwnd);