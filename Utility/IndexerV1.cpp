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
#include "IndexerV1.h"

#define INDEX_OFF_0 0x00000000
#define INDEX_OFF_1 0x10000000
#define INDEX_OFF_2 0x20000000
#define INDEX_OFF_3 0x30000000
#define INDEX_OFF_4 0x40000000
#define INDEX_OFF_5 0x50000000
#define INDEX_OFF_6 0x60000000
#define INDEX_OFF_7 0x70000000
#define INDEX_OFF_8 0x80000000
#define INDEX_OFF_9 0x90000000
#define INDEX_OFF_A 0xA0000000
#define INDEX_OFF_B 0xB0000000
#define INDEX_OFF_C 0xC0000000
#define INDEX_OFF_D 0xD0000000
#define INDEX_OFF_E 0xE0000000
#define INDEX_OFF_F 0xF0000000

unsigned int IndexerV1::GetFreeIndex()
{
	unsigned int index = lastAssignedIndex + 1;

	bool foundIndex = false;
	char indexBitOffset = 0;

	// We use 16 offsets here to speed up the search for a free index.
	while (foundIndex == false) {
		index = index + 64;

		uint64_t toCheck = this->indexes[index >> 6];
		for (indexBitOffset = 0; indexBitOffset < 64; indexBitOffset++) {
			if ((toCheck & (1ULL << indexBitOffset)) == false) {
				foundIndex = true;
				break;
			}
		}
	}
	index = index + indexBitOffset;

	// Mark Index as in use.
	this->indexes[index >> 6] |= 1ULL << indexBitOffset;
	lastAssignedIndex = index;

	return lastAssignedIndex;
}

void IndexerV1::MarkFreeIndex(int index)
{
	unsigned short bitFlip = index % 64;

	// Mark index as unused.
	this->indexes[index >> 6] &= ~(1ULL << bitFlip);
}

DLL_EXPORT void* IndexerV1_Create() {
	IndexerV1* indexer = new IndexerV1();
	return indexer;
}
#pragma comment(linker, "/EXPORT:IndexerV1_Create=_IndexerV1_Create@0")

DLL_EXPORT int IndexerV1_GetFreeIndex(uint32_t* indexerPtr) {
	IndexerV1* indexer = (IndexerV1*)indexerPtr;
	return indexer->GetFreeIndex();
}
#pragma comment(linker, "/EXPORT:IndexerV1_GetFreeIndex=_IndexerV1_GetFreeIndex@4")

DLL_EXPORT void IndexerV1_MarkFreeIndex(uint32_t* indexerPtr, uint32_t Index) {
	IndexerV1* indexer = (IndexerV1*)indexerPtr;
	indexer->MarkFreeIndex(Index);
}
#pragma comment(linker, "/EXPORT:IndexerV1_MarkFreeIndex=_IndexerV1_MarkFreeIndex@8")

DLL_EXPORT void IndexerV1_Destroy(uint32_t* indexerPtr) {
	IndexerV1* indexer = (IndexerV1*)indexerPtr;
	delete indexer;
}
#pragma comment(linker, "/EXPORT:IndexerV1_Destroy=_IndexerV1_Destroy@4")
