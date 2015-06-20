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
#include "sqlite3.h"
#include <list>

// Basic Info
DLL_METHOD const char* DLL_CALL SQLite_Version();
DLL_METHOD int32_t DLL_CALL SQLite_ThreadSafe();

// Initialization and Finalization
DLL_METHOD int32_t DLL_CALL SQLite_Initialize();
DLL_METHOD int32_t DLL_CALL SQLite_Shutdown();

// Database Handling
DLL_METHOD int32_t DLL_CALL SQLite_Open(const char* file, sqlite3** db);
DLL_METHOD int32_t DLL_CALL SQLite_Open_V2(const char* file, sqlite3** db, int32_t flags, const char* zVfs);
DLL_METHOD int32_t DLL_CALL SQLite_Close(sqlite3* db);
DLL_METHOD int32_t DLL_CALL SQLite_Close_V2(sqlite3* db);

// Online Backup API
DLL_METHOD sqlite3_backup* SQLite_Backup_Init(sqlite3* pDest, const char* zDestName, sqlite3* pSource, const char* zSourceName);
DLL_METHOD int32_t DLL_CALL SQLite_Backup_Step(sqlite3_backup* p, int32_t nPage);
DLL_METHOD int32_t DLL_CALL SQLite_Backup_Finish(sqlite3_backup* p);
DLL_METHOD int32_t DLL_CALL SQLite_Backup_Remaining(sqlite3_backup* p);
DLL_METHOD int32_t DLL_CALL SQLite_Backup_PageCount(sqlite3_backup* p);

// Error Handling
DLL_METHOD int32_t DLL_CALL SQLite_ErrCode(sqlite3* db);
DLL_METHOD int32_t DLL_CALL SQLite_Extended_ErrCode(sqlite3* db);
DLL_METHOD const char* DLL_CALL SQLite_ErrMsg(sqlite3* db);
DLL_METHOD const char* DLL_CALL SQLite_ErrStr(int32_t errCode);

// Memory Management
DLL_METHOD int32_t DLL_CALL SQLite_Release_Memory(int32_t bytes);
DLL_METHOD int32_t DLL_CALL SQLite_DB_Release_Memory(sqlite3* db);

// Busy Timeout
DLL_METHOD int32_t DLL_CALL SQLite_Busy_Timeout(sqlite3* db, int32_t timeout);
DLL_METHOD int32_t DLL_CALL SQLite_Busy_Handler(sqlite3* db, int32_t handler);

// Database Settings
DLL_METHOD int32_t DLL_CALL SQLite_Get_AutoCommit(sqlite3* db);

// Database Information
DLL_METHOD const char* DLL_CALL SQLite_DB_FileName(sqlite3* db, const char* zDbName);
DLL_METHOD sqlite3* DLL_CALL SQLite_DB_Handle(sqlite3_stmt* stmt);
DLL_METHOD sqlite3_mutex* DLL_CALL SQLite_DB_Mutex(sqlite3* db);

//Unsorted (Alphabetical
