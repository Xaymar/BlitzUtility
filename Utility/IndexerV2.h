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

