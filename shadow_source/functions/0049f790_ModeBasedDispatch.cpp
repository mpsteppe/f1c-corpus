// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049F790
// Canonical corpus name: ModeBasedDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ModeBasedDispatch_0049f790.c

void UnknownObject::ModeBasedDispatch()
{
    // UI-mode dispatcher. When the feature flag dword_7CC234 is set and the control-profile pointer equals the audio-device state whose mode field (at +52) is 1 or 2, scans the enable-mask byte_7CF7AC to select the next enabled mode index above the current one (wrapping to 0) and stores it via FunctionCallWrapper_f150; otherwise it stores the boolean (current mode != 1). Independently, when the current mode is 1, it consumes audio/input/UI flags: dword_7CC28C and dword_7CC2B8 trigger the cyclic index advance sub_49F170 with direction 1 or 0, dword_7CC2E4 triggers UtilityFunction_5750 on the secondary index this+0x4, and dword_7CC310 triggers IndexDecrementWithBoundsWrap on this+0x4.
    // ASSIGNMENT: Seed result with the feature flag dword_7CC234 before branching. [global:0x007CC234, source:raw]
    // GUARD: Only run the mode-set dispatch when dword_7CC234 is non-zero. [global:0x007CC234, source:raw]
    // GUARD: The index-scan path requires the control profile pointer dword_5EA518 to equal the audio device state dword_5EA528 and the device mode field read at dword_5EA528 + 52 to equal 1 or 2. [global:0x005EA518, global:0x005EA528, source:raw]
    // ASSIGNMENT: Start the candidate scan from the current mode index at this+0x0. [field:this:0x00000000, source:raw]
    // LOOP: Increment v2 while v2 < 5, selecting the first candidate whose enable-mask bit in byte_7CF7AC is set; fall through to wrap v2 to 0 when none qualifies. [global:0x007CF7AC, source:raw]
    // GUARD: Index 2 is selectable when byte_7CF7AC bit 1 is set, index 3 when bit 2 is set, index 4 when bit 4 is set; every other index is selectable on sight. [global:0x007CF7AC, source:raw]
    // CALL: Store the selected mode index v2 via FunctionCallWrapper_f150(this, v2). [callee:0x0049F150, source:raw]
    // CALCULATION: On the non-matching branch, compute the boolean (this+0x0 != 1) as the new mode value. [guard:0, field:this:0x00000000, source:raw]
    // CALL: Store the boolean mode (this+0x0 != 1) via FunctionCallWrapper_f150(this, *this != 1). [callee:0x0049F150, field:this:0x00000000, source:raw]
    // GUARD: Enter the mode-1 update branch when the current mode this+0x0 equals 1. [guard:1, field:this:0x00000000, source:raw]
    // GUARD: When dword_7CC28C is set, advance the cyclic index with direction 1. [global:0x007CC28C, source:raw]
    // CALL: Call sub_49F170(this, 1) to advance the cyclic index by one. [callee:0x0049F170, source:raw]
    // GUARD: Else, when dword_7CC2B8 is set, advance the cyclic index with direction 0. [global:0x007CC2B8, source:raw]
    // CALL: Call sub_49F170(this, 0) to advance the cyclic index. [callee:0x0049F170, source:raw]
    // GUARD: Else, when dword_7CC2E4 is set, run UtilityFunction_5750 on the secondary index this+0x4. [global:0x007CC2E4, field:this:0x00000004, source:raw]
    // CALL: Call UtilityFunction_5750(this[1]) processing the secondary index. [callee:0x004A5750, field:this:0x00000004, source:raw]
    // GUARD: Else, seed result with dword_7CC310 and decrement the secondary index when it is non-zero. [global:0x007CC310, field:this:0x00000004, source:raw]
    // CALL: Call IndexDecrementWithBoundsWrap(this[1]) to decrement the secondary index with wrap-around. [callee:0x004A57A0, field:this:0x00000004, source:raw]
    // RETURN: Return the stored/result value, which is the feature flag, the FunctionCallWrapper result, or the mode-1 handler return. [function:0x0049F790, source:raw]

    // Conservative worker pseudocode:
    //   result = dword_7CC234;
    //   if (dword_7CC234) {
    //     if (dword_5EA518 == dword_5EA528 && (*(dword_5EA528 + 52) == 1 || *(dword_5EA528 + 52) == 2)) {
    //       v2 = *this;
    //       while (++v2 < 5) {
    //         if (v2 == 2) { if (byte_7CF7AC & 1) goto picked; }
    //         else if (v2 == 3) { if (byte_7CF7AC & 2) goto picked; }
    //         else if (v2 != 4 || (byte_7CF7AC & 4) != 0) goto picked;
    //       }
    //       v2 = 0;
    //     picked:
    //       result = FunctionCallWrapper_f150(this, v2);
    //     } else {
    //       result = FunctionCallWrapper_f150(this, *this != 1);
    //     }
    //   }
    //   if (*this == 1) {
    //     if (dword_7CC28C) return sub_49F170(this, 1);
    //     if (dword_7CC2B8) return sub_49F170(this, 0);
    //     if (dword_7CC2E4) return UtilityFunction_5750(this[1]);
    //     result = dword_7CC310;
    //     if (dword_7CC310) return IndexDecrementWithBoundsWrap(this[1]);
    //   }
    //   return result;
    // UNRESOLVED: dword_7C54E8 (0x007C54E8) is listed as a read global but does not appear in the raw function body; its role here is unknown.
    // UNRESOLVED: Called from ShortComputation_f070 (0049f070); no frame-path evidence for this function.
    // UNRESOLVED: The exact mode set indexed by this+0x0 and the enable-mask semantics of byte_7CF7AC bits 1, 2 and 4 are inferred from the scan loop; not independently confirmed.
    // UNRESOLVED: The internal state effect of FunctionCallWrapper_f150 is not resolved here; it stores the new mode index per prior analysis.
}
