// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041C0F0
// Canonical corpus name: PitExit
// Owner: PitExitMessageDispatcher [DERIVED]
// Raw source: functions/PitExit_0041c0f0.c

void PitExitMessageDispatcher::PitExit()
{
    // Dispatches a pit-exit commentary message for the car whose driver number (a2+1) is leaving the pit lane. Guards on race-active (dword_7D0308) and track condition (flt_7CF3C8), then locates the car slot in the vehicle array (dword_5F0738, stride 4656) by its first dword. Selects an audio message id (default 397, range 516-535) from the slot's relationship classification (this[v4] in 1..3), the car's relative race position against the player's position (dword_7C54E8+16480), position-fraction thresholds (v11/dword_5C329C), parity, and championship mode (dword_7D0410). A random remap may replace some ids via a jump table (jpt_41C243). The chosen entry is emitted through DriverDataTableLookupAndTimeConversion and InsertDriverTableEntry.
    // GUARD: If race-active flag dword_7D0308 is zero, return without dispatching any commentary. [global:0x007D0308, source:raw]
    // GUARD: If track condition state flt_7CF3C8 equals 0.0, return without dispatching any commentary. [global:0x007CF3C8, source:raw]
    // ASSIGNMENT: Initialize locals: driver number v3 = a2 + 1 (also stored to v11), slot counter v4 = 0. [source:raw]
    // GUARD: If vehicle count dword_5C329C is zero, skip the slot lookup and message dispatch. [global:0x005C329C, source:raw]
    // LOOP: Iterate the vehicle array from base dword_5F0738 with element stride 4656, comparing each slot's first dword to v3 (the driver number), advancing v4 per step. [global:0x005F0738, source:raw]
    // GUARD: If the slot counter v4 reaches vehicle count dword_5C329C without a driver-number match, return without dispatching. [global:0x005C329C, source:raw]
    // ASSIGNMENT: Set default message id v6 = 397 and driver index v13 = a2 + 1, then initialize the local entry struct v12. [callee:0x004144D0, source:raw]
    // CALL: StructInitWithSentinelValues(v12) fills the driver-table entry struct with sentinel/default values. [callee:0x004144D0, source:raw]
    // GUARD: If championship mode dword_7D0410 equals 2, skip all relationship-specific message selection and keep the default id 397. [global:0x007D0410, source:raw]
    // GUARD: Branch on the matched slot's relationship classification this[v4]: value 1 (player-lead group), value 2 (rival group), value 3 with mode 4 (constructor-rival group). [source:raw]
    // CALCULATION: For classification 1: id 516 when v3 == 1; otherwise compute position fraction v10 = v11 / dword_5C329C and select id 517, 518, or 519 from thresholds v10>=0.5, v10<=2.0, v3>10, and the condition dword_5C329C*2/3 > v11 with dword_5C329C > 11. [global:0x005C329C, source:raw]
    // CALCULATION: For classification 2: read player's race position v9 = *(dword_7C54E8 + 16480); select id 521/523/524 from the sign of (v3 - v9), odd/even parity (v3 % 2), and distance > 3, using the expression (distance > 3) + 524 or (distance > 3) + 521. [global:0x007C54E8, source:raw]
    // CALCULATION: For classification 3 with dword_7D0410 == 4: read player's race position v8 = *(dword_7C54E8 + 16480); select id 528/531/534/535 from relative position and parity, base expression (v3 >= v8 + 3) + 528 or (v3 + 3 <= v8) + 534. [global:0x007C54E8, global:0x007D0410, source:raw]
    // STATE_TRANSITION: If RandLCGRandomNumberGenerator(v7) returns odd, remap the selected id through the jump table jpt_41C243: 528->526, 529->527, 531->530, 534->532, 535->533; default case sets v13 = v3. [callee:0x005884ED, global:0x0041C3BC, source:raw]
    // CALL: DriverDataTableLookupAndTimeConversion(v12, v6, dword_5F0F74[4656 * v4], v13, -1, -1, -2.0, -2.0) fills the entry with the selected message id, the slot's driver identifier, and the driver/time index; -1 and -2.0 are fixed default arguments. [callee:0x004144F0, global:0x005F0F74, source:raw]
    // CALL: InsertDriverTableEntry(flt_5EA618, v12) appends the completed entry to the driver-table at flt_5EA618. [callee:0x00418560, global:0x005EA618, source:raw]
    // RETURN: Return after insertion; the function is void and always returns via the guarded exits. [function:0x0041C0F0, source:raw]

    // Conservative worker pseudocode:
    //   if (!race_active || track_condition == 0.0) return;
    //   driver_number = a2 + 1;
    //   slot = find_slot(vehicle_array, driver_number);   // stride 4656, by slot->id
    //   if (!slot_found) return;
    //   entry = {}; StructInitWithSentinelValues(&entry);
    //   msg = 397;
    //   if (mode != 2) {
    //       switch (slot->relationship) {
    //           case 1: msg = pick_lead_msg(driver_number, vehicle_count); break;
    //           case 2: msg = pick_rival_msg(driver_number, player_position); break;
    //           case 3: if (mode == 4) msg = pick_constructor_msg(driver_number, player_position); break;
    //       }
    //   }
    //   if (rand(seed) % 2 == 1) msg = remap_random_variant(msg);
    //   DriverDataTableLookupAndTimeConversion(&entry, msg, slot_driver_id, driver_index, -1, -1, -2.0, -2.0);
    //   InsertDriverTableEntry(driver_table, &entry);
    // UNRESOLVED: Globals flt_59E440, flt_59E450, flt_59E800, and dbl_59E838 are listed as read in the packet but never appear in the decompiled body; their access is unobserved here (prose names them ZeroThreshold/DegreesToRadians/AmplitudeLimit/PositionThreshold, physics-related).
    // UNRESOLVED: The exact audio-message meaning of ids 397 and 516-535 is not verified against a message/emitter table.
    // UNRESOLVED: this[v4] classification values 1/2/3 are interpreted as player/rival/constructor-rival from analysis prose; the relationship semantics are not independently confirmed.
    // UNRESOLVED: Offset +16480 (player race position) and +18588 on dword_7C54E8 are used numerically without named-field confirmation.
}
