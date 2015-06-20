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

#pragma once
#include "dllmain.h"

// Reverse engineered from https://github.com/blitz-research/blitz3d/blob/master/compiler/declnode.cpp
enum BBVarType {
	Global = 0,
	Int = 1,
	Float = 2,
	String = 4,
	Type = 5,
	Array = 6
};

// Basic Blitz Variable
struct BBVar {
	uint32_t type;
	uint32_t value;
};

// Basic Type predefinition.
struct BBType;

// Basic Type Element
struct BBTypeElement {
	uint32_t* fields;
	BBTypeElement* next;
	BBTypeElement* prev;
	BBType* type;
	unsigned int refCount;
};

// Basic Type
struct BBType {
	uint32_t type;
	BBTypeElement used, free;
	uint32_t fieldCount;
};

// List struct.
struct List {
	BBType* originalType;
	BBType* fakeType;

	BBTypeElement* storageElement;
	uint32_t* storageElementFields;
};

DLL_METHOD List* DLL_CALL BU_List_Create(BBTypeElement* element);
#pragma comment(linker, "/EXPORT:BU_List_Create=_BU_List_Create@4")
DLL_METHOD void DLL_CALL BU_List_Destroy(List* list);
#pragma comment(linker, "/EXPORT:BU_List_Destroy=_BU_List_Destroy@4")
DLL_METHOD uint32_t DLL_CALL BU_List_First(List* list);
#pragma comment(linker, "/EXPORT:BU_List_First=_BU_List_First@4")
DLL_METHOD uint32_t DLL_CALL BU_List_Last(List* list);
#pragma comment(linker, "/EXPORT:BU_List_Last=_BU_List_Last@4")
DLL_METHOD uint32_t DLL_CALL BU_List_Previous(List* list);
#pragma comment(linker, "/EXPORT:BU_List_Previous=_BU_List_Previous@4")
DLL_METHOD uint32_t DLL_CALL BU_List_Next(List* list);
#pragma comment(linker, "/EXPORT:BU_List_Next=_BU_List_Next@4")
DLL_METHOD uint32_t DLL_CALL BU_List_Before(List* list, BBTypeElement* other);
#pragma comment(linker, "/EXPORT:BU_List_Before=_BU_List_Before@8")
DLL_METHOD uint32_t DLL_CALL BU_List_After(List* list, BBTypeElement* other);
#pragma comment(linker, "/EXPORT:BU_List_After=_BU_List_After@8")
DLL_METHOD void DLL_CALL BU_List_Insert(List* list, BBTypeElement* element);
#pragma comment(linker, "/EXPORT:BU_List_Insert=_BU_List_Insert@8")
DLL_METHOD void DLL_CALL BU_List_InsertEx(List* list, BBTypeElement* element, BBTypeElement* other);
#pragma comment(linker, "/EXPORT:BU_List_InsertEx=_BU_List_InsertEx@12")
DLL_METHOD void DLL_CALL BU_List_Remove(List* list, BBTypeElement* element);
#pragma comment(linker, "/EXPORT:BU_List_Remove=_BU_List_Remove@8")
