// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00582650
// Canonical corpus name: sub_582650
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_582650_00582650.c

void UnknownObject::DestroyEmbeddedNodeLists()
{
    // Destroys two embedded singly-linked lists on the object. First pass frees the list anchored at this+0x10 (this[4]): each node whose flag byte (node+0x8) and data pointer (node+0x0) are non-null gets its data object's vtable slot 0 called as (data)(data, 1), then the node wrapper is freed with FreeWrapper_7bcf; the four list1 fields are then zeroed. Second pass destroys the list anchored at this+0x0: for each node with flag byte set, the data object's vtable slot 0 is called as (data)(data, 3) and the data object is freed, then the node wrapper is freed; the four list2 fields are then zeroed. No handle close is performed.
    // LOOP: First pass over list1: walk the node chain anchored at this+0x10 (read via this[4]), saving each node's next pointer (first dword of the head node) before freeing. [field:this:0x00000010, field:*(this+0x10):0x00000000, field:*(*(this+0x10)+0x0):0x00000000]
    // GUARD: Before invoking the node's destructor, require the flag byte at node+0x8 to be non-zero and the data pointer at node+0x0 to be non-null. [field:obj:0x00000008, field:obj:0x00000000]
    // CALL: When the guard passes, call the data object's vtable slot 0 (function pointer at *(*(obj+0x0)+0x0), reached through the vtable pointer at *(obj+0x0)) as a __thiscall (data)(data, 1). [field:*(*(*(obj+0x0)+0x0)+0x0):0x00000000, field:*(*(obj+0x0)+0x0):0x00000000]
    // CALL: Free each list1 node wrapper with FreeWrapper_7bcf (callee 0x00587BCF). [callee:0x00587BCF]
    // ASSIGNMENT: Zero the four list1 bookkeeping fields this+0x10, this+0x14, this+0x18, this+0x1C. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C]
    // LOOP: Second pass over list2: walk the node chain anchored at this+0x0 (read via a1[0]). [field:this:0x00000000]
    // GUARD: Second pass only proceeds with a node's data object when the flag byte at node+0x8 is non-zero. [field:obj:0x00000008]
    // GUARD: Require the node's data pointer (node+0x0) to be non-null and its first dword *(obj+0x0) to be non-null before calling the destructor. [field:obj:0x00000000, field:*(obj+0x0):0x00000000]
    // CALL: Call the data object's vtable slot 0 as a __thiscall (data)(data, 3). [field:*(*(*(obj+0x0)+0x0)+0x0):0x00000000]
    // CALL: Free the data object and the node wrapper via FreeWrapper_7bcf. [callee:0x00587BCF]
    // ASSIGNMENT: Zero the four list2 bookkeeping fields this+0x0, this+0x4, this+0x8, this+0xC. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]
    // RETURN: Return the value left in result by the last FreeWrapper call (decompiler artifact). [source:raw]

    // Conservative worker pseudocode:
    //   // this = a1; list1 anchored at this+0x10, list2 at this+0x0 (4 dword fields each).
    //   for (node = this->list1_head; node; node = next) {
    //     next = node->next;
    //     if (node->destroy_flag && node->data) node->data->vtable[0](node->data, 1);
    //     FreeWrapper_7bcf(node);
    //   }
    //   this->list1_head = this->list1_tail = this->list1_iter = 0;
    //   for (node = this->list2_head; node; node = next) {
    //     next = node->next;
    //     if (node->destroy_flag && node->data && node->data->vtable[0]) {
    //       node->data->vtable[0](node->data, 3);
    //       FreeWrapper_7bcf(node->data);
    //     }
    //     FreeWrapper_7bcf(node);
    //   }
    //   this->list2_head = this->list2_tail = this->list2_iter = 0;
    // UNRESOLVED: Global 0x0059CCD0 (SEH_582650) is the structured-exception registration for this function; its role is not modeled beyond that.
    // UNRESOLVED: Vtable slot 0 targets are not resolved: the destructor call addresses are indirect and unknown.
}
