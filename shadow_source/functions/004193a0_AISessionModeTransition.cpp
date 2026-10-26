// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004193A0
// Canonical corpus name: AISessionModeTransition
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AISessionModeTransition_004193a0.c

void UnknownObject::AISessionModeTransition()
{
    // Processes a session mode transition for the AI commentary/event system. After guarding on race-active, track-condition and player-vehicle identity, resolves a three-way mode index (from the explicit argument or via float lookup), and when the scoring gate is open and the mode is not already marked transitioned, builds an 8-dword event entry (sentinel-initialized, filled with mode-specific event ids) and inserts it into the session event table, marking this[v5+316] = 2.
    // GUARD: Proceed only when the race is active (dword_7D0308 nonzero), the track condition float flt_7CF3C8 is nonzero, and the vehicle at a2 matches the player vehicle (dword_7C54E8) by the identity field at offset 18580. [global:0x007D0308, global:0x007CF3C8, global:0x007C54E8, source:raw]
    // ASSIGNMENT: Seed the raw mode selector v4 with the argument a3; when a3 is -1, resolve it through FloatRangeIndexLookup on the float at a2+16456. [callee:0x004D7C10, source:raw]
    // CALL: FloatRangeIndexLookup maps the vehicle float at offset 16456 to a mode index when no explicit mode was supplied. [callee:0x004D7C10, source:raw]
    // CALCULATION: Convert the raw selector v4 to the three-way session mode v5 via ThreeWayEnumConverter. [callee:0x004D7CC0, source:raw]
    // CALL: ThreeWayEnumConverter normalizes the mode value to the 0/1/2 range used by the rest of the function. [callee:0x004D7CC0, source:raw]
    // GUARD: Insert an entry only when ScoringGateSelector(v5) returns 2 and the per-mode marker this[v5+316] is not already 2. [callee:0x004D1AD0, source:raw]
    // CALL: ScoringGateSelector(v5) determines which scoring gate the current mode maps to. [callee:0x004D1AD0, source:raw]
    // CALL: Initialize the local 8-dword event entry v6 with sentinel values via StructInitWithSentinelValues. [callee:0x004144D0, source:raw]
    // GUARD: Dispatch on the mode v5: mode 0, mode 1 and mode 2 each use distinct event id pairs (138/137, 134/133, 136/135 respectively). [source:raw]
    // CALL: For mode 0, fire BooleanOROfTwoChecks(flt_5EA618, 137) and fill v6 via DriverDataTableLookupAndTimeConversion with id 138 and sentinel -1/-1 ids and -2.0 times. [callee:0x00418A20, callee:0x004144F0, global:0x005EA618, source:raw]
    // GUARD: For mode 1, the table entry is created only when the race phase dword_7C56A8 is not 8. [global:0x007C56A8, source:raw]
    // CALL: For mode 1, fire BooleanOROfTwoChecks(flt_5EA618, 133) and fill v6 via DriverDataTableLookupAndTimeConversion with id 134 and sentinel values. [callee:0x00418A20, callee:0x004144F0, global:0x005EA618, source:raw]
    // CALL: For mode 2, fire BooleanOROfTwoChecks(flt_5EA618, 135) and fill v6 via DriverDataTableLookupAndTimeConversion with id 136 and sentinel values. [callee:0x00418A20, callee:0x004144F0, global:0x005EA618, source:raw]
    // CALL: Insert the completed entry into the session event table via InsertDriverTableEntry(flt_5EA618, v6). [callee:0x00418560, global:0x005EA618, source:raw]
    // STATE_TRANSITION: Mark the mode as transitioned: this[v5+316] = 2. [source:raw]
    // CALL: Called by sub_4BCCC0 as part of the AI session event pipeline. [caller:0x004BCCC0, source:raw]

    // Conservative worker pseudocode:
    //   void AISessionModeTransition(vehicle* a2, int a3) {
    //     if (dword_7D0308 && flt_7CF3C8 != 0.0 && player_veh_id == a2->id18580) {
    //       v4 = a3;
    //       if (a3 == -1) v4 = FloatRangeIndexLookup(a2->flt16456);
    //       v5 = ThreeWayEnumConverter(v4);
    //       if (ScoringGateSelector(v5) == 2 && this[v5+316] != 2) {
    //         StructInitWithSentinelValues(v6);
    //         if (v5 == 0)      { BooleanOROfTwoChecks(flt_5EA618, 137); DriverDataTableLookupAndTimeConversion(v6, 138, -1, -1, -1, -1, -2.0, -2.0); }
    //         else if (v5 == 1) { if (dword_7C56A8 != 8) { BooleanOROfTwoChecks(flt_5EA618, 133); DriverDataTableLookupAndTimeConversion(v6, 134, -1, -1, -1, -1, -2.0, -2.0); } }
    //         else if (v5 == 2) { BooleanOROfTwoChecks(flt_5EA618, 135); DriverDataTableLookupAndTimeConversion(v6, 136, -1, -1, -1, -1, -2.0, -2.0); }
    //         InsertDriverTableEntry(flt_5EA618, v6);
    //         this[v5+316] = 2;
    //       }
    //     }
    //   }
    // UNRESOLVED: The float a2 argument is in fact a vehicle pointer; the vehicle type layout at offsets 16456 and 18580 is not established from this function alone.
    // UNRESOLVED: The per-mode marker array this[v5+316] and the owning session handler class are unknown.
    // UNRESOLVED: flt_59E440, dword_8ACEE0 and dword_8AD264 appear in the packet globals but are absent from the raw decompiled text; their role here is unresolved.
}
