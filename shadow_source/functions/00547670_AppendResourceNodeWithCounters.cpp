// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00547670
// Canonical corpus name: sub_547670
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_547670_00547670.c

void UnknownObject::AppendResourceNodeWithCounters()
{
    // Appends node a2 to a singly linked list rooted at this+0x24. When the list is non-empty it walks from the head to the tail using each node's next pointer at +0xC0, then links the tail to a2; when empty it makes a2 the head. Sets a2's previous pointer to the old tail and its next pointer (+0xC0) to null. Then inspects a2's flag word (+0x9C) and increments the total counter this+0x10 plus one of four bucket counters (this+0x14/0x18/0x1C/0x20) chosen by flag bits 0x20 and 0x100. Returns the new total count.
    // ASSIGNMENT: Read the list head from this[9] (this+0x24) into v2 and seed v3 with it. [field:this:0x00000024, source:raw]
    // GUARD: Branch on the list head: non-null walks to the tail; null takes the empty-list path that makes a2 the head. [source:raw]
    // LOOP: Walk the list from the head via each node's next pointer at +0xC0 until the tail node is reached (v3 = last node). [field:*(*(this+0xE4)+0xC0):0x000000C0, source:raw]
    // ASSIGNMENT: Set the tail node's next pointer at +0xC0 to the new node a2. [field:*(*(this+0xE4)+0xC0):0x000000C0, source:raw]
    // ASSIGNMENT: Empty-list path: set the list head this+0x24 to the new node a2. [field:this:0x00000024, source:raw]
    // ASSIGNMENT: Set a2[47] (previous-node pointer) to the old tail (or null on the empty-list path). [source:raw]
    // ASSIGNMENT: Set a2's next pointer at +0xC0 to null, terminating the list. [field:*(*(this+0xE4)+0xC0):0x000000C0, source:raw]
    // ASSIGNMENT: Read a2's flag word a2[39] (+0x9C) into v6 for the counter classification. [source:raw]
    // CALCULATION: Compute the new total count as this[4] + 1 (total counter at this+0x10, incremented unconditionally). [field:this:0x00000010, source:raw]
    // GUARD: Branch on flag bit 0x20 of v6 to select the counter bucket group. [source:raw]
    // STATE_TRANSITION: Flag bit 0x20 set and bit 0x100 set: increment bucket counter this+0x1C. [field:this:0x0000001C, source:raw]
    // STATE_TRANSITION: Flag bit 0x20 set and bit 0x100 clear: increment bucket counter this+0x20. [field:this:0x00000020, source:raw]
    // STATE_TRANSITION: Flag bit 0x20 clear and bit 0x100 set: increment bucket counter this+0x14. [field:this:0x00000014, source:raw]
    // STATE_TRANSITION: Flag bit 0x20 clear and bit 0x100 clear: increment bucket counter this+0x18. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Write the incremented total count back to this+0x10. [field:this:0x00000010, source:raw]
    // RETURN: Return the new total count. [source:raw]

    // Conservative worker pseudocode:
    //   int AppendResourceNode(DWORD *this, DWORD *a2) {
    //     DWORD *tail = this[9];
    //     if (tail) {
    //       DWORD *n;
    //       for (n = *(DWORD *)(tail + 192); n; n = *(DWORD *)(n + 192)) tail = n;
    //       *(DWORD *)(tail + 192) = a2;
    //     } else {
    //       this[9] = a2;
    //     }
    //     a2[47] = tail;
    //     a2[48] = 0;
    //     int flags = a2[39];
    //     int total = this[4] + 1;
    //     if (flags & 0x20) {
    //       if (flags & 0x100) ++this[7]; else ++this[8];
    //     } else {
    //       if (flags & 0x100) ++this[5]; else ++this[6];
    //     }
    //     this[4] = total;
    //     return total;
    //   }
    // UNRESOLVED: Node links use a2[47]/a2[48] (offsets 0xBC/0xC0 per the decompiled source); only the +0xC0 slot is present in the packet field evidence.
    // UNRESOLVED: Semantics of the four bucket counters (this+0x14/0x18/0x1C/0x20) are DERIVED resource-type classifications, not confirmed.
    // UNRESOLVED: this+0xE4 is read per packet field evidence but has no visible use in the decompiled source text.
    // UNRESOLVED: Field evidence base "*(*(this+0xE4)+0xC0)" disagrees with the source walk (head at this[9]/this+0x24); the +0xC0 next-pointer association is the shared fact.
}
