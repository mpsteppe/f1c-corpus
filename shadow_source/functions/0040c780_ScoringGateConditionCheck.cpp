// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040C780
// Canonical corpus name: ScoringGateConditionCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScoringGateConditionCheck_0040c780.c

void UnknownObject::ScoringGateConditionCheck()
{
    // No-argument function returning a double. When the gate dword_8AB6E4 equals 2 it returns the absolute value of FloatDifference(&dword_8AB6EC); otherwise it returns the default double dbl_8AFE98. Existing analysis (skeletons_filled) labels the gate 'ScoringGate' and notes callers (CameraModeViewportUpdate, CameraShake, CameraTransformComputation, RandomStateMachineWithTimerAndTrigger) use the result as a timer decrement, but that labeling is prose, not packet evidence.
    // GUARD: Gate: when dword_8AB6E4 equals 2 the absolute-difference branch is taken; otherwise the default double dbl_8AFE98 is returned [global:0x008AB6E4, source:raw]
    // CALL: Calls FloatDifference(&dword_8AB6EC) to compute a signed float difference of the data at dword_8AB6EC [callee:0x004B9CF0, global:0x008AB6EC, source:raw]
    // CALCULATION: Applies the absolute-value operation (fabs in the raw source) to the FloatDifference result [source:raw]
    // RETURN: Returns fabs(FloatDifference(&dword_8AB6EC)) on the gate==2 path [global:0x008AB6EC, source:raw]
    // RETURN: Returns the default double dbl_8AFE98 on the gate!=2 path [global:0x008AFE98, source:raw]

    // Conservative worker pseudocode:
    //   double ScoringGateConditionCheck() {
    //     if (dword_8AB6E4 == 2)
    //       return fabs(FloatDifference(&dword_8AB6EC));
    //     return dbl_8AFE98;
    //   }
    // UNRESOLVED: The identity and meaning of the data at dword_8AB6EC (labeled 'ScoringDataPtr' only in existing-analysis prose) and why a gate value of exactly 2 selects it
    // UNRESOLVED: The purpose of the default double dbl_8AFE98 (labeled 'ScoringDefaultReturn' only in existing-analysis prose)
    // UNRESOLVED: fabs has no callee evidence ref; whether it is an inline intrinsic or a resolved call is not evidenced by this packet
    // UNRESOLVED: The raw source declares a double return while the caller analysis describes a per-tick timer decrement; the exact consumer semantics are not evidenced here
}
