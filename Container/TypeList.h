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

#pragma once
#include "BlitzUtility.h"
#include "Container/List.h"
#include <list>

struct BBType;
struct BBTypeElement;

struct TypeList {
	BBType *type;

	BBTypeElement *storedFirstElement, *storedLastElement;
	BBTypeElement *firstElement, *lastElement;
};

DLL_FUNCTION(TypeList*) BU_TypeList_Create(BBTypeElement* element);
#pragma comment(linker, "/EXPORT:BU_TypeList_Create=_BU_TypeList_Create@4")
DLL_FUNCTION(void) BU_TypeList_Destroy(TypeList* list);
#pragma comment(linker, "/EXPORT:BU_TypeList_Destroy=_BU_TypeList_Destroy@4")
DLL_FUNCTION(void) BU_TypeList_Activate(TypeList* list);
#pragma comment(linker, "/EXPORT:BU_TypeList_Activate=_BU_TypeList_Activate@4")
DLL_FUNCTION(void) BU_TypeList_Deactivate(TypeList* list);
#pragma comment(linker, "/EXPORT:BU_TypeList_Deactivate=_BU_TypeList_Deactivate@4")
