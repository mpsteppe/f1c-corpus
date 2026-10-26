// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048FAF0
// Canonical corpus name: DecrementCounterWithClamp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DecrementCounterWithClamp_0048faf0.c

void UnknownObject::DecrementCounterWithClamp()
{
    // Decrements the counter at this[90] (byte offset 0x168) by a2, or by the fallback value this[94] (offset 0x178) when a2 is negative. Clamps the counter to 0 if it would go negative, then calls UITileGrid(this) and returns its result. ABI lead name Subtract_value_from_counter_at_0x168_clamp_to_0.
    // GUARD: If the decrement argument a2 is negative, use the fallback value this[94] (byte offset 0x178) instead of a2 as the decrement amount. [field:this:0x00000178, source:raw]
    // ASSIGNMENT: Compute v3 = this[90] (byte offset 0x168) minus the chosen decrement amount v2 and store the result back into this[90]. [field:this:0x00000168, source:raw]
    // GUARD: If the new counter value v3 is negative, clamp this[90] (byte offset 0x168) to 0. [field:this:0x00000168, source:raw]
    // CALL: Call UITileGrid(this) to recalculate tile positions after the counter change. [callee:0x0048F870, source:raw]
    // RETURN: Return the result of UITileGrid(this). [source:raw]

    // Conservative worker pseudocode:
    //   int DecrementCounterWithClamp(int *this, int a2) {
    //       int v2 = a2;
    //       if (a2 < 0)
    //           v2 = this[94];
    //       int v3 = this[90] - v2;
    //       this[90] = v3;
    //       if (v3 < 0)
    //           this[90] = 0;
    //       return UITileGrid(this);
    //   }
    // UNRESOLVED: this is typed _DWORD*; array indices this[90] and this[94] map to byte offsets 0x168 and 0x178 from the 4-byte element size, which the packet field table states directly.
    // UNRESOLVED: The meaning of the fallback value at this[94] (offset 0x178) is not evidenced in the packet.
    // UNRESOLVED: Reading this[90] (offset 0x168) as a scroll offset comes from the existing analysis; the packet itself only shows a counter that is decremented and clamped.
    // UNRESOLVED: The owner object type is unknown; no class name is evidenced.
}
