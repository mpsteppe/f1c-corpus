// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7C10
// Canonical corpus name: FloatRangeIndexLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatRangeIndexLookup_004d7c10.c

void UnknownObject::FloatRangeIndexLookup()
{
    // Wraps a float a2 into the range [0, this[9]) by repeatedly adding or subtracting the wrap period stored at this+0x24, then classifies the wrapped value against a small descending threshold table rooted at flt_5EA404. Returns the matched segment index (2, 1 or 0), or 0 when the wrapped value exceeds flt_5EA404, or -1 when it exceeds every scanned threshold.
    // ASSIGNMENT: Initialize v2 from input a2 and read the wrap period from this[9] (this+0x24). [source:raw, field:this:0x00000024]
    // LOOP: While v2 is negative, add the wrap period this[9] to move it back toward the [0, period) range. [source:raw, field:this:0x00000024]
    // LOOP: While v2 exceeds the wrap period this[9], subtract the wrap period to reduce it into range. [source:raw, field:this:0x00000024]
    // GUARD: If the wrapped v2 is above flt_5EA404, return 0 as the matched segment index. [source:raw, global:0x005EA404]
    // LOOP: Scan up to three descending float thresholds beginning at flt_5EA404 (offsets 0, -4, -8); stop at the first threshold that v2 exceeds. [source:raw, global:0x005EA404]
    // ASSIGNMENT: Track the candidate segment index i, counting down from 2 toward 0 for each threshold the value fails to exceed. [source:raw]
    // RETURN: Return the matched segment index i (2, 1 or 0), or -1 when v2 exceeded every scanned threshold. [source:raw]
    // CALL: Called by AISessionModeTransition, sub_41B250, PitSelectionStateMachine, sub_4BCCC0 and FloatWrapTableInterpolation on the frame path. [caller:0x004193A0, caller:0x0041B250, caller:0x0041B3C0, caller:0x004BCCC0, caller:0x004D7CF0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4D7C10(float *this, float a2) {
    //     float v = a2;
    //     while (v < 0.0f) v += this[9];
    //     while (v > this[9]) v -= this[9];
    //     if (v > flt_5EA404) return 0;
    //     int idx = 2; float *t = &flt_5EA404;
    //     for (int k = 324; k >= 320; k -= 4) {
    //       if (v > *t) break;
    //       idx--; t--;
    //     }
    //     return idx;
    //   }
    // UNRESOLVED: Global flt_59E440 is listed in the packet but absent from the raw source body; the skeleton labels it a zero-threshold global, yet its role in this function is unconfirmed.
    // UNRESOLVED: Semantic meaning of the three thresholds at flt_5EA404 (e.g. heading/angle segment boundaries) depends on the unknown owning object.
}
