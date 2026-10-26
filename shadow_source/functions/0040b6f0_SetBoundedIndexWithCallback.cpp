// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040B6F0
// Canonical corpus name: ShortComputation_b6f0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_b6f0_0040b6f0.c

void UnknownObject::SetBoundedIndexWithCallback()
{
    // Bounded index setter with virtual callback dispatch. When 0 <= a2 < this[4] (offset 0x10), writes a2 into this[5] (offset 0x14) and invokes the __thiscall virtual callback stored at vtable+16 (this+0x0). Otherwise the write and callback are skipped and a2 is returned unchanged.
    // ASSIGNMENT: Initialize result to a2 so the out-of-bounds path returns a2 unchanged. [source:raw]
    // GUARD: Guard: a2 >= 0 AND a2 < this[4] (this+0x10, upper bound field). Both conditions must hold for the index write and callback to execute. [source:raw, field:this:0x00000010]
    // ASSIGNMENT: Set the index field this[5] (this+0x14) to a2 when the bound check passes. [source:raw, field:this:0x00000014]
    // CALL: Invoke the virtual __thiscall callback dispatched through the vtable pointer at this+0x0, offset +16 bytes into the vtable, passing this. [source:raw, field:this:0x00000000]
    // RETURN: Return a2 (unchanged when the guard fails; after the callback when it passes). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_40B6F0(int *this, int index) {
    //     if (index >= 0 && index < this[4]) {
    //       this[5] = index;
    //       return (*(int (__thiscall **)(int *))(*this + 16))(this);
    //     }
    //     return index;
    //   }
    // UNRESOLVED: The virtual callback target at vtable+16 is not resolvable from this packet; no callee address is listed, so the called function is unidentified.
    // UNRESOLVED: field:obj:0x00000010 duplicates field:this:0x00000010 at the same byte offset under a different base name; treated as an extraction artifact of the same upper-bound read.
    // UNRESOLVED: Class identity and the meaning of the stored index remain unknown (owner is UnknownObject).
}
