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
#include "LongLong.h"
#include <list>

// Templates
template< typename T >
std::string int_to_hex(T i) {
	std::stringstream stream;
	stream
		<< std::setfill('0')
		<< std::setw(sizeof(T) * 2)
		<< std::hex
		<< i;
	return stream.str();
}

template< typename T >
T hex_to_int(std::string t) {
	T x;
	std::stringstream stream;
	stream
		<< std::hex
		<< t;
	stream
		>> x;
	return x;
}


std::list<int64_t*> blitzLLTemporary;

DLL_FUNCTION(int64_t*) BU_LongLong_Create() {
#pragma comment(linker, "/EXPORT:BU_LongLong_Create=_BU_LongLong_Create@0")
	return new int64_t;
}

DLL_FUNCTION(void) BU_LongLong_Destroy(int64_t* pthis) {
#pragma comment(linker, "/EXPORT:BU_LongLong_Destroy=_BU_LongLong_Destroy@4")
	delete pthis;
}

DLL_FUNCTION(int64_t*) BU_LongLong_Copy(int64_t* other) {
#pragma comment(linker, "/EXPORT:BU_LongLong_Copy=_BU_LongLong_Copy@4")
	return new int64_t(*other);
}


DLL_FUNCTION(int64_t*) BU_LongLong_TempCreate() {
#pragma comment(linker, "/EXPORT:BU_LongLong_TempCreate=_BU_LongLong_TempCreate@0")
	int64_t* val = new int64_t;
	blitzLLTemporary.push_back(val);
	return val;
}

DLL_FUNCTION(int64_t*) BU_LongLong_TempCopy(int64_t* other) {
#pragma comment(linker, "/EXPORT:BU_LongLong_TempCopy=_BU_LongLong_TempCopy@4")
	int64_t* val = new int64_t(*other);
	blitzLLTemporary.push_back(val);
	return val;
}

DLL_FUNCTION(void) BU_LongLong_SetTemp(int64_t* pthis) {
#pragma comment(linker, "/EXPORT:BU_LongLong_SetTemp=_BU_LongLong_SetTemp@4")
	blitzLLTemporary.push_back(pthis);
}

DLL_FUNCTION(void) BU_LongLong_UnsetTemp(int64_t* pthis) {
#pragma comment(linker, "/EXPORT:BU_LongLong_UnsetTemp=_BU_LongLong_UnsetTemp@4")
	blitzLLTemporary.remove(pthis);
}

DLL_FUNCTION(void) BU_LongLong_TempCleanup() {
#pragma comment(linker, "/EXPORT:BU_LongLong_TempCleanup=_BU_LongLong_TempCleanup@0")
	auto iterEnd = blitzLLTemporary.end();
	for (auto iter = blitzLLTemporary.begin(); iter != iterEnd; ++iter) {
		delete *iter;
	}
	blitzLLTemporary.clear();
}

DLL_FUNCTION(void) BU_LongLong_Set(int64_t* pthis, int64_t* other) {
#pragma comment(linker, "/EXPORT:BU_LongLong_Set=_BU_LongLong_Set@8")
	*pthis = *other;
}

DLL_FUNCTION(void) BU_LongLong_SetV(int64_t* pthis, int32_t left, int32_t right) {
#pragma comment(linker, "/EXPORT:BU_LongLong_SetV=_BU_LongLong_SetV@12")
	*pthis = ((int64_t)left << 32) + right;
}


DLL_FUNCTION(void) BU_LongLong_Add(int64_t* pthis, int64_t* other) {
#pragma comment(linker, "/EXPORT:BU_LongLong_Add=_BU_LongLong_Add@8")
	*pthis += *other;
}

DLL_FUNCTION(void) BU_LongLong_AddV(int64_t* pthis, int32_t left, int32_t right) {
#pragma comment(linker, "/EXPORT:BU_LongLong_AddV=_BU_LongLong_AddV@12")
	*pthis += ((int64_t)left << 32) + right;
}


DLL_FUNCTION(void) BU_LongLong_Sub(int64_t* pthis, int64_t* other) {
#pragma comment(linker, "/EXPORT:BU_LongLong_Sub=_BU_LongLong_Sub@8")
	*pthis -= *other;
}

DLL_FUNCTION(void) BU_LongLong_SubV(int64_t* pthis, int32_t left, int32_t right) {
#pragma comment(linker, "/EXPORT:BU_LongLong_SubV=_BU_LongLong_SubV@12")
	*pthis -= ((int64_t)left << 32) + right;
}


DLL_FUNCTION(void) BU_LongLong_Mul(int64_t* pthis, int64_t* other) {
#pragma comment(linker, "/EXPORT:BU_LongLong_Mul=_BU_LongLong_Mul@8")
	*pthis *= *other;
}

DLL_FUNCTION(void) BU_LongLong_MulV(int64_t* pthis, int32_t left, int32_t right) {
#pragma comment(linker, "/EXPORT:BU_LongLong_MulV=_BU_LongLong_MulV@12")
	*pthis *= ((int64_t)left << 32) + right;
}


DLL_FUNCTION(void) BU_LongLong_Div(int64_t* pthis, int64_t* other) {
#pragma comment(linker, "/EXPORT:BU_LongLong_Div=_BU_LongLong_Div@8")
	*pthis /= *other;
}

DLL_FUNCTION(void) BU_LongLong_DivV(int64_t* pthis, int32_t left, int32_t right) {
#pragma comment(linker, "/EXPORT:BU_LongLong_DivV=_BU_LongLong_DivV@12")
	*pthis /= ((int64_t)left << 32) + right;
}


