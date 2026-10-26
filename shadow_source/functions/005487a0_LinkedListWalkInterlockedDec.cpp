// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005487A0
// Canonical corpus name: LinkedListWalkInterlockedDec
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListWalkInterlockedDec_005487a0.c

void UnknownObject::LinkedListWalkInterlockedDec()
{
    // Walks a linked list rooted at the head pointer in this[9] (this+0x24), following node-next pointers at +0xC0. For each node, calls sub_546450(node, -1); on a non-zero return (match found) returns -1 immediately. Otherwise decrements the global Addend atomically via InterlockedDecrement and runs AudioVolumeLoadComputation(0), then advances to the next node. Returns 0 when the list is empty or the chain ends without a match.
    // ASSIGNMENT: Load head pointer into v1 from this[9] (dword at byte offset 0x24). [field:this:0x00000024]
    // GUARD: If head pointer is null, return 0 (empty list, nothing to scan). [field:this:0x00000024, source:raw]
    // LOOP: While sub_546450(current_node, -1) returns 0, keep walking the chain through each node's next pointer at +0xC0. [callee:0x00546450, field:*(this+0xE4):0x000000C0]
    // CALL: Call sub_546450(v1, -1); a non-zero return indicates the match that exits the loop. [callee:0x00546450]
    // CALL: Atomically decrement the global Addend via InterlockedDecrement (target address 0x0059E234). [global:0x0059E234, global:0x008B8EEC]
    // CALL: Invoke AudioVolumeLoadComputation(0) as a side effect on the non-match path. [callee:0x00545F50]
    // ASSIGNMENT: Advance v1 to the next node read from the current node's +0xC0 pointer. [field:*(this+0xE4):0x000000C0]
    // GUARD: If the next node pointer is null, return 0 (chain ended without a match). [field:*(this+0xE4):0x000000C0, source:raw]
    // RETURN: Return -1 when a node matches sub_546450's condition. [source:raw]

    // Conservative worker pseudocode:
    //   node = this[9];
    //   if (node == 0) return 0;
    //   while (sub_546450(node, -1) == 0) {
    //       InterlockedDecrement(&Addend);
    //       AudioVolumeLoadComputation(0);
    //       node = *(node + 192);
    //       if (node == 0) return 0;
    //   }
    //   return -1;
    // UNRESOLVED: Semantics of sub_546450's match condition are not resolved; it determines whether the walk returns -1 or continues.
    // UNRESOLVED: Global 0x008B8EEC is only labelled Addend by the legacy ABI name; its role beyond being an interlocked counter is unproven.
    // UNRESOLVED: Why each non-match also triggers AudioVolumeLoadComputation(0) is unresolved.
}
