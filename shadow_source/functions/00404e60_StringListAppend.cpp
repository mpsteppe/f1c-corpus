// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404E60
// Canonical corpus name: LinkedListNodeInsertion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeInsertion_00404e60.c

void UnknownObject::StringListAppend()
{
    // Appends a string to a linked list whose control block lives at (*this)+64 (four dwords: head at +0x40, tail at +0x44, aux at +0x48, count at +0x4C). Allocates an 8-byte buffer via OperatorNewNhMallocWrapper, prefills it with 0 at +0 and -1 at +4, fills it with a copy of the input through StringCopyWithBufferRealloc, then allocates a 12-byte node holding the string pointer at +0, 0 at +4 and a byte flag of 1 at +8, and links it either as the new tail (non-empty list) or as head/aux/tail (empty list), incrementing the count.
    // CALL: Allocate an 8-byte string buffer via OperatorNewNhMallocWrapper(8); the allocation result gates the string-copy branch [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the buffer: dword 0 at +0 and -1 at +4, then StringCopyWithBufferRealloc(a2) fills it with a copy of the input string [callee:0x00566650, source:raw]
    // GUARD: If the 8-byte allocation failed, the string pointer v5 is 0 and no node is created [source:raw]
    // CALCULATION: v6 = (int*)(*this + 64) locates the list control block one level past the object pointer stored at this+0 [field:this:0x00000000, source:raw]
    // CALL: Allocate a 12-byte list node via OperatorNewNhMallocWrapper(12); on success the node stores the string pointer at +0, 0 at +4 and 1 as a byte flag at +8 [callee:0x00587C03, source:raw]
    // GUARD: If the 12-byte node allocation failed, result stays 0 and the node is not linked into the list [source:raw]
    // ASSIGNMENT: Non-empty-list path: previous tail's next pointer is set to the new node, tail at obj+0x44 advances, and count at obj+0x4C increments [field:obj:0x00000040, field:obj:0x00000044, field:obj:0x0000004C, source:raw]
    // ASSIGNMENT: Empty-list path: head at obj+0x40, aux at obj+0x48 and tail at obj+0x44 all become the new node, and count at obj+0x4C is set to 1 [field:obj:0x00000040, field:obj:0x00000044, field:obj:0x00000048, field:obj:0x0000004C, source:raw]
    // RETURN: Returns the linked node pointer on success, or 0 when either allocation failed [source:raw]
    // CALL: Reached from ResourceListCleanup (00404d50) and ConfigIniParser (00421cd0) as a shared string-list append helper [caller:0x00404D50, caller:0x00421CD0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_404E60(this, a2) {
    //     v4 = OperatorNewNhMallocWrapper(8);
    //     if (v4) { *(DWORD*)v4 = 0; *(DWORD*)(v4 + 4) = -1; StringCopyWithBufferRealloc(a2); v5 = v4; }
    //     else v5 = 0;
    //     v6 = (int*)(*this + 64);
    //     if (v5) {
    //       node = OperatorNewNhMallocWrapper(12);
    //       if (node) { node[0] = v5; node[1] = 0; node[8] = 1; } else node = 0;
    //       if (v6[0]) { *(v6[1] + 4) = node; v6[1] = node; ++v6[3]; }
    //       else { v6[0] = node; v6[2] = node; v6[1] = node; v6[3] = 1; }
    //     }
    //     return node;
    //   }
    // UNRESOLVED: Purpose of the aux dword at obj+0x48 (written only on first insertion) is unknown; it may be a list cursor distinct from the tail.
    // UNRESOLVED: Semantics of the byte flag at node+8 set to 1 and of the -1 prefill in the string buffer's second dword are unknown.
    // UNRESOLVED: Owner class of the list control block is unknown; callers span config parsing and resource-list management.
}
