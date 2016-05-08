# BlitzUtility
BlitzUtility is aimed at extending Blitz beyond it's initial capabilities and is a sub-project of BlitzExtensions.
All functions assume that you are passing valid parameters and do no extra checking to reduce performance impact.

# Functionality
## Containers
### List
An element-based method of creating a List in Blitz, works by creating a clone of the original Type and inserting the elements into the new flow.

* List% = BU_List_Create(TypeObject*)  
Creates a new list from an existing object, using it as a way of accessing the currently selected List entry.
* BU_List_Destroy(List%)  
Destroys an existing List, returning it's objects into the original type.
* Sucess% = BU_List_First(List%)  
Tries to selects the first object in a List, returning false if it failed.
* Sucess% = BU_List_Last(List%)  
Tries to selects the last object in a List, returning false if it failed.
* Sucess% = BU_List_Previous(List%)  
Tries to selects the previous object from the currently selected one, returning false if it failed.
* Sucess% = BU_List_Next(List%)  
Tries to selects the next object from the currently selected one, returning false if it failed.
* Success% = BU_List_Before(List%, TypeObject*)  
Tries to select the element before the given object, returning false if it failed.
* Success% = BU_List_After(List%, TypeObject*)  
Tries to select the element After the given object, returning false if it failed.
* BU_List_Insert(List%, TypeObject*)  
Inserts an object at the end of the given list.
* BU_List_InsertEx(List%, TypeObject*, OtherObject*)  
Inserts an object after the given other object.
* BU_List_Remove(List%, TypeObject*)  
Removes an object from a list, returning it to the original type.

### Type List
A type-based method of creating Lists in Blitz, works by modifying the base Type.

* List% = BU_TypeList_Create(TypeObject*)  
Creates a new list from an existing object, immediately removing it from the original type and inserting it into it's own list.
* BU_TypeList_Destroy(List%)  
Destroy an existing list, returning the objects into the flow of the base type.
* BU_TypeList_Activate(List%)  
Activates the list, making elements inside it available for use.
* BU_TypeList_Deactivate(List%)  
Deactivates the list, restoring the flow of elements to before activation.

## Types
### Long Long
64-bit integers for Blitz.

