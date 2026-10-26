// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00590246
// Canonical corpus name: sub_590246
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_590246_00590246.c

void UnknownObject::LocaleEnumCallback()
{
    // Locale enumeration callback: parses a hex locale string a1 into an integer, queries the locale info function pointer (dword_8D3FB8), and on match compares the current language string (dword_8D3FA8) against the returned buffer. When the language matches and charset-mode / three-letter checks pass, it records the validated locale ID into dword_8D3FB4 and Locale (0x008D3F98) and sets a bit in the validation flags dword_8D3FB0. Returns the value of bit 2 of the complement of dword_8D3FB0, and returns 1 with dword_8D3FB0 cleared when the locale info query itself fails.
    // CALL: Parse a1 with HexStringToIntParser into integer v1 for use as the locale ID. [callee:0x005905DD, source:raw]
    // CALCULATION: Build query flags: v2 starts as the two's-complement presence mask of dword_8D3FA4 (nonzero becomes -1) and is masked to low bits with 0xF002. [global:0x008D3FA4, source:raw]
    // CALL: Invoke the locale info function pointer dword_8D3FB8(v1, v2 + 4097, v5, 120), writing up to 120 bytes into the scratch buffer. [global:0x008D3FB8, source:raw]
    // GUARD: When the locale info query returns 0 (failure), clear the validation flags dword_8D3FB0 = 0 and return 1, skipping all matching logic. [global:0x008D3FB0, source:raw]
    // CALL: sub_588410(dword_8D3FA8, v5) compares the current language string against the returned locale info buffer; its result gates the next branch. [callee:0x00588410, global:0x008D3FA8, source:raw]
    // GUARD: On match failure, if the three-letter flag dword_8D3FA4 is set, commit the locale: dword_8D3FB0 |= 4, dword_8D3FB4 = v1, Locale (0x008D3F98) = v1, then return the bit test. [global:0x008D3FA4, global:0x008D3FB0, global:0x008D3FB4, global:0x008D3F98, source:raw]
    // CALL: On match failure without the three-letter flag, validate the locale ID with sub_59045F(v1, 1); a nonzero result takes the same commit path. [callee:0x0059045F, source:raw]
    // GUARD: On match success, accept when the three-letter flag dword_8D3FA4 is set, when the charset-mode global dword_8D3FA0 is zero, or when sub_596C80(dword_8D3FA8, v5, dword_8D3FA0) compares the language string with charset mode successfully. [callee:0x00596C80, global:0x008D3FA4, global:0x008D3FA0, global:0x008D3FA8, source:raw]
    // CALL: On match success without the accept conditions, validate the locale ID with sub_59045F(v1, 0); a nonzero result also takes the commit path. [callee:0x0059045F, source:raw]
    // STATE_TRANSITION: Commit path (LABEL_11): dword_8D3FB0 |= 4, dword_8D3FB4 = v1 and Locale (0x008D3F98) = v1 record the validated locale ID. [global:0x008D3FB0, global:0x008D3FB4, global:0x008D3F98, source:raw]
    // RETURN: Return ((~dword_8D3FB0) >> 2) & 1, i.e. the inverse of bit 2 of the validation flags, on every exit path except the failed-query early return. [global:0x008D3FB0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_590246(char *a1) {
    //     int v1 = HexStringToIntParser(a1);
    //     int v2 = -(dword_8D3FA4 != 0);
    //     LOWORD(v2) = v2 & 0xF002;
    //     if (!dword_8D3FB8(v1, v2 + 4097, v5, 120)) {
    //       dword_8D3FB0 = 0;
    //       return 1;
    //     }
    //     if (sub_588410((char*)dword_8D3FA8, v5)) {
    //       if (dword_8D3FA4 || !dword_8D3FA0 || sub_596C80(dword_8D3FA8, v5, dword_8D3FA0))
    //         return ((~dword_8D3FB0) >> 2) & 1;
    //       v4 = sub_59045F(v1, 0);
    //     } else {
    //       if (dword_8D3FA4) goto commit;
    //       v4 = sub_59045F(v1, 1);
    //     }
    //     if (v4) goto commit;
    //     return ((~dword_8D3FB0) >> 2) & 1;
    //   commit:
    //     dword_8D3FB0 |= 4;
    //     dword_8D3FB4 = v1;
    //     Locale = v1;
    //     return ((~dword_8D3FB0) >> 2) & 1;
    //   }
    // UNRESOLVED: The concrete meaning of the 0xF002 mask and the +4097 info-query subtype is only inferable from the locale-info API contract, not from this packet.
    // UNRESOLVED: dword_8D3FB8 is called as a function pointer with no static target; its identity is defined elsewhere.
    // UNRESOLVED: The charset-mode global dword_8D3FA0 and the three-letter flag dword_8D3FA4 are read only; their writers are not visible here.
}
