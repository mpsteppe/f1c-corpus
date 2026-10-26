// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053D3A0
// Canonical corpus name: DoublyLinkedListNodeRemoval_d3a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListNodeRemoval_d3a0_0053d3a0.c

void UnknownObject::DoublyLinkedListNodeRemoval()
{
    // Unlinks a node from the registry doubly-linked list whose link fields sit at offsets 0x86C (prev) and 0x870 (next) and whose head pointer is dword_8B8E20. Patches the previous node's next and the next node's prev to bypass this node, advances the head when this node is the head, clears the node's own link fields, and returns the original node pointer.
    // ASSIGNMENT: Save the input node pointer a1 as result (the eventual return value). [function:0x0053D3A0, source:raw]
    // CALCULATION: Read the node's prev pointer stored at offset 0x86C. [field:this:0x0000086C, source:raw]
    // GUARD: If prev (at 0x86C) is non-null, write this node's next pointer (at 0x870) into prev's next field at offset 0x870. [field:this:0x0000086C, field:*(this+0x86C):0x00000870, source:raw]
    // GUARD: If next (at 0x870) is non-null, write this node's prev pointer (at 0x86C) into next's prev field at offset 0x86C. [field:this:0x00000870, field:*(this+0x870):0x0000086C, source:raw]
    // GUARD: If dword_8B8E20 (list head) equals this node, advance the head to this node's next pointer at offset 0x870. [global:0x008B8E20, field:this:0x00000870, source:raw]
    // ASSIGNMENT: Clear this node's prev (0x86C) and next (0x870) pointers to 0. [field:this:0x0000086C, field:this:0x00000870, source:raw]
    // RETURN: Return the original node pointer. [source:raw]

    // Conservative worker pseudocode:
    //   prev = *(this + 0x86C);
    //   next = *(this + 0x870);
    //   if (prev)
    //       *(prev + 0x870) = next;
    //   if (next)
    //       *(next + 0x86C) = prev;
    //   if (dword_8B8E20 == this)
    //       dword_8B8E20 = next;
    //   *(this + 0x86C) = 0;
    //   *(this + 0x870) = 0;
    //   return this;
}
