// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A01E
// Canonical corpus name: FileOffsetPositionValidation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileOffsetPositionValidation_0059a01e.c

void UnknownObject::PutbackOrValidateCharWithStreamRead()
{
    // Validates a character (a2) for putback or output against an encoding-table length tracked via the pointer at this+0x1C. On the table-matching putback path it adjusts the offset pointer and returns the character (or 0 for the end sentinel 0xFFFF). Otherwise, when an output device is present at this+0x50, it either validates a backward buffer scan and truncates the stream (copying this+0x3C into this+0x40) or writes the byte through StreamReadWrapperWithLockUnlock. Returns the character on success and -1 on failure.
    // CALCULATION: Reads v3 as the value at offset 0 of the structure pointed to by this+0x1C; interpreted as the encoding-table length used by the putback validation. [field:this:0x0000001C, field:*(this+0x1C):0x00000000, source:raw]
    // GUARD: Enters the encoding-table path only when v3 is non-zero and the putback state value at offset 0 of the pointer at this+0xC is below v3. [field:this:0x0000000C, field:*(this+0xC):0x00000000, source:raw]
    // GUARD: Matches the putback when a2 equals 0xFFFF (end sentinel) or when the byte at v3 - 2 equals a2. [source:raw]
    // CALL: Calls PointerOffsetAdjuster(this) on the matched putback path, adjusting the object's offset/position state. [callee:0x0059A407, source:raw]
    // RETURN: Returns a2 when it is not 0xFFFF, otherwise returns 0; the putback of the matched character or the end-sentinel value. [function:0x0059A01E, source:raw]
    // GUARD: Output path requires a non-null output device at this+0x50 and a character (v4) that is not 0xFFFF; otherwise the failure return -1 is taken. [field:this:0x00000050, source:raw]
    // GUARD: When the stream buffer pointer at this+0x38 is set, dereference the buffer pointer stored at this+0x44 and read its capacity v8 at offset 8. [field:this:0x00000038, field:this:0x00000044, field:*(this+0x44):0x00000008, source:raw]
    // GUARD: Proceeds with the backward scan only when the buffer capacity v8 is non-zero. [field:*(this+0x44):0x00000008, source:raw]
    // CALL: Calls BufferBoundaryMarkerCheckSet on the stream buffer pointer stored at this+0x44 before scanning. [callee:0x00599534, field:this:0x00000044, source:raw]
    // GUARD: Runs CharByCharBackwardScanWithValidation over the buffered data (start at offset 4 of the stream buffer), the output device at this+0x50 and the capacity v8; the character is considered present when it returns non-zero. [callee:0x00599707, field:*(this+0x44):0x00000004, field:this:0x00000050, source:raw]
    // CALL: Calls BufferTruncationShrink(*(this+0x44), 0, 0xFFFFFFFF) to shrink the stream buffer after the backward validation succeeds. [callee:0x00599348, field:this:0x00000044, source:raw]
    // ASSIGNMENT: Copies the position/state value at this+0x3C into this+0x40, updating stream position tracking after the successful backward validation. [field:this:0x0000003C, field:this:0x00000040, source:raw]
    // RETURN: Returns a2 when the backward validation path consumed the character from the buffered stream. [function:0x0059A01E, source:raw]
    // RETURN: Returns -1 when the buffered path fails to validate the character. [function:0x0059A01E, source:raw]
    // CALL: When no buffered scan applies, writes the byte v4 to the output device at this+0x50 via StreamReadWrapperWithLockUnlock. [callee:0x0059BCD2, field:this:0x00000050, source:raw]
    // RETURN: Returns v4, or -1 when the device write returned 0xFFFF (failure). [function:0x0059A01E, source:raw]

    // Conservative worker pseudocode:
    //   v3 = **(this + 0x1C);
    //   if (v3 && **(this + 0xC) < v3) {
    //     if (a2 == 0xFFFF || *(v3 - 2) == a2) {
    //       PointerOffsetAdjuster(this);
    //       return a2 == 0xFFFF ? 0 : a2;
    //     }
    //   }
    //   if (*(this + 0x50) && v4 != 0xFFFF) {
    //     if (*(this + 0x38)) {
    //       v7 = *(this + 0x44);
    //       v8 = *(v7 + 8);
    //       if (v8) {
    //         BufferBoundaryMarkerCheckSet(*(this + 0x44));
    //         if (CharByCharBackwardScanWithValidation(*(v7 + 4), *(this + 0x50), v8)) {
    //           BufferTruncationShrink(*(this + 0x44), 0, 0xFFFFFFFF);
    //           *(this + 0x40) = *(this + 0x3C);
    //           return a2;
    //         }
    //       }
    //       return -1;
    //     }
    //     v6 = (StreamReadWrapperWithLockUnlock(v4, *(this + 0x50)) == 0xFFFF);
    //     return v6 ? -1 : v4;
    //   }
    //   return -1;
    // UNRESOLVED: The global dword_5B9C38 (0x005B9C38) is listed as a read global but does not appear in the raw function body; its role here is unknown.
    // UNRESOLVED: The prelabel cluster_copy identifies this as the structural twin of PutbackOrValidateCharWithCodecvt (00598fd4); the output path here writes through StreamReadWrapperWithLockUnlock rather than a direct file write.
    // UNRESOLVED: 0xFFFF is overloaded: it selects the end-of-putback path, disables the output path, and is the failure return from the device write; the exact enum semantics are not resolved.
    // UNRESOLVED: this+0x50 is treated by prior analysis as the output stream/device; the full object contract (encoding table, putback state and stream buffer) is DERIVED from the raw body, not independently confirmed.
}
