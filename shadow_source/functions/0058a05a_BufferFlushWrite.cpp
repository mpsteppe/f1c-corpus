// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A05A
// Canonical corpus name: BufferFlushWrite
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferFlushWrite_0058a05a.c

void UnknownObject::BufferFlushWrite()
{
    // Flushes a buffered file writer to the OS file handle. When the buffer holds data and the file is in write mode (flags & 3 == 2) and initialized (flags & 0x108 != 0), it writes the buffered bytes (write pointer minus data start) to the OS handle via sub_58E22B. On full success the error flag is cleared; on partial/failed write an error flag is set and -1 returned. Buffer pointers are reset (field 0x4 = 0, field 0x0 = data start) regardless of outcome.
    // GUARD: Proceed only when file state flags indicate write mode ((flags & 3) == 2) and initialization ((flags & 0x108) != 0); otherwise skip the flush and fall through to pointer reset. [field:this:0x0000000C, source:raw]
    // GUARD: Proceed with the OS write only when buffered data exists, i.e. write pointer (field 0x0) is greater than the buffer data start pointer (field 0x8). [field:this:0x00000000, field:this:0x00000008]
    // CALCULATION: Byte count to write = write pointer (field 0x0) minus buffer data start pointer (field 0x8). [field:this:0x00000000, field:this:0x00000008]
    // CALL: Call sub_58E22B with the OS file handle (field 0x10), the buffer data start pointer (field 0x8) and the computed byte count; success requires the returned count to equal the requested count. [callee:0x0058E22B, field:this:0x00000010, field:this:0x00000008]
    // STATE_TRANSITION: On a successful full write, if the error flag bit 0x80 is set, clear bit 0x2 in the low byte of the file state flags. [field:this:0x0000000C, source:raw]
    // STATE_TRANSITION: On a failed or partial write, set error flag bit 0x20 in the file state flags and mark the result as failure (-1). [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Reset the buffer state after the flush attempt: clear the buffer start pointer (field 0x4 = 0) and set the write pointer (field 0x0) back to the buffer data start pointer (field 0x8). [field:this:0x00000004, field:this:0x00000000, field:this:0x00000008]
    // RETURN: Return 0 when the flush succeeded or was skipped (no buffered data / not write mode), and -1 when the OS write failed. [source:raw, function:0x0058A05A]

    // Conservative worker pseudocode:
    //   int BufferFlushWrite(BufferFile* self) {
    //     int result = 0;
    //     if ((self->flags & 3) == 2 && (self->flags & 0x108) != 0) {
    //       byte* dataStart = self->dataStart;
    //       if (self->writePtr > dataStart) {
    //         DWORD count = self->writePtr - dataStart;
    //         if (write_os(self->handle, dataStart, count) == count) {
    //           if (self->flags & 0x80) self->flags &= 0xFD;
    //         } else { self->flags |= 0x20; result = -1; }
    //       }
    //     }
    //     self->startPtr = 0;
    //     self->writePtr = self->dataStart;
    //     return result;
    //   }
}
