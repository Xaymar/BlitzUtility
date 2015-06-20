;	BlitzUtility - Expanding the normal Blitz functionality.
;	Copyright (C) 2015 Project Kube (Michael Fabian Dirks)
;
;	This program is free software: you can redistribute it and/or modify
;	it under the terms of the GNU Lesser General Public License as
;	published by the Free Software Foundation, either version 3 of the 
;	License, or (at your option) any later version.
;
;	This program is distributed in the hope that it will be useful,
;	but WITHOUT ANY WARRANTY; without even the implied warranty of
;	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;	GNU General Public License for more details.
;
;	You should have received a copy of the GNU Lesser General Public License
;	along with this program.  If not, see <http:;www.gnu.org/licenses/>.

; Utility ----------------------------------------------------------------------
;-- Mass Operation
; Constants: Supported Types
Const BU_MASSOP_TYPE_DOUBLE							= 0
Const BU_MASSOP_TYPE_LONGLONG							= 1
Const BU_MASSOP_TYPE_VECTOR2							= 10
Const BU_MASSOP_TYPE_VECTOR3							= 11
; Constants: Supported OpCodes
Const BU_MASSOP_OPCODE_CREATE							= 0
Const BU_MASSOP_OPCODE_DESTROY							= 1
Const BU_MASSOP_OPCODE_COPY							= 2
Const BU_MASSOP_OPCODE_TEMPCREATE						= 5
Const BU_MASSOP_OPCODE_TEMPDESTROY						= 6
Const BU_MASSOP_OPCODE_TEMPCLEANUP						= 7
Const BU_MASSOP_OPCODE_SET								= 10
Const BU_MASSOP_OPCODE_ADD								= 11
Const BU_MASSOP_OPCODE_SUB								= 12
Const BU_MASSOP_OPCODE_MUL								= 13
Const BU_MASSOP_OPCODE_DIV								= 14
Const BU_MASSOP_OPCODE_COMPARE							= 15
; GoTo
;	leftOperand: new massop index
Const BU_MASSOP_OPCODE_GOTO							= 249
; SetOpCode
;	leftOperand: target massop index
;	rightOperand: new OpCode
Const BU_MASSOP_OPCODE_SETOPCODE						= 250
; CopyLeft
;	leftOperand: source massop index
;	rightOperand: target massop index
;	result: target position (0/leftOperand, 1/rightOperand, 2/result)
Const BU_MASSOP_OPCODE_COPYLEFT						= 251
; CopyRight
;	leftOperand: source massop index
;	rightOperand: target massop index
;	result: target position (0/leftOperand, 1/rightOperand, 2/result)
Const BU_MASSOP_OPCODE_COPYRIGHT						= 252
; CopyOut
;	leftOperand: source massop index
;	rightOperand: target massop index
;	result: target position (0/leftOperand, 1/rightOperand, 2/result)
Const BU_MASSOP_OPCODE_COPYOUT							= 253
; If - Compares the result of <leftOperand> with the result of <rightOperand>, 
;  skipping over <result> instructions if the results match.
;	leftOperand: source massop index
;	rightOperand: target massop index
;	result: amount to skip
Const BU_MASSOP_OPCODE_IF								= 254
; IfValue - Compares the result of <leftOperand> with <rightOperand>, skipping
;  over <result> instructions if the results match.
;	leftOperand: source massop index
;	rightOperand: target massop index
;	result: amount to skip
Const BU_MASSOP_OPCODE_IFVALUE							= 255

; Helpers ----------------------------------------------------------------------
Type BU_Point
	Field X,Y
End Type

Type BU_Rectangle
	Field X,Y,X2,Y2
End Type

