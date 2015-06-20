//	Blitz - Steam wrapper for Blitz.
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
#include "Double.h"
#include <string>
#include <sstream>

#pragma region Constructor & Destructor
DLL_METHOD int64_t* DLL_CALL BU_LongLong_Create();
DLL_METHOD void DLL_CALL BU_LongLong_Destroy(int64_t* pthis);
DLL_METHOD int64_t* DLL_CALL BU_LongLong_Copy(int64_t* other);
#pragma comment(linker, "/EXPORT:BU_LongLong_Create=_BU_LongLong_Create@0")
#pragma comment(linker, "/EXPORT:BU_LongLong_Destroy=_BU_LongLong_Destroy@4")
#pragma comment(linker, "/EXPORT:BU_LongLong_Copy=_BU_LongLong_Copy@4")
#pragma endregion Constructor & Destructor

#pragma region Temporary Objects
DLL_METHOD int64_t* DLL_CALL BU_LongLong_TempCreate();
DLL_METHOD int64_t* DLL_CALL BU_LongLong_TempCopy(int64_t* other);
DLL_METHOD void DLL_CALL BU_LongLong_SetTemp(int64_t* pthis);
DLL_METHOD void DLL_CALL BU_LongLong_UnsetTemp(int64_t* pthis);
DLL_METHOD void DLL_CALL BU_LongLong_TempCleanup();
#pragma comment(linker, "/EXPORT:BU_LongLong_TempCreate=_BU_LongLong_TempCreate@0")
#pragma comment(linker, "/EXPORT:BU_LongLong_TempCopy=_BU_LongLong_TempCopy@4")
#pragma comment(linker, "/EXPORT:BU_LongLong_SetTemp=_BU_LongLong_SetTemp@4")
#pragma comment(linker, "/EXPORT:BU_LongLong_UnsetTemp=_BU_LongLong_UnsetTemp@4")
#pragma comment(linker, "/EXPORT:BU_LongLong_TempCleanup=_BU_LongLong_TempCleanup@0")
#pragma endregion Temporary Objects

#pragma region Math
DLL_METHOD void DLL_CALL BU_LongLong_Set(int64_t* pthis, int64_t* other);
DLL_METHOD void DLL_CALL BU_LongLong_SetV(int64_t* pthis, uint32_t left, uint32_t right);
#pragma comment(linker, "/EXPORT:BU_LongLong_Set=_BU_LongLong_Set@8")
#pragma comment(linker, "/EXPORT:BU_LongLong_SetV=_BU_LongLong_SetV@12")
DLL_METHOD void DLL_CALL BU_LongLong_Add(int64_t* pthis, int64_t* other);
DLL_METHOD void DLL_CALL BU_LongLong_AddV(int64_t* pthis, uint32_t left, uint32_t right);
#pragma comment(linker, "/EXPORT:BU_LongLong_Add=_BU_LongLong_Add@8")
#pragma comment(linker, "/EXPORT:BU_LongLong_AddV=_BU_LongLong_AddV@12")
DLL_METHOD void DLL_CALL BU_LongLong_Sub(int64_t* pthis, int64_t* other);
DLL_METHOD void DLL_CALL BU_LongLong_SubV(int64_t* pthis, uint32_t left, uint32_t right);
#pragma comment(linker, "/EXPORT:BU_LongLong_Sub=_BU_LongLong_Sub@8")
#pragma comment(linker, "/EXPORT:BU_LongLong_SubV=_BU_LongLong_SubV@12")
DLL_METHOD void DLL_CALL BU_LongLong_Mul(int64_t* pthis, int64_t* other);
DLL_METHOD void DLL_CALL BU_LongLong_MulV(int64_t* pthis, uint32_t left, uint32_t right);
#pragma comment(linker, "/EXPORT:BU_LongLong_Mul=_BU_LongLong_Mul@8")
#pragma comment(linker, "/EXPORT:BU_LongLong_MulV=_BU_LongLong_MulV@12")
DLL_METHOD void DLL_CALL BU_LongLong_Div(int64_t* pthis, int64_t* other);
DLL_METHOD void DLL_CALL BU_LongLong_DivV(int64_t* pthis, uint32_t left, uint32_t right);
#pragma comment(linker, "/EXPORT:BU_LongLong_Div=_BU_LongLong_Div@8")
#pragma comment(linker, "/EXPORT:BU_LongLong_DivV=_BU_LongLong_DivV@12")
#pragma endregion Math

