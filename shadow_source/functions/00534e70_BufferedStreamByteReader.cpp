// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00534E70
// Canonical corpus name: sub_534E70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_534E70_00534e70.c

void UnknownObject::BufferedStreamByteReader()
{
    // __thiscall single-byte reader for a buffered stream object. Returns the next byte from the in-memory buffer (advancing the cursor) while bytes remain; otherwise clears the TLS error slot, refills a 16 KB buffer from the underlying stream handle via ThreadSafeReadWrapper_803f, and returns the first byte. On a failed/empty refill it sets the EOF flag and, when a status byte in the stream object signals it, records error -1 in the error-code field. Returns -1 on EOF/error.
    // GUARD: If EOF flag this[15] (offset 0x3C) is non-zero, return -1 immediately. [field:this:0x0000003C]
    // GUARD: If remaining-bytes counter this[1] (offset 0x4) is non-zero, serve the next byte from the buffer without refilling. [field:this:0x00000004]
    // CALL: TLSOffsetGetter(): clear the primary TLS error slot to 0 before the read. [callee:0x0058AFCF]
    // CALL: ThreadSafeReadWrapper_803f(this[17], 1, 0x4000, this[16]): read up to 0x4000 bytes from stream handle (offset 0x44) into the buffer (offset 0x40); store the byte count returned into this[1]. [callee:0x0058803F, field:this:0x00000044, field:this:0x00000040, field:this:0x00000004]
    // GUARD: If the refill returned a non-zero byte count, consume from the buffer. [source:raw]
    // ASSIGNMENT: Reset the buffer cursor this[0] (offset 0x0) to the buffer start (stream handle value). [field:this:0x00000000]
    // CALCULATION: Decrement the remaining-bytes counter: --this[1] (offset 0x4). [field:this:0x00000004]
    // RETURN: Read one byte from the cursor this[0] (offset 0x0) and advance it. [field:this:0x00000000, source:raw]
    // STATE_TRANSITION: On empty/failed refill, set EOF flag this[15] (offset 0x3C) to 1. [field:this:0x0000003C]
    // GUARD: If the stream status byte at (buffer base + 12) has bit 0x20 set, record a read error. [field:this:0x00000040, source:raw]
    // ASSIGNMENT: Set error-code field this[14] (offset 0x38) to -1. [field:this:0x00000038]
    // RETURN: Return -1 on EOF or error. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_534E70(StreamCtx *this) {
    //     if (this[15]) return -1;
    //     if (this[1]) { --this[1]; return *(unsigned char *)(*this)++; }
    //     *TLSOffsetGetter() = 0;
    //     int got = ThreadSafeReadWrapper_803f(this[17], 1, 0x4000, this[16]);
    //     this[1] = got;
    //     if (got) { *this = this[17]; --this[1]; return *(unsigned char *)(*this)++; }
    //     this[15] = 1;
    //     if ((*(unsigned char *)(this[16] + 12) & 0x20) != 0) this[14] = -1;
    //     return -1;
    //   }
    // UNRESOLVED: Field 0x4C (this[19], allocator/uncompressed-size per prior analysis) is not referenced by this function's source.
    // UNRESOLVED: Meaning of the stream status bit 0x20 at (buffer base + 12) and the error-code field this[14] (offset 0x38) semantics are inferred, not proven.
    // UNRESOLVED: ThreadSafeReadWrapper_803f's own buffering/caching behavior that makes the byte-count semantics exact is not inspected.
    // UNRESOLVED: Buffer cursor reset this[0] = this[17] reuses the stream-handle slot as a pointer seed; exact buffer ownership is unresolved.
}
