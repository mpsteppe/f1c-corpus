// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059807B
// Canonical corpus name: sub_59807B
// Owner: CrtStringCollation [DERIVED]
// Raw source: functions/sub_59807B_0059807b.c

void CrtStringCollation::LocaleCompareStringAnsi()
{
    // Locale-aware comparison of two bounded ANSI string buffers. On first call it detects whether CompareStringW is functional by probing it with a known test string; based on the outcome it caches a compare mode (1 = wide, 2 = ANSI) in a global. Mode 2 compares with CompareStringA directly. Mode 1 converts both strings to wide characters with MultiByteToWideChar and compares with CompareStringW, with special empty-string/DBCS lead-byte ordering handled via GetCPInfo. Returns 0 on failure.
    // GUARD: On first use (cached mode global is zero), probe CompareStringW with the test string String2 and cache mode 1 if it succeeds; otherwise probe CompareStringA with test string String1 and cache mode 2, returning 0 if that also fails. [source:raw, global:0x008D4208, global:0x0059E06C, global:0x0059E070, global:0x005B95C4, global:0x007CD8BC]
    // CALCULATION: Cap the input lengths: when each count is positive, replace it with BoundedStringLengthWithCap of the corresponding string; otherwise keep the raw count. [source:raw, callee:0x005982F8]
    // CALL: ANSI path: when the cached mode is 2, return CompareStringA(Locale, dwCmpFlags, lpString1, length1, lpString2, length2). [source:raw, global:0x0059E070, global:0x008D4208]
    // ASSIGNMENT: Wide path setup: when the cached mode is 1 and no explicit code page was passed, fall back to the default CodePage global. [source:raw, global:0x008D3F48, global:0x008D4208]
    // GUARD: Empty-string ordering: when either capped length is zero, return 2 when both lengths are equal, otherwise use GetCPInfo and the DBCS lead-byte table to decide which single byte sorts first, returning 0 when code page info is unavailable. [source:raw, global:0x0059E148]
    // CALCULATION: Convert the first string to wide: query the required wide-character count via MultiByteToWideChar(CodePage, 9, lpString1, length1, 0, 0), reserve a rounded stack buffer with alloca (guarded by __alloca_probe), and perform the conversion. [source:raw, global:0x0059E12C, callee:0x005881C0]
    // CALCULATION: Convert the second string to wide the same way, with its own width query, allocation and conversion. [source:raw, global:0x0059E12C, callee:0x005881C0]
    // CALL: Compare the two wide strings with CompareStringW and return its result; any failed conversion falls through to 0. [source:raw, global:0x0059E06C]
    // RETURN: Return 0 on every failure path: unavailable compare API, failed code page probe, or failed wide conversion. [source:raw]

    // Conservative worker pseudocode:
    //   int LocaleCompareStringAnsi(LCID loc, DWORD flags, const char* s1, int n1, const char* s2, int n2, UINT cp) {
    //     if (g_mode == 0) {
    //       if (CompareStringW(0, 0, g_testWide, 1, g_testWide, 1)) g_mode = 1;
    //       else if (!CompareStringA(0, 0, g_testAnsi, 1, g_testAnsi, 1)) return 0;
    //       else g_mode = 2;
    //     }
    //     int l1 = n1 > 0 ? BoundedStringLengthWithCap(s1, n1) : n1;
    //     if (n2 > 0) n2 = BoundedStringLengthWithCap(s2, n2);
    //     if (g_mode == 2) return CompareStringA(loc, flags, s1, l1, s2, n2);
    //     if (g_mode == 1) {
    //       if (!cp) cp = g_codePage;
    //       /* empty-string and DBCS lead-byte ordering via GetCPInfo; on failure return 0 * /
    //       int w1 = MultiByteToWideChar(cp, 9, s1, l1, 0, 0);
    //       int w2 = MultiByteToWideChar(cp, 9, s2, n2, 0, 0);
    //       if (!w1 || !w2) return 0;
    //       /* reserve wide buffers, convert both, then * /
    //       return CompareStringW(loc, flags, wbuf1, w1, wbuf2, w2);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Globals ScriptFrameProcessor (0x0058895C) and stru_5B9B88 (0x005B9B88) appear only in the fact tables and never in the raw source; likely stale attributions.
    // UNRESOLVED: The byte globals at 0xFF00000000001692, 0xFF00000000001695, 0xFF00000000001699, 0xFF0000000000169B, 0xFF0000000000547A and 0xFF0000000000547C carry impossible non-image addresses and are not referenced by the raw source; likely extraction artifacts rather than real globals.
}
