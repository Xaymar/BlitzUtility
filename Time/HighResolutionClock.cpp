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

#include "HighResolutionClock.h"
using namespace std;
using namespace std::chrono;

DLL_FUNCTION(high_resolution_clock::time_point*) BU_HighResolutionClock_Now() {
#pragma comment(linker, "/EXPORT:BU_HighResolutionClock_Now=_BU_HighResolutionClock_Now@0")
	return new high_resolution_clock::time_point(high_resolution_clock::now());
}

DLL_FUNCTION(void) BU_HighResolutionClock_Destroy(high_resolution_clock::time_point* pThis) {
#pragma comment(linker, "/EXPORT:BU_HighResolutionClock_Destroy=_BU_HighResolutionClock_Destroy@4")
	delete pThis;
}

DLL_FUNCTION(int32_t) BU_HighResolutionClock_Duration(high_resolution_clock::time_point* pThis, high_resolution_clock::time_point* pOther) {
#pragma comment(linker, "/EXPORT:BU_HighResolutionClock_Duration=_BU_HighResolutionClock_Duration@8")
	duration<int32_t, std::nano> temp = chrono::duration_cast<duration<int32_t, std::nano>>(*pThis - *pOther);
	return temp.count();
}

DLL_FUNCTION(int64_t*) BU_HighResolutionClock_DurationLL(high_resolution_clock::time_point* pThis, high_resolution_clock::time_point* pOther) {
#pragma comment(linker, "/EXPORT:BU_HighResolutionClock_DurationLL=_BU_HighResolutionClock_DurationLL@8")
	duration<int64_t, std::nano> temp = (*pThis - *pOther);
	return new int64_t(temp.count());
}

DLL_FUNCTION(float_t) BU_HighResolutionClock_DurationF(high_resolution_clock::time_point* pThis, high_resolution_clock::time_point* pOther) {
#pragma comment(linker, "/EXPORT:BU_HighResolutionClock_DurationF=_BU_HighResolutionClock_DurationF@8")
	double_t duration = (chrono::duration_cast<chrono::duration<double_t>>(*pThis - *pOther)).count();
	return (float_t)(duration);
}

DLL_FUNCTION(double_t*) BU_HighResolutionClock_DurationD(high_resolution_clock::time_point* pThis, high_resolution_clock::time_point* pOther) {
#pragma comment(linker, "/EXPORT:BU_HighResolutionClock_DurationD=_BU_HighResolutionClock_DurationD@8")
	double_t duration = (chrono::duration_cast<chrono::duration<double_t>>(*pThis - *pOther)).count();
	return new double_t(duration);
}