Function BU_Helper_Window_LockPointer(HWND% = 0)
	If HWND = 0 Then
		BU_User32_ClipCursor(0)
	Else
		Local tRect.BU_Rectangle = New BU_Rectangle
		
		; Retrieve Information about the selected window.
		BU_User32_GetWindowRect(HWND, tRect)
		
		; Correct Rectangle to be inside the selected Window.
		tRect\X2=tRect\X2-1
		tRect\Y2=tRect\Y2-1
		
		; Update clipping area.
		BU_User32_ClipCursor(tRect)
		
		Delete tRect
	EndIf
End Function

Function BU_Helper_Window_LockPointerAuto(HWND=0)
	If BU_User32_GetActiveWindow() = HWND Then
		BU_Helper_Window_LockPointer(HWND)
	Else
		BU_Helper_Window_LockPointer(0)
	EndIf
End Function

Function BU_Helper_Window_MakeBorderless(HWND=0)
	If HWND = 0 Then HWND = SystemProperty("AppHwnd")
	
	; Create Storage
	Local tRect.BU_Rectangle = New BU_Rectangle
	
	; Client Information
	BU_User32_GetClientRect(HWND, tRect)
	Local clientX, clientY, clientW, clientH
	clientX = tRect\X
	clientY = tRect\Y
	clientW = tRect\X2 - clientX
	clientH = tRect\Y2 - clientY
	
	; Convert Client coordinates to screen position.
	Local tPoint.BU_Point = New BU_Point
	BU_User32_ClientToScreen(HWND, tPoint)
	Local realClientX, realClientY
	realClientX = tPoint\X
	realClientY = tPoint\Y
	Delete tPoint
	
	; Window Information
	BU_User32_GetWindowRect(HWND, tRect)
	Local windowX, windowY, windowW, windowH
	windowX = tRect\X
	windowY = tRect\Y
	windowW = tRect\X2 - windowX
	windowH = tRect\Y2 - windowY
	
	; Delete Storage
	Delete tRect
	
	; Calculate new position and size.
	Local newX, newY, newW, newH
	newX = windowX + (realClientX - windowX)
	newY = windowY + (realClientY - windowY)
	newW = clientW
	newH = clientH
	
;	DebugLog "Window:     " + RSet(windowX,8) + "," + RSet(windowY,8) + ":" + RSet(windowW,8) + "," + RSet(windowH,8)
;	DebugLog "Client:     " + RSet(clientX,8) + "," + RSet(clientY,8) + ":" + RSet(clientW,8) + "," + RSet(clientH,8)
;	DebugLog "RealClient: " + RSet(realClientX,8) + "," + RSet(realClientY,8)
;	DebugLog "Diff:       " + RSet(realClientX - windowX,8) + "," + RSet(realClientY - windowY,8) + ":" + RSet(windowW - clientW,8) + "," + RSet(windowH - clientH,8)
;	DebugLog "New:        " + RSet(newX,8) + "," + RSet(newY,8) + ":" + RSet(newW,8) + "," + RSet(newH,8)
	
	; Apply changes
	BU_User32_SetWindowLong HWND, -16, $01000000
	BU_User32_SetWindowPos HWND, 0, newX, newY, newW, newH, $4 + $10 + $20 + $40
End Function

Function BU_Helper_Window_Center(HWND=0, Monitor=0)
	Local displayEnumerator = BU_DisplayEnumerator_Create()
	Local displayAmount = BU_DisplayEnumerator_Enumerate(displayEnumerator)
	If Monitor >= displayAmount Then Monitor = displayAmount - 1
	If Monitor < 0 Then Monitor = 0
	
	; Get Display Information
	Local displayRectangle.BU_Rectangle = New BU_Rectangle
	BU_DisplayEnumerator_Retrieve displayEnumerator, Monitor, displayRectangle
	BU_DisplayEnumerator_Destroy displayEnumerator
	Local displayX, displayY, displayW, displayH
	displayX = displayRectangle\X
	displayY = displayRectangle\Y
	displayW = displayRectangle\X2 - displayRectangle\X
	displayH = displayRectangle\Y2 - displayRectangle\Y
	Delete displayRectangle
	
	; Get Window Information
	Local windowRectangle.BU_Rectangle = New BU_Rectangle
	BU_User32_GetWindowRect(HWND, windowRectangle)
	Local windowW%, windowH%
	windowW = windowRectangle\X2 - windowRectangle\X
	windowH = windowRectangle\Y2 - windowRectangle\Y
	Delete windowRectangle
	
	; Calculate new position and size.
	Local newX, newY, newW, newH
	newX = displayX + (displayW/2 - windowW/2)
	newY = displayY + (displayH/2 - windowH/2)
	newW = windowW
	newH = windowH
	
