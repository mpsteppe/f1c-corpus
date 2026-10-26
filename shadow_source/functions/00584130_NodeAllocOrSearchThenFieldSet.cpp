// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00584130
// Canonical corpus name: sub_584130
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_584130_00584130.c

void UnknownObject::NodeAllocOrSearchThenFieldSet()
{
    // Searches list B (control at this+0x11C) for a node whose id, read via StructFieldGetter_7720, equals a3 (or is -1). When no match is found, allocates a node from the list A node pool (control at this+0x10C): takes the head node, clears the control's byte flag at +0x8, validates it with sub_586670, and on failure resets the pool via sub_586320 before retrying. Sets the acquired node's back-pointer at +0x414 to this and appends it via LinkedListNodeAppend_6000. Then records a3 into the object field at +0x410 via FieldSetterAt0x410 and runs sub_587730(a2). Returns 1 on success, 0 when a3 == -1.
    // ASSIGNMENT: Initialize result to 0 (the value returned on the a3 == -1 early-out path). [source:raw]
    // GUARD: Early-out: when a3 == -1 the function returns 0 without touching either list. [source:raw]
    // ASSIGNMENT: Load the list B control block from this+0x11C and seed the list B iterator this+0x124 with it. [field:this:0x0000011C, field:this:0x00000124, source:raw]
    // GUARD: Guard: if the list B control this+0x11C is null the search list is unusable; fall through to the allocation path. [field:this:0x0000011C, source:raw]
    // GUARD: Guard: if the list B head node (first dword of the list B control) is null the search list is empty; fall through to the allocation path. [source:raw]
    // LOOP: Walk the list B chain: advance the iterator this+0x124 to the current node's successor (node+4) whenever the current iterator value is non-null; terminate on a null successor or on a node whose id matches. [field:this:0x00000124, source:raw]
    // CALL: Read the current node's id via StructFieldGetter_7720 and break the walk when it equals a3 or is -1. [callee:0x00587720, source:raw]
    // CALCULATION: Advance the search: this+0x124 = *(current + 4) when the current node is non-null. [field:this:0x00000124, source:raw]
    // ASSIGNMENT: Load the list A (node pool) control block from this+0x10C and seed the list A iterator this+0x114 with it. [field:this:0x0000010C, field:this:0x00000114, source:raw]
    // GUARD: Guard on the list A control pointer this+0x10C: when null, skip the first pool-acquire attempt. [guard:0, field:this:0x0000010C, source:raw]
    // ASSIGNMENT: Take the pool head node from the list A control's first dword (*(this+0x10C)+0x0) and clear the byte flag at the control + 8 (*(this+0x10C)+0x8). [field:*(this+0x10C):0x00000000, field:*(this+0x10C):0x00000008, source:raw]
    // CALL: Validate the taken node with sub_586670(node, 1); on failure clear the acquired-node slot so the fallback path runs. [callee:0x00586670, source:raw]
    // GUARD: When the first acquire produced no node, reset the pool state via sub_586320(this + 63) and re-run the acquire. [callee:0x00586320, source:raw]
    // ASSIGNMENT: After the pool reset, re-seed the list A iterator this+0x114 = this+0x10C, re-take the head node and clear the control byte flag again. [field:this:0x00000114, field:this:0x0000010C, field:*(this+0x10C):0x00000000, field:*(this+0x10C):0x00000008, source:raw]
    // CALL: Retry sub_586670 on the re-taken node; a failure clears the node slot again. [callee:0x00586670, source:raw]
    // ASSIGNMENT: Store the owning object into the acquired node's back-pointer field at node + 0x414 (*(*(this+0x10C)+0x0):0x414). [field:*(*(this+0x10C)+0x0):0x00000414, source:raw]
    // CALL: Append the acquired node to the free/unused list via LinkedListNodeAppend_6000(node, 0). [callee:0x00586000, source:raw]
    // CALL: Record the searched id a3 into the object field at +0x410 via FieldSetterAt0x410(a3). [callee:0x00587710, source:raw]
    // CALL: Run the per-node processing step sub_587730(a2). [callee:0x00587730, source:raw]
    // RETURN: Return 1 on the successful search-or-allocate path. [source:raw]
    // RETURN: Return 0 when a3 == -1. [source:raw]
    // CALL: Invoked by sub_585270 during the same node-management iteration. [caller:0x00585270, source:raw]

    // Conservative worker pseudocode:
    //   char sub_584130(int this, int a2, int a3) {
    //     if (a3 == -1) return 0;
    //     int found = 0;
    //     int* lb = *(int**)(this + 0x11C);
    //     *(int**)(this + 0x124) = lb;
    //     if (lb && *lb) {
    //       int node = *lb;
    //       while (1) {
    //         int id = StructFieldGetter_7720(node);
    //         if (id == a3 || id == -1) { found = node; break; }
    //         int* cur = *(int**)(this + 0x124);
    //         if (cur) *(int**)(this + 0x124) = *(int**)(cur + 4);
    //         int* nx = *(int**)(this + 0x124);
    //         if (nx && *nx) { node = *nx; continue; }
    //         break;
    //       }
    //     }
    //     if (!found) {
    //       int* la = *(int**)(this + 0x10C);
    //       *(int**)(this + 0x114) = la;
    //       if (la) {
    //         found = *la;
    //         *((BYTE*)la + 8) = 0;
    //         if (!sub_586670(found, 1)) found = 0;
    //       }
    //       if (!found) {
    //         sub_586320(this + 63);
    //         la = *(int**)(this + 0x10C);
    //         *(int**)(this + 0x114) = la;
    //         if (la) {
    //           found = *la;
    //           *((BYTE*)la + 8) = 0;
    //           if (!sub_586670(found, 1)) found = 0;
    //         }
    //       }
    //       *(int*)(found + 1044) = this;
    //       LinkedListNodeAppend_6000(found, 0);
    //     }
    //     FieldSetterAt0x410(a3);
    //     sub_587730(a2);
    //     return 1;
    //   }
    // UNRESOLVED: Field this+0x128 is recorded as read but never appears in the decompiled body; its purpose is unknown.
    // UNRESOLVED: The node structure layout (head dword, +4 successor pointer, +8 byte flag, +0x414 back-pointer) is only partially evidenced; the full node type is unknown.
    // UNRESOLVED: The semantics of FieldSetterAt0x410 and sub_587730 depend on the unknown owning object; a2's meaning is caller-defined.
    // UNRESOLVED: The pool reset sub_586320(this + 63) targets a sub-object at this + 0xFC which has no packet field evidence.
}
