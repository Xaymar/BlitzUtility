//	BlitzUtility - Expanding the normal Blitz functionality.
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

/*
#pragma once
#include "dllmain.h"
#ifndef _USE_MATH_DEFINES
	#define _USE_MATH_DEFINES
	#include <math.h>
	#undef _USE_MATH_DEFINES
#endif

struct FVector2 {
	float X, Y;

	// Constructor & Destructor
	FVector2(float V);
	FVector2(float X, float Y);
	FVector2(FVector2& V);

	// Operator Overloading
	FVector2& operator++();
	FVector2& operator--();
	bool operator>(const FVector2& r);
	bool operator<(const FVector2& r);
	bool operator==(const FVector2& r);
	bool operator>=(const FVector2& r);
	bool operator<=(const FVector2& r);
	bool operator!=(const FVector2& r);
	FVector2& operator=(const FVector2& r);
	FVector2& operator+(const FVector2& r);
	FVector2& operator-(const FVector2& r);
	FVector2& operator*(const FVector2& r);
	FVector2& operator/(const FVector2& r);
	FVector2& operator+=(const FVector2& r);
	FVector2& operator-=(const FVector2& r);
	FVector2& operator*=(const FVector2& r);
	FVector2& operator/=(const FVector2& r);

	// Operator Overloading - float
	bool operator>(const float& r);
	bool operator<(const float& r);
	bool operator==(const float& r);
	bool operator>=(const float& r);
	bool operator<=(const float& r);
	bool operator!=(const float& r);
	FVector2& operator=(const float& r);
	FVector2& operator+(const float& r);
	FVector2& operator-(const float& r);
	FVector2& operator*(const float& r);
	FVector2& operator/(const float& r);
	FVector2& operator+=(const float& r);
	FVector2& operator-=(const float& r);
	FVector2& operator*=(const float& r);
	FVector2& operator/=(const float& r);

	// Simple Math
	double length();
	void normalize();
	double distance(const FVector2 r);

	// Advanced Math
	void rotate(const double )

	// Serialization
	const char* serialize();
	static FVector2& deserialize(const char* serialized);
};

DLL_METHOD FVector2* DLL_CALL BU_FVector2_Create();
DLL_METHOD FVector2* DLL_CALL BU_FVector2_Copy(FVector2* copyVector);
DLL_METHOD void DLL_CALL BU_FVector2_Destroy();

DLL_METHOD FVector2* DLL_CALL BU_FVector2_TempCreate();
DLL_METHOD FVector2* DLL_CALL BU_FVector2_TempCopy(FVector2* copyVector);
DLL_METHOD void DLL_CALL BU_FVector2_SetTemp(FVector2* vector);
DLL_METHOD void DLL_CALL BU_FVector2_UnsetTemp(FVector2* vector);
DLL_METHOD void DLL_CALL BU_FVector2_TempCleanup();

DLL_METHOD float DLL_CALL BU_FVector2_Length(FVector2* vector);
DLL_METHOD float DLL_CALL BU_FVector2_Normalize();
DLL_METHOD float DLL_CALL BU_FVector2_Distance(FVector2* vector);
DLL_METHOD float DLL_CALL BU_FVector2_DistanceL(float X, float Y);

*/