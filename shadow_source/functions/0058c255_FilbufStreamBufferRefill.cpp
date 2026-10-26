// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058C255
// Canonical corpus name: sub_58C255
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58C255_0058c255.c

void UnknownObject::FilbufStreamBufferRefill()
{
    // CRT _filbuf-style stream buffer refill on read underflow. Operates on a FILE descriptor array (a1[0]=read pointer, a1[1]=byte count, a1[2]=buffer base, a1[3]=flags, a1[4]=OS file handle, a1[6]=buffer size). Rejects invalid or write-mode streams, allocates a buffer via MemoryAllocatorInit when needed, reads up to a1[6] bytes from the handle via sub_58C9B4, sets EOF (16) or error (32) flags on failure, copies text-mode descriptor state from unk_5E7898 or the dword_8D4920 descriptor table, auto-grows a default 512-byte buffer to 4096, and returns the first buffered byte while advancing the read pointer.
    // GUARD: Read stream flags from a1[3] (this+0xC); when (flags & 0x83) == 0 or (flags & 0x40) != 0 the stream is unusable for refill, so return -1. [field:this:0x0000000C, source:raw]
    // STATE_TRANSITION: When (flags & 2) is set, OR 0x20 into the flags (EOF-style state), store them back, and return -1. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Set the low 'buffer active' bit by storing flags | 1 back into a1[3] (this+0xC). [field:this:0x0000000C, source:raw]
    // GUARD: When the 16-bit flags test (flags & 0x10C) is nonzero the buffer is already established, so set the read pointer *a1 (this+0x0) to the buffer base a1[2] (this+0x8); otherwise initialize the buffer via MemoryAllocatorInit(a1). [field:this:0x00000000, field:this:0x00000008, callee:0x005957BD, source:raw]
    // CALL: Read bytes from the OS handle a1[4] (this+0x10) into the buffer base a1[2] (this+0x8) requesting a1[6] (this+0x18) bytes via sub_58C9B4, and store the returned count into a1[1] (this+0x4). [callee:0x0058C9B4, field:this:0x00000010, field:this:0x00000008, field:this:0x00000018, field:this:0x00000004, source:raw]
    // GUARD: When the read returns 0 or 0xFFFFFFFF (-1), OR 32 (error) or 16 (EOF) into the flags this+0xC, clear the count this+0x4 to 0, and return -1. [field:this:0x0000000C, field:this:0x00000004, source:raw]
    // GUARD: When (flags & 0x82) == 0, resolve the text-mode descriptor: for handle this+0x10 == 0xFFFFFFFF use the default descriptor unk_5E7898, otherwise index dword_8D4920[handle >> 5] + 36 * (handle & 0x1F); when descriptor[4] & 0x82 == 0x82, OR 0x20 into the high flags byte and store back to this+0xC. [global:0x005E7898, global:0x008D4920, field:this:0x00000010, field:this:0x0000000C, guard:0, source:raw]
    // ASSIGNMENT: When the buffer size this+0x18 equals the default 512 and (flags & 8) is set while the flags byte-1 & 4 bit is clear, grow the buffer size to 4096. [field:this:0x00000018, field:this:0x0000000C, guard:1, source:raw]
    // RETURN: Store the remaining byte count this+0x4 as v2 - 1, return the buffered byte value at the current read pointer (obj), and advance the read pointer this+0x0 by 1. [field:obj:0x00000000, field:this:0x00000000, field:this:0x00000004, source:raw]
    // RETURN: Function 0x0058C255 is the per-character underflow refill handler invoked by FileReadUntilNewline, sub_58806E, StreamGetcWithUnderflowHandler, BufferedByteReader, and sub_59BE0C. [caller:0x00587CA0, caller:0x0058806E, caller:0x00589FCC, caller:0x0058EF2E, caller:0x0059BE0C, function:0x0058C255, source:raw]

    // Conservative worker pseudocode:
    //   int FilbufStreamBufferRefill(FILE *f) {
    //     flags = f[3];
    //     if ((flags & 0x83) == 0 || (flags & 0x40)) return -1;
    //     if (flags & 2) { f[3] = flags | 0x20; return -1; }
    //     f[3] = flags | 1;
    //     if (f[3] & 0x10C) f[0] = f[2]; else MemoryAllocatorInit(f);
    //     n = ReadFile(f[4], f[2], f[6]);
    //     f[1] = n;
    //     if (n == 0 || n == 0xFFFFFFFF) {
    //       f[3] |= (n ? 32 : 16); f[1] = 0; return -1;
    //     }
    //     if ((f[3] & 0x82) == 0) {
    //       desc = (f[4] == 0xFFFFFFFF) ? &unk_5E7898 : &dword_8D4920[f[4] >> 5][f[4] & 0x1F];
    //       if ((desc[4] & 0x82) == 0x82) f[3] |= 0x20 << 8;
    //     }
    //     if (f[6] == 512 && (f[3] & 8) && !(f[3] & 0x400)) f[6] = 4096;
    //     f[1] = n - 1;
    //     c = *f[0];
    //     f[0] += 1;
    //     return c;
    //   }
    // UNRESOLVED: The exact text-mode descriptor fields beyond descriptor[4] (flag byte at +4) and their meaning are not recoverable from this function alone.
    // UNRESOLVED: The high flags byte 0x20 set from the descriptor (and its byte-1 & 4 companion bit) is written here but consumed by other stream functions.
    // UNRESOLVED: The auto-grow to 4096 applies only when the buffer size is exactly the 512 default; other buffer sizes are left untouched.
}