;	DebugLog "New:        " + RSet(newX,8) + "," + RSet(newY,8) + ":" + RSet(newW,8) + "," + RSet(newH,8)
	
	; Apply changes
	BU_User32_SetWindowPos HWND, 0, newX, newY, newW, newH, $1 + $4 + $10 + $20 + $40 
End Function

; Database ---------------------------------------------------------------------
;-- SQLite3
;;[Block] Return Codes / Error Codes
;; Many SQLite functions return an integer result code from the set shown
;; here in order to indicate success or failure.
;;
;; New error codes may be added in future versions of SQLite.
;Const SQLITE_OK%			= 0   ; Successful result
;Const SQLITE_ERROR%			= 1   ; SQL error or missing database
;Const SQLITE_INTERNAL%		= 2   ; Internal logic error in SQLite
;Const SQLITE_PERM%			= 3   ; Access permission denied
;Const SQLITE_ABORT%			= 4   ; Callback routine requested an abort
;Const SQLITE_BUSY%			= 5   ; The database file is locked
;Const SQLITE_LOCKED%		= 6   ; A table in the database is locked
;Const SQLITE_NOMEM%			= 7   ; A malloc() failed
;Const SQLITE_READONLY%		= 8   ; Attempt to write a readonly database
;Const SQLITE_INTERRUPT%		= 9   ; Operation terminated by SQLite3_Interrupt()
;Const SQLITE_IOERR%			= 10   ; Some kind of disk I/O error occurred
;Const SQLITE_CORRUPT%		= 11   ; The database disk image is malformed
;Const SQLITE_NOTFOUND%		= 12   ; Unknown opcode in sqlite3_file_control()
;Const SQLITE_FULL%			= 13   ; Insertion failed because database is full
;Const SQLITE_CANTOPEN%		= 14   ; Unable to open the database file
;Const SQLITE_PROTOCOL%		= 15   ; Database lock protocol error
;Const SQLITE_EMPTY%			= 16   ; Database is empty
;Const SQLITE_SCHEMA%		= 17   ; The database schema changed
;Const SQLITE_TOOBIG%		= 18   ; String or BLOB exceeds size limit
;Const SQLITE_CONSTRAINT%	= 19   ; Abort due to constraint violation
;Const SQLITE_MISMATCH%		= 20   ; Data type mismatch
;Const SQLITE_MISUSE%		= 21   ; Library used incorrectly
;Const SQLITE_NOLFS%			= 22   ; Uses OS features not supported on host
;Const SQLITE_AUTH%			= 23   ; Authorization denied
;Const SQLITE_FORMAT%		= 24   ; Auxiliary database format error
;Const SQLITE_RANGE%			= 25   ; 2nd parameter to sqlite3_bind out of range
;Const SQLITE_NOTADB%		= 26   ; File opened that is not a database file
;Const SQLITE_NOTICE%		= 27   ; Notifications from sqlite3_log()
;Const SQLITE_WARNING%		= 28   ; Warnings from sqlite3_log()
;Const SQLITE_ROW%			= 100  ; sqlite3_step() has another row ready
;Const SQLITE_DONE%			= 101  ; sqlite3_step() has finished executing
;;[End Block]
;
;;[Block] SQLite_Open Flags
;; These bit values are intended for use in the
;; 3rd parameter to the [sqlite3_open_v2()] interface.
;Const SQLITE_OPEN_READONLY%		= $00000001
;Const SQLITE_OPEN_READWRITE%	= $00000002
;Const SQLITE_OPEN_CREATE%		= $00000004
;Const SQLITE_OPEN_URI%			= $00000040
;Const SQLITE_OPEN_MEMORY%		= $00000080
;Const SQLITE_OPEN_NOMUTEX%		= $00008000
;Const SQLITE_OPEN_FULLMUTEX%	= $00010000
;Const SQLITE_OPEN_SHAREDCACHE%	= $00020000
;Const SQLITE_OPEN_PRIVATECACHE%	= $00040000
;;[End Block]
;
;;[Block] Column Type
;Const SQLITE_UNKNOWN	= 0
;Const SQLITE_INTEGER	= 1
;Const SQLITE_REAL		= 2
;Const SQLITE_FLOAT		= 2
;Const SQLITE_DOUBLE		= 2
;Const SQLITE_TEXT		= 3
;Const SQLITE_STRING		= 3
;Const SQLITE_BLOB		= 4
;Const SQLITE_NULL		= 5
;;[End Block]
;
;;[Block] Internal Types
;Type SQLite_Container
;	Field Pointer%
;End Type
;
;Type SQLite_Int64
;	Field Left%, Right%
;End Type
;;[End Block]
;
;Function SQLite_Open%(File$, Flags% = $00000006)
;	; Create a Container to hold the database pointer.
;	Local Container.SQLite_Container = New SQLite_Container
;	Local ErrCode = SQLite3_Open_V2(File, Container, Flags, 0)
;	Local Database = Container\Pointer
;	Delete Container
;	
;	If ErrCode = SQLITE_OK
;		Return Database
;	Else
;		Return False
;	EndIf
;End Function
;
;Function SQLite_Execute(Database, SQL$)
;	Return SQLite3_Exec(Database, SQL, 0, 0, 0)
;End Function
;
;Function SQLite_Prepare(Database, SQL$)
;	Local Container.SQLite_Container = New SQLite_Container
;	Local ErrCode = SQLite3_Prepare(Database, SQL$, -1, Container, 0)
;	Local Statement = Container\Pointer
;	Delete Container
;	
;	If ErrCode = SQLITE_OK
;		Return Statement
;	Else
;		Return False
;	EndIf
;End Function
;
;Global SQLite_Column_Int64_L%, SQLite_Column_Int64_R%
;Function SQLite_Column_Int64(Statement, ColumnIndex%)
;	Local Result.SQLite_Int64 = New SQLite_Int64
;	SQLite3_Column_Int64(Statement, ColumnIndex, Result)
;	SQLite_Column_Int64_L = Result\Left
;	SQLite_Column_Int64_R = Result\Right
;	Delete Result
;End Function
;
;Function SQLite_Bind_Text(Statement, ColumnIndex%, Value$)
;	Return SQLite3_Bind_Text(Statement, ColumnIndex, Value, -1, -1)
;End Function
;
;Function SQLite_Bind_Blob(Statement, ColumnIndex%, Bank)
;	If Bank <> 0 Then
;		Local Size% = BankSize(Bank)
;		Return SQLite3_Bind_Blob(Statement, ColumnIndex, Bank, Size, 0)
;	EndIf
;End Function

; Math -------------------------------------------------------------------------
;-- Vector2
Type Vector2
	Field X#, Y#
End Type

Function Vector2_Create.Vector2(X#, Y#)
	Local vec.Vector2 = New Vector2
	vec\X = X
	vec\Y = Y
	Return vec
End Function

;-- Vector3
Type Vector3
	Field X#, Y#, Z#
End Type

Function Vector3_Create.Vector3(X#, Y#, Z#)
	Local vec.Vector3 = New Vector3
	vec\X = X
	vec\Y = Y
	vec\Z = Z
	Return vec
End Function


;~IDEal Editor Parameters:
;~C#Blitz3D