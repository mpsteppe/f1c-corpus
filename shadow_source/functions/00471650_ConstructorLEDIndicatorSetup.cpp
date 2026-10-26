// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00471650
// Canonical corpus name: ConstructorLEDIndicatorSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorLEDIndicatorSetup_00471650.c

void UnknownObject::ConstructorLEDIndicatorSetup()
{
    // UI component constructor (thiscall) with a LED-indicator configuration. Runs the base initializer ShortComputation_6d60, installs the vtable pointer off_5A0FC0 at +0x0, points the data source field +0x31C at dword_7CE7A8, sets the flag words +0x324/+0x328/+0x32C/+0x330 to 1/0/1/1, stores literal 238 at +0x334, inserts two linked-list entries (off_5BE704 and the "On" string aOn) with node allocation and a -1 index, then runs SwitchOnActionIDVirtualCall for post-init dispatch. Returns the receiver.
    // CALL: Runs base initialization via ShortComputation_6d60(this, 1) [callee:0x00466D60, source:raw]
    // ASSIGNMENT: Installs the class vtable pointer off_5A0FC0 into word this+0x0 [field:this:0x00000000, global:0x005A0FC0, source:raw]
    // ASSIGNMENT: Stores the data source pointer dword_7CE7A8 into word this+0x31C [field:this:0x0000031C, global:0x007CE7A8, source:raw]
    // ASSIGNMENT: Writes the flag/state words: this+0x324 = 1, this+0x328 = 0, this+0x32C = 1, this+0x330 = 1 [field:this:0x00000324, field:this:0x00000328, field:this:0x0000032C, field:this:0x00000330, source:raw]
    // ASSIGNMENT: Stores literal 238 into word this+0x334 (component ID; interpretation not established by this packet) [field:this:0x00000334, source:raw]
    // CALL: Inserts a linked-list entry for the off_5BE704 handle via LinkedListInsertWithNodeAllocation(this, off_5BE704, -1) [callee:0x00486F30, global:0x005BE704, source:raw]
    // CALL: Inserts a linked-list entry for the "On" string handle aOn via LinkedListInsertWithNodeAllocation(this, aOn, -1) [callee:0x00486F30, global:0x005C32C8, source:raw]
    // CALL: Runs post-init virtual dispatch via SwitchOnActionIDVirtualCall(this) [callee:0x004670E0, source:raw]
    // RETURN: Returns the initialized receiver pointer (this) [source:raw]

    // Conservative worker pseudocode:
    //   ShortComputation_6d60(this, 1);
    //   this[0x0/4] = &off_5A0FC0;
    //   this[0x31C/4] = &dword_7CE7A8;
    //   this[0x324/4] = 1; this[0x328/4] = 0;
    //   this[0x32C/4] = 1; this[0x330/4] = 1;
    //   this[0x334/4] = 238;
    //   LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1);
    //   LinkedListInsertWithNodeAllocation(this, (int)&aOn, -1);
    //   SwitchOnActionIDVirtualCall(this);
    //   return this;
    // UNRESOLVED: Semantics of the flag words +0x324/+0x328/+0x32C/+0x330 and the literal 238 at +0x334 are not established by this packet
    // UNRESOLVED: Purpose of dword_7CE7A8 as a data source and of the two linked-list entries is inferred from the skeleton fill, not from raw source
    // UNRESOLVED: Whether this and UIScreenConstructor (00470670) share a common base layout is not provable from these packets alone
}
