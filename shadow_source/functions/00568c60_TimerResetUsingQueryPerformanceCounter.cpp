// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00568C60
// Canonical corpus name: TimerResetUsingQueryPerformanceCounter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TimerResetUsingQueryPerformanceCounter_00568c60.c

void UnknownObject::TimerResetUsingQueryPerformanceCounter()
{
    // Resets a high-resolution timer struct. Gated on the frequency base at offset 0x0 being non-zero (timer initialized). When the mode dword at offset 0x48 has bit 0 set, it refreshes the QPC snapshot via QueryPerformanceCounter (stored at 0x18/0x1C); otherwise it reuses the existing snapshot. It then copies the snapshot into the working pair (0x20/0x24), zeroes six accumulator dwords (0x10/0x14, 0x28/0x2C and 0x30/0x34), and returns the snapshot low dword (offset 0x18).
    // GUARD: Guard: proceed only when the frequency base at offset 0x0 is non-zero, i.e. the timer was initialized. [field:this:0x00000000, source:raw]
    // GUARD: Guard: when the mode dword at offset 0x48 has bit 0 set, refresh the QPC snapshot before resetting. [field:this:0x00000048, source:raw]
    // CALL: Call QueryPerformanceCounter via the import pointer global 0x0059E23C to snapshot the current tick count. [global:0x0059E23C, source:raw]
    // ASSIGNMENT: Store the fresh counter low/high dwords at offsets 0x18/0x1C (this[6]/this[7]). [field:this:0x00000018, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Zero the six accumulator dwords: 0x10/0x14 (this[4]/this[5]), 0x28/0x2C (this[10]/this[11]) and 0x30/0x34 (this[12]/this[13]). [field:this:0x00000010, field:this:0x00000014, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, source:raw]
    // ASSIGNMENT: Copy the current snapshot pair into the working pair: offset 0x20 gets 0x18, offset 0x24 gets 0x1C (this[8] = this[6], this[9] = this[7]). [field:this:0x00000020, field:this:0x00000024, source:raw]
    // RETURN: Return the snapshot low dword (offset 0x18). [field:this:0x00000018, source:raw]

    // Conservative worker pseudocode:
    //   int TimerResetUsingQueryPerformanceCounter(_DWORD *this) {
    //     LARGE_INTEGER count;
    //     if (*this) {
    //       if ((this[18] & 1) != 0) {
    //         QueryPerformanceCounter(&count);
    //         this[6] = count.LowPart;
    //         this[7] = count.HighPart;
    //       }
    //       this[12] = 0;
    //       this[13] = 0;
    //       this[10] = 0;
    //       this[11] = 0;
    //       this[8] = this[6];
    //       this[9] = this[7];
    //       this[4] = 0;
    //       this[5] = 0;
    //       return this[6];
    //     }
    //   }
    // UNRESOLVED: The global byte_FF00000000005406 is a malformed high import-table artifact with no identified semantic role.
    // UNRESOLVED: When the offset 0x0 guard fails, the decompiled result is never assigned, so the returned value is unspecified; this is a decompiler artifact since callers only reach the reset path on an initialized timer.
    // UNRESOLVED: The owning class is unknown; field-role labels follow the shared high-resolution timer layout used by the sibling QPCTimerInitialization.
}
