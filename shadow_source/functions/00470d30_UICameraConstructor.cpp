// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00470D30
// Canonical corpus name: UICameraConstructor
// Owner: UICamera [DERIVED]
// Raw source: functions/UICameraConstructor_00470d30.c

void UICamera::UICameraConstructor()
{
    // Constructor for a UI camera object. Runs the base sub-object init ShortComputation_6d60 with flag 1, installs the vtable off_5A0900 at this+0x0, stores the data pointer dword_7CF038 at this+0x31C, sets configuration flags (this+0x324=1, this+0x328=0, this+0x32C=1, this+0x330=1) and a preset value 409 at this+0x334, registers two linked-list nodes (off_5BE704 and the On string aOn) with id -1 via LinkedListInsertWithNodeAllocation, and returns this. Sibling of UICameraConstructor2, which additionally calls SwitchOnActionIDVirtualCall.
    // CALL: Runs base/sub-object init ShortComputation_6d60 on this with flag 1 [callee:0x00466D60]
    // ASSIGNMENT: Installs the vtable pointer off_5A0900 at this+0x0 [field:this:0x00000000, global:0x005A0900]
    // ASSIGNMENT: Stores the data pointer dword_7CF038 at this+0x31C (this[199]) [field:this:0x0000031C, global:0x007CF038]
    // ASSIGNMENT: Sets configuration fields: this+0x324=1, this+0x328=0, this+0x32C=1, this+0x330=1, and the preset value 409 at this+0x334 (this[201..205]) [field:this:0x00000324, field:this:0x00000328, field:this:0x0000032C, field:this:0x00000330, field:this:0x00000334]
    // CALL: Inserts a linked-list node for off_5BE704 with id -1 via LinkedListInsertWithNodeAllocation [callee:0x00486F30, global:0x005BE704]
    // CALL: Inserts a linked-list node for the On string aOn with id -1 via LinkedListInsertWithNodeAllocation [callee:0x00486F30, global:0x005C32C8]
    // RETURN: Returns this, the constructed object [source:raw]

    // Conservative worker pseudocode:
    //   ShortComputation_6d60(this, 1);
    //   this[0] = &off_5A0900;
    //   this[199] = &dword_7CF038;
    //   this[201] = 1; this[202] = 0; this[203] = 1; this[204] = 1; this[205] = 409;
    //   LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1);
    //   LinkedListInsertWithNodeAllocation(this, aOn, -1);
    //   return this;
}
