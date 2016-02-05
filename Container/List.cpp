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
#include "List.h"

DLL_FUNCTION(List*) BU_List_Create(BBTypeElement* element) {
	// Make sure the given element is valid.
	if (element == NULL)
		return NULL;
	element = (BBTypeElement*)((uint32_t*)element - 5);

	// Create our List.
	List* myList = new List;
	myList->originalType = element->type;

	// Create a fake base Type by copying data.
	myList->fakeType = new BBType;
	myList->fakeType->fieldCount = myList->originalType->fieldCount;
	myList->fakeType->free.type = myList->originalType->free.type;
	myList->fakeType->free.refCount = myList->originalType->free.refCount;
	myList->fakeType->free.fields = myList->originalType->free.fields;
	myList->fakeType->free.next = (BBTypeElement*)&myList->fakeType->free;
	myList->fakeType->free.prev = (BBTypeElement*)&myList->fakeType->free;
	myList->fakeType->used.type = myList->originalType->used.type;
	myList->fakeType->used.refCount = myList->originalType->used.refCount;
	myList->fakeType->used.fields = myList->originalType->used.fields;
	myList->fakeType->used.prev = (BBTypeElement*)&myList->fakeType->used;
	myList->fakeType->used.next = (BBTypeElement*)&myList->fakeType->used;

	// Remove element from original flow.
	element->prev->next = element->next;
	element->next->prev = element->prev;
	element->prev = NULL;
	element->next = NULL;
	element->type = myList->fakeType;

	// Store the element for later use;
	myList->storageElement = element;
	myList->storageElementFields = element->fields;

	return myList;
}

DLL_FUNCTION(void) BU_List_Destroy(List* list) {
	if (list == NULL)
		return;

	// Append remaining elements to original type.
	BBTypeElement *thisEl = NULL;
	for (thisEl = list->fakeType->used.next; thisEl != (BBTypeElement*)&list->fakeType->used; thisEl = list->fakeType->used.next) {
		// Remove from fakeType's flow.
		thisEl->prev->next = thisEl->next;
		thisEl->next->prev = thisEl->prev;

		// Append to originalType's flow.
		thisEl->prev = list->originalType->used.prev;
		thisEl->prev->next = thisEl;
		thisEl->next = (BBTypeElement*)&list->originalType->used;
		thisEl->next->prev = thisEl;
	}
	for (thisEl = list->fakeType->free.next; thisEl != (BBTypeElement*)&list->fakeType->free; thisEl = list->fakeType->free.next) {
		// Remove from fakeType's flow.
		thisEl->prev->next = thisEl->next;
		thisEl->next->prev = thisEl->prev;

		// Append to originalType's flow.
		thisEl->prev = list->originalType->free.prev;
		thisEl->prev->next = thisEl;
		thisEl->next = (BBTypeElement*)&list->originalType->free;
		thisEl->next->prev = thisEl;
	}
	
	// Append storageElement to original type.
	thisEl = list->storageElement;
	thisEl->prev = list->originalType->used.prev;
	thisEl->prev->next = thisEl;
	thisEl->next = (BBTypeElement*)&list->originalType->used;
	thisEl->next->prev = thisEl;
	thisEl->type = list->originalType;
	thisEl->fields = list->storageElementFields;

	// Delete custom objects.
	delete list->fakeType;
	delete list;
}

DLL_FUNCTION(uint32_t) BU_List_First(List* list) {
	if (list == NULL)
		return FALSE;

	BBTypeElement* element = list->fakeType->used.next;
	if (element == (BBTypeElement*)&list->fakeType->used)
		return FALSE; // End of List.

	// Copy data from selected element.
	list->storageElement->fields = element->fields;

	// Make deletion easier
	list->storageElement->next = element;
	list->storageElement->prev = element;

	return TRUE;
}

DLL_FUNCTION(uint32_t) BU_List_Last(List* list) {
	if (list == NULL)
		return FALSE;
	
	BBTypeElement* element = list->fakeType->used.prev;
	if (element == (BBTypeElement*)&list->fakeType->used)
		return FALSE; // End of List.

	// Copy data from selected element.
	list->storageElement->fields = element->fields;

	// Make deletion easier
	list->storageElement->next = element;
	list->storageElement->prev = element;

	return TRUE;
}

