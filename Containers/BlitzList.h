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
#include <memory>
#include <sstream>
#include <iomanip>
#include <list>

// Rev-engineered from https://github.com/blitz-research/blitz3d/blob/master/compiler/declnode.cpp
#define BBVARTYPE_GLOBAL	0
#define BBVARTYPE_INT		1
#define BBVARTYPE_FLOAT		2
#define BBVARTYPE_UNUSED	3
#define BBVARTYPE_STRING	4
#define BBVARTYPE_TYPE		5
#define BBVARTYPE_ARRAY		6

struct BBVar {
	unsigned int Type;
};

struct BBVarElement {
	int* currentPtr; // Points towards fields.
	BBVarElement* nextPtr;
	BBVarElement* prevPtr;
	void* BBVarTypePtr;
	unsigned int refCount;	// Fields usually follow here, may be at another location, see currentPtr.
};

struct BBVarType : BBVar {
	BBVarElement used, free;
	unsigned int fieldCount; // Field Info follows (Exactly <fieldCount> int pointers to variable struct)
	//BBVar* fields[];
};

struct BlitzTypeInfo {
	BBVarType *type;
	BBVarElement *lastNextPtr, *lastPrevPtr;
	BBVarElement *ourNextPtr, *ourPrevPtr;
};

void BlitzList_OnProcessAttach();
void BlitzList_OnProcessDetach();