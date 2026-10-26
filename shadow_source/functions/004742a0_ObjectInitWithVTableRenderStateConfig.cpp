// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004742A0
// Canonical corpus name: ObjectInitWithVTableRenderStateConfig
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInitWithVTableRenderStateConfig_004742a0.c

void UnknownObject::ObjectInitWithVTableRenderStateConfig()
{
    // UI element constructor. Calls a short pre-init helper on the object, installs the vtable off_5A3840, stores the camera center/target pointer (dword_7CF680) at this+0x31C, writes a run of configuration literals (1, 0, 1, 1) at this+0x324..+0x330 and 392 at this+0x334, registers two text-handle nodes (off_5BE704 and the "On" label aOn) into a linked list, then triggers virtual action-ID dispatch and returns the object.
    // CALL: ShortComputation_6d60(this, 1) performs the shared pre-initialization of the object with a constant argument 1 before any fields are written [callee:0x00466D60, source:raw]
    // ASSIGNMENT: Install the type vtable: this+0x0 = off_5A3840 [field:this:0x00000000, global:0x005A3840, source:raw]
    // ASSIGNMENT: Store the camera center/target position pointer: this+0x31C = &dword_7CF680 [field:this:0x0000031C, global:0x007CF680, source:raw]
    // ASSIGNMENT: Write the configuration run: this+0x324 = 1, this+0x328 = 0, this+0x32C = 1, this+0x330 = 1 [field:this:0x00000324, field:this:0x00000328, field:this:0x0000032C, field:this:0x00000330, source:raw]
    // ASSIGNMENT: Write the value literal 392 at this+0x334 [field:this:0x00000334, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1) registers the first text-handle node into the object's linked list with sentinel -1 [callee:0x00486F30, global:0x005BE704, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(this, aOn, -1) registers the "On" label text-handle node into the object's linked list with sentinel -1 [callee:0x00486F30, global:0x005C32C8, source:raw]
    // CALL: SwitchOnActionIDVirtualCall(this) triggers the virtual action-ID dispatch to finish initialization [callee:0x004670E0, source:raw]
    // RETURN: Return the fully constructed object pointer [function:0x004742A0, source:raw]

    // Conservative worker pseudocode:
    //   ShortComputation_6d60(this, 1);
    //   this->vtable = &off_5A3840;
    //   this[0x31C/4] = &dword_7CF680;
    //   this[0x324/4] = 1; this[0x328/4] = 0;
    //   this[0x32C/4] = 1; this[0x330/4] = 1;
    //   this[0x334/4] = 392;
    //   LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1);
    //   LinkedListInsertWithNodeAllocation(this, aOn, -1);
    //   SwitchOnActionIDVirtualCall(this);
    //   return this;
    // UNRESOLVED: Semantics of the literals at this+0x324..+0x334 (flag run plus 392) are not determinable from this packet
    // UNRESOLVED: The meaning of the -1 sentinel argument to LinkedListInsertWithNodeAllocation is not documented here
}
