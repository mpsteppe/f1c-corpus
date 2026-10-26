// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C29F0
// Canonical corpus name: sub_4C29F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C29F0_004c29f0.c

void UnknownObject::UpdateRaceStateScoring()
{
    // Race-session scoring update. Runs only when ScoringGateCheck() passes, dword_8AB6E4 is not 2, and dword_7C56A4 equals 7. Reads a state word from the player vehicle pointer dword_7C54E8 at +16472, updates short-term scoring data via ShortComputation_2bf0, applies a running-average filter, conditionally feeds the AI difficulty value into ArithmeticComparison_2dc0 when dword_7D0990 > 0, and processes the race-setup scaling factor through sub_4C2D30. When championship mode dword_7D0410 is 4 or 3 and the vehicle state word equals 1, increments the session counter at this[15] (offset +0x3C). Returns dword_7D0410.
    // CALL: ScoringGateCheck() decides whether scoring processing is allowed this invocation. [callee:0x0042BC10]
    // GUARD: Proceed only when ScoringGateCheck() is non-zero, dword_8AB6E4 != 2, and dword_7C56A4 == 7 (race session type). [source:raw, global:0x008AB6E4, global:0x007C56A4]
    // CALCULATION: Read a state word into v3 from the player-vehicle pointer dword_7C54E8 at offset +16472. [source:raw, global:0x007C54E8]
    // CALL: ShortComputation_2bf0(this) updates short-term scoring state on this. [callee:0x004C2BF0]
    // CALL: RunningAverageFilter(v3) applies the running-average filter to the player vehicle state word. [callee:0x004C2C40]
    // GUARD: When dword_7D0990 > 0, cast dword_7D01A0 (AI difficulty) to float and pass it to ArithmeticComparison_2dc0. [global:0x007D0990, global:0x007D01A0, callee:0x004C2DC0]
    // CALL: sub_4C2D30(flt_7D0798) processes the race-setup scaling factor. [callee:0x004C2D30, global:0x007D0798]
    // GUARD: When dword_7D0410 (championship mode) is 4 or 3 and v3 == 1, increment the session counter this[15] at +0x3C. [source:raw, global:0x007D0410, field:this:0x0000003C]
    // RETURN: Return dword_7D0410, or the ScoringGateCheck result when the outer guard fails. [source:raw, global:0x007D0410]

    // Conservative worker pseudocode:
    //   int sub_4C29F0(int *this) {
    //     int gate = ScoringGateCheck();
    //     if (gate && dword_8AB6E4 != 2 && dword_7C56A4 == 7) {
    //       int state = *(int *)(dword_7C54E8 + 16472);
    //       ShortComputation_2bf0(this);
    //       RunningAverageFilter(state);
    //       if (dword_7D0990 > 0) ArithmeticComparison_2dc0((float)dword_7D01A0);
    //       sub_4C2D30(flt_7D0798);
    //       if ((dword_7D0410 == 4 || dword_7D0410 == 3) && state == 1)
    //         ++this[15];
    //       return dword_7D0410;
    //     }
    //     return gate;
    //   }
    // UNRESOLVED: unk_5EC6D0 is listed as a referenced global but does not appear in the visible raw source; its role here is unknown.
    // UNRESOLVED: The exact meaning of the +16472 state word and the 4/3 championship-mode enumeration are not proven by this packet.
}
