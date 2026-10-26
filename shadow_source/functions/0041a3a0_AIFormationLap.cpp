// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041A3A0
// Canonical corpus name: AIFormationLap
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIFormationLap_0041a3a0.c

void UnknownObject::AIFormationLap()
{
    // Formation-lap race-start event handler. Emits per-driver session commentary events only when a race is active, the track condition state is nonzero, the race phase is not post-race, and the driver is not the player. Race/practice sessions (session type <= 6) and World Championship mode emit the generic event code 6; a championship weekend (session type 7) outside World Championship mode emits a formation-lap position event (180/181/182) selected by field 0x342C when the position counter is within one lap of the current lap number.
    // GUARD: Function identity: formation-lap race-start event handler (legacy ABI label AI_Formation_Lap_Race_Start), dispatched per frame from the AI session event pipeline. [abi:lead, caller:0x004A5F20, function:0x0041A3A0, source:raw]
    // GUARD: Outer guard: race must be active (dword_7D0308 nonzero), otherwise return immediately. [global:0x007D0308]
    // GUARD: Track-condition guard: flt_7CF3C8 must be nonzero and race phase (dword_7C56A8) must not be 8 (post-race). [global:0x007CF3C8, global:0x007C56A8]
    // CALL: Initialize the local 8-DWORD event-parameter buffer v4 with sentinel values. [callee:0x004144D0]
    // GUARD: Skip the player's own events: this driver's driver ID (field 0x4894) must differ from the player vehicle's driver ID (dword_7C54E8 + 0x4894), and session type (dword_7C56A4) must be >= 0. [field:this:0x00004894, global:0x007C54E8, global:0x007C56A4]
    // GUARD: Session-type branch: if dword_7C56A4 <= 6 (race/practice), fall through to generic event code 6. [global:0x007C56A4]
    // GUARD: Session-type branch: if dword_7C56A4 != 7 (championship weekend), return without emitting an event. [global:0x007C56A4]
    // GUARD: Championship-mode branch: if dword_7D0410 == 5 (World Championship), fall through to generic event code 6 instead of position-specific events. [global:0x007D0410]
    // ASSIGNMENT: v1 (lap_number) = a1[4111], the current lap counter at field 0x403C. [field:this:0x0000403C]
    // ASSIGNMENT: v2 (formation_lap_position) = a1[3340], the formation-lap position counter at field 0x3430. [field:this:0x00003430]
    // GUARD: Lap-proximity guard: emit only when the formation-lap position counter v2 is within one lap of the lap number v1 (v2 >= v1 - 1 && v2 <= v1 + 1). [field:this:0x00003430, field:this:0x0000403C]
    // STATE_TRANSITION: Select the formation-lap position event code from field 0x342C: 1 -> 180, 2 -> 181, 3 -> 182; any other value returns without emitting. [field:this:0x0000342C]
    // ASSIGNMENT: Generic path sets event_code v3 = 6 for race/practice sessions and World Championship mode. [global:0x007D0410, global:0x007C56A4]
    // CALL: DriverDataTableLookupAndTimeConversion(v4, event_code v3, a1[4647] driver index at field 0x489C, -1, -1, -1, -2.0, -2.0) fills the event-parameter buffer for the driver. [callee:0x004144F0, field:this:0x0000489C]
    // CALL: InsertDriverTableEntry(flt_5EA618, v4) inserts the built event row into the session event table. [callee:0x00418560, global:0x005EA618]
    // RETURN: Early return when the session type is not 7 after the position-specific branch is ruled out. [global:0x007C56A4]
    // RETURN: Early return from the switch default when field 0x342C holds no known formation-lap position status. [field:this:0x0000342C]

    // Conservative worker pseudocode:
    //   if (!race_active) return;
    //   if (track_condition == 0.0f || race_phase == 8) return;
    //   StructInitWithSentinelValues(&event_params);
    //   if (player_vehicle[0x4894] == this[0x4894] || session_type < 0) return;
    //   if (session_type <= 6 || (session_type == 7 && world_championship == 5)) { event_code = 6; }
    //   else if (session_type != 7) return;
    //   else {
    //     lap_number = this[0x403C]; formation_lap_position = this[0x3430];
    //     if (!(formation_lap_position >= lap_number - 1 && formation_lap_position <= lap_number + 1)) return;
    //     switch (this[0x342C]) { case 1: event_code = 180; break; case 2: event_code = 181; break; case 3: event_code = 182; break; default: return; }
    //   }
    //   DriverDataTableLookupAndTimeConversion(&event_params, event_code, this[0x489C], -1, -1, -1, -2.0, -2.0);
    //   InsertDriverTableEntry(session_event_table, &event_params);
    // UNRESOLVED: flt_59E440 is listed as a read global in the packet facts but does not appear in the raw decompiled body; its role is unknown.
    // UNRESOLVED: Session-type semantics (0-6 = race/practice, 7 = championship weekend) and World Championship mode value 5 are inferred from the existing skeleton analysis prose, not from constants present in the packet.
    // UNRESOLVED: Event code meanings (6 generic, 180/181/182 formation-lap position) are derived from the skeleton prose and are not confirmed by independent runtime evidence.
}
