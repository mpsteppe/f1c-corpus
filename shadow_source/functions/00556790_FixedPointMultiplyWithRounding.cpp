// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00556790
// Canonical corpus name: FixedPointMultiplyWithRounding
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FixedPointMultiplyWithRounding_00556790.c

void UnknownObject::FixedPointMultiplyWithRounding()
{
    // 16.16 fixed-point multiply with rounding: multiplies two 32-bit integer operands as a signed 64-bit product, adds the half-unit rounding constant 0x8000, then shifts the sum right by 16 to land back on the fixed-point scale.
    // CALCULATION: Form the signed 64-bit product of the two 32-bit operands: a2 * (__int64)a1. [source:raw]
    // CALCULATION: Add the rounding offset 0x8000 (half of 2^16) to the 64-bit product. [source:raw]
    // CALCULATION: Shift the sum right by 16 bits, treating the intermediate as an unsigned 64-bit value per the raw source cast, to recover the fixed-point result. [source:raw]
    // RETURN: Return the shifted 32-bit integer result. [source:raw]

    // Conservative worker pseudocode:
    //   int FixedPointMultiplyWithRounding(int a, int b) {
    //     return (int)(((unsigned __int64)((__int64)a * b) + 0x8000) >> 16);
    //   }
    // UNRESOLVED: The raw source widens the intermediate to unsigned before the shift, so the rounding path for negative products is defined only by the decompiler cast, not by a documented semantic.
    // UNRESOLVED: Caller identity and the exact fixed-point scale in use are not evidenced by this packet.
}
