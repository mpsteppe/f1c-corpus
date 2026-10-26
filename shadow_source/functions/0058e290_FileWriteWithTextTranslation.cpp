// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058E290
// Canonical corpus name: sub_58E290
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58E290_0058e290.c

void UnknownObject::FileWriteWithTextTranslation()
{
    // CRT file write (_write): writes lpBuffer bytes to the handle for CRT index a1, seeking to end-of-file first when the text-mode append flag (bit 5) is set. In binary mode (bit 7 clear) writes directly via WriteFile; in text mode translates '\n' (10) to "\r\n" (13 10) in chunks of at most 1024 bytes, returning the byte count minus inserted carriage returns. Maps ERROR_ACCESS_DENIED (5) to errno 9 (EBADF), maps other errors via ErrorIDLookupTable, and reports ENOSPC (28) for a zero-length write without error.
    // ASSIGNMENT: Initialize v14 (bytes written) and v12 (inserted-newline count) to 0. [source:raw]
    // GUARD: Guard: when nNumberOfBytesToWrite is 0, return 0 immediately. [source:raw]
    // CALCULATION: Compute the handle-block pointer v4 = 4*(a1>>5) + 9259296 and the within-block slot offset v5 = 36*(a1&0x1F). [source:raw]
    // GUARD: Guard: when the flag byte at dword_8D4920[a1>>5] + v5 + 4 has bit 5 (0x20, text-mode append) set, call FileSeekViaSetFilePointer(a1, 0, 2u) to seek to end-of-file before writing. [callee:0x0058C789, source:raw]
    // GUARD: Guard on the sign of the mode byte at v6 + 4: when >= 0 (binary mode, bit 7 clear) write the whole buffer directly with a single WriteFile call. [global:0x0059E220, source:raw]
    // CALL: Binary-mode write: WriteFile(*(HANDLE*)v6, lpBuffer, nNumberOfBytesToWrite, &NumberOfBytesWritten, 0); on success v14 = NumberOfBytesWritten and LastError = 0, otherwise LastError = GetLastError(). [global:0x0059E220, global:0x0059E188, source:raw]
    // LOOP: Text-mode path: loop translating the input into a 1024-byte chunk buffer, emitting '\r' before every '\n' (10), incrementing the inserted-newline count v12, and writing each chunk via WriteFile until the input is consumed or a write fails. [global:0x0059E220, source:raw]
    // CALCULATION: Accumulate v14 += NumberOfBytesWritten and break when a WriteFile call fails or the input is exhausted. [global:0x0059E220, source:raw]
    // RETURN: When v14 is nonzero, return v14 - v12 (subtract the inserted carriage-return bytes). [source:raw]
    // CALL: On failure with LastError 5 (ERROR_ACCESS_DENIED): write errno 9 (EBADF) via TLSOffsetGetter() and doserrno 5 via TLSOffsetGetter_afd8(); for other errors map via ErrorIDLookupTable(LastError). [callee:0x0058AFCF, callee:0x0058AFD8, callee:0x0058AF5C, source:raw]
    // GUARD: When no bytes were written and there was no error: if the flag byte at the block slot +4 has bit 6 (0x40, EOF/Ctrl-Z flag) and the first buffer byte is 26 (Ctrl-Z), return 0; otherwise write errno 28 (ENOSPC) via TLSOffsetGetter() and doserrno 0 via TLSOffsetGetter_afd8(). [callee:0x0058AFCF, callee:0x0058AFD8, source:raw]
    // RETURN: Return -1 on all error paths. [source:raw]
    // CALL: Called by sub_58E22B and sub_59797B on the frame path to write buffered output. [caller:0x0058E22B, caller:0x0059797B, source:raw]

    // Conservative worker pseudocode:
    //   int FileWriteWithTextTranslation(int a1, BYTE* lpBuffer, DWORD n) {
    //     DWORD written = 0; int nl = 0;
    //     if (!n) return 0;
    //     if (flag(a1, BIT_APPEND)) FileSeekViaSetFilePointer(a1, 0, 2u);
    //     if ((signed char)mode(a1) >= 0) {
    //       if (WriteFile(handle(a1), lpBuffer, n, &written, 0)) return (int)written;
    //     } else {
    //       translate_and_write_chunks(); // '\n' -> "\r\n", <=1024 bytes per WriteFile
    //       if (written) return (int)written - nl;
    //     }
    //     if (LastError) {
    //       if (LastError == 5) { *(DWORD*)TLSOffsetGetter() = 9; *(DWORD*)TLSOffsetGetter_afd8() = 5; }
    //       else ErrorIDLookupTable(LastError);
    //     } else {
    //       if ((flag(a1, BIT_CTRLZ)) && *lpBuffer == 26) return 0;
    //       *(DWORD*)TLSOffsetGetter() = 28; *(DWORD*)TLSOffsetGetter_afd8() = 0;
    //     }
    //     return -1;
    //   }
    // UNRESOLVED: The handle-block pointer arithmetic (4*(a1>>5) + 9259296 and slot offset 36*(a1&0x1F)) matches the shared CRT handle-tracking array dword_8D4920 seen in the sibling handle functions, but this packet carries no global evidence ref for it, so the identity stays source-only.
    // UNRESOLVED: The exact meaning of flag bit 6 (0x40) as an EOF/Ctrl-Z condition is inferred from the branch reading *lpBuffer == 26 and is not independently proven.
}
