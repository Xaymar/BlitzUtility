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
#include "Double.h"
#include <string>
#include <sstream>
#include <iomanip>

#pragma region Constructor & Destructor
DLL_FUNCTION(int64_t*) BU_LongLong_Create();
DLL_FUNCTION(void) BU_LongLong_Destroy(int64_t* pthis);
DLL_FUNCTION(int64_t*) BU_LongLong_Copy(int64_t* other);
#pragma endregion Constructor & Destructor

#pragma region Temporary Objects
DLL_FUNCTION(int64_t*) BU_LongLong_TempCreate();
DLL_FUNCTION(int64_t*) BU_LongLong_TempCopy(int64_t* other);
DLL_FUNCTION(void) BU_LongLong_SetTemp(int64_t* pthis);
DLL_FUNCTION(void) BU_LongLong_UnsetTemp(int64_t* pthis);
DLL_FUNCTION(void) BU_LongLong_TempCleanup();
#pragma endregion Temporary Objects

#pragma region Math
DLL_FUNCTION(void) BU_LongLong_Set(int64_t* pthis, int64_t* other);
DLL_FUNCTION(void) BU_LongLong_SetV(int64_t* pthis, int32_t left, int32_t right);

DLL_FUNCTION(void) BU_LongLong_Add(int64_t* pthis, int64_t* other);
DLL_FUNCTION(void) BU_LongLong_AddV(int64_t* pthis, int32_t left, int32_t right);

DLL_FUNCTION(void) BU_LongLong_Sub(int64_t* pthis, int64_t* other);
DLL_FUNCTION(void) BU_LongLong_SubV(int64_t* pthis, int32_t left, int32_t right);

DLL_FUNCTION(void) BU_LongLong_Mul(int64_t* pthis, int64_t* other);
DLL_FUNCTION(void) BU_LongLong_MulV(int64_t* pthis, int32_t left, int32_t right);

DLL_FUNCTION(void) BU_LongLong_Div(int64_t* pthis, int64_t* other);
DLL_FUNCTION(void) BU_LongLong_DivV(int64_t* pthis, int32_t left, int32_t right);
#pragma endregion Math

#pragma region Advanced Math
DLL_FUNCTION(void) BU_LongLong_Modulo(int64_t* pThis, int64_t* pOther);
DLL_FUNCTION(void) BU_LongLong_ModuloV(int64_t* pThis, int32_t left, int32_t right);

DLL_FUNCTION(void) BU_LongLong_ShiftLeft(int64_t* pThis, int32_t left);
DLL_FUNCTION(void) BU_LongLong_ShiftRight(int64_t* pThis, int32_t right);
#pragma endregion Advanced Math

#pragma region Comparison
DLL_FUNCTION(int32_t) BU_LongLong_Compare(int64_t* pthis, int64_t* other);
DLL_FUNCTION(int32_t) BU_LongLong_CompareV(int64_t* pthis, int32_t left, int32_t right);
#pragma endregion Comparison

#pragma region Conversion
DLL_FUNCTION(const char*) BU_LongLong_ToString(int64_t* pthis);
DLL_FUNCTION(int64_t*) BU_LongLong_FromString(const char* text);

DLL_FUNCTION(int32_t) BU_LongLong_ToLong(int64_t* pthis, int32_t _modulus);
DLL_FUNCTION(int64_t*) BU_LongLong_FromLong(int32_t left, int32_t right);
DLL_FUNCTION(int32_t) BU_LongLong_ToLongHigh(int64_t* pthis);
DLL_FUNCTION(int32_t) BU_LongLong_ToLongLow(int64_t* pthis);

DLL_FUNCTION(float_t) BU_LongLong_ToFloat(int64_t* pthis);
DLL_FUNCTION(int64_t*) BU_LongLong_FromFloat(float_t other);

DLL_FUNCTION(double_t*) BU_LongLong_ToDouble(int64_t* pthis);
DLL_FUNCTION(int64_t*) BU_LongLong_FromDouble(double_t* pthis);
#pragma endregion Conversion

#pragma region Serialization
DLL_FUNCTION(const char*) BU_LongLong_Serialize(int64_t* pthis);
DLL_FUNCTION(int64_t*) BU_LongLong_Deserialize(const char* text);
#pragma endregion Serialization
