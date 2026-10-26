// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004988A0
// Canonical corpus name: FieldSetterCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldSetterCall_004988a0.c

void UnknownObject::FieldSetterCall()
{
    // Stores the argument a2 into the integer field at offset 0x58 (this[22]), then calls the cursor-selection function with the global dword_7CB24C as first argument and the same a2 as second argument, returning the selection result.
    // ASSIGNMENT: Store argument a2 into the integer field at offset 0x58 (this[22]). [field:this:0x00000058, source:raw]
    // CALL: Call the cursor-selection function (named CursorSelectorFromArray in the raw decompilation, ABI-lead FUN_0044f640) with the global dword_7CB24C and argument a2. [global:0x007CB24C, source:raw, abi:lead]
    // RETURN: Return the result of the cursor-selection call as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   char setFieldAndSelectCursor(_DWORD* this, int a2) {
    //     this[22] = a2;
    //     return CursorSelectorFromArray(dword_7CB24C, a2);
    //   }
    // UNRESOLVED: The callee is named CursorSelectorFromArray in the raw decompilation and FUN_0044f640 in the ABI lead, but the callees list is empty, so its address and exact behavior are not confirmed.
    // UNRESOLVED: Semantic role of the field at offset 0x58 (proposed UI state/index) is not confirmed.
    // UNRESOLVED: Owner object identity is unknown.
}
