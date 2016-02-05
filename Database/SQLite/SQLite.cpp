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
#include "..\BlitzPointer\BlitzPointer.h"

static int32_t __BU_SQLite_OpenSimpleError = 0;

#pragma region Core
DLL_FUNCTION(const char*) BU_SQLite_Version() {
#pragma comment(linker, "/EXPORT:BU_SQLite_Version=_BU_SQLite_Version@0")
	return sqlite3_libversion();
}

DLL_FUNCTION(int32_t) BU_SQLite_Version_Number() {
#pragma comment(linker, "/EXPORT:BU_SQLite_Version_Number=_BU_SQLite_Version_Number@0")
	return sqlite3_libversion_number();
}

DLL_FUNCTION(const char*) BU_SQLite_SourceID() {
#pragma comment(linker, "/EXPORT:BU_SQLite_SourceID=_BU_SQLite_SourceID@0")
	return sqlite3_sourceid();
}

DLL_FUNCTION(int32_t) BU_SQLite_CompileOption_Used(const char* zOptName) {
#pragma comment(linker, "/EXPORT:BU_SQLite_CompileOption_Used=_BU_SQLite_CompileOption_Used@4")
	return sqlite3_compileoption_used(zOptName);
}

DLL_FUNCTION(const char*) BU_SQLite_CompileOption_Get(int32_t n) {
#pragma comment(linker, "/EXPORT:BU_SQLite_CompileOption_Get=_BU_SQLite_CompileOption_Get@4")
	return sqlite3_compileoption_get(n);
}

DLL_FUNCTION(int32_t) BU_SQLite_ThreadSafe() {
#pragma comment(linker, "/EXPORT:BU_SQLite_ThreadSafe=_BU_SQLite_ThreadSafe@0")
	return sqlite3_threadsafe();
}

DLL_FUNCTION(int32_t) BU_SQLite_Initialize() {
#pragma comment(linker, "/EXPORT:BU_SQLite_Initialize=_BU_SQLite_Initialize@0")
	return sqlite3_initialize();
}

DLL_FUNCTION(int32_t) BU_SQLite_Shutdown() {
#pragma comment(linker, "/EXPORT:BU_SQLite_Shutdown=_BU_SQLite_Shutdown@0")
	return sqlite3_shutdown();
}

DLL_FUNCTION(int32_t) BU_SQLite_Sleep(int32_t ms) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Sleep=_BU_SQLite_Sleep@4")
	return sqlite3_sleep(ms);
}
#pragma endregion Core

#pragma region Open & Close
DLL_FUNCTION(int32_t) BU_SQLite_Open(const char* file, sqlite3** db) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Open=_BU_SQLite_Open@8")
	return sqlite3_open(file, db);
}

DLL_FUNCTION(int32_t) BU_SQLite_Open_V2(const char* file, sqlite3** db, int32_t flags, const char* zVfs) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Open_V2=_BU_SQLite_Open_V2@16")
	return sqlite3_open_v2(file, db, flags, zVfs);
}

DLL_FUNCTION(int32_t) BU_SQLite_Close(sqlite3* db) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Close=_BU_SQLite_Close@4")
	return sqlite3_close(db);
}

DLL_FUNCTION(int32_t) BU_SQLite_Close_V2(sqlite3* db) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Close_V2=_BU_SQLite_Close_V2@4")
	return sqlite3_close_v2(db);
}

// Simple Open() and Open_V2()
DLL_FUNCTION(sqlite3*) BU_SQLite_OpenSimple(const char* file) {
#pragma comment(linker, "/EXPORT:BU_SQLite_OpenSimple=_BU_SQLite_OpenSimple@4")
	sqlite3** db = new sqlite3*();
	__BU_SQLite_OpenSimpleError = sqlite3_open(file, db);
	sqlite3* ret = *db; delete db; return ret;
}

