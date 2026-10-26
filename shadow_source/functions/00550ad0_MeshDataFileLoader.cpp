// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00550AD0
// Canonical corpus name: MeshVertexIndexBufferLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MeshVertexIndexBufferLoader_00550ad0.c

void UnknownObject::MeshDataFileLoader()
{
    // Loads a mesh data file (or an embedded sub-block of a parent context a3) into the shared read buffer dword_8B8F30, parses the header into this+0x0 (flags), this+0x4 (scale, inverted to 1.0/scale), this+0x8 (dimension) and the name string at this+28, then parses either material blocks (flags bit 2, descriptor arrays of 12 and 8 bytes with 36-byte elements) or texture/animation blocks (flags bit 1, 44-byte descriptors with 32-byte frames) via ArithmeticComparison_a5c0 buffer reads. Returns 0 on success, -1 on a short read, freeing the temporary buffers on the way out.
    // GUARD: If the context a3 is present and the header byte at (a3+296) + ((a3+292)<<8) has bit 0x10 set, load the embedded sub-block; otherwise fall through to the file-based path. [source:raw]
    // ASSIGNMENT: Sub-block path: allocate dword_8B8F30 of the block size at +8 and dword_8B8F34 of the size at +12 via OperatorNewNhMallocWrapper. [global:0x008B8F30, global:0x008B8F34, callee:0x00587C03, source:raw]
    // CALL: Read the block into dword_8B8F34 via ThreadSafeReadWrapper_803f; on a short read free both temporary buffers and return -1. [callee:0x0058803F, callee:0x00587BCF, global:0x008B8F30, global:0x008B8F34]
    // CALL: Post-process the read block via sub_59B260(dword_8B8F34, size). [callee:0x0059B260, global:0x008B8F34]
    // CALCULATION: File path: query the file size at the current position via FileSizeQueryWrapper, seek to the end via sub_587F64(a2, 0, 2), compute the file length as the size delta, and seek back to the original position. [callee:0x0058ACE6, callee:0x00587F64, source:raw]
    // ASSIGNMENT: Allocate dword_8B8F30 for the full file length via OperatorNewNhMallocWrapper and read it via ThreadSafeReadWrapper_803f; on a short read free it and return -1. [callee:0x00587C03, callee:0x0058803F, callee:0x00587BCF, global:0x008B8F30]
    // ASSIGNMENT: Zero the read-position global dword_8B8F3C. [global:0x008B8F3C]
    // CALL: Parse the header from the shared buffer via ArithmeticComparison_a5c0: the 16-byte name block at this+28, the flags dword at this+0x0, the scale float at this+0x4 and the value at this+0x8; then invert the scale (this+0x4 = 1.0/scale) and process the name via sub_589901. [callee:0x0054A5C0, callee:0x00589901, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // GUARD: Material-block path: when flags at this+0x0 have bit 2 set, read the block count at this+0x14, allocate a 12-byte-element descriptor array via OperatorNewNhMallocWrapper, zero-initialize each element via StructZeroInit_93b0, and store the array at this+0x18. [callee:0x0054A5C0, callee:0x00587C03, callee:0x005593B0, field:this:0x00000000, field:this:0x00000014, field:this:0x00000018]
    // LOOP: For each material block, read its sub-entry count via ArithmeticComparison_a5c0, allocate a 2-dword sub-entry header array, zero-initialize each entry via DualFieldZeroInit, store it in the block element, then read per-sub-entry element counts and allocate and fill the 36-byte element arrays via ArithmeticComparison_a5c0. [callee:0x0054A5C0, callee:0x00587C03, callee:0x00550800, field:this:0x00000018, source:raw]
    // GUARD: Texture/animation path: else when flags at this+0x0 have bit 1 set, read the block count at this+0xC, allocate a 44-byte-element descriptor array via OperatorNewNhMallocWrapper, initialize each element via StructInitWithVtableZero, and store the array at this+0x10. [callee:0x0054A5C0, callee:0x00587C03, callee:0x005507E0, field:this:0x00000000, field:this:0x0000000C, field:this:0x00000010]
    // LOOP: For each texture/animation block, read the header region (32 bytes plus two dwords) via ArithmeticComparison_a5c0, allocate a 32-byte-element frame array, initialize each frame via sub_5507A0, read the frame data, then overwrite each frame float with index * scale (this+0x4); update the maximum sub-entry count at this+0x14. [callee:0x0054A5C0, callee:0x00587C03, callee:0x005507A0, field:this:0x00000010, field:this:0x00000014, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Texture path epilogue: set this+0x8 = (sub-entry count at this+0x14) * scale (this+0x4). [field:this:0x00000008, field:this:0x00000014, field:this:0x00000004, source:raw]
    // CALL: Free the temporary read buffers dword_8B8F30 and dword_8B8F34 via FreeWrapper_7bcf when they are set. [callee:0x00587BCF, global:0x008B8F30, global:0x008B8F34]
    // RETURN: Return 0 on success, or -1 when a read returned fewer bytes than requested. [source:raw]
    // CALL: Called by sub_5508A0. [caller:0x005508A0]

    // Conservative worker pseudocode:
    //   int MeshDataFileLoader(float* this, int handle, int ctx) {
    //       if (ctx && (*(BYTE*)(*(DWORD*)(ctx+296) + (*(DWORD*)(ctx+292)<<8)) & 0x10)) {
    //           DWORD* blk = (DWORD*)(*(DWORD*)(ctx+296) + (*(DWORD*)(ctx+292)<<8));
    //           DWORD blk_size = blk[3];
    //           dword_8B8F30 = OperatorNewNhMallocWrapper(blk[2]);
    //           dword_8B8F34 = OperatorNewNhMallocWrapper(blk_size);
    //           if (ThreadSafeReadWrapper_803f(dword_8B8F34, 1, blk_size, handle) != blk_size) {
    //               FreeWrapper_7bcf((LPVOID)dword_8B8F30);
    //               FreeWrapper_7bcf((LPVOID)dword_8B8F34);
    //               return -1;
    //           }
    //           sub_59B260(dword_8B8F34, blk_size);
    //       } else {
    //           DWORD pos = FileSizeQueryWrapper(handle);
    //           sub_587F64(handle, 0, 2);
    //           DWORD len = FileSizeQueryWrapper(handle) - pos;
    //           sub_587F64(handle, pos, 0);
    //           dword_8B8F30 = OperatorNewNhMallocWrapper(len);
    //           if (ThreadSafeReadWrapper_803f(dword_8B8F30, 1, len, handle) != len) {
    //               FreeWrapper_7bcf((LPVOID)dword_8B8F30);
    //               return -1;
    //           }
    //       }
    //       dword_8B8F3C = 0;
    //       ArithmeticComparison_a5c0((float*)this + 7, dword_8B8F30, 16); // name block
    //       ArithmeticComparison_a5c0(this, dword_8B8F30, 4);              // flags
    //       ArithmeticComparison_a5c0((float*)this + 1, dword_8B8F30, 4);  // scale
    //       ArithmeticComparison_a5c0((float*)this + 2, dword_8B8F30, 4);
    //       this[1] = 1.0f / this[1];
    //       sub_589901((LPCSTR)this + 28);
    //       if (*(DWORD*)this & 2) {
    //           // material path
    //           ArithmeticComparison_a5c0((float*)this + 5, dword_8B8F30, 4);
    //           DWORD blocks = *((DWORD*)this + 5);
    //           DWORD* arr = (DWORD*)OperatorNewNhMallocWrapper(12*blocks + 4);
    //           if (arr) { *arr = blocks; for (i = 0; i < blocks; ++i) StructZeroInit_93b0(arr + 1 + 3*i); }
    //           *((DWORD*)this + 6) = (DWORD)arr;
    //           for (b = 0; b < blocks; ++b) {
    //               DWORD* el = (DWORD*)(b*12 + *((DWORD*)this + 6));
    //               ArithmeticComparison_a5c0(el + 1, dword_8B8F30, 4);
    //               DWORD subs = el[1];
    //               DWORD* sub = (DWORD*)OperatorNewNhMallocWrapper(8*subs + 4);
    //               if (sub) { *sub = subs; for (j = 0; j < subs; ++j) DualFieldZeroInit(sub + 1 + 2*j); }
    //               el[2] = (DWORD)sub;
    //               for (k = 0; k < subs; ++k) {
    //                   int* ent = (int*)(el[2] + 8*k);
    //                   ArithmeticComparison_a5c0(ent, dword_8B8F30, 4);
    //                   ent[1] = (int)OperatorNewNhMallocWrapper(36 * *ent);
    //                   ArithmeticComparison_a5c0(ent + 1, dword_8B8F30, 36 * *ent);
    //               }
    //           }
    //       } else if (*(DWORD*)this & 1) {
    //           // texture/animation path
    //           ArithmeticComparison_a5c0((float*)this + 3, dword_8B8F30, 4);
    //           DWORD blocks = *((DWORD*)this + 3);
    //           DWORD* arr = (DWORD*)OperatorNewNhMallocWrapper(44*blocks + 4);
    //           if (arr) { *arr = blocks; for (i = 0; i < blocks; ++i) StructInitWithVtableZero(arr + 1 + 11*i); }
    //           *((DWORD*)this + 4) = (DWORD)arr;
    //           for (b = 0; b < blocks; ++b) {
    //               DWORD* el = (DWORD*)(b*44 + *((DWORD*)this + 4));
    //               ArithmeticComparison_a5c0(el, dword_8B8F30, 32);
    //               ArithmeticComparison_a5c0(el + 8, dword_8B8F30, 4);
    //               ArithmeticComparison_a5c0(el + 9, dword_8B8F30, 4);
    //               DWORD frames = el[9];
    //               DWORD* fa = (DWORD*)OperatorNewNhMallocWrapper(32*frames + 4);
    //               if (fa) { *fa = frames; for (j = 0; j < frames; ++j) sub_5507A0((DWORD*)(fa + 1 + 8*j)); }
    //               el[10] = (int)fa;
    //               ArithmeticComparison_a5c0(fa, dword_8B8F30, 32*frames);
    //               for (k = 0; k < frames; ++k)
    //                   *(float*)((DWORD)(fa + 1) + 32*k) = (float)((double)k * this[1]);
    //               if (frames > *((DWORD*)this + 5)) *((DWORD*)this + 5) = frames;
    //           }
    //           this[2] = (float)(*((int*)this + 5) * this[1]);
    //       }
    //       if (dword_8B8F30) FreeWrapper_7bcf((LPVOID)dword_8B8F30);
    //       if (dword_8B8F34) FreeWrapper_7bcf((LPVOID)dword_8B8F34);
    //       return 0;
    //   }
    // UNRESOLVED: The exact semantics of ArithmeticComparison_a5c0 (buffer cursor reads advancing a shared position) are inferred from its repeated use as the file-to-struct reader; not confirmed independently.
    // UNRESOLVED: The meaning of the sub-block in the context pointer a3 (data pointer at +296 combined with a byte index at +292<<8) and the purpose of the header bit 0x10 are not established by this packet.
    // UNRESOLVED: The nature of the 16-byte name string at this+28 processed by sub_589901 is unknown.
    // UNRESOLVED: The per-frame float fill (index * scale) overwrites data read from the file; whether that data is a fallback or a separate quantity is unresolved.
    // UNRESOLVED: The material-array allocation path reads the per-sub-entry count and fills 36-byte arrays, but the element layout is not established beyond the sizes.
}
