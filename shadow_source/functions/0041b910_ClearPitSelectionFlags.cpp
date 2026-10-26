// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041B910
// Canonical corpus name: ClearPitSelectionFlags
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ClearPitSelectionFlags_0041b910.c

void UnknownObject::ClearPitSelectionFlags()
{
    // Conditionally invokes BooleanOROfTwoChecks three times with flag indices 123, 124 and 125 on the shared pointer-table entry flt_5EA618. The body runs only when the race is active (dword_7D0308 != 0), track-condition state exists (flt_7CF3C8 != 0.0), the race phase dword_7C56A8 is not 8, and the action identifier a1 equals 5. Parameter a2 is unused. Canonical name interprets these OR-flag writes as clearing pit-selection flags; the exact flag semantics are not resolvable in this function alone.
    // GUARD: Compound guard: proceed only when dword_7D0308 (race active) is non-zero, flt_7CF3C8 (track-condition state) is non-zero, dword_7C56A8 (race phase) is not 8, and the action identifier a1 equals 5; otherwise return without modifying anything. [global:0x007D0308, global:0x007CF3C8, global:0x007C56A8, function:0x0041B910, source:raw]
    // CALL: BooleanOROfTwoChecks(flt_5EA618, 123): set/clear flag index 123 on the pointer-table entry. [callee:0x00418A20, global:0x005EA618, source:raw]
    // CALL: BooleanOROfTwoChecks(flt_5EA618, 124): set/clear flag index 124 on the pointer-table entry. [callee:0x00418A20, global:0x005EA618, source:raw]
    // CALL: BooleanOROfTwoChecks(flt_5EA618, 125): set/clear flag index 125 on the pointer-table entry. [callee:0x00418A20, global:0x005EA618, source:raw]
    // CALL: Invoked once per frame by sub_4BCCC0 (004BCCC0), the AI pit logic path, matching the canonical pit-selection role. [caller:0x004BCCC0, source:raw]

    // Conservative worker pseudocode:
    //   void ClearPitSelectionFlags(int actionId, int unused) {
    //     if (dword_7D0308 != 0 && flt_7CF3C8 != 0.0f && dword_7C56A8 != 8 && actionId == 5) {
    //       BooleanOROfTwoChecks(flt_5EA618, 123);
    //       BooleanOROfTwoChecks(flt_5EA618, 124);
    //       BooleanOROfTwoChecks(flt_5EA618, 125);
    //     }
    //   }
    // UNRESOLVED: flt_59E440 is listed in packet facts but appears nowhere in the raw source; its role here is not verifiable
    // UNRESOLVED: The callee name BooleanOROfTwoChecks implies OR semantics while the canonical name implies clearing; the two cannot be reconciled without reading the callee
    // UNRESOLVED: Parameter a2 is accepted but never referenced
}
