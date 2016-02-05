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
#include "IndexerV1.h"

void IndexerV1::mark(uint32_t index, bool used) {
	uint8_t bit = index & 0x3F;
	index = index >> 6;

	this->indexes[index] ^= (!(uint64_t)used ^ this->indexes[index]) & (1ULL << bit);
}

bool IndexerV1::is(uint32_t index, bool used) {
	uint8_t bit = index & 0x3F;
	index = index >> 6;

	return (!!(this->indexes[index] & (1ULL << bit)) == used);
}

uint32_t IndexerV1::get() {
	bool hasFoundIndex = false;
	uint32_t foundIndex = 0;

	// Our search begins and ends at lastAssignedIndex.
	for (uint32_t indexOffset = 0; indexOffset <= INDEXER_INDEXES; indexOffset++) {
		uint32_t index = (lastAssignedIndex >> 6) + indexOffset;
		uint8_t bit = 0;

		uint64_t checkValue = this->indexes[index];
		for (uint8_t bit = 0; bit < 64; bit++) {
			if (this->is((index << 6) + bit, false)) {
				hasFoundIndex = true;
				foundIndex = (index << 6) + bit;
				break;
			}
		}
	}

	if (hasFoundIndex) {
		this->mark(foundIndex, true);
		return foundIndex;
	}
	
	return FALSE;
}

uint32_t IndexerV1::count(bool used) {
	uint32_t amount = 0;

	for (uint32_t index = 0; index <= INDEXER_INDEXES; index++) {
		uint8_t bit = 0;

		uint64_t checkValue = this->indexes[index];
		if (checkValue == !(uint64_t)!used) {
			amount += 64;
		} else {
			for (uint8_t bit = 0; bit < 64; bit++) {
				amount += this->is((index << 6) + bit, used);
			}
		}
	}

	return amount;
}

DLL_FUNCTION(IndexerV1*) BU_IndexerV1_Create() {
	return new IndexerV1();
}

DLL_FUNCTION(void) BU_IndexerV1_Destroy(IndexerV1* indexer) {
	delete indexer;
}

DLL_FUNCTION(void) BU_IndexerV1_Mark(IndexerV1* indexer, uint32_t index, uint32_t used) {
	indexer->mark(index, used != 0);
}

DLL_FUNCTION(void) BU_IndexerV1_MarkFree(IndexerV1* indexer, uint32_t index) {
	indexer->mark(index, false);
}

DLL_FUNCTION(void) BU_IndexerV1_MarkUsed(IndexerV1* indexer, uint32_t index) {
	indexer->mark(index, true);
}

DLL_FUNCTION(uint32_t) BU_IndexerV1_Is(IndexerV1* indexer, uint32_t index, uint32_t used) {
	return indexer->is(index, used != 0);
}

DLL_FUNCTION(uint32_t) BU_IndexerV1_IsFree(IndexerV1* indexer, uint32_t index) {
	return indexer->is(index, false);
}

DLL_FUNCTION(uint32_t) BU_IndexerV1_IsUsed(IndexerV1* indexer, uint32_t index) {
	return indexer->is(index, true);
}

DLL_FUNCTION(uint32_t) BU_IndexerV1_Get(IndexerV1* indexer) {
	return indexer->get();
}

DLL_FUNCTION(uint32_t) BU_IndexerV1_Count(IndexerV1* indexer, uint32_t used) {
	return indexer->count(used != 0);
}

DLL_FUNCTION(uint32_t) BU_IndexerV1_CountFree(IndexerV1* indexer) {
	return indexer->count(false);
}

DLL_FUNCTION(uint32_t) BU_IndexerV1_CountUsed(IndexerV1* indexer) {
	return indexer->count(true);
}
