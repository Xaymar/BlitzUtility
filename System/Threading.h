//	Blitz - Steam wrapper for Blitz.
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
#include <mutex>
#include <chrono>

class BlitzThread {
public:
	BlitzThread(void* ptr, void* data, uint32_t uiStackSize, bool bIsSuspended);
	~BlitzThread();

	void Terminate(int32_t exitCode);

	int32_t Suspend();
	int32_t Resume();
	int32_t Wait(int32_t timeout);
	int32_t GetExitCode();

	static DWORD WINAPI ThreadMain(LPVOID pData);
private:
	void *ptr, *data;
	std::exception* ex;

	HANDLE thread;
};




