// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00581C20
// Canonical corpus name: sub_581C20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_581C20_00581c20.c

void UnknownObject::DestroyDualCallbackLists()
{
    // Destructor-style cleanup of two embedded linked lists. When the byte flag at this+0x28 is set, closes the handle at this+0x20 and zeroes it on success. Walks the first list (head this+0x10) through node+4 next pointers, invoking SEHGuardedFunctionWithExceptionHandling on each node's data and freeing the data when the node byte flag at node+8 is set and the data pointer is non-zero, then zeroes this+0x10..this+0x1C. Walks the second list (head this+0x0) through node+4 next pointers; for flagged nodes, adjusts the data pointer back by 4 bytes, runs NTimeCallbackLoopWithSEH with constant 84 on the adjusted data and its preceding dword, frees the adjusted data, the data block and the node, then zeroes this+0x0..this+0xC. Returns the last FreeWrapper result.
    // GUARD: When the byte flag at this+0x28 is set, closes the handle at this+0x20 via CloseHandle and, on a successful close, zeroes this+0x20 [field:this:0x00000028, field:this:0x00000020, global:0x0059E1A8, source:raw]
    // LOOP: Walks the first list from its head at this+0x10 by following the node+4 next pointers until a null node is reached [field:this:0x00000010, field:this:0x00000014, source:raw]
    // GUARD: For each first-list node whose byte flag at node+8 is non-zero and whose data pointer (node+0) is non-null, calls SEHGuardedFunctionWithExceptionHandling on the data and frees the data with FreeWrapper_7bcf [field:obj:0x00000008, field:obj:0x00000000, callee:0x005867B0, global:0x005867B0, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zeroes the first list's four state fields this+0x10..this+0x1C after traversal [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // LOOP: Walks the second list from its head at this+0x0 by following the node+4 next pointers until a null node is reached [field:this:0x00000000, source:raw]
    // GUARD: For each second-list node whose byte flag at node+8 is non-zero: when the node's data pointer (node+0) is non-null and the data block's first dword is non-null, calls NTimeCallbackLoopWithSEH with the data block, constant 84, the dword preceding the data block and SEHGuardedFunctionWithExceptionHandling (referenced both as a callee and as the read-only SEH handler global), then frees the adjusted pointer (data-4) and the data block; the node itself is freed via FreeWrapper_7bcf after processing [field:obj:0x00000008, field:obj:0x00000000, field:*(obj+0x0):0x00000000, callee:0x0058A5F7, callee:0x005867B0, global:0x005867B0, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zeroes the second list's four state fields this+0x0..this+0xC after traversal [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // RETURN: Returns the last FreeWrapper_7bcf result (v2), which is a status value, not a meaningful object pointer [source:raw]

    // Conservative worker pseudocode:
    //   if (this+0x28) {
    //     if (CloseHandle(this+0x20)) this+0x20 = 0;
    //   }
    //   node = this+0x10;
    //   while (node) {
    //     next = node+4;
    //     if (node[8]) {
    //       data = node+0;
    //       if (data) {
    //         SEHGuardedFunctionWithExceptionHandling(data);
    //         FreeWrapper_7bcf(data);
    //       }
    //     }
    //     node = next;
    //   }
    //   this+0x10 = this+0x14 = this+0x18 = this+0x1C = 0;
    //   node = this+0x0;
    //   while (node) {
    //     next = node+4;
    //     if (node[8]) {
    //       block = node+0;
    //       if (block) {
    //         head = block[0];
    //         if (head) {
    //           NTimeCallbackLoopWithSEH(head, 84, *(head-4), SEHGuardedFunctionWithExceptionHandling);
    //           FreeWrapper_7bcf(head - 4);
    //         }
    //         FreeWrapper_7bcf(block);
    //       }
    //     }
    //     FreeWrapper_7bcf(node);
    //     node = next;
    //   }
    //   this+0x0 = this+0x4 = this+0x8 = this+0xC = 0;
    //   return lastFreeResult;
    // UNRESOLVED: The packet-flagged field base *(this+0x14) with offset 4 corresponds to the node+4 next-pointer read during first-list traversal, but the tail field this+0x14 itself is never dereferenced directly in the raw source
    // UNRESOLVED: Global SEH_581C20 (0x0059CB70) is flagged by packet facts but appears nowhere in the raw decompiled source; it is presumably this function's SEH unwind table
    // UNRESOLVED: The byte flag at node+8 distinguishes nodes with registered cleanup, but the exact meaning of the two list types (the second list carries an extra 4-byte header before each callback block) is unknown
    // UNRESOLVED: The handle at this+0x20 is closed and zeroed only when the flag at this+0x28 is set; whether this+0x20 ever becomes non-null again is not visible here
}
