// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499870
// Canonical corpus name: LinkedListIteratorAdvance
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListIteratorAdvance_00499870.c

void UnknownObject::LinkedListIteratorAdvance()
{
    // Advances a linked-list iterator by one node. Reads the current node from this[4] (this+0x10); when it is NULL the iterator is exhausted and the function returns false. Otherwise it loads the container pointer this[3] (this+0xC), refreshes the container traversal slot at container+0xC from the current node's link field (+4), dereferences the first dword of the next-candidate node to obtain the new current node, stores it to this[4] (this+0x10), and updates this[5] (this+0x14) with FieldGetter_8e30(next). Returns true while a next node exists.
    // GUARD: Guard on the current node this[4] (this+0x10): when zero the iterator is exhausted and the function returns false. [field:this:0x00000010, guard:0, source:raw]
    // CALCULATION: Load the container pointer this[3] (this+0xC) used to walk the traversal state. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Refresh the container traversal slot at container+0xC from the link field (offset +4) of the current node when the link is present. [field:*(this+0x18):0x00000004, source:raw]
    // CALCULATION: Read the next-candidate node pointer from the refreshed traversal slot; the candidate pointer is held in the temporary at this+0x18, and dereferencing its first dword yields the next node. [field:this:0x00000018, field:*(this+0x18):0x00000000, source:raw]
    // ASSIGNMENT: Write the new current node to this[4] (this+0x10). [field:this:0x00000010, source:raw]
    // CALL: FieldGetter_8e30(next) extracts the value/data from the new current node when it is non-null. [callee:0x00498E30, source:raw]
    // ASSIGNMENT: Store the extracted value to this[5] (this+0x14) when a new current node exists. [field:this:0x00000014, callee:0x00498E30, source:raw]
    // RETURN: Return (this[4] != 0): true if the iterator now points at a valid node, false when exhausted. [field:this:0x00000010, source:raw]
    // CALL: Invoked from sub_499910 (0x00499910) to step the linked-list iterator. [caller:0x00499910]

    // Conservative worker pseudocode:
    //   bool sub_499870(DWORD* it) {
    //     DWORD cur = it[4];
    //     bool done = (cur == 0);
    //     if (cur) {
    //       DWORD* container = (DWORD*)it[3];
    //       DWORD link = *(DWORD*)(container + 3);
    //       if (link)
    //         *(DWORD*)(container + 3) = *(DWORD*)(link + 4);
    //       DWORD* cand = *(DWORD**)(container + 3);
    //       DWORD* next = cand ? *cand : 0;
    //       it[4] = (DWORD)next;
    //       if (next)
    //         it[5] = FieldGetter_8e30(next);
    //       done = (it[4] == 0);
    //     }
    //     return !done;
    //   }
    // UNRESOLVED: The exact field layout of the container at this+0xC and of the list nodes is DERIVED from the existing analysis; the packet does not name the structure.
    // UNRESOLVED: The role of the traversal temporary at this+0x18 is inferred from the existing analysis; the raw source compiles the traversal through container+0xC.
    // UNRESOLVED: FieldGetter_8e30 (0x00498E30) body is outside this packet; it extracts the current value from a node.
}