DLL_FUNCTION(sqlite3*) BU_SQLite_OpenSimple_V2(const char* file, int32_t flags, const char* zVfs) {
#pragma comment(linker, "/EXPORT:BU_SQLite_OpenSimple_V2=_BU_SQLite_OpenSimple_V2@12")
	sqlite3** db = new sqlite3*();
	__BU_SQLite_OpenSimpleError = sqlite3_open_v2(file, db, flags, zVfs);
	sqlite3* ret = *db;
	delete db;
	return ret;
}

DLL_FUNCTION(int32_t) BU_SQLite_OpenSimpleError() {
#pragma comment(linker, "/EXPORT:BU_SQLite_OpenSimpleError=_BU_SQLite_OpenSimpleError@0")
	return __BU_SQLite_OpenSimpleError;
}
#pragma endregion Open & Close

#pragma region Error Handling
DLL_FUNCTION(int32_t) BU_SQLite_Error_Code(sqlite3* db) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Error_Code=_BU_SQLite_Error_Code@4")
	return sqlite3_errcode(db);
}

DLL_FUNCTION(int32_t) BU_SQLite_Extended_Error_Code(sqlite3* db) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Extended_Error_Code=_BU_SQLite_Extended_Error_Code@4")
	return sqlite3_extended_errcode(db);
}

DLL_FUNCTION(const char*) BU_SQLite_Error_Message(sqlite3* db) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Error_Message=_BU_SQLite_Error_Message@4")
	return sqlite3_errmsg(db);
}

DLL_FUNCTION(const char*) BU_SQLite_Error_String(int32_t errCode) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Error_String=_BU_SQLite_Error_String@4")
	return sqlite3_errstr(errCode);
}

DLL_FUNCTION(int32_t) BU_SQLite_Extended_Result_Codes(sqlite3* db, int32_t onoff) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Extended_Result_Codes=_BU_SQLite_Extended_Result_Codes@8")
	return sqlite3_extended_result_codes(db, onoff);
}
#pragma endregion Error Handling

#pragma region Busy Handler
DLL_FUNCTION(int32_t) BU_SQLite_Busy_Timeout(sqlite3* db, int32_t timeout) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Busy_Timeout=_BU_SQLite_Busy_Timeout@8")
	return sqlite3_busy_timeout(db, timeout);
}

DLL_FUNCTION(int32_t) BU_SQLite_Busy_Handler(sqlite3* db, int(*phandlerfunc)(void*, int), void* param) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Busy_Handler=_BU_SQLite_Busy_Handler@12")
	return sqlite3_busy_handler(db, phandlerfunc, param);
}

int __cdecl BU_SQLite_Busy_Handler_SimpleInternal(void* handler, int prm) {
	BP_BlitzFunction1_t lpFunctionPointer = (BP_BlitzFunction1_t)handler;
	return lpFunctionPointer((int32_t)prm);
}

DLL_FUNCTION(int32_t) BU_SQLite_Busy_Handler_Simple(sqlite3* db, BP_BlitzFunction1_t handler) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Busy_Handler_Simple=_BU_SQLite_Busy_Handler_Simple@8")
	return sqlite3_busy_handler(db, BU_SQLite_Busy_Handler_SimpleInternal, (void*)handler);
}
#pragma endregion Busy Handler

#pragma region Memory Management
DLL_FUNCTION(int64_t*) BU_SQLite_Memory_Used() {
#pragma comment(linker, "/EXPORT:BU_SQLite_Memory_Used=_BU_SQLite_Memory_Used@0")
	return new int64_t(sqlite3_memory_used());
}

DLL_FUNCTION(int64_t*) BU_SQLite_Memory_Highwater(int32_t bReset) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Memory_Highwater=_BU_SQLite_Memory_Highwater@4")
	return new int64_t(sqlite3_memory_highwater(bReset));
}

DLL_FUNCTION(int32_t) BU_SQLite_Release_Memory(int32_t bytes) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Release_Memory=_BU_SQLite_Release_Memory@4")
	return sqlite3_release_memory(bytes);
}

DLL_FUNCTION(int32_t) BU_SQLite_DB_Release_Memory(sqlite3* db) {
#pragma comment(linker, "/EXPORT:BU_SQLite_DB_Release_Memory=_BU_SQLite_DB_Release_Memory@4")
	return sqlite3_db_release_memory(db);
}

