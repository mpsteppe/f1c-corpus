// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EF2E0
// Canonical corpus name: sub_4EF2E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4EF2E0_004ef2e0.c

void UnknownObject::ForceFeedbackEventLogger()
{
    // Throttled force-feedback state logger. Reads the current session time (dbl_8AFEA0), and when the delta since the last logged event (field 0x1018) exceeds 0.125s it compares the previously stored 18-byte FF snapshot (fields 0x101C..0x102C) against the live force-feedback state returned by ForceFeedback(this+0x6E4). On mismatch it stores an event via ProgressBarEventEncode into a ring buffer (dword_8AAE64, count dword_83EE60) and records the new snapshot. When the delta exceeds 4.0s it force-logs the current FF state without a comparison. Both paths select an event code of 6 or 18 from a zero-test on the FF state and pass the object id (field 0x4) plus session time as payload.
    // CALCULATION: Compute elapsed time: delta = dbl_8AFEA0 - *(float*)(this+0x1018). [source:raw, global:0x008AFEA0, field:this:0x00001018]
    // GUARD: Debounce gate: proceed only when delta >= 0.125; otherwise do nothing this call. [source:raw]
    // GUARD: Branch on delta <= 4.0: inside = compare-and-log path; else = forced flush path without comparison. [source:raw]
    // ASSIGNMENT: Build an 18-byte stored-state snapshot into local buffer from fields 0x101C (dword), 0x1020, 0x1024, 0x1028 and 16-bit field 0x102C. [source:raw, field:this:0x0000101C, field:this:0x00001020, field:this:0x00001024, field:this:0x00001028, field:this:0x0000102C]
    // CALL: Call ForceFeedback(this + 0x6E4) to obtain the current 18-byte force-feedback state pointer. [callee:0x004E2760, source:raw]
    // ASSIGNMENT: Copy the live state from the returned pointer: four dwords at +0/+4/+8/+12 and a 16-bit word at +16 into locals v26..v30. [source:raw]
    // LOOP: Word-wise comparison loop (9 iterations) of stored snapshot vs live state; stops at the first mismatch. [source:raw]
    // GUARD: Log only on mismatch: if the stored and live states are equal, no event is written. [source:raw]
    // ASSIGNMENT: Update last-event timestamp: this+0x1018 = dbl_8AFEA0. [source:raw, field:this:0x00001018, global:0x008AFEA0]
    // CALCULATION: Ring buffer advance: if dword_83EE60 < 1023 then increment dword_83EE60 and add 432 to the write pointer dword_8AAE64. [source:raw, global:0x0083EE60, global:0x008AAE64]
    // CALCULATION: Event-kind selection: code 6 when byte2 of the second live dword and the third dword are both zero, else code 18. [source:raw]
    // CALL: Call ProgressBarEventEncode(ring_ptr, 2, 2, kind, *(DWORD*)(this+0x4), dbl_8AFEA0, 0) to encode the event header with the object id and session time. [callee:0x004B33B0, source:raw, field:this:0x00000004, global:0x008AFEA0]
    // ASSIGNMENT: Write the 18-byte live state payload (v26..v30) into the ring slot at ring_ptr+8..ring_ptr+24. [source:raw]
    // ASSIGNMENT: Forced-flush path: update last-event timestamp this+0x1018 = dbl_8AFEA0. [source:raw, field:this:0x00001018, global:0x008AFEA0]
    // CALCULATION: Ring buffer advance: if dword_83EE60 < 1023 then increment dword_83EE60 and add 432 to the write pointer dword_8AAE64. [source:raw, global:0x0083EE60, global:0x008AAE64]
    // CALL: Call ForceFeedback(this + 0x6E4) to obtain the current force-feedback state pointer. [callee:0x004E2760, source:raw]
    // ASSIGNMENT: Write the live state directly into the ring slot at +8 (dword), +12, +16, +20 and +24 (word) with no prior comparison. [source:raw]
    // CALCULATION: Event-kind selection for flush path: code 6 when byte at slot+14 and dword at slot+16 are both zero, else code 18. [source:raw]
    // CALL: Call ProgressBarEventEncode(ring_ptr, 2, 2, kind, *(DWORD*)(this+0x4), dbl_8AFEA0, 0) to encode the flush event header. [callee:0x004B33B0, source:raw, field:this:0x00000004, global:0x008AFEA0]

    // Conservative worker pseudocode:
    //   float now = dbl_8AFEA0;
    //   double delta = now - this->lastEventTime;  // field 0x1018
    //   if (delta >= 0.125) {
    //     if (delta <= 4.0) {
    //       char stored[18]; copy from this fields 0x101C..0x102C;
    //       int ff = ForceFeedback(this + 0x6E4);
    //       char cur[18]; copy dwords at ff+0/+4/+8/+12 and word at ff+16;
    //       if (memcmp(stored, cur, 18) != 0) {
    //         this->lastEventTime = now;
    //         char* slot = dword_8AAE64;
    //         if (dword_83EE60 < 1023) { ++dword_83EE60; dword_8AAE64 += 432; }
    //         int kind = (!cur[6] && !cur[8..11]) ? 6 : 18;
    //         ProgressBarEventEncode(slot, 2, 2, kind, this->unit, now, 0);  // unit = field 0x4
    //         copy cur[18] to slot+8..slot+24;
    //       }
    //     } else {
    //       this->lastEventTime = now;
    //       char* slot = dword_8AAE64;
    //       if (dword_83EE60 < 1023) { ++dword_83EE60; dword_8AAE64 += 432; }
    //       int ff = ForceFeedback(this + 0x6E4);
    //       copy ff[0..16] to slot+8..slot+24;
    //       int kind = (!slot[14] && !slot[16..19]) ? 6 : 18;
    //       ProgressBarEventEncode(slot, 2, 2, kind, this->unit, now, 0);
    //     }
    //   }
    // UNRESOLVED: The object type and the meaning of the 18-byte force-feedback state payload are not established by this packet alone.
    // UNRESOLVED: The event-kind test reads byte 2 of the second state dword and the third state dword; the semantic meaning of code 6 vs 18 is unknown.
    // UNRESOLVED: Two read-only globals (flt_59E46C, flt_59E4E0) are flagged by packet facts but appear nowhere in the raw decompiled source; their role is not verifiable here.
    // UNRESOLVED: The 432-byte ring slot stride and the 1023-count ceiling come directly from the source, but the ring buffer owner and reader are unknown.
}
