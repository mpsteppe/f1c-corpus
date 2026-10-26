// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044F640
// Canonical corpus name: CursorSelectorFromArray
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CursorSelectorFromArray_0044f640.c

void UnknownObject::CursorSelectorFromArray()
{
    // Selects a cursor by index and activates it. Validates that the requested index a2 is within the cursor count at this[42] (offset 0xA8) and that the handle stored in the cursor-handle slot this[5*a2+12] is non-null; on success it calls SetCursor with that handle and records the selected index at this[43] (offset 0xAC), returning 1. Returns 0 when the index is out of range or the slot handle is null.
    // GUARD: Validate the index: reject when a2 is negative, when a2 is not less than the cursor count at this[42] (offset 0xA8), or when the handle in slot this[5*a2+12] is null. [field:this:0x000000A8, source:raw]
    // RETURN: Return 0 when the guard fails (out of range or null handle). [source:raw]
    // CALL: Activate the chosen cursor: SetCursor((HCURSOR)this[5*a2+12]). [global:0x0059E2B0, source:raw]
    // ASSIGNMENT: Record the selected index: this[43] (offset 0xAC) = a2. [field:this:0x000000AC, source:raw]
    // RETURN: Return 1 to signal a successful selection. [source:raw]

    // Conservative worker pseudocode:
    //   if (a2 < 0 || a2 >= this[42] || !this[5 * a2 + 12])
    //       return 0;
    //   SetCursor((HCURSOR)this[5 * a2 + 12]);
    //   this[43] = a2;
    //   return 1;
    // UNRESOLVED: The cursor-handle slot is accessed as this[5*a2+12], implying a five-dword (20-byte) slot stride beginning at this[12]; only the first dword handle is consumed and the rest of the slot layout is unproven.
    // UNRESOLVED: SetCursor is reached through the import-table global at 0x0059E2B0; the indirection is tooling detail and the import binding is not otherwise evidenced.
}
