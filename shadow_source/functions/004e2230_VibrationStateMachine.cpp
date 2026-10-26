// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E2230
// Canonical corpus name: VibrationStateMachine
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VibrationStateMachine_004e2230.c

void UnknownObject::VibrationStateMachine()
{
    // Vibration/force-feedback state machine driven by |a3|: magnitude below 16.0 selects the OFF state (0), 16.0..64.0 the LOW state (1), and 64.0+ the HIGH state (2). On a state change the new state is stored at this[74*a2+123], sub_5506A0(state, 0, 0) updates the primary slot, and the sound effect slot array (dword_8AD3EC .. unk_8AD3F8) is iterated applying sub_5506A0(this[731], slot, 0) to each non-zero entry. Returns the current state. Called from VehiclePhysicsTimeStep, SubslotCleanup and sub_4F0430.
    // CALCULATION: Compute the vibration magnitude v3 = fabs(a3). [source:raw]
    // GUARD: If v3 < 16.0, select the OFF state (0). [source:raw]
    // GUARD: Else if v3 < 64.0, select the LOW state (1). [source:raw]
    // GUARD: Else (v3 >= 64.0), select the HIGH state (2). [source:raw]
    // STATE_TRANSITION: If the stored state at this[74*a2+123] differs from the selected state, store the new state, call sub_5506A0(new_state, 0, 0), then iterate the sound effect slot array applying sub_5506A0 to each non-zero entry. [callee:0x005506A0, field:this:0x00000B6C, global:0x008AD3EC, global:0x008AD3F8, source:raw]
    // LOOP: Iterate the sound effect slot array from dword_8AD3EC (0x008AD3EC) up to unk_8AD3F8 (0x008AD3F8); for each non-zero slot value call sub_5506A0(this[731], slot_value, 0), where this[731] is the vibration intensity. [global:0x008AD3EC, global:0x008AD3F8, callee:0x005506A0, field:this:0x00000B6C, source:raw]
    // RETURN: Return the current vibration state (0, 1, or 2). [function:0x004E2230, source:raw]

    // Conservative worker pseudocode:
    //   int VibrationStateMachine(int* this, int a2, float a3) {
    //     long double v3 = fabs(a3);
    //     int state;
    //     if (v3 < 16.0) state = 0;
    //     else if (v3 < 64.0) state = 1;
    //     else state = 2;
    //     if (this[74*a2 + 123] != state) {
    //       this[74*a2 + 123] = state;
    //       sub_5506A0(state, 0, 0);
    //       for (int* p = &dword_8AD3EC; (int)p < (int)&unk_8AD3F8; ++p)
    //         if (*p) sub_5506A0(this[731], *p, 0);
    //     }
    //     return state;
    //   }
    // UNRESOLVED: The threshold literals 16.0 and 64.0 correspond to the globals flt_59E708 (0x0059E708) and flt_59EED0 (0x0059EED0), but the exact pairing is not proven.
    // UNRESOLVED: The state slot this[74*a2+123] is an indexed array slot rather than a named packet field; its stride (74 entries) and meaning are unverified.
    // UNRESOLVED: unk_8AD3F8 (0x008AD3F8) serves as the end bound of the sound effect slot iteration; its exact type is unknown.
    // UNRESOLVED: The semantics of sub_5506A0 (0x005506A0) as a hardware/audio vibration slot update are DERIVED from existing analysis, not proven here.
}
