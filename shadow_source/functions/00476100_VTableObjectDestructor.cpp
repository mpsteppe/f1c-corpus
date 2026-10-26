// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00476100
// Canonical corpus name: VTableObjectDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableObjectDestructor_00476100.c

void UnknownObject::VTableObjectDestructor()
{
    // Multi-phase destructor for a UI/DB object. Installs the DB-object vtable off_5A4464 and frees the child resource at this+0x50, destroys the linked list at this+0x3C (invoking each node's virtual destructor through its node vtable with argument 1 when the node's +12 flag is non-zero and its vtable pointer is non-null), zeroes the list fields, then transitions the vtable through off_5A4450 and off_5A443C while freeing the children at this+0x30 and this+0x4. When the a2 flag's bit 0 is set, frees the object itself. Returns the this pointer.
    // ASSIGNMENT: Install the DB-object vtable off_5A4464 into this+0x0. [global:0x005A4464, field:this:0x00000000]
    // GUARD: Test whether the DB child resource at this+0x50 is non-null. [field:this:0x00000050]
    // CALL: Free the DB child resource at this+0x50 through FreeWrapper_7bcf. [callee:0x00587BCF]
    // LOOP: Iterate the linked list whose head is at this+0x3C, following each node's next pointer at node+4 until the chain is exhausted. [field:*(this+0x3C):0x00000000, field:this:0x0000003C]
    // GUARD: Per node, read the flag byte at node+12; when the byte is zero the node carries no interface to destroy. [guard:0, field:this:0x00000048]
    // CALL: When the node flag is non-zero and the node vtable pointer at node+0 is non-null, invoke the virtual destructor through that vtable with argument 1. [field:*(*(this+0x3C)+0x0):0x00000000, field:*(this+0x3C):0x00000000]
    // CALL: Free each list node itself through FreeWrapper_7bcf. [callee:0x00587BCF]
    // ASSIGNMENT: Clear the list bookkeeping fields this+0x3C, +0x40, +0x44 and +0x48 to 0. [field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048]
    // ASSIGNMENT: Re-point the vtable at this+0x0 to off_5A4450 (HUD layer). [global:0x005A4450, field:this:0x00000000]
    // GUARD: Test whether the child HUD node at this+0x30 is non-null. [field:this:0x00000030]
    // CALL: Free the child HUD node at this+0x30 through FreeWrapper_7bcf. [callee:0x00587BCF]
    // ASSIGNMENT: Re-point the vtable at this+0x0 to off_5A443C (control base). [global:0x005A443C, field:this:0x00000000]
    // GUARD: Test whether the owned resource at this+0x4 is non-null. [field:this:0x00000004]
    // CALL: Free the owned resource at this+0x4 through FreeWrapper_7bcf. [callee:0x00587BCF]
    // STATE_TRANSITION: When the a2 flag bit 0 is set, free the object itself through FreeWrapper_7bcf (scalar-delete pattern). [callee:0x00587BCF]
    // RETURN: Return the this pointer after the multi-phase teardown. [source:raw, function:0x00476100, abi:lead]

    // Conservative worker pseudocode:
    //   void *sub_476100(void *obj, char a2) {
    //     *(void **)obj = &off_5A4464;
    //     if (*(void **)((char *)obj + 0x50)) FreeWrapper_7bcf(*(void **)((char *)obj + 0x50));
    //     int node = *(int *)((char *)obj + 0x3C);
    //     while (node) {
    //       int nx = *(int *)(node + 4);
    //       int no_interface = *(char *)(node + 12) == 0;
    //       if (!no_interface && *(void **)node) (**(void (***)(void *, int))node)(*(void **)node, 1);
    //       FreeWrapper_7bcf((void *)node);
    //       node = nx;
    //     }
    //     *(int *)((char *)obj + 0x3C) = 0; *(int *)((char *)obj + 0x40) = 0;
    //     *(int *)((char *)obj + 0x44) = 0; *(int *)((char *)obj + 0x48) = 0;
    //     *(void **)obj = &off_5A4450;
    //     if (*(void **)((char *)obj + 0x30)) FreeWrapper_7bcf(*(void **)((char *)obj + 0x30));
    //     *(void **)obj = &off_5A443C;
    //     if (*(void **)((char *)obj + 0x4)) FreeWrapper_7bcf(*(void **)((char *)obj + 0x4));
    //     if (a2 & 1) FreeWrapper_7bcf(obj);
    //     return obj;
    //   }
    // UNRESOLVED: The three vtable globals off_5A4464, off_5A4450 and off_5A443C are not tied to confirmed classes; their corpus identities are DERIVED, not CONFIRMED.
    // UNRESOLVED: The a2 argument is a deletion-mode flag (bit 0 controls freeing self); the exact caller contract is unknown because there are no static callers.
    // UNRESOLVED: The virtual destructor invoked through each node's vtable is an indirect call; the concrete node class is unknown.
    // UNRESOLVED: The node+12 flag byte is expressed in the guard as this+0x48 because the extractor uses the list-head base this+0x3C plus the node offset.
    // UNRESOLVED: Ownership semantics of the freed children (which allocations each this+0x50, +0x30 and +0x4 pointer refers to) are unconfirmed.
}
