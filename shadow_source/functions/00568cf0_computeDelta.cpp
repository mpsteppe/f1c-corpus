// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00568CF0
// Canonical corpus name: HighResolutionTimerDelta
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HighResolutionTimerDelta_00568cf0.c

void UnknownObject::computeDelta()
{
    // Reads a high-resolution timestamp via QPCTimestampReadWrapper, computes the delta from the previously stored timestamp, stores the new timestamp, and returns the delta scaled by per-instance factors.
    // ASSIGNMENT: Capture the previous timestamp from the two dwords at this+0x20 and this+0x24 into locals. [field:this:0x00000020, field:this:0x00000024]
    // CALL: Call QPCTimestampReadWrapper(this, &lo, &hi) to read the current high-resolution timestamp. [callee:0x00568CB0]
    // CALCULATION: Compute the 64-bit delta as the current timestamp minus the previously stored timestamp (this+0x20/this+0x24). [field:this:0x00000020, field:this:0x00000024, source:raw]
    // ASSIGNMENT: Store the new timestamp dwords back into this+0x20 and this+0x24. [field:this:0x00000020, field:this:0x00000024]
    // CALCULATION: Scale the delta into seconds: divide the low delta dword by this+0x0 and add the high delta dword multiplied by this+0x4 (the multiplier field at +4 is not tracked in this packet). [field:this:0x00000000, source:raw]
    // RETURN: Return the scaled delta as a double. [field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   prev = (hi(this+0x24) << 32) | lo(this+0x20);
    //   QPCTimestampReadWrapper(this, &cur_lo, &cur_hi);
    //   cur = (cur_hi << 32) | cur_lo;
    //   this+0x20 = cur_lo; this+0x24 = cur_hi;
    //   delta = cur - prev;
    //   return (double)(uint32)delta / this+0x0
    //        + (double)(uint32)(delta >> 32) * this+0x4;
    // UNRESOLVED: The purpose of the read-only field this+0x8 is not observed in this function; its meaning is unknown.
    // UNRESOLVED: The exact scale semantics of this+0x0 and this+0x4 (frequency conversion factors) are DERIVED from the structural twin note, not confirmed.
}
