// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042AEE0
// Canonical corpus name: PitStopBlockingCondition
// Owner: F1CVehicle [CONFIRMED]
// Raw source: functions/PitStopBlockingCondition_0042aee0.c

void F1CVehicle::PitStopBlockingCondition()
{
    // Per-frame pit-blocked check on an F1CVehicle with two paths gated by session type. For non-race sessions it returns bit 8 of an indexed pit-schedule slot (index read from +0x45E0). For race sessions (dword_7C56A4 == 7) it ORs four conditions: lapNumber (+0x403C) >= dword_8ACF8C, dword_7C56A8 == 8, a byte at +0x39FA, and a rear-wing damage record reached through the +0x0 pointer (ptr at obj+0xD18 nonzero AND intact byte at obj+0xD58 zero).
    // GUARD: If session type dword_7C56A4 is not 7, take the non-race path and skip the race-session terms. [global:0x007C56A4, source:raw]
    // CALCULATION: Non-race path: return this[4 * this[4472] + 4455] & 8, where this[4472] is the pit-schedule index at +0x45E0 and the indexed slot base (dword index 4455, +0x459C) is not packet-listed. [field:this:0x000045E0, source:raw]
    // CALCULATION: Race-path term 1: lapNumber at +0x403C (this[4111]) >= dword_8ACF8C. [field:this:0x0000403C, global:0x008ACF8C, source:raw]
    // CALCULATION: Race-path term 2: global dword_7C56A8 equals 8. [global:0x007C56A8, source:raw]
    // CALCULATION: Race-path term 3: the byte at this+0x39FA is nonzero. [field:this:0x000039FA, source:raw]
    // CALCULATION: Race-path term 4: dereference the +0x0 pointer and test the rear-wing damage record — dword at obj+0xD18 nonzero AND byte at obj+0xD58 zero. [field:this:0x00000000, field:obj:0x00000D18, field:obj:0x00000D58, source:raw]
    // RETURN: Race path returns the OR of the four terms above; non-race path returns the indexed bitmask. [source:raw]

    // Conservative worker pseudocode:
    //   if (dword_7C56A4 != 7)
    //       return (this[4 * this[4472] + 4455] & 8);
    //   return (this[4111] >= dword_8ACF8C)
    //       || (dword_7C56A8 == 8)
    //       || *(byte*)(this + 0x39FA)
    //       || (*(dword*)*this + 0xD18 && !*(byte*)*this + 0xD58);
    // UNRESOLVED: The indexed pit-schedule slot (dword index 4455, +0x459C) is not packet-listed; only the index field +0x45E0 is evidenced.
    // UNRESOLVED: obj+0xD18 / obj+0xD58 are reached through the +0x0 pointer dereference; the existing analysis identifies them as the rear-wing damage record (pointer + intact flag), but the packet itself does not name the sub-object.
    // UNRESOLVED: The meaning of dword_7C56A8 == 8 (race phase) is from existing-analysis prose; the packet only evidences the literal comparison.
}
