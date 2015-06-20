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

#pragma once;
#include "TypeList.h"

DLL_METHOD TypeList* DLL_CALL BU_TypeList_Create(BBTypeElement* element) {
	// Make sure the given element is valid.
	if (element == NULL)
		return NULL;
	element = (BBTypeElement*)(((uint32_t*)element) - 5);

	// Create our TypeList.
	TypeList* list = new TypeList();
	list->type = element->type;
	list->firstElement = element;
	list->lastElement = element;

	// Remove the given element from the flow of the type.
	element->prev->next = element->next;
	element->next->prev = element->prev;
	element->prev = (BBTypeElement*)&list->type->used;
	element->next = (BBTypeElement*)&list->type->used;

	// Return the list.
	return list;
}

DLL_METHOD void DLL_CALL BU_TypeList_Destroy(TypeList* list) {
	// Make sure we have a valid list.
	if (list == NULL)
		return;

	// Append elements to the original type.
	list->firstElement->prev = list->type->used.prev;
	list->firstElement->prev->next = list->firstElement;
	list->lastElement->next = (BBTypeElement*)&list->type->used;
	list->lastElement->next->prev = list->lastElement;

	// Free our TypeList.
	delete list;
}

DLL_METHOD void DLL_CALL BU_TypeList_Activate(TypeList* list) {
	// Store current pointers
	list->storedFirstElement = list->type->used.next;
	list->storedLastElement = list->type->used.prev;

	// ... and replace them.
	list->type->used.next = list->firstElement;
	list->type->used.prev = list->lastElement;
}

DLL_METHOD void DLL_CALL BU_TypeList_Deactivate(TypeList* list) {
	// Store current pointers
	list->firstElement = list->type->used.next;
	list->lastElement = list->type->used.prev;

	// ... and replace them.
	list->type->used.next = list->storedFirstElement;
	list->type->used.prev = list->storedLastElement;
}

