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

#include "IndexerV2.h"

IndexerV2::IndexerV2() {
	this->range.reserve(32);
}


IndexerV2::~IndexerV2() {
	this->range.clear();
}

uint32_t IndexerV2::GetIndex() {
	uint32_t index = 0;

	if (this->range.size() == 0) {
		this->range.push_back(IndexerV2Range(0, 0));
	} else {
		auto range = this->range[0];

		if (range.min > 0) {
			index = --range.min;
		} else {
			index = ++range.max;
		}

		// Combine the next and current element if we need to.
		if (this->range.size() > 1) {
			auto rangeNext = this->range[1];
			
			if (rangeNext.min == (index + 1)) {
				uint32_t newMin, newMax;
				newMin = range.min;
				newMax = rangeNext.max;

				this->range.erase(this->range.begin(), this->range.begin() + 1);
				this->range.insert(this->range.begin(), IndexerV2Range(newMin, newMax));
			}
		}
	}

	return index;
}

void IndexerV2::MarkIndex(uint32_t index) {
	IndexerV2Range* rangePtr;
	uint32_t rangePtrPos;
	
	uint32_t rangeSize = this->range.size();
	for (uint32_t rangePos = 0; rangePos < rangeSize; rangePos++) {
		auto range = this->range[rangePos];

		if (index >= range.min && index <= range.max) {
			rangePtr = &range;
			rangePtrPos = rangePos;
			break;
		}
	}

	// Temporarily store the values needed for swapping.
	uint32_t leftMin, leftMax, rightMin, rightMax;
	leftMin = rangePtr->min; leftMax = index - 1;
	rightMin = index + 1; rightMax = rangePtr->max;

	// Due to us doing this instead of push_back, our vector is always sorted.
	auto rangeIter = this->range.begin() + rangePtrPos;
	this->range.erase(rangeIter);
	this->range.insert(rangeIter, IndexerV2Range(leftMin, leftMax));
	this->range.insert(rangeIter + 1, IndexerV2Range(rightMin, rightMax));
}

bool IndexerV2::IsFree(uint32_t index) {
	uint32_t rangeSize = this->range.size();
	for (uint32_t rangePos = 0; rangePos < rangeSize; rangePos++) {
		auto range = this->range[rangePos];
		if (index >= range.min && index <= range.max)
			return false;
	}
	return true;
}

bool IndexerV2::IsUsed(uint32_t index) {
	return !IsFree(index);
}

IndexerV2::IndexerV2Range::IndexerV2Range(uint32_t min, uint32_t max) {
	this->min = min;
	this->max = max;
}

DLL_EXPORT void* IndexerV2_Create() {
	IndexerV2* indexerPtr = new IndexerV2();
	return indexerPtr;
}
#pragma comment(linker, "/EXPORT:IndexerV2_Create=_IndexerV2_Create@0")

DLL_EXPORT void IndexerV2_Destroy(uint32_t indexerIntPtr) {
	IndexerV2* indexerPtr = (IndexerV2*)indexerIntPtr;
	delete indexerPtr;
}
#pragma comment(linker, "/EXPORT:IndexerV2_Destroy=_IndexerV2_Destroy@4")

DLL_EXPORT uint32_t IndexerV2_GetIndex(uint32_t indexerIntPtr) {
	IndexerV2* indexerPtr = (IndexerV2*)indexerIntPtr;
	return indexerPtr->GetIndex();
}
#pragma comment(linker, "/EXPORT:IndexerV2_GetIndex=_IndexerV2_GetIndex@4")

DLL_EXPORT uint32_t IndexerV2_IsFree(uint32_t indexerIntPtr, uint32_t index) {
	IndexerV2* indexerPtr = (IndexerV2*)indexerIntPtr;
	return indexerPtr->IsFree(index);
}
#pragma comment(linker, "/EXPORT:IndexerV2_IsFree=_IndexerV2_IsFree@8")

DLL_EXPORT uint32_t IndexerV2_IsUsed(uint32_t indexerIntPtr, uint32_t index) {
	IndexerV2* indexerPtr = (IndexerV2*)indexerIntPtr;
	return indexerPtr->IsUsed(index);
}
#pragma comment(linker, "/EXPORT:IndexerV2_IsUsed=_IndexerV2_IsUsed@8")