DLL_FUNCTION(void) BU_SQLite_Randomness(int32_t n, void* p) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Randomness=_BU_SQLite_Randomness@8")
	sqlite3_randomness(n, p);
}
#pragma endregion Memory Management

#pragma region Database Management & Modification
DLL_FUNCTION(int32_t) BU_SQLite_Exec(sqlite3* db, const char* sql, int(*callbackp)(void*, int, char**, char**), void* param, char** errMsg) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Exec=_BU_SQLite_Exec@20")
	return sqlite3_exec(db, sql, callbackp, param, errMsg);
}

DLL_FUNCTION(int64_t*) BU_SQLite_Last_Insert_RowId(sqlite3* db) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Last_Insert_RowId=_BU_SQLite_Last_Insert_RowId@4")
	return new int64_t(sqlite3_last_insert_rowid(db));
}

DLL_FUNCTION(int32_t) BU_SQLite_Changes(sqlite3* db) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Changes=_BU_SQLite_Changes@4")
	return sqlite3_changes(db);
}

DLL_FUNCTION(int32_t) BU_SQLite_Total_Changes(sqlite3* db) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Total_Changes=_BU_SQLite_Total_Changes@4")
	return sqlite3_total_changes(db);
}

DLL_FUNCTION(void) BU_SQLite_Interrupt(sqlite3* db) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Interrupt=_BU_SQLite_Interrupt@4")
	return sqlite3_interrupt(db);
}

DLL_FUNCTION(int32_t) BU_SQLite_Complete(const char* sql) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Complete=_BU_SQLite_Complete@4")
	return sqlite3_complete(sql);
}

DLL_FUNCTION(int32_t) BU_SQLite_Get_Table(sqlite3* db, const char* zSql, char*** pazResult, int32_t* pnRow, int32_t* pnColumn, char** pzErrMessage) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Get_Table=_BU_SQLite_Get_Table@24")
	return sqlite3_get_table(db, zSql, pazResult, pnRow, pnColumn, pzErrMessage);
}

DLL_FUNCTION(void) BU_SQLite_Free_Table(char** result) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Free_Table=_BU_SQLite_Free_Table@4")
	sqlite3_free_table(result);
}

DLL_FUNCTION(int32_t) BU_SQLite_Set_Authorizer(sqlite3* db,
											  int(*xAuth)(void*, int, const char*, const char*, const char*, const char*),
											  void *pArg) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Set_Authorizer=_BU_SQLite_Set_Authorizer@12")
	return sqlite3_set_authorizer(db, xAuth, pArg);
}

DLL_FUNCTION(void*) BU_SQLite_Trace(sqlite3* db,
								   void(*xTrace)(void*, const char*),
								   void* param) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Trace=_BU_SQLite_Trace@12")
	return sqlite3_trace(db, xTrace, param);
}

DLL_FUNCTION(void*) BU_SQLite_Profile(sqlite3* db,
									  void(*xProfile)(void*, const char*, sqlite3_uint64),
									  void* param) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Profile=_BU_SQLite_Profile@12")
	return sqlite3_profile(db, xProfile, param);
}

DLL_FUNCTION(void) BU_SQLite_Progress_Handler(sqlite3* db, int32_t nOps, int32_t(*xProgress)(void*), void* pArg) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Progress_Handler=_BU_SQLite_Progress_Handler@16")
	sqlite3_progress_handler(db, nOps, xProgress, pArg);
}

DLL_FUNCTION(const char*) BU_SQLite_URI_Parameter(const char* zFilename, const char* zParam) {
#pragma comment(linker, "/EXPORT:BU_SQLite_URI_Parameter=_BU_SQLite_URI_Parameter@8")
	return sqlite3_uri_parameter(zFilename, zParam);
}

DLL_FUNCTION(int32_t) BU_SQLite_URI_Boolean(const char* zFilename, const char* zParam, int32_t bDefault) {
#pragma comment(linker, "/EXPORT:BU_SQLite_URI_Boolean=_BU_SQLite_URI_Boolean@12")
	return sqlite3_uri_boolean(zFilename, zParam, bDefault);
}

