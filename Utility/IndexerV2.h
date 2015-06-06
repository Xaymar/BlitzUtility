#pragma once
#include "dllmain.h"
#include <vector>

class IndexerV2 {
	public:
		IndexerV2();
		~IndexerV2();

		uint32_t GetIndex();
		void MarkIndex(uint32_t index);

		bool IsFree(uint32_t index);
		bool IsUsed(uint32_t index);
	private:
		struct IndexerV2Range {
			uint32_t min, max;

			IndexerV2Range(uint32_t pmin, uint32_t pmax);
		};

		std::vector<IndexerV2Range> range;
};

