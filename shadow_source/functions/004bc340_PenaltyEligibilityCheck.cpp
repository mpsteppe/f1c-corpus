// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BC340
// Canonical corpus name: sub_4BC340
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4BC340_004bc340.c

void UnknownObject::PenaltyEligibilityCheck()
{
    // Penalty-eligibility guard. Returns true only when the session is a server (dword_7C569C == 5, server mode), the penalty state at this[12] (offset 0x30) permits penalty processing, and the race phase (dword_7C56A8) is one of 5, 6 or 8. The penalty-state clause passes when this[12] is neither 1 nor 3, or when penalties are enabled (dword_7CEF84) with this[12] != 3 and SessionType (dword_7C56A4) == 5. Used as a conditional guard for penalty logic by LapSplitTimeEvent, sub_4BCCC0 and AIRacingLinePathFollowing.
    // GUARD: Require server session mode: dword_7C569C must equal 5. [source:raw, global:0x007C569C]
    // GUARD: Penalty-state check on this[12] (offset 0x30): passes when the value is not 1 and not 3, or when penalties are enabled (dword_7CEF84 nonzero) AND the value is not 3 AND SessionType dword_7C56A4 equals 5. [source:raw, field:this:0x00000030, global:0x007CEF84, global:0x007C56A4]
    // GUARD: Require the race phase dword_7C56A8 to be one of 5, 6 or 8. [source:raw, global:0x007C56A8]
    // RETURN: Return the conjunction of the three guards; false when any clause fails. [source:raw]

    // Conservative worker pseudocode:
    //   bool PenaltyEligibilityCheck(int this) {
    //     bool ok = dword_7C569C == 5
    //       && (((*(int*)(this + 0x30) != 1) && (*(int*)(this + 0x30) != 3))
    //           || (dword_7CEF84 && (*(int*)(this + 0x30) != 3) && dword_7C56A4 == 5))
    //       && (dword_7C56A8 == 5 || dword_7C56A8 == 6 || dword_7C56A8 == 8);
    //     return ok;
    //   }
    // UNRESOLVED: The exact meaning of the this[12] (offset 0x30) penalty-state enum values (1, 3) is not stated in the packet; the existing analysis labels it penalty disqualification state (DERIVED).
    // UNRESOLVED: The owning object of this[0x30] and the writer of the session/phase globals are external to this function.
}
