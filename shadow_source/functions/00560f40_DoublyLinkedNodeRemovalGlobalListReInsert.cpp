// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00560F40
// Canonical corpus name: DoublyLinkedNodeRemovalGlobalListReInsert
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedNodeRemovalGlobalListReInsert_00560f40.c

void UnknownObject::DoublyLinkedNodeRemovalGlobalListReInsert()
{
    // __thiscall that splices a node out of its current doubly linked list and, when the global context pointer dword_8B8F28 is non-null, re-inserts the node at the tail of a second global list headed at dword_8B8F28+348. The node carries a prev link at a2[12] (+48) and a next link at a2[13] (+52). If the removed node was the local list head (this[11] at +44 == a2), the head is advanced to a2[13]. Re-insertion walks the global list next links to its tail (or sets it as head when empty), then resets the node links (a2[12] = prior tail, a2[13] = 0) and clears the node's active flag bit 2 (a2[9] &= ~4u). Returns the last computed result (the prior global-list tail pointer, or 0 when the global list was empty or dword_8B8F28 was null).
    // ASSIGNMENT: Save the node's previous-link pointer as v2 = a2[12] (byte offset +48). [source:raw]
    // GUARD: If v2 is non-null, write a2[13] (the node next link, +52) into v2 + 52, splicing the node out: prev->next = node->next. [source:raw]
    // ASSIGNMENT: result = a2[13], the node's next-link pointer. [source:raw]
    // GUARD: If result (the node next link) is non-null, write a2[12] (the node prev link, +48) into result + 48: next->prev = node->prev. [source:raw]
    // GUARD: If the removed node was the list head (this[11] at +44 == a2), promote a2[13] to head: this[11] = a2[13]; and if that next is non-null, clear its prev link (result + 48 = 0). [field:this:0x0000002C, source:raw]
    // GUARD: If global context pointer dword_8B8F28 is non-null, re-insert the node into the global list headed at dword_8B8F28 + 348. [global:0x008B8F28, source:raw]
    // GUARD: Read the global list head v4 = *(dword_8B8F28 + 348); if empty (v4 == 0) the else branch makes a2 the new head. [global:0x008B8F28, source:raw]
    // LOOP: If the global list is non-empty, traverse the next links (+52) from v4 to the tail, accumulating result = i for each node. [global:0x008B8F28, source:raw]
    // ASSIGNMENT: Append the node: write a2 into tail->next (result + 52); when the global list was empty, write a2 as the new head at dword_8B8F28 + 348. [global:0x008B8F28, source:raw]
    // ASSIGNMENT: Reset the re-inserted node links to tail position: a2[12] = result (prior tail, or 0 when the list was empty) and a2[13] = 0. [source:raw]
    // ASSIGNMENT: Clear the node active flag bit 2: a2[9] &= ~4u (flags field at byte offset +36). [source:raw]
    // RETURN: Return result, the last computed value (prior global-list tail pointer, or 0 when the global list was empty or dword_8B8F28 was null). [function:0x00560F40, source:raw]
    // CALL: Invoked by DoublyLinkedListNodeTransplant (0x0054BAA0). [caller:0x0054BAA0]

    // Conservative worker pseudocode:
    //   v2 = a2[12]; if (v2) v2[13] = a2[13];
    //   result = a2[13]; if (result) result[12] = a2[12];
    //   if (this[11] == a2) { this[11] = a2[13]; if (result) result[12] = 0; }
    //   if (dword_8B8F28) {
    //     if (*(dword_8B8F28 + 348)) {
    //       result = *(dword_8B8F28 + 348);
    //       for (i = result[13]; i; i = i[13]) result = i;
    //       result[13] = a2;
    //     } else { *(dword_8B8F28 + 348) = a2; }
    //     a2[12] = result; a2[13] = 0;
    //   }
    //   a2[9] &= ~4u;
    //   return result;
    // UNRESOLVED: The return value's consumer and meaning are not packet-evident; result happens to be the prior global-list tail pointer (or 0) but no caller contract confirms it.
    // UNRESOLVED: The identity and meaning of dword_8B8F28 and the global list at +348 are DERIVED from existing analysis; only the address is deterministic.
    // UNRESOLVED: The node active flag bit 2 (a2[9] &= ~4u) is inferred to mean attached/active; that semantic is not packet-stated.
}
