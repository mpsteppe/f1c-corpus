// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BD760
// Canonical corpus name: SentinelSlotFill
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SentinelSlotFill_004bd760.c

void UnknownObject::SentinelSlotFill()
{
    // Scans a fixed 10-element array of dwords starting at this+0xE0 for the first slot holding the sentinel -1, inserts the value read from this+0x8 into that slot, and returns the slot index. If all 10 slots are occupied (no sentinel found) it returns 10 without inserting. Called per-frame by PostPitCleanup (0042A6F0).
    // ASSIGNMENT: Initialize the slot counter result to 0 before scanning. [source:raw]
    // LOOP: Iterate the 10-dword slot array at this+56 (byte offset 0xE0) from index 0, advancing one slot per step. [source:raw, field:this:0x000000E0]
    // GUARD: Loop guard: continue while the current slot value is not the sentinel -1 (0xFFFFFFFF); the loop stops at the first sentinel slot. [source:raw, guard:0]
    // GUARD: When the counter reaches 10 the array is full; return 10 (the saturated index) without inserting. [source:raw, field:this:0x000000E0]
    // ASSIGNMENT: Insert the value read from this+2 (byte offset 0x8) into the first free slot at this[result + 56]. [source:raw, field:this:0x00000008]
    // RETURN: Return the index of the inserted slot. [source:raw, function:0x004BD760]

    // Conservative worker pseudocode:
    //   int SentinelSlotFill(int *this) {
    //     int result = 0;
    //     for (int *i = this + 56; *i != -1; ++i) {
    //       if (++result >= 10) return result;
    //     }
    //     this[result + 56] = this[2];
    //     return result;
    //   }
    // UNRESOLVED: Semantic meaning of the stored slot value (this+0x8) and of the array entries at this+0xE0 is caller-dependent; PostPitCleanup (0042A6F0) is the only known caller.
    // UNRESOLVED: Owner object holding the slot array is unknown.
}
