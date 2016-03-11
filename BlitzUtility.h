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

// Standard Library
#include <time.h>
#include <exception>
#include <stdexcept>
#include <memory>

// Platform specific: Windows
#include <windows.h>

// Macros
#define DLL_FUNCTION(type) extern "C" __declspec(dllexport) type __stdcall

// BlitzUtility Includes
#include "Container/List.h"
#include "Container/TypeList.h"
#include "Database/SQLite/SQLite.h"
#include "Time/HighResolutionClock.h"
#include "Type/Double.h"
#include "Type/Long.h"
#include "Utility/DisplayEnumerator.h"
#include "Utility/IndexerV1.h"
#include "Utility/IndexerV2.h"
#include "Utility/MassOp.h"
#include "Utility/WindowMessageHandler.h"
