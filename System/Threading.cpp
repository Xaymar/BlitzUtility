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

#include "Threading.h"

// Types of Blitz Functions.
typedef int32_t(__stdcall *BP_BlitzFunction1_t)(int32_t);
int32_t BP_CallFunction1(BP_BlitzFunction1_t lpFunctionPointer, int32_t p1) {
	int32_t returnValue, StackPointer;

	__asm { // Store Stack Pointer
		mov StackPointer, esp;
	}

	returnValue = lpFunctionPointer(p1);

	__asm { // Restore Stack Pointer
		mov esp, StackPointer;
	}

	return returnValue;
}

BlitzThread::BlitzThread(void* ptr, void* data, uint32_t uiStackSize, bool bIsSuspended) {
	this->ptr = ptr;
	this->data = data;

	this->thread = CreateThread(NULL, uiStackSize, &ThreadMain, this, (bIsSuspended ? CREATE_SUSPENDED : 0), NULL);
}

BlitzThread::~BlitzThread() {
	this->Terminate(-1);
}

void BlitzThread::Terminate(int32_t exitCode) {
	if (this->thread) {
		TerminateThread(this->thread, -1);
		this->thread = 0;
	}
}

int32_t BlitzThread::Suspend() {
	return SuspendThread(this->thread);
}

int32_t BlitzThread::Resume() {
	return ResumeThread(this->thread);
}

int32_t BlitzThread::Wait(int32_t timeout) {
	return WaitForSingleObject(this->thread, timeout);
}

int32_t BlitzThread::GetExitCode() {
	DWORD pExitCode;
	GetExitCodeThread(this->thread, &pExitCode);
	return pExitCode;
}

DWORD WINAPI BlitzThread::ThreadMain(LPVOID pData) {
	BlitzThread* pThis = reinterpret_cast<BlitzThread*>(pData);

	try {
		return BP_CallFunction1((BP_BlitzFunction1_t)pThis->ptr, reinterpret_cast<int32_t>(pThis->data));
	} catch (std::exception e) {
		return -2;
	} catch (...) {
		return -1;
	}
}

DLL_FUNCTION(BlitzThread*) BU_Thread_Create(void* pFunction, void* pData, uint32_t uiStackSize, uint32_t bIsSuspended) {
#pragma comment(linker, "/EXPORT:BU_Thread_Create=_BU_Thread_Create@16")
	return new BlitzThread(pFunction, pData, uiStackSize, !!bIsSuspended);
}

DLL_FUNCTION(void) BU_Thread_Destroy(BlitzThread* pThread) {
#pragma comment(linker, "/EXPORT:BU_Thread_Destroy=_BU_Thread_Destroy@4")
	delete pThread;
}
DLL_FUNCTION(void) BU_Thread_Terminate(BlitzThread* pThread, int32_t exitCode) {
#pragma comment(linker, "/EXPORT:BU_Thread_Terminate=_BU_Thread_Terminate@8")
	pThread->Terminate(exitCode);
	delete pThread;
}

DLL_FUNCTION(int32_t) BU_Thread_Suspend(BlitzThread* pThread) {
#pragma comment(linker, "/EXPORT:BU_Thread_Suspend=_BU_Thread_Suspend@4")
	return pThread->Suspend();
}

DLL_FUNCTION(int32_t) BU_Thread_Resume(BlitzThread* pThread) {
#pragma comment(linker, "/EXPORT:BU_Thread_Resume=_BU_Thread_Resume@4")
	return pThread->Resume();
}

DLL_FUNCTION(int32_t) BU_Thread_Wait(BlitzThread* pThread, int32_t timeout) {
#pragma comment(linker, "/EXPORT:BU_Thread_Wait=_BU_Thread_Wait@8")
	return pThread->Wait(timeout);
}

DLL_FUNCTION(int32_t) BU_Thread_GetExitCode(BlitzThread* pThread) {
#pragma comment(linker, "/EXPORT:BU_Thread_GetExitCode=_BU_Thread_GetExitCode@4")
	return pThread->GetExitCode();
}

DLL_FUNCTION(void) BU_Thread_Exit(int32_t exitCode) {
#pragma comment(linker, "/EXPORT:BU_Thread_Exit=_BU_Thread_Exit@4")
	ExitThread(exitCode);
}

DLL_FUNCTION(HANDLE) BU_Mutex_Create(int32_t bInitialOwner) {
#pragma comment(linker, "/EXPORT:BU_Mutex_Create=_BU_Mutex_Create@4")
	return CreateMutex(NULL, !!bInitialOwner, NULL);
}

DLL_FUNCTION(void) BU_Mutex_Destroy(HANDLE mutex) {
#pragma comment(linker, "/EXPORT:BU_Mutex_Destroy=_BU_Mutex_Destroy@4")
	CloseHandle(mutex);
}

DLL_FUNCTION(int32_t) BU_Mutex_Lock(HANDLE mutex, int32_t timeout) {
#pragma comment(linker, "/EXPORT:BU_Mutex_Lock=_BU_Mutex_Lock@8")
	return WaitForSingleObject(mutex, timeout);
}

DLL_FUNCTION(int32_t) BU_Mutex_Unlock(HANDLE mutex) {
#pragma comment(linker, "/EXPORT:BU_Mutex_Unlock=_BU_Mutex_Unlock@4")
	return ReleaseMutex(mutex);
}