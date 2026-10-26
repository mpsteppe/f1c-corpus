// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C6760
// Canonical corpus name: BoundsCheckedIndexSetter_6760
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BoundsCheckedIndexSetter_6760_004c6760.c

void UnknownObject::BoundsCheckedIndexSetter_6760()
{
    // Bounds-checked index setter. Accepts a candidate index a2 and stores it into the index field this[6] (offset 0x18) only when a2 is in the valid range [0, this[5]) where this[5] (offset 0x14) is the item count. The input value a2 is returned unchanged whether or not the write occurs.
    // ASSIGNMENT: Initialize result to the input a2; the function returns this value unchanged in all paths. [source:raw]
    // GUARD: Bounds check on a2: proceed only when a2 >= 0 AND a2 < this[5] (item count at offset 0x14). [source:raw, field:this:0x00000014]
    // ASSIGNMENT: Store a2 into the index field this[6] (offset 0x18) when the bounds check passes. [source:raw, field:this:0x00000018]
    // RETURN: Return result, which equals the original a2 whether or not the index field was written. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C6760(DWORD* this_, int a2) {
    //     int result = a2;
    //     if (a2 >= 0 && a2 < this_[5]) this_[6] = a2;
    //     return result;
    //   }
    // UNRESOLVED: Semantics of the index field at 0x18 (which list it selects) and the count field at 0x14 depend on the owning object, which is unidentified.
    // UNRESOLVED: Out-of-range writes are silently dropped; the caller is not informed of a failed set beyond receiving the unchanged a2 back.
}
