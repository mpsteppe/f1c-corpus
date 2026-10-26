// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00534F90
// Canonical corpus name: BufferedFileReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferedFileReader_00534f90.c

void UnknownObject::ReadBufferedFileBytes()
{
    // Buffered file read: reads up to a3 bytes from the buffered file stream a1 into the caller buffer a2, refilling the internal 0x4000-byte buffer from the OS handle via ThreadSafeReadWrapper_803f when exhausted, draining buffered bytes first, then direct-reading any remainder. Tracks bytes read at a1+8 and a1+20, sets the EOF flag at a1+60 when nothing was read, and returns the number of bytes read. Early returns -2 for a non-read stream (mode byte a1+92 != 114 'r'), -1 on error states, 0 at EOF.
    // GUARD: Reject invalid streams: a1 null or the mode byte at a1+92 not equal to 114 ('r') returns -2. [source:raw]
    // GUARD: State gate on a1+56: -3 or -1 returns -1 (error), 1 returns 0 (EOF). [source:raw]
    // ASSIGNMENT: Initialize the transfer: dest cursor a1+12 = a2 and remaining count a1+16 = a3. [source:raw]
    // LOOP: Main read loop that runs while bytes remain; exits when the stream flag at a1+88 is set, on EOF, or when a1+16 reaches 0. [source:raw]
    // GUARD: Break the loop when the stream control flag at a1+88 is non-zero. [source:raw]
    // CALL: Refill the buffer: clear the TLS error slot via TLSOffsetGetter, then ThreadSafeReadWrapper_803f(a1+68, 1, 0x4000, a1+64) into a1+4. [callee:0x0058803F, callee:0x0058AFCF]
    // GUARD: EOF handling: when the refill returns 0, set a1+60 = 1, and if the backend descriptor at a1+64 has text-mode EOF bit 0x20 in byte 12, set state a1+56 = -1. [source:raw]
    // ASSIGNMENT: Reset the buffer cursor: a1+0 = a1+68 (the OS handle) after a successful refill. [source:raw]
    // CALL: Advance the parse/read state with sub_5357E0(a1, 0); store its result into state a1+56. [callee:0x005357E0]
    // CALCULATION: When sub_5357E0 returns 1 (end of data), compute bytes consumed so far as sub_536E90(a1+12 - v4) and store it at a1+76. [callee:0x00536E90]
    // CALL: Verify integrity: when F_4BitFieldPack(a1) does not equal the stored count a1+76, set state a1+56 = -3 and finish. [callee:0x00535560]
    // CALL: Finalize the stream record with sub_534D50(a1); bail if it leaves state a1+56 non-zero. [callee:0x00534D50]
    // CALL: Position bookkeeping: preserve a1+8 and a1+20 around ArithmeticComparison_5620(a1), then restore them and recompute a1+76 as sub_536E90(0). [callee:0x00535620]
    // CALCULATION: Drain buffered bytes: copy min(a1+4, a1+16) bytes from the buffer at a1+0 into the dest at a1+12; advance cursor a1+0, dest a1+12, remaining a1+16 and reduce a1+4. [source:raw]
    // CALL: Direct-read the remainder: a1+16 is decremented by ThreadSafeReadWrapper_803f(dest, 1, a1+16, a1+64). [callee:0x0058803F]
    // CALCULATION: Account the transfer: v22 = a3 - a1+16 bytes read, add v22 to position fields a1+8 and a1+20, and set EOF flag a1+60 = 1 when v22 is 0. [source:raw]
    // RETURN: Return v22 (bytes actually read) on the normal path; the no-remaining path returns a3 - a1+16. [source:raw]

    // Conservative worker pseudocode:
    //   int ReadBufferedFileBytes(BufferedFile* f, char* dst, int n) {
    //     if (!f || f->mode != 'r') return -2;
    //     int st = f->state;                 // a1+56
    //     if (st == -3 || st == -1) return -1;
    //     if (st == 1) return 0;
    //     f->dst = dst; f->remaining = n;   // a1+12, a1+16
    //     int total = 0;
    //     while (1) {
    //       int buffered = f->buffered;     // a1+4
    //       if (f->flag) break;             // a1+88
    //       if (!buffered && !f->eof) {     // a1+60
    //         *TLSOffsetGetter() = 0;
    //         f->buffered = ThreadSafeReadWrapper_803f(f->handle, 1, 0x4000, f->backend);
    //         if (!f->buffered) { f->eof = 1; if (*(BYTE*)(f->backend+12) & 0x20) { f->state = -1; break; } }
    //         f->cur = f->handle;
    //       }
    //       f->state = sub_5357E0(f, 0);
    //       if (f->state == 1) {
    //         f->consumed = sub_536E90(f->dst - dst);
    //         if (F_4BitFieldPack(f) != f->consumed) { f->state = -3; break; }
    //         F_4BitFieldPack(f); sub_534D50(f); if (f->state) break;
    //         int p = f->pos, q = f->acc; ArithmeticComparison_5620(f); f->pos = p; f->acc = q;
    //         f->consumed = sub_536E90(0);
    //       }
    //       if (f->state || f->eof || !f->remaining) break;
    //     }
    //     int avail = f->buffered;
    //     if (avail > f->remaining) avail = f->remaining;
    //     if (avail) { memcpy(f->dst, f->cur, avail); f->cur += avail; f->dst += avail; f->remaining -= avail; f->buffered -= avail; }
    //     if (f->remaining) f->remaining -= ThreadSafeReadWrapper_803f(f->dst, 1, f->remaining, f->backend);
    //     int got = n - f->remaining;
    //     f->pos += got; f->acc += got;
    //     if (!got) f->eof = 1;
    //     return got;
    //   }
    // UNRESOLVED: The precise role of sub_5357E0 (state advance, possibly token/record parse) is not established from this function alone.
    // UNRESOLVED: The meaning of F_4BitFieldPack's integrity comparison and the semantics of state values -3 and the count at a1+76 are DERIVED from context.
    // UNRESOLVED: The stream-flag semantics of a1+88 (loop break) and the backend descriptor layout at a1+64 are inferred, not proven.
}
