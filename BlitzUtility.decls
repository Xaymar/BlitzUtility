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

.lib "BlitzUtility.dll"
; Container --------------------------------------------------------------------
; -- List (Single Element)
BU_List_Create%(element*)
BU_List_Destroy%(list%)
BU_List_First%(list%)
BU_List_Last%(list%)
BU_List_Previous%(list%)
BU_List_Next%(list%)
BU_List_Before%(list%, other*)
BU_List_After%(list%, other*)
BU_List_Insert(list%, element*)
BU_List_InsertEx(list%, element*, other*)
BU_List_Remove(list%, element*)
; -- TypeList (Single Type)
BU_TypeList_New%(obj*)
BU_TypeList_Activate(list%)
BU_TypeList_Deactivate(list%)
BU_TypeList_Destroy(list%)

; Types ------------------------------------------------------------------------
; -- LongLong
BU_LongLong_Create%()
BU_LongLong_Destroy(LongLong%)
BU_LongLong_Copy%(LongLong%)
BU_LongLong_TempCreate%()
BU_LongLong_TempCopy%(LongLong%)
BU_LongLong_SetTemp(LongLong%)
BU_LongLong_UnsetTemp(LongLong%)
BU_LongLong_TempCleanup()
BU_LongLong_Set(LongLong%, LongLong%)
BU_LongLong_SetV(LongLong%, LongHigh%, LongLow%)
BU_LongLong_Add(LongLong%, LongLong%)
BU_LongLong_AddV(LongLong%, LongHigh%, LongLow%)
BU_LongLong_Sub(LongLong%, LongLong%)
BU_LongLong_SubV(LongLong%, LongHigh%, LongLow%)
BU_LongLong_Mul(LongLong%, LongLong%)
BU_LongLong_MulV(LongLong%, LongHigh%, LongLow%)
BU_LongLong_Div(LongLong%, LongLong%)
BU_LongLong_DivV(LongLong%, LongHigh%, LongLow%)
BU_LongLong_Compare%(LongLong%, LongLong%)
BU_LongLong_CompareV%(LongLong%, LongHigh%, LongLow%)
BU_LongLong_ToString$(LongLong%)
BU_LongLong_FromString%(String$)
BU_LongLong_ToLong%(LongLong%, Modulus%)
BU_LongLong_FromLong%(LongHigh%, LongLow%)
BU_LongLong_ToLongHigh%(LongLong%)
BU_LongLong_ToLongLow%(LongLong%)
BU_LongLong_ToFloat#(LongLong%)
BU_LongLong_FromFloat%(Float#)
BU_LongLong_ToDouble%(LongLong%)
BU_LongLong_FromDouble%(double%)
BU_LongLong_Serialize$(LongLong%)
BU_LongLong_Deserialize%(String$)
; -- Double
BU_Double_Create%()
BU_Double_Destroy(Double%)
BU_Double_Copy%(Double%)
BU_Double_TempCreate%()
BU_Double_TempCopy%(Double%)
BU_Double_SetTemp(Double%)
BU_Double_UnsetTemp(Double%)
BU_Double_TempCleanup()
BU_Double_Set(Double%, Double%)
BU_Double_SetF(Double%, Float#)
BU_Double_Add(Double%, Double%)
BU_Double_AddF(Double%, Float#)
BU_Double_Sub(Double%, Double%)
BU_Double_SubF(Double%, Float#)
BU_Double_Mul(Double%, Double%)
BU_Double_MulF(Double%, Float#)
BU_Double_Div(Double%, Double%)
BU_Double_DivF(Double%, Float#)
BU_Double_Compare%(Double%, Double%)
BU_Double_CompareF%(Double%, Float#)
BU_Double_ToString$(Double%)
BU_Double_FromString%(String$)
BU_Double_ToFloat#(Double%)
BU_Double_FromFloat%(Float#)
BU_Double_ToLongLong%(Double%)
BU_Double_FromLongLong%(LongLong%)
BU_Double_Serialize$(Double%)
BU_Double_Deserialize%(String$)

; Utility ----------------------------------------------------------------------
; -- Display Enumerator
BU_DisplayEnumerator_Create%()
BU_DisplayEnumerator_Destroy(DisplayEnumerator%)
BU_DisplayEnumerator_Enumerate%(DisplayEnumerator%)
BU_DisplayEnumerator_Count%(DisplayEnumerator%)
BU_DisplayEnumerator_Retrieve(DisplayEnumerator%, index%, Rect*)
; -- Indexer V1 (Array)
BU_IndexerV1_Create%()
BU_IndexerV1_Destroy(Indexer%)
BU_IndexerV1_Mark(Indexer%, Used%)
BU_IndexerV1_MarkFree(Indexer%)
BU_IndexerV1_MarkUsed(Indexer%)
BU_IndexerV1_Is%(Indexer%, Used%)
BU_IndexerV1_IsFree%(Indexer%)
BU_IndexerV1_IsUsed%(Indexer%)
BU_IndexerV1_Get%(Indexer%)
BU_IndexerV1_Count%(Indexer%, Used%)
BU_IndexerV1_CountFree%(Indexer%)
BU_IndexerV1_CountUsed%(Indexer%)
; -- Indexer V2 (List)
BU_IndexerV2_Create%()
BU_IndexerV2_Destroy(Indexer%)
BU_IndexerV2_Mark(Indexer%, Used%)
BU_IndexerV2_MarkFree(Indexer%)
BU_IndexerV2_MarkUsed(Indexer%)
BU_IndexerV2_Is%(Indexer%, Used%)
BU_IndexerV2_IsFree%(Indexer%)
BU_IndexerV2_IsUsed%(Indexer%)
BU_IndexerV2_Get%(Indexer%)
BU_IndexerV2_Count%(Indexer%, Used%)
BU_IndexerV2_CountFree%(Indexer%)
BU_IndexerV2_CountUsed%(Indexer%)
; -- Mass Operation
BU_MassOp_Create%(length%)
BU_MassOp_Destroy(massop%)
BU_MassOp_Instruction(massop%, index%, type%, code%, leftOperand%, rightOperand%, result%)
BU_MassOp_Run(massop%)
; -- Window Message Handler
BU_WindowMessageHandler_Install(hwnd%)
BU_WindowMessageHandler_Uninstall(hwnd%)
BU_WindowMessageHandler_Message_Close%(hwnd%)
BU_WindowMessageHandler_Message_Destroy%(hwnd%)
BU_WindowMessageHandler_Message_Resize%(hwnd%, point*)

; Helpers ----------------------------------------------------------------------
.lib " "
; -- Blitz Functions
BU_Helper_Window_LockPointer(HWND%)
BU_Helper_Window_LockPointerAuto(HWND%)
BU_Helper_Window_MakeBorderless(HWND%)
BU_Helper_Window_Center(HWND%, Monitor%)
; -- Windows API (User32)
.lib "User32.dll"
BU_User32_ClientToScreen%(hwnd%, point*)										: "ClientToScreen"
BU_User32_ClientToScreenEx%(hwnd%, point%)										: "ClientToScreen"
BU_User32_ClipCursor%(rect*)													: "ClipCursor"
BU_User32_ClipCursorEx%(ptr%)													: "ClipCursor"
BU_User32_GetActiveWindow%()													: "GetActiveWindow"
BU_User32_GetSystemMetrics%(index%)												: "GetSystemMetrics"
BU_User32_SetWindowLong%(hwnd%, nIndex%, dwNewLong%)							: "SetWindowLongA"
BU_User32_GetWindowLong%(hwnd%, index%)											: "GetWindowLongA"
BU_User32_GetWindowRect%(hwnd%, rect*)											: "GetWindowRect"
BU_User32_GetWindowRectEx%(hwnd%, rect%)										: "GetWindowRect"
BU_User32_GetClientRect%(hwnd%, rect*)											: "GetClientRect"
BU_User32_GetClientRectEx%(hwnd%, rect%)										: "GetClientRect"
BU_User32_SetWindowPos%(hwnd%, hWndInsertAfter%, x%, y%, cx%, cy%, wFlags%)		: "SetWindowPos" 
; -- Windows API (Kernel32)
.lib "Kernel32.dll"
BU_Kernel32_FlushFileBuffers%(hFile%)											: "FlushFileBuffers"
FlushFile%(hFile%)																: "FlushFileBuffers"