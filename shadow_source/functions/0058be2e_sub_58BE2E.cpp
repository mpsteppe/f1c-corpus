// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058BE2E
// Canonical corpus name: sub_58BE2E
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58BE2E_0058be2e.c

void UnknownObject::sub_58BE2E()
{
    // Formats a floating-point string representation: optionally shifts the buffer to make room, writes a leading '-' sign if negative, shifts digits left by one and inserts the locale decimal separator byte, then advances past the mantissa, optionally writes an exponent marker 'E' (69), and decomposes the exponent value from the struct at a4 into hundreds/tens/units digits accumulated onto pre-initialized '0' characters. Returns the original buffer pointer a1.
    // GUARD: If a5 is nonzero, call StringShiftByOffset on the buffer at a1 + (*(_DWORD *)a4 == 45) with shift flag (a2 > 0) to make room for sign/decimal separator. [callee:0x0058C0D0, source:raw, function:0x0058BE2E]
    // GUARD: If *(_DWORD *)a4 == 45 (negative), write '-' (45) at a1 and advance the write cursor to a1 + 1. [field:this:0x00000000, source:raw, function:0x0058BE2E]
    // ASSIGNMENT: If a2 > 0, shift the digit at the cursor left one position and insert the locale decimal separator byte byte_5E6BD8 at the freed position. [field:this:0x00000001, global:0x005E6BD8, source:raw, function:0x0058BE2E]
    // CALL: Call sub_58FCA0 with v5 + a2 + (a5 == 0) to advance the output cursor past the mantissa portion; result stored in v6. [callee:0x0058FCA0, source:raw, function:0x0058BE2E]
    // GUARD: If a3 is nonzero, write 'E' (69) at *v6 to mark the exponent start. [source:raw, function:0x0058BE2E]
    // GUARD: If the leading digit char at **(_BYTE **)(a4 + 12) is not '0' (48), decompose the exponent value *(_DWORD *)(a4 + 4) - 1 (or 1 - value when negative, writing '-' at v6[1]) and accumulate hundreds (v6[2]), tens (v6[3]) and units (v6[4]) digits onto pre-initialized '0' characters. [field:this:0x00000002, source:raw, function:0x0058BE2E]
    // RETURN: Return the original buffer pointer a1. [source:raw, function:0x0058BE2E]

    // Conservative worker pseudocode:
    //   if (a5) StringShiftByOffset(a1 + (*(_DWORD *)a4 == 45), a2 > 0);
    //   v5 = a1;
    //   if (*(_DWORD *)a4 == 45) { *a1 = 45; v5 = a1 + 1; }
    //   if (a2 > 0) { *v5 = v5[1]; *++v5 = byte_5E6BD8; }
    //   v6 = sub_58FCA0(v5 + (a5 == 0) + a2);
    //   if (a3) *v6 = 69;
    //   if (**(_BYTE **)(a4 + 12) != 48) {
    //       v7 = *(_DWORD *)(a4 + 4) - 1;
    //       if (v7 < 0) { v7 = 1 - *(_DWORD *)(a4 + 4); v6[1] = 45; }
    //       if (v7 >= 100) { v6[2] += v7 / 100; v7 %= 100; }
    //       if (v7 >= 10) { v6[3] += v7 / 10; v7 %= 10; }
    //       v6[4] += v7;
    //   }
    //   return a1;
    // UNRESOLVED: The struct at a4 (offset +4 exponent value, offset +12 leading-digit flag, offset +0 sign flag) is only partially characterized; its owning type is unknown.
    // UNRESOLVED: Buffer chars at v6[1]/v6[2]/v6[3]/v6[4] are assumed to be pre-initialized '0' by the caller; this function only accumulates onto them.
    // UNRESOLVED: Global aE000 (0x005B8D80) appears in the index as the exponent template but is not referenced in the function body; likely supplied by the caller (FloatToStringWithSignWidth / UtilityFunction_bfec).
}
