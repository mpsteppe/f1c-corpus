// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D37B0
// Canonical corpus name: TrackTemperatureDisplay
// Owner: TrackTemperatureDisplay [GUESS]
// Raw source: functions/TrackTemperatureDisplay_004d37b0.c

void TrackTemperatureDisplay::updateTelemetry()
{
    // Session/telemetry update for the current vehicle slot. Reads two flag properties (flag 2048) to obtain a vehicle slot index v6 and a session-state value v7, addresses the vehicle as (0x5EC6D8 base + 18624 * v6), and dispatches AI commands (5 for the active state, 4 for the transition/pit state) with a vehicle substate update; when the slot is the player vehicle it additionally runs pfnAPC and StateResetOnCondition. Rate-limits a progress-bar telemetry event to every 3 seconds, advancing a 432-byte ring buffer for encoded events, and clears the object's buffer entry each call.
    // CALL: FlagPropertyGetter reads a vehicle slot index into v6 and a session-state value into v7, both for flag 2048 [callee:0x0054C150]
    // ASSIGNMENT: Computes the addressed vehicle slot: v2 = unk_5EC6D8 + 18624 * v6 (vehicle array base plus slot stride) [global:0x005EC6D8]
    // GUARD: Branches on the session-state value v7 not equal to -11 [source:raw, callee:0x0054C150]
    // CALL: Active-state path: AICommandMessageQueueDispatcher(v2, 5, 0) queues AI command 5 for the vehicle slot [callee:0x00424CD0, global:0x005EC6D8]
    // CALL: sub_4A5F20 updates the vehicle telemetry substate at v2 + 13004 [callee:0x004A5F20, global:0x005EC6D8]
    // STATE_TRANSITION: When the addressed slot is the player vehicle (v2 == dword_7C54E8): pfnAPC(0) and StateResetOnCondition(&dword_5EA510) [global:0x007C54E8, callee:0x0041A160, callee:0x0040D450, global:0x005EA510]
    // CALL: Transition/pit path (v7 == -11): AICommandMessageQueueDispatcher(v2, 4, 0) queues AI command 4 for the vehicle slot [callee:0x00424CD0, global:0x005EC6D8]
    // CALL: sub_4A5EA0 updates the vehicle telemetry substate at v2 + 13004 [callee:0x004A5EA0, global:0x005EC6D8]
    // STATE_TRANSITION: When the addressed slot is the player vehicle (v2 == dword_7C54E8): pfnAPC(1) [global:0x007C54E8, callee:0x0041A160]
    // GUARD: Rate limit: when fabs(dbl_8AFEA0 - flt_8AC4B0) <= 3.0 the telemetry event is skipped; both the active and transition paths converge here, clear the buffer entry at this+0x14 via BufferEntryClear(this[5]) and return 0 [global:0x008AFEA0, global:0x008AC4B0, callee:0x0054FAE0, field:this:0x00000014]
    // CALCULATION: Ring-buffer slot selection: when counter dword_83EE60 >= 1023 reuse the current pointer dword_8AAE64; otherwise increment dword_83EE60 and advance dword_8AAE64 by 432 bytes [global:0x0083EE60, global:0x008AAE64]
    // CALL: ProgressBarEventEncode(v3, 3, 7, 0, v2[4645], dbl_8AFEA0, 0) encodes a telemetry event for the vehicle slot; then flt_8AC4B0 = dbl_8AFEA0 updates the rate-limit stamp [callee:0x004B33B0, global:0x005EC6D8, global:0x008AFEA0, global:0x008AC4B0]
    // RETURN: Clears the buffer entry at this+0x14 via BufferEntryClear(this[5]) and returns 0 [callee:0x0054FAE0, field:this:0x00000014, function:0x004D37B0]

    // Conservative worker pseudocode:
    //   FlagPropertyGetter(&v6, 2048);
    //   FlagPropertyGetter(&v7, 2048);
    //   v2 = (int *)((char *)&unk_5EC6D8 + 18624 * v6);
    //   if (v7 != -11) {
    //       AICommandMessageQueueDispatcher(v2, 5, 0);
    //       sub_4A5F20((_BYTE *)v2 + 13004);
    //       if (v2 == dword_7C54E8) { pfnAPC(0); StateResetOnCondition(&dword_5EA510); }
    //   } else {
    //       AICommandMessageQueueDispatcher(v2, 4, 0);
    //       sub_4A5EA0((_BYTE *)v2 + 13004);
    //       if (v2 == dword_7C54E8) pfnAPC(1);
    //   }
    //   if (fabs(dbl_8AFEA0 - flt_8AC4B0) <= 3.0) {
    //       BufferEntryClear(this[5]);
    //       return 0;
    //   }
    //   if (dword_83EE60 >= 1023) v3 = dword_8AAE64;
    //   else { ++dword_83EE60; v3 = dword_8AAE64; dword_8AAE64 += 432; }
    //   ProgressBarEventEncode(v3, 3, 7, 0, v2[4645], dbl_8AFEA0, 0);
    //   flt_8AC4B0 = dbl_8AFEA0;
    //   BufferEntryClear(this[5]);
    //   return 0;
    // UNRESOLVED: Read-only globals flt_59E478 and dword_5EB978 are listed but do not appear in the raw source; their role in this function is unknown
    // UNRESOLVED: The v2[4645] vehicle field read and the 13004-byte substate offset are consumed only as arguments; their semantics come from the vehicle structure, not this function
    // UNRESOLVED: Owner identity is a GUESS: the ABI lead names this TrackTemperatureDisplay, but the body reads more like a session-state/telemetry dispatcher; the concrete class is unverified
    // UNRESOLVED: The session-state enumeration at flag 2048 (value -11 vs otherwise) is not independently confirmed
}
