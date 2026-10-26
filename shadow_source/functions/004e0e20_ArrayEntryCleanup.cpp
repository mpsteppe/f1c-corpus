// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E0E20
// Canonical corpus name: ArrayEntryCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayEntryCleanup_004e0e20.c

void UnknownObject::ArrayEntryCleanup()
{
    // Per-entry lazy-cleanup within an array owned by a subsystem object. Selects an array entry by scaling the a2 index by 74 dwords, runs one-time lazy initialization on a sub-block 81 dwords into the entry, advances 98 dwords, runs lazy initialization on the second sub-block, then if that second sub-block still has a nonzero first value flags a state condition through FlagFieldBitManipulation(1, 1, 0, 0); otherwise returns the initialization result.
    // ASSIGNMENT: Select array entry: v3 = this + 74*a2 dwords, scaling the a2 index by the 74-dword entry stride. [source:raw, function:0x004E0E20]
    // CALL: LazyInitCallback(this, v3 + 81) one-time initializes the first sub-block located 81 dwords into the selected entry. [callee:0x004E0D00, source:raw]
    // CALCULATION: Advance the entry cursor by 98 dwords: v3 += 98. [source:raw]
    // CALL: result = LazyInitCallback(this, v3) one-time initializes the second sub-block at the advanced cursor. [callee:0x004E0D00, source:raw]
    // GUARD: If the first dword of the second sub-block (*v3) is nonzero, take the flag branch and return immediately. [source:raw]
    // CALL: FlagFieldBitManipulation(1, 1, 0, 0) marks the flag-state condition when the second sub-block is nonempty. [callee:0x0054C030, source:raw]
    // RETURN: Return the FlagFieldBitManipulation result on the nonzero branch, or the LazyInitCallback result otherwise. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4E0E20(_DWORD* this, int a2) {
    //     _DWORD* v3 = &this[74 * a2];
    //     LazyInitCallback(this, (int)(v3 + 81));
    //     v3 += 98;
    //     int result = LazyInitCallback(this, (int)v3);
    //     if (*v3) return FlagFieldBitManipulation(1, 1, 0, 0);
    //     return result;
    //   }
    // UNRESOLVED: The owning object (this) is unknown; its layout, the 74-dword array entry stride and the 81/98-dword sub-block offsets are grounded only in the raw source and have no named field evidence.
    // UNRESOLVED: Semantics of the a2 entry index and of the two sub-blocks per entry are unknown.
    // UNRESOLVED: Meaning of the FlagFieldBitManipulation(1, 1, 0, 0) call and its constants is unresolved.
    // UNRESOLVED: Whether the nonzero *v3 branch represents an already-initialized or error state is unknown.
}
