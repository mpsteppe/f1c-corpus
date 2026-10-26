// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057E760
// Canonical corpus name: MutexProtectedLinkedListFlushDestroy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MutexProtectedLinkedListFlushDestroy_0057e760.c

void UnknownObject::MutexProtectedLinkedListFlushDestroy()
{
    // Destroys a mutex-protected singly-linked list. It waits on the mutex at this+0xB10 with the timeout at this+0xB14, then walks the list anchored at this+0xB00 (tail this+0xB04, cursor this+0xB08, fourth dword this+0xB0C); for every node it frees the node's data pointer when the byte flag at node+0x8 is non-zero and then frees the node itself. Afterward it zeros the four head fields, releases the mutex if one was held, and returns 0 otherwise. Called from NetworkCleanup_fbe0 (0057FBE0).
    // GUARD: Lock gate: only traverse when the mutex at this+0xB10 is non-null and WaitForSingleObject(handle, timeout at this+0xB14) returns 0 or 128 (owned/abandoned); otherwise the list head pointer is treated as null [field:this:0x00000B10, field:this:0x00000B14, global:0x0059E1A0]
    // CALL: WaitForSingleObject on the mutex handle this+0xB10 with the timeout this+0xB14 before touching the list [field:this:0x00000B10, field:this:0x00000B14, global:0x0059E1A0]
    // GUARD: Empty-list guard: when this+0xB00 (first node pointer) is 0, the traversal loop body is skipped entirely [guard:0, field:this:0x00000B00]
    // LOOP: Walk the singly-linked list: read the current node from this+0xB00, follow the next pointer at node+0x4, free node data when the flag byte at node+0x8 is set, free the node, and continue until the next pointer is null [field:this:0x00000B00, field:*(this+0xB00):0x00000000, field:*(*(this+0xB00)+0x4):0x00000004, field:*(this+0xB00):0x00000008]
    // CALL: FreeWrapper_7bcf(*(LPVOID*)node) releases the node's data pointer when the byte at node+0x8 is non-zero [field:*(this+0xB00):0x00000008, callee:0x00587BCF]
    // CALL: FreeWrapper_7bcf(node) frees the node allocation itself for every visited node [callee:0x00587BCF]
    // ASSIGNMENT: After traversal, zero the four head fields this+0xB00, this+0xB04, this+0xB08 and this+0xB0C, leaving the list empty [field:this:0x00000B00, field:this:0x00000B04, field:this:0x00000B08, field:this:0x00000B0C]
    // GUARD: Release gate: only ReleaseMutex runs when the mutex handle at this+0xB10 is non-null [field:this:0x00000B10, global:0x0059E1A4]
    // CALL: ReleaseMutex(this+0xB10) releases the mutex acquired at entry, ending the critical section [field:this:0x00000B10, global:0x0059E1A4]
    // RETURN: Return the mutex handle's prior state (0 when no mutex was held); called by NetworkCleanup_fbe0 (0057FBE0) [function:0x0057E760, caller:0x0057FBE0]

    // Conservative worker pseudocode:
    //   handle = *(void**)&this->list[0x4];  // this+0xB10
    //   if (handle) {
    //       wait = WaitForSingleObject(handle, *(dword*)((byte*)this + 0xB14));
    //       if (wait == 0 || wait == 128)
    //           head = &this->list[0x0];
    //       else
    //           head = NULL;
    //   } else {
    //       head = NULL;
    //   }
    //   node = head ? *head : 0;
    //   head[2] = *head;
    //   while (node) {
    //       next = *(node + 0x4);
    //       if (*(byte*)(node + 0x8))
    //           FreeWrapper_7bcf(*(void**)node);
    //       FreeWrapper_7bcf(node);
    //       node = next;
    //   }
    //   head[0] = head[1] = head[2] = head[3] = 0;
    //   if (handle)
    //       return ReleaseMutex(handle);
    //   return 0;
    // UNRESOLVED: Object type owning the list block at this+0xB00 is unidentified; it sits in the network-cleanup path so is likely a network message/connection list
    // UNRESOLVED: Semantics of the node byte flag at node+0x8 (data ownership) and the fourth head field this+0xB0C are undocumented
    // UNRESOLVED: WaitForSingleObject/ReleaseMutex are modeled as read globals via the IAT; their addresses are call targets, not data reads
}
