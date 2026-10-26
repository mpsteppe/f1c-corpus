// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BF4F0
// Canonical corpus name: AITickUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AITickUpdate_004bf4f0.c

void UnknownObject::AITickUpdate()
{
    // Per-frame AI timing update over the live vehicle array. Sets the half-distance flag, then for each vehicle not in states 3 or 2, checks a per-vehicle accumulated elapsed time (in a float array at vehicle-array-relative byte offset 8148208) and, when it is above a small threshold, computes the delta against offset 8148624, increments a lap counter at vehicle +16444, writes the clamped race time into vehicle +16536, writes the offset-adjusted race delta into vehicle +16568, forces vehicle state to 1, and re-sorts driver ordering via AIDriverSorting. Idle vehicles with state 0 are set to state 1. Ends by resetting the scoring ring-buffer globals (83EE54/58/5C to &unk_7D2E54, 8AAE64/68/6C to &unk_83EE64, counters zeroed) and returns &unk_83EE64.
    // ASSIGNMENT: Set byte_8ACFA0 = 1 at tick start. [global:0x008ACFA0, source:raw]
    // CALCULATION: Read the vehicle count from dword_5C329C into the loop bound v1 and snapshot it in v11; the loop runs while v2 < v1. [global:0x005C329C, source:raw]
    // LOOP: Iterate v2 over the live vehicle pointers dword_7C54F0[v2], computing v4 = this - dword_7C54F0 once so per-vehicle accumulator reads are addressed relative to the array base. [global:0x007C54F0, source:raw]
    // GUARD: Read vehicle state at +16484; skip the timed update entirely when the state is 3 or 2 (retired/inactive classes). [source:raw]
    // GUARD: Per-vehicle accumulated time at (v4 + 4*v2 + 8148208) must be greater than the zero threshold (the packet lists flt_59E440 as the read constant backing the literal 0.0). [global:0x0059E440, source:raw]
    // CALCULATION: v7 = accum[8148208] - accum[8148624]: elapsed delta between the two per-vehicle accumulator slots. [source:raw]
    // STATE_TRANSITION: Increment the lap/segment counter at vehicle +16444. [source:raw]
    // CALCULATION: v8 = v7 + this[213]; clamp v8 to >= 0.0. [field:this:0x00000354, source:raw]
    // ASSIGNMENT: Write the clamped race time into vehicle +16536 as a float. [source:raw]
    // CALCULATION: Write vehicle +16568 = this[213] - flt_8ACF90 + v7 (time delta offset by the race-time offset global). [field:this:0x00000354, global:0x008ACF90, source:raw]
    // STATE_TRANSITION: When the vehicle state at +16484 is not 3, force it to 1. [source:raw]
    // CALL: AIDriverSorting(v5): re-sort driver ordering after the lap/time update. [callee:0x004BF390, source:raw]
    // STATE_TRANSITION: For vehicles whose state at +16484 is 0, force it to 1. [source:raw]
    // ASSIGNMENT: Reset the scoring ring-buffer globals: dword_83EE5C = dword_83EE58 = dword_83EE54 = (int)&unk_7D2E54, and dword_83EE60 = 0. [global:0x0083EE54, global:0x0083EE58, global:0x0083EE5C, global:0x0083EE60, global:0x007D2E54, source:raw]
    // ASSIGNMENT: Reset the queue pointers: dword_8AAE6C = dword_8AAE68 = dword_8AAE64 = (int)&unk_83EE64, and dword_7D2E50 = 0. [global:0x008AAE64, global:0x008AAE68, global:0x008AAE6C, global:0x0083EE64, global:0x007D2E50, source:raw]
    // RETURN: Return &unk_83EE64. [global:0x0083EE64, source:raw]

    // Conservative worker pseudocode:
    //   byte_8ACFA0 = 1;
    //   count = dword_5C329C;
    //   base_delta = this - dword_7C54F0;
    //   for (i = 0; i < count; ++i) {
    //       v = dword_7C54F0[i];
    //       st = *(v + 16484);
    //       if (st != 3 && st != 2) {
    //           if (*(base_delta + 4*i + 8148208) > 0.0) {
    //               delta = *(base_delta + 4*i + 8148208) - *(base_delta + 4*i + 8148624);
    //               ++*(v + 16444);
    //               t = delta + this[213];
    //               if (t < 0.0) t = 0.0;
    //               *(v + 16536) = t;
    //               *(v + 16568) = this[213] - flt_8ACF90 + delta;
    //               if (*(v + 16484) != 3) *(v + 16484) = 1;
    //               AIDriverSorting(v);
    //           }
    //           if (!*(dword_7C54F0[i] + 16484)) *(dword_7C54F0[i] + 16484) = 1;
    //       }
    //   }
    //   dword_83EE5C = dword_83EE58 = dword_83EE54 = (int)&unk_7D2E54;
    //   dword_83EE60 = 0;
    //   dword_8AAE6C = dword_8AAE68 = dword_8AAE64 = (int)&unk_83EE64;
    //   dword_7D2E50 = 0;
    //   return &unk_83EE64;
    // UNRESOLVED: The per-vehicle accumulator array addressed as v4 + 4*v2 + 8148208 and 8148624 (byte offsets relative to the vehicle pointer array base) is rendered by Hex-Rays as absolute-ish offsets; their exact meaning is not established by the packet.
    // UNRESOLVED: The vehicle struct offsets 16484 (state), 16444 (lap counter), 16536 (race time) and 16568 (offset delta) are not named in the packet; the existing fill names them at DERIVED trust only, not adopted here.
    // UNRESOLVED: flt_59E440 is packet-listed as a read global but does not appear literally in the raw source; it is assumed to back the > 0.0 threshold literal.
    // UNRESOLVED: The exact contents of unk_7D2E54 / unk_83EE64 and the roles of the ring-buffer globals (83EE54..83EE60, 8AAE64..8AAE6C, 7D2E50, 7D2E54) are not fully mapped; the existing fill labels them scoring/session structures at DERIVED trust.
    // UNRESOLVED: The meaning of byte_8ACFA0 (existing fill: HalfDistanceFlag, DERIVED) is not independently evidenced.
    // UNRESOLVED: The legacy ABI label AI_Tick_Update_Ring_Buffer_Reset (abi:lead) is narrower than the tick body; the canonical name AITickUpdate is kept.
}
