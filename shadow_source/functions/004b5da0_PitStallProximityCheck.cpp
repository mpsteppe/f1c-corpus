// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B5DA0
// Canonical corpus name: PitStallProximityCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PitStallProximityCheck_004b5da0.c

void UnknownObject::PitStallProximityCheck()
{
    // Pit-stall proximity check driven from a circular buffer of pit stall entries. Queries the stall buffer; if empty, reinitializes it by setting the pit-stop action (PitstopActionSet) and re-queries. Iterates the buffer backward from the current index (this+0x9B8) modulo the buffer size (this+0x9B4), resolves each entry to a stall pointer, and skips entries whose Z-threshold (entry+108) is at or beyond the vehicle Z-position (a2+4). When the first stall within reach is found (Z-distance below 1.5), registers the contact via CollisionObjectInsertion.
    // CALL: Query CircularBufferCheck for the stall buffer count; if it returns zero, call PitstopActionSet with a3 (interpreted as a float) to (re)initialize the buffer, then re-query CircularBufferCheck(this). [function:0x004B5DA0, source:raw, callee:0x004B68C0, callee:0x004B6940]
    // LOOP: Iterate v4 buffer entries from index 0 upward: compute the circular index as (current index this[0x9B8] - i) modulo the buffer size this[0x9B4], and resolve each index to a stall pointer via IndexedPointerLookup. [source:raw, field:this:0x000009B8, field:this:0x000009B4, callee:0x004B6920]
    // GUARD: Skip the stall when the vehicle Z-position (a2+4) is at or beyond the stall Z-threshold (v7+108); break on the first stall that is within reach. [source:raw]
    // CALL: When the Z-distance (vehicle Z minus stall threshold) is less than 1.5, call CollisionObjectInsertion with the stall pointer, the vehicle data, and a3 to register the stall contact. [source:raw, callee:0x004B48E0]
    // RETURN: Return early once all v4 entries have been scanned without finding a stall within reach. [source:raw]

    // Conservative worker pseudocode:
    //   void sub_4B5DA0(int this, int a2, int a3) {
    //     int count = CircularBufferCheck();
    //     if (!count) {
    //       PitstopActionSet(*(float*)&a3);
    //       count = CircularBufferCheck(this);
    //     }
    //     for (int i = 0; i < count; ++i) {
    //       int idx = this[622] - i;
    //       if (idx < 0) idx += this[621];
    //       char* stall = IndexedPointerLookup(idx);
    //       if (*(float*)(a2 + 4) >= *(float*)(stall + 108))
    //         return;
    //     }
    //     if (*(float*)(a2 + 4) - *(float*)(stall + 108) < 1.5)
    //       CollisionObjectInsertion(stall, a2, a3);
    //   }
    // UNRESOLVED: The exact meaning of the entry float written at stall+108 and the vehicle value at a2+4 (interpreted as Z-position) is DERIVED from the comparison shape, not independently confirmed.
    // UNRESOLVED: The global flt_59E8A4 appears in the packet's globals list but the raw source text contains no reference to it; likely a packet join artifact.
    // UNRESOLVED: The first CircularBufferCheck call appears argument-less in the decompiler output; whether it also receives `this` is unclear.
}
