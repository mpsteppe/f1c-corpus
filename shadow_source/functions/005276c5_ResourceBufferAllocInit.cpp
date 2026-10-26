// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005276C5
// Canonical corpus name: sub_5276C5
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5276C5_005276c5.c

void UnknownObject::ResourceBufferAllocInit()
{
    // Allocate and initialize a resource buffer struct through an allocator object (this). Uses the allocation callback at this+0x20 with the allocator handle at this+0x28 to allocate a primary struct (size 64), a secondary fixed-size buffer (tag 8, size 1440) and a variable-size buffer (tag 1, size a3). On success stores the buffers at v3[9] and v3[10], initializes the struct (v3[0]=0, v3[11]=a3+size, v3[14]=a2) and calls sub_52765A to reset/initialize it, then returns the struct. On any allocation failure, frees previously allocated blocks via the release callback at this+0x24 and returns 0.
    // CALL: Allocate the primary struct: call the allocation callback at this+0x20 with the allocator handle at this+0x28, tag 1 and size 64, storing the result in v3. [field:this:0x00000020, field:this:0x00000028, source:raw]
    // GUARD: Primary allocation guard: when v3 is null, return 0 immediately (BLOCKED). [source:raw]
    // CALL: Allocate the secondary fixed-size buffer: call the allocation callback at this+0x20 with the handle at this+0x28, tag 8 and size 1440, storing the result in v4. [field:this:0x00000020, field:this:0x00000028, source:raw]
    // ASSIGNMENT: Store the secondary buffer pointer at v3[9] (dword index 9 of the primary struct). [source:raw]
    // GUARD: Secondary allocation guard: when v4 is null, release v3 through the callback at this+0x24 with the handle at this+0x28, then return 0 (BLOCKED). [field:this:0x00000024, field:this:0x00000028, source:raw]
    // CALL: Allocate the variable-size buffer: call the allocation callback at this+0x20 with the handle at this+0x28, tag 1 and size a3, storing the result in v6. [field:this:0x00000020, field:this:0x00000028, source:raw]
    // ASSIGNMENT: Store the variable-size buffer pointer at v3[10] (dword index 10 of the primary struct). [source:raw]
    // GUARD: Variable allocation guard: when v6 is non-null take the success path; otherwise release v3[9] and v3 through the callback at this+0x24 with the handle at this+0x28, then return 0 (BLOCKED). [field:this:0x00000024, field:this:0x00000028, source:raw]
    // ASSIGNMENT: Initialize the struct header fields: v3[0] = 0, v3[11] = a3 + v6 (end of the variable buffer), v3[14] = a2. [source:raw]
    // CALL: Call sub_52765A(v3, a1, 0) to reset/initialize the newly allocated struct with the allocator context. [callee:0x0052765A, source:raw]
    // RETURN: Return the initialized primary struct pointer v3 on success, or 0 on any allocation failure path. [abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* ResourceBufferAllocInit(int a1, int a2, int a3) {
    //     _DWORD* v3 = (*(int (__cdecl**)(_DWORD, int, int))(a1 + 32))(*(_DWORD*)(a1 + 40), 1, 64);
    //     if (!v3) return 0;
    //     int v4 = (*(int (__cdecl**)(_DWORD, int, int))(a1 + 32))(*(_DWORD*)(a1 + 40), 8, 1440);
    //     v3[9] = v4;
    //     if (!v4) {
    //       (*(void (__cdecl**)(_DWORD, _DWORD*))(a1 + 36))(*(_DWORD*)(a1 + 40), v3);
    //       return 0;
    //     }
    //     int v6 = (*(int (__cdecl**)(_DWORD, int, int))(a1 + 32))(*(_DWORD*)(a1 + 40), 1, a3);
    //     v3[10] = v6;
    //     if (v6) {
    //       *v3 = 0;
    //       v3[11] = a3 + v6;
    //       v3[14] = a2;
    //       sub_52765A(v3, a1, 0);
    //       return v3;
    //     } else {
    //       (*(void (__cdecl**)(_DWORD, _DWORD))(a1 + 36))(*(_DWORD*)(a1 + 40), v3[9]);
    //       (*(void (__cdecl**)(_DWORD, _DWORD*))(a1 + 36))(*(_DWORD*)(a1 + 40), v3);
    //       return 0;
    //     }
    //   }
    // UNRESOLVED: Semantic meaning of the allocation tags 1 and 8 and the sizes 64 and 1440 is not in the packet.
    // UNRESOLVED: Meaning of the stored fields v3[9], v3[10], v3[11] and v3[14], and of the parameter a2, is unknown.
    // UNRESOLVED: sub_52765A (0x0052765A) purpose is not in the packet; existing analysis reads it as a struct reset/initializer.
    // UNRESOLVED: The class identity of the allocator object (this slots 0x20/0x24/0x28) and the owner of the buffer struct are unverified.
}
