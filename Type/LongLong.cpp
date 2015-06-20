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
#include "LongLong.h"
#include <list>

std::list<int64_t*> blitzLLTemporary;

int64_t* DLL_CALL BU_LongLong_Create() {
	return new int64_t;
}

void DLL_CALL BU_LongLong_Destroy(int64_t* pthis) {
	delete pthis;
}

int64_t* DLL_CALL BU_LongLong_Copy(int64_t* other) {
	int64_t* pthis = new int64_t;
	*pthis = *other;
	return pthis;
}

DLL_METHOD int64_t* DLL_CALL BU_LongLong_TempCreate() {
	int64_t* val = new int64_t;
	blitzLLTemporary.push_back(val);
	return val;
}

DLL_METHOD int64_t* DLL_CALL BU_LongLong_TempCopy(int64_t* other) {
	int64_t* val = new int64_t(*other);
	blitzLLTemporary.push_back(val);
	return val;
}

DLL_METHOD void DLL_CALL BU_LongLong_SetTemp(int64_t* pthis) {
	blitzLLTemporary.push_back(pthis);
}

DLL_METHOD void DLL_CALL BU_LongLong_UnsetTemp(int64_t* pthis) {
	blitzLLTemporary.remove(pthis);
}

DLL_METHOD void DLL_CALL BU_LongLong_TempCleanup() {
	auto iterEnd = blitzLLTemporary.end();
	for (auto iter = blitzLLTemporary.begin(); iter != iterEnd; ++iter) {
		delete *iter;
	}
	blitzLLTemporary.clear();
}


void DLL_CALL BU_LongLong_Set(int64_t* pthis, int64_t* other) {
	*pthis = *other;
}

void DLL_CALL BU_LongLong_SetV(int64_t* pthis, uint32_t left, uint32_t right) {
	*pthis = ((int64_t)left << 32) + right;
}

void DLL_CALL BU_LongLong_Add(int64_t* pthis, int64_t* other) {
	*pthis += *other;
}

void DLL_CALL BU_LongLong_AddV(int64_t* pthis, uint32_t left, uint32_t right) {
	*pthis += ((int64_t)left << 32) + right;
}

void DLL_CALL BU_LongLong_Sub(int64_t* pthis, int64_t* other) {
	*pthis -= *other;
}

void DLL_CALL BU_LongLong_SubV(int64_t* pthis, uint32_t left, uint32_t right) {
	*pthis -= ((int64_t)left << 32) + right;
}

void DLL_CALL BU_LongLong_Mul(int64_t* pthis, int64_t* other) {
	*pthis *= *other;
}

void DLL_CALL BU_LongLong_MulV(int64_t* pthis, uint32_t left, uint32_t right) {
	*pthis *= ((int64_t)left << 32) + right;
}

void DLL_CALL BU_LongLong_Div(int64_t* pthis, int64_t* other) {
	*pthis *= *other;
}

void DLL_CALL BU_LongLong_DivV(int64_t* pthis, uint32_t left, uint32_t right) {
	*pthis *= ((int64_t)left << 32) + right;
}

uint32_t DLL_CALL BU_LongLong_Compare(int64_t* pthis, int64_t* other) {
	return (*pthis == *other ? 1 : 0) + (*pthis < *other ? 2 : 0) + (*pthis > *other ? 4 : 0);
}

uint32_t DLL_CALL BU_LongLong_CompareV(int64_t* pthis, uint32_t left, uint32_t right) {
	int64_t other = ((int64_t)left << 32) + right;
	return (*pthis == other ? 1 : 0) + (*pthis < other ? 2 : 0) + (*pthis > other ? 4 : 0);
}

const char* DLL_CALL BU_LongLong_ToString(int64_t* pthis) {
	std::stringstream stream;
	stream << *pthis;
	return stream.str().c_str();
}

int64_t* DLL_CALL BU_LongLong_FromString(const char* text) {
	std::stringstream stream = std::stringstream(text);
	int64_t* val = new int64_t;
	stream >> *val;
	return val;
}

int32_t DLL_CALL BU_LongLong_ToLong(int64_t* pthis, int32_t _modulus) {
	return *pthis % _modulus;
}

int64_t* DLL_CALL BU_LongLong_FromLong(int32_t left, int32_t right) {
	int64_t* val = new int64_t;
	*val = ((int64_t)left << 32) + right;
	return val;
}

int32_t DLL_CALL BU_LongLong_ToLongHigh(int64_t* pthis) {
	return (int32_t)((*pthis) >> 32);
}

int32_t DLL_CALL BU_LongLong_ToLongLow(int64_t* pthis) {
	return (int32_t)((*pthis) && 0xFFFFFFFF);
}

float_t DLL_CALL BU_LongLong_ToFloat(int64_t* pthis) {
	return (float)*pthis;
}

int64_t* DLL_CALL BU_LongLong_FromFloat(float_t other) {
	int64_t val = (int64_t)other;
	return BU_LongLong_Copy(&val);
}

double_t* DLL_CALL BU_LongLong_ToDouble(int64_t* pthis) {
	double_t* val = new double_t;
	*val = (double_t)*pthis;
	return val;
}

int64_t* DLL_CALL BU_LongLong_FromDouble(double_t* other) {
	int64_t* val = new int64_t;
	*val = (int64_t)*other;
	return val;
}

const char* DLL_CALL BU_LongLong_Serialize(int64_t* pthis) {
	return int_to_hex<int64_t>(*pthis).c_str();
}

int64_t* DLL_CALL BU_LongLong_Deserialize(const char* text) {
	int64_t val = hex_to_int<int64_t>(std::string(text));
	return BU_LongLong_Copy(&val);
}