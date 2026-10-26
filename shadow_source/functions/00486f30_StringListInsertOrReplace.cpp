// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486F30
// Canonical corpus name: LinkedListInsertWithNodeAllocation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListInsertWithNodeAllocation_00486f30.c

void UnknownObject::StringListInsertOrReplace()
{
    // Manages a linked list of string nodes on a UI string-list object. When a3 <= 0, allocates a new string node and prepends it to the list (allocating an 8-byte string node then a 12-byte list node, linking head/tail and incrementing the count). When a3 > 0, seeks to that index and replaces the string content of the selected node via StringCopyWithBufferRealloc.
    // GUARD: If a3 <= 0, allocate new nodes and prepend to the list. [source:raw]
    // CALL: Allocate an 8-byte string node via OperatorNewNhMallocWrapper(8). [callee:0x00587C03, source:raw]
    // ASSIGNMENT: If allocation succeeded, zero the string pointer (*v7 = 0) and set v7[1] = -1 (empty/invalid marker). [source:raw]
    // CALL: Copy the source string a2 into the new node with StringCopyWithBufferRealloc(a2). [callee:0x00566650, source:raw]
    // CALL: Allocate a 12-byte list node via OperatorNewNhMallocWrapper(12). [callee:0x00587C03, source:raw]
    // ASSIGNMENT: If the list node allocated, link it to the string node: *v9 = string_node, *(v9+4) = 0 (next), *(v9+8) = 1 (in-use flag). [source:raw]
    // STATE_TRANSITION: If the list head this[17] is non-null, append via *(this[18]+4) = v9; otherwise set head this[17] = v9 and cursor this[19] = v9. [field:this:0x00000044, field:this:0x0000004C, source:raw]
    // ASSIGNMENT: Set tail this[18] = v9 and increment the list count this[20]. [field:this:0x00000048, field:this:0x00000050, source:raw]
    // GUARD: Else (a3 > 0): if a3 >= this[20] (count), clear the cursor this[19] = 0. [field:this:0x0000004C, field:this:0x00000050, source:raw]
    // LOOP: Otherwise walk from the head: set this[19] = this[17], then follow next pointers (offset +4) while decrementing a3 until it reaches 0, leaving this[19] at the selected node. [field:this:0x00000044, field:this:0x0000004C, source:raw]
    // GUARD: If the selected node v6 = this[19] is non-null and *v6 (its string) is non-null, replace its string with StringCopyWithBufferRealloc(a2). [callee:0x00566650, field:this:0x0000004C, source:raw]

    // Conservative worker pseudocode:
    //   if (a3 <= 0) {
    //     v8 = OperatorNewNhMallocWrapper(8);
    //     if (v8) { *v8 = 0; v8[1] = -1; StringCopyWithBufferRealloc(a2); }
    //     if (v8) {
    //       v9 = OperatorNewNhMallocWrapper(12);
    //       if (v9) { *(DWORD*)v9 = v8; *(DWORD*)(v9+4) = 0; *(BYTE*)(v9+8) = 1; }
    //       if (this[17]) *(DWORD*)(this[18]+4) = v9; else { this[17] = v9; this[19] = v9; }
    //       this[18] = v9;
    //       ++this[20];
    //     }
    //   } else {
    //     if (a3 >= this[20]) this[19] = 0;
    //     else {
    //       this[19] = this[17];
    //       while (this[19] && a3-- > 0) this[19] = *(DWORD*)(this[19]+4);
    //     }
    //     if (this[19] && *(DWORD*)this[19]) StringCopyWithBufferRealloc(a2);
    //   }
    // UNRESOLVED: The node layout (string pointer at +0, next link at +4, flag byte at +8) is inferred from the structural writes in the source; the exact struct shape is not separately evidenced.
    // UNRESOLVED: The semantic distinction between the a3 <= 0 prepend path and the a3 > 0 replace path (insert vs replace) is a DERIVED reading of the source, not confirmed by an external source.
    // UNRESOLVED: A failed list-node allocation on the prepend path still advances this[18] and increments this[20] even when v9 is 0, which may be a latent bug; not resolved.
}
