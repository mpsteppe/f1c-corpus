// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495A80
// Canonical corpus name: DoublyLinkedListAppend_5a80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListAppend_5a80_00495a80.c

void UnknownObject::DoublyLinkedListAppend()
{
    // Appends a node a2 to the tail of a doubly-linked list. First unlinks a2 from any list it currently belongs to (DoublyLinkedListNodeUnlink), then zeroes a2's next/prev link slots. If the list head at this+0x14 is non-null, walks from it following each node's next pointer at +0x64 to find the tail, then splices a2 in: updates the tail pointer at this+0x18, links the old tail's next to a2, and sets a2's prev link. If the list is empty, sets both head (this+0x14) and tail (this+0x18) to a2. Does nothing if a2 is null.
    // GUARD: If a2 is null, return immediately without modifying the list. [source:raw]
    // CALL: Unlink a2 from any list it currently belongs to before re-appending. [callee:0x00495A20]
    // ASSIGNMENT: Zero a2's next pointer (offset 100, 0x64) and prev pointer (offset 104, 0x68) so it is a standalone node. [source:raw]
    // ASSIGNMENT: Read the list head pointer from this+0x14 (this[5]) into v3. [field:this:0x00000014]
    // GUARD: If the head v3 is non-null, walk to the tail; otherwise the list is empty. [source:raw]
    // LOOP: Walk from the head node toward the tail by repeatedly reading each node's next pointer at +0x64 until the next pointer is null, leaving v3 on the last node. [field:*(*(this+0x78)+0x64):0x00000064]
    // ASSIGNMENT: Splice a2 at the tail: set the list tail pointer this+0x18 to a2, set the old tail's next pointer at +0x64 to a2, and set a2's prev pointer (offset 104, 0x68) back to the old tail v3. [field:this:0x00000018, field:*(*(this+0x78)+0x64):0x00000064]
    // ASSIGNMENT: Empty-list case: set both the head pointer this+0x14 and the tail pointer this+0x18 to a2. [field:this:0x00000014, field:this:0x00000018]

    // Conservative worker pseudocode:
    //   void DoublyLinkedListAppend(void* this, int a2) {
    //     if (!a2) return;
    //     DoublyLinkedListNodeUnlink(this, a2);
    //     *(int*)(a2 + 0x64) = 0;
    //     *(int*)(a2 + 0x68) = 0;
    //     int v3 = *(int*)(this + 0x14);
    //     if (v3) {
    //       int i = *(int*)(v3 + 0x64);
    //       while (i) { v3 = i; i = *(int*)(i + 0x64); }
    //       *(int*)(this + 0x18) = a2;
    //       *(int*)(v3 + 0x64) = a2;
    //       *(int*)(a2 + 0x68) = v3;
    //     } else {
    //       *(int*)(this + 0x14) = a2;
    //       *(int*)(this + 0x18) = a2;
    //     }
    //   }
    // UNRESOLVED: The corpus field this+0x78 (read, cached/sentinel traversal start) is not directly dereferenced in the visible raw source, which starts the tail walk from the head at this+0x14; the two models of the traversal starting point are not reconciled.
    // UNRESOLVED: The node link offsets (+0x64 next, +0x68 prev) are identified from the raw source literals 100 and 104; no independent packet evidence names them.
    // UNRESOLVED: The list that a2 is appended into (which object/field owns it) is not visible in this function.
}
