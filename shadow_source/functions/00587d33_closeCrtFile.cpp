// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587D33
// Canonical corpus name: MSVCCRTFileClose
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MSVCCRTFileClose_00587d33.c

void UnknownObject::closeCrtFile()
{
    // MSVC CRT file-close internals. When the state flags at a1+0xC have any of bits 0x83 set (file open/writeable state), it flushes buffered writes via BufferFlushWrite, releases the stream lock via sub_58C411, closes the OS file handle at a1+0x10 through sub_58C331, and on success frees the heap-allocated buffer pointer stored at a1+0x1C via sub_58AA6F, clearing it to 0. On failure the default -1 is returned. The state flags at a1+0xC are unconditionally reset to 0 before returning.
    // ASSIGNMENT: Initialize v1 to -1 as the default close result. [source:raw]
    // GUARD: Guard on the file state at a1+0xC: (flags & 0x83) != 0 selects the open-file close path. [field:this:0x0000000C]
    // CALL: BufferFlushWrite(a1) flushes any buffered writes to the OS before the handle is closed. [callee:0x0058A05A]
    // CALL: sub_58C411(a1) releases the stream lock held on the file object. [callee:0x0058C411]
    // GUARD: Guard on the OS handle at a1+0x10: sub_58C331(handle) must return >= 0 for the close to succeed; otherwise v1 stays -1. [field:this:0x00000010, callee:0x0058C331]
    // CALL: sub_58AA6F(a1+0x1C) frees the heap-allocated internal buffer when the pointer is non-zero. [callee:0x0058AA6F, field:this:0x0000001C]
    // ASSIGNMENT: Clear the buffer pointer at a1+0x1C to 0 after freeing it. [field:this:0x0000001C]
    // ASSIGNMENT: Reset the file state flags at a1+0xC to 0 unconditionally before returning. [field:this:0x0000000C]
    // RETURN: Return v1: the OS close result, or -1 when the file was not in an open state or the close failed. [function:0x00587D33, source:raw]
    // CALL: Invoked by the locked close wrapper FileCloseWithLock. [caller:0x00587D02]

    // Conservative worker pseudocode:
    //   int closeCrtFile(int stream) {
    //     int result = -1;
    //     if ((*(byte*)(stream + 12) & 0x83) != 0) {
    //       result = BufferFlushWrite(stream);
    //       sub_58C411(stream);
    //       if (sub_58C331(*(dword*)(stream + 16)) >= 0) {
    //         if (*(dword*)(stream + 28)) {
    //           sub_58AA6F(*(dword*)(stream + 28));
    //           *(dword*)(stream + 28) = 0;
    //         }
    //       } else {
    //         result = -1;
    //       }
    //     }
    //     *(dword*)(stream + 12) = 0;
    //     return result;
    //   }
    // UNRESOLVED: The exact meaning of each flag bit in 0x83 at a1+0xC is not decomposed here beyond 'open/writeable state'.
    // UNRESOLVED: The object type of the file stream is unknown; offsets 0xC, 0x10 and 0x1C are treated as state, OS handle and buffer pointer respectively.
}
