// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00547710
// Canonical corpus name: sub_547710
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_547710_00547710.c

void UnknownObject::RemoveResourceNodeFromListWithCounters()
{
    // Resource-manager node removal. Decrements the reference count of the node a2 via ReferenceCountedResourceRelease; only when the count reaches 0 does it continue: format an already-deleted message into a local buffer if the node's state word is -1, decrement one of four category counters (this+0x14..+0x20) selected by bits 0x20/0x100 of the state word, splice the node out of the doubly linked list by relinking a2[47]/a2[48] neighbor pointers, update the list head this+0x24 if the removed node was head, free the node's internal arrays and memory, and decrement the total count this+0x10.
    // CALL: ReferenceCountedResourceRelease(a2) decrements the node reference count; the removal path is only entered when it returns 0 [callee:0x005469C0, source:raw]
    // GUARD: Continue only when the release returned 0 and a2[34] is also 0; otherwise return the release result unchanged [source:raw]
    // GUARD: If the node state word a2[39] equals -1, StringFormatWithBufferOverflowCheck(v7, aAlreadyDeleted) formats the already-deleted diagnostic message into the local buffer [callee:0x0058815F, global:0x005DBE60, source:raw]
    // CALCULATION: Select and decrement the category counter from bits 0x20 and 0x100 of a2[39]: both set decrements this[7] (+0x1C), only bit 0x20 decrements this[8] (+0x20), only bit 0x100 decrements this[5] (+0x14), neither decrements this[6] (+0x18) [field:this:0x0000001C, field:this:0x00000020, field:this:0x00000014, field:this:0x00000018, source:raw]
    // ASSIGNMENT: Splice the node out of the doubly linked list: if a2[47] is non-zero write a2[48] to *(a2[47]+192); if a2[48] is non-zero write a2[47] to *(a2[48]+188) [source:raw]
    // ASSIGNMENT: If this[9] equals the removed node, the list head this+0x24 is advanced to a2[48] (the next neighbor) [field:this:0x00000024, source:raw]
    // CALL: ArrayCleanupWithDualFree(a2) frees the node's internal array allocations [callee:0x00546370, source:raw]
    // CALL: EmptyStub_7470(a2) runs the stub cleanup callback for the node [callee:0x00557470, source:raw]
    // CALL: FreeWrapper_7bcf(a2) deallocates the node memory [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Decrement the total resource count: this[4] (+0x10) = this[4] - 1 [field:this:0x00000010, source:raw]
    // RETURN: Return 0 (the successful-release result); invoked by sub_54AC70, QueueResourceCleanup and sub_5574B0 [function:0x00547710, caller:0x0054AC70, caller:0x0054C410, caller:0x005574B0, source:raw]

    // Conservative worker pseudocode:
    //   if (ReferenceCountedResourceRelease(a2) != 0) return result;
    //   if (a2[34] != 0) return result;
    //   if (a2[39] == -1) StringFormatWithBufferOverflowCheck(v7, aAlreadyDeleted);
    //   if (a2[39] & 0x20) (a2[39] & 0x100) ? --this[7] : --this[8];
    //   else                (a2[39] & 0x100) ? --this[5] : --this[6];
    //   if (a2[47]) *(a2[47] + 192) = a2[48];
    //   if (a2[48]) *(a2[48] + 188) = a2[47];
    //   if (this[9] == a2) this[9] = a2[48];
    //   ArrayCleanupWithDualFree(a2); EmptyStub_7470(a2); FreeWrapper_7bcf(a2);
    //   --this[4];
    //   return 0;
    // UNRESOLVED: Meaning of the state bits 0x20/0x100 and the values at a2[34], a2[47], a2[48] (node internals) are not determinable from this packet
    // UNRESOLVED: The offsets 192 and 188 in the neighbor pointers are node-internal links without further packet evidence
}
