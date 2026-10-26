// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059567D
// Canonical corpus name: Float80ToFloat64Unpack
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Float80ToFloat64Unpack_0059567d.c

void UnknownObject::convertDoubleToExtended80()
{
    // Floating-point format conversion helper. Reads an IEEE-754 double precision value from a3 (low mantissa dword at a3[0], sign/11-bit exponent/mantissa-high dword at a3[1], with sign at bit 31 and exponent at bits 20..30, read via the word at (_WORD*)a3 + 3) and writes a 10-byte extended-precision value at a2: 64-bit significand as dword at a2+0 and a2+4, sign and rebased 15-bit exponent word at a2+8. The exponent is rebased from the double bias by +15360 (and +15361 on the subnormal path), a leading-one bit is forced for normal values, and the significand is left-shift normalized while the exponent is decremented until the leading bit reaches the top of the significand. Returns a2. The packet's caller label (LocaleAwareStringFormat at 0x00595621) suggests use inside a floating-point formatting path.
    // CALCULATION: Read the double input from a3: mantissa low dword from a3[0], mantissa-high 20 bits as a3[1] & 0xFFFFF, and extract the 11-bit exponent ((a1 >> 4) & 0x7FF) and sign bit (a1 & 0x8000) from the word at (_WORD*)a3 + 3. [source:raw]
    // GUARD: If the exponent field is nonzero, take the normal/Inf/NaN path: an exponent of 0x7FF (2047) maps the output exponent to 0x7FFF, otherwise the exponent is rebased to the extended-precision bias by +15360. [source:raw]
    // GUARD: If the exponent field is zero and both mantissa dwords are zero, the value is zero: write all-zero bytes to the 10-byte output at a2 and return a2. [source:raw]
    // GUARD: If the exponent field is zero with a nonzero mantissa, take the subnormal path: rebase the exponent by +15361 and clear the forced leading-one bit so the normalization loop can align the significand. [source:raw]
    // CALCULATION: Assemble the 64-bit extended significand at a2: low dword at a2+0 = mantissa low shifted left 11; high dword at a2+4 = 0x80000000 | (mantissa-high-20 << 11) | (mantissa low >> 21). [source:raw]
    // LOOP: Normalization loop: while the top bit of the significand high dword is clear, left-shift the 64-bit significand stored at a2+0 by one and decrement the adjusted exponent by one. [source:raw]
    // ASSIGNMENT: Write the final word at a2+8 as the adjusted exponent OR the sign bit, completing the 10-byte extended-precision value. [source:raw]
    // RETURN: Return a2, the pointer to the converted extended-precision value. [source:raw]

    // Conservative worker pseudocode:
    //   int* convertDoubleToExtended80(unsigned int a1, int a2, int* a3) {
    //       unsigned int sign = a1 & 0x8000;
    //       unsigned int exp  = (a1 >> 4) & 0x7FF;
    //       unsigned int mantLo  = (unsigned int)*a3;
    //       unsigned int mant20  = (unsigned int)a3[1] & 0xFFFFF;
    //       unsigned int lead = 0x80000000;
    //       unsigned int adjExp;
    //       if (exp != 0) {
    //           adjExp = (exp == 0x7FF) ? 0x7FFF : (exp + 15360);
    //       } else {
    //           if (mant20 == 0 && mantLo == 0) {
    //               *(_DWORD*)(a2 + 0) = 0;
    //               *(_DWORD*)(a2 + 4) = 0;
    //               *(_WORD*)(a2 + 8) = 0;
    //               return (int*)a2;
    //           }
    //           adjExp = exp + 15361;
    //           lead = 0;
    //       }
    //       unsigned int hi = lead | (mant20 << 11) | (mantLo >> 21);
    //       *(_DWORD*)(a2 + 0) = mantLo << 11;
    //       *(_DWORD*)(a2 + 4) = hi;
    //       while ((hi & 0x80000000) == 0) {
    //           unsigned __int64 s = 2 * ((unsigned __int64)hi << 32 | *(_DWORD*)(a2 + 0));
    //           *(_QWORD*)(a2 + 0) = s;
    //           hi = (unsigned int)(s >> 32);
    //           --adjExp;
    //       }
    //       *(_WORD*)(a2 + 8) = (unsigned short)(adjExp | sign);
    //       return (int*)a2;
    //   }
    // UNRESOLVED: The legacy ABI and canonical labels (Float80_to_Float64_Unpack / Float80ToFloat64Unpack) imply an 80-bit to 64-bit direction, but the raw code reads a 64-bit double input (sign at bit 31 and exponent at bits 20..30 of a3[1]) and writes a 10-byte extended value at a2, i.e. double-to-extended. The direction discrepancy cannot be resolved from this packet alone.
    // UNRESOLVED: The caller label LocaleAwareStringFormat at 0x00595621 suggests use inside a floating-point formatting path, but the caller is not analyzed, so the exact consumer of the extended output is unknown.
    // UNRESOLVED: Whether the significand assembly and normalization exactly round-trip every double bit pattern (edge cases of the forced-leading-one scheme, including the zero-output layout) is not proven here.
}