DLL_FUNCTION(int64_t*) BU_SQLite_URI_LongLong(const char* zFilename, const char* zParam, int64_t* bDefault) {
#pragma comment(linker, "/EXPORT:BU_SQLite_URI_LongLong=_BU_SQLite_URI_LongLong@12")
	return new int64_t(sqlite3_uri_int64(zFilename, zParam, *bDefault));
}

DLL_FUNCTION(int32_t) BU_SQLite_Limit(sqlite3* db, int32_t id, int32_t newVal) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Limit=_BU_SQLite_Limit@12")
	return sqlite3_limit(db, id, newVal);
}
#pragma endregion Database Management & Modification

#pragma region Prepared Statements
DLL_FUNCTION(sqlite3_stmt*) BU_SQLite_Next_Statement(sqlite3* db, sqlite3_stmt* pStmt) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Next_Statement=_BU_SQLite_Next_Statement@8")
	return sqlite3_next_stmt(db, pStmt);
}

DLL_FUNCTION(int32_t) BU_SQLite_Prepare(sqlite3* db, const char* zSql, int32_t nByte, sqlite3_stmt** ppStmt, const char** pzTail) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Prepare=_BU_SQLite_Prepare@20")
	return sqlite3_prepare(db, zSql, nByte, ppStmt, pzTail);
}

DLL_FUNCTION(int32_t) BU_SQLite_Prepare_V2(sqlite3* db, const char* zSql, int32_t nByte, sqlite3_stmt** ppStmt, const char** pzTail) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Prepare_V2=_BU_SQLite_Prepare_V2@20")
	return sqlite3_prepare_v2(db, zSql, nByte, ppStmt, pzTail);
}

DLL_FUNCTION(int32_t) BU_SQLite_Statement_ReadOnly(sqlite3_stmt* pStmt) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Statement_ReadOnly=_BU_SQLite_Statement_ReadOnly@4")
	return sqlite3_stmt_readonly(pStmt);
}

DLL_FUNCTION(int32_t) BU_SQLite_Statement_Busy(sqlite3_stmt* pStmt) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Statement_Busy=_BU_SQLite_Statement_Busy@4")
	return sqlite3_stmt_busy(pStmt);
}

DLL_FUNCTION(int32_t) BU_SQLite_Statement_Status(sqlite3_stmt* pStmt, int32_t op, int32_t resetFlag) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Statement_Status=_BU_SQLite_Statement_Status@12")
	return sqlite3_stmt_status(pStmt, op, resetFlag);
}

DLL_FUNCTION(const char*) BU_SQLite_SQL(sqlite3_stmt* pStmt) {
#pragma comment(linker, "/EXPORT:BU_SQLite_SQL=_BU_SQLite_SQL@4")
	return sqlite3_sql(pStmt);
}

DLL_FUNCTION(sqlite3*) BU_SQLite_Database_Handle(sqlite3_stmt* pStmt) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Database_Handle=_BU_SQLite_Database_Handle@4")
	return sqlite3_db_handle(pStmt);
}

DLL_FUNCTION(int32_t) BU_SQLite_Bind_Null(sqlite3_stmt* pStmt, int32_t index) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Bind_Null=_BU_SQLite_Bind_Null@8")
	return sqlite3_bind_null(pStmt, index);
}

DLL_FUNCTION(int32_t) BU_SQLite_Bind_Int(sqlite3_stmt* pStmt, int32_t index, int32_t value) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Bind_Int=_BU_SQLite_Bind_Int@12")
	return sqlite3_bind_int(pStmt, index, value);
}

DLL_FUNCTION(int32_t) BU_SQLite_Bind_LongLong(sqlite3_stmt* pStmt, int32_t index, int64_t* pValue) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Bind_LongLong=_BU_SQLite_Bind_LongLong@12")
	return sqlite3_bind_int64(pStmt, index, *pValue);
}

