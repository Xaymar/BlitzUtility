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

#include "dllmain.h"

#include <list>
#include "Containers\BlitzList.h"
#include "Database\SQLite\SQLite.h"
#include "Math\Vector2.h"
#include "Math\Vector3.h"
#include "Math\Matrix3.h"
#include "Utility\Display.h"
#include "Utility\IndexerV1.h"
#include "Utility\WindowMessageHandler.h"

bool WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	switch (fdwReason) {
		case DLL_PROCESS_ATTACH:
			// Containers
			BlitzList_OnProcessAttach();

			// Math

			// Database
			SQLite3_OnProcessAttach();

			// Utility
			Display_OnProcessAttach();
			WindowMessageHandler_OnProcessAttach();

			break;
		case DLL_PROCESS_DETACH:
			// Containers
			BlitzList_OnProcessDetach();

			// Math

			// Database
			SQLite3_OnProcessDetach();

			// Utility
			Display_OnProcessDetach();
			WindowMessageHandler_OnProcessDetach();

			break;
	}
	return TRUE;
}