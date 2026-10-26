// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00599ED6
// Canonical corpus name: sub_599ED6
// Owner: StreamWriter [DERIVED]
// Raw source: functions/sub_599ED6_00599ed6.c

void StreamWriter::StreamWriteToken16()
{
    // Writes a 16-bit token a2 into a buffered stream, returning the token on success, 0 when a2 is the 0xFFFF sentinel, or -1 on failure. Takes a fast in-memory path when the buffered byte count read through this+0x20 is non-zero and below the limit behind this+0x30, writing a2 through StreamBufferPointerAdjust. Otherwise, without a file handle at this+0x50 it fails fast; without the codec object at this+0x38 it falls back to ThreeStepStreamQuery against the file handle. The main path resets and expands the output buffer at this+0x44 (BufferTruncationShrink, BufferAppendWithMemset, BufferBoundaryMarkerCheckSet), invokes the virtual encode method at vtable slot +0x14 of the codec behind this+0x38, then reads back the consumed byte count with FileReadWrapperWithLock and returns a2 when the read-back matches.
    // GUARD: When a2 truncated to 16 bits equals 0xFFFF (sentinel), return 0 without writing. [source:raw]
    // CALCULATION: v4 = **(_DWORD**)(this+32): read the buffered byte count through the pointer chain stored at this+0x20. [field:this:0x00000020, field:*(this+0x20):0x00000000, source:raw]
    // GUARD: Take the in-memory fast path when v4 is non-zero and v4 < v4 + 2 * **(_DWORD**)(this+48) (fits within the capacity limit behind this+0x30). [field:this:0x00000030, field:*(this+0x30):0x00000000, source:raw]
    // CALL: StreamBufferPointerAdjust(this) returns the current write position and the 16-bit a2 is written there. [callee:0x0059A43C, source:raw]
    // RETURN: Return a2 after the in-memory write. [source:raw]
    // GUARD: Without a stream/file handle at this+0x50, return -1. [field:this:0x00000050, source:raw]
    // GUARD: When the codec object at this+0x38 is absent, use the direct ThreeStepStreamQuery fallback path. [field:this:0x00000038, source:raw]
    // CALL: ThreeStepStreamQuery(a2, *(this+0x50)) queries the stream; return a2 unless it reports 0xFFFF, in which case return -1. [callee:0x0059BBAF, field:this:0x00000050, source:raw]
    // CALL: BufferTruncationShrink(v6, 0, 0xFFFFFFFF) resets the output buffer object stored at this+0x44. [callee:0x00599348, field:this:0x00000044, source:raw]
    // CALL: BufferAppendWithMemset(buf, 8, 0) expands/initializes 8 bytes in the output buffer. [callee:0x005992EF, field:this:0x00000044, source:raw]
    // CALL: BufferBoundaryMarkerCheckSet(buf) validates/updates the buffer boundary marker before and after reading the saved buffer base v16 = v7[1] at buffer+0x4. [callee:0x00599534, field:*(this+0x44):0x00000004, source:raw]
    // CALCULATION: v16 = v7[1]: save the buffer base offset at buffer+0x4; v8[1] is re-read through a second boundary check. [field:*(this+0x44):0x00000004, source:raw]
    // CALL: Virtual encode/write method at vtable slot +0x14 of the codec object behind this+0x38, called with the token pointer &v17, the byte-pointer &v17+2, output pointer &v15, the buffer size, and the extension amount v16 + v7[2] when v16 is non-zero. [field:*(this+0x38):0x00000000, field:*(*(this+0x38)+0x0):0x00000014, field:this:0x00000038, field:*(this+0x44):0x00000004, field:*(this+0x44):0x00000008, source:raw]
    // GUARD: When the virtual call returns 1 and v15 still points at the local v17 (nothing consumed), return -1. [source:raw]
    // CALCULATION: v12 = v14 - v11[1]: compute the byte count to read back from the stream (result offset minus the buffer base at buffer+0x4). [field:*(this+0x44):0x00000004, source:raw]
    // CALL: FileReadWrapperWithLock(v13[1], 1, v12, *(this+0x50)) reads exactly v12 bytes back from the stream file handle. [callee:0x00588678, field:*(this+0x44):0x00000004, field:this:0x00000050, source:raw]
    // RETURN: Return a2 when the read-back length matched v12; otherwise return -1. [source:raw]
    // GUARD: When the virtual call returned 3 (v10 == 2 after the -1 adjustment), fall through to the ThreeStepStreamQuery result check. [source:raw]
    // CALL: ThreeStepStreamQuery(v17, *(this+0x50)) decides the final result: return a2 unless it reports 0xFFFF. [callee:0x0059BBAF, field:this:0x00000050, source:raw]

    // Conservative worker pseudocode:
    //   short StreamWriteToken16(void* this, int a2) {
    //     if ((short)a2 == 0xFFFF)
    //       return 0;
    //     v4 = **(int**)((char*)this + 0x20);
    //     if (v4 && v4 < v4 + 2 * **(int**)((char*)this + 0x30)) {
    //       *(short*)StreamBufferPointerAdjust(this) = a2;
    //       return a2;
    //     }
    //     if (!*(int*)((char*)this + 0x50))
    //       return -1;
    //     if (!*(int*)((char*)this + 0x38))
    //       return ThreeStepStreamQuery(a2, *(int*)((char*)this + 0x50)) == 0xFFFF ? -1 : a2;
    //     v6 = *(int**)((char*)this + 0x44);
    //     v17 = a2;
    //     BufferTruncationShrink(v6, 0, 0xFFFFFFFF);
    //     BufferAppendWithMemset(*(int**)((char*)this + 0x44), 8, 0);
    //     v7 = *(int**)((char*)this + 0x44);
    //     BufferBoundaryMarkerCheckSet(v7);
    //     v8 = *(int**)((char*)this + 0x44);
    //     v16 = v7[1];
    //     BufferBoundaryMarkerCheckSet(v8);
    //     v9 = (*(int (__thiscall **)(...))**(int**)((char*)this + 0x38) + 0x14)(
    //            *(int*)((char*)this + 0x38), (char*)this + 0x40, &v17,
    //            (char*)&v17 + 2, &v15, v8[1], v16 ? v16 + v7[2] : 0, &v14);
    //     if (v9 == 0 || (v9 == 1 && v15 != &v17)) {
    //       v11 = *(int**)((char*)this + 0x44);
    //       BufferBoundaryMarkerCheckSet(v11);
    //       v12 = v14 - v11[1];
    //       v13 = *(int**)((char*)this + 0x44);
    //       BufferBoundaryMarkerCheckSet(v13);
    //       if (FileReadWrapperWithLock(v13[1], 1, v12, *(int*)((char*)this + 0x50)) == v12)
    //         return a2;
    //       return -1;
    //     }
    //     if (v9 != 3)
    //       return -1;
    //     return ThreeStepStreamQuery(v17, *(int*)((char*)this + 0x50)) == 0xFFFF ? -1 : a2;
    //   }
    // UNRESOLVED: Global dword_5B9C38 is listed in the packet as a read global but is absent from the raw decompiled source; it may be reached indirectly through a callee.
    // UNRESOLVED: The virtual encode call at codec vtable slot +0x14 is indirect and its concrete target/address is unknown; it is not in the packet callee list.
    // UNRESOLVED: The owner type StreamWriter and the object at this+0x38 (codec) are DERIVED from behavior; the prelabel marks this function a structural twin of sub_598E9E (cluster_copy, DERIVED), which is not independently proven here.
    // UNRESOLVED: The meaning of the three virtual-call return codes (0, 1, 3) and the exact role of the this+0x40 pointer passed to the encode call are only partially resolved from control flow.
}
