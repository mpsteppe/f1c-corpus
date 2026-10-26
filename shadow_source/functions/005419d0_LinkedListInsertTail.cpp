// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005419D0
// Canonical corpus name: LinkedListInsertTail
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListInsertTail_005419d0.c

void UnknownObject::LinkedListInsertTail()
{
    // Unlink node a2 from its current doubly-linked list and append it at the tail of this node's list. Updates the global list tail (dword_8B8F28 + 248) when a2 was the tail, and rebinds a2's owner to this.
    // ASSIGNMENT: Read a2's previous-node link (a2[109]) and, when set, connect that node's next pointer (offset 440) to a2's next node (a2[110]). [source:raw]
    // ASSIGNMENT: When a2 has a next node (a2[110]), connect it back: write a2[109] into that node's previous pointer (offset 436). [source:raw]
    // STATE_TRANSITION: If a2 is the current global list tail (dword_8B8F28 + 248), advance the global tail to a2[110] so it does not keep pointing at the unlinked node. [global:0x008B8F28, field:*(*(this+0x368)+0x1B8):0x000001B8, source:raw]
    // GUARD: Check whether this list's head (this[108], offset 0x1B0) is null to choose between first-insertion and tail-walk. [field:this:0x000001B0, source:raw]
    // LOOP: Walk the next-pointer chain from the head (offset 0x1B8 per node) until the tail node is reached. [field:*(this+0x368):0x000001B8, source:raw]
    // ASSIGNMENT: Append a2 at the tail: set the previous tail's next pointer (offset 440) to a2, or set this[108] to a2 when the list was empty. [source:raw]
    // ASSIGNMENT: Rebind a2: previous link to the old tail (a2[109] = v3), next link cleared (a2[110] = 0), list owner set to this (a2[107]). [source:raw]
    // RETURN: Return the walk result (null when the list was empty before insertion). [source:raw]

    // Conservative worker pseudocode:
    //   v2 = a2[109];
    //   if (v2) *(v2 + 440) = a2[110];
    //   v4 = a2[110];
    //   if (v4) *(v4 + 436) = a2[109];
    //   if (a2 == *(dword_8B8F28 + 248)) *(dword_8B8F28 + 248) = a2[110];
    //   result = this[108];
    //   if (result) {
    //       v3 = this[108];
    //       while ((result = *(result + 440))) v3 = result;
    //       *(v3 + 440) = a2;
    //   } else {
    //       this[108] = a2;
    //   }
    //   a2[109] = v3; a2[110] = 0; a2[107] = this;
    //   return result;
    // UNRESOLVED: The packet fields express the global list object as *(this+0x368) while the raw source dereferences the global base dword_8B8F28 directly; the equivalence of the two bases is not fully reconciled.
    // UNRESOLVED: Node layout semantics beyond bookkeeping (owner field a2[107], head field this[108]) are unverified.
}
