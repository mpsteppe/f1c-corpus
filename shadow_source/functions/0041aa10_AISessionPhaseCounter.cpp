// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041AA10
// Canonical corpus name: AISessionPhaseCounter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AISessionPhaseCounter_0041aa10.c

void UnknownObject::AISessionPhaseCounter()
{
    // Per-driver session-phase completion tracker in the AI/session event pipeline. When the race is active (dword_7D0308 nonzero, flt_7CF3C8 nonzero, dword_7C56A8 not 8), it sets the completion flag for the given phase index (this+0xA44 + 4*phase) and counts how many of the four phase flags are set. If fewer than three are set it emits an individual phase event (ID 95/97/99/101 depending on the phase index, dispatched through jump table jpt_41AA9C); otherwise it emits the combined event (ID 105). In both cases the event is materialized into a local descriptor by DriverDataTableLookupAndTimeConversion and appended to the session event table via InsertDriverTableEntry. Called per-frame from VehicleDynamicsForceAccumulatorIntegration (00438130).
    // GUARD: Whole body gated on the session being live: dword_7D0308 (race active) nonzero, flt_7CF3C8 (track condition) not equal to 0.0, and dword_7C56A8 (race phase) not equal to 8 [global:0x007D0308, global:0x007CF3C8, global:0x007C56A8]
    // ASSIGNMENT: Sets the completion flag for the phase: writes 1 to this[a2 + 657], i.e. the DWORD at this+0xA44 + 4*a2 [field:this:0x00000A44, source:raw]
    // CALL: StructInitWithSentinelValues initializes the local 8-DWORD event descriptor v6 with sentinel defaults before the table lookup fills it [callee:0x004144D0, source:raw]
    // LOOP: Iterates the four phase-completion flags at this+0xA44 .. this+0xA44+0xC (4 DWORDs), incrementing the count v3 for each nonzero entry [field:this:0x00000A44, source:raw]
    // STATE_TRANSITION: Branches on the count: when fewer than 3 flags are set, switches on the phase index a2 through the jump table jpt_41AA9C to select the individual phase event; otherwise selects the combined event (105) [global:0x0041AB1C, source:raw]
    // CALL: DriverDataTableLookupAndTimeConversion fills v6 for the chosen event ID (95/97/99/101 per phase index 0-3, or 105 for the combined case) with default index -1 arguments and -2.0 sentinel times [callee:0x004144F0, source:raw]
    // CALL: InsertDriverTableEntry appends the filled descriptor v6 to the session event table pointed at by flt_5EA618 [callee:0x00418560, global:0x005EA618]
    // CALL: Invoked per-frame from VehicleDynamicsForceAccumulatorIntegration (00438130) [caller:0x00438130]

    // Conservative worker pseudocode:
    //   if (dword_7D0308 != 0 && flt_7CF3C8 != 0.0 && dword_7C56A8 != 8) {
    //     this[0xA44/4 + a2] = 1;
    //     StructInitWithSentinelValues(&desc);
    //     count = 0;
    //     for (i = 0; i < 4; ++i)
    //       if (this[0xA44/4 + i]) ++count;
    //     if (count < 3)
    //       eventId = switch(a2) { 0:95, 1:97, 2:99, 3:101, default: none };
    //     else
    //       eventId = 105;
    //     DriverDataTableLookupAndTimeConversion(&desc, eventId, -1, -1, -1, -1, -2.0, -2.0);
    //     InsertDriverTableEntry(flt_5EA618, &desc);
    //   }
    // UNRESOLVED: flt_59E440 is listed by the packet globals but never appears in the raw decompiled source; the skeleton fill calls it a zero-threshold constant, which is unverifiable from this packet
    // UNRESOLVED: The packet records field this+0xA44 as read-only even though the raw source writes it; the effective write target is this+0xA44 + 4*a2
    // UNRESOLVED: The -2.0 sentinel values and the -1 default indices passed to DriverDataTableLookupAndTimeConversion have unknown meaning
}
