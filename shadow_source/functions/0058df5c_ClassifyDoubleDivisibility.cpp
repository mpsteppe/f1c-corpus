// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058DF5C
// Canonical corpus name: DoubleIntegerAndDivisibilityClassification
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoubleIntegerAndDivisibilityClassification_0058df5c.c

void UnknownObject::ClassifyDoubleDivisibility()
{
    // Double classifier: returns 0 when FloatClassify(a1) has any of the 0x90 mask bits set (non-finite/special classification), otherwise rounds a1 and a1/2.0 through FrndMSVCCRTRounding and returns 2. Both rounding results are discarded, so the return value (0 vs 2) is the caller-visible output; called from sub_58DE2C (0058DE2C).
    // CALL: FloatClassify(a1) evaluates the input's floating-point class [callee:0x0058A8A3, source:raw]
    // GUARD: When (FloatClassify(a1) & 0x90) != 0 the function takes the early return path with value 0 [callee:0x0058A8A3, source:raw]
    // RETURN: Returns 0 for inputs whose classification intersects the 0x90 bitmask [source:raw]
    // CALL: FrndMSVCCRTRounding(a1) rounds the original input (result discarded) [callee:0x00591CF3, source:raw]
    // CALCULATION: Computes a1 / 2.0, the divisor coming from read-only double dbl_5B8E48 [global:0x005B8E48, source:raw]
    // CALL: FrndMSVCCRTRounding(a1 / 2.0) rounds the halved input (result discarded) [callee:0x00591CF3, source:raw]
    // RETURN: Returns 2 once the two rounding calls have run [source:raw]
    // CALL: Invoked on the frame path by sub_58DE2C (0058DE2C), which consumes the returned classification [caller:0x0058DE2C, source:raw]

    // Conservative worker pseudocode:
    //   if ((FloatClassify(a1) & 0x90) != 0)
    //     return 0;
    //   FrndMSVCCRTRounding(a1);
    //   FrndMSVCCRTRounding(a1 / 2.0);
    //   return 2;
    // UNRESOLVED: Both FrndMSVCCRTRounding results are discarded, so the two rounding calls appear to be side-effect or validation steps whose contribution is not visible here
    // UNRESOLVED: Meaning of the 0x90 bitmask within FloatClassify's classification flags is not determined from this packet
    // UNRESOLVED: Value of the divisor at dbl_5B8E48 (assumed 2.0) is not present in the packet
    // UNRESOLVED: The caller's interpretation of the returned 0 vs 2 is not visible from this packet
}