DLL_FUNCTION(void) BU_LongLong_Modulo(int64_t* pThis, int64_t* pOther) {
#pragma comment(linker, "/EXPORT:BU_LongLong_Modulo=_BU_LongLong_Modulo@8")
	*pThis %= *pOther;
}

DLL_FUNCTION(void) BU_LongLong_ModuloV(int64_t* pThis, int32_t left, int32_t right) {
#pragma comment(linker, "/EXPORT:BU_LongLong_ModuloV=_BU_LongLong_ModuloV@12")
	*pThis %= (((uint64_t)left << 32) + (uint64_t)right);
}


DLL_FUNCTION(void) BU_LongLong_ShiftLeft(int64_t* pThis, int32_t left) {
#pragma comment(linker, "/EXPORT:BU_LongLong_ShiftLeft=_BU_LongLong_ShiftLeft@8")
	*pThis <<= left;
}

DLL_FUNCTION(void) BU_LongLong_ShiftRight(int64_t* pThis, int32_t right) {
#pragma comment(linker, "/EXPORT:BU_LongLong_ShiftRight=_BU_LongLong_ShiftRight@8")
	*pThis >>= right;
}


DLL_FUNCTION(int32_t) BU_LongLong_Compare(int64_t* pthis, int64_t* other) {
#pragma comment(linker, "/EXPORT:BU_LongLong_Compare=_BU_LongLong_Compare@8")
	return (*pthis == *other ? 1 : 0) + (*pthis < *other ? 2 : 0) + (*pthis > *other ? 4 : 0);
}

DLL_FUNCTION(int32_t) BU_LongLong_CompareV(int64_t* pthis, int32_t left, int32_t right) {
#pragma comment(linker, "/EXPORT:BU_LongLong_CompareV=_BU_LongLong_CompareV@12")
	int64_t other = ((int64_t)left << 32) + right;
	return (*pthis == other ? 1 : 0) + (*pthis < other ? 2 : 0) + (*pthis > other ? 4 : 0);
}

DLL_FUNCTION(const char*) BU_LongLong_ToString(int64_t* pthis) {
#pragma comment(linker, "/EXPORT:BU_LongLong_ToString=_BU_LongLong_ToString@4")
	std::stringstream stream;
	stream << (*pthis);
	return stream.str().c_str();
}

DLL_FUNCTION(int64_t*) BU_LongLong_FromString(const char* text) {
#pragma comment(linker, "/EXPORT:BU_LongLong_FromString=_BU_LongLong_FromString@4")
	std::stringstream stream = std::stringstream(text);
	int64_t* val = new int64_t;
	stream >> (*val);
	return val;
}

DLL_FUNCTION(int32_t) BU_LongLong_ToLong(int64_t* pthis, int32_t _modulus) {
#pragma comment(linker, "/EXPORT:BU_LongLong_ToLong=_BU_LongLong_ToLong@8")
	return *pthis % _modulus;
}

DLL_FUNCTION(int64_t*) BU_LongLong_FromLong(int32_t left, int32_t right) {
#pragma comment(linker, "/EXPORT:BU_LongLong_FromLong=_BU_LongLong_FromLong@8")
	int64_t* val = new int64_t;
	*val = ((int64_t)left << 32) + right;
	return val;
}

DLL_FUNCTION(int32_t) BU_LongLong_ToLongHigh(int64_t* pthis) {
#pragma comment(linker, "/EXPORT:BU_LongLong_ToLongHigh=_BU_LongLong_ToLongHigh@4")
	return (int32_t)((*pthis) >> 32);
}

DLL_FUNCTION(int32_t) BU_LongLong_ToLongLow(int64_t* pthis) {
#pragma comment(linker, "/EXPORT:BU_LongLong_ToLongLow=_BU_LongLong_ToLongLow@4")
	return (int32_t)((*pthis) && 0xFFFFFFFF);
}

DLL_FUNCTION(float_t) BU_LongLong_ToFloat(int64_t* pthis) {
#pragma comment(linker, "/EXPORT:BU_LongLong_ToFloat=_BU_LongLong_ToFloat@4")
	return (float)*pthis;
}

DLL_FUNCTION(int64_t*) BU_LongLong_FromFloat(float_t other) {
#pragma comment(linker, "/EXPORT:BU_LongLong_FromFloat=_BU_LongLong_FromFloat@4")
	int64_t val = (int64_t)other;
	return BU_LongLong_Copy(&val);
}

DLL_FUNCTION(double_t*) BU_LongLong_ToDouble(int64_t* pthis) {
#pragma comment(linker, "/EXPORT:BU_LongLong_ToDouble=_BU_LongLong_ToDouble@4")
	double_t* val = new double_t;
	*val = (double_t)*pthis;
	return val;
}

DLL_FUNCTION(int64_t*) BU_LongLong_FromDouble(double_t* other) {
#pragma comment(linker, "/EXPORT:BU_LongLong_FromDouble=_BU_LongLong_FromDouble@4")
	int64_t* val = new int64_t;
	*val = (int64_t)*other;
	return val;
}

DLL_FUNCTION(const char*) BU_LongLong_Serialize(int64_t* pthis) {
#pragma comment(linker, "/EXPORT:BU_LongLong_Serialize=_BU_LongLong_Serialize@4")
	return int_to_hex<int64_t>(*pthis).c_str();
}

DLL_FUNCTION(int64_t*) BU_LongLong_Deserialize(const char* text) {
#pragma comment(linker, "/EXPORT:BU_LongLong_Deserialize=_BU_LongLong_Deserialize@4")
	int64_t val = hex_to_int<int64_t>(std::string(text));
	return new int64_t(val);
}
