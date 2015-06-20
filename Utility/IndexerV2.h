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

		void mark(uint32_t index, bool used);
		bool is(uint32_t index, bool used);
		uint32_t get();
		uint32_t count(bool used);

	private:
		struct IndexerV2Range {
			uint32_t min, max;

			IndexerV2Range(uint32_t pmin, uint32_t pmax);
		};

		std::vector<IndexerV2Range> range;
};

DLL_METHOD IndexerV2* DLL_CALL BU_IndexerV2_Create();
#pragma comment(linker, "/EXPORT:BU_IndexerV2_Create=_BU_IndexerV2_Create@0")
DLL_METHOD void DLL_CALL BU_IndexerV2_Destroy(IndexerV2* indexer);
#pragma comment(linker, "/EXPORT:BU_IndexerV2_Destroy=_BU_IndexerV2_Destroy@4")
DLL_METHOD void DLL_CALL BU_IndexerV2_Mark(IndexerV2* indexer, uint32_t used, uint32_t index);
#pragma comment(linker, "/EXPORT:BU_IndexerV2_Mark=_BU_IndexerV2_Mark@12")
DLL_METHOD void DLL_CALL BU_IndexerV2_MarkFree(IndexerV2* indexer, uint32_t index);
#pragma comment(linker, "/EXPORT:BU_IndexerV2_MarkFree=_BU_IndexerV2_MarkFree@8")
DLL_METHOD void DLL_CALL BU_IndexerV2_MarkUsed(IndexerV2* indexer, uint32_t index);
#pragma comment(linker, "/EXPORT:BU_IndexerV2_MarkUsed=_BU_IndexerV2_MarkUsed@8")
DLL_METHOD uint32_t DLL_CALL BU_IndexerV2_Is(IndexerV2* indexer, uint32_t index, uint32_t used);
#pragma comment(linker, "/EXPORT:BU_IndexerV2_Is=_BU_IndexerV2_Is@12")
DLL_METHOD uint32_t DLL_CALL BU_IndexerV2_IsFree(IndexerV2* indexer, uint32_t index);
#pragma comment(linker, "/EXPORT:BU_IndexerV2_IsFree=_BU_IndexerV2_IsFree@8")
DLL_METHOD uint32_t DLL_CALL BU_IndexerV2_IsUsed(IndexerV2* indexer, uint32_t index);
#pragma comment(linker, "/EXPORT:BU_IndexerV2_IsUsed=_BU_IndexerV2_IsUsed@8")
DLL_METHOD uint32_t DLL_CALL BU_IndexerV2_Get(IndexerV2* indexer);
#pragma comment(linker, "/EXPORT:BU_IndexerV2_Get=_BU_IndexerV2_Get@4")
DLL_METHOD uint32_t DLL_CALL BU_IndexerV2_Count(IndexerV2* indexer, uint32_t used);
#pragma comment(linker, "/EXPORT:BU_IndexerV2_Count=_BU_IndexerV2_Count@8")
DLL_METHOD uint32_t DLL_CALL BU_IndexerV2_CountFree(IndexerV2* indexer);
#pragma comment(linker, "/EXPORT:BU_IndexerV2_CountFree=_BU_IndexerV2_CountFree@4")
DLL_METHOD uint32_t DLL_CALL BU_IndexerV2_CountUsed(IndexerV2* indexer);
#pragma comment(linker, "/EXPORT:BU_IndexerV2_CountUsed=_BU_IndexerV2_CountUsed@4")

