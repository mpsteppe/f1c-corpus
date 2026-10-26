// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00596089
// Canonical corpus name: sub_596089
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_596089_00596089.c

void UnknownObject::WideCharToMultiByteSingle()
{
    // Converts a single wide character (WideCharStr) into multi-byte form, the wide-to-ANSI mirror of the single-character conversion layer. Returns 0 when the output buffer lpMultiByteStr is NULL. When no locale is set (dword_8D3F38 == 0) and the character fits in one byte (WideCharStr <= 0xFF), it writes the truncation directly into the buffer and returns 1. Otherwise it calls WideCharToMultiByte(CodePage, 0x220u, &WideCharStr, 1, output, cbMultiByte, 0, &defaultCharUsed) and returns the byte count written, or -1 with TLS error 42 when conversion fails or a default (replacement) character was used.
    // ASSIGNMENT: Seed result with the output buffer pointer: result = lpMultiByteStr. [source:raw]
    // GUARD: Return result (0) immediately when lpMultiByteStr is NULL. [source:raw]
    // GUARD: When dword_8D3F38 (locale) is zero and WideCharStr <= 0xFF, take the direct truncation path. [global:0x008D3F38, source:raw]
    // ASSIGNMENT: Write the wide character truncated to one byte into the output buffer at this+0x0 (*lpMultiByteStr = WideCharStr) and return 1. [field:this:0x00000000, source:raw]
    // CALL: Call WideCharToMultiByte(CodePage, 0x220u, &WideCharStr, 1, output buffer, cbMultiByte, 0, &defaultCharUsed) and store the byte count written as result. [global:0x0059E228, global:0x008D3F48, global:0x005E6BD4, source:raw]
    // GUARD: Failure path taken when the conversion returned 0 or a default (replacement) character flag was set. [source:raw]
    // CALL: On failure store error 42 via TLSOffsetGetter() and return -1. [callee:0x0058AFCF, source:raw]
    // RETURN: Return result (byte count written) on success, or -1 on failure. [function:0x00596089, source:raw]
    // CALL: Called by sub_596030 (00596030) as the single-character wide-to-ANSI conversion step. [caller:0x00596030]

    // Conservative worker pseudocode:
    //   result = (int)lpMultiByteStr;
    //   if (lpMultiByteStr) {
    //     if (!dword_8D3F38) {
    //       if (WideCharStr <= 0xFF) { *lpMultiByteStr = WideCharStr; return 1; }
    //       goto fail;
    //     }
    //     result = WideCharToMultiByte(CodePage, 0x220, &WideCharStr, 1, (LPSTR)result, cbMultiByte, 0, (LPBOOL)&defaultCharUsed);
    //     if (!result || defaultCharUsed) goto fail;
    //   }
    //   return result;
    //   fail: *(DWORD*)TLSOffsetGetter() = 42; return -1;
    // UNRESOLVED: dword_8D3F38 (locale-present flag) and cbMultiByte (output-buffer capacity / sequence length) are only named as data locations; their exact runtime roles are inferred from the fill analysis, not proven.
    // UNRESOLVED: The default-character flag in the raw source aliases the lpMultiByteStr variable after it is repurposed; whether this is a decompiler artifact or genuine stack reuse is unknown.
}
