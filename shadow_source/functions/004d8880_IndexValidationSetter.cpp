// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D8880
// Canonical corpus name: IndexValidationSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndexValidationSetter_004d8880.c

void UnknownObject::IndexValidationSetter()
{
    // Validated selection-index setter on `this`: an a2 of -1 unconditionally clears this[2] (offset 0x8) to -1; otherwise the index is stored into this[2] only when the entry flag at this[a2 + 3] is non-zero and the global enable gate dword_7CF788 is non-zero. Always returns the original a2.
    // ASSIGNMENT: Cache the incoming index as the return value: result = a2. [source:raw]
    // GUARD: Test whether the index a2 equals -1 (invalid/clear request). [source:raw]
    // ASSIGNMENT: Clear the stored selection: this[2] = -1 when a2 is -1. [source:raw, field:this:0x00000008]
    // GUARD: For a non-negative index, require the entry validation flag this[a2 + 3] to be non-zero before accepting it. [source:raw]
    // GUARD: Require the enable gate global dword_7CF788 (0x007CF788) to be non-zero before storing the validated index. [source:raw, global:0x007CF788]
    // ASSIGNMENT: Store the validated index: this[2] = a2 when the entry flag and enable gate both pass. [source:raw, field:this:0x00000008]
    // RETURN: Return the original a2 unchanged. [source:raw]
    // CALL: Called by sub_4D8450 (004D8450) to set a validated selection index through this gate. [caller:0x004D8450, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4D8880(this, int a2) {
    //     int result = a2;
    //     if (a2 == -1) {
    //       this->selection = -1;              // this[2], offset 0x8
    //     } else if (this->entries[a2] != 0) { // this[a2 + 3]
    //       if (dword_7CF788) {                // enable gate, 0x007CF788
    //         this->selection = a2;
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantics of the entry flag array at this[a2 + 3] and the owner class of the selection field are not established.
    // UNRESOLVED: Identity and lifecycle of the enable gate dword_7CF788 are unknown.
}
