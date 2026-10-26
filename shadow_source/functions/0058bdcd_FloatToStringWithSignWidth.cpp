// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058BDCD
// Canonical corpus name: FloatToStringWithSignWidth
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToStringWithSignWidth_0058bdcd.c

void UnknownObject::FloatToStringWithSignWidth()
{
    // Converts a double value to a sign/width-formatted string. Reads the double through a1, formats it via LocaleAwareStringFormat into a local 24-byte buffer and a 4-dword scratch array, then applies sign-aware width handling by calling sub_5955AA with an adjusted width (adding 1 when the formatted text starts with '-' and when a3 is positive) and finally sub_58BE2E with the original a2, a3, a4 and the scratch array. Returns a2.
    // CALCULATION: Read the double value v5 through a1 (low/high 32-bit halves passed to the formatter) [source:raw, field:this:0x00000000]
    // CALL: LocaleAwareStringFormat(SLOBYTE(v5), HIDWORD(v5), v7, v6): format the double into scratch array v7 and 24-byte buffer v6 [source:raw, callee:0x00595621]
    // CALCULATION: Compute adjusted width as (v7[0] == 45) + a2 + (a3 > 0), i.e. add 1 for a leading '-' sign character in the formatted text and add 1 when a3 is positive, then call sub_5955AA(adjusted_width, a3 + 1, v7) [source:raw, callee:0x005955AA]
    // CALL: sub_58BE2E(a2, a3, a4, v7, 0): apply the width/sign formatting using the scratch array and original width arguments [source:raw, callee:0x0058BE2E]
    // RETURN: Return a2 (the original width argument) [source:raw]

    // Conservative worker pseudocode:
    //   v5 = *a1;
    //   LocaleAwareStringFormat(low32(v5), high32(v5), v7, v6);
    //   sub_5955AA((v7[0] == '-') + a2 + (a3 > 0), a3 + 1, v7);
    //   sub_58BE2E(a2, a3, a4, v7, 0);
    //   return a2;
    // UNRESOLVED: The exact behavior of sub_58BE2E and sub_5955AA (padding, truncation, or width application) is not established from this function alone.
    // UNRESOLVED: The role of the 24-byte local buffer v6 versus the 4-dword scratch v7 is unclear; v6 may be an intermediate formatted string that is only consumed later.
    // UNRESOLVED: The check v7[0] == 45 is interpreted as detecting a leading '-' sign to reserve width for negative numbers, but the formatter's exact output layout is unverified.
    // UNRESOLVED: The semantics of the returned a2 value (width versus count) and its contract with the caller CfltcvtCRTFloatConversionDispatch are unknown.
}
