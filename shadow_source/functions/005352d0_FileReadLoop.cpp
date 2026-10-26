// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005352D0
// Canonical corpus name: FileReadLoop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileReadLoop_005352d0.c

void UnknownObject::FileReadLoop()
{
    // Buffered file read driver. When the stream object is valid and its type byte at a1+92 equals 119, resets the buffer at a1+4 and repeatedly tops up a 0x4000-byte buffer, reads 1 byte through FileReadWrapperWithLock, then hands each chunk to sub_535E80 to parse it. Returns 1 (mapped to 0) when parsing reports more data pending, the parser status otherwise, -1 on a short read, or -2 when the stream type guard fails.
    // GUARD: Proceed only when the stream pointer is non-null and the type byte at a1+92 equals 119 (0x77, 'w'); otherwise return -2. [function:0x005352D0, source:raw]
    // ASSIGNMENT: Reset the buffered byte counter at a1+4 to 0 before the read loop. [function:0x005352D0, source:raw]
    // LOOP: While the buffer is not yet full (a1+16 != 0x4000), compute the remaining space as 0x4000 minus the current buffered byte count and attempt to fill it. [function:0x005352D0, source:raw]
    // CALL: Call FileReadWrapperWithLock with the file handle at a1+72, size 1, the remaining space, and the target buffer at a1+64; treat a short read as a fatal error. [callee:0x00588678, source:raw]
    // ASSIGNMENT: On a short read, set the status at a1+56 to -1 and return -1. [function:0x005352D0, source:raw]
    // ASSIGNMENT: On a successful fill, mark the buffer full by setting a1+16 to 0x4000 and record the file handle from a1+72 at a1+12. [function:0x005352D0, source:raw]
    // CALL: Call sub_535E80 with the stream and parse context; store its returned parse status at a1+56. [callee:0x00535E80, source:raw]
    // ASSIGNMENT: When the buffer is exactly full and parsing returns -5, coerce the stored status at a1+56 to 0. [function:0x005352D0, source:raw]
    // GUARD: Continue parsing while either the buffer still holds unread bytes (a1+16 non-zero) or parsing reports status 1 (more data available); stop when the stored status is 2 or higher. [function:0x005352D0, source:raw]
    // RETURN: Return 0 when the final status is 1, otherwise return the final stored status at a1+56. [function:0x005352D0, source:raw]

    // Conservative worker pseudocode:
    //   int FileReadLoop(stream, parse_context) {
    //     parsing_done = 0;
    //     if (stream && *(BYTE *)(stream + 92) == 119) {
    //       *(DWORD *)(stream + 4) = 0;
    //       for (;;) {
    //         buffered = *(DWORD *)(stream + 16);
    //         to_read = 0x4000 - buffered;
    //         if (buffered != 0x4000) {
    //           if (FileReadWrapperWithLock(*(DWORD *)(stream + 72), 1, to_read, *(DWORD *)(stream + 64)) != to_read) {
    //             *(DWORD *)(stream + 56) = -1;
    //             return -1;
    //           }
    //           *(DWORD *)(stream + 16) = 0x4000;
    //           *(DWORD *)(stream + 12) = *(DWORD *)(stream + 72);
    //         }
    //         if (!parsing_done) {
    //           status = sub_535E80(stream, parse_context);
    //           *(DWORD *)(stream + 56) = status;
    //           if (!to_read && status == -5)
    //             *(DWORD *)(stream + 56) = 0;
    //           parsing_done = *(DWORD *)(stream + 16) || *(DWORD *)(stream + 56) == 1;
    //           if (*(DWORD *)(stream + 56) < 2)
    //             continue;
    //         }
    //         return *(DWORD *)(stream + 56) != 1 ? *(DWORD *)(stream + 56) : 0;
    //       }
    //     }
    //     return -2;
    //   }
    // UNRESOLVED: Layout and meaning of the stream object (offsets a1+4/12/16/56/64/72/92 referenced only in source) are not formally classified in the packet fields list.
    // UNRESOLVED: Meaning of the parse status constants (-5, 1, 2+) from sub_535E80 is not derivable from this function alone.
}
