// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BC270
// Canonical corpus name: sub_4BC270
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4BC270_004bc270.c

void UnknownObject::BoundedFloatArrayLookup()
{
    // Indexed read of a float array with a default sentinel. Loads the array pointer from this+0x8C, forms the index as a2 - 1, and returns the float at that slot when the pointer is non-null and the index satisfies two capacity bounds (this+0x8 and this+0x88). Returns -1.0 (the flt_59E670 sentinel constant) when the pointer is null or the index is out of range. __thiscall double-returning accessor with no side effects.
    // ASSIGNMENT: Load the array pointer v2 = this[35] (this+0x8C) and precompute v3 = a2 - 1. [source:raw, field:this:0x0000008C]
    // GUARD: Guard: pass only when v2 (array pointer) is non-null AND v3 >= 0 AND v3 <= this[2] (this+0x8 bound) AND v3 < this[34] (this+0x88 bound); otherwise fall through to the sentinel return. [source:raw, field:this:0x00000008, field:this:0x00000088]
    // CALCULATION: Compute the element address as v2 + 4 * v3 (scaling the index by float stride 4). [source:raw]
    // RETURN: Return the float value stored at the computed element address when the guard passes. [source:raw, field:this:0x0000008C]
    // RETURN: Return -1.0 (the flt_59E670 sentinel flag constant) when the array pointer is null or the index is out of either bound. [source:raw, global:0x0059E670]
    // CALL: Called by sub_4D24D0 (0x004D24D0) and SingleFunctionCallWrapper_ad30 (0x004DAD30) to fetch bounded float-array entries. [caller:0x004D24D0, caller:0x004DAD30, source:raw]

    // Conservative worker pseudocode:
    //   double sub_4BC270(_DWORD *this, int index) {
    //     float *arr = (float *)this[35];
    //     int i = index - 1;
    //     if (arr && i >= 0 && i <= this[2] && i < this[34])
    //       return arr[i];
    //     return -1.0;
    //   }
    // UNRESOLVED: Meaning of the two capacity bounds this+0x8 and this+0x88 and their relationship (one is not strictly implied by the other in the guard).
    // UNRESOLVED: Semantic role of the array and the meaning of the -1.0 sentinel depend on the caller context; flt_59E670 is a read-only sentinel constant here.
    // UNRESOLVED: Callers sub_4D24D0 and 0x004DAD30 have no caller-side analysis in this packet, so the actual array contents are unknown.
}
