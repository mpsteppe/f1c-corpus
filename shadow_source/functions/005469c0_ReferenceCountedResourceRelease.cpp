// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005469C0
// Canonical corpus name: ReferenceCountedResourceRelease
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ReferenceCountedResourceRelease_005469c0.c

void UnknownObject::ReferenceCountedResourceRelease()
{
    // Reference-counted resource release. Returns -2 immediately if the release-blocking flag bit (this+0x9C bit 2) is set. Otherwise decrements both ref counts at this+0x84 and this+0x88; if this+0x88 is still non-zero it returns -2 (more references outstanding). When the count reaches zero it iterates the sub-resource slots at this+0xA8 (count this+0xA4), finds each slot's node in the linked list headed at this+0xB8, decrements that node's reference count, and when it reaches zero destructs its per-element data (count at node+0x4C), removes the node with DoublyLinkedListNodeRemovalWithArrayCleanup, and zeroes the slot pointer. Finally ORs this+0x9C with 3 and returns 0.
    // GUARD: Release-blocking check: if bit 1 of the flags at this+0x9C is set, return -2 immediately without touching ref counts. [field:this:0x0000009C, source:raw]
    // CALCULATION: Decrement both ref counts: this+0x84 and this+0x88 are each reduced by 1. [field:this:0x00000084, field:this:0x00000088, source:raw]
    // RETURN: If the remaining count this+0x88 is still non-zero, return -2 (further references are alive). [field:this:0x00000088, source:raw]
    // GUARD: Outer sub-resource loop only runs when the slot count this+0xA4 is greater than 0. [guard:0, field:this:0x000000A4, source:raw]
    // LOOP: Walk the sub-resource slots starting at this+0xA8, advancing 37 dwords (148 bytes) per slot, once per slot in this+0xA4. [field:this:0x000000A8, field:this:0x000000A4, source:raw]
    // CALCULATION: Match the slot's node pointer (stored at the sub-resource slot offset 0x8C) against the linked list headed at this+0xB8: walk nodes from list-head + 0x28 following the next pointer at dword index 23 until a match or the end of the list. [field:*(this+0xB8):0x00000028, field:*(*(this+0xB8)+0x28):0x000000B8, field:this:0x000000B8, field:*(this+0xA8):0x0000008C, source:raw]
    // CALCULATION: Decrement the matched node's reference count (field 0x0 of the sub-resource node); when it drops from 1 to 0 the node is freed. [field:*(*(this+0xA8)+0x8C):0x00000000, source:raw]
    // GUARD: Per-element destruction only runs when the node's element count (at node + 0x4C) is greater than 0. [guard:1, field:*(*(this+0xA8)+0x8C):0x0000004C, source:raw]
    // LOOP: Loop over the node's elements in 24-byte steps, calling DestructorWithConditionalFreeFlagClear on each element pointer. [field:*(*(this+0xA8)+0x8C):0x0000004C, callee:0x005502C0, source:raw]
    // CALL: DoublyLinkedListNodeRemovalWithArrayCleanup unlinks the node from the linked list and cleans up its backing array. [callee:0x005478B0, source:raw]
    // ASSIGNMENT: Zero the sub-resource slot pointer at the node (this+0xA8 + 0x8C), marking the slot released. [field:*(this+0xA8):0x0000008C, source:raw]
    // STATE_TRANSITION: On successful release OR the flags at this+0x9C with 3, marking the resource as released/cleaned. [field:this:0x0000009C, source:raw]
    // RETURN: Return 0 on a fully completed release. [source:raw]
    // CALL: Invoked by sub_547710 (00547710) and LinkedListWalkWithExitCheck (005487E0). [caller:0x00547710, caller:0x005487E0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_5469C0(int this) {
    //     if (this[0x9C/4] & 2) return -2;
    //     --this[0x84/4];
    //     int remaining = --this[0x88/4];
    //     if (remaining) return -2;
    //     if (this[0xA4/4] > 0) {
    //       _DWORD *slot = this[0xA8/4] + 140/4;
    //       for (int n = 0; n < this[0xA4/4]; ++n, slot += 37) {
    //         _DWORD *node = *slot;
    //         _DWORD *walk = *(this[0xB8/4] + 40/4);
    //         while (walk && walk != node) walk = walk[23];
    //         if (walk == node && --node[0] == 0) {
    //           if (node[76/4] > 0)
    //             for (int e = 0; e < node[76/4]; ++e)
    //               DestructorWithConditionalFreeFlagClear(node + e * 24/4);
    //           DoublyLinkedListNodeRemovalWithArrayCleanup(node);
    //           *slot = 0;
    //         }
    //       }
    //     }
    //     this[0x9C/4] |= 3;
    //     return 0;
    //   }
    // UNRESOLVED: The linked-list node layout (next pointer at dword index 23, element count at 0x4C, ref count at 0x0) is only partially recovered; the head pointer at this+0xB8 and its +0x28 indirection are read as two distinct evidence fields whose exact object roles are not established.
    // UNRESOLVED: The 148-byte sub-resource slot stride and the 24-byte element stride are inferred from the loop increments and have no named struct backing.
    // UNRESOLVED: The meaning of returning -2 versus 0 to the caller (sub_547710, LinkedListWalkWithExitCheck) is not established by this packet.
}
