// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00467720
// Canonical corpus name: sub_467720
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_467720_00467720.c

void UnknownObject::objectInitAndClearLinkedList()
{
    // Initializes an object (vtable install, counter and pointer fields zeroed) then walks an embedded singly-linked list starting at this+0xF8, freeing the payload chain and each node, and finally resets the head/tail pointers, counts and flag bytes to zero. Acts as a combined constructor and cleanup path for a linked-list-backed object. The list node layout (data at +0, next at +4, one-byte flag at +8) is read directly from the raw source.
    // CALL: Initialize the object via InitWithVTableFlags(this, 0, 0). [callee:0x00487ED0, source:raw]
    // ASSIGNMENT: Install vtable pointer this[0] = off_59F5B8. [field:this:0x00000000, global:0x0059F5B8, source:raw]
    // ASSIGNMENT: Zero the counter/state dwords this[57]..this[60] at offsets 0xE4..0xF0. [field:this:0x000000E4, field:this:0x000000E8, field:this:0x000000EC, field:this:0x000000F0, source:raw]
    // LOOP: Walk the linked list from head this[62] (offset 0xF8), following each node's next pointer at node+4 until a null next terminates the walk; the head node's data and next pointers are read through *(this+0xF8) and *(this+0xFC) respectively. [field:this:0x000000F8, field:this:0x000000FC, field:*(this+0xF8):0x00000000, field:*(this+0xFC):0x00000004, source:raw]
    // GUARD: If the node's one-byte flag at node+8 is set, free the node's payload chain (inner payload pointer then the payload block) via FreeWrapper_7bcf. [callee:0x00587BCF, field:*(this+0xF8):0x00000000, source:raw]
    // CALL: Free the current list node itself via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Reset the linked-list container fields to zero: head/tail pointers this[62]..this[63] (0xF8..0xFC), element count this[64] (0x100), capacity this[65] (0x104), unknown field this[66] (0x108), and flag bytes at 0xF4 and 0xF5. [field:this:0x000000F8, field:this:0x000000FC, field:this:0x00000100, field:this:0x00000104, field:this:0x00000108, field:this:0x000000F4, field:this:0x000000F5, source:raw]
    // RETURN: Return the this pointer. [function:0x00467720, source:raw]

    // Conservative worker pseudocode:
    //   InitWithVTableFlags(this, 0, 0);
    //   this[0] = off_59F5B8;
    //   this[57] = 0; this[58] = 0; this[59] = 0; this[60] = 0;
    //   node = this[62];
    //   while (node) {
    //     next = node[1];
    //     if (node[2] != 0) {
    //       data = node[0];
    //       if (data) { if (data[0]) FreeWrapper_7bcf(data[0]); FreeWrapper_7bcf(data); }
    //     }
    //     FreeWrapper_7bcf(node);
    //     node = next;
    //   }
    //   this[62] = 0; this[63] = 0; this[64] = 0; this[65] = 0; this[66] = 0;
    //   *(byte*)(this + 0xF4) = 0; *(byte*)(this + 0xF5) = 0;
    //   return this;
    // UNRESOLVED: The list node layout (payload at +0, next at +4, one-byte flag at +8) is visible only in the raw source text; only the payload and next-of-tail reads have packet field evidence refs.
    // UNRESOLVED: Semantics of the individual counter fields at 0xE4..0xF0 and the flag bytes at 0xF4/0xF5 are unknown beyond being reset to zero.
}
