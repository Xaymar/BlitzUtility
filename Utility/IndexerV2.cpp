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

#include "IndexerV2.h"

IndexerV2::IndexerV2() {
	this->range.reserve(32);
}

IndexerV2::~IndexerV2() {
	this->range.clear();
}

void IndexerV2::mark(uint32_t index, bool used) {
	if (this->range.size() == 0) {
		if (used == true)
			this->range.push_back(IndexerV2Range(index, index));
	} else {
		auto iter = this->range.begin();
		for (auto iter = this->range.begin(); iter != this->range.end(); iter++) {
			if (used) {
				if ((index + 1) == iter->min) {
					iter->min--;
					break;
				} else if ((index - 1) == iter->max) {
					iter->max++;
					if ((iter + 1) != this->range.end() && iter->max == (iter + 1)->min) {
						(iter + 1)->min = iter->min;
						this->range.erase(iter);
					}
					break;
				} else if (index < iter->min) {
					this->range.insert(iter, IndexerV2Range(index, index));
					break;
				} 
			} else {
				if (index >= iter->min && index <= iter->max) {
					this->range.insert(iter - 1, IndexerV2Range(iter->min, index - 1));
					this->range.insert(iter + 1, IndexerV2Range(index + 1, iter->max));
					this->range.erase(iter); break;
				} else if (index == iter->min) {
					iter->min++;
					if (iter->min == iter->max)
						this->range.erase(iter);
					break;
				} else if (index == iter->max) {
					iter->max--;
					if (iter->min == iter->max)
						this->range.erase(iter);
					
					break;
				}
			}
		}
	}
}

bool IndexerV2::is(uint32_t index, bool used) {
	bool isUsed = false;
	for (auto iter = this->range.begin(); iter != this->range.end(); iter++) {
		if (index >= iter->min && index <= iter->max) {
			isUsed = true;
			break;
		}
	}
	return (isUsed == used);
}

uint32_t IndexerV2::get() {
	if (this->range.size() == 0) {
		this->range.push_back(IndexerV2Range(0, 0));
		return 0;
	}

	// We only need to check the first element to get a new free index.
	std::vector<IndexerV2Range>::iterator iter = this->range.begin();
	if (iter->min > 0) {
		return --iter->min;
	} else {
		if (iter->max == UINT32_MAX)
			return UINT32_MAX;

		uint32_t index = ++iter->max;

		// Check if we can combine this element with the next one.
		std::vector<IndexerV2Range>::iterator iterN = this->range.begin() + 1;
		if ((iterN != this->range.end()) && iterN->min == iter->max) {
			iter->max = iterN->max;
			this->range.erase(iterN);
		}

		return index;
	}

	return UINT32_MAX;
}

uint32_t IndexerV2::count(bool used) {
	uint32_t amount = 0;
	for (auto iter = this->range.begin(); iter != this->range.end(); iter++) {
		amount += iter->max - iter->min;
	}
	return (used ? UINT32_MAX - amount : amount);
}

IndexerV2::IndexerV2Range::IndexerV2Range(uint32_t min, uint32_t max) {
	this->min = min;
	this->max = max;
}


DLL_FUNCTION(IndexerV2*) BU_IndexerV2_Create() {
	return new IndexerV2();
}

DLL_FUNCTION(void) BU_IndexerV2_Destroy(IndexerV2* indexer) {
	delete indexer;
}

DLL_FUNCTION(void) BU_IndexerV2_Mark(IndexerV2* indexer, uint32_t used, uint32_t index) {
	indexer->mark(index, used != 0);
}

DLL_FUNCTION(void) BU_IndexerV2_MarkFree(IndexerV2* indexer, uint32_t index) {
	indexer->mark(index, false);
}

DLL_FUNCTION(void) BU_IndexerV2_MarkUsed(IndexerV2* indexer, uint32_t index) {
	indexer->mark(index, true);
}

DLL_FUNCTION(uint32_t) BU_IndexerV2_Is(IndexerV2* indexer, uint32_t index, uint32_t used) {
	return indexer->is(index, used != 0);
}

DLL_FUNCTION(uint32_t) BU_IndexerV2_IsFree(IndexerV2* indexer, uint32_t index) {
	return indexer->is(index, false);
}

DLL_FUNCTION(uint32_t) BU_IndexerV2_IsUsed(IndexerV2* indexer, uint32_t index) {
	return indexer->is(index, true);
}

DLL_FUNCTION(uint32_t) BU_IndexerV2_Get(IndexerV2* indexer) {
	return indexer->get();
}

DLL_FUNCTION(uint32_t) BU_IndexerV2_Count(IndexerV2* indexer, uint32_t used) {
	return indexer->count(used != 0);
}

DLL_FUNCTION(uint32_t) BU_IndexerV2_CountFree(IndexerV2* indexer) {
	return indexer->count(false);
}

DLL_FUNCTION(uint32_t) BU_IndexerV2_CountUsed(IndexerV2* indexer) {
	return indexer->count(true);
}
