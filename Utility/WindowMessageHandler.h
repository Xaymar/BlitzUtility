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