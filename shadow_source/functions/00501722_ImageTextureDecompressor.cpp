// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00501722
// Canonical corpus name: ImageTextureDecompressor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ImageTextureDecompressor_00501722.c

void UnknownObject::ImageTextureDecompressor()
{
    // State-machine image texture decoder protected by a setjmp/longjmp dispatch block. Decodes a streaming texture into a per-object pixel buffer, supporting format 50 (raw row copy) and format 22 (24-bit RGB unpacked from the stream into 16-bit pixels). Allocates the destination pixel buffer on first decode unless the palette-only flag at this+0x40 is set, in which case pixel decode is skipped.
    // CALL: Initialize the state-machine block by calling sub_51177C(v19) and storing its return value in v22; this function is entered from DirectXSurfaceFormatNegotiation. [callee:0x0051177C, caller:0x00502A15, source:raw]
    // ASSIGNMENT: Install the setjmp/longjmp recovery vtable: v19[0] = VTableDispatchWithLongjmp and v20 = nullsub_4. [global:0x005016E0, global:0x0051DFCA, source:raw]
    // GUARD: setjmp guard: Setjmp3MSVCJmpBufSave(v21, 0, v17); a nonzero result branches to the teardown/error label, skipping the decode body. [callee:0x0058A7EC, source:raw]
    // CALL: sub_50F632(&v22, 61, 424) initializes the dispatch state machine with state 61 and buffer capacity 424. [callee:0x0050F632, source:raw]
    // ASSIGNMENT: Allocate a new dispatch object via the state-machine allocator (v23)(&v22, 0, 36) and fill its vtable: entry 0 = 0, entry 1 = 0, entry 2 = nullsub_4, entry 3 = loc_5016FC, entry 4 = BufferPointerAdjust, entry 5 = AudioVideoDecodeSubbandLoop, entry 6 = nullsub_4, entry 7 = a2 (source pointer), entry 8 = a3 (destination). [global:0x005016FC, global:0x00501711, global:0x005114D5, global:0x0051DFCA, source:raw]
    // CALL: Start the state machine: StateMachineDispatch_f9ab(&v22, 1). [callee:0x0050F9AB, source:raw]
    // GUARD: Guard on the result of sub_50FC7D(); when it returns zero set v25 = 1 as a side-state flag. [callee:0x0050FC7D, source:raw]
    // ASSIGNMENT: Swap the dispatch thunk: v20 = VtableDispatchThunk. [global:0x00511686, source:raw]
    // CALL: Run the state machine to completion: StateMachineWithDispatch(&v22). [callee:0x0050FB3B, source:raw]
    // GUARD: Decoded-state guard: when v28 == 1 select the format 50 path, setting this[0] = 50 and this[0x30] = v26 (row width/stride). [field:this:0x00000000, field:this:0x00000030, source:raw]
    // GUARD: Palette flag guard: read this[0x40]; when non-zero the function skips pixel-buffer allocation and the decode loops entirely. [guard:2, field:this:0x00000040, source:raw]
    // ASSIGNMENT: Shared decode init: this[0x34] = 0, this[0xC] = width, this[0x10] = height, this[0x14] = 1. [field:this:0x00000034, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // CALL: When this[0x40] == 0: set this[0x38] = 1 and allocate the pixel buffer via OperatorNewNhMallocWrapper(height * width), storing the pointer in this[0x4]; on allocation failure return -2147024882. [field:this:0x00000038, field:this:0x00000004, callee:0x00587C03, source:raw]
    // LOOP: Format 50 (raw RGBA) path: when this[0] == 50, stream each row via StreamBufferReadStateMachine(&v22, v31, 1) and copy v26 bytes per row into the buffer, advancing the destination by v26 each row. [guard:1, field:this:0x00000000, callee:0x0050FAB7, source:raw]
    // LOOP: Format 22 (RGB unpack) path: when this[0] == 22, stream each row via StreamBufferReadStateMachine and convert each 3-byte RGB source tuple into a packed 16-bit pixel stored into the destination buffer. [guard:0, field:this:0x00000000, callee:0x0050FAB7, source:raw]
    // CALL: Finalize the decode: StateMachineDispatcher(&v22). [callee:0x0050F904, source:raw]
    // GUARD: Decoded-state guard: when v28 == 3 select the format 22 setup path, setting this[0] = 22 and this[0x30] = 4 * v26 (expanded row stride), then fall through to the shared decode init. [field:this:0x00000000, field:this:0x00000030, source:raw]
    // RETURN: Return 0 for a completed decode; the error label returns -2147467259; the buffer failure path returns -2147024882. [abi:lead, source:raw]
    // CALL: Teardown on every exit path: VTableDtorNullFields(&v22) frees the dispatch block before the return value is propagated. [callee:0x0050F6F2, source:raw]

    // Conservative worker pseudocode:
    //   int sub_501722(_DWORD *this, int a2, int a3) {
    //     v22 = sub_51177C(v19);
    //     v19[0] = VTableDispatchWithLongjmp; v20 = nullsub_4;
    //     if (Setjmp3MSVCJmpBufSave(v21, 0, v17)) goto fail;
    //     sub_50F632(&v22, 61, 424);
    //     obj = (v23)(&v22, 0, 36);
    //     obj[8] = a3; obj[2] = nullsub_4; obj[3] = loc_5016FC;
    //     obj[4] = BufferPointerAdjust; obj[5] = AudioVideoDecodeSubbandLoop; obj[6] = nullsub_4;
    //     obj[1] = 0; obj[0] = 0; obj[7] = a2;
    //     StateMachineDispatch_f9ab(&v22, 1);
    //     if (!sub_50FC7D()) v25 = 1;
    //     v20 = VtableDispatchThunk; StateMachineWithDispatch(&v22);
    //     if (v28 == 1)  { this[0] = 50; this[0x30] = v26; }
    //     else if (v28 == 3) { this[0] = 22; this[0x30] = 4 * v26; }
    //     else goto fail;
    //     this[0x34] = 0;
    //     if (this[0x40] == 0) {
    //       this[0xC] = v26; this[0x10] = v27; this[0x14] = 1; this[0x38] = 1;
    //       this[0x4] = OperatorNewNhMallocWrapper(v27 * v26);
    //       if (!this[0x4]) return -2147024882;
    //       if (this[0] == 50) { for rows: StreamBufferReadStateMachine(&v22, v31, 1); copy v26 bytes per row; }
    //       else if (this[0] == 22) { for rows: StreamBufferReadStateMachine(&v22, v31, 1); unpack 3-byte RGB to 16-bit pixels; }
    //       StateMachineDispatcher(&v22);
    //     }
    //     return 0;
    //   fail:
    //     VTableDtorNullFields(&v22);
    //     return -2147467259;
    //   }
    // UNRESOLVED: Meaning of the decoded state value v28 beyond the two branches (1 and 3) is decoder-internal.
    // UNRESOLVED: this+0x40 is read but never written in this function; the writer that controls the palette-only path is unknown.
    // UNRESOLVED: Exact units of v26/v27 (width/height versus byte quantities) differ between branches and are not confirmed.
}