* LongLong% = BU_LongLong_Create%()
* BU_LongLong_Destroy(LongLong%)
* LongLong% = BU_LongLong_Copy%(LongLong%)
* LongLong% = BU_LongLong_TempCreate%()
* LongLong% = BU_LongLong_TempCopy%(LongLong%)
* BU_LongLong_SetTemp(LongLong%)
* BU_LongLong_UnsetTemp(LongLong%)
* BU_LongLong_TempCleanup()
* BU_LongLong_Set(LongLong%, LongLong%)
* BU_LongLong_SetV(LongLong%, LongHigh%, LongLow%)
* BU_LongLong_Add(LongLong%, LongLong%)
* BU_LongLong_AddV(LongLong%, LongHigh%, LongLow%)
* BU_LongLong_Sub(LongLong%, LongLong%)
* BU_LongLong_SubV(LongLong%, LongHigh%, LongLow%)
* BU_LongLong_Mul(LongLong%, LongLong%)
* BU_LongLong_MulV(LongLong%, LongHigh%, LongLow%)
* BU_LongLong_Div(LongLong%, LongLong%)
* BU_LongLong_DivV(LongLong%, LongHigh%, LongLow%)
* Result% = BU_LongLong_Compare%(LongLong%, LongLong%)
* Result% = BU_LongLong_CompareV%(LongLong%, LongHigh%, LongLow%)
* String$ = BU_LongLong_ToString$(LongLong%)
* LongLong% = BU_LongLong_FromString%(String$)
* Long% = BU_LongLong_ToLong%(LongLong%, Modulus%)
* LongLong% = BU_LongLong_FromLong%(LongHigh%, LongLow%)
* Long% = BU_LongLong_ToLongHigh%(LongLong%)
* Long% = BU_LongLong_ToLongLow%(LongLong%)
* Float# = BU_LongLong_ToFloat#(LongLong%)
* LongLong% = BU_LongLong_FromFloat%(Float#)
* Double% = BU_LongLong_ToDouble%(LongLong%)
* LongLong% = BU_LongLong_FromDouble%(double%)
* String$ = BU_LongLong_Serialize$(LongLong%)
* LongLong% = BU_LongLong_Deserialize%(String$)

### Double
64-bit floating point for Blitz.

* Double% = BU_Double_Create%()
* BU_Double_Destroy(Double%)
* Double% = BU_Double_Copy%(Double%)
* Double% = BU_Double_TempCreate%()
* Double% = BU_Double_TempCopy%(Double%)
* BU_Double_SetTemp(Double%)
* BU_Double_UnsetTemp(Double%)
* BU_Double_TempCleanup()
* BU_Double_Set(Double%, Double%)
* BU_Double_SetF(Double%, Float#)
* BU_Double_Add(Double%, Double%)
* BU_Double_AddF(Double%, Float#)
* BU_Double_Sub(Double%, Double%)
* BU_Double_SubF(Double%, Float#)
* BU_Double_Mul(Double%, Double%)
* BU_Double_MulF(Double%, Float#)
* BU_Double_Div(Double%, Double%)
* BU_Double_DivF(Double%, Float#)
* Result% = BU_Double_Compare%(Double%, Double%)
Compares the two doubles and returns combinations of the following: 1 for equal, 2 for smaller, 4 for greater.
* Result% = BU_Double_CompareF%(Double%, Float#)
Compares the double as float with another float and returns combinations of the following: 1 for equal, 2 for smaller, 4 for greater.
* String$ = BU_Double_ToString$(Double%)
* Double% = BU_Double_FromString%(String$)
* Float# = BU_Double_ToFloat#(Double%)
* Double% = BU_Double_FromFloat%(Float#)
* LongLong% = BU_Double_ToLongLong%(Double%)
* Double% = BU_Double_FromLongLong%(LongLong%)
* String$ = BU_Double_Serialize$(Double%)
* String$ = BU_Double_Deserialize%(String$)

## Utility
### Display Enumerator
Retrieve information about displays from Windows.

* DisplayEnumerator% = BU_DisplayEnumerator_Create%()
* BU_DisplayEnumerator_Destroy(DisplayEnumerator%)
* BU_DisplayEnumerator_Enumerate%(DisplayEnumerator%)
* BU_DisplayEnumerator_Count%(DisplayEnumerator%)
* BU_DisplayEnumerator_Retrieve%(DisplayEnumerator%, index%, Rect*)

### Indexer V1
Fast array-based index generation. Uses a constant chunk of memory.

* Indexer% = BU_IndexerV1_Create%()
* BU_IndexerV1_Destroy(Indexer%)
* BU_IndexerV1_Mark(Indexer%, Used%)
* BU_IndexerV1_MarkFree(Indexer%)
* BU_IndexerV1_MarkUsed(Indexer%)
* Result% = BU_IndexerV1_Is%(Indexer%, Used%)
* Result% = BU_IndexerV1_IsFree%(Indexer%)
* Result% = BU_IndexerV1_IsUsed%(Indexer%)
* Index% = BU_IndexerV1_Get%(Indexer%)
* Amount% = BU_IndexerV1_Count%(Indexer%, Used%)
* Amount% = BU_IndexerV1_CountFree%(Indexer%)
* Amount% = BU_IndexerV1_CountUsed%(Indexer%)

### Indexer V2
Fast vector-based index generation, uses a dynamic amount of memory.

* Indexer% = BU_IndexerV2_Create%()
* BU_IndexerV2_Destroy(Indexer%)
* BU_IndexerV2_Mark(Indexer%, Used%)
* BU_IndexerV2_MarkFree(Indexer%)
* BU_IndexerV2_MarkUsed(Indexer%)
* Result% = BU_IndexerV2_Is%(Indexer%, Used%)
* Result% = BU_IndexerV2_IsFree%(Indexer%)
* Result% = BU_IndexerV2_IsUsed%(Indexer%)
* Index% = BU_IndexerV2_Get%(Indexer%)
* Amount% = BU_IndexerV2_Count%(Indexer%, Used%)
* Amount% = BU_IndexerV2_CountFree%(Indexer%)
* Amount% = BU_IndexerV2_CountUsed%(Indexer%)

### Mass Operation
Allows chaining operations on custom types, such as LongLong and Double. See contants

* BU_MassOp_Create%(length%)
* BU_MassOp_Destroy(massop%)
* BU_MassOp_Instruction%(massop%, index%, type%, code%, leftOperand%, rightOperand%, result%)
* BU_MassOp_Run(massop%)

### Window Message Handler
Easily handle messages sent to Blitz windows using these functions. May not work as expected initially.

* BU_WindowMessageHandler_Install(hwnd%)
* BU_WindowMessageHandler_Uninstall(hwnd%)
* Count% = BU_WindowMessageHandler_Message_Close%(hwnd%)
* Count% = BU_WindowMessageHandler_Message_Destroy%(hwnd%)
* Count% = BU_WindowMessageHandler_Message_Resize%(hwnd%, point*)