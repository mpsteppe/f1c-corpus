// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045B950
// Canonical corpus name: sub_45B950
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_45B950_0045b950.c

void UnknownObject::AudioCollisionSettingHelper()
{
    // Unconditional configuration helper: calls UtilityFunction_cfb0 with the global pointer off_5C5B50 and parameters (0x80000000, 0, 0.5, 0.0, 1.0, 1.0, flt_7CD200, 2, 0), then calls TwoFieldSetters with the identical value 1060320051 twice, and returns the UtilityFunction_cfb0 result.
    // CALL: Call UtilityFunction_cfb0(off_5C5B50, 0x80000000, 0, 0.5, 0.0, 1.0, 1.0, flt_7CD200, 2, 0) and store its return value in v0. [callee:0x004DCFB0, global:0x005C5B50, global:0x007CD200, function:0x0045B950, source:raw]
    // CALL: Call TwoFieldSetters(1060320051, 1060320051) to set two fields to the same value. [callee:0x004DD010, source:raw]
    // RETURN: Return v0, the UtilityFunction_cfb0 result. [function:0x0045B950, source:raw]

    // Conservative worker pseudocode:
    //   int sub_45B950() {
    //     int v0 = UtilityFunction_cfb0(off_5C5B50, 0x80000000, 0, 0.5, 0.0, 1.0, 1.0, flt_7CD200, 2, 0);
    //     TwoFieldSetters(1060320051, 1060320051);
    //     return v0;
    //   }
    // UNRESOLVED: Semantics of UtilityFunction_cfb0's parameter set (constant 0x80000000 and float literals) are unknown.
    // UNRESOLVED: Meaning of the shared value 1060320051 passed to TwoFieldSetters is unknown.
}
