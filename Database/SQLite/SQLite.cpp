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

#include "SQLite.h"
#include "..\BlitzPointer\Include\BlitzPointer.h"

DLL_METHOD const char* DLL_CALL SQLite_Version() {
	return sqlite3_version;
}
DLL_METHOD int32_t DLL_CALL SQLite_ThreadSafe() {
	return sqlite3_threadsafe();
}

DLL_METHOD int32_t DLL_CALL SQLite_Initialize() {
	return sqlite3_initialize();
}

DLL_METHOD int32_t DLL_CALL SQLite_Shutdown() {
	return sqlite3_shutdown();
}

DLL_METHOD int32_t DLL_CALL SQLite_Open(const char* file, sqlite3** db) {
	return sqlite3_open(file, db);
}

DLL_METHOD int32_t DLL_CALL SQLite_Open_V2(const char* file, sqlite3** db, int32_t flags, const char* zVfs) {
	return sqlite3_open_v2(file, db, flags, zVfs);
}

DLL_METHOD int32_t DLL_CALL SQLite_Close(sqlite3* db) {
	return sqlite3_close(db);
}

DLL_METHOD int32_t DLL_CALL SQLite_Close_V2(sqlite3* db) {
	return sqlite3_close_v2(db);
}

DLL_METHOD int32_t DLL_CALL SQLite_ErrCode(sqlite3* db) {
	return sqlite3_errcode(db);
}

DLL_METHOD int32_t DLL_CALL SQLite_Extended_ErrCode(sqlite3* db) {
	return sqlite3_extended_errcode(db);
}

DLL_METHOD const char* DLL_CALL SQLite_ErrMsg(sqlite3* db) {
	return sqlite3_errmsg(db);
}

DLL_METHOD const char* DLL_CALL SQLite_ErrStr(int32_t errCode) {
	return sqlite3_errstr(errCode);
}

DLL_METHOD int32_t DLL_CALL SQLite_Release_Memory(int32_t bytes) {
	return sqlite3_release_memory(bytes);
}

DLL_METHOD int32_t DLL_CALL SQLite_DB_Release_Memory(sqlite3* db) {
	return sqlite3_db_release_memory(db);
}

DLL_METHOD int32_t DLL_CALL SQLite_Busy_Timeout(sqlite3* db, int32_t timeout) {
	return sqlite3_busy_timeout(db, timeout);
}

int __cdecl SQLite3_Busy_Handler_Internal(void* handler, int prm) {
	return BlitzPointer_CallFunction1((int32_t)handler, (int32_t)prm);
}

DLL_METHOD int32_t DLL_CALL SQLite_Busy_Handler(sqlite3* db, int32_t handler) {
	return sqlite3_busy_handler(db, SQLite3_Busy_Handler_Internal, (void*)handler);
}




