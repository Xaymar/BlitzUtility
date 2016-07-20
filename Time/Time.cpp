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

#include "Time.h"

DLL_FUNCTION(time_t*) BU_Time_Now() {
#pragma comment(linker, "/EXPORT:BU_Time_Now=_BU_Time_Now@0")
	time_t* pTime = new time_t();
	time(pTime);
	return pTime;
}

DLL_FUNCTION(time_t*) BU_Time_Create(uint32_t seconds, uint32_t minutes, uint32_t hours, uint32_t days, uint32_t months, uint32_t years, uint32_t isDaylightSavings) {
#pragma comment(linker, "/EXPORT:BU_Time_Create=_BU_Time_Create@28")
	tm* pTM = new tm();
	pTM->tm_sec = seconds;
	pTM->tm_min = minutes;
	pTM->tm_hour = hours;
	pTM->tm_mday = days;
	pTM->tm_mon = months;
	pTM->tm_year = years;
	pTM->tm_isdst = isDaylightSavings;

	time_t* pTime = new time_t(mktime(pTM));
	delete pTM;
	return pTime;
}

DLL_FUNCTION(void) BU_Time_Destroy(time_t* pTime) {
#pragma comment(linker, "/EXPORT:BU_Time_Destroy=_BU_Time_Destroy@4")
	delete pTime;
}

char* BU_Time_Format_Buffer = new char[1024];
DLL_FUNCTION(const char*) BU_Time_Format(time_t* pTime, const char* pchFormatString) {
#pragma comment(linker, "/EXPORT:BU_Time_Format=_BU_Time_Format@8")
	tm* pTM = new tm;
	localtime_s(pTM, pTime);
	
	strftime(BU_Time_Format_Buffer, 1024, pchFormatString, pTM);
	delete pTM;

	return BU_Time_Format_Buffer;
}