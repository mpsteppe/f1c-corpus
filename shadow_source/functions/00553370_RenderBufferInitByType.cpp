// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00553370
// Canonical corpus name: sub_553370
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_553370_00553370.c

void UnknownObject::RenderBufferInitByType()
{
    // Initializes a render vertex-buffer object for one of two modes selected by a2 (1 or 2). Each mode lazily allocates the vertex storage buffer (this+0x18, 384 or 448 bytes), reuses or freshly allocates a 36-byte buffer descriptor (this+0x14) and writes primitive type 34, vertex count 16 and mode-specific stride/size fields into it. When this+0x4 (vertex count) is positive, locks the buffer via BufferLockAllocate and copies the source vertex array (this+0x18) into the locked memory, transforming the per-vertex layout (24-byte source stride in mode 1, 28-byte source stride in mode 2 with a brightness/volume scale applied). Returns 0 on success, -1 when sub_540DF0 rejects the descriptor.
    // GUARD: Dispatch on mode a2: equal to 1 selects the type-1 path, equal to 2 selects the type-2 path, anything else returns 0 immediately. [source:raw]
    // ASSIGNMENT: Set the type flags: clear the low 2 bits of this+0x0 and set them to 1 (mode 1) or 2 (mode 2). [field:this:0x00000000, source:raw]
    // GUARD: Lazily allocate the vertex source buffer this+0x18 (384 bytes in mode 1, 448 bytes in mode 2) only when it is still null. [field:this:0x00000018, callee:0x00587C03, source:raw]
    // CALL: Reuse an existing buffer descriptor: if this+0x14 is non-null, reset it with ObjectResetWithVirtualRelease using the dword_8B78A0 manager; otherwise allocate 36 zeroed bytes and store them at this+0x14. [field:this:0x00000014, callee:0x00540EB0, callee:0x00587C03, global:0x008B78A0, source:raw]
    // ASSIGNMENT: Initialize descriptor fields: +0x0 = 34 (primitive type), +0x4 = 324 (mode 2) or 322 (mode 1) stride, +0x8 = 28 (mode 2) or 24 (mode 1) source stride, +0xC = 16 vertex count. [field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, source:raw]
    // CALL: Validate or register the descriptor with sub_540DF0(dword_8B78A0, this+0x14); a non-zero result makes the function return -1. [field:this:0x00000014, callee:0x00540DF0, global:0x008B78A0, source:raw]
    // GUARD: Only fill the vertex buffer when this+0x4 (vertex count) is greater than 0; otherwise skip the copy and return 0. [field:this:0x00000004, guard:0, guard:1, source:raw]
    // CALL: Lock the device buffer with BufferLockAllocate(dword_8B78A0, this+0x14, 96, 0, 0), obtaining a writable pointer v11. [field:this:0x00000014, callee:0x00540F00, global:0x008B78A0, source:raw]
    // CALCULATION: Precompute per-vertex scale factors for mode 2: v16 = flt_8B8CF0 * dword_8B8DD4 and v17 = flt_8B8CF4 (brightness/volume scaling). [global:0x008B8CF0, global:0x008B8CF4, global:0x008B8DD4, source:raw]
    // LOOP: do-while over this+0x4 iterations: read one vertex from this+0x18 (24-byte stride in mode 1, 28-byte stride in mode 2) and write it into the locked buffer at a 28-byte (mode 2) or 24-byte (mode 1) destination stride, with the first X component scaled by v17 and offset by v16 in mode 2 and the remaining layout fields reordered. [field:this:0x00000004, field:this:0x00000018, source:raw]
    // CALL: Unlock or commit the descriptor with ArithmeticComparison_0f90(dword_8B78A0, this+0x14) after the vertex copy completes. [field:this:0x00000014, callee:0x00540F90, global:0x008B78A0, source:raw]
    // RETURN: Return 0 on success and -1 when sub_540DF0 rejects the descriptor. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_553370(BufferObj* this, int mode) {
    //     if (mode == 1 || mode == 2) {
    //       this->flags = (this->flags & ~3) | mode;
    //       if (!this->verts) this->verts = alloc(mode == 1 ? 384 : 448);
    //       if (this->desc) ObjectResetWithVirtualRelease(gManager, this->desc);
    //       else this->desc = zalloc(36);
    //       this->desc->primType = 34;
    //       this->desc->vertexCount = 16;
    //       this->desc->dstStride = mode == 1 ? 322 : 324;
    //       this->desc->srcStride = mode == 1 ? 24 : 28;
    //       if (sub_540DF0(gManager, this->desc)) return -1;
    //       if (this->count > 0) {
    //         p = BufferLockAllocate(gManager, this->desc, 96, 0, 0);
    //         scaleX = flt_8B8CF0 * dword_8B8DD4; scale = flt_8B8CF4;
    //         for (i = 0; i < this->count; ++i)
    //           copy_vertex(p, this->verts + i * srcStride, scale, scaleX);
    //         ArithmeticComparison_0f90(gManager, this->desc);
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Exact semantics of sub_540DF0 and ArithmeticComparison_0f90 (validation vs. commit) are unknown.
    // UNRESOLVED: Purpose of the descriptor field written with 16 and the exact meaning of strides 322/324 vs 24/28.
    // UNRESOLVED: The per-vertex field reordering differs between modes (24-byte vs 28-byte layouts); exact vertex struct layout is unconfirmed.
}
