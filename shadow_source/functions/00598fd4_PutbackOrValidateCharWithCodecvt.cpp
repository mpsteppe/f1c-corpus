// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598FD4
// Canonical corpus name: CharValidationAgainstEncodingTableWithLocaleFall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CharValidationAgainstEncodingTableWithLocaleFall_00598fd4.c

void UnknownObject::PutbackOrValidateCharWithCodecvt()
{
    // Validates a character (a2) for putback or output against an encoding-table length tracked via the pointer at this+0x1C. On the table-matching putback path it bumps the reference count and returns the character (or 0 for the end sentinel). Otherwise, when an output device is present at this+0x50, it either validates a backward buffer scan and truncates the stream (copying this+0x3C into this+0x40) or writes the raw byte through FileIOWrapperWithLock. Returns the character on success and -1 on failure.
    // CALCULATION: Reads v3 as the value at offset 0 of the structure pointed to by this+0x1C; interpreted as the encoding-table length/size used by the putback validation. [field:this:0x0000001C, field:*(this+0x1C):0x00000000, source:raw]
    // GUARD: Enters the encoding-table path only when v3 is non-zero and the putback state value at offset 0 of the pointer at this+0xC is below v3. [field:this:0x0000000C, field:*(this+0xC):0x00000000, source:raw]
    // GUARD: Matches the putback when a2 equals -1 (end sentinel) or when the byte at v3 - 1 (last table position) equals a2. [source:raw]
    // CALL: Calls RefCountIncDec(this) on the matched putback path, adjusting the object's reference state. [callee:0x00599465, source:raw]
    // RETURN: Returns a2 when it is not -1, otherwise returns 0; the putback of the matched character or the end-sentinel sentinel value. [function:0x00598FD4, source:raw]
    // GUARD: Output path requires a non-null output device at this+0x50 and a character (v4) that is not -1. [field:this:0x00000050, source:raw]
    // GUARD: When the stream buffer pointer at this+0x38 is set, dereference the buffer pointer stored at this+0x44 and read its capacity v7 at offset 8. [field:this:0x00000038, field:this:0x00000044, field:*(this+0x44):0x00000008, source:raw]
    // GUARD: Proceeds with the backward scan only when the buffer capacity v7 is non-zero. [field:*(this+0x44):0x00000008, source:raw]
    // CALL: Calls BufferBoundaryMarkerCheckSet on the stream buffer pointer stored at this+0x44 before scanning. [callee:0x00599534, field:this:0x00000044, source:raw]
    // GUARD: Runs CharByCharBackwardScanWithValidation over the buffered data (start at offset 4 of the stream buffer), the output device at this+0x50 and the capacity v7; the character is considered present when it returns non-zero. [callee:0x00599707, field:*(this+0x44):0x00000004, field:this:0x00000050, source:raw]
    // CALL: Calls BufferTruncationShrink(0, -1) to shrink the stream buffer after the backward validation succeeds. [callee:0x00599348, source:raw]
    // ASSIGNMENT: Copies the position/state value at this+0x3C into this+0x40, updating stream position tracking after the successful backward validation. [field:this:0x0000003C, field:this:0x00000040, source:raw]
    // RETURN: Returns a2 when the backward validation path consumed the character from the buffered stream. [function:0x00598FD4, source:raw]
    // CALL: When no buffered scan applies, writes the raw byte v4 to the output device at this+0x50 via FileIOWrapperWithLock and returns v4 when the write does not fail. [callee:0x0059685F, field:this:0x00000050, source:raw]
    // RETURN: Returns -1 when none of the putback or output paths accept the character. [function:0x00598FD4, source:raw]

    // Conservative worker pseudocode:
    //   v3 = **(this + 0x1C);
    //   if (v3 && **(this + 0xC) < v3) {
    //     if (a2 == -1 || *(v3 - 1) == a2) {
    //       RefCountIncDec(this);
    //       return a2 == -1 ? 0 : a2;
    //     }
    //   }
    //   if (*(this + 0x50) && a2 != -1) {
    //     if (*(this + 0x38)) {
    //       v6 = *(this + 0x44);
    //       v7 = *(v6 + 8);
    //       if (v7) {
    //         BufferBoundaryMarkerCheckSet(*(this + 0x44));
    //         if (CharByCharBackwardScanWithValidation(*(v6 + 4), *(this + 0x50), v7)) {
    //           BufferTruncationShrink(0, -1);
    //           *(this + 0x40) = *(this + 0x3C);
    //           return a2;
    //         }
    //       }
    //     } else if (FileIOWrapperWithLock(a2, *(this + 0x50)) != -1) {
    //       return a2;
    //     }
    //   }
    //   return -1;
    // UNRESOLVED: The global dword_5B9C38 (0x005B9C38) is read per the deterministic facts but does not appear in the raw function body; its role here is unknown.
    // UNRESOLVED: this+0x50 is treated by the prior analysis as the output stream/device; the full object contract (encoding table, putback state and stream buffer) is DERIVED from the raw body, not independently confirmed.
    // UNRESOLVED: The byte-sentinel -1 is overloaded: it selects the end-of-putback path, disables the output path, and is the failure return; the exact enum semantics are not resolved.
}
