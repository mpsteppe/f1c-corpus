// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D1670
// Canonical corpus name: sub_4D1670
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D1670_004d1670.c

void UnknownObject::VehicleOccupiedFlagBuilder()
{
    // Builds a 52-entry occupancy bitmask from the live vehicle grid, then reconciles a 52-entry paired flag array against it. Reads the vehicle count from dword_5C329C and, for each vehicle pointer in dword_7C54F0, reads the type dword at offset 18596; when that type is below 0x34 the matching bit of a 52-byte local array is set. Then iterates the 52 entries of the flag-field array anchored at this+0x280, and for each entry's paired earlier flag field and its this+0x280 member calls FlagFieldBitManipulation, choosing set/clear argument order by whether the corresponding occupancy bit is set. Returns the last FlagFieldBitManipulation result.
    // ASSIGNMENT: Read the vehicle count into v1 from dword_5C329C and clear the 52-byte local occupancy array v10 to zero with memset. [global:0x005C329C, source:raw]
    // LOOP: Loop over the vehicles while the index is below the count; for each, read the vehicle type dword at dword_7C54F0[slot] + 18596 and, when the type is below 0x34, set the occupancy bit v10[type] = 1. [global:0x007C54F0, source:raw]
    // LOOP: Iterate the 52 entries of the paired flag-field array anchored at this+0x280 (this+160 in dword units), reading each entry's paired earlier flag value v8 and its this+0x280 member v9. [field:this:0x00000280, source:raw]
    // CALL: When the occupancy bit is set, call FlagFieldBitManipulation(0, 0, 1, 0) if the earlier paired flag v8 is non-zero and FlagFieldBitManipulation(1, 1, 1, 0) if the this+0x280 member v9 is non-zero. [callee:0x0054C030, field:this:0x00000280, source:raw]
    // CALL: When the occupancy bit is clear, call FlagFieldBitManipulation(1, 1, 1, 0) if the earlier paired flag v8 is non-zero and FlagFieldBitManipulation(0, 0, 1, 0) if the this+0x280 member v9 is non-zero. [callee:0x0054C030, source:raw]
    // RETURN: Return the last FlagFieldBitManipulation result after all 52 entries have been reconciled. [source:raw]
    // CALL: Called from SceneRenderUpdate and LoopOverTwoParallelArrays as the per-frame vehicle-occupancy flag builder. [caller:0x004C6D90, caller:0x004D1030, source:raw]

    // Conservative worker pseudocode:
    //   char VehicleOccupiedFlagBuilder(int *this) {
    //     int count = dword_5C329C;
    //     char occ[52]; memset(occ, 0, sizeof(occ));
    //     for (int i = 0; i < count; ++i) {
    //       unsigned t = *(unsigned*)(dword_7C54F0[i] + 18596);
    //       if (t < 0x34) occ[t] = 1;
    //     }
    //     int *p = this + 160;
    //     char result;
    //     for (int j = 0; j < 52; ++j, ++p) {
    //       int earlier = *(p - 52);
    //       int member = *p;
    //       if (occ[j]) {
    //         if (earlier) result = FlagFieldBitManipulation(0, 0, 1, 0);
    //         if (member) result = FlagFieldBitManipulation(1, 1, 1, 0);
    //       } else {
    //         if (earlier) result = FlagFieldBitManipulation(1, 1, 1, 0);
    //         if (member) result = FlagFieldBitManipulation(0, 0, 1, 0);
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The field semantics of the 52 paired flag fields (anchor at this+0x280 and its paired earlier field) are established by the flag consumer, not visible in this packet; only the anchor this+0x280 is evidenced.
    // UNRESOLVED: The concrete mapping between occupancy bit index and the 52 vehicle/entry slots (whether index == vehicle slot) is caller-visible and not asserted here.
    // UNRESOLVED: The four FlagFieldBitManipulation arguments (0, 0, 1, 0 vs 1, 1, 1, 0) are passed through verbatim; their bit-level meaning lives in that callee.
}
