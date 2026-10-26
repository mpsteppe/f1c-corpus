// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B54E0
// Canonical corpus name: NetworkMessageDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkMessageDispatch_004b54e0.c

void UnknownObject::NetworkMessageDispatch()
{
    // Dispatches a network message (a2) into a message-list object. Extracts a 6-bit message type and a flag byte from a2, walks the active singly-linked entry list (this+0x20) for an existing node with matching type (+0x368) and flag (+0x36C); if none matches it reuses a free-list node (this+0x10, removed via DoublyLinkedListNodeRemoval) or allocates and constructs a fresh one (OperatorNewNhMallocWrapper + sub_4BA980, registered via CollisionNodeListInsertion). Reinitializes the node identity/value fields, appends a 12-byte entry to the active list, increments the entry count, then calls ZoneThresholdComparisonWithConditionalAction(node, *(float*)(this+0x30), msg). Called by sub_4B9000.
    // CALCULATION: Extract 6-bit message type from a2: (*(_DWORD*)a2 >> 18) & 0x3F; used as the node lookup key. [source:raw]
    // CALCULATION: Read message flag byte at a2+8 (saved as v16); second node lookup key. [source:raw]
    // ASSIGNMENT: Set walk position (this+0x28) to the active list head (this+0x20). [field:this:0x00000020, field:this:0x00000028]
    // GUARD: If active list head (this+0x20) is non-null and its first node (*(this+0x20)) is non-null, walk for an existing matching node; otherwise fall through to the node-creation path. [field:this:0x00000020, field:*(this+0x20):0x00000000]
    // LOOP: Walk active list: while node type (+0x368) differs from the message type or node flag (+0x36C) differs from the message flag, advance the walk position via the entry next link (+0x4) and re-read the node pointer (*(this+0x28)). [field:*(*(this+0x28)+0x0):0x00000368, field:*(*(this+0x28)+0x0):0x0000036C, field:*(this+0x28):0x00000000, field:*(this+0x28):0x00000004]
    // GUARD: If the walk exhausts without a type/flag match, proceed to the free-list reuse / fresh-allocation path. [field:this:0x00000010]
    // ASSIGNMENT: Save a copy of the free-list head (this+0x10) into this+0x18 (temporary head). [field:this:0x00000018, field:this:0x00000010]
    // GUARD: If the free-list head (this+0x10) is non-null, pop its node pointer (*(this+0x10)) for reuse; else node = 0. [field:this:0x00000010, field:*(this+0x10):0x00000000]
    // ASSIGNMENT: Clear the popped free-list node flag byte at node+8. [field:*(this+0x10):0x00000008]
    // CALL: DoublyLinkedListNodeRemoval(free list at this+0x10, popped node value, 1); if it returns false, the popped node is discarded (node = 0). [callee:0x004BA7A0, field:this:0x00000010, field:*(this+0x10):0x00000000]
    // GUARD: If no reusable node is available, allocate and construct a fresh node. [source:raw]
    // CALL: OperatorNewNhMallocWrapper(4) allocates the node struct (null on OOM). [callee:0x00587C03]
    // CALL: sub_4BA980(allocated, 0) constructs/initializes the new node; result may be null. [callee:0x004BA980]
    // CALL: CollisionNodeListInsertion(this, node, 0) registers the node in the collision/dynamic list. [callee:0x004BAD70]
    // CALL: LinkedListRemoveByValue(this+0x10) removes the node value from the temporary list and yields the node to use. [callee:0x004BAE20, field:this:0x00000010]
    // CALL: ThunkWithStructInitSubCalls(node) resets the node before the identity fields are written. [callee:0x004FFFA0]
    // ASSIGNMENT: Reset node identity/value fields: flag (+0x36C) = 0xFF, type (+0x368) = 0, value (+0x370) = -51331646. [field:*(*(this+0x10)+0x0):0x0000036C, field:*(*(this+0x10)+0x0):0x00000368, field:*(*(this+0x10)+0x0):0x00000370]
    // ASSIGNMENT: Write message keys and threshold value into the node: type (+0x368) = message type, flag (+0x36C) = message flag, value (+0x370) = float at this+0x30. [field:*(*(this+0x10)+0x0):0x00000368, field:*(*(this+0x10)+0x0):0x0000036C, field:*(*(this+0x10)+0x0):0x00000370, field:this:0x00000030]
    // CALL: OperatorNewNhMallocWrapper(12) allocates a 12-byte active-list entry, initialized to {node, next=0, flags=0}. [callee:0x00587C03]
    // ASSIGNMENT: Append the entry to the active list: if head (this+0x20) is non-null, link the tail entry's next slot (*(this+0x24)+4) = entry; otherwise set head (this+0x20) = entry and walk position (this+0x28) = entry. [field:this:0x00000020, field:this:0x00000024, field:*(this+0x24):0x00000004, field:this:0x00000028]
    // ASSIGNMENT: Update active list tail (this+0x24) = entry and increment the entry count (this+0x2C). [field:this:0x00000024, field:this:0x0000002C]
    // CALL: ZoneThresholdComparisonWithConditionalAction(node, *(float*)(this+0x30), message) compares the node value against the threshold and may trigger a conditional action. [callee:0x004FFFB0, field:this:0x00000030, source:raw]

    // Conservative worker pseudocode:
    //   void NetworkMessageDispatch(this, msg) {
    //     int msgType = ((int)*(dword*)msg >> 18) & 0x3F;
    //     char msgFlag = *(byte*)(msg + 8);
    //     walkPos(this+0x28) = activeHead(this+0x20);
    //     if (activeHead && *activeHead) {
    //       node = *activeHead;
    //       while (node->type(0x368) != msgType || node->flag(0x36C) != msgFlag) {
    //         walkPos = walkPos ? *((dword*)walkPos + 1) : 0;
    //         node = walkPos ? *(dword*)walkPos : 0;
    //         if (!node) break;
    //       }
    //       if (!node) {
    //         node = createOrReuseNode();
    //       }
    //     } else {
    //       node = createOrReuseNode();
    //     }
    //     ThunkWithStructInitSubCalls(node);
    //     node->flag(0x36C) = 0xFF;
    //     node->type(0x368) = 0;
    //     node->value(0x370) = -51331646;
    //     node->type(0x368) = msgType;
    //     node->flag(0x36C) = msgFlag;
    //     node->value(0x370) = *(float*)(this + 0x30);
    //     entry = OperatorNewNhMallocWrapper(12);
    //     if (entry) { *(dword*)entry = node; *((dword*)entry + 1) = 0; *(byte*)(entry + 8) = 0; }
    //     if (activeHead(this+0x20)) { *(dword*)(*(this+0x24) + 4) = entry; }
    //     else { *(dword*)(this+0x20) = entry; *(dword*)(this+0x28) = entry; }
    //     *(dword*)(this+0x24) = entry;
    //     ++*(dword*)(this+0x2C);
    //     ZoneThresholdComparisonWithConditionalAction(node, *(float*)(this+0x30), msg);
    //   }
    // UNRESOLVED: dword_5ACD24 (global:0x005ACD24) is listed as referenced but does not appear in the raw decompiled body; its role here is unclear (existing analysis proposes D3DRenderDefaultColor, DERIVED, unverified).
    // UNRESOLVED: Message layout is only partially evidenced: a2+0 dword packs a 6-bit type at bits 18..23 and a2+8 holds a flag byte; no evidence pins the packet/type enum.
    // UNRESOLVED: Node layout beyond +0x368 (type), +0x36C (flag), +0x370 (value) is unknown; identity/value field semantics are DERIVED from use, and sub_4BA980's constructor behavior is unproven.
    // UNRESOLVED: Whether the type/flag lookup is a message coalescing cache rather than a plain duplicate check is GUESS; the node is reinitialized with the same keys in both paths.
}
