// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050A7E1
// Canonical corpus name: RenderBufferVertexAllocator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RenderBufferVertexAllocator_0050a7e1.c

void UnknownObject::RenderBufferVertexAllocator()
{
    // Allocates and initializes a render buffer with a vertex array. Runs the SEH setup, calls the base DirectX texture creation with a descriptor pointer read from *(this+0x8), computes a vertex count rounded up to even minus an even-masked base count, installs the vtable off_5ADBB8, zeroes several fields, allocates a 16-byte-stride array of that size via OperatorNewNhMallocWrapper, initializes each element through sub_5008C2 with sub_5007EC as element constructor, and finally branches on the format tag at *(*(this+0x8)+4): the value 1498831189 (0x59565955) selects one 8-vs-zero field layout, otherwise the mirrored one. Returns the buffer pointer.
    // CALL: Initialize the exception-handling context via SEHHandlerInit. [callee:0x0058A5D8, source:raw]
    // ASSIGNMENT: Load the parent descriptor pointer from *(this+0x8) into v9 and pass it, with size 0 and count 1, to DirectXTextureCreationWithMipmapChain along with the object pointer. [field:this:0x00000008, callee:0x00507496, source:raw]
    // CALCULATION: Compute v4 = this[1036] & 0xFFFFFFFE, v5 = ((this[1038]+1) & 0xFFFFFFFE) - v4, store this[1054] = (this[1038]+1) & 0xFFFFFFFE and this[1052] = v4. [source:raw]
    // ASSIGNMENT: Install the vtable by writing &off_5ADBB8 into the object's first dword, zero the fields this[1053], this[1056], this[1055], this[1057] and this[1059], store v5 into this[1058], and set this[1060] = 1. [global:0x005ADBB8, source:raw]
    // CALL: Allocate the vertex array through OperatorNewNhMallocWrapper(16 * v5), storing the result into the local at a1-16. [callee:0x00587C03, source:raw]
    // GUARD: When the allocation result is non-null, call sub_5008C2(alloc, 16, v5, sub_5007EC) to construct v5 elements with stride 16 using sub_5007EC as the element initializer; otherwise treat the array as null. [callee:0x005008C2, global:0x005007EC, source:raw]
    // ASSIGNMENT: Store the allocation result into this[1051]; if it is null, clear this[1060] back to 0.0. [source:raw]
    // GUARD: Compare the format tag *(*(this+0x8)+4) with 1498831189 (0x59565955): on equality set this[1061]=8 and this[1062]=0.0; otherwise set this[1061]=0.0 and this[1062]=8. [field:*(this+0x8):0x00000004, guard:0, source:raw]
    // RETURN: Return the initialized buffer pointer (the object pointer). [source:raw]

    // Conservative worker pseudocode:
    //   float* RenderBufferVertexAllocator(this, a1, a2) {
    //     SEHHandlerInit();
    //     v9 = *(float**)(a1 + 8);
    //     DirectXTextureCreationWithMipmapChain(this, v9, 0, 1);
    //     v4 = (unsigned)this[1036] & 0xFFFFFFFE;
    //     v5 = ((this[1038] + 1) & 0xFFFFFFFE) - v4;
    //     this[1054] = (this[1038] + 1) & 0xFFFFFFFE;
    //     *(int*)this = (int)&off_5ADBB8;
    //     this[1052] = v4;
    //     this[1053] = 0.0f; this[1056] = 0.0f;
    //     this[1055] = 0.0f; this[1057] = 0.0f;
    //     this[1058] = v5; this[1059] = 0.0f; this[1060] = 1.0f;
    //     alloc = OperatorNewNhMallocWrapper(16 * v5);
    //     if (alloc) { sub_5008C2(alloc, 16, v5, sub_5007EC); this[1051] = alloc; }
    //     else this[1051] = 0;
    //     if (!this[1051]) this[1060] = 0.0f;
    //     if (*(int*)(*(int*)(a1 + 8) + 4) == 1498831189) {
    //       this[1061] = 8; this[1062] = 0.0f;
    //     } else {
    //       this[1061] = 0.0f; this[1062] = 8;
    //     }
    //     return this;
    //   }
    // UNRESOLVED: Meaning of the global loc_59C578 listed in the packet but not present in the raw source text.
    // UNRESOLVED: Semantics of the base count this[1036], the derived this[1054] slot, and the (0,291)-style validity window for the vertex count.
    // UNRESOLVED: Meaning of the format tag 1498831189 (0x59565955) and of the two mirrored 8/0 field assignments.
    // UNRESOLVED: Purpose of the uninitialized this/v2 register convention of the __userpurge signature.
}
