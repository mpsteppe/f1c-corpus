// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499910
// Canonical corpus name: sub_499910
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_499910_00499910.c

void UnknownObject::TreeTraversalNextNode()
{
    // State-machine iterator that yields the next node of a tree/container traversal one step at a time. Maintains three states on this+0x0 (0=init, 1=sibling-descend, 2=child-iterate) and a done flag on this+0x4. Advances a current item at this+0x8 along sibling next-pointers at item+140 and child lists under the parent at this+0x10, with container state at this+0xC. When exhausted, sets the done flag and returns; otherwise returns the current item pointer. Called from rendering tree traversal by RenderingContextSetup (0x00497750) and sub_4998E0 (0x004998E0).
    // GUARD: Early exit: when the done flag this+0x4 is set, clears the current item at this+0x8 and returns immediately (traversal already complete) [field:this:0x00000004, field:this:0x00000008, source:raw]
    // LOOP: Main state-machine loop: repeats dispatching on this+0x0 until a node is yielded, the iteration is exhausted, or the done flag becomes set [field:this:0x00000000, source:raw]
    // ASSIGNMENT: When a current item exists at this+0x8, advances it to the next pointer stored at item+140 (0x8C) [field:this:0x00000008, field:*(this+0x8):0x0000008C, source:raw]
    // GUARD: State dispatch on this+0x0: value 0 means re-init (container head check), value 1 enters sibling-descend, value 2 enters child-iterate [guard:0, guard:1, guard:2, field:this:0x00000000, source:raw]
    // STATE_TRANSITION: Sibling-descend (state 1): reads the parent from this+0x10, transitions to state 2, reads the child-list head at parent+72 into this+0x14 and, when non-null, the first child item at child-head+68 into this+0x8 [field:this:0x00000010, field:this:0x00000014, field:this:0x00000008, field:*(this+0x10):0x00000048, field:*(this+0x14):0x00000044, source:raw]
    // GUARD: Child-iterate (state 2): LinkedListNodeTraversal_98c0 decides whether sibling iteration continues; on true, fetches the next sibling at child-head+68 (0x44) into this+0x8 [callee:0x004998C0, field:*(this+0x14):0x00000044, field:*(*(this+0x10)+0x48):0x00000044, field:this:0x00000008, source:raw]
    // CALL: LinkedListIteratorAdvance advances the sibling iterator; when it reports failure the traversal has no more children and proceeds to the done/return path [callee:0x00499870, source:raw]
    // STATE_TRANSITION: After a successful iterator advance, sets the state back to 1 (sibling-descend) and reads the next sibling node at parent+76 (0x4C) from the parent at this+0x10 into this+0x8 [field:this:0x00000010, field:*(this+0x10):0x0000004C, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Loop tail: if the done flag this+0x4 is clear and the current item this+0x8 is non-null, returns the item; otherwise continues the loop or returns the done status [field:this:0x00000004, field:this:0x00000008, source:raw]
    // STATE_TRANSITION: Re-initialization path (state 0): reads the container's sibling-list head at container+4, copies it into container+12 (0xC), sets state 1, selects the first sibling at sibling+76 (0x4C) into this+0x8 and clears the child pointer this+0x14; when the head is null the done flag this+0x4 is set [field:this:0x0000000C, field:*(this+0xC):0x00000004, field:*(this+0xC):0x0000000C, field:*(*(this+0xC)+0x4):0x00000000, field:*(*(*(this+0xC)+0x4)+0x0):0x0000004C, field:this:0x00000004, source:raw]
    // CALL: Invoked by RenderingContextSetup (0x00497750) and sub_4998E0 (0x004998E0) as the per-step node iterator during rendering tree traversal [caller:0x00497750, caller:0x004998E0, source:raw]

    // Conservative worker pseudocode:
    //   if (this+4 /*done* /) { this+8 = 0; return this+4; }
    //   loop {
    //     if (item = this+8) { this+8 = *(item+140); continue_to_tail(); }
    //     switch (this+0) {
    //       case 0: /* re-init * /
    //         head = *(this+12 /*container* / + 4);
    //         *(this+12 + 12) = head;
    //         this+0 = 1;
    //         parent = head ? *head : 0; this+16 = parent;
    //         this+20 = 0;
    //         if (parent) { this+8 = *(parent+76); tail(); }
    //         else this+4 = 1;
    //         return;
    //       case 1: /* sibling-descend * /
    //         parent = this+16; this+0 = 2;
    //         child = *(parent+72); this+20 = child;
    //         if (child) this+8 = *(child+68);
    //         tail();
    //       case 2: /* child-iterate * /
    //         if (LinkedListNodeTraversal_98c0(this)) { this+8 = *(*(this+20)+68); tail(); }
    //         else if (LinkedListIteratorAdvance(this)) {
    //           parent = this+16; this+0 = 1;
    //           this+8 = *(parent+76); tail();
    //         } else { this+4 = 1; return; }
    //     }
    //   }
    // UNRESOLVED: The concrete classes of the container/tree nodes are unidentified; the iterator reads child lists at node+72/+76 and sibling next-pointers at +68/+140 without resolving the owning type
    // UNRESOLVED: The vtable-slot style field refs *(*(this+0x10)+0x48):0x44 and *(*(*(this+0xC)+0x4)+0x0):0x4C overlap with the plain child/sibling reads and cannot be distinguished as distinct objects from this packet alone
}
