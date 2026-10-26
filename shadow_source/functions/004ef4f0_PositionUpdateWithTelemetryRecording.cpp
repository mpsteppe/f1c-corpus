// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EF4F0
// Canonical corpus name: PositionUpdateWithTelemetryRecording
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PositionUpdateWithTelemetryRecording_004ef4f0.c

void UnknownObject::PositionUpdateWithTelemetryRecording()
{
    // Per-frame telemetry tick: when the session time dbl_8AFEA0 exceeds the last-recorded timestamp at this+0x4014 plus 4.5, stamps the new time and appends a telemetry/event record into a bounded ring buffer (slots capped at 1023, 432-byte stride), encoding it with ProgressBarEventEncode. Part of the telemetry/event recording system; called by Gearbox and RaceStartCountdownStateUpdate.
    // GUARD: Time gate: record only when session time dbl_8AFEA0 is greater than the last-recorded time at this+0x4014 plus 4.5. [global:0x008AFEA0, field:this:0x00004014, source:raw]
    // ASSIGNMENT: Stamp the last-recorded time: this+0x4014 = dbl_8AFEA0. [field:this:0x00004014, global:0x008AFEA0, source:raw]
    // GUARD: Ring-buffer capacity check: when the record count dword_83EE60 is already >= 1023, the current write slot is reused without advancing. [global:0x0083EE60, source:raw]
    // CALCULATION: Otherwise increment the record count dword_83EE60 and advance the write pointer dword_8AAE64 by the 432-byte record stride; both branches take the slot pointer as dword_8AAE64. [global:0x0083EE60, global:0x008AAE64, source:raw]
    // CALL: Encode a telemetry/event record: ProgressBarEventEncode(slot, 2, 0, 0, value at this+0x4, value at this+0x34AC, 0). [callee:0x004B33B0, field:this:0x00000004, field:this:0x000034AC, source:raw]
    // CALL: Invoked from Gearbox (0x00443B70) and RaceStartCountdownStateUpdate (0x004EF930). [caller:0x00443B70, caller:0x004EF930, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4EF4F0(int this) {
    //     if (dbl_8AFEA0 > *(float *)(this + 0x4014) + 4.5) {
    //       *(float *)(this + 0x4014) = dbl_8AFEA0;
    //       _DWORD *slot;
    //       if (dword_83EE60 >= 1023) {
    //         slot = (_DWORD *)dword_8AAE64;
    //       } else {
    //         ++dword_83EE60;
    //         slot = (_DWORD *)dword_8AAE64;
    //         dword_8AAE64 += 432;
    //       }
    //       ProgressBarEventEncode(slot, 2, 0, 0, *(_DWORD *)(this + 0x4), *(_DWORD *)(this + 0x34AC), 0);
    //     }
    //   }
    // UNRESOLVED: Semantics of the ProgressBarEventEncode argument tuple (2, 0, 0, ..., 0) and the meaning of the payload fields this+0x4 and this+0x34AC are unresolved.
    // UNRESOLVED: The 1023 slot ceiling and 432-byte stride bound the telemetry ring buffer, but its capacity/reuse semantics are unknown.
    // UNRESOLVED: Global flt_5ACB5C appears in the packet global list but is not referenced by the raw source text; it is listed here only to account for the evidence reference.
}
