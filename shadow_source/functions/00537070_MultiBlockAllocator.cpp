// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00537070
// Canonical corpus name: MultiBlockAllocator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiBlockAllocator_00537070.c

void UnknownObject::MultiBlockAllocator()
{
    // Fastcall factory that builds a multi-block allocator object through the allocator interface embedded in a1. Calls the allocation callback at a1+32 with the allocator context at a1+40 to obtain the header object v6, then allocates an 8 x 1440-byte block array stored at v6[9] and a single a3-byte payload block stored at v6[10] (with v6[11] set to its end address). On success it records a2 at v6[14], zeroes the header word *v6, calls StateResetWithCallback(v6, a1, 0) and returns v6. On any allocation failure it rolls back with the deallocation callback at a1+36 and returns 0.
    // CALL: Call the allocation callback at a1+32 with context *(a1+40), count 1 and size 64 to allocate the allocator header; result is v6. [function:0x00537070, source:raw]
    // GUARD: If v6 is non-null, proceed with setup; otherwise return the unset result (null). [source:raw]
    // CALL: Call the allocation callback at a1+32 with context *(a1+40), count 8 and size 1440 to allocate the block array; store the pointer at v6[9]. [source:raw]
    // GUARD: If the block array at v6[9] is non-null, continue; otherwise free v6 through the deallocation callback at a1+36 and return 0. [source:raw]
    // CALL: Call the allocation callback at a1+32 with context v8 (a1+40), count 1 and size a3 to allocate the single payload block; store the pointer at v6[10]. [source:raw]
    // GUARD: If the payload at v6[10] is non-null, finish initialization; otherwise free the block array at v6[9] and the header v6 through the deallocation callback at a1+36 and return 0. [source:raw]
    // ASSIGNMENT: Set v6[11] = a3 + v6[10] (end address of the payload block), v6[14] = a2, and zero the header word *v6. [source:raw]
    // CALL: Call StateResetWithCallback(v6, a1, 0) to initialize the allocator state with the allocator interface as callback owner. [callee:0x00537000, source:raw]
    // RETURN: Return v6 as the constructed multi-block allocator object on the success path; the failure paths return 0. [source:raw]

    // Conservative worker pseudocode:
    //   v6 = alloc(a1->ctx, 1, 64);
    //   if (v6 == null) return 0;
    //   v6[9] = alloc(a1->ctx, 8, 1440);
    //   if (v6[9] == null) { free(a1->ctx, v6); return 0; }
    //   v6[10] = alloc(a1->ctx, 1, a3);
    //   if (v6[10] == null) { free(a1->ctx, v6[9]); free(a1->ctx, v6); return 0; }
    //   v6[11] = a3 + v6[10];
    //   v6[14] = a2;
    //   *v6 = 0;
    //   StateResetWithCallback(v6, a1, 0);
    //   return v6;
    // UNRESOLVED: The roles of offsets a1+32, a1+36 and a1+40 (alloc callback, free callback, allocator context) are DERIVED from the raw source's indirect-call pattern and are not backed by a packet field list.
    // UNRESOLVED: The meaning of a2 (stored at v6[14]) and the purpose of the 8 x 1440-byte block array are not evidenced beyond the literal allocation sizes.
    // UNRESOLVED: The allocator vtable/interface layout of a1 is unknown; no owner type is recorded in the packet.
}
