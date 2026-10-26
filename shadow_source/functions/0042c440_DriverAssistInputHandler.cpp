// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042C440
// Canonical corpus name: sub_42C440
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_42C440_0042c440.c

void UnknownObject::DriverAssistInputHandler()
{
    // Per-frame driver-assist input processor on the main game-tick path. When the session guard at dword_7C54E8 + 13000 and the flag byte_7CE254 are both clear, it walks the action-code word array (dword_7CB218 entries starting at word_7CB21C) and dispatches each code through a switch to AIShiftPattern calls that shift steering/traction/braking/assist config patterns. Afterwards it conditionally dispatches session transition, visual state change, brake-bias, assist-toggle and vehicle-vibration behaviors driven by one-shot command flags.
    // GUARD: Guard: proceed only while the dword at offset 13000 of the dword_7C54E8 object is zero. [global:0x007C54E8, source:raw]
    // GUARD: Guard: proceed only while byte_7CE254 is zero. [global:0x007CE254, source:raw]
    // LOOP: Walk the 16-bit action-code array from word_7CB21C for dword_7CB218 entries, dispatching each code via a switch bounded by byte_42C664 and jumped through jpt_42C48C. [global:0x007CB21C, global:0x007CB218, global:0x0042C664, global:0x0042C634, source:raw]
    // CALL: Case ';' (SteeringAssist): call AIShiftPattern with pattern 7 on dword_7CE6AC, stride 2, config key aSteeringAssist. [callee:0x0042B8D0, global:0x007CE6AC, global:0x005C3480, source:raw]
    // CALL: Case '<' (OppositeLockAssist): call AIShiftPattern with pattern 6 on dword_7CE7CC, stride 1, config key aOppositeLockAs. [callee:0x0042B8D0, global:0x007CE7CC, global:0x005C3464, source:raw]
    // CALL: Case '=' (BrakingPointAssist): call AIShiftPattern with pattern 8 on dword_7CE718, stride 2, config key aBrakingPointAs. [callee:0x0042B8D0, global:0x007CE718, global:0x005C3448, source:raw]
    // CALL: Case '>' (StabilityAssist): call AIShiftPattern with pattern 2 on dword_7CE7F0, stride 2, config key aStabilityAssis. [callee:0x0042B8D0, global:0x007CE7F0, global:0x005C3430, source:raw]
    // CALL: Case '?' (SpinRecovery): call AIShiftPattern with pattern 9 on dword_7CE760, stride 2, config key aSpinRecovery. [callee:0x0042B8D0, global:0x007CE760, global:0x005C3420, source:raw]
    // CALL: Case '@' (Invulnerability): call AIShiftPattern with pattern 5 on dword_7CE784, stride 1, config key aInvulnerabilit. [callee:0x0042B8D0, global:0x007CE784, global:0x005C340C, source:raw]
    // CALL: Case 'A' (AutoShifting): call AIShiftPattern with pattern 3 on dword_7CE8A4, stride 3, config key aAutoShifting. [callee:0x0042B8D0, global:0x007CE8A4, global:0x005C33FC, source:raw]
    // CALL: Case 'B' (TractionControl): call AIShiftPattern with pattern 0 on dword_7CE6F4, stride 2, config key aTractionContro. [callee:0x0042B8D0, global:0x007CE6F4, global:0x005C33E8, source:raw]
    // CALL: Case 'C' (AntiLockBrakes): call AIShiftPattern with pattern 1 on dword_7CE73C, stride 2, config key aAntiLockBrakes. [callee:0x0042B8D0, global:0x007CE73C, global:0x005C33D4, source:raw]
    // CALL: Case 'D' (PitLaneAssist): call AIShiftPattern with pattern 10 on dword_7CE7A8, stride 1, config key aPitLaneAssista. [callee:0x0042B8D0, global:0x007CE7A8, global:0x005C33BC, source:raw]
    // CALL: Case 'W' (ClutchAssist): call AIShiftPattern with pattern 4 on dword_7CE850, stride 1, config key aClutchAssistan. [callee:0x0042B8D0, global:0x007CE850, global:0x005C33A8, source:raw]
    // GUARD: Guard: when dword_7CC260 is nonzero, dispatch a session transition for the dword_7C54E8 object. [global:0x007CC260, global:0x007C54E8, source:raw]
    // CALL: Call SessionTransitionDispatch on dword_7C54E8 + 13004. [callee:0x004A5E10, global:0x007C54E8, source:raw]
    // GUARD: Guard: when dword_7CC394 and byte_7C9081 are both nonzero and byte_7C74A4 is zero, trigger a visual state change. [global:0x007CC394, global:0x007C9081, global:0x007C74A4, source:raw]
    // CALL: Call VisualStateChange with the boolean (byte_7C9080 == 0) and constant 0. [callee:0x00447C70, global:0x007C9080, source:raw]
    // GUARD: Guard: when dword_7CC3C0 is nonzero, adjust brake bias in the negative direction. [global:0x007CC3C0, source:raw]
    // CALL: Call BrakeBiasAdjustmentControl with constant -1. [callee:0x00447D00, source:raw]
    // GUARD: Guard: when dword_7CC3EC is nonzero, adjust brake bias in the positive direction. [global:0x007CC3EC, source:raw]
    // CALL: Call BrakeBiasAdjustmentControl with constant 1. [callee:0x00447D00, source:raw]
    // STATE_TRANSITION: When dword_7CC6D8 is nonzero, toggle byte_7C9081 (assist enabled flag) to its inverse. [global:0x007CC6D8, global:0x007C9081, source:raw]
    // GUARD: Guard: when dword_7CC704 is nonzero, check whether the vehicle described by dbl_7C7428 is active. [global:0x007CC704, global:0x007C7428, source:raw]
    // CALL: Call VehicleActive on the vehicle object dbl_7C7428. [callee:0x00447160, global:0x007C7428, source:raw]
    // CALL: When the active-vehicle check succeeds, call SuspensionVibration with constant 0. [callee:0x004471F0, source:raw]
    // RETURN: Return the last result value held by the caller-visible accumulator. [source:raw]

    // Conservative worker pseudocode:
    //   char DriverAssistInputHandler() {
    //     char result = dword_7C54E8;
    //     if (!*(_DWORD*)(dword_7C54E8 + 13000) && !byte_7CE254) {
    //       for (int i = 0; i < dword_7CB218; ++i) {
    //         switch (word_7CB21C[i]) {
    //           case ';': AIShiftPattern(7, &dword_7CE6AC, 2, aSteeringAssist); break;
    //           case '<': AIShiftPattern(6, &dword_7CE7CC, 1, aOppositeLockAs); break;
    //           case '=': AIShiftPattern(8, &dword_7CE718, 2, aBrakingPointAs); break;
    //           case '>': AIShiftPattern(2, &dword_7CE7F0, 2, aStabilityAssis); break;
    //           case '?': AIShiftPattern(9, &dword_7CE760, 2, aSpinRecovery); break;
    //           case '@': AIShiftPattern(5, &dword_7CE784, 1, aInvulnerabilit); break;
    //           case 'A': AIShiftPattern(3, &dword_7CE8A4, 3, aAutoShifting); break;
    //           case 'B': AIShiftPattern(0, &dword_7CE6F4, 2, aTractionContro); break;
    //           case 'C': AIShiftPattern(1, &dword_7CE73C, 2, aAntiLockBrakes); break;
    //           case 'D': AIShiftPattern(10, &dword_7CE7A8, 1, aPitLaneAssista); break;
    //           case 'W': AIShiftPattern(4, &dword_7CE850, 1, aClutchAssistan); break;
    //         }
    //       }
    //       if (dword_7CC260) SessionTransitionDispatch(dword_7C54E8 + 13004);
    //       if (dword_7CC394 && byte_7C9081 && !byte_7C74A4) VisualStateChange(byte_7C9080 == 0, 0);
    //       if (dword_7CC3C0) BrakeBiasAdjustmentControl(-1);
    //       if (dword_7CC3EC) BrakeBiasAdjustmentControl(1);
    //       if (dword_7CC6D8) byte_7C9081 = byte_7C9081 == 0;
    //       if (dword_7CC704 && VehicleActive(&dbl_7C7428)) return SuspensionVibration(0);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantics of AIShiftPattern pattern ids and of the target dword_7CExxx config-pattern buffers are defined by the callee and unknown here.
    // UNRESOLVED: Meaning of the session structure fields at dword_7C54E8 + 13000 and + 13004 is unknown.
    // UNRESOLVED: Purpose of the flag bytes byte_7C9080, byte_7C9081 and byte_7C74A4 beyond the visible toggling/visual-state role is unknown.
    // UNRESOLVED: Meaning of dbl_7C7428 as a vehicle object reference for VehicleActive is presumed from the call shape, not confirmed.
    // UNRESOLVED: The set of one-shot command flag globals (dword_7CC260, dword_7CC394, dword_7CC3C0, dword_7CC3EC, dword_7CC6D8, dword_7CC704) is assumed to be set elsewhere in the input system.
}
