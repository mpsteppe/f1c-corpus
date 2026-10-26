// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005397A0
// Canonical corpus name: ChecksummedBufferWriter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ChecksummedBufferWriter_005397a0.c

void UnknownObject::WriteChecksummedBytes()
{
    // Writes a checksummed byte sequence into a growable buffer. First flushes the target via UnicodeBufferFlusher(a1), then sets a mode/count field at this + 5799 to 8. When a4 is set it appends a 4-byte integrity trailer for a3 (low byte, high byte, one's-complement low, one's-complement high) to the buffer at base v5[2] plus cursor v5[5]. When a3 is nonzero it then copies a3 bytes from a2 into the same buffer, advancing the cursor per byte, and returns a3 (0 after a full copy).
    // CALL: UnicodeBufferFlusher(a1) flushes the target stream/buffer before writing [callee:0x00539720, source:raw]
    // ASSIGNMENT: Sets the field at this + 5799 to 8 (mode or pending-count marker) [function:0x005397A0, source:raw]
    // GUARD: When a4 is nonzero, appends a 4-byte checksum trailer for a3 (low, high, one's-complement low, one's-complement high) at base v5[2] + cursor v5[5] and advances the cursor [source:raw]
    // GUARD: When a3 is nonzero, enters the payload copy loop over a2 [source:raw]
    // LOOP: Copies a3 bytes from a2 into the buffer at base v5[2] + cursor v5[5], advancing the cursor one per byte until result reaches 0 [source:raw]
    // RETURN: Returns a3, which is 0 after a full payload copy (or a3 unchanged when the copy guard is skipped) [function:0x005397A0, source:raw]
    // CALL: Invoked by BitstreamWriteBits for checksummed payload writes [abi:lead, caller:0x00537F30]

    // Conservative worker pseudocode:
    //   UnicodeBufferFlusher(a1);
    //   *(dword*)((char*)v5 + 5799) = 8;
    //   if (a4) {
    //     append(a3 lo); append(a3 hi);
    //     append(~a3 lo); append(~a3 hi);
    //   }
    //   while (a3--) *bufferbase + cursor++ = *a2++;
    //   return a3;
    // UNRESOLVED: The pointer v5 arrives uninitialized in the decompiled body (held in ecx) and is treated as this; its exact type and the meaning of the field at this + 5799 are not defined
    // UNRESOLVED: The buffer base/length fields (v5[2] and v5[5]) are untyped; no capacity or bounds check is visible in this packet
    // UNRESOLVED: Whether the written byte stream is genuine UTF-16/Unicode or a byte protocol named after the flusher is unresolved
}
