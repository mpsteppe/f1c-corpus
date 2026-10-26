// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047FB10
// Canonical corpus name: sub_47FB10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_47FB10_0047fb10.c

void UnknownObject::UISliderListDtor()
{
    // Destructor for a UI slider/list manager. Installs vtable off_5A7168, tears down the sub-object at this+96 via sub_4C5DE0, then installs vtable off_5A4550. Walks the singly linked list starting at this[60], conditionally destroying each node's embedded object (vtable entry 0 called with argument 1 when the node's flag byte is non-zero and the data pointer is non-null), frees every node through FreeWrapper_7bcf, and clears the four list state fields this[60..63]. Chains to the base-class destructor via sub_485EB0 and frees the object itself through FreeWrapper_7bcf when the delete flag a2 bit 0 is set.
    // ASSIGNMENT: Install the initial vtable pointer off_5A7168 into *this. [global:0x005A7168, field:this:0x00000000, source:raw]
    // CALL: Call sub_4C5DE0 on the sub-object at this + 96 to tear down that sub-structure. [callee:0x004C5DE0, source:raw]
    // ASSIGNMENT: Reinstall the vtable pointer off_5A4550 into *this for the remainder of the destructor. [global:0x005A4550, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Seed the traversal: v3 = this[60] (the list head). [field:this:0x000000F0, source:raw]
    // LOOP: Iterate the singly linked list while v3 is non-zero: capture the current node v4, advance v3 to the next node (node+4, matching the field layout *(this+0xF4)), then process and free the current node. [field:*(this+0xF0):0x00000000, field:*(this+0xF4):0x00000004, source:raw]
    // GUARD: Conditional object destroy: when the node's flag byte (node+12) is non-zero and the node's data pointer *v4 is non-null, call the embedded object's __thiscall destructor (vtable entry 0) with argument 1; the zero-check guard (this+0xFC == 0) is the packet-level guard evidence for this branch. [guard:0, field:*(*(this+0xF0)+0x0):0x00000000, source:raw]
    // CALL: Free each list node through FreeWrapper_7bcf(v4). [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Clear the list state after traversal: this[60], this[61], this[62] and this[63] are all set to 0. [field:this:0x000000F0, field:this:0x000000F4, field:this:0x000000F8, field:this:0x000000FC, source:raw]
    // CALL: Chain to the base-class destructor via sub_485EB0(this). [callee:0x00485EB0, source:raw]
    // GUARD: When the delete flag has bit 0 set ((a2 & 1) != 0), free the object itself through FreeWrapper_7bcf(this). [callee:0x00587BCF, source:raw]
    // RETURN: Return this (the object pointer). [source:raw]

    // Conservative worker pseudocode:
    //   *this = &off_5A7168;
    //   sub_4C5DE0(this + 96);
    //   *this = &off_5A4550;
    //   node = this[60];
    //   while (node) {
    //     next = *(node + 4);
    //     if (*(byte*)(node + 12) != 0 && *node)
    //       (**(void(***)(int,int))*node)(*node, 1);
    //     FreeWrapper_7bcf(node);
    //     node = next;
    //   }
    //   this[60] = 0; this[61] = 0; this[62] = 0; this[63] = 0;
    //   sub_485EB0(this);
    //   if (a2 & 1) FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: The concrete class owning this destructor is not evidenced by the packet; the existing analysis names it UISliderListDtor and identifies off_5A4550 as VTable_UISlider, both DERIVED and not adopted here.
    // UNRESOLVED: The node flag byte at node+12 appears in the raw source but has no dedicated field evidence reference; the packet-level guard (this+0xFC == 0) is the closest deterministic match and is used for the conditional-destroy branch.
    // UNRESOLVED: The legacy ABI name 'Destructor_with_List_Cleanup_and_Conditional_Fre' (abi:lead) is consistent with the raw source but not further grounded.
}
