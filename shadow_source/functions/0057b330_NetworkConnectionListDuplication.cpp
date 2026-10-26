// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057B330
// Canonical corpus name: NetworkConnectionListDuplication
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkConnectionListDuplication_0057b330.c

void UnknownObject::NetworkConnectionListDuplication()
{
    // Duplicates two singly-linked lists from source object a2 into destination object this. First copies the connection flag byte (this+4) from the source, then frees any existing nodes in the destination's first list (freeing per-node data when the node flag byte is set) and its second list (ConditionalFreeByFlagCheck per node), zeroing the list heads/tails/counts. Then clones the source's first list: each source node's 16-byte socket-address entry is recreated (family word 2, htonl/htons zeroed port/address fields, 4 copied dwords) and wrapped in a 12-byte node linked into the destination first list with tail and count updates. Finally clones the source's second list: each 4-byte data word is copied into a fresh node built via ShortComputation_ac20 and appended to the destination second list with tail and count updates. Returns 1 (or 0 when the source is null).
    // GUARD: Return 0 immediately when the source object a2 is null. [source:raw]
    // ASSIGNMENT: Copy the connection flag byte this+4 = a2+4 from the source to the destination. [field:this:0x00000004]
    // LOOP: Free the destination's existing first-list nodes: walk from head this+8 via node next pointer at +4; when the node flag byte at +8 is set free the node's data (word at +0), then free the node itself. [field:this:0x00000008, field:*(this+0x8):0x00000000, field:*(this+0x8):0x00000008, field:*(*(this+0x8)+0x4):0x00000004, callee:0x00587BCF]
    // ASSIGNMENT: Zero the first-list bookkeeping fields this+8 (head), +0xC (tail), +0x10 (first node) and +0x14 (count). [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014]
    // LOOP: Free the destination's existing second-list nodes: walk from head this+0x18 via next pointer at +4, calling ConditionalFreeByFlagCheck(v8) on each node before freeing it. [field:this:0x00000018, field:*(this+0x18):0x00000008, callee:0x00582290, callee:0x00587BCF]
    // ASSIGNMENT: Zero the second-list bookkeeping fields this+0x18 (head), +0x1C (tail), +0x20 (first node) and +0x24 (count). [field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024]
    // ASSIGNMENT: Capture the source first-list head from a2+8 and mirror it into a2+16 (the source's own walk pointer). [source:raw]
    // LOOP: Clone the source first list: per source node allocate a 16-byte socket-address entry (family word set to 2, htonl(0)/htons(0) zeroed fields) and copy 4 dwords from the source node, then allocate a 12-byte wrapper node (data pointer, null next, active flag 1). [callee:0x00587C03, global:0x0059E2D8, global:0x0059E2F4]
    // ASSIGNMENT: Append the cloned wrapper to the destination first list: when head this+8 is null set head and first-node this+0x10, otherwise link the previous tail's next via *(this+0xC)+4; always update tail this+0xC and increment count this+0x14. [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:*(this+0xC):0x00000004]
    // LOOP: Advance the source first-list walker through the a2+16 chain, stopping when the next node or its data is null. [source:raw]
    // ASSIGNMENT: Capture the source second-list head from a2+0x18 and mirror it into a2+0x20. [source:raw]
    // LOOP: Clone the source second list: per source node allocate a 4-byte data block copied from the source word, then allocate a 12-byte node built via ShortComputation_ac20(node, data, 1). [callee:0x00587C03, callee:0x004BAC20]
    // ASSIGNMENT: Append the cloned node to the destination second list: when head this+0x18 is null set head and first-node this+0x20, otherwise link the previous tail's next via *(this+0x1C)+4; always update tail this+0x1C and increment count this+0x24. [field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:*(this+0x1C):0x00000004]
    // CALL: LinkedListNodeAdvance(v23) advances the source second-list iterator for each loop iteration. [callee:0x00581780]
    // RETURN: Return 1 on successful duplication. [source:raw]

    // Conservative worker pseudocode:
    //   char DuplicateNetworkConnectionLists(int this, int src) {
    //     if (!src) return 0;
    //     *(BYTE*)(this+4) = *(BYTE*)(src+4);
    //     for (int n = *(int*)(this+8); n; ) {
    //       int cur = n; n = *(int*)(cur+4);
    //       if (*(BYTE*)(cur+8)) FreeWrapper(*(void**)cur);
    //       FreeWrapper(cur);
    //     }
    //     *(int*)(this+8)=0; *(int*)(this+12)=0; *(int*)(this+16)=0; *(int*)(this+20)=0;
    //     for (int n = *(int*)(this+24); n; ) {
    //       int cur = n; n = *(int*)(cur+4);
    //       ConditionalFreeByFlagCheck(cur);
    //       FreeWrapper(cur);
    //     }
    //     *(int*)(this+24)=0; *(int*)(this+28)=0; *(int*)(this+32)=0; *(int*)(this+36)=0;
    //     int *head1 = *(int**)(src+8);
    //     *(int*)(src+16) = (int)head1;
    //     for (int *p = head1; p && *p; p = *(int**)p) {
    //       int e = OperatorNew(16);
    //       if (e) { *(WORD*)e = 2; *(int*)(e+4) = htonl(0); *(WORD*)(e+2) = htons(0); }
    //       *(int*)e   = ((int*)p)[0];
    //       *(int*)(e+4) = ((int*)p)[1];
    //       *(int*)(e+8) = ((int*)p)[2];
    //       *(int*)(e+12)= ((int*)p)[3];
    //       int node = OperatorNew(12);
    //       if (node) { *(int*)node = e; *(int*)(node+4) = 0; *(BYTE*)(node+8) = 1; }
    //       if (*(int*)(this+8)) *(int*)(*(int*)(this+12)+4) = node;
    //       else { *(int*)(this+8) = node; *(int*)(this+16) = node; }
    //       *(int*)(this+12) = node;
    //       *(int*)(this+20) = *(int*)(this+20) + 1;
    //     }
    //     int *head2 = *(int**)(src+24);
    //     *(int*)(src+32) = (int)head2;
    //     for (int *i = head2; i; i = LinkedListNodeAdvance(src+24)) {
    //       int d = OperatorNew(4); *d = *i;
    //       int node = OperatorNew(12);
    //       if (node) node = ShortComputation_ac20(node, (int)d, 1);
    //       if (*(int*)(this+24)) *(int*)(*(int*)(this+28)+4) = node;
    //       else { *(int*)(this+24) = node; *(int*)(this+32) = node; }
    //       *(int*)(this+28) = node;
    //       *(int*)(this+36) = *(int*)(this+36) + 1;
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: SEH_57B330 (0x0059C7BB) is listed in packet globals but not referenced in the function body source; it is a compiler-emitted SEH scope table/registration address.
    // UNRESOLVED: The function mutates the source object a2 (a2+16 and a2+32) as walk pointers while duplicating; whether this is intentional state consumption or a quirk is not settled.
    // UNRESOLVED: Exact socket-address layout of the 16-byte first-list entries (family word 2, htons/htonl zeroed fields) is inferred from the written constants; the remaining copied dwords are opaque.
    // UNRESOLVED: Semantics of ShortComputation_ac20's second argument (a 4-byte data block pointer) and the meaning of the second-list data words are external to this packet.
}
