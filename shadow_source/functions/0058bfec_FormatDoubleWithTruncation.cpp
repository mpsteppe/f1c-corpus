// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058BFEC
// Canonical corpus name: UtilityFunction_bfec
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_bfec_0058bfec.c

void UnknownObject::FormatDoubleWithTruncation()
{
    // Number-to-string helper (__cdecl): reads a double from a1, formats it through LocaleAwareStringFormat into a local buffer, then routes through sub_5955AA into an output buffer a2. Length guards decide between an alternate conversion sub_58BE2E and a truncation path that strips the trailing character before the final UtilityFunction_bf45 call. ABI legacy label is Utility_Function_Number_to_String_with_Truncatio.
    // CALCULATION: Load the double value v7 = *a1 from the caller-supplied double pointer. [source:raw]
    // CALL: Format the value by calling LocaleAwareStringFormat with the low and high DWORD halves of the double, the count out-parameter &v9, and the local buffer v8. [callee:0x00595621, source:raw]
    // CALCULATION: Precompute v4 = v10 - 1 and derive the sign-aware buffer pointer v5 = &a2[v9 == 45], skipping one byte when the format count is the minus character code 45. [source:raw]
    // CALL: Invoke sub_5955AA(v5, a3, &v9) to convert/scan the formatted text with length limit a3, capturing a length into &v9. [callee:0x005955AA, source:raw]
    // GUARD: Guard on the precomputed length: when (v10 - 1) < -4 or (v10 - 1) >= a3, return sub_58BE2E(a2, a3, a4, &v9, 1) as the alternate conversion path. [callee:0x0058BE2E, source:raw]
    // GUARD: Guard on v4 < (v10 - 1): when the earlier length is short, truncate the trailing character with v5[strlen(v5) - 1] = 0. [source:raw]
    // RETURN: Return UtilityFunction_bf45(a2, a3, &v9, 1) as the final completion path when no alternate branch was taken. [callee:0x0058BF45, source:raw]
    // CALL: Invoked by CfltcrtCRTFloatConversionDispatch (0x0058C07F) as a float-to-string conversion stage. [caller:0x0058C07F, source:raw]

    // Conservative worker pseudocode:
    //   BYTE *FormatDoubleWithTruncation(double *src, BYTE *out, int limit, int flags) {
    //     double value = *src;
    //     int count;
    //     BYTE stackbuf[24];
    //     LocaleAwareStringFormat(LOW32(value), HIGH32(value), &count, stackbuf);
    //     int len = v10 - 1;
    //     const char *cursor = out + (count == 45);
    //     sub_5955AA(cursor, limit, &count);
    //     if (len < -4 || len >= limit)
    //       return sub_58BE2E(out, limit, flags, &count, 1);
    //     if (len < v10 - 1)
    //       cursor[strlen(cursor) - 1] = 0;
    //     return UtilityFunction_bf45(out, limit, &count, 1);
    //   }
    // UNRESOLVED: Local v10 is read (v10 - 1) before any visible write in the decompiled body; it is likely a hidden stack slot written by LocaleAwareStringFormat or a decompiler artifact, and its true producer is unresolved.
    // UNRESOLVED: Semantics of the constant 45 comparison (minus-sign char code hypothesis) and the shared &v9 length parameter are inferred, not confirmed.
    // UNRESOLVED: The field entry this:0x00000000 has no corresponding this-based access in this __cdecl body; the packet field list appears misattributed.
}
