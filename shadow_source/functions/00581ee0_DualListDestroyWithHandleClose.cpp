// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00581EE0
// Canonical corpus name: sub_581EE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_581EE0_00581ee0.c

void UnknownObject::DualListDestroyWithHandleClose()
{
    // Destroys two embedded singly-linked lists on a container object and optionally closes a handle. First, when the flag byte at this+0x28 is non-zero, calls CloseHandle (0x0059E1A8) on the handle stored at this+0x20 and zeroes the handle slot on success. Then walks list 1 (head this+0x10, tail this+0x14, next-node links at node+4): for each node whose flag byte (+8) is set and whose data pointer is non-null, invokes the data object's vtable destructor at vtable+4 with argument 1, and frees every node with FreeWrapper_7bcf (0x00587BCF); afterwards zeroes the four list1 fields (this+0x10/0x14/0x18/0x1C). Then walks list 2 (head this+0x0, next-node links at node+4): for each node whose flag byte (+8) is set, takes the data pointer and, if the data object and its vtable are non-null, invokes the data object's vtable destructor at vtable+4 with argument 3 and frees the data object; every node is freed; afterwards zeroes the four list2 fields (this+0x0/0x4/0x8/0xC).
    // GUARD: If the flag byte at this+0x28 is non-zero and CloseHandle succeeds on the handle stored at this+0x20, clear the handle field (this+0x20) to 0. [field:this:0x00000028, field:this:0x00000020, global:0x0059E1A8, source:raw]
    // LOOP: Walk list 1 from the head pointer at this+0x10, reading the head node's first dword, the tail slot at this+0x14 (node link at +4), and following next-node links at node+4 until null. [field:this:0x00000010, field:*(this+0x10):0x00000000, field:*(this+0x14):0x00000004, field:*(*(this+0x10)+0x0):0x00000004, source:raw]
    // GUARD: For each list1 node whose flag byte at node+8 is set and whose data pointer at node+0 (dereferenced node first dword) is non-null, invoke the data object's vtable destructor at vtable+4 (vtable entry 1) with argument 1. [field:obj:0x00000008, field:obj:0x00000000, field:*(obj+0x0):0x00000000, field:*(*(obj+0x0)+0x0):0x00000000, field:*(*(*(obj+0x0)+0x0)+0x0):0x00000004, source:raw]
    // CALL: Release every list1 node wrapper with FreeWrapper_7bcf (0x00587BCF). [callee:0x00587BCF, field:obj:0x00000000, source:raw]
    // ASSIGNMENT: Zero the list1 bookkeeping fields this+0x10 (head), this+0x14 (tail), this+0x18 (cursor) and this+0x1C (count). [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // LOOP: Walk list 2 from the head pointer at this+0x0, following next-node links at node+4 until null. [field:this:0x00000000, source:raw]
    // GUARD: For each list2 node whose flag byte at node+8 is set: take the data pointer at node+0; if the data object is non-null and its vtable pointer is non-null, call the data object's vtable destructor at vtable+4 with argument 3, then free the data object with FreeWrapper_7bcf. [field:obj:0x00000008, field:obj:0x00000000, field:*(*(obj+0x0)+0x0):0x00000000, field:*(*(*(obj+0x0)+0x0)+0x0):0x00000004, callee:0x00587BCF, source:raw]
    // CALL: Release each list2 node wrapper with FreeWrapper_7bcf (0x00587BCF). [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the list2 bookkeeping fields this+0x0 (head), this+0x4 (tail), this+0x8 (cursor) and this+0xC (count). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]

    // Conservative worker pseudocode:
    //   if (this->flag(0x28) && CloseHandle(this->handle(0x20))) this->handle(0x20) = 0;
    //   for (n = this->list1Head; n; n = n->next) {
    //       if (n->flag(8) && n->data) callVtblEntry1(n->data, 1);
    //       FreeWrapper_7bcf(n);
    //   }
    //   this->list1 = {0, 0, 0, 0};
    //   for (n = this->list2Head; n; n = n->next) {
    //       if (n->flag(8)) {
    //           if (n->data && n->data->vtbl) callVtblEntry1(n->data, 3);
    //           FreeWrapper_7bcf(n->data);
    //       }
    //       FreeWrapper_7bcf(n);
    //   }
    //   this->list2 = {0, 0, 0, 0};
    // UNRESOLVED: The SEH registration global 0x0059CBF0 (SEH_581EE0) is read by the function's exception frame; its exact role is not visible in the decompiled body.
    // UNRESOLVED: The list2 tail/cursor/count fields this+0x4/0x8/0xC and the list1 cursor/count fields this+0x18/0x1C are only zeroed here and never read; the tail/cursor/count roles come from the existing-analysis prose.
    // UNRESOLVED: The two vtable destructor calls use argument 1 (list1 data) and argument 3 (list2 data); the class types and the meaning of the differing arguments are unknown.
    // UNRESOLVED: The resource represented by the handle at this+0x20 and the flag byte at this+0x28 is unknown.
    // UNRESOLVED: The packet records no static callers; the container class owning these fields is unknown.
}
