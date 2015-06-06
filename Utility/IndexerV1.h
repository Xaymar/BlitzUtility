#pragma once
#include <cstdlib>
#include <list>
#include "dllmain.h"

// 67108864 = 2 ^ 32 / 64
#define INDEXER_INDEXES 67108864

/** Indexer structure helps with getting unique, unused Indexes (Ids).
  * Doing this natively would be too slow, so I'm using a DLL for this.
  */
struct IndexerV1 {
	uint64_t indexes[67108864];
	uint32_t lastAssignedIndex;

	unsigned int GetFreeIndex();
	void MarkFreeIndex(int index);
};
