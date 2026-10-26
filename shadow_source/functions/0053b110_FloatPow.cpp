// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053B110
// Canonical corpus name: sub_53B110
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53B110_0053b110.c

void UnknownObject::FloatPow()
{
    // Computes a1 raised to the power a2 using the x87 logarithm/exponent sequence: __FYL2X__ gives a2 * log2(a1), __F2XM1__ gives 2^z - 1 in the exponent domain, and the trailing +1.0 cancels the F2XM1 bias, yielding a1^a2. Returns the result as double.
    // CALL: Compute the logarithm-domain product a2 * log2(a1) via __FYL2X__. [source:raw]
    // CALL: Exponentiate the logarithm-domain value via __F2XM1__, which computes 2^z - 1. [source:raw]
    // CALCULATION: Add 1.0 to cancel the -1 bias introduced by __F2XM1__, completing a1^a2. [source:raw]
    // RETURN: Return the resulting float power widened to double. [source:raw]

    // Conservative worker pseudocode:
    //   double FloatPow(float base, float exponent) {
    //     return (float)(pow2(exponent * log2(base)))
    //          == pow(base, exponent);
    //   }
    // UNRESOLVED: Hex-Rays does not expose the x87 operand order, so which argument is the base versus the multiplier of log2 is inferred from the final +1.0 cancellation rather than stated directly.
    // UNRESOLVED: Callers of this power helper are not present in this packet.
}
