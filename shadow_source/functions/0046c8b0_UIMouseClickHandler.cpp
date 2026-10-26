// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046C8B0
// Canonical corpus name: UIMouseClickHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIMouseClickHandler_0046c8b0.c

void UnknownObject::UIMouseClickHandler()
{
    // Mouse click handler for the key binding UI. Reads dual-field values from the structure pointer at this+0x40 via DualFieldRead, looks up a binding index with sub_489F40 using the second read value, and if the index is valid removes the previous binding through an indirect remove/shift function and inserts the new binding into the array selected by the byte at this+0x174 (0 selects the primary array). Returns 0.
    // CALL: Read the dual-field values v8 and v7 via DualFieldRead on the structure pointer at this+0x40. [field:this:0x00000040, callee:0x00498880, source:raw]
    // CALL: Look up the binding index v4 via sub_489F40(a1, v7, 1) using the second dual-field value. [callee:0x00489F40, source:raw]
    // GUARD: If the binding index v4 is negative, skip the remove/insert path and return. [source:raw]
    // CALL: Invoke the indirect remove/shift function (at KeyBindingArrayRemoveShift + 1) with arguments (byte at this+0x174, a2, a3, byte at this+0x174, v4), storing the result in v5. [field:this:0x00000174, source:raw]
    // GUARD: Compare the byte at this+0x174 to 0 to select which binding array receives the insert (0 = primary array). [guard:0, field:this:0x00000174, source:raw]
    // CALL: Insert the new binding via IndexedArrayInsertWithShift(byte at this+0x174 == 0, v5, -1). [callee:0x0046C7B0, guard:0, field:this:0x00000174, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   DualFieldRead(*(DWORD**)(a1 + 64), &v8, &v7);
    //   v4 = sub_489F40(a1, v7, 1);
    //   if (v4 >= 0) {
    //     v5 = RemoveShift(*(BYTE*)(a1 + 372), a2, a3, *(BYTE*)(a1 + 372), v4);
    //     IndexedArrayInsertWithShift(*(BYTE*)(a1 + 372) == 0, v5, -1);
    //   }
    //   return 0;
    // UNRESOLVED: The indirect call target (KeyBindingArrayRemoveShift + 1) is not in the packet callee list; its exact address and semantics are unresolved.
    // UNRESOLVED: The meaning of the byte at this+0x174 as a primary/secondary array selector is DERIVED from the guard comparison.
    // UNRESOLVED: Roles of a2/a3 in the remove/shift call are not explained by packet evidence.
}
