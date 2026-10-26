// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005527C0
// Canonical corpus name: VertexBufferSurfaceInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VertexBufferSurfaceInit_005527c0.c

void UnknownObject::VertexBufferSurfaceInit()
{
    // Initializes a vertex buffer surface on the rendering object. Gated by flag bit 0x20000 at this+0x24. Lazily allocates a 36-byte descriptor (this+0xC) and fills it with primitive type 34, vertex count 768, size 28, and stride dword_8CEF78. Validates the descriptor against device dword_8B78A0 via sub_540DF0 (returns -1 on failure), allocates the vertex buffer through BufferLockAllocate (dword_8B78A0, descriptor, 96, 0, 0) storing it at this+0x10, initializes each vertex (zero at +0x8, 1.0f at +0xC, advancing by 28 bytes per vertex up to the count), then finalizes via ArithmeticComparison_0f90.
    // GUARD: Whole body gated on flag bit 0x20000 at this+0x24; if clear, function does nothing and returns 0. [field:this:0x00000024, source:raw]
    // GUARD: If this+0xC is null, allocate the descriptor; the 36-byte allocation and the null-pointer branch are both followed. [field:this:0x0000000C, source:raw]
    // CALL: OperatorNewNhMallocWrapper(36) allocates the 36-byte vertex buffer descriptor object. [callee:0x00587C03]
    // ASSIGNMENT: Zero all nine dwords of the fresh descriptor (offsets 0x0 through 0x20) and store the descriptor pointer into this+0xC. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Descriptor offset 0x0 set to 34 (vertex buffer primitive type). [field:*(this+0xC):0x00000000, source:raw]
    // ASSIGNMENT: Descriptor offset 0xC set to 768 (vertex/element count, later loop bound). [field:*(this+0xC):0x0000000C, source:raw]
    // ASSIGNMENT: Descriptor offset 0x8 set to 28 (per-vertex byte size; loop advances this+0x10 by 28). [field:*(this+0xC):0x00000008, source:raw]
    // ASSIGNMENT: Descriptor offset 0x4 set to global dword_8CEF78 (vertex stride). [field:*(this+0xC):0x00000004, global:0x008CEF78]
    // CALL: sub_540DF0(dword_8B78A0, this+0xC) validates the descriptor against the device handle. [callee:0x00540DF0, global:0x008B78A0]
    // GUARD: If sub_540DF0 returns nonzero, the function returns -1 before allocating the buffer. [callee:0x00540DF0]
    // RETURN: Early failure exit returning -1 after descriptor validation fails. [source:raw]
    // CALL: BufferLockAllocate(dword_8B78A0, this+0xC, 96, 0, 0) allocates the vertex buffer; its pointer is stored at this+0x10. [callee:0x00540F00, global:0x008B78A0, field:this:0x00000010]
    // LOOP: Per-vertex init loop iterating count = descriptor+0xC (guard: count > 0): zero vertex+0x8, set vertex+0xC to 1.0f (1065353216), advance this+0x10 by 28 bytes per iteration. [guard:0, field:*(this+0x10):0x00000008, field:*(this+0x10):0x0000000C, field:*(this+0xC):0x0000000C, field:this:0x00000010]
    // CALL: ArithmeticComparison_0f90(dword_8B78A0, this+0xC) finalizes the vertex buffer descriptor. [callee:0x00540F90, global:0x008B78A0]
    // RETURN: Normal completion returning 0. [source:raw]

    // Conservative worker pseudocode:
    //   int VertexBufferSurfaceInit(int this) {
    //     if (((*(unsigned int*)(this + 0x24)) & 0x20000) == 0) return 0;
    //     if (*(unsigned int*)(this + 0xC) == 0) {
    //       unsigned int* d = OperatorNewNhMallocWrapper(36);
    //       if (d) { d[0]=d[1]=d[2]=d[3]=d[4]=d[5]=d[6]=d[7]=d[8]=0; }
    //       *(unsigned int**)(this + 0xC) = d;
    //     }
    //     *(unsigned int*)(*(unsigned int*)(this + 0xC)) = 34;
    //     *(unsigned int*)(*(unsigned int*)(this + 0xC) + 12) = 768;
    //     *(unsigned int*)(*(unsigned int*)(this + 0xC) + 8) = 28;
    //     *(unsigned int*)(*(unsigned int*)(this + 0xC) + 4) = dword_8CEF78;
    //     if (sub_540DF0(dword_8B78A0, *(int**)(this + 0xC))) return -1;
    //     *(unsigned int*)(this + 0x10) = BufferLockAllocate(dword_8B78A0, *(unsigned int**)(this + 0xC), 96, 0, 0);
    //     int i = 0;
    //     int count = *(int*)(*(unsigned int*)(this + 0xC) + 12);
    //     while (i < count) {
    //       *(unsigned int*)(*(unsigned int*)(this + 0x10) + 8) = 0;
    //       *(unsigned int*)(*(unsigned int*)(this + 0x10) + 12) = 1065353216; // 1.0f
    //       *(unsigned int*)(this + 0x10) += 28;
    //       i++;
    //     }
    //     ArithmeticComparison_0f90(dword_8B78A0, *(unsigned int**)(this + 0xC));
    //     return 0;
    //   }
    // UNRESOLVED: Semantics of the descriptor fields (34 as primitive type, 768 count, 28 byte size) and of BufferLockAllocate's element-size argument 96 are inferred from context; the packet provides the literals only.
    // UNRESOLVED: The exact role of sub_540DF0 and ArithmeticComparison_0f90 against the device handle depends on their callees, not visible in this packet.
    // UNRESOLVED: The vertex buffer surface owner object is unknown; only its flag gating (this+0x24) and two pointer fields (this+0xC, this+0x10) are evidenced.
}
