// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00411650
// Canonical corpus name: CircularBufferIndexIncrement
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CircularBufferIndexIncrement_00411650.c

void UnknownObject::CircularBufferIndexIncrement()
{
    // Circular buffer index increment with wrap. Reads capacity from this[0] and current index from this[1]; if capacity exceeds 1, increments the index, wraps it to 0 when it reaches capacity, and returns the previous index. When capacity <= 1 the index is left unchanged and 0 is returned.
    // ASSIGNMENT: Initialize result to 0 and read current index v1 = this[0] capacity and this[1] index. [source:raw, field:this:0x00000000, field:this:0x00000002]
    // GUARD: Guard: only increment when this[0] (capacity) > 1; otherwise return 0 without modifying the index. [source:raw, guard:0, field:this:0x00000000]
    // CALCULATION: Read old index result = this[1] and write back this[1] = result + 1. [source:raw, field:this:0x00000002]
    // ASSIGNMENT: Wrap: if (unsigned)(result + 1) >= capacity, set this[1] = 0. [source:raw, field:this:0x00000002, field:this:0x00000000]
    // RETURN: Return the previous index value result. [source:raw, field:this:0x00000002]

    // Conservative worker pseudocode:
    //   unsigned short CircularBufferIndexIncrement(unsigned short *this) {
    //     unsigned short cap = this[0];
    //     unsigned short result = 0;
    //     if (cap > 1) {
    //       result = this[1];
    //       this[1] = (unsigned short)(result + 1);
    //       if ((unsigned short)(result + 1) >= cap) this[1] = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Caller context for the circular buffer position is unknown; only the single caller ShortComputation_1a50 (0x00411A50) is known statically.
    // UNRESOLVED: Object owning the buffer is unknown.
}
