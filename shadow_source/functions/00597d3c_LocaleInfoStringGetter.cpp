// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00597D3C
// Canonical corpus name: sub_597D3C
// Owner: LocaleInfoHelper [DERIVED]
// Raw source: functions/sub_597D3C_00597d3c.c

void LocaleInfoHelper::LocaleInfoStringGetter()
{
    // CRT locale-string getter: returns locale info as a wide-character string, caching a detected system type in dword_8D4200 (1 = native GetLocaleInfoW, 2 = GetLocaleInfoA plus MultiByteToWideChar conversion). On the ANSI path it sizes and stack-allocates a buffer, queries it, converts to wide output (or returns the required size when cchData is 0), and returns 0 on every failure path.
    // GUARD: Branch on cached system type dword_8D4200; when unset, probe GetLocaleInfoW(0, 1, ...) then GetLocaleInfoA(0, 1, ...) to detect Unicode support (1 = wide, 2 = ANSI fallback), returning 0 if neither works. Called by sub_5968F6 (0x005968F6). [global:0x008D4200, global:0x0059E074, global:0x0059E13C, caller:0x005968F6, source:raw]
    // ASSIGNMENT: Cache the detected system type into dword_8D4200. [global:0x008D4200, source:raw]
    // CALL: When the cached type is 1, return GetLocaleInfoW(Locale, LCType, lpLCData, cchData) directly. [global:0x0059E074, source:raw]
    // RETURN: Return 0 when the cached type is neither 1 nor 2. [function:0x00597D3C, source:raw]
    // ASSIGNMENT: Default the CodePage argument from the ::CodePage global (0x008D3F48) when the caller passed 0. [global:0x008D3F48, source:raw]
    // CALL: Size the ANSI buffer with a count-only GetLocaleInfoA(Locale, LCType, 0, 0) query; return 0 on failure. [global:0x0059E13C, source:raw]
    // CALCULATION: Round the byte count up with (size + 3) & 0xFC and stack-allocate the buffer via alloca (__alloca_probe). [callee:0x005881C0, source:raw]
    // CALL: Fill the stack buffer via GetLocaleInfoA(Locale, LCType, buffer, size); return 0 on failure. [global:0x0059E13C, source:raw]
    // CALL: Convert the ANSI buffer to the wide output via MultiByteToWideChar(CodePage, 1, buffer, -1, lpLCData, cchData); query-only form when cchData is 0. [global:0x0059E12C, source:raw]
    // RETURN: Return 0 on every failure path. [function:0x00597D3C, source:raw]

    // Conservative worker pseudocode:
    //   int LocaleInfoStringGetter(LCID Locale, LCTYPE LCType, LPWSTR lpLCData, int cchData, UINT CodePage) {
    //     int type = dword_8D4200;
    //     if (!type) {
    //       if (GetLocaleInfoW(0, 1, 0, 0)) type = 1;
    //       else if (!GetLocaleInfoA(0, 1, 0, 0)) return 0;
    //       else type = 2;
    //       dword_8D4200 = type;
    //     }
    //     if (type == 1) return GetLocaleInfoW(Locale, LCType, lpLCData, cchData);
    //     if (type != 2) return 0;
    //     if (!CodePage) CodePage = ::CodePage;
    //     int size = GetLocaleInfoA(Locale, LCType, 0, 0);
    //     if (!size) return 0;
    //     CHAR *buf = (CHAR*)alloca((size + 3) & 0xFC);
    //     if (!buf || !GetLocaleInfoA(Locale, LCType, buf, size)) return 0;
    //     if (cchData) return MultiByteToWideChar(CodePage, 1, buf, -1, lpLCData, cchData);
    //     return MultiByteToWideChar(CodePage, 1, buf, -1, 0, 0);
    //   }
    // UNRESOLVED: global:0x0058895C, global:0x005B9B68 and the byte_ globals are listed in the packet global table but never referenced by the raw body; likely spurious import-thunk or SEH-artifact symbol resolutions.
}
