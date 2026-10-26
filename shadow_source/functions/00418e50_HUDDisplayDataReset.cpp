// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00418E50
// Canonical corpus name: HUDDisplayDataReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HUDDisplayDataReset_00418e50.c

void UnknownObject::HUDDisplayDataReset()
{
    // Resets the per-driver AI HUD display data for all 104 driver slots. Gated on the race-active flag and the track-condition float, it walks 104 per-driver entries starting at this+0x350, writing a -1 driver-ID sentinel, a 0x7FFFFFFF sentinel, zeroed base/timer/flag fields and a -1.0f float sentinel per entry, then calls AITargetDriverSelection for the initial AI target assignment and zeroes three global tracking counters.
    // GUARD: Whole reset runs only when the race-active flag dword_7D0308 is set AND the track-condition float flt_7CF3C8 is not 0.0 [global:0x007D0308, global:0x007CF3C8, source:raw]
    // LOOP: Walk the 104 per-driver display entries: the walker starts at this+0x350 and advances one dword per iteration, running exactly 104 times [field:this:0x00000350, source:raw]
    // ASSIGNMENT: Per entry: write -1 to the dword at the start of the entry (driver ID sentinel) [source:raw]
    // ASSIGNMENT: Per entry: write 0x7FFFFFFF to the entry dword 104 dwords before the slot base (per-driver maximum sentinel) [source:raw]
    // ASSIGNMENT: Per entry: zero the dword at the entry base this+0x350 [field:this:0x00000350, source:raw]
    // ASSIGNMENT: Per entry: write -1.0f (source literal -1082130432) to this+0x4FC, the per-driver float timer/state sentinel [field:this:0x000004FC, source:raw]
    // ASSIGNMENT: Per entry: zero this+0x69C, the per-driver counter/timer field [field:this:0x0000069C, source:raw]
    // ASSIGNMENT: Per entry: zero this+0x83C, the per-driver byte/state flag field [field:this:0x0000083C, source:raw]
    // ASSIGNMENT: Per entry: zero the byte at this+2524 indexed by the loop counter (a 104-byte per-driver flag array) [source:raw]
    // CALL: After the loop, call AITargetDriverSelection(this) to assign the initial AI target driver [callee:0x00418EE0, source:raw]
    // ASSIGNMENT: Zero the three global tracking counters this+0x4F0, this+0x4F4 and this+0x4F8 [field:this:0x000004F0, field:this:0x000004F4, field:this:0x000004F8, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_7D0308 && flt_7CF3C8 != 0.0) {
    //     entry = this + 0x350;
    //     for (i = 0; i < 104; ++i, ++entry) {
    //       *(entry - 212) = -1;
    //       *(entry - 104) = 0x7FFFFFFF;
    //       *entry = 0;
    //       entry[107] = -1.0f;
    //       entry[211] = 0;
    //       entry[315] = 0;
    //       ((byte*)this)[i + 2524] = 0;
    //     }
    //     AITargetDriverSelection(this);
    //     this[316] = 0; this[317] = 0; this[318] = 0;
    //   }
    // UNRESOLVED: flt_59E440 is listed as a read global by the packet but never appears in the raw decompiled source text
    // UNRESOLVED: The packet records caller Game_Restart (0042d7a0) but the function body carries no direct evidence of that call context
}
