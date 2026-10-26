// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00595DC8
// Canonical corpus name: sub_595DC8
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_595DC8_00595dc8.c

void UnknownObject::ClassifyCharacterStringType()
{
    // Classifies the character types of a string via GetStringTypeW (Unicode path) or GetStringTypeA (ANSI path), after lazily detecting which string-API family the runtime supports and caching it in dword_8D41C0. The Unicode path first converts the multi-byte input to a wide buffer with MultiByteToWideChar using the active code page. Returns a BOOL result or 0 on failure.
    // GUARD: Lazy mode detection: when the cached mode flag dword_8D41C0 is zero, probe GetStringTypeW with the static String2 probe string; if that fails, probe GetStringTypeA with the static String1 probe string; if both fail, return 0. [global:0x008D41C0, global:0x0059E090, global:0x005B95C4, global:0x0059E094, global:0x007CD8BC]
    // STATE_TRANSITION: Record the detected string-API mode (1 = Unicode path, 2 = ANSI path) back into the cached flag dword_8D41C0. [global:0x008D41C0]
    // GUARD: ANSI path (mode 2): default the Locale to dword_8D3F38 when none is supplied and classify the input via GetStringTypeA. [global:0x008D3F38, global:0x0059E094]
    // CALCULATION: Unicode path (mode 1): default CodePage to the global code page at 0x008D3F48 when none is supplied, then query MultiByteToWideChar with conversion flags 9 (when a7 is set) or 1 (otherwise) to obtain the required wide-char length. [global:0x008D3F48, global:0x0059E12C]
    // LOOP: Allocate a stack wide-char buffer of the required size (via __alloca_probe), clear it with sub_58BB10, perform the real MultiByteToWideChar conversion into the buffer, and classify the wide characters with GetStringTypeW. [callee:0x005881C0, callee:0x0058BB10, global:0x0059E12C, global:0x0059E090]
    // RETURN: Return the GetStringTypeW result when the wide conversion succeeded; otherwise return 0 (false). [source:raw]

    // Conservative worker pseudocode:
    //   BOOL sub_595DC8(DWORD info, LPCSTR src, int cch, LPWORD types, UINT cp, LCID loc, int a7) {
    //     if (!dword_8D41C0) {
    //       if (GetStringTypeW(1, &String2, 1, &ct)) dword_8D41C0 = 1;
    //       else { if (!GetStringTypeA(0, 1, &String1, 1, &ct)) return 0; dword_8D41C0 = 2; }
    //     }
    //     if (dword_8D41C0 == 2) {
    //       if (!loc) loc = dword_8D3F38;
    //       return GetStringTypeA(loc, info, src, cch, types);
    //     }
    //     if (!cp) cp = ::CodePage;
    //     int len = MultiByteToWideChar(cp, a7 ? 9 : 1, src, cch, 0, 0);
    //     if (!len) return 0;
    //     /* allocate + zero wide buffer, convert, then GetStringTypeW(info, buf, len, types) * /
    //   }
    // UNRESOLVED: The role of the referenced globals ScriptFrameProcessor and stru_5B99C8 is not visible in the reconstructed body.
    // UNRESOLVED: The four byte globals byte_FF00000000001692/1695/1699/169B are reported as referenced but do not appear in the reconstructed body; their purpose is unknown.
    // UNRESOLVED: The exact meaning of a7 (drives conversion flags 9 vs 1, likely MB_PRECOMPOSED vs MB_ERR_INVALID_CHARS) is inferred, not confirmed.
}
