// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058FFEC
// Canonical corpus name: LocaleEnumProc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LocaleEnumProc_0058ffec.c

void UnknownObject::LocaleEnumProc()
{
    // Win32 locale-enumeration callback (for EnumSystemLocalesA). Parses the callback locale string with HexStringToIntParser, queries the locale's region and language names through the locale-info function pointer dword_8D3FB8, and compares them against the target region string (dword_8D3FAC) and language string (dword_8D3FA8) with sub_588410. Records the best-matching locale identifier in Locale and dword_8D3FB4 and accumulates match-quality flags in dword_8D3FB0. Returns nonzero to keep enumerating; stops (returns zero) once the region+charset match flags are satisfied.
    // CALL: Parse the enumeration string a1 into an integer locale identifier via HexStringToIntParser. [callee:0x005905DD, function:0x0058FFEC]
    // CALCULATION: Build the region-name query selector: v2 = (-(dword_8D3F9C != 0)) & 0xF005, then add 4098; a nonzero dword_8D3F9C switches to the 3-letter region-code variant. [global:0x008D3F9C, source:raw]
    // CALL: Query the locale region name: dword_8D3FB8(v1, v2 + 4098, buffer, 120) into the 120-byte stack buffer. [global:0x008D3FB8, global:0x008D3F9C, source:raw]
    // GUARD: If the region query or the region-string comparison (sub_588410 against dword_8D3FAC) fails, re-query the language name using LCTYPE 3 or 4097 selected by dword_8D3FA4 and compare it with sub_588410 against dword_8D3FA8. [global:0x008D3FB8, global:0x008D3FA4, global:0x008D3FAC, callee:0x00588410, global:0x008D3FA8, source:raw]
    // GUARD: When any query fails, reset dword_8D3FB0 = 0 and return 1 to continue enumeration. [global:0x008D3FB0, source:raw]
    // STATE_TRANSITION: On a direct language-name match, set the low word of dword_8D3FB0 to (flags | 0x304), record dword_8D3FB4 = locale identifier, and set Locale = locale identifier. [global:0x008D3FB0, global:0x008D3FB4, global:0x008D3F98, source:raw]
    // GUARD: Partial/close-match bookkeeping when flag bit 2 of dword_8D3FB0 is clear: if dword_8D3FA0 is zero or sub_596C80(dword_8D3FA8, buffer, dword_8D3FA0) passes, and bit 0 is clear and ShortInRangeCheckAgainstStaticTable(locale) is true, set bit 0 and record dword_8D3FB4 = locale. [global:0x008D3FA0, callee:0x00596C80, global:0x008D3FA8, callee:0x00590440, global:0x008D3FB0, global:0x008D3FB4, source:raw]
    // STATE_TRANSITION: Otherwise mark a close match: set dword_8D3FB0 bit 1, record dword_8D3FB4 = locale, and if Strlen(dword_8D3FA8) equals dword_8D3FA0 set Locale = locale. [global:0x008D3FB0, global:0x008D3FB4, global:0x008D3F98, callee:0x0058E1B0, global:0x008D3FA8, global:0x008D3FA0, source:raw]
    // GUARD: Final validation runs only while the region+charset bits (0x300) are not both set in dword_8D3FB0: re-query the language name with LCTYPE 3 or 4097; on query failure reset flags and return 1. [global:0x008D3FB0, global:0x008D3FB8, global:0x008D3FA4, source:raw]
    // CALL: Language-match branch (sub_588410 against dword_8D3FA8 succeeded): return ((~dword_8D3FB0 >> 2) & 1) when dword_8D3FA4 is set or dword_8D3FA0 is zero or sub_596C80(dword_8D3FA8, buffer, dword_8D3FA0) passes; otherwise run sub_59045F(locale, 0). [callee:0x00588410, global:0x008D3FA8, global:0x008D3FB0, global:0x008D3FA4, global:0x008D3FA0, callee:0x00596C80, callee:0x0059045F, source:raw]
    // CALL: Language-mismatch branch: set byte_8D3FB1 bit 1 (BYTE1 of dword_8D3FB0 |= 2); unless dword_8D3FA4 is set or dword_8D3FA0 is zero or Strlen(dword_8D3FA8) differs from dword_8D3FA0, run sub_59045F(locale, 1). [global:0x008D3FB1, global:0x008D3FB0, global:0x008D3FA8, global:0x008D3FA4, global:0x008D3FA0, callee:0x0058E1B0, callee:0x0059045F, source:raw]
    // STATE_TRANSITION: After the secondary match returns nonzero (or the mismatch shortcut), set byte_8D3FB1 bit 0 and, if Locale is still zero, store Locale = locale identifier. [global:0x008D3FB1, global:0x008D3F98, source:raw]
    // RETURN: Return ((~dword_8D3FB0 >> 2) & 1): continue enumerating while the charset-match bit is clear, stop once it is set. [global:0x008D3FB0, source:raw]

    // Conservative worker pseudocode:
    //   BOOL LocaleEnumProc(LPSTR localeStr) {
    //     int id = HexStringToIntParser(localeStr);
    //     char buf[120];
    //     int v2 = (-(dword_8D3F9C != 0)) & 0xF005;
    //     if (!dword_8D3FB8(id, v2 + 4098, buf, 120)) { dword_8D3FB0 = 0; return 1; }
    //     if (!sub_588410((BYTE*)dword_8D3FAC, buf)) {
    //       int langType = dword_8D3FA4 != 0 ? 3 : 4097;
    //       if (!dword_8D3FB8(id, langType, buf, 120)) { dword_8D3FB0 = 0; return 1; }
    //       if (!sub_588410((BYTE*)dword_8D3FA8, buf)) {
    //         LOWORD(dword_8D3FB0) |= 0x304;
    //         dword_8D3FB4 = id;
    //         Locale = id;
    //       } else if ((dword_8D3FB0 & 2) == 0) {
    //         if (!dword_8D3FA0 || sub_596C80(dword_8D3FA8, buf, dword_8D3FA0)) {
    //           if ((dword_8D3FB0 & 1) == 0 && ShortInRangeCheckAgainstStaticTable(id)) {
    //             dword_8D3FB0 |= 1; dword_8D3FB4 = id;
    //           }
    //         } else {
    //           dword_8D3FB0 |= 2; dword_8D3FB4 = id;
    //           if (Strlen((DWORD*)dword_8D3FA8) == dword_8D3FA0) Locale = id;
    //         }
    //       }
    //     }
    //     if ((dword_8D3FB0 & 0x300) != 0x300) {
    //       int langType = dword_8D3FA4 != 0 ? 3 : 4097;
    //       if (!dword_8D3FB8(id, langType, buf, 120)) { dword_8D3FB0 = 0; return 1; }
    //       int v4 = 0;
    //       if (sub_588410((BYTE*)dword_8D3FA8, buf)) {
    //         if (dword_8D3FA4 || !dword_8D3FA0 || sub_596C80(dword_8D3FA8, buf, dword_8D3FA0))
    //           return ((~dword_8D3FB0 >> 2) & 1);
    //         v4 = sub_59045F(id, 0);
    //       } else {
    //         BYTE1(dword_8D3FB0) |= 2;
    //         if (!(dword_8D3FA4 || !dword_8D3FA0 || Strlen((DWORD*)dword_8D3FA8) != dword_8D3FA0))
    //           v4 = sub_59045F(id, 1);
    //       }
    //       if (v4) { BYTE1(dword_8D3FB0) |= 1; if (!Locale) Locale = id; }
    //     }
    //     return ((~dword_8D3FB0 >> 2) & 1);
    //   }
    // UNRESOLVED: Exact semantics of the locale-info function pointer dword_8D3FB8 (likely GetLocaleInfoA) and the comparison helpers sub_588410, sub_596C80 and sub_59045F are not established here.
    // UNRESOLVED: Meaning of the dword_8D3FB0 flag bits (0x300 region+charset, bit 0 partial, bit 1 close) is inferred from branch structure, not from a documented enum.
    // UNRESOLVED: No static caller is recorded; the function is invoked as an OS locale-enumeration callback.
}
