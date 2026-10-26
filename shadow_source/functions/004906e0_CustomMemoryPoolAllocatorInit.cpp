// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004906E0
// Canonical corpus name: CustomMemoryPoolAllocatorInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CustomMemoryPoolAllocatorInit_004906e0.c

void UnknownObject::CustomMemoryPoolAllocatorInit()
{
    // One-time initializer for a custom memory pool allocator. Guarded by byte_7CD9C8 bit 0: on first call it allocates and zeroes a pool struct, allocates a pool descriptor holding a 32-entry array (count 32 stored in its first dword, each entry initialized through ThunkToFUN00491330), builds a linked list of pool-struct nodes, walks the entry array in 16-byte steps linking 12-byte free-list nodes, stores the pool pointer in dword_7CD9CC, constructs an allocator handle via ObjectConstructor_1710 into dword_7CD9D0, registers ResourceLinkedListTeardown as teardown callback, and returns a pointer to dword_7CD9CC. Called by Accessor (00490920) and GlobalDataRead (00490930).
    // GUARD: Skip the whole initialization when byte_7CD9C8 bit 0 is already set; otherwise set it to mark initialization in progress. [global:0x007CD9C8]
    // CALL: Allocate the 32-byte pool struct (eight dwords) via OperatorNewNhMallocWrapper and zero all eight dwords. [callee:0x00587C03]
    // CALL: Allocate the 4-byte pool descriptor via OperatorNewNhMallocWrapper. [callee:0x00587C03]
    // CALL: Allocate the 516-byte entry array via OperatorNewNhMallocWrapper and store count 32 in its first dword. [callee:0x00587C03]
    // LOOP: Initialize the 32 pool entries by calling ThunkToFUN00491330 on each successive 4-byte slot of the array. [callee:0x004912F0]
    // ASSIGNMENT: Store the entry array pointer into the pool descriptor (null if the allocation failed). [source:raw]
    // CALL: Allocate a 12-byte pool-struct node via OperatorNewNhMallocWrapper. [callee:0x00587C03]
    // ASSIGNMENT: Initialize the pool-struct node (pool pointer, next 0, flag 1) and link it into the pool struct's head/tail list, incrementing its node count. [source:raw]
    // LOOP: Walk the entry array in 16-byte steps; for each entry allocate a 12-byte free-list node via OperatorNewNhMallocWrapper, initialize it (entry pointer, next 0, flag 0), and link it into the free list, incrementing its count. [callee:0x00587C03]
    // ASSIGNMENT: Store the pool struct pointer in global dword_7CD9CC (zero if the pool allocation failed). [global:0x007CD9CC]
    // CALL: Allocate the 4-byte handle storage and construct the allocator handle object via ObjectConstructor_1710 with argument 1; falls back to 0 when the allocation fails. [callee:0x00491710]
    // ASSIGNMENT: Store the allocator handle in global dword_7CD9D0. [global:0x007CD9D0]
    // CALL: Register ResourceLinkedListTeardown as a teardown callback via BooleanToIntConversion. [callee:0x00587B3E, global:0x00490850]
    // RETURN: Return a pointer to the global pool descriptor dword_7CD9CC. [global:0x007CD9CC]

    // Conservative worker pseudocode:
    //   // Custom memory pool allocator one-time initialization (guarded by flag).
    //   if (initFlag & 1) return;            // byte_7CD9C8 already initialized
    //   initFlag |= 1;
    //   PoolStruct* pool = new_zeroed(32);   // eight dwords
    //   PoolDesc* desc = new(4);
    //   if (desc != 0) {
    //       int* entries = new(516);
    //       desc->entries = (entries != 0) ? entries : 0;
    //       if (entries != 0) {
    //           entries[0] = 32;              // entry count
    //           for (int k = 0; k < 32; k++)
    //               ThunkToFUN00491330(&entries[k]);
    //       }
    //       Node* n = new(12);
    //       if (n != 0) { n->pool = desc; n->next = 0; n->flag = 1; }
    //       link_head_tail(pool, n);          // head/tail/next/count bookkeeping
    //   }
    //   for (int i = 0; i < 512; i += 16) {
    //       void* base = i + *(int*)desc;
    //       if (base != 0) {
    //           Node* node = new(12);
    //           if (node != 0) { node->base = base; node->next = 0; node->flag = 0; }
    //           link_free_list(pool, node);    // head/tail/next/count bookkeeping
    //       }
    //   }
    //   dword_7CD9CC = (int)pool;
    //   dword_7CD9D0 = (new(4) != 0) ? ObjectConstructor_1710(1) : 0;
    //   BooleanToIntConversion(ResourceLinkedListTeardown);
    //   return &dword_7CD9CC;
    // UNRESOLVED: The exact layouts of the pool struct and the free-list nodes are DERIVED from dword/byte indices in the raw body; not independently confirmed.
    // UNRESOLVED: The semantics of the ObjectConstructor_1710 argument (1) and its return value are unknown.
    // UNRESOLVED: When the descriptor allocation fails the decompiled body still dereferences the descriptor inside the walk loop; whether the original code carried a guard is not recoverable from this body.
    // UNRESOLVED: What ThunkToFUN00491330 writes into each 32-byte entry and how the stored count is later consumed is unknown.
}
