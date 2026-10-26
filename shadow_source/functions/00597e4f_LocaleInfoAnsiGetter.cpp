// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00597E4F
// Canonical corpus name: sub_597E4F
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_597E4F_00597e4f.c

void UnknownObject::LocaleInfoAnsiGetter()
{
    // Retrieves system/thread locale information as an ANSI or multibyte string, abstracting the wide-vs-ANSI Win32 locale APIs. Caches the detected system mode in the global dword_8D4204 (0 = undetected, 1 = GetLocaleInfoW available, 2 = ANSI only) on first use. Mode 2 returns the direct GetLocaleInfoA result. Mode 1 probes the wide buffer size, allocates a stack buffer via alloca (with __alloca_probe), fills it with GetLocaleInfoW and converts the result to the caller's code page with WideCharToMultiByte, falling back to the global CodePage (0x008D3F48) when the caller passes 0. Returns 0 on any probe/fill failure.
    // GUARD: Read cached locale mode dword_8D4204; if zero (undetected) fall through to probe which Win32 locale API the system supports. [global:0x008D4204, source:raw]
    // CALL: GetLocaleInfoW(0, 1u, 0, 0): wide-API availability probe; success sets the detected mode to 1. [global:0x0059E074, source:raw]
    // CALL: GetLocaleInfoA(0, 1u, 0, 0): ANSI-API fallback probe; when both probes fail the function returns 0, otherwise the detected mode is set to 2. [global:0x0059E13C, source:raw]
    // ASSIGNMENT: Cache the detected system locale mode (1 = wide, 2 = ANSI) in the global dword_8D4204. [global:0x008D4204, source:raw]
    // GUARD: When the cached mode is 2 (ANSI only), forward the request to GetLocaleInfoA(Locale, LCType, lpLCData, cchData) and return its result directly. [global:0x0059E13C, source:raw]
    // GUARD: When the cached mode is neither 1 nor 2, return 0. [global:0x008D4204, source:raw]
    // ASSIGNMENT: When the caller passes CodePage == 0, default it to the global CodePage (0x008D3F48). [global:0x008D3F48, source:raw]
    // CALL: GetLocaleInfoW(Locale, LCType, 0, 0): size probe for the wide string; on failure the function returns 0. [global:0x0059E074, source:raw]
    // CALCULATION: Allocate the wide buffer on the stack: byte size = 2 * wide_char_count + 3, with the low 2 bits cleared (v8 & 0xFC), via alloca guarded by __alloca_probe. [callee:0x005881C0, source:raw]
    // CALL: GetLocaleInfoW(Locale, LCType, buffer, size): fill the stack WCHAR buffer; on failure the function returns 0. [global:0x0059E074, source:raw]
    // CALL: WideCharToMultiByte(CodePage, 0x220, buffer, -1, lpLCData, cchData, 0, 0): convert the wide locale string to the target code page; when cchData is 0 the null output buffer is used as a pure size query. [global:0x0059E228, source:raw]
    // RETURN: Return the WideCharToMultiByte result (characters written or required buffer size); the ANSI direct path returns the GetLocaleInfoA result instead. [source:raw]

    // Conservative worker pseudocode:
    //   mode = dword_8D4204;
    //   if (mode == 0) {
    //       if (GetLocaleInfoW(0, 1, 0, 0)) mode = 1;
    //       else if (!GetLocaleInfoA(0, 1, 0, 0)) return 0; else mode = 2;
    //       dword_8D4204 = mode;
    //   }
    //   if (mode == 2) return GetLocaleInfoA(Locale, LCType, lpLCData, cchData);
    //   if (mode != 1) return 0;
    //   if (CodePage == 0) CodePage = ::CodePage;
    //   size = GetLocaleInfoW(Locale, LCType, 0, 0);
    //   if (!size) return 0;
    //   buf = alloca(round4(2 * size + 3));
    //   if (!GetLocaleInfoW(Locale, LCType, buf, size)) return 0;
    //   return WideCharToMultiByte(CodePage, 0x220, buf, -1, lpLCData, cchData, 0, 0);
    // UNRESOLVED: The packet globals 0x0058895C (ScriptFrameProcessor), 0x005B9B78 (stru_5B9B78) and the four high-address byte globals (0xFF00000000001692, 0xFF00000000001695, 0xFF00000000001699, 0xFF0000000000169B) appear in the packet global list but are absent from the raw source text; they are likely stale join artifacts and are not used in any operation.
    // UNRESOLVED: The 0x220 flag constant passed to WideCharToMultiByte is a flag set (WC_COMPOSITECHECK | WC_NO_BEST_FIT_CHARS per the Windows SDK) but that identification is not evidenced by the packet.
    // UNRESOLVED: The exact purpose of the buffer-alignment mask (v8 & 0xFC) applied to the alloca size is not established by the packet.
}
