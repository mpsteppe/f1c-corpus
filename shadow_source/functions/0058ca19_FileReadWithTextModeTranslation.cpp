// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058CA19
// Canonical corpus name: sub_58CA19
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58CA19_0058ca19.c

void UnknownObject::FileReadWithTextModeTranslation()
{
    // Low-level file read helper with CRT text-mode translation, structurally the inner read of a CRT-like _read. Locates the per-slot record for handle a1 in the slot table dword_8D4920 (indexed in 32-slot groups by a1>>5, 36-byte stride, flag byte at +4). Returns 0 immediately when the requested byte count is zero or the slot EOF bit (0x02) is set. On a text-mode + pushback state (bits 0x48) emits the pending pushback byte from +5 (resetting it to LF) before reading. Reads through ReadFile with the handle from the slot record; on failure maps GetLastError: access denied (5) writes TLS error 9 via TLSOffsetGetter and TLS 5 via TLSOffsetGetter_afd8 and returns -1; broken pipe (109) returns 0; any other error goes through ErrorIDLookupTable and returns -1. On success, when the flag byte is negative (signed test, the text-mode indicator), translates the buffer: CRLF pairs fold to a single LF, a trailing CR at buffer end triggers a one-byte ReadFile probe with pushback to slot+5 or a FileSeekViaSetFilePointer(a1, -1, 1) rewind, and Ctrl-Z (0x1A) sets the EOF bit (0x02, unless bit 0x40 is set) and ends the read. Returns the byte count actually delivered (v3 - lpBuffer in text mode, v22 otherwise).
    // ASSIGNMENT: Initialize the byte-count accumulator v22 to 0 and the output cursors v3 and v4 to lpBuffer [source:raw]
    // GUARD: If nNumberOfBytesToRead is zero, return 0 without reading [source:raw]
    // CALCULATION: Compute the slot record address v6 = dword_8D4920[a1>>5] + 36*(a1&0x1F): a1 indexes into a global table of per-32-slot groups with a 36-byte stride [global:0x008D4920, source:raw]
    // GUARD: EOF guard: read the slot flag byte v7 = *(v6+4); if bit 0x02 is set, return 0 [global:0x008D4920, source:raw]
    // GUARD: Pushback path: when bits 0x48 are set in the flag byte and the pushback byte at +5 is not LF (10), emit the pushback byte into *lpBuffer, decrement the remaining count, reset +5 to 10, advance v4 past it and set v22 = 1 [global:0x008D4920, source:raw]
    // CALL: ReadFile(handle at slot record, v4, nNumberOfBytesToRead, &NumberOfBytesRead, 0) performs the raw read [global:0x0059E164, global:0x008D4920, source:raw]
    // GUARD: Error path (access denied): when GetLastError() == 5, write TLS error 9 through TLSOffsetGetter and TLS 5 through TLSOffsetGetter_afd8, then return -1 [global:0x0059E188, callee:0x0058AFCF, callee:0x0058AFD8, source:raw]
    // GUARD: Error path (pipe/other): when GetLastError() == 109 (broken pipe) return 0; otherwise map the error through ErrorIDLookupTable and return -1 [global:0x0059E188, callee:0x0058AF5C, source:raw]
    // ASSIGNMENT: Success accounting: v22 += NumberOfBytesRead; re-read the slot flag byte v13 = slot-record+4 and capture v14 = *v13 [global:0x008D4920, source:raw]
    // GUARD: Text-mode guard: when the flag byte is negative (signed test *v13 < 0), enter the translation path and update the flag byte (set bit 0x04 when the first delivered byte is LF, else clear it); otherwise return v22 directly [global:0x008D4920, source:raw]
    // LOOP: CRLF/Ctrl-Z translation loop over the delivered bytes: Ctrl-Z (0x1A) sets the EOF bit 0x02 in the slot flag (unless bit 0x40 is set) and ends the read; CR (0x0D) followed by LF folds to a single LF, a trailing CR at buffer end triggers a one-byte ReadFile probe with the probed byte pushed back to slot+5 in text mode or rewound via FileSeekViaSetFilePointer(a1, -1, 1); other bytes are copied verbatim. Returns v3 - lpBuffer [global:0x0059E164, callee:0x0058C789, global:0x008D4920, source:raw]
    // RETURN: Return the delivered byte count: v3 - lpBuffer on the text-mode path, v22 on the non-text path, 0 on the EOF/zero-count/broken-pipe paths, -1 on the error paths [source:raw]
    // CALL: Called from sub_58C9B4 and sub_595AF9 as the shared low-level read implementation [caller:0x0058C9B4, caller:0x00595AF9]

    // Conservative worker pseudocode:
    //   unsigned int FileReadWithTextModeTranslation(int a1, char *lpBuffer, DWORD nNumberOfBytesToRead) {
    //     unsigned int v22 = 0;
    //     char *v3 = lpBuffer, *v4 = lpBuffer;
    //     if (!nNumberOfBytesToRead) return 0;
    //     int v5 = 36 * (a1 & 0x1F);
    //     char *v6 = dword_8D4920[a1>>5] + v5;
    //     char v7 = v6[4];
    //     if (v7 & 2) return 0;
    //     if (v7 & 0x48) {
    //       char v8 = v6[5];
    //       if (v8 != 10) {
    //         --nNumberOfBytesToRead; *lpBuffer = v8;
    //         v4 = lpBuffer + 1; v22 = 1;
    //         dword_8D4920[a1>>5][v5+5] = 10;
    //       }
    //     }
    //     DWORD NumberOfBytesRead;
    //     if (!ReadFile(*(HANDLE*)v6, v4, nNumberOfBytesToRead, &NumberOfBytesRead, 0)) {
    //       DWORD e = GetLastError();
    //       if (e == 5) { *(_DWORD*)TLSOffsetGetter() = 9; *(_DWORD*)TLSOffsetGetter_afd8() = 5; return -1; }
    //       if (e != 109) { ErrorIDLookupTable(e); return -1; }
    //       return 0;
    //     }
    //     v22 += NumberOfBytesRead;
    //     char *v13 = v6 + 4;
    //     if (*v13 < 0) {
    //       *v13 = (NumberOfBytesRead && *lpBuffer == 10) ? (*v13 | 4) : (*v13 & 0xFB);
    //       // fold CRLF to LF, probe+pushback/rewind trailing CR, stop at Ctrl-Z setting EOF bit 0x02
    //       return v3 - lpBuffer;
    //     }
    //     return v22;
    //   }
    // UNRESOLVED: The decompiler reuses v22 as both a byte count and an end-pointer inside the translation loop; the exact loop bound logic is an artifact of inlined code and was summarized rather than line-for-line transcribed
    // UNRESOLVED: Meanings of the slot-record flag bits (0x02 EOF, 0x04, 0x40, 0x48, and the text-mode sign bit tested via *v13 < 0) and the 36-byte slot layout of dword_8D4920 are inferred purely from behavior in the raw source, with no external contract
    // UNRESOLVED: TLS error codes 9 and 5 and the ErrorIDLookupTable mapping are assumed to be CRT errno/_doserrno conventions but are not documented in the packet
}
