// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00407520
// Canonical corpus name: LinkedListNodeInsert
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeInsert_00407520.c

void UnknownObject::insertFileResourceByKey()
{
    // Inserts a file-backed resource node into an intrusive linked list keyed by integer a3. On entry, if a2 is non-null it first consumes the two-element a2 pair (StringCopyWithBufferRealloc on a2[0], sub_5665B0 on a2[1]) as resource identification. It then walks the list from the head (this+0x38) via the cursor this+0x40, advancing each step through the node's next pointer at +4, and aborts if a node whose key (first dword of the node pointed at by the cursor) already equals a3. After a validity check through sub_588410(&byte_5EA438, &byte_5EA438), it allocates a 116-byte node, initializes it with ShortComputation_53e0, opens a file handle via sub_587DB0(&byte_5EA438, aRb), and on a successful read stores the file-handle-derived size into the node (v14[4] = StructFieldGetterAt0x10(v14[3])), records the key *v14 = a3, and links a newly allocated 12-byte list element into the list, updating head (this+0x38), tail (this+0x3C), cursor (this+0x40) and the node count (this+0x44), returning 1. On any failure path it closes the file handle, runs MultiStageCleanupWithFree and FreeWrapper_7bcf on the node, and returns 0.
    // GUARD: If a2 is null, return 0 immediately without doing any work. [function:0x00407520, source:raw]
    // CALL: Consume a2[0]: if it is non-null, pass it to StringCopyWithBufferRealloc. [callee:0x00566650, source:raw]
    // CALL: Consume a2[1]: if it is non-null, pass it to sub_5665B0. [callee:0x005665B0, source:raw]
    // ASSIGNMENT: Start the list traversal: cursor this+0x40 (this[16]) is initialized to the head this+0x38 (this[14]). [field:this:0x00000040, field:this:0x00000038, source:raw]
    // LOOP: Walk the list: while the key (first dword of the node pointed at by the cursor, *(this+0x40)) differs from a3, advance the cursor to the node's next pointer at +4 (this[16] = *(this[16]+4)); if the walk ends or a matching key is found, set the duplicate flag v18 when the key equals a3. [field:this:0x00000040, field:*(this+0x40):0x00000000, source:raw]
    // CALL: Validity gate: call sub_588410(&byte_5EA438, &byte_5EA438); if it returns zero, return 0 without inserting. [callee:0x00588410, global:0x005EA438, source:raw]
    // GUARD: If the duplicate-key flag v18 is set (a node with key a3 already present), return 0. [source:raw]
    // CALL: Allocate the 116-byte resource node with OperatorNewNhMallocWrapper(116); if allocation fails return 0. [callee:0x00587C03, source:raw]
    // CALL: Initialize the allocated node via ShortComputation_53e0(v13), yielding v14; if it returns null return 0. [callee:0x004053E0, source:raw]
    // CALL: Open/attach the file handle: v15 = sub_587DB0(&byte_5EA438, aRb) and store it into node field v14[3]. [callee:0x00587DB0, global:0x005EA438, global:0x005BE828, source:raw]
    // CALL: Read the file content into the node via MemoryAllocationWithBufferRead(v14); the success branch (recorded as returning zero here) proceeds to finalize the node. [callee:0x004080F0, source:raw]
    // ASSIGNMENT: On the successful read path: set node size v14[4] = StructFieldGetterAt0x10(v14[3]) and record the key *v14 = a3; then re-invoke StringCopyWithBufferRealloc(&byte_5EA438) as part of the finalize step. [callee:0x0059B758, callee:0x00566650, global:0x005EA438, source:raw]
    // CALL: Allocate the 12-byte list element via OperatorNewNhMallocWrapper(12); if non-null initialize it as *(v16) = v14 (node), *(v16+4) = 0 (next), *(v16+8) = 1. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Link the element into the list: if the head this+0x38 (this[14]) is non-null set the tail this+0x3C node's next pointer (*(this[15]+4)) to v16; otherwise set head this+0x38 = v16 and cursor this+0x40 = v16. Always update tail this+0x3C = v16, increment the node count this+0x44 (this[17]) and return 1. [field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, source:raw]
    // CALL: Failure path (read failed or handle absent): FileCloseWithLock(v14[3]) then v14[3] = 0, then MultiStageCleanupWithFree(v14) and FreeWrapper_7bcf(v14), returning 0. [callee:0x00587D02, callee:0x00405410, callee:0x00587BCF, source:raw]
    // RETURN: Returns 1 on a successful insertion, 0 on every early-abort and failure path. [source:raw]

    // Conservative worker pseudocode:
    //   if (!a2) return 0;
    //   if (a2[0]) StringCopyWithBufferRealloc(a2[0]);
    //   if (a2[1]) sub_5665B0(a2[1]);
    //   cursor = this[14];                      // this+0x38 head
    //   dup = 0;
    //   for (node = (cursor ? *cursor : 0); node && *node != a3; node = (this[16] ? *(this[16]+4) : 0)) { this[16] = this[16] ? *(this[16]+4) : 0; }
    //   if (*node == a3) dup = 1;
    //   if (!sub_588410(&byte_5EA438, &byte_5EA438)) return 0;
    //   if (dup) return 0;
    //   v13 = OperatorNewNhMallocWrapper(116); if (!v13) return 0;
    //   v14 = ShortComputation_53e0(v13); if (!v14) return 0;
    //   v14[3] = sub_587DB0(&byte_5EA438, aRb);
    //   if (v14[3]) {
    //     if (MemoryAllocationWithBufferRead(v14) == 0) {
    //       v14[4] = StructFieldGetterAt0x10(v14[3]);
    //       *v14 = a3;
    //       StringCopyWithBufferRealloc(&byte_5EA438);
    //       v16 = OperatorNewNhMallocWrapper(12);
    //       if (v16) { *(v16) = v14; *(v16+4) = 0; *(v16+8) = 1; }
    //       if (this[14]) *(this[15]+4) = v16; else { this[14] = v16; this[16] = v16; }
    //       this[15] = v16;
    //       ++this[17];
    //       return 1;
    //     }
    //     FileCloseWithLock(v14[3]);
    //     v14[3] = 0;
    //   }
    //   MultiStageCleanupWithFree(v14);
    //   FreeWrapper_7bcf(v14);
    //   return 0;
    // UNRESOLVED: The success branch is entered when MemoryAllocationWithBufferRead(v14) returns zero, which is the inverse of the helper's label 'returns non-zero on success'; the exact return contract of that helper is not evidenced by this packet.
    // UNRESOLVED: sub_588410 is invoked with two identical arguments (&byte_5EA438, &byte_5EA438); its guard role and the meaning of byte_5EA438 (labelled a directory/path default) are opaque from the raw text.
    // UNRESOLVED: The two-element a2 pair is consumed before insertion (StringCopyWithBufferRealloc on a2[0], sub_5665B0 on a2[1]) but its meaning (e.g. path/name components of the resource) is not evidenced here.
    // UNRESOLVED: Packet field list marks this+0x44 as read-only while the raw source increments it (++this[17]) on insertion; the count interpretation is DERIVED from that write, not confirmed.
}
