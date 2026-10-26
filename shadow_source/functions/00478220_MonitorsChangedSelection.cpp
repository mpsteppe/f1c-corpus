// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00478220
// Canonical corpus name: MonitorsChangedSelection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MonitorsChangedSelection_00478220.c

void UnknownObject::MonitorsChangedSelection()
{
    // Queries the game command dispatch interface global dword_7CD8C0 for the current selection identifier through its vtable (method at offset +28, argument 22). If the returned object is non-null, reads a selection value from it and compares it against the cached value at this+0xE8 (this[58]); on a difference, updates the cache and invokes a this vtable notification callback (offset +44, argument 1). Always returns 0.
    // CALL: Dispatch a query through the command interface global dword_7CD8C0: dereference its vtable pointer and call the thiscall method at vtable offset +28 (index 7) with argument 22 to obtain the current selection object. [global:0x007CD8C0, function:0x00478220, source:raw, abi:lead]
    // GUARD: If the dispatch query returned a null object (v2 == 0), take the early return-0 path and skip the update entirely. [function:0x00478220, source:raw]
    // CALCULATION: Read the reported selection identifier from the dispatch result object. Raw source reads result+372 (0x174); packet field evidence labels the result-object read field at offset 0x2C. Store into a temporary for comparison. [field:obj:0x0000002C, function:0x00478220, source:raw]
    // GUARD: Compare the reported selection identifier against the cached value stored at this+0xE8 (this[58]); if equal, skip the cache update and the notification callback. [field:this:0x000000E8, function:0x00478220, source:raw]
    // ASSIGNMENT: Cache the reported selection identifier into this+0xE8 (this[58]), replacing the previous cached value. [field:this:0x000000E8, function:0x00478220, source:raw]
    // CALL: Load the vtable pointer from this+0x0 (*this) and invoke the thiscall method at vtable offset +44 (0x2C, index 11) with (this, 1) as the change notification callback. [field:this:0x00000000, function:0x00478220, source:raw]
    // RETURN: Return 0 from the method on every path. [function:0x00478220, source:raw]

    // Conservative worker pseudocode:
    //   // v2 = (*(*(void**)dword_7CD8C0 + 28))(dword_7CD8C0, 22);
    //   // if (v2 != 0) {
    //   //   v3 = *(int*)(v2 + 372);
    //   //   if (this[58] != v3) {
    //   //     this[58] = v3;
    //   //     (*(*(void**)this + 44))(this, 1);
    //   //   }
    //   // }
    //   // return 0;
    // UNRESOLVED: The packet field evidence labels the dispatch-result object's read field at offset 0x2C (field:obj:0x0000002C), while the raw source reads result+372 (0x174). The two offsets do not match; one mapping is mislabeled and needs reconciliation against deterministic facts before use.
    // UNRESOLVED: The meaning of command interface query argument 22 (assumed a selection/command ID lookup) is unknown.
    // UNRESOLVED: The meaning of the notification callback argument 1 at this vtable offset +44 is unknown.
    // UNRESOLVED: Whether this+0xE8 really caches the game's selection state is only prose-level (existing analysis), not independently proven.
}
