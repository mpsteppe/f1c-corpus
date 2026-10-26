// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00556440
// Canonical corpus name: HighResolutionTimerReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HighResolutionTimerReset_00556440.c

void UnknownObject::HighResolutionTimerReset()
{
    // Resets a high-resolution timer object: if the timer is initialized, it queries a fresh timestamp (QueryPerformanceCounter when the mode flag bit 0 is set, otherwise RDTSCTimestampRead), stores it at offsets 0x18/0x1C, copies it as a snapshot to 0x20/0x24, and clears all accumulator and previous-timestamp fields (0x10/0x14, 0x28/0x2C, 0x30/0x34) to zero. Returns the timer frequency field value.
    // GUARD: Guard on *this (offset 0x0): the timer frequency field is non-zero only when the timer is initialized; the entire reset body runs only then. [field:this:0x00000000]
    // GUARD: Guard on (this[18] & 1) != 0 (offset 0x48): the mode flag selects the timestamp source, QueryPerformanceCounter when bit 0 is set. [field:this:0x00000048]
    // CALL: Call QueryPerformanceCounter(&PerformanceCount) to obtain the fresh timestamp for the QPC path. [global:0x0059E23C]
    // ASSIGNMENT: Store the fresh timestamp into this[6] (0x18, low part) and this[7] (0x1C, high part) on the QPC path. [field:this:0x00000018, field:this:0x0000001C]
    // CALL: Call RDTSCTimestampRead(this + 7, this + 6) to write the RDTSC timestamp into offsets 0x1C/0x18 on the non-QPC path. [callee:0x0055687B]
    // ASSIGNMENT: Clear the accumulated-elapsed accumulator fields this[4] (0x10) and this[5] (0x14) to 0. [field:this:0x00000010, field:this:0x00000014]
    // ASSIGNMENT: Snapshot the fresh timestamp: copy result from offset 0x18 and v6 from offset 0x1C into this[8] (0x20) and this[9] (0x24). [field:this:0x00000020, field:this:0x00000024]
    // ASSIGNMENT: Clear the delta-accumulator fields this[10] (0x28) and this[11] (0x2C) to 0. [field:this:0x00000028, field:this:0x0000002C]
    // ASSIGNMENT: Clear the previous-timestamp fields this[12] (0x30) and this[13] (0x34) to 0. [field:this:0x00000030, field:this:0x00000034]
    // RETURN: Return result = *this (the timer frequency field from offset 0x0). [field:this:0x00000000]

    // Conservative worker pseudocode:
    //   int sub_556440(int *this) {
    //     int result = this[0];
    //     if (this[0]) {
    //       LARGE_INTEGER pc;
    //       if (this[18] & 1) {
    //         QueryPerformanceCounter(&pc);
    //         this[6] = pc.LowPart;
    //         this[7] = pc.HighPart;
    //       } else {
    //         RDTSCTimestampRead(&this[7], &this[6]);
    //       }
    //       this[12] = 0; this[13] = 0;
    //       this[10] = 0; this[11] = 0;
    //       this[8] = this[6]; this[9] = this[7];
    //       this[4] = 0; this[5] = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The exact meaning of the byte_FF00000000005406 global is unresolved; it does not appear in the raw decompilation and is likely a mis-extracted constant associated with the RDTSC path.
    // UNRESOLVED: Offset 0x48 mode-flag bit assignment (bit 0 = use QPC, else RDTSC) is inferred from the guard and not independently confirmed.
    // UNRESOLVED: The owning class and the exact 64-bit structure layout are unknown.
}
