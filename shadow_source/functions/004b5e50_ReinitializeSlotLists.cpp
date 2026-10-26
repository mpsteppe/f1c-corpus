// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B5E50
// Canonical corpus name: sub_4B5E50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B5E50_004b5e50.c

void UnknownObject::ReinitializeSlotLists()
{
    // Iterates 104 per-slot list records (16 bytes each) starting at this+0x40. For every non-empty slot it drains the linked node list: for each node it locates the node by its data pointer, unlinks it from the slot list (adjusting slot head/tail/current/count), frees the node and, when its +8 flag is set, its data payload, reinitializes the data via StructInitWithGlobalData, allocates a fresh 12-byte node via OperatorNewNhMallocWrapper, and prepends it into the object's output list at this+0x10 (head/tail/current/count). Returns the slot counter after the loop.
    // LOOP: Outer do-while: iterates 104 slot records, one per iteration, starting at the record at this+0x40 and advancing by 16 bytes each time. [field:this:0x00000040, source:raw]
    // ASSIGNMENT: At the start of each slot iteration the slot current pointer this+0x48 is set equal to the slot head this+0x40. [field:this:0x00000040, field:this:0x00000048, source:raw]
    // GUARD: The slot's inner processing is skipped when its head this+0x40 is null (packet guard). [guard:0, field:this:0x00000040, source:raw]
    // ASSIGNMENT: Capture the head node's data pointer (node+0) as the key used for re-initialization and node matching. [field:*(this+0x40):0x00000000, source:raw]
    // LOOP: Inner do-while walks the slot's node list, restarting from the slot head each pass and following node+4 (next) links to locate the node whose data (node+0) matches the captured key. [field:*(this+0x40):0x00000000, field:*(this+0x40):0x00000004, source:raw]
    // ASSIGNMENT: Unlink the matched node from the slot list: the predecessor's node+4 link, or the slot head this+0x40 when there is no predecessor, is set to the removed node's next; the slot current this+0x48 is advanced to node next when the removed node was current, and the slot tail this+0x44 moves to the predecessor when the removed node was tail. [field:*(this+0x40):0x00000004, field:this:0x00000040, field:this:0x00000048, field:this:0x00000044, source:raw]
    // ASSIGNMENT: Decrement the slot count this+0x4C for each node removed from the slot. [field:this:0x0000004C, source:raw]
    // GUARD: When the removed node's +8 flag byte is set, its data pointer (node+0) is released before the node itself is freed. [field:*(this+0x40):0x00000008, field:*(this+0x40):0x00000000, source:raw]
    // CALL: EmptyStub_0170 is invoked before the node payload is released. [callee:0x004B0170, source:raw]
    // CALL: FreeWrapper_7bcf releases the node's data pointer when the flag is set. [callee:0x00587BCF, field:*(this+0x40):0x00000000, source:raw]
    // CALL: FreeWrapper_7bcf releases the node wrapper itself. [callee:0x00587BCF, field:*(this+0x40):0x00000004, source:raw]
    // CALL: StructInitWithGlobalData reinitializes the underlying data record for the node being moved into the output list. [callee:0x004B4F70, field:*(this+0x40):0x00000000, source:raw]
    // CALL: OperatorNewNhMallocWrapper(12) allocates a fresh 12-byte output-list node wrapper. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the new node wrapper: node+0 stores the reinitialized data, node+4 (next) is cleared, and the node+8 flag byte is cleared. [field:*(this+0x40):0x00000000, field:*(this+0x40):0x00000004, field:*(this+0x40):0x00000008, source:raw]
    // ASSIGNMENT: Prepend the new node into the output list: when the output head this+0x10 is non-null the new node's node+4 link is set to it, otherwise the output tail this+0x14 and output current this+0x18 are both set to the new node. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:*(this+0x40):0x00000004, source:raw]
    // ASSIGNMENT: Advance the output list: the output count this+0x1C is incremented and the output head this+0x10 is set to the new node. [field:this:0x0000001C, field:this:0x00000010, source:raw]
    // RETURN: Return the decremented slot counter, which reaches 0 once all 104 slots have been processed. [source:raw]

    // Conservative worker pseudocode:
    //   result = 104;
    //   v2 = (char*)this + 0x40;                       // slot record: head/current at +0/+8, tail at +4, count at +0xC
    //   do {
    //       head = *(this + 0x40);                     // slot head
    //       *(this + 0x48) = *(this + 0x40);           // slot current = slot head
    //       if (head) {
    //           key = *(head + 0);                     // data of head node
    //           do {
    //               // locate node with node+0 == key by walking node+4 links
    //               // unlink it; adjust slot head/tail/current; decrement slot count
    //               if (*(node + 8)) FreeWrapper_7bcf(*(node + 0));   // payload release
    //               FreeWrapper_7bcf(node);
    //               StructInitWithGlobalData(key);
    //               nn = OperatorNewNhMallocWrapper(12);
    //               *(nn + 0) = key; *(nn + 4) = 0; *(nn + 8) = 0;
    //               if (out_head) *(nn + 4) = out_head; else { out_tail = nn; out_cur = nn; }
    //               out_head = nn; out_count++;
    //               head = *(this + 0x40);             // slot head
    //               *(this + 0x48) = *(this + 0x40);   // slot current = slot head
    //           } while (head);
    //       }
    //       v2 += 16;
    //   } while (--result);
    //   return result;
    // UNRESOLVED: Node second field at +0xC is flagged as read by the packet facts but never appears in the rendered pseudocode; its role is unknown in this function.
    // UNRESOLVED: The output-list node layout (data, next, flag) is inferred from the 12-byte allocation and the link writes; the slot records after the first are the stride-16 array repeats of the this+0x40..0x4C record and are not listed individually by the packet.
}
