// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00490850
// Canonical corpus name: ResourceLinkedListTeardown
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceLinkedListTeardown_00490850.c

void UnknownObject::ResourceLinkedListTeardown()
{
    // Tears down a custom memory-pool/allocator subsystem. Destroys and frees the allocator handle global dword_7CD9D0, then, when the pool descriptor global dword_7CD9CC is non-null, walks and frees two linked lists rooted in the descriptor (a used list at descriptor offset +16 and a free list at descriptor start), running per-node conditional cleanup helpers, zeroes each list's head fields, and frees the pool descriptor itself. Returns the free-call result on the success path or the descriptor value (0) when dword_7CD9CC was null.
    // ASSIGNMENT: Load the allocator handle pointer from global dword_7CD9D0 into v0 and use it as the first guard value. [global:0x007CD9D0, source:raw]
    // GUARD: Proceed with handle teardown only when dword_7CD9D0 is non-null; otherwise skip it. [global:0x007CD9D0, source:raw]
    // CALL: Run the conditional destructor on the allocator handle. [callee:0x00491740, source:raw]
    // CALL: Free the allocator handle object after its destructor. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Load the pool descriptor pointer dword_7CD9CC into result/v2/v10 and use it as the second guard value. [global:0x007CD9CC, source:raw]
    // GUARD: Proceed with pool teardown only when dword_7CD9CC is non-null; otherwise return its value (0). [global:0x007CD9CC, source:raw]
    // ASSIGNMENT: Read the used-list head from the pool descriptor at offset +16 into v3, with v4 pointing at that head field. [source:raw]
    // GUARD: Walk the used list only when its head at descriptor offset +16 is non-null. [source:raw]
    // LOOP: do-while walk of the used list, following each node's next pointer at node offset +4 until it is null. [source:raw]
    // GUARD: Test the flag byte at node offset +8; cleanup runs only when it is non-zero and the node's first dword (resource/vtable pointer) is non-null. [source:raw]
    // CALL: Invoke ShortComputation_1e60(1) to release the used-list node's resource. [callee:0x00491E60, source:raw]
    // CALL: Free each used-list node structure. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the four dwords at descriptor offset +16 (the used-list head fields) after the list is drained. [source:raw]
    // GUARD: Walk the free list only when its head (*v2) is non-null. [source:raw]
    // LOOP: do-while walk of the free list, following each node's next pointer at node offset +4 until it is null. [source:raw]
    // GUARD: Test the flag byte at node offset +8; resource cleanup runs only when it is non-zero. [source:raw]
    // GUARD: Within cleanup, check the node's first dword (v9) for non-null before releasing the resource. [source:raw]
    // CALL: Invoke UtilityFunction_1e80 on the free-list node's resource. [callee:0x00491E80, source:raw]
    // CALL: Free the free-list node's resource object. [callee:0x00587BCF, source:raw]
    // CALL: Free each free-list node structure. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the four dwords at the pool descriptor start (the free-list head fields). [source:raw]
    // CALL: Free the pool descriptor itself and return that call's result. [callee:0x00587BCF, source:raw]

    // Conservative worker pseudocode:
    //   int sub_490850() {
    //     void* handle = (void*)dword_7CD9D0;
    //     if (dword_7CD9D0) { ConditionalDestructor_1740(); FreeWrapper_7bcf(handle); }
    //     int result = dword_7CD9CC;
    //     int* pool = (int*)dword_7CD9CC;
    //     if (dword_7CD9CC) {
    //       int* used_head = (int*)dword_7CD9CC + 4;
    //       if (used_head) {
    //         void* node = used_head;
    //         do {
    //           void* next = *(void**)((char*)node + 4);
    //           if (*(char*)((char*)node + 8) != 0 && *(int*)node) ShortComputation_1e60(1);
    //           FreeWrapper_7bcf(node);
    //           node = next;
    //         } while (node);
    //       }
    //       used_head[0] = 0; used_head[1] = 0; used_head[2] = 0; used_head[3] = 0;
    //       if (*pool) {
    //         void* node = (void*)*pool;
    //         do {
    //           void* next = *(void**)((char*)node + 4);
    //           if (*(char*)((char*)node + 8) != 0) {
    //             void* res = *(void**)node;
    //             if (*(void**)node) { UtilityFunction_1e80(*(void**)node); FreeWrapper_7bcf(res); }
    //           }
    //           FreeWrapper_7bcf(node);
    //           node = next;
    //         } while (node);
    //       }
    //       pool[0] = 0; pool[1] = 0; pool[2] = 0; pool[3] = 0;
    //       return FreeWrapper_7bcf(pool);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Node layout semantics (first dword resource/vtable pointer, offset +4 next pointer, offset +8 flag) are inferred from the raw source only; no packet field evidence names them.
    // UNRESOLVED: Exact meaning of the ShortComputation_1e60(1) argument is unknown.
    // UNRESOLVED: No static callers exist in the packet, so the top-level owner and exact subsystem role are UNKNOWN.
}
