// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00471750
// Canonical corpus name: ObjectInitializerWithGlobals
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInitializerWithGlobals_00471750.c

void UnknownObject::ObjectInitializerWithGlobals()
{
    // Constructs a UI component: runs a short per-instance setup with constant 1, installs the vtable at this+0x0, binds the data-source pointer at this+0x31C to dword_7CE718, seeds the state/config fields (this+0x324 = 2, this+0x328 = 0, this+0x32C = 1, this+0x330 = 1, this+0x334 = 240), inserts three linked-list nodes with node allocation each tagged -1, and finishes with the post-init virtual dispatch. Returns this.
    // CALL: Calls ShortComputation_6d60(this, 1) with the instance and constant 1 as a per-instance setup step. [callee:0x00466D60, source:raw]
    // ASSIGNMENT: Installs the vtable: *this = &off_5A1140. [field:this:0x00000000, global:0x005A1140, source:raw]
    // ASSIGNMENT: Binds the data-source pointer: this[199] (this+0x31C) = &dword_7CE718. [field:this:0x0000031C, global:0x007CE718, source:raw]
    // ASSIGNMENT: this[201] (this+0x324) = 2, setting the value/state count. [field:this:0x00000324, source:raw]
    // ASSIGNMENT: this[202] (this+0x328) = 0, initial/current state value. [field:this:0x00000328, source:raw]
    // ASSIGNMENT: this[203] (this+0x32C) = 1, minimum state value or enabled flag. [field:this:0x0000032C, source:raw]
    // ASSIGNMENT: this[204] (this+0x330) = 1, maximum state value or visibility flag. [field:this:0x00000330, source:raw]
    // ASSIGNMENT: this[205] (this+0x334) = 240, the component ID. [field:this:0x00000334, source:raw]
    // CALL: Calls LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1), inserting the first global handle as a new node. [callee:0x00486F30, global:0x005BE704, source:raw]
    // CALL: Calls LinkedListInsertWithNodeAllocation(this, &off_5C32A4, -1), inserting the second global handle as a new node. [callee:0x00486F30, global:0x005C32A4, source:raw]
    // CALL: Calls LinkedListInsertWithNodeAllocation(this, &aHigh, -1), inserting the third global handle as a new node. [callee:0x00486F30, global:0x005C32A8, source:raw]
    // CALL: Calls SwitchOnActionIDVirtualCall(this) as the post-init virtual dispatch. [callee:0x004670E0, source:raw]
    // RETURN: Returns this, the constructed object. [function:0x00471750, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *ObjectInitializerWithGlobals(_DWORD *this) {
    //     ShortComputation_6d60(this, 1);
    //     *this = &off_5A1140;
    //     this[199] = &dword_7CE718;
    //     this[201] = 2; this[202] = 0; this[203] = 1; this[204] = 1; this[205] = 240;
    //     LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1);
    //     LinkedListInsertWithNodeAllocation(this, &off_5C32A4, -1);
    //     LinkedListInsertWithNodeAllocation(this, &aHigh, -1);
    //     SwitchOnActionIDVirtualCall(this);
    //     return this;
    //   }
    // UNRESOLVED: Exact roles of the three linked-list handles (off_5BE704, off_5C32A4, aHigh) and of dword_7CE718 are inferred from the existing fill as UI text/data/control handles; the object type is not evidenced.
    // UNRESOLVED: Meaning of the -1 tag passed to LinkedListInsertWithNodeAllocation is not established.
    // UNRESOLVED: Semantics of ShortComputation_6d60's constant 1 and of SwitchOnActionIDVirtualCall's dispatch target are not evidenced.
}
