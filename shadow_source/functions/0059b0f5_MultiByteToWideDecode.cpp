// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059B0F5
// Canonical corpus name: sub_59B0F5
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59B0F5_0059b0f5.c

void UnknownObject::MultiByteToWideDecode()
{
    // Stateful multibyte-to-wide decode step (cdecl). Guards on a2 (input bytes) and a3 (input length) being non-zero. When the first input byte is zero it writes a null wide char and returns 0. Defaults locale (v7) and code page (v8) come from dword_8D3F38 and CodePage globals unless an LCID pair a5 is supplied. When v7 is zero it emits the first byte as a wide char and returns 1. Otherwise it drives MultiByteToWideChar through the import pointer global at 0x0059E12C with flags 9: a resumable state path using the cbMultiByte global when a conversion state dword is set, a direct single-byte path when off_5E69C8[0][v5] is non-negative, and a lead-byte path otherwise that returns -2 when a3 is below cbMultiByte or stores the lead byte for later. On failure it stores 42 through TLSOffsetGetter() and returns -1. Structural twin of sub_596773 (00596773) per cluster copy.
    // GUARD: Returns 0 immediately when the input bytes pointer a2 or the length a3 is zero [source:raw]
    // GUARD: When the first input byte *a2 is zero, writes a null wide char into lpWideCharStr and returns 0 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Locale v7 and code page v8 are read from a5 (v7=*a5, v8=a5[1]) when present, otherwise from the dword_8D3F38 and CodePage globals [global:0x008D3F38, global:0x008D3F48, source:raw]
    // GUARD: When v7 (locale) is zero, emits the first byte as a wide char into lpWideCharStr and returns 1 [field:this:0x00000000, source:raw]
    // GUARD: When the caller's conversion-state dword is set, resumes a partial conversion: stores v5 into lpMultiByteStr[1], and when cbMultiByte is above 1 succeeds through MultiByteToWideChar with length 2 it returns cbMultiByte, otherwise resets the state dword [global:0x0059E12C, global:0x005E6BD4, source:raw]
    // GUARD: When off_5E69C8[0][v5] is non-negative the byte is not a lead byte: a direct MultiByteToWideChar of one byte returns 1 on success [global:0x005E69C8, global:0x0059E12C, source:raw]
    // GUARD: Lead-byte path: when a3 is below cbMultiByte the lead byte is stored in lpMultiByteStr and -2 is returned (needs more input); otherwise a cbMultiByte-length conversion or a non-zero second input byte returns cbMultiByte, else the state dword is reset [global:0x0059E12C, global:0x005E6BD4, source:raw]
    // ASSIGNMENT: On the failure path stores 42 into the dword returned by TLSOffsetGetter() and returns -1 [callee:0x0058AFCF, source:raw]
    // RETURN: Returns one of 0, 1, cbMultiByte, -2 or -1 to signal consumption or error [function:0x0059B0F5, source:raw]
    // CALL: Invoked by sub_59B092 [caller:0x0059B092, source:raw]

    // Conservative worker pseudocode:
    //   if (!a2 || !a3) return 0;
    //   v5 = *a2;
    //   if (!v5) { if (lpWideCharStr) *lpWideCharStr = 0; return 0; }
    //   v7 = a5 ? *a5 : dword_8D3F38;
    //   v8 = a5 ? a5[1] : CodePage;
    //   if (!v7) { if (lpWideCharStr) *lpWideCharStr = v5; return 1; }
    //   if (*(DWORD*)lpMultiByteStr) {
    //     lpMultiByteStr[1] = v5;
    //     if (cbMultiByte > 1 && MultiByteToWideChar(v8, 9, lpMultiByteStr, 2, lpWideCharStr, !!lpWideCharStr))
    //       { *(DWORD*)lpMultiByteStr = 0; return cbMultiByte; }
    //     *(DWORD*)lpMultiByteStr = 0;
    //   } else if (off_5E69C8[0][v5] >= 0) {
    //     if (MultiByteToWideChar(v8, 9, a2, 1, lpWideCharStr, !!lpWideCharStr)) return 1;
    //   } else {
    //     if (a3 < cbMultiByte) { *lpMultiByteStr = v5; return -2; }
    //     if (cbMultiByte > 1 && MultiByteToWideChar(v8, 9, a2, cbMultiByte, lpWideCharStr, !!lpWideCharStr) || a2[1])
    //       return cbMultiByte;
    //     *(DWORD*)lpMultiByteStr = 0;
    //   }
    //   *(DWORD*)TLSOffsetGetter() = 42;
    //   return -1;
    // UNRESOLVED: MultiByteToWideChar is referenced at address 0x0059E12C as a global; whether that is an import thunk or a data slot is not resolved from this packet
    // UNRESOLVED: The exact semantics of the off_5E69C8 lead-byte table and the meaning of the 42 error code stored via TLSOffsetGetter (errno-style) are inferred, not documented
    // UNRESOLVED: Whether lpWideCharStr is the same object as the field evidence this+0 is a naming inference; the decompiler signature names it as a separate parameter
    // UNRESOLVED: The prelabel cluster note names sub_596773 (00596773) as the structural twin; that relationship is not independently verified here
}
