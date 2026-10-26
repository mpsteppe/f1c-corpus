// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00474900
// Canonical corpus name: UICameraConstructor2
// Owner: UICamera [DERIVED]
// Raw source: functions/UICameraConstructor2_00474900.c

void UICamera::UICameraConstructor2()
{
    // Constructor for a UI camera object. Runs the base sub-object init ShortComputation_6d60 with flag 1, installs the vtable off_5A3CC0 at this+0x0, stores the data pointer unk_7CFC44 at this+0x31C, sets configuration flags (this+0x324=1, this+0x328=0, this+0x32C=1, this+0x330=1) and a preset value 398 at this+0x334, registers two linked-list nodes (off_5BE704 and the On string aOn) with id -1 via LinkedListInsertWithNodeAllocation, triggers virtual-dispatch initialization via SwitchOnActionIDVirtualCall, and returns this.
    // CALL: Runs base/sub-object init ShortComputation_6d60 on this with flag 1 [callee:0x00466D60]
    // ASSIGNMENT: Installs the vtable pointer off_5A3CC0 at this+0x0 [field:this:0x00000000, global:0x005A3CC0]
    // ASSIGNMENT: Stores the data pointer unk_7CFC44 at this+0x31C (this[199]) [field:this:0x0000031C, global:0x007CFC44]
    // ASSIGNMENT: Sets configuration fields: this+0x324=1, this+0x328=0, this+0x32C=1, this+0x330=1, and the preset value 398 at this+0x334 (this[201..205]) [field:this:0x00000324, field:this:0x00000328, field:this:0x0000032C, field:this:0x00000330, field:this:0x00000334]
    // CALL: Inserts a linked-list node for off_5BE704 with id -1 via LinkedListInsertWithNodeAllocation [callee:0x00486F30, global:0x005BE704]
    // CALL: Inserts a linked-list node for the On string aOn with id -1 via LinkedListInsertWithNodeAllocation [callee:0x00486F30, global:0x005C32C8]
    // CALL: Triggers virtual-dispatch initialization via SwitchOnActionIDVirtualCall(this) [callee:0x004670E0]
    // RETURN: Returns this, the constructed object [source:raw]

    // Conservative worker pseudocode:
    //   ShortComputation_6d60(this, 1);
    //   this[0] = &off_5A3CC0;
    //   this[199] = &unk_7CFC44;
    //   this[201] = 1; this[202] = 0; this[203] = 1; this[204] = 1; this[205] = 398;
    //   LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1);
    //   LinkedListInsertWithNodeAllocation(this, aOn, -1);
    //   SwitchOnActionIDVirtualCall(this);
    //   return this;
}