DLL_FUNCTION(uint32_t) BU_List_Previous(List* list) {
	if (list == NULL)
		return FALSE;

	BBTypeElement* element = list->storageElement->prev->prev;
	if (element == (BBTypeElement*)&list->fakeType->used)
		return FALSE; // End of List.

	// Copy data from selected element.
	list->storageElement->fields = element->fields;

	// Make deletion easier
	list->storageElement->next = element;
	list->storageElement->prev = element;

	return TRUE;
}

DLL_FUNCTION(uint32_t) BU_List_Next(List* list) {
	if (list == NULL)
		return FALSE;

	BBTypeElement* element = list->storageElement->next->next;
	if (element == (BBTypeElement*)&list->fakeType->used)
		return FALSE; // End of List.

	// Copy data from selected element.
	list->storageElement->fields = element->fields;

	// Make deletion easier
	list->storageElement->next = element;
	list->storageElement->prev = element;

	return TRUE;
}

DLL_FUNCTION(uint32_t) BU_List_Before(List* list, BBTypeElement* other) {
	if (list == NULL)
		return FALSE;
	if (other == NULL)
		return FALSE;

	other = (BBTypeElement*)((uint32_t*)other - 5);
	if (other->type != list->fakeType)
		return FALSE;

	BBTypeElement* element = other->prev;
	if (element == (BBTypeElement*)&list->fakeType->used)
		return FALSE; // End of List.

	// Copy data from selected element.
	list->storageElement->fields = element->fields;

	// Make deletion easier
	list->storageElement->next = element;
	list->storageElement->prev = element;

	return TRUE;
}

DLL_FUNCTION(uint32_t) BU_List_After(List* list, BBTypeElement* other) {
	if (list == NULL)
		return FALSE;
	if (other == NULL)
		return FALSE;

	other = (BBTypeElement*)((uint32_t*)other - 5);
	if (other->type != list->fakeType)
		return FALSE;

	BBTypeElement* element = other->next;
	if (element == (BBTypeElement*)&list->fakeType->used)
		return FALSE; // End of List.

	// Copy data from selected element.
	list->storageElement->fields = element->fields;

	// Make deletion easier
	list->storageElement->next = element;
	list->storageElement->prev = element;

	return TRUE;
}

DLL_FUNCTION(void) BU_List_Insert(List* list, BBTypeElement* element) {
	BU_List_InsertEx(list, element, NULL);
}

DLL_FUNCTION(void) BU_List_InsertEx(List* list, BBTypeElement* element, BBTypeElement* other) {
	if (list == NULL)
		return;

	// Make sure element is a valid pointer.
	if (element == NULL)
		return;
	element = (BBTypeElement*)((uint32_t*)element - 5);
	if (element->type != list->originalType)
		return; // Can't add elements from other types, could cause serious issues.

	// Make sure other is a valid pointer.
	if (other == NULL) {
		other = (BBTypeElement*)&list->fakeType->used;
	} else {
		other = (BBTypeElement*)((uint32_t*)other - 5);

		// Other element must be of the same fakeType.
		if (other->type != list->fakeType)
			return;
	}

	// Insert the element after(!) the other element.
	element->prev = other->prev;
	element->next = other;
	element->prev->next = element;
	element->next->prev = element;
	element->type = list->fakeType;
}

DLL_FUNCTION(void) BU_List_Remove(List* list, BBTypeElement* element) {
	if (list == NULL)
		return;
	if (element == NULL)
		return;
	
	element = (BBTypeElement*)((uint32_t*)element - 5);
	if (element->type != list->fakeType)
		return; // Can't remove elements from another type.

	element->type = list->originalType;
	element->prev = list->originalType->used.prev;
	element->next = (BBTypeElement*)&list->originalType->used;
	list->originalType->used.prev->next = element;
	list->originalType->used.prev = element;
}


