// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055BF70
// Canonical corpus name: ArrayOfPointersCleanupWithFreeLoop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayOfPointersCleanupWithFreeLoop_0055bf70.c

void UnknownObject::freePointerArrayWithLinkedListCleanup()
{
    // Frees an array of pointer slots. Reads the count from this+0x4, and when it is positive iterates the slot array beginning at this+0x8: for each slot it frees the slot's linked list via LinkedListFreeWithTraversalAndNulling, then if the slot pointer is non-null runs EmptyStub_7470 on it and releases it via FreeWrapper_7bcf, and finally nulls the slot. Returns the count. Called by GlobalResourceCleanup as part of global resource teardown.
    // ASSIGNMENT: Read the array count: result = this[1] (dword at this+0x4). [field:this:0x00000004, function:0x0055BF70, source:raw]
    // GUARD: If the count is not greater than 0 the loop is skipped and the function returns immediately; there is nothing to free. [field:this:0x00000004, function:0x0055BF70, source:raw]
    // LOOP: Walk v4 from the first slot at this+0x8 through the count slots, advancing one dword per iteration and stopping once v3 reaches the count. [field:this:0x00000008, function:0x0055BF70, source:raw]
    // CALL: For the current slot, LinkedListFreeWithTraversalAndNulling(*v4) frees the linked list rooted in the slot. [callee:0x0055BBA0, field:this:0x00000008, source:raw]
    // GUARD: If the slot pointer *v4 is non-null, call EmptyStub_7470(*v4) and then FreeWrapper_7bcf(v5) to release the slot pointer itself. [callee:0x00557470, callee:0x00587BCF, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Null the slot after freeing it: *v4 = 0. [field:this:0x00000008, source:raw]
    // RETURN: Return result, the array count. [function:0x0055BF70, source:raw]

    // Conservative worker pseudocode:
    //   result = this[1];
    //   v3 = 0;
    //   if (result > 0) {
    //       v4 = this + 2;
    //       do {
    //           LinkedListFreeWithTraversalAndNulling(*v4);
    //           v5 = *v4;
    //           if (*v4) { EmptyStub_7470(*v4); FreeWrapper_7bcf(v5); }
    //           *v4 = 0;
    //           result = this[1];
    //           ++v3; ++v4;
    //       } while (v3 < result);
    //   }
    //   return result;
    // UNRESOLVED: EmptyStub_7470 is described as a no-op stub by prior analysis; its actual behavior is not evidenced in this packet.
    // UNRESOLVED: FreeWrapper_7bcf's callee body is absent from the packet, so the exact deallocation semantics are inferred, not evidenced here.
}
