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

#include "Timer.h"
#include <string.h>
#include <string>
#include <functional>
#include <chrono>
#include <future>
#include <cstdio>

using namespace std;

struct BlitzTimerInfo {
	uint32_t Interval;

	HANDLE hSemaphore;
};

int32_t BU_Timer_Index = 0;
std::map<int32_t, BlitzTimerInfo> BU_Timer_List;// = new std::map<int32_t, HANDLE>();

VOID CALLBACK BU_Timer_PROC(
	_In_ HWND     hwnd,
	_In_ UINT     uMsg,
	_In_ UINT_PTR idEvent,
	_In_ DWORD    dwTime
) {
	BlitzTimerInfo myTimer = BU_Timer_List[idEvent];
	ReleaseSemaphore(myTimer.hSemaphore, 1, NULL);
}

DLL_FUNCTION(int32_t) BU_Timer_Create(uint32_t Interval, HWND hwnd) {
	UINT_PTR timer = SetTimer(hwnd, 32767, Interval, &BU_Timer_PROC);

	if (timer) {
		BlitzTimerInfo myTimer = BlitzTimerInfo();
		myTimer.Interval = Interval;
		myTimer.hSemaphore = CreateSemaphore(NULL, 0, 32767, NULL);
		BU_Timer_List[timer] = myTimer;
		return timer;
	} else {
		return 0;
	}
}

DLL_FUNCTION(void) BU_Timer_Destroy(uint32_t Id) {
	BlitzTimerInfo myTimer = BU_Timer_List[Id];
	CloseHandle(myTimer.hSemaphore);
	BU_Timer_List.erase(Id);
}

DLL_FUNCTION(int32_t) BU_Timer_Wait(uint32_t Id) {
	BlitzTimerInfo myTimer = BU_Timer_List[Id];

	//HANDLE myHandles[] = { myTimer.hSemaphore };
	//MsgWaitForMultipleObjects(1, myHandles, true, 0xFFFFFFFF, QS_TIMER);
	return WaitForSingleObject(myTimer.hSemaphore, 0xFFFFFFFF);
}