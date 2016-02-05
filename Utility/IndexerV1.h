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
#include <cstdlib>
#include <list>
#include "BlitzUtility.h"

// 67108864 = 2 ^ 32 / 64
#define INDEXER_INDEXES 67108864 //pow(2,32) / 64 

/** Indexer structure helps with getting unique, unused Indexes (Ids).
  * Doing this natively would be too slow, so I'm using a DLL for this.
  */
struct IndexerV1 {
	uint64_t indexes[INDEXER_INDEXES];
	uint32_t lastAssignedIndex;

	void mark(uint32_t index, bool used);
	bool is(uint32_t index, bool used);
	uint32_t get();
	uint32_t count(bool used);
};

DLL_FUNCTION(IndexerV1*) BU_IndexerV1_Create();
#pragma comment(linker, "/EXPORT:BU_IndexerV1_Create=_BU_IndexerV1_Create@0")
DLL_FUNCTION(void) BU_IndexerV1_Destroy(IndexerV1* indexer);
#pragma comment(linker, "/EXPORT:BU_IndexerV1_Destroy=_BU_IndexerV1_Destroy@4")
DLL_FUNCTION(void) BU_IndexerV1_Mark(IndexerV1* indexer, uint32_t used, uint32_t index);
#pragma comment(linker, "/EXPORT:BU_IndexerV1_Mark=_BU_IndexerV1_Mark@12")
DLL_FUNCTION(void) BU_IndexerV1_MarkFree(IndexerV1* indexer, uint32_t index);
#pragma comment(linker, "/EXPORT:BU_IndexerV1_MarkFree=_BU_IndexerV1_MarkFree@8")
DLL_FUNCTION(void) BU_IndexerV1_MarkUsed(IndexerV1* indexer, uint32_t index);
#pragma comment(linker, "/EXPORT:BU_IndexerV1_MarkUsed=_BU_IndexerV1_MarkUsed@8")
DLL_FUNCTION(uint32_t) BU_IndexerV1_Is(IndexerV1* indexer, uint32_t index, uint32_t used);
#pragma comment(linker, "/EXPORT:BU_IndexerV1_Is=_BU_IndexerV1_Is@12")
DLL_FUNCTION(uint32_t) BU_IndexerV1_IsFree(IndexerV1* indexer, uint32_t index);
#pragma comment(linker, "/EXPORT:BU_IndexerV1_IsFree=_BU_IndexerV1_IsFree@8")
DLL_FUNCTION(uint32_t) BU_IndexerV1_IsUsed(IndexerV1* indexer, uint32_t index);
#pragma comment(linker, "/EXPORT:BU_IndexerV1_IsUsed=_BU_IndexerV1_IsUsed@8")
DLL_FUNCTION(uint32_t) BU_IndexerV1_Get(IndexerV1* indexer);
#pragma comment(linker, "/EXPORT:BU_IndexerV1_Get=_BU_IndexerV1_Get@4")
DLL_FUNCTION(uint32_t) BU_IndexerV1_Count(IndexerV1* indexer, uint32_t used);
#pragma comment(linker, "/EXPORT:BU_IndexerV1_Count=_BU_IndexerV1_Count@8")
DLL_FUNCTION(uint32_t) BU_IndexerV1_CountFree(IndexerV1* indexer);
#pragma comment(linker, "/EXPORT:BU_IndexerV1_CountFree=_BU_IndexerV1_CountFree@4")
DLL_FUNCTION(uint32_t) BU_IndexerV1_CountUsed(IndexerV1* indexer);
#pragma comment(linker, "/EXPORT:BU_IndexerV1_CountUsed=_BU_IndexerV1_CountUsed@4")
