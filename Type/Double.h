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
#include "LongLong.h"
#include <iomanip>

#pragma region Constructor & Destructor
DLL_FUNCTION(double_t*) BU_Double_Create();
DLL_FUNCTION(void) BU_Double_Destroy(double_t* pthis);
DLL_FUNCTION(double_t*) BU_Double_Copy(double_t* other);
#pragma comment(linker, "/EXPORT:BU_Double_Create=_BU_Double_Create@0")
#pragma comment(linker, "/EXPORT:BU_Double_Destroy=_BU_Double_Destroy@4")
#pragma comment(linker, "/EXPORT:BU_Double_Copy=_BU_Double_Copy@4")
#pragma endregion Constructor & Destructor

#pragma region Temporary Objects
DLL_FUNCTION(double_t*) BU_Double_TempCreate();
DLL_FUNCTION(double_t*) BU_Double_TempCopy(double_t* other);
DLL_FUNCTION(void) BU_Double_SetTemp(double_t* pthis);
DLL_FUNCTION(void) BU_Double_UnsetTemp(double_t* pthis);
DLL_FUNCTION(void) BU_Double_TempCleanup();
#pragma comment(linker, "/EXPORT:BU_Double_TempCreate=_BU_Double_TempCreate@0")
#pragma comment(linker, "/EXPORT:BU_Double_TempCopy=_BU_Double_TempCopy@4")
#pragma comment(linker, "/EXPORT:BU_Double_SetTemp=_BU_Double_SetTemp@4")
#pragma comment(linker, "/EXPORT:BU_Double_UnsetTemp=_BU_Double_UnsetTemp@4")
#pragma comment(linker, "/EXPORT:BU_Double_TempCleanup=_BU_Double_TempCleanup@0")
#pragma endregion Temporary Objects

#pragma region Math
DLL_FUNCTION(void) BU_Double_Set(double_t* pthis, double_t* other);
DLL_FUNCTION(void) BU_Double_SetF(double_t* pthis, float_t other);
#pragma comment(linker, "/EXPORT:BU_Double_Set=_BU_Double_Set@8")
#pragma comment(linker, "/EXPORT:BU_Double_SetF=_BU_Double_SetF@8")
DLL_FUNCTION(void) BU_Double_Add(double_t* pthis, double_t* other);
DLL_FUNCTION(void) BU_Double_AddF(double_t* pthis, float_t other);
#pragma comment(linker, "/EXPORT:BU_Double_Add=_BU_Double_Add@8")
#pragma comment(linker, "/EXPORT:BU_Double_AddF=_BU_Double_AddF@8")
DLL_FUNCTION(void) BU_Double_Sub(double_t* pthis, double_t* other);
DLL_FUNCTION(void) BU_Double_SubF(double_t* pthis, float_t other);
#pragma comment(linker, "/EXPORT:BU_Double_Sub=_BU_Double_Sub@8")
#pragma comment(linker, "/EXPORT:BU_Double_SubF=_BU_Double_SubF@8")
DLL_FUNCTION(void) BU_Double_Mul(double_t* pthis, double_t* other);
DLL_FUNCTION(void) BU_Double_MulF(double_t* pthis, float_t other);
#pragma comment(linker, "/EXPORT:BU_Double_Mul=_BU_Double_Mul@8")
#pragma comment(linker, "/EXPORT:BU_Double_MulF=_BU_Double_MulF@8")
DLL_FUNCTION(void) BU_Double_Div(double_t* pthis, double_t* other);
DLL_FUNCTION(void) BU_Double_DivF(double_t* pthis, float_t other);
#pragma comment(linker, "/EXPORT:BU_Double_Div=_BU_Double_Div@8")
#pragma comment(linker, "/EXPORT:BU_Double_DivF=_BU_Double_DivF@8")
#pragma endregion Math

#pragma region Comparision
DLL_FUNCTION(uint32_t) BU_Double_Compare(double_t* pthis, double_t* other);
DLL_FUNCTION(uint32_t) BU_Double_CompareF(double_t* pthis, float_t other);
#pragma comment(linker, "/EXPORT:BU_Double_Compare=_BU_Double_Compare@8")
#pragma comment(linker, "/EXPORT:BU_Double_CompareF=_BU_Double_CompareF@8")
#pragma endregion Comparision

#pragma region Conversion
// String conversion
DLL_FUNCTION(const char*) BU_Double_ToString(double_t* pthis);
DLL_FUNCTION(double_t*) BU_Double_FromString(const char* text);
#pragma comment(linker, "/EXPORT:BU_Double_ToString=_BU_Double_ToString@4")
#pragma comment(linker, "/EXPORT:BU_Double_FromString=_BU_Double_FromString@4")
// 32-Bit Floating Point
DLL_FUNCTION(float_t) BU_Double_ToFloat(double_t* pthis);
DLL_FUNCTION(double_t*) BU_Double_FromFloat(float_t other);
#pragma comment(linker, "/EXPORT:BU_Double_ToFloat=_BU_Double_ToFloat@4")
#pragma comment(linker, "/EXPORT:BU_Double_FromFloat=_BU_Double_FromFloat@4")
// 64-Bit Integer
DLL_FUNCTION(int64_t*) BU_Double_ToLongLong(double_t* pthis);
DLL_FUNCTION(double_t*) BU_Double_FromLongLong(int64_t* other);
#pragma comment(linker, "/EXPORT:BU_Double_ToLongLong=_BU_Double_ToLongLong@4")
#pragma comment(linker, "/EXPORT:BU_Double_FromLongLong=_BU_Double_FromLongLong@4")
#pragma endregion Conversion

#pragma region Serialization
DLL_FUNCTION(const char*) BU_Double_Serialize(double_t* pthis);
DLL_FUNCTION(double_t*) BU_Double_Deserialize(const char* text);
#pragma comment(linker, "/EXPORT:BU_Double_Serialize=_BU_Double_Serialize@4")
#pragma comment(linker, "/EXPORT:BU_Double_Deserialize=_BU_Double_Deserialize@4")
#pragma endregion Serialization