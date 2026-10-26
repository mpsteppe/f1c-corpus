// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052E080
// Canonical corpus name: F_64BitIntegerDivision
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_64BitIntegerDivision_0052e080.c

void UnknownObject::multiply_and_divide_int64()
{
    // Pure integer arithmetic helper: computes (__int64)a1 * a2 / a3 with a 64-bit intermediate, returning the result truncated to int. Full behavior is known from the raw source.
    // CALCULATION: Widens a1 to __int64 and multiplies by a2, producing a 64-bit intermediate product. [source:raw]
    // CALCULATION: Divides the 64-bit product by a3 (integer division). [source:raw]
    // RETURN: Returns the quotient as int, truncating the 64-bit result. [source:raw, function:0x0052E080]

    // Conservative worker pseudocode:
    //   int multiply_and_divide_int64(int a1, int a2, int a3) {
    //       return (int)((__int64)a1 * a2 / a3);
    //   }
    // UNRESOLVED: Semantics for negative a3, negative product, or 64-bit overflow of the product are not captured in the packet.
    // UNRESOLVED: Callers (CMpegBase_Open, CMpegFilePlayer_Open) place this in an MPEG playback path but do not establish the calling values or rounding intent.
}
