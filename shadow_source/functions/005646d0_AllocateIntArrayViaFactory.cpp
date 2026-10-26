// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005646D0
// Canonical corpus name: AllocateIntArrayViaFactory
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AllocateIntArrayViaFactory_005646d0.c

void UnknownObject::AllocateIntArrayViaFactory()
{
    // Allocates a five-dword descriptor and a backing array of a2 element slots, then fills every slot with a distinct heap object built by Malloc0x18ByteStructWithInnerBuffer(a6). Returns a pointer to the descriptor. The descriptor stores the element array pointer at index 0, the element count a2 at index 1, the factory parameter a6 at index 2, and the caller-supplied values a4 and a5 at indices 3 and 4. This is an allocation helper shared by three callers, so the descriptor shape is a caller-facing contract.
    // ASSIGNMENT: Allocate the 20-byte (five-dword) descriptor via MallocWrapperForNhMalloc(20) and keep its address in v7. [callee:0x0058A935, source:raw]
    // ASSIGNMENT: Allocate the element array of a2 dword pointers via MallocWrapperForNhMalloc(4 * a2) and store the buffer pointer at descriptor index 0 (*v7). [callee:0x0058A935, source:raw]
    // LOOP: for-loop from v8 = 0 while v8 < a2: each iteration fills slot v7[0] + 4 * v8 with a fresh Malloc0x18ByteStructWithInnerBuffer(a6) object (the post-increment write lands at the slot for the prior v8 value). [callee:0x00564810, source:raw]
    // ASSIGNMENT: Store the element count a2 at descriptor index 1 (v7[1]). [source:raw]
    // ASSIGNMENT: Store the factory parameter a6 at descriptor index 2 (v7[2]). [source:raw]
    // ASSIGNMENT: Store the caller-supplied value a4 at descriptor index 3 (v7[3]). [source:raw]
    // ASSIGNMENT: Store the caller-supplied value a5 at descriptor index 4 (v7[4]). [source:raw]
    // RETURN: Return the descriptor pointer v7. [source:raw]
    // CALL: Invoked by MemoryObjectAllocator (00562B50), DirectDrawDisplayModeInit (00563E00) and StructAllocInitWithSwitchBasedType (005642F0). [caller:0x00562B50, caller:0x00563E00, caller:0x005642F0, source:raw]

    // Conservative worker pseudocode:
    //   int* AllocateIntArrayViaFactory(int count, int a4, int a5, int a6) {
    //     int* desc = MallocWrapperForNhMalloc(20);
    //     desc[0] = MallocWrapperForNhMalloc(4 * count);
    //     for (int i = 0; i < count; ++i)
    //       desc[0][i] = Malloc0x18ByteStructWithInnerBuffer(a6);
    //     desc[1] = count;
    //     desc[2] = a6;
    //     desc[3] = a4;
    //     desc[4] = a5;
    //     return desc;
    //   }
    // UNRESOLVED: Semantics of the a4 and a5 descriptor fields depend on each caller's use of the descriptor; unknown here.
    // UNRESOLVED: The descriptor is a caller-facing allocation contract, but the owning class/allocator subsystem is not established by this packet.
}
