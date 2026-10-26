// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FD840
// Canonical corpus name: DualLinkedListDestruction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualLinkedListDestruction_004fd840.c

void UnknownObject::DualLinkedListDestruction()
{
    // Destroys two linked lists on the object. First list walked from this+0x3C with each node's next at node+0xC; nodes are freed until the next pointer is null and this+0x38 is cleared. Second list walked from this+0x54 with each node holding a sub-pointer at +0, next at +4, and a flag byte at +8; the sub-pointer is freed when the flag is non-zero and each node is freed via the loop condition. All second-list tracking fields this+0x54 through this+0x60 are cleared to null before returning.
    // ASSIGNMENT: Save the first-list head from this+0x3C into the return accumulator and clear this+0x38 to null. [field:this:0x0000003C, field:this:0x00000038, source:raw]
    // GUARD: If the saved first-list head at this+0x3C is null, skip the first-list cleanup entirely. [field:this:0x0000003C, source:raw]
    // LOOP: First-list walk: read the next node pointer at node+0xC, free the current node, advance this+0x3C to that next, repeat while the next is non-null. [field:this:0x0000003C, field:*(this+0x3C):0x0000000C, source:raw]
    // CALL: FreeWrapper_7bcf frees each first-list node. [callee:0x00587BCF, source:raw]
    // LOOP: Second-list walk from this+0x54: capture the node, read next at node+4, free the node in the loop increment, continue while next is non-null. [field:this:0x00000054, field:*(*(this+0x54)+0x4):0x00000004, source:raw]
    // GUARD: Guard comparing the second-list node flag byte at node+8 to 0; when equal the sub-pointer is not freed. [guard:0, field:*(this+0x54):0x00000008, source:raw]
    // CALL: FreeWrapper_7bcf frees the second-list node sub-pointer at node+0 when the flag byte is non-zero. [callee:0x00587BCF, field:*(this+0x54):0x00000000, source:raw]
    // CALL: FreeWrapper_7bcf frees each second-list node. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Clear the second-list tracking fields this+0x54, this+0x58, this+0x5C and this+0x60 to null. [field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060, source:raw]
    // RETURN: Return the last FreeWrapper result accumulated through both walks. [source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall sub_4FD840(int this) {
    //     int result = *(this + 60);
    //     *(this + 56) = 0;
    //     if (result) {
    //       do {
    //         int next = *(*(this + 60) + 12);
    //         result = FreeWrapper_7bcf(*(this + 60));
    //         *(this + 60) = next;
    //       } while (next);
    //     }
    //     for (int i = *(this + 84); i; result = FreeWrapper_7bcf(i)) {
    //       int node = i;
    //       bool skip = *((char*)i + 8) == 0;
    //       i = *(i + 4);
    //       if (!skip) FreeWrapper_7bcf(*(void**)node);
    //     }
    //     *(this + 84) = 0; *(this + 88) = 0;
    //     *(this + 92) = 0; *(this + 96) = 0;
    //     return result;
    //   }
    // UNRESOLVED: Identity of the object owning the two lists and the semantics of the second-list sub-pointer flag byte.
}
