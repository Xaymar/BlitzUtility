#pragma once
#include "dllmain.h"
#include <list>

struct Display {
	int left;
	int top;
	int right;
	int bottom;
};

void Display_OnProcessAttach();
void Display_OnProcessDetach();

BOOL CALLBACK Display_EnumerateProcedure(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData);