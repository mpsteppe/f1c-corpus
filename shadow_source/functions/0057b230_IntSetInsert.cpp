// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057B230
// Canonical corpus name: IntSetInsert
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IntSetInsert_0057b230.c

void UnknownObject::IntSetInsert()
{
    // Set insertion with deduplication: linearly scans the integer set stored as a linked list rooted at this+0x18. If the input value a2 is already present, returns 1 (duplicate). Otherwise allocates a 4-byte cell, stores a2, appends a node via LinkedListNodeAppend_6000 with flag 1, and returns 0.
    // ASSIGNMENT: Initialize result to 1, the already-present marker returned when the set already contains the value. [source:raw]
    // GUARD: Read the list head from this+0x18; if it is null the set is empty and control jumps to the insertion path. [field:this:0x00000018, source:raw]
    // LOOP: Linear traversal of the linked list starting at the head, following each node's next pointer until a null next pointer ends the scan. [field:this:0x00000018, source:raw]
    // GUARD: Compare each node's stored value (first dword of the node reached through the pointer at this+0x1C) against a2; a match exits the scan to return the duplicate marker. [field:this:0x0000001C, field:*(this+0x1C):0x00000000, source:raw]
    // CALL: Allocate a 4-byte cell for the integer value via OperatorNewNhMallocWrapper. [callee:0x00587C03]
    // ASSIGNMENT: Store the input value a2 into the allocated cell. [field:*(this+0x1C):0x00000000]
    // CALL: Append the new node to the list via LinkedListNodeAppend_6000 with flag argument 1; on allocation failure the same append is attempted with a null node. [callee:0x00586000, source:raw]
    // RETURN: Return 0 for a new insertion, or 1 when the value was already present. [source:raw, function:0x0057B230]

    // Conservative worker pseudocode:
    //   int IntSetInsert(_DWORD* this, int value) {
    //     _DWORD* node = (_DWORD*)this[6];
    //     if (!node) goto insert;
    //     while (!*node || *(_DWORD*)*node != value) {
    //       node = (_DWORD*)node[1];
    //       if (!node) goto insert;
    //     }
    //     if (!*node) {
    //     insert:
    //       _DWORD* cell = OperatorNewNhMallocWrapper(4);
    //       if (cell) { *cell = value; LinkedListNodeAppend_6000(cell, 1); }
    //       else      { LinkedListNodeAppend_6000(0, 1); }
    //       return 0;
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: Purpose of the list-related field at this+0x20 is not expressed in the raw body.
    // UNRESOLVED: Node bookkeeping (head/tail/count maintenance) is owned by LinkedListNodeAppend_6000 and is not reconstructed here.
}
