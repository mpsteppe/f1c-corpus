// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D2260
// Canonical corpus name: ProgressBarDataStore
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ProgressBarDataStore_004d2260.c

void UnknownObject::ProgressBarDataStore()
{
    // Stores two integer payload values into the progress-bar ring buffer. Reads the current write pointer from dword_8AAE64, optionally bumps the ring-buffer count dword_83EE60 (guard < 1023) and advances the pointer by 432 bytes, loads the session time float dbl_8AFEA0, then encodes a progress bar event via ProgressBarEventEncode (4, 21, 8, 255, time, 1) and writes a1 to buffer[2] and a2 to buffer[3] relative to the write pointer. Returns a1. Invoked by sub_4D4580 (004D4580).
    // ASSIGNMENT: Loads the current ring buffer write pointer from dword_8AAE64 into local v2 [global:0x008AAE64, source:raw]
    // GUARD: When the ring buffer count dword_83EE60 is below 1023, increments the count and advances the write pointer dword_8AAE64 by 432 bytes; otherwise the pointer stays put [global:0x0083EE60, global:0x008AAE64, source:raw]
    // ASSIGNMENT: Loads the current session time as a float from dbl_8AFEA0 into local v4 [global:0x008AFEA0, source:raw]
    // CALL: ProgressBarEventEncode(v2, 4, 21, 8, 255, v4, 1) encodes a progress bar event (type 21, subtype 8, colour/intensity 255, timestamp v4) into the ring buffer at the write pointer [callee:0x004B33B0, source:raw]
    // ASSIGNMENT: Writes a1 to buffer index 2 and a2 to buffer index 3 relative to the write pointer v2 [source:raw]
    // RETURN: Returns a1, echoing the first argument back to the caller [source:raw]
    // CALL: Invoked by sub_4D4580 (004D4580), the only known caller [caller:0x004D4580, source:raw]

    // Conservative worker pseudocode:
    //   ptr = dword_8AAE64;
    //   if (dword_83EE60 < 1023) {
    //       dword_83EE60 += 1;
    //       dword_8AAE64 += 432;
    //   }
    //   time = (float)dbl_8AFEA0;
    //   ProgressBarEventEncode(ptr, 4, 21, 8, 255, time, 1);
    //   ptr[2] = a1;
    //   ptr[3] = a2;
    //   return a1;
    // UNRESOLVED: Ring buffer entries are written even when the capacity guard (count < 1023) fails; the event and payload land at the current pointer regardless of whether the counter was bumped
    // UNRESOLVED: Semantics of the ProgressBarEventEncode parameters (4, 21, 8, 255, 1) are not derivable from this packet alone
}
