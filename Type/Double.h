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
#include <sstream>

DLL_FUNCTION(double_t*) BU_Double_New();
DLL_FUNCTION(double_t*) BU_Double_Copy(double_t* pRight);
DLL_FUNCTION(void) BU_Double_Destroy(double_t* pThis);

DLL_FUNCTION(const char*) BU_Double_ToString(double_t* pThis);
DLL_FUNCTION(double_t*) BU_Double_FromString(const char* pString);

DLL_FUNCTION(double_t*) BU_Double_FromF(float_t fOther);
DLL_FUNCTION(float_t) BU_Double_ToF(double_t* pThis);

DLL_FUNCTION(double_t*) BU_Double_FromI(int32_t iOther);
DLL_FUNCTION(int32_t) BU_Double_ToI(double_t* pThis);

DLL_FUNCTION(double_t*) BU_Double_FromL(int64_t* pOther);
DLL_FUNCTION(int64_t*) BU_Double_ToL(double_t* pThis);

DLL_FUNCTION(int32_t) BU_Double_Compare(double_t* pThis, double_t* pOther);

DLL_FUNCTION(double_t*) BU_Double_Set(double_t* pThis, double_t* pOther);
DLL_FUNCTION(double_t*) BU_Double_Add(double_t* pThis, double_t* pOther);
DLL_FUNCTION(double_t*) BU_Double_Sub(double_t* pThis, double_t* pOther);
DLL_FUNCTION(double_t*) BU_Double_Div(double_t* pThis, double_t* pOther);
DLL_FUNCTION(double_t*) BU_Double_Mul(double_t* pThis, double_t* pOther);
DLL_FUNCTION(double_t*) BU_Double_Mod(double_t* pThis, double_t* pOther);

DLL_FUNCTION(double_t*) BU_Double_SetF(double_t* pThis, float_t fOther);
DLL_FUNCTION(double_t*) BU_Double_AddF(double_t* pThis, float_t fOther);
DLL_FUNCTION(double_t*) BU_Double_SubF(double_t* pThis, float_t fOther);
DLL_FUNCTION(double_t*) BU_Double_DivF(double_t* pThis, float_t fOther);
DLL_FUNCTION(double_t*) BU_Double_MulF(double_t* pThis, float_t fOther);
DLL_FUNCTION(double_t*) BU_Double_ModF(double_t* pThis, float_t fOther);
