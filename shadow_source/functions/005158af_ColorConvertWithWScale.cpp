// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005158AF
// Canonical corpus name: DelegationWithErrorCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DelegationWithErrorCheck_005158af.c

void UnknownObject::ColorConvertWithWScale()
{
    // Two-stage conversion delegator (__cdecl): runs MatrixScaleByW(a2, v3) to produce a scratch float array v3 (64 floats), and if that returns non-negative runs QuantizationColorSpaceConversion(a1, v3) on the caller's DWORD array a1. Returns 0 when both stages succeed, otherwise propagates the first negative error code from either stage.
    // CALL: Invoke MatrixScaleByW(a2, v3) writing the scale result into the 64-float scratch buffer v3 and store its return value as result. [callee:0x00513E2D, source:raw]
    // GUARD: Guard on result >= 0; a negative return from MatrixScaleByW aborts before the conversion stage. [source:raw]
    // CALL: Invoke QuantizationColorSpaceConversion(a1, v3) with the caller array a1 and the scaled scratch buffer, storing its return value as result. [callee:0x00515303, source:raw]
    // GUARD: Guard on result >= 0 after the conversion stage; a negative return is propagated to the caller. [source:raw]
    // RETURN: Return 0 when both stages succeeded, otherwise return the first negative error result. [function:0x005158AF, source:raw]

    // Conservative worker pseudocode:
    //   int ColorConvertWithWScale(_DWORD* a1, float* a2) {
    //     float v3[64];
    //     int result = MatrixScaleByW(a2, v3);
    //     if (result >= 0) {
    //       result = QuantizationColorSpaceConversion(a1, v3);
    //       if (result >= 0) return 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The exact transforms MatrixScaleByW and QuantizationColorSpaceConversion perform are not evidenced by this packet alone.
    // UNRESOLVED: The meaning of the DWORD array a1 and the float input a2 (likely a color matrix and its W scale) is inferred only from callee names.
    // UNRESOLVED: Callers and the intended failure convention of the negative error codes are unknown here.
}
