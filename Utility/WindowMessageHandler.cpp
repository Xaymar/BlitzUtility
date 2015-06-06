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
#include "WindowMessageHandler.h"

std::list<WindowUserData>* WindowMessageHandler_List;

void WindowMessageHandler_OnProcessAttach() {
	WindowMessageHandler_List = new std::list<WindowUserData>();
}

void WindowMessageHandler_OnProcessDetach() {
	for (auto iterator = WindowMessageHandler_List->begin(), end = WindowMessageHandler_List->end(); iterator != end; iterator++) {
		WindowMessageHandler_Uninstall(iterator->hwnd);
	}

	WindowMessageHandler_List->clear();
	delete WindowMessageHandler_List;
}

LRESULT CALLBACK WindowMessageHandler_Procedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	WindowUserData* UserData = (WindowUserData*)GetWindowLong(hwnd, GWL_USERDATA);
	if (UserData) {
		switch (uMsg) {
			case WM_SIZE:
				UserData->WindowWasResized = true;
				UserData->WindowClientWidth = lParam & 0xFFFF;
				UserData->WindowClientHeight = lParam & 0xFFFF0000 >> 16;

				return CallWindowProc(UserData->oWindowProcedure, hwnd, uMsg, wParam, lParam);
				break;
			
			case WM_CLOSE:
				UserData->DestroyCount++;
				return false;

			case WM_DESTROY:
				UserData->CloseCount++;
				return false;

			default:
				return CallWindowProc(UserData->oWindowProcedure, hwnd, uMsg, wParam, lParam);
		}
	} else {
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}

DLL_EXPORT void WindowMessageHandler_Install(HWND hwnd) {
	if (hwnd) {
		WindowUserData* UserData = new WindowUserData;
		ZeroMemory(UserData, sizeof(UserData));
		UserData->oWindowProcedure = (WNDPROC)SetWindowLong(hwnd, GWL_WNDPROC, (LONG)&WindowMessageHandler_Procedure);
		UserData->oUserData = SetWindowLong(hwnd, GWL_USERDATA, (LONG)UserData);
	}
}
#pragma comment(linker, "/EXPORT:WindowMessageHandler_Install=_WindowMessageHandler_Install@4")

DLL_EXPORT void WindowMessageHandler_Uninstall(HWND hwnd) {
	if (hwnd) {
		WindowUserData* UserData = (WindowUserData*)GetWindowLong(hwnd, GWL_USERDATA);
		if (UserData) {
			SetWindowLong(hwnd, GWL_USERDATA, UserData->oUserData);
			SetWindowLong(hwnd, GWL_WNDPROC, (LONG)(UserData->oWindowProcedure));
			delete UserData;
		}
	}
}
#pragma comment(linker, "/EXPORT:WindowMessageHandler_Uninstall=_WindowMessageHandler_Uninstall@4")

DLL_EXPORT int WindowMessageHandler_Message_Resize(HWND hwnd, LPPOINT point) {
	if (hwnd) {
		WindowUserData* UserData = (WindowUserData*)GetWindowLong(hwnd, GWL_USERDATA);
		if (UserData) {
			int toReturn = UserData->WindowWasResized;
			point->x = UserData->WindowClientWidth;
			point->y = UserData->WindowClientHeight;
			UserData->WindowWasResized = false;
			return toReturn;
		}
	}
	return 0;
}
#pragma comment(linker, "/EXPORT:WindowMessageHandler_Message_Resize=_WindowMessageHandler_Message_Resize@8")

DLL_EXPORT int WindowMessageHandler_Message_Destroy(HWND hwnd) {
	if (hwnd) {
		WindowUserData* UserData = (WindowUserData*)GetWindowLong(hwnd, GWL_USERDATA);
		if (UserData) {
			int toReturn = UserData->DestroyCount;
			UserData->DestroyCount = 0;
			return toReturn;
		}
	}
	return 0;
}
#pragma comment(linker, "/EXPORT:WindowMessageHandler_Message_Destroy=_WindowMessageHandler_Message_Destroy@4")

DLL_EXPORT int WindowMessageHandler_Message_Close(HWND hwnd) {
	if (hwnd) {
		WindowUserData* UserData = (WindowUserData*)GetWindowLong(hwnd, GWL_USERDATA);
		if (UserData) {
			int toReturn = UserData->CloseCount;
			UserData->CloseCount = 0;
			return toReturn;
		}
	}
	return 0;
}
#pragma comment(linker, "/EXPORT:WindowMessageHandler_Message_Close=_WindowMessageHandler_Message_Close@4")

