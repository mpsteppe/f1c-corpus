// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005894A0
// Canonical corpus name: FloatFunctionPassThrough
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatFunctionPassThrough_005894a0.c

void UnknownObject::FloatFunctionPassThrough()
{
    // Float pass-through shim used by quaternion and rotation math. Receives a double value, runs FloatExponentExtractWithNaNGuard on it (NaN/exponent guard), then forwards the float state to sub_5894BD and returns that result. The rendered source shows the two locals v2/v3 being passed uninitialized, which is treated as a decompiler artifact of the pass-through rather than real data flow.
    // CALL: Call FloatExponentExtractWithNaNGuard(a1, HIDWORD(a1)) to run the NaN/exponent guard on the incoming double before forwarding. [callee:0x0058DD28, source:raw]
    // CALL: Forward the float state to sub_5894BD(v2, v3). [callee:0x005894BD, source:raw]
    // RETURN: Return the result of sub_5894BD(v2, v3). [callee:0x005894BD, source:raw]
    // CALL: Used as a float-component pass-through by quaternion and rotation math: QuaternionNormalizeAndDecompose (0x0050DAB2), RotationVectorToQuaternion (0x0050E055), QuaternionSphericalInterpolation (0x0053B5B0), CrossProductNormalize (0x0056C540), plus sub_426100, sub_4FAF60, sub_567580. [caller:0x0050DAB2, caller:0x0050E055, caller:0x0053B5B0, caller:0x0056C540, caller:0x00426100, caller:0x004FAF60, caller:0x00567580]

    // Conservative worker pseudocode:
    //   int FloatFunctionPassThrough(double a1) {
    //     FloatExponentExtractWithNaNGuard(a1);
    //     return sub_5894BD(a1);
    //   }
    // UNRESOLVED: v2 and v3 are read before any write in the rendered source; the true argument flow is hidden by the decompiler, likely a register-based (st0) pass-through.
    // UNRESOLVED: The result of FloatExponentExtractWithNaNGuard is discarded; whether it mutates the value forwarded to sub_5894BD is not visible in the source.
    // UNRESOLVED: The owning class is unknown; packet marks owner as UnknownObject/UNKNOWN.
}
