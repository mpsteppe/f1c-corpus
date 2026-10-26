// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041B3C0
// Canonical corpus name: PitSelectionStateMachine
// Owner: PitSelectionStateMachine [DERIVED]
// Raw source: functions/PitSelectionStateMachine_0041b3c0.c

void PitSelectionStateMachine::pitSelectionStateMachine()
{
    // Per-frame pit-selection commentary state machine. Guarded by race-active flag, track-condition state, player-vehicle flag, and race phase. Computes a requested zone index (v7) from clamped input a4 and a projected zone index (v8) from the player vehicle's distance projection, then dispatches on event/state argument a2 through a jump table: state 0 deactivates a zone (clearing this[v7+316], emitting zone-specific event codes 133/135/137 or the common 126), state 2 activates a zone (committing this[v7+316]=2, firing preceding event pairs via BooleanOROfTwoChecks), state 3 emits generic event 131, state 5 emits player pit-entry sub-events 123-125 when the player vehicle matches a5. Built entries are inserted into session event table flt_5EA618 through the shared sentinel-guarded tail.
    // GUARD: Outer execution guard: proceed only when race active dword_7D0308 is nonzero, track condition flt_7CF3C8 is nonzero, the player vehicle byte at offset 13388 is clear, and race phase dword_7C56A8 is not 8. [function:0x0041B3C0, source:raw, global:0x007D0308, global:0x007CF3C8, global:0x007C54E8, global:0x007C56A8]
    // CALCULATION: Clamp input a4 to [0.0, flt_5EA3FC]: negative values become 0.0, values above flt_5EA3FC are capped to it. [source:raw, global:0x005EA3FC]
    // CALL: StructInitWithSentinelValues initializes the 8-DWORD local event entry v13 with sentinel values. [source:raw, callee:0x004144D0]
    // CALL: DistanceProjectionCalc computes a distance projection from the player vehicle (dword_7C54E8 + 12) and stores the double result in v11. [source:raw, callee:0x004F0050, global:0x007C54E8]
    // CALL: FloatRangeIndexLookup maps the clamped requested input a4 to a zone index v7. [source:raw, callee:0x004D7C10]
    // CALL: FloatRangeIndexLookup maps the projected distance v11 to a zone index v8. [source:raw, callee:0x004D7C10]
    // CALCULATION: v9 records whether the projected zone index equals the requested zone index (v8 == v7); used to gate re-entry events across state 0 and state 2 paths. [source:raw]
    // STATE_TRANSITION: Dispatch on event/state argument a2 through jump table jpt_41B47F: state 0 deactivates a zone, state 2 activates a zone, state 3 emits a generic event, state 5 handles player pit entry. [source:raw, global:0x0041B8F0]
    // GUARD: State 0 pre-check: the per-zone activation flag this[v7 + 316] must equal 2 and ScoringGateSelector(v7) must return false before the zone can be deactivated. [source:raw, callee:0x004D1AD0]
    // ASSIGNMENT: Deactivate the zone: clear the per-zone flag this[v7 + 316] to 0. [source:raw]
    // GUARD: State 0 zone-event path proceeds only when session type dword_7C56A4 equals 7 and race phase dword_7C56A8 is not 5; otherwise control falls through to the shared tail. [source:raw, global:0x007C56A4, global:0x007C56A8]
    // CALL: State 0, zone index 0: guarded by projected zone v8 not being 1; StateCheckedVirtualDispatch then ArraySearchReturningIndex evaluate whether event 138 already exists in session table flt_5EA618. [source:raw, callee:0x004189B0, callee:0x004189F0, global:0x005EA618]
    // CALL: State 0, zone index 0 fill: DriverDataTableLookupAndTimeConversion builds an event 137 entry (v13, 137, -1, -1, -1, -1, -2.0, -2.0). [source:raw, callee:0x004144F0]
    // CALL: State 0, zone index 1 (v7 == 1): guarded by projected zone v8 not being 2; StateCheckedVirtualDispatch then ArraySearchReturningIndex evaluate whether event 134 already exists in session table flt_5EA618. [source:raw, callee:0x004189B0, callee:0x004189F0, global:0x005EA618]
    // CALL: State 0, zone index 1 fill: DriverDataTableLookupAndTimeConversion builds an event 133 entry (v13, 133, -1, -1, -1, -1, -2.0, -2.0); when zones match (v9) an event 126 entry is filled instead via LABEL_37. [source:raw, callee:0x004144F0]
    // CALL: State 0, zone index 2 (v7 == 2): guarded by projected zone v8 being 1; StateCheckedVirtualDispatch then ArraySearchReturningIndex evaluate whether event 136 already exists in session table flt_5EA618. [source:raw, callee:0x004189B0, callee:0x004189F0, global:0x005EA618]
    // CALL: State 0, zone index 2 fill: DriverDataTableLookupAndTimeConversion builds an event 135 entry (v13, 135, -1, -1, -1, -1, -2.0, -2.0); when zones match (v9) an event 126 entry is filled instead via LABEL_37. [source:raw, callee:0x004144F0]
    // CALL: LABEL_37 common re-entry fill: DriverDataTableLookupAndTimeConversion builds an event 126 entry (v13, 126, -1, -1, -1, -1, -2.0, -2.0) for the zone-matching case. [source:raw, callee:0x004144F0]
    // RETURN: Shared tail (LABEL_67): if the first entry field LODWORD(v13[0]) is not the -1 sentinel, InsertDriverTableEntry inserts the entry into session table flt_5EA618, then the function returns. [source:raw, callee:0x00418560, global:0x005EA618]
    // GUARD: State 2 activation condition: triggered when the projected zone moved (v8 != v7) or the projected distance plus 50.0 falls below the requested a4; per-zone sub-branches additionally gate on v8 and on FloatWrapTableInterpolation(v11, 0) producing a value below 0.89999998. [source:raw, callee:0x004D7CF0]
    // CALL: State 2 per-zone event churn: BooleanOROfTwoChecks fires the preceding event pair on session table flt_5EA618 (137/134 for zone 0, 133/136 for zone 1, 135/138 for zone 2), ArraySearchReturningIndex clears the target event (138, 134 or 136), and DriverDataTableLookupAndTimeConversion fills the matching code (138, 134 or 136). [source:raw, callee:0x00418A20, callee:0x004189F0, callee:0x004144F0, global:0x005EA618]
    // ASSIGNMENT: State 2 commit: set the per-zone activation flag this[v7 + 316] to 2, then reach the shared insertion tail. [source:raw]
    // CALL: State 3: DriverDataTableLookupAndTimeConversion builds a generic event 131 entry (v13, 131, -1, -1, -1, -1, -2.0, -2.0), then control reaches the shared tail. [source:raw, callee:0x004144F0]
    // GUARD: State 5 player pit entry: proceeds only when player vehicle dword_7C54E8 is nonzero and equals the passed vehicle a5, then switches on sub-type a6. [source:raw, global:0x007C54E8]
    // CALL: State 5 sub-types: a6 == 1 fills event 123; a6 == 2 fires BooleanOROfTwoChecks for 123 then fills event 124; a6 == 3 fires BooleanOROfTwoChecks for 123 and 124 then fills event 125, all on session table flt_5EA618. [source:raw, callee:0x00418A20, callee:0x004144F0, global:0x005EA618]

    // Conservative worker pseudocode:
    //   if (race_active && track_condition != 0.0 && player_pit_flag_clear && race_phase != 8) {
    //       a4 = clamp(a4, 0.0, flt_5EA3FC);
    //       init_event_entry(v13);
    //       v11 = distance_projection(player_vehicle + 12);
    //       v7 = zone_index(a4);  v8 = zone_index(v11);  v9 = (v8 == v7);
    //       switch (a2) {
    //         case DEACTIVATE: if (this[v7+316] == 2 && !scoring_gate(v7)) { this[v7+316] = 0; ... emit zone event 137/133/135 or 126 } break;
    //         case ACTIVATE:   if (zone_moved_or_threshold) { ... fire prior events, fill 138/134/136 }; this[v7+316] = 2; break;
    //         case GENERIC:    fill event 131; break;
    //         case PIT_ENTRY:  if (player_vehicle == a5) { fill 123/124/125 per a6 }; break;
    //       }
    //       if (v13[0] != -1) insert_event_entry(flt_5EA618, v13);
    //   }
    // UNRESOLVED: Packet globals flt_59E440, flt_59E824, flt_59E828, dword_8ACEE0, dword_8AD264 do not appear in the decompiled source; their role in this function is not visible.
    // UNRESOLVED: Per-zone flag this[v7 + 316] and player-vehicle offsets 13388 and +12 have no packet field entries; field identities remain unnamed.
    // UNRESOLVED: Semantic role of event codes 123-125, 126, 131, 133-138 and of the BooleanOROfTwoChecks/ArraySearchReturningIndex argument shapes is inferred from call signatures, not independently confirmed.
}