#pragma region Comparison
DLL_METHOD uint32_t DLL_CALL BU_LongLong_Compare(int64_t* pthis, int64_t* other);
DLL_METHOD uint32_t DLL_CALL BU_LongLong_CompareV(int64_t* pthis, uint32_t left, uint32_t right);
#pragma comment(linker, "/EXPORT:BU_LongLong_Compare=_BU_LongLong_Compare@8")
#pragma comment(linker, "/EXPORT:BU_LongLong_CompareV=_BU_LongLong_CompareV@12")
#pragma endregion Comparison


#pragma region Conversion
DLL_METHOD const char* DLL_CALL BU_LongLong_ToString(int64_t* pthis);
DLL_METHOD int64_t* DLL_CALL BU_LongLong_FromString(const char* text);
#pragma comment(linker, "/EXPORT:BU_LongLong_ToString=_BU_LongLong_ToString@4")
#pragma comment(linker, "/EXPORT:BU_LongLong_FromString=_BU_LongLong_FromString@4")
DLL_METHOD int32_t DLL_CALL BU_LongLong_ToLong(int64_t* pthis, int32_t _modulus);
DLL_METHOD int64_t* DLL_CALL BU_LongLong_FromLong(int32_t left, int32_t right);
#pragma comment(linker, "/EXPORT:BU_LongLong_ToLong=_BU_LongLong_ToLong@8")
#pragma comment(linker, "/EXPORT:BU_LongLong_FromLong=_BU_LongLong_FromLong@8")
DLL_METHOD int32_t DLL_CALL BU_LongLong_ToLongHigh(int64_t* pthis);
DLL_METHOD int32_t DLL_CALL BU_LongLong_ToLongLow(int64_t* pthis);
#pragma comment(linker, "/EXPORT:BU_LongLong_ToLongHigh=_BU_LongLong_ToLongHigh@4")
#pragma comment(linker, "/EXPORT:BU_LongLong_ToLongLow=_BU_LongLong_ToLongLow@4")
DLL_METHOD float_t DLL_CALL BU_LongLong_ToFloat(int64_t* pthis);
DLL_METHOD int64_t* DLL_CALL BU_LongLong_FromFloat(float_t other);
#pragma comment(linker, "/EXPORT:BU_LongLong_ToFloat=_BU_LongLong_ToFloat@4")
#pragma comment(linker, "/EXPORT:BU_LongLong_FromFloat=_BU_LongLong_FromFloat@4")
DLL_METHOD double_t* DLL_CALL BU_LongLong_ToDouble(int64_t* pthis);
DLL_METHOD int64_t* DLL_CALL BU_LongLong_FromDouble(double_t* pthis);
#pragma comment(linker, "/EXPORT:BU_LongLong_ToDouble=_BU_LongLong_ToDouble@4")
#pragma comment(linker, "/EXPORT:BU_LongLong_FromDouble=_BU_LongLong_FromDouble@4")
#pragma endregion Conversion

#pragma region Serialization
DLL_METHOD const char* DLL_CALL BU_LongLong_Serialize(int64_t* pthis);
DLL_METHOD int64_t* DLL_CALL BU_LongLong_Deserialize(const char* text);
#pragma comment(linker, "/EXPORT:BU_LongLong_Serialize=_BU_LongLong_Serialize@4")
#pragma comment(linker, "/EXPORT:BU_LongLong_Deserialize=_BU_LongLong_Deserialize@4")
#pragma endregion Serialization
