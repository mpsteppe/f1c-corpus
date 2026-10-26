// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048FB30
// Canonical corpus name: sub_48FB30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_48FB30_0048fb30.c

void UnknownObject::ScrollOffsetIncrementClamp()
{
    // Increments a scroll-offset counter. Uses the caller-supplied increment a2 unless a2 < 0, in which case the default increment from this+0x178 is used. Adds it to the current offset at this+0x168, stores the sum back, and clamps the result to the maximum bound at this+0x16C. Finally calls UITileGrid(this) to recompute tile positions and returns its result.
    // GUARD: Select the effective increment: use a2 as given, but when a2 < 0 substitute the default increment value stored at this+0x178 (this[94]). [source:raw, field:this:0x00000178]
    // CALCULATION: Compute the new scroll offset v3 = selected increment + current offset this[90] (this+0x168). [source:raw, field:this:0x00000168]
    // ASSIGNMENT: Store the computed offset v3 back into this[90] (this+0x168). [source:raw, field:this:0x00000168]
    // GUARD: Clamp: when v3 exceeds the maximum bound this[91] (this+0x16C), cap this[90] to the maximum value. [source:raw, field:this:0x00000168, field:this:0x0000016C]
    // CALL: Recalculate tile positions by calling UITileGrid(this) after the offset change. [source:raw, callee:0x0048F870]
    // RETURN: Return the result of UITileGrid(this). [source:raw]

    // Conservative worker pseudocode:
    //   int ScrollOffsetIncrementClamp(int this, int a2) {
    //     int v2 = (a2 < 0) ? *(int*)(this + 0x178) : a2;
    //     int v3 = v2 + *(int*)(this + 0x168);
    //     *(int*)(this + 0x168) = v3;
    //     if (v3 > *(int*)(this + 0x16C))
    //       *(int*)(this + 0x168) = *(int*)(this + 0x16C);
    //     return UITileGrid(this);
    //   }
    // UNRESOLVED: this is a UI tile-grid scroll container; its exact type and the meaning of the default increment at +0x178 are unknown.
    // UNRESOLVED: UITileGrid semantics (tile-position recomputation) are unverified beyond the update after an offset change.
}