DLL_FUNCTION(int32_t) BU_SQLite_Bind_Float(sqlite3_stmt* pStmt, int32_t index, float_t value) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Bind_Float=_BU_SQLite_Bind_Float@12")
	return sqlite3_bind_double(pStmt, index, (double_t)value);
}

DLL_FUNCTION(int32_t) BU_SQLite_Bind_Double(sqlite3_stmt* pStmt, int32_t index, double_t* pValue) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Bind_Double=_BU_SQLite_Bind_Double@12")
	return sqlite3_bind_double(pStmt, index, *pValue);
}

DLL_FUNCTION(int32_t) BU_SQLite_Bind_Text(sqlite3_stmt* pStmt, int32_t index, const char* zData, int32_t nData) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Bind_Text=_BU_SQLite_Bind_Text@16")
	return sqlite3_bind_text(pStmt, index, zData, nData, nullptr);
}

DLL_FUNCTION(int32_t) BU_SQLite_Bind_Blob(sqlite3_stmt* pStmt, int32_t index, void* zData, int32_t nData) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Bind_Blob=_BU_SQLite_Bind_Blob@16")
	return sqlite3_bind_blob(pStmt, index, zData, nData, nullptr);
}

DLL_FUNCTION(int32_t) BU_SQLite_Bind_Value(sqlite3_stmt* pStmt, int32_t index, const sqlite3_value* pValue) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Bind_Value=_BU_SQLite_Bind_Value@12")
	return sqlite3_bind_value(pStmt, index, pValue);
}

DLL_FUNCTION(int32_t) BU_SQLite_Bind_ZeroBlob(sqlite3_stmt* pStmt, int32_t index, int32_t bytes) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Bind_ZeroBlob=_BU_SQLite_Bind_ZeroBlob@12")
	return sqlite3_bind_zeroblob(pStmt, index, bytes);
}

DLL_FUNCTION(int32_t) BU_SQLite_Bind_Parameter_Count(sqlite3_stmt* pStmt) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Bind_Parameter_Count=_BU_SQLite_Bind_Parameter_Count@4")
	return sqlite3_bind_parameter_count(pStmt);
}

DLL_FUNCTION(const char*) BU_SQLite_Bind_Parameter_Name(sqlite3_stmt* pStmt, int32_t index) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Bind_Parameter_Name=_BU_SQLite_Bind_Parameter_Name@8")
	return sqlite3_bind_parameter_name(pStmt, index);
}

DLL_FUNCTION(int32_t) BU_SQLite_Bind_Parameter_Index(sqlite3_stmt* pStmt, const char* zName) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Bind_Parameter_Name=_BU_SQLite_Bind_Parameter_Name@8")
	return sqlite3_bind_parameter_index(pStmt, zName);
}

DLL_FUNCTION(int32_t) BU_SQLite_Clear_Bindings(sqlite3_stmt* pStmt) {
#pragma comment(linker, "/EXPORT:BU_SQLite_Clear_Bindings=_BU_SQLite_Clear_Bindings@4")
	return sqlite3_clear_bindings(pStmt);
}

DLL_FUNCTION(int32_t) BU_SQLite_Column_Count(sqlite3_stmt* pStmt) {
	return sqlite3_column_count(pStmt);
}

DLL_FUNCTION(const char*) BU_SQLite_Column_Name(sqlite3_stmt* pStmt, int32_t n) {
	return sqlite3_column_name(pStmt, n);
}

DLL_FUNCTION(const char*) BU_SQLite_Column_DeclaredType(sqlite3_stmt* pStmt, int32_t n) {
	return sqlite3_column_decltype(pStmt, n);
}

DLL_FUNCTION(int32_t) BU_SQLite_Step(sqlite3_stmt* pStmt) {
	return sqlite3_step(pStmt);
}

DLL_FUNCTION(int32_t) BU_SQLite_Data_Count(sqlite3_stmt* pStmt) {
	return sqlite3_data_count(pStmt);
}

DLL_FUNCTION(const void*) BU_SQLite_Column_Blob(sqlite3_stmt* pStmt, int32_t iCol) {
	return sqlite3_column_blob(pStmt, iCol);
}

