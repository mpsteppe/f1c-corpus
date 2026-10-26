// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00596773
// Canonical corpus name: sub_596773
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_596773_00596773.c

void UnknownObject::MultiByteToWideCharSingle()
{
    // Converts a single multi-byte character into a wide character (one-character MB_ERR_INVALID_CHARS path of the ANSI layer). Returns 0 when the input buffer or max-byte count is null/zero. When the first byte is a NUL it writes a NUL wide char and returns 0. When no locale is set (dword_8D3F38 == 0) it assigns the byte directly as the wide char and returns 1. Otherwise it consults the character-type table (off_5E69C8) for a lead byte: single-byte characters go through MultiByteToWideChar with length 1, while lead bytes use the cbMultiByte sequence length when a3 allows it. On conversion failure it stores TLS error 42 and returns -1. Returns the number of bytes consumed on success.
    // GUARD: Return 0 when lpMultiByteStr is NULL or a3 (max bytes) is zero. [source:raw]
    // ASSIGNMENT: Read the first byte of the sequence: v3 = *lpMultiByteStr. [source:raw]
    // GUARD: If the first byte is NUL, write 0 to the output wide char at this+0x0 (*lpWideCharStr) and return 0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: When dword_8D3F38 (locale) is zero, write v3 directly as the wide char at this+0x0 (*lpWideCharStr) and return 1 (direct byte-to-wchar assignment). [field:this:0x00000000, global:0x008D3F38, source:raw]
    // GUARD: Lead-byte check: consult the character-type table off_5E69C8 indexed by v3; proceed only when the table entry is >= 0. [global:0x005E69C8, source:raw]
    // CALL: Call MultiByteToWideChar(CodePage, 9u, lpMultiByteStr, 1, lpWideCharStr, lpWideCharStr != 0) to convert the single character; return 1 on success. [global:0x0059E12C, global:0x008D3F48, source:raw]
    // ASSIGNMENT: For a lead byte take result = cbMultiByte (sequence byte count) and branch on cbMultiByte > 1. [global:0x005E6BD4, source:raw]
    // CALL: When a3 >= cbMultiByte, call MultiByteToWideChar(CodePage, 9u, lpMultiByteStr, cbMultiByte, lpWideCharStr, lpWideCharStr != 0) to convert the full sequence; return cbMultiByte on success. [global:0x0059E12C, global:0x008D3F48, global:0x005E6BD4, source:raw]
    // CALL: On conversion failure (or when a3 < cbMultiByte / the sequence is truncated) store error 42 via TLSOffsetGetter() and return -1. [callee:0x0058AFCF, source:raw]
    // GUARD: Failure path also taken when a3 < result or when the second byte lpMultiByteStr[1] is missing from an incomplete sequence. [source:raw]
    // RETURN: Return result (bytes consumed) on the successful sequence path. [function:0x00596773, source:raw]
    // CALL: Called by sub_596716 (00596716) as the single-character ANSI-to-wide conversion step. [caller:0x00596716]

    // Conservative worker pseudocode:
    //   if (!lpMultiByteStr || !a3) return 0;
    //   v3 = *lpMultiByteStr;
    //   if (!v3) { if (lpWideCharStr) *lpWideCharStr = 0; return 0; }
    //   if (!dword_8D3F38) { if (lpWideCharStr) *lpWideCharStr = v3; return 1; }
    //   if (off_5E69C8[0][v3] >= 0)
    //     return MultiByteToWideChar(CodePage, 9, lpMultiByteStr, 1, lpWideCharStr, lpWideCharStr != 0) ? 1 : fail;
    //   result = cbMultiByte;
    //   if (cbMultiByte > 1 && a3 >= cbMultiByte)
    //     if (MultiByteToWideChar(CodePage, 9, lpMultiByteStr, cbMultiByte, lpWideCharStr, lpWideCharStr != 0)) return cbMultiByte;
    //   if (a3 < result || !lpMultiByteStr[1]) fail;
    //   return result;
    //   fail: *(DWORD*)TLSOffsetGetter() = 42; return -1;
    // UNRESOLVED: dword_8D3F38 (locale-present flag), off_5E69C8 (character-type table) and cbMultiByte (lead-byte sequence length) are only named as data locations; their exact runtime roles are inferred from the fill analysis, not proven.
    // UNRESOLVED: The multi-byte/wchar argument sizes passed to MultiByteToWideChar reuse lpWideCharStr != 0 as the buffer-count argument in the raw source; whether that is decompiler artifact or intentional is unknown.
}
