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

#include "Double.h"
#include <list>

std::list<double_t*> BU_DoubleTemporary;

DLL_METHOD double_t* DLL_CALL BU_Double_Create() {
	return new double_t;
}

DLL_METHOD void DLL_CALL BU_Double_Destroy(double_t* pthis) {
	delete pthis;
}

DLL_METHOD double_t* DLL_CALL BU_Double_Copy(double_t* other) {
	double_t* pthis = new double_t;
	*pthis = *other;
	return pthis;
}

DLL_METHOD double_t* DLL_CALL BU_Double_TempCreate() {
	double_t* val = new double_t;
	BU_DoubleTemporary.push_back(val);
	return val;
}

DLL_METHOD double_t* DLL_CALL BU_Double_TempCopy(double_t* other) {
	double_t* val = new double_t(*other);
	BU_DoubleTemporary.push_back(val);
	return val;
}

DLL_METHOD void DLL_CALL BU_Double_SetTemp(double_t* pthis) {
	BU_DoubleTemporary.push_back(pthis);
}

DLL_METHOD void DLL_CALL BU_Double_UnsetTemp(double_t* pthis) {
	BU_DoubleTemporary.remove(pthis);
}

DLL_METHOD void DLL_CALL BU_Double_TempCleanup() {
	auto iterEnd = BU_DoubleTemporary.end();
	for (auto iter = BU_DoubleTemporary.begin(); iter != iterEnd; ++iter) {
		delete *iter;
	}
	BU_DoubleTemporary.clear();
}

DLL_METHOD void DLL_CALL BU_Double_Set(double_t* pthis, double_t* other) {
	*pthis = *other;
}

DLL_METHOD void DLL_CALL BU_Double_SetF(double_t* pthis, float_t other) {
	*pthis = other;
}

DLL_METHOD void DLL_CALL BU_Double_Add(double_t* pthis, double_t* other) {
	*pthis += *other;
}

DLL_METHOD void DLL_CALL BU_Double_AddF(double_t* pthis, float_t other) {
	*pthis += other;
}

DLL_METHOD void DLL_CALL BU_Double_Sub(double_t* pthis, double_t* other) {
	*pthis -= *other;
}

DLL_METHOD void DLL_CALL BU_Double_SubF(double_t* pthis, float_t other) {
	*pthis -= other;
}

DLL_METHOD void DLL_CALL BU_Double_Mul(double_t* pthis, double_t* other) {
	*pthis *= *other;
}

DLL_METHOD void DLL_CALL BU_Double_MulF(double_t* pthis, float_t other) {
	*pthis *= other;
}

DLL_METHOD void DLL_CALL BU_Double_Div(double_t* pthis, double_t* other) {
	*pthis /= *other;
}

DLL_METHOD void DLL_CALL BU_Double_DivF(double_t* pthis, float_t other) {
	*pthis /= other;
}

DLL_METHOD uint32_t DLL_CALL BU_Double_Compare(double_t* pthis, double_t* other) {
	return (*pthis == *other ? 1 : 0) + (*pthis < *other ? 2 : 0) + (*pthis > *other ? 4 : 0);
}

DLL_METHOD uint32_t DLL_CALL BU_Double_CompareF(double_t* pthis, float_t other) {
	return ((float_t)*pthis == other ? 1 : 0) + ((float_t)*pthis < other ? 2 : 0) + ((float_t)*pthis > other ? 4 : 0);
}

DLL_METHOD const char* DLL_CALL BU_Double_ToString(double_t* pthis) {
	std::stringstream stream;
	stream << *pthis;
	return stream.str().c_str();
}

DLL_METHOD double_t* DLL_CALL BU_Double_FromString(const char* text) {
	std::stringstream stream = std::stringstream(text);
	double_t* doublePtr = new double_t;
	stream >> *doublePtr;
	return doublePtr;
}

DLL_METHOD float_t DLL_CALL BU_Double_ToFloat(double_t* pthis) {
	return (float_t)*pthis;
}

DLL_METHOD double_t* DLL_CALL BU_Double_FromFloat(float_t other) {
	double_t* val = new double_t;
	*val = (double_t)other;
	return val;
}

DLL_METHOD int64_t* DLL_CALL BU_Double_ToLongLong(double_t* pthis) {
	int64_t* val = new int64_t;
	*val = (int64_t)*pthis;
	return val;
}

DLL_METHOD double_t* DLL_CALL BU_Double_FromLongLong(int64_t* other) {
	double_t* val = new double_t;
	*val = (double_t)*other;
	return val;
}

DLL_METHOD const char* DLL_CALL BU_Double_Serialize(double_t* pthis) {
	union {
		double_t real;
		int64_t integer;
	} myval;
	myval.real = *pthis;
	return int_to_hex<int64_t>(myval.integer).c_str();
}

DLL_METHOD double_t* DLL_CALL BU_Double_Deserialize(const char* text) {
	union {
		double_t real;
		int64_t integer;
	} myval;
	myval.integer = hex_to_int<int64_t>(std::string(text));
	return BU_Double_Copy(&myval.real);
}