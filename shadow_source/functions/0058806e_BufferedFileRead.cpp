// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058806E
// Canonical corpus name: sub_58806E
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58806E_0058806e.c

void UnknownObject::BufferedFileRead()
{
    // fread-style buffered read from a FILE-style stream descriptor a4 (a4[0]=read pointer, a4[1]=buffered byte count, a4[3]=flags at +0xC, a4[4]=OS file handle at +0x10, a4[6]=buffer size at +0x18). Requests a3*a2 bytes into destination a1. Drains buffered bytes first via MemoryCopy_cc00, refills one character at a time through sub_58C255 (filbuf-style underflow refill) when the request fits inside the buffer, and falls back to a direct sub_58C9B4 read of the OS handle rounded down to a multiple of the buffer size for larger requests. On failure ORs the EOF flag (0x10) or the error flag (0x20) into the flags word and returns the element count actually transferred, (total - remaining) / a2; a completed request returns the requested count a3.
    // CALCULATION: Compute the requested byte total as a3 * a2 into v4, v6 and v14. [function:0x0058806E, source:raw]
    // GUARD: If the requested byte total a3 * a2 is zero, return 0 immediately. [function:0x0058806E, source:raw]
    // ASSIGNMENT: Select the buffer size: when the flags word at a4[3] has the buffered-stream bits ((flags & 0x10C) != 0) use the buffer size at a4[6] (a4+24), otherwise default to 4096. [source:raw]
    // LOOP: Main read loop; each iteration first tries to drain buffered bytes, then either refills per character or takes the direct-read path. [function:0x0058806E, source:raw]
    // GUARD: When the stream is buffered (flags & 0x10C) and the buffered byte count at a4[1] is nonzero, drain min(current need, buffered count) buffered bytes into a1 via MemoryCopy_cc00(a1, *a4, take). [callee:0x0058CC00, source:raw]
    // ASSIGNMENT: After draining: subtract the copied count from the buffered count at a4[1], advance the read pointer at a4[0] and the destination a1, and decrement the remaining byte total v14. [callee:0x0058CC00, source:raw]
    // GUARD: If the current need v6 is >= the buffer size v15, break out to the direct-read path (the request is too large for per-character buffering). [function:0x0058806E, source:raw]
    // CALL: Refill one character: v13 = sub_58C255(a4), the filbuf-style underflow refill for the stream. [callee:0x0058C255, source:raw]
    // GUARD: If sub_58C255 returns -1, the read failed: return the partial element count (v4 - v14) / a2. [callee:0x0058C255, source:raw]
    // ASSIGNMENT: Store the refilled character into a1, advance a1, decrement the remaining byte total v14, and refresh the buffer size from a4[6]. [callee:0x0058C255, source:raw]
    // GUARD: If the remaining byte total v14 reached zero, the request is complete: return the requested element count a3. [function:0x0058806E, source:raw]
    // ASSIGNMENT: Set the current need v6 = remaining byte total v14 and continue the loop. [source:raw]
    // CALCULATION: Direct-read path: compute v11 = v6, rounded down to a multiple of the buffer size when the buffer size is nonzero. [source:raw]
    // CALL: Read from the OS file handle at a4[4] (a4+16): v12 = sub_58C9B4(*(_DWORD *)(a4 + 16), a1, v11). [callee:0x0058C9B4, source:raw]
    // GUARD: If sub_58C9B4 returns 0, set the EOF flag (OR 0x10 into the flags word at a4[3]) and return the partial element count (v4 - v14) / a2. [callee:0x0058C9B4, source:raw]
    // ASSIGNMENT: If sub_58C9B4 returns a positive count, subtract it from the remaining byte total v14, advance a1, and loop. [callee:0x0058C9B4, source:raw]
    // GUARD: If sub_58C9B4 returns -1, set the error flag (OR 0x20 into the flags word at a4[3]) and return the partial element count (v4 - v14) / a2. [callee:0x0058C9B4, source:raw]
    // RETURN: All partial returns report the number of elements transferred, (v4 - v14) / a2; a completed transfer returns a3. [function:0x0058806E, source:raw]
    // UNKNOWN: Context: called by ThreadSafeReadWrapper (0x0058803F), which holds the stream lock across this call; this function is the actual buffered read implementation. [caller:0x0058803F, source:raw]

    // Conservative worker pseudocode:
    //   unsigned int BufferedFileRead(char *a1, unsigned int a2, unsigned int a3, FILE *a4) {
    //     total = a3 * a2;
    //     remaining = a3 * a2;
    //     need = a3 * a2;
    //     if (!total) return 0;
    //     if (*(WORD *)(a4 + 12) & 0x10C) bufsize = *(DWORD *)(a4 + 24); else bufsize = 4096;
    //     while (1) {
    //       if (*(WORD *)(a4 + 12) & 0x10C) {
    //         avail = *(DWORD *)(a4 + 4);
    //         if (avail) {
    //           take = need < avail ? need : avail;
    //           MemoryCopy_cc00(a1, *(DWORD *)a4, take);
    //           remaining -= take;
    //           *(DWORD *)(a4 + 4) -= take;
    //           *(DWORD *)a4 += take;
    //           a1 += take;
    //           goto next;
    //         }
    //       }
    //       if (need >= bufsize) break;
    //       c = sub_58C255(a4);
    //       if (c == -1) return (total - remaining) / a2;
    //       *a1++ = c;
    //       remaining -= 1;
    //       bufsize = *(DWORD *)(a4 + 24);
    //     next:
    //       if (!remaining) return a3;
    //       need = remaining;
    //     }
    //     n = need;
    //     if (bufsize) n = need - need % bufsize;
    //     r = sub_58C9B4(*(DWORD *)(a4 + 16), a1, n);
    //     if (!r) { *(DWORD *)(a4 + 12) |= 0x10; return (total - remaining) / a2; }
    //     if (r != -1) { remaining -= r; a1 += r; goto next; }
    //     *(DWORD *)(a4 + 12) |= 0x20;
    //     return (total - remaining) / a2;
    //   }
    // UNRESOLVED: The exact meaning of a1/a2/a3 is inferred as destination / element size / element count (fread-style); the parameter roles are not stated in the packet.
    // UNRESOLVED: The sub_58C9B4 read contract beyond returning -1 / 0 / positive is not evidenced here.
    // UNRESOLVED: The descriptor owner (CRT FILE vs a custom stream object) is not established by this packet.
}
