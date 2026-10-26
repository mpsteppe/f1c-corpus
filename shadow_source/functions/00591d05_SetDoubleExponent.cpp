// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00591D05
// Canonical corpus name: FloatBitManipulation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatBitManipulation_00591d05.c

void UnknownObject::SetDoubleExponent()
{
    // Rebuilds the exponent field of a double by bit manipulation. Copies argument a1 into local v3, then rewrites the high word of v3: the sign bit and the low four mantissa bits are retained from HIWORD(a1) via the mask 0x800F, while the 11-bit exponent field is replaced with (a2 + 1022), encoded as 16 * (a2 + 1022) (shifted left four places). The modified double v3 is returned.
    // ASSIGNMENT: Copy the double argument a1 into the local v3 so its bits can be modified without disturbing the argument. [source:raw]
    // CALCULATION: Rewrite the high word of v3: keep the sign bit and the low four mantissa bits from HIWORD(a1) using the mask 0x800F, and OR in 16 * (a2 + 1022), which places the value (a2 + 1022) into the 11-bit exponent field. [source:raw, function:0x00591D05]
    // RETURN: Return v3, the double whose exponent field has been replaced. [source:raw, function:0x00591D05]

    // Conservative worker pseudocode:
    //   v3 = a1;
    //   HIWORD(v3) = (HIWORD(a1) & 0x800F) | (16 * (a2 + 1022));
    //   return v3;
    // UNRESOLVED: The result scales a1 by a power of two derived from a2 (the true binary exponent becomes a2 - 1), but that scaling interpretation is DERIVED from the bit layout and is not stated by the packet.
    // UNRESOLVED: The call site 00591D88 and the mathematical purpose of the scaling (e.g. constructing a power-of-two or rescaling a value) are outside the packet's evidence.
    // UNRESOLVED: The ABI name 'Float_Bit_Manipulation' carries LEGACY trust and is not runtime-confirmed.
}
