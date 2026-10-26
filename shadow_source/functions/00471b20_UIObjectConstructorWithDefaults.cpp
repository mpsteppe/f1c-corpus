// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00471B20
// Canonical corpus name: UIObjectConstructorWithDefaults
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIObjectConstructorWithDefaults_00471b20.c

void UnknownObject::UIObjectConstructorWithDefaults()
{
    // Constructor for a UI component. Runs base-class initialization ShortComputation_6d60(this, 1), writes vtable pointer off_5A1680 at this+0, stores the data-source pointer dword_7CE6F4 at this+0x31C, configures four state/config fields (2, 0, 1, 1) at this+0x324..0x330, stamps component identifier 247 at this+0x334, inserts three linked-list UI handle nodes (off_5BE704, off_5C32A4, aHigh) via LinkedListInsertWithNodeAllocation with key -1, then invokes post-init virtual dispatch SwitchOnActionIDVirtualCall(this). Returns this.
    // CALL: Base-class/subobject initialization: ShortComputation_6d60(this, 1). [callee:0x00466D60]
    // ASSIGNMENT: Install the type vtable: *this = &off_5A1680. [field:this:0x00000000, global:0x005A1680]
    // ASSIGNMENT: Store the data-source interface pointer: this[199] = &dword_7CE6F4 (offset 0x31C). [field:this:0x0000031C, global:0x007CE6F4]
    // ASSIGNMENT: Configure state fields: this[201] = 2, this[202] = 0, this[203] = 1, this[204] = 1 (offsets 0x324, 0x328, 0x32C, 0x330). [field:this:0x00000324, field:this:0x00000328, field:this:0x0000032C, field:this:0x00000330]
    // ASSIGNMENT: Stamp the component identifier: this[205] = 247 (offset 0x334). [field:this:0x00000334]
    // CALL: Insert the text handle node: LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1). [callee:0x00486F30, global:0x005BE704]
    // CALL: Insert the registered-data handle node: LinkedListInsertWithNodeAllocation(this, &off_5C32A4, -1). [callee:0x00486F30, global:0x005C32A4]
    // CALL: Insert the registered-control handle node: LinkedListInsertWithNodeAllocation(this, aHigh, -1). [callee:0x00486F30, global:0x005C32A8]
    // CALL: Post-init virtual dispatch: SwitchOnActionIDVirtualCall(this). [callee:0x004670E0]
    // RETURN: Return the initialized object pointer this. [function:0x00471B20, source:raw]

    // Conservative worker pseudocode:
    //   UIObjectConstructorWithDefaults(this) {
    //     ShortComputation_6d60(this, 1);
    //     this[0]   = &off_5A1680;
    //     this[0x31C] = &dword_7CE6F4;
    //     this[0x324] = 2;  this[0x328] = 0;
    //     this[0x32C] = 1;  this[0x330] = 1;
    //     this[0x334] = 247;
    //     LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1);
    //     LinkedListInsertWithNodeAllocation(this, &off_5C32A4, -1);
    //     LinkedListInsertWithNodeAllocation(this, aHigh, -1);
    //     SwitchOnActionIDVirtualCall(this);
    //     return this;
    //   }
    // UNRESOLVED: Semantic meaning of the four state fields at 0x324/0x328/0x32C/0x330 (two-state value/range interpretation is carried from existing analysis only).
    // UNRESOLVED: Role of the three inserted handle globals off_5BE704, off_5C32A4 and aHigh (text/registered handle labels are DERIVED corpus names).
    // UNRESOLVED: Meaning of the insertion key -1 passed to LinkedListInsertWithNodeAllocation.
}