DLL_FUNCTION(int32_t) BU_SQLite_Column_Bytes(sqlite3_stmt* pStmt, int32_t iCol) {
	return sqlite3_column_bytes(pStmt, iCol);
}

DLL_FUNCTION(float_t) BU_SQLite_Column_Float(sqlite3_stmt* pStmt, int32_t iCol) {
	return (float_t)sqlite3_column_double(pStmt, iCol);
}

DLL_FUNCTION(double_t*) BU_SQLite_Column_Double(sqlite3_stmt* pStmt, int32_t iCol) {
	return new double_t(sqlite3_column_double(pStmt, iCol));
}

DLL_FUNCTION(int32_t) BU_SQLite_Column_Int(sqlite3_stmt* pStmt, int32_t iCol) {
	return sqlite3_column_int(pStmt, iCol);
}

DLL_FUNCTION(int64_t*) BU_SQLite_Column_LongLong(sqlite3_stmt* pStmt, int32_t iCol) {
	return new int64_t(sqlite3_column_int64(pStmt, iCol));
}

DLL_FUNCTION(const char*) BU_SQLite_Column_Text(sqlite3_stmt* pStmt, int32_t iCol) {
	return (const char*)sqlite3_column_text(pStmt, iCol);
}

DLL_FUNCTION(sqlite3_value*) BU_SQLite_Column_Value(sqlite3_stmt* pStmt, int32_t iCol) {
	return sqlite3_column_value(pStmt, iCol);
}

DLL_FUNCTION(int32_t) BU_SQLite_Column_Type(sqlite3_stmt* pStmt, int32_t iCol) {
	return sqlite3_column_type(pStmt, iCol);
}

DLL_FUNCTION(int32_t) BU_SQLite_Finalize(sqlite3_stmt* pStmt) {
	return sqlite3_finalize(pStmt);
}

DLL_FUNCTION(int32_t) BU_SQLite_Reset(sqlite3_stmt* pStmt) {
	return sqlite3_reset(pStmt);
}
#pragma endregion Prepared Statements

#pragma region SQLite Values
DLL_FUNCTION(const void*) BU_SQLite_Value_Blob(sqlite3_value* pValue) {
	return sqlite3_value_blob(pValue);
}

DLL_FUNCTION(int32_t) BU_SQLite_Value_Bytes(sqlite3_value* pValue) {
	return sqlite3_value_bytes(pValue);
}

DLL_FUNCTION(int32_t) BU_SQLite_Value_Int(sqlite3_value* pValue) {
	return sqlite3_value_int(pValue);
}

DLL_FUNCTION(int64_t*) BU_SQLite_Value_LongLong(sqlite3_value* pValue) {
	return new int64_t(sqlite3_value_int64(pValue));
}

DLL_FUNCTION(float_t) BU_SQLite_Value_Float(sqlite3_value* pValue) {
	return (float_t)sqlite3_value_double(pValue);
}

DLL_FUNCTION(double_t*) BU_SQLite_Value_Double(sqlite3_value* pValue) {
	return new double_t(sqlite3_value_double(pValue));
}

DLL_FUNCTION(const char*) BU_SQLite_Value_Text(sqlite3_value* pValue) {
	return (const char*)sqlite3_value_text(pValue);
}

DLL_FUNCTION(int32_t) BU_SQLite_Value_Type(sqlite3_value* pValue) {
	return sqlite3_value_type(pValue);
}

DLL_FUNCTION(int32_t) BU_SQLite_Value_Numeric_Type(sqlite3_value* pValue) {
	return sqlite3_value_numeric_type(pValue);
}

DLL_FUNCTION(int32_t) BU_SQLite_Value_SubType(sqlite3_value* pValue) {
	return sqlite3_value_subtype(pValue);
}

DLL_FUNCTION(sqlite3_value*) BU_SQLite_Value_Duplicate(sqlite3_value* pValue) {
	return sqlite3_value_dup(pValue);
}

DLL_FUNCTION(void) BU_SQLite_Value_Free(sqlite3_value* pValue) {
	return sqlite3_value_free(pValue);
}
#pragma endregion

