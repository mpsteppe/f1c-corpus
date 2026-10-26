// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00582CE0
// Canonical corpus name: sub_582CE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_582CE0_00582ce0.c

void UnknownObject::VirtualDestructorListCleanup()
{
    // Tears down two singly-linked node lists rooted at this+0x10 and this+0x0. For the list at this+0x10, each node (data at +0x0, next at +0x4, flag at +0x8) with a non-zero flag and non-null data pointer gets the data block's second vtable entry invoked as a thiscall with argument 1; every node is freed via FreeWrapper_7bcf, then this+0x10..0x1C are zeroed. For the list at this+0x0, flagged nodes have their data block's second vtable entry invoked with argument 3, the data block and node are freed via FreeWrapper_7bcf, then this+0x0..0xC are zeroed. Called by sub_57BCE0.
    // LOOP: Walk the linked list whose head is at this+0x10, following each node's +0x4 next pointer until null. [field:this:0x00000010]
    // GUARD: For each node in the this+0x10 list, proceed only if the node+0x8 flag byte is non-zero and the node+0x0 data pointer is non-null. [field:obj:0x00000008, field:obj:0x00000000]
    // CALL: Invoke the data block's second vtable entry (vtable pointer at data+0x0, entry at +0x4) as a thiscall on the data block with argument 1. [field:*(*(*(obj+0x0)+0x0)+0x0):0x00000004, field:*(*(obj+0x0)+0x0):0x00000000, field:*(obj+0x0):0x00000000]
    // CALL: Free every node of the this+0x10 list with FreeWrapper_7bcf. [callee:0x00587BCF, field:obj:0x00000000]
    // ASSIGNMENT: Zero the second list's four fields this+0x10, this+0x14, this+0x18, this+0x1C. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C]
    // LOOP: Walk the linked list whose head is at this+0x0, following each node's +0x4 next pointer until null. [field:this:0x00000000]
    // GUARD: For each node in the this+0x0 list, proceed only if the node+0x8 flag byte is non-zero, the node+0x0 data pointer is non-null, and the data block's first vtable pointer is non-null. [field:obj:0x00000008, field:obj:0x00000000]
    // CALL: Invoke the data block's second vtable entry as a thiscall on the data block with argument 3. [field:*(this+0x10):0x00000000, field:*(*(this+0x10)+0x0):0x00000004, field:*(this+0x14):0x00000004]
    // CALL: Free the flagged data block and every node of the this+0x0 list with FreeWrapper_7bcf. [callee:0x00587BCF]
    // ASSIGNMENT: Zero the first list's four fields this+0x0, this+0x4, this+0x8, this+0xC. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]
    // RETURN: Return the last FreeWrapper_7bcf result; the caller ignores the value. [function:0x00582CE0]

    // Conservative worker pseudocode:
    //   for (n = *(this+0x10); n; n = *(n+4)) { if (n[8] && n[0]) data_vtable[1](n[0], 1); FreeWrapper_7bcf(n); }
    //   *(this+0x10)=0; *(this+0x14)=0; *(this+0x18)=0; *(this+0x1C)=0;
    //   for (n = *(this+0x0); n; n = *(n+4)) { if (n[8] && n[0] && *(n[0])) { data_vtable[1](n[0], 3); FreeWrapper_7bcf(n[0]); } FreeWrapper_7bcf(n); }
    //   *(this+0x0)=0; *(this+0x4)=0; *(this+0x8)=0; *(this+0xC)=0;
    // UNRESOLVED: Object types and container semantics of the two linked lists (roots this+0x0 and this+0x10) are unknown; the argument values 1 and 3 passed to the virtual release methods are uninterpreted.
    // UNRESOLVED: Exact node layout beyond +0x0 (data), +0x4 (next), +0x8 (flag) is unproven.
    // UNRESOLVED: Whether the this+0x10/this+0x14 based deref chains in the second loop denote the same data vtable as the obj-based chain in the first loop is unconfirmed.
    // UNRESOLVED: The SEH registration global SEH_582CE0 belongs to the function's exception frame but does not appear in the raw source body.
}
