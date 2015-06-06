#include "SQLite.h"

void SQLite3_OnProcessAttach() {
	sqlite3_initialize();
}

void SQLite3_OnProcessDetach() {
	sqlite3_shutdown();
}

/*DLL_EXPORT const char* SQLite_LibVersion() {
	return sqlite3_libversion();
}

DLL_EXPORT uint32_t SQLite_LibVersionNumber() {
	return sqlite3_libversion_number();
}

DLL_EXPORT uint32_t* SQLite_Open(char* dbFilename) {
	sqlite3* dbHandle;
	sqlite3_open(dbFilename, &dbHandle);
	return (uint32_t*)dbHandle;
}

DLL_EXPORT uint32_t* SQLite_Open_V2(char* dbFilename, uint32_t flags) {
	sqlite3* dbHandle;
	sqlite3_open_v2(dbFilename, &dbHandle, flags, nullptr);
	return (uint32_t*)dbHandle;
}

DLL_EXPORT void SQLite_Close(uint32_t* dbHandlePtr) {
	sqlite3* dbHandle = (sqlite3*)dbHandlePtr;
	sqlite3_close(dbHandle);
}

DLL_EXPORT int SQLite_Busy_TimeOut() {

}*/

DLL_EXPORT int sqlite3_bind_int64_ex(void* stmtPtr, uint32_t index, uint32_t low, uint32_t high) {
	return sqlite3_bind_int64((sqlite3_stmt*)stmtPtr, index, (((uint64_t)low << 32) + (uint64_t)high));
}
#pragma comment(linker, "/EXPORT:sqlite3_bind_int64_ex=_sqlite3_bind_int64_ex@16")

DLL_EXPORT int sqlite3_bind_float(void* stmtPtr, uint32_t index, float value) {
	return sqlite3_bind_double((sqlite3_stmt*)stmtPtr, index, (double)value);
}
#pragma comment(linker, "/EXPORT:sqlite3_bind_float=_sqlite3_bind_float@12")

DLL_EXPORT void sqlite3_column_int64_ex(void* stmtPtr, uint32_t index, void* outPtr) {
	sqlite3_int64 out = sqlite3_column_int64((sqlite3_stmt*)stmtPtr, index);
	uint32_t* ourPtr = (uint32_t*)outPtr;
	(*ourPtr) = (uint32_t)(out & 0xFFFFFFFF);
	(*(ourPtr + 1)) = (uint32_t)(out >> 32);
}
#pragma comment(linker, "/EXPORT:sqlite3_column_int64_ex=_sqlite3_column_int64_ex@12")

DLL_EXPORT float sqlite3_column_float(void* stmtPtr, uint32_t index) {
	double out = sqlite3_column_double((sqlite3_stmt*)stmtPtr, index);
	return (float)out;
}
#pragma comment(linker, "/EXPORT:sqlite3_column_float=_sqlite3_column_float@8")