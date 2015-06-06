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

#include "BlitzList.h"

std::list<BlitzTypeInfo*>* BlitzUtility_Lists;

void BlitzList_OnProcessAttach() {
	BlitzUtility_Lists = new std::list<BlitzTypeInfo*>();
}

void BlitzList_OnProcessDetach() {
	BlitzUtility_Lists->clear();
	delete BlitzUtility_Lists;
}

DLL_EXPORT void* BlitzList_New(uint32_t* elementPtr) {
	BBVarElement* element = (BBVarElement*)(((uint32_t*)elementPtr) - 5);
	BBVarType* type = (BBVarType*)(*(((uint32_t*)elementPtr) - 2));

	// Create and initialize structure to hold information about this change.
	BlitzTypeInfo* bti = new BlitzTypeInfo();
	bti->type = type;

	// Store list pointers.
	bti->ourNextPtr = element;
	bti->ourPrevPtr = element;

	// Remove passed object from the flow of the old list.
	element->prevPtr->nextPtr = element->nextPtr;
	element->nextPtr->prevPtr = element->prevPtr;

	// Correct element next/prev pointers to no longer be inside the old list.
	element->prevPtr = (BBVarElement*)((uint32_t*)type + 1);
	element->nextPtr = (BBVarElement*)((uint32_t*)type + 1);

	BlitzUtility_Lists->push_back(bti);
	return bti;
}
#pragma comment(linker, "/EXPORT:BlitzList_New=_BlitzList_New@4")

DLL_EXPORT void BlitzList_Activate(uint32_t* list) {
	BlitzTypeInfo* bti = (BlitzTypeInfo*)list;

	// Store current pointers
	bti->lastNextPtr = bti->type->used.nextPtr;
	bti->lastPrevPtr = bti->type->used.prevPtr;

	// ... and replace them.
	bti->type->used.nextPtr = bti->ourNextPtr;
	bti->type->used.prevPtr = bti->ourPrevPtr;
}
#pragma comment(linker, "/EXPORT:BlitzList_Activate=_BlitzList_Activate@4")

DLL_EXPORT void BlitzList_Deactivate(uint32_t* list) {
	BlitzTypeInfo* bti = (BlitzTypeInfo*)list;

	// Store current pointers
	bti->ourNextPtr = bti->type->used.nextPtr;
	bti->ourPrevPtr = bti->type->used.prevPtr;

	// ... and replace them.
	bti->type->used.nextPtr = bti->lastNextPtr;
	bti->type->used.prevPtr = bti->lastPrevPtr;
}
#pragma comment(linker, "/EXPORT:BlitzList_Deactivate=_BlitzList_Deactivate@4")

DLL_EXPORT void BlitzList_Delete(uint32_t* list) {
	BlitzTypeInfo* bti = (BlitzTypeInfo*)list;
	BlitzUtility_Lists->remove(bti);
	delete bti;
}
#pragma comment(linker, "/EXPORT:BlitzList_Delete=_BlitzList_Delete@4")