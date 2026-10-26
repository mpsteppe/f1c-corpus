// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00467340
// Canonical corpus name: IndexedCallWith1Increment
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndexedCallWith1Increment_00467340.c

void UnknownObject::MenuOptionValueAdjust()
{
    // Adjusts a menu option value by one step in a direction given by argument a2 (1 increments, otherwise decrements) and dispatches the result to the handler selected by the option's type field. It reads the option data pointer at this[200], computes value +/- 1 from the current value stored at offset 20 of the pointed-to structure, then calls ListSelectionClamp when this[203] equals 4, or AIGearSelectionSet otherwise, using global byte_7C56C0 as the shared session/selection state, and finally returns the result of MenuOptionValueDisplay(this). Returns 0 immediately when this[200] is null.
    // GUARD: Guard on the option data pointer at this[200] (offset 0x320): if null, return 0 without adjusting; otherwise proceed to compute and dispatch the adjusted value. [source:raw, field:this:0x00000320]
    // CALCULATION: Read the current value at offset 20 of the structure pointed to by this[200] and compute the adjusted value v5: v4 + 1 when a2 equals 1, otherwise v4 - 1. [source:raw, field:this:0x00000320]
    // GUARD: Dispatch guard on the option type field this[203] (offset 0x32C): when it equals 4 take the list-clamp path, otherwise take the AI gear selection path. [source:raw, field:this:0x0000032C]
    // CALL: On the type-4 path, clamp/validate the adjusted value via ListSelectionClamp on global byte_7C56C0 using the selection index at this[201] (offset 0x324). [source:raw, callee:0x0042EB60, global:0x007C56C0, field:this:0x00000324]
    // CALL: On the non-type-4 path, set the AI gear selection via AIGearSelectionSet on global byte_7C56C0 using the type at this[203] (offset 0x32C) and the parameter at this[202] (offset 0x328). [source:raw, callee:0x0042EAA0, global:0x007C56C0, field:this:0x00000328, field:this:0x0000032C]
    // CALL: Refresh the option's displayed text by calling MenuOptionValueDisplay(this) and return its result. [source:raw, callee:0x004673B0]

    // Conservative worker pseudocode:
    //   int MenuOptionValueAdjust(int *this, int a2)
    //   {
    //     int *p = this[200];
    //     if (!p) return 0;
    //     int cur = *(int *)((char *)p + 20);
    //     int adj = (a2 == 1) ? cur + 1 : cur - 1;
    //     if (this[203] == 4)
    //       ListSelectionClamp(&byte_7C56C0, this[201], adj);
    //     else
    //       AIGearSelectionSet(&byte_7C56C0, this[203], this[202], adj);
    //     return MenuOptionValueDisplay(this);
    //   }
    // UNRESOLVED: Field this+0x334 is listed in the packet but never referenced in the raw source; its purpose is not established.
    // UNRESOLVED: The type of the structure pointed to by this[200] and the meaning of the current value at offset 20 of it are not identified.
    // UNRESOLVED: The value 4 as the list-clamp discriminator is asserted by the code; no owner or documentation confirms the semantics of that type value.
}
