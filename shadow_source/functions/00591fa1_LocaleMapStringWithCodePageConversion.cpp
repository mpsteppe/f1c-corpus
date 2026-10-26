// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00591FA1
// Canonical corpus name: sub_591FA1
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_591FA1_00591fa1.c

void UnknownObject::LocaleMapStringWithCodePageConversion()
{
    // Locale-sensitive string mapping (LCMapString) with automatic code-page conversion. Lazily detects at runtime whether the platform maps wide strings (mode 1) or only ANSI (mode 2). Mode 2 calls LCMapStringA directly. Mode 1 converts the source to wide chars, maps with LCMapStringW, and either writes a sortkey directly to the destination (when the 0x400 flag is set) or converts the wide result back to the destination code page with WideCharToMultiByte. Returns the mapped length or 0 on any failure.
    // GUARD: Lazy runtime mode detection: when the mode global dword_8D3FBC is zero, probe LCMapStringW against the wide test string String2; success records mode 1, otherwise probe LCMapStringA against String1 and record mode 2, returning 0 when both probes fail. [global:0x008D3FBC, global:0x0059E124, global:0x0059E128, global:0x005B95C4, global:0x007CD8BC, source:raw]
    // CALCULATION: When the source length cchSrc is positive, bound it through BoundedStringLengthWithCap. [callee:0x005982F8, source:raw]
    // RETURN: Mode 2 (ANSI-only platform): call LCMapStringA directly with the given locale and flags and return its result. [global:0x0059E128, source:raw]
    // GUARD: Mode 1 path: when the caller-supplied CodePage is zero substitute the default CodePage global. [global:0x008D3F48, source:raw]
    // CALL: Query the required wide-char buffer size via MultiByteToWideChar, using conversion flags 9 when a8 is non-zero else 1; bail out returning 0 on failure. [global:0x0059E12C, source:raw]
    // CALCULATION: Size a working buffer on the stack (2 * length + 3 aligned down to a 4-byte boundary) via alloca, then set the compiler SEH try-level state for the frame. [callee:0x005881C0, global:0xFF00000000001692, global:0xFF00000000001695, global:0xFF00000000001699, global:0xFF0000000000169B, source:raw]
    // CALL: Convert the source ANSI string into the wide-character stack buffer with MultiByteToWideChar; bail out returning 0 on failure. [global:0x0059E12C, source:raw]
    // CALL: Map the wide string with LCMapStringW to obtain the mapped length; bail out returning 0 on failure. [global:0x0059E124, source:raw]
    // GUARD: Sortkey path: when dwMapFlags has the 0x400 bit set, map directly into the destination buffer and validate the length fits cchDest. [global:0x0059E124, source:raw]
    // CALL: Otherwise map into a wide buffer and convert the result back to the destination code page with WideCharToMultiByte; bail out returning 0 on failure. [global:0x0059E228, source:raw]
    // RETURN: Return the mapped length computed by the active branch, or 0 when any step failed. [source:raw]

    // Conservative worker pseudocode:
    //   // Locale map string with code-page conversion; wide vs ANSI detected once at runtime.
    //   int sub_591FA1(LCID locale, DWORD flags, const char* src, int srcLen,
    //                  char* dst, int dstLen, UINT cp, int a8) {
    //     if (!g_wideMode) {
    //       if (LCMapStringW(0, 0x100, &testWide, 1, 0, 0)) g_wideMode = 1;
    //       else if (!LCMapStringA(0, 0x100, testA, 1, 0, 0)) return 0;
    //       else g_wideMode = 2;
    //     }
    //     if (srcLen > 0) srcLen = BoundedStringLengthWithCap(src, srcLen);
    //     if (g_wideMode == 2) return LCMapStringA(locale, flags, src, srcLen, dst, dstLen);
    //     if (g_wideMode != 1) return 0;
    //     if (!cp) cp = DefaultCodePage;
    //     int n = MultiByteToWideChar(cp, a8 ? 9 : 1, src, srcLen, 0, 0);
    //     if (!n) return 0;
    //     WCHAR* wide = _alloca((2 * n + 3) & ~3);
    //     if (!MultiByteToWideChar(cp, 1, src, srcLen, wide, n)) return 0;
    //     int m = LCMapStringW(locale, flags, wide, n, 0, 0);
    //     if (!m) return 0;
    //     if (flags & 0x400) {
    //       if (dstLen && (m > dstLen || !LCMapStringW(locale, flags, wide, n, (LPWSTR)dst, dstLen))) return 0;
    //       return m;
    //     }
    //     WCHAR* mapped = _alloca((2 * m + 3) & ~3);
    //     if (!LCMapStringW(locale, flags, wide, n, mapped, m)) return 0;
    //     int out = WideCharToMultiByte(cp, 0x220, mapped, m, dst, dstLen, 0, 0);
    //     return out ? out : 0;
    //   }
    // UNRESOLVED: The exact meaning of the caller-supplied a8 flag is unresolved; it selects conversion flags 9 versus 1 for the size query.
    // UNRESOLVED: global:0x0058895C (ScriptFrameProcessor) and global:0x005B95C8 (stru_5B95C8, adjacent to the String2 test data) are listed as referenced but have no visible use in the recovered body; their roles are unverified.
    // UNRESOLVED: The function-pointer globals at 0x0059E124, 0x0059E128, 0x0059E12C, and 0x0059E228 are assumed to hold the resolved kernel32 entry points; indirection is not visible in the recovered body.
}
