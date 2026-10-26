// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CE8D0
// Canonical corpus name: IndexedArrayAccess
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndexedArrayAccess_004ce8d0.c

void UnknownObject::IndexedArrayAccess()
{
    // Bounds-checked index into a fixed-stride array owned by `this`: validates a2 against the element count stored at this[2] (offset 0x8), returning 0 when out of range, otherwise returning the address this[3] + 108 * a2 (offset 0xC holds the array base; element stride is 108 bytes). Structural twin of ShortComputation_c910 (0040c910) per cluster_copy.
    // GUARD: Reject index a2 when it is negative or at/above the element count stored at this[2] (offset 0x8). [source:raw, field:this:0x00000008]
    // RETURN: Return 0 as the invalid-access sentinel when the bounds check fails. [source:raw]
    // CALCULATION: Compute the target element address as this[3] (array base at offset 0xC) plus 108 * a2 (element stride). [source:raw, field:this:0x0000000C]
    // RETURN: Return the computed element address for a valid index. [source:raw]
    // CALL: Used by HATPolygonSurfaceFit (00449A80), AnimationPlaybackSequence (0044ACB0) and sub_4CEF30 (004CEF30) to obtain validated per-element pointers into their fixed-stride arrays. [caller:0x00449A80, caller:0x0044ACB0, caller:0x004CEF30, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4CE8D0(this, int a2) {
    //     if (a2 < 0 || a2 >= this->count)  // this[2], offset 0x8
    //       return 0;
    //     return this->base + 108 * a2;     // this[3], offset 0xC, stride 0x6C
    //   }
    // UNRESOLVED: Element type and array semantics of the 108-byte stride are caller-defined and not established here.
    // UNRESOLVED: Identity of the owning class (container of count/base fields) is unknown.
}
