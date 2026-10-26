// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00471970
// Canonical corpus name: ShortComputation_1970
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_1970_00471970.c

void UnknownObject::UIComponentConstructor()
{
    // Constructor for a UI component object (component ID 244). Calls the shared base initializer ShortComputation_6d60 with 1, writes the vtable pointer off_5A1440 to this+0x0 and binds the data source interface pointer dword_7CE7F0 at this+0x31C, configures a two-value state block (this+0x324 = 2, +0x328 = 0, +0x32C = 1, +0x330 = 1) and the component ID (this+0x334 = 244), inserts three linked-list UI handles (off_5BE704, off_5C32A4, aHigh) with index -1, then invokes the post-construction virtual dispatch SwitchOnActionIDVirtualCall.
    // CALL: Base-object initialization: ShortComputation_6d60(this, 1) runs before any fields of this object are written [callee:0x00466D60, source:raw]
    // ASSIGNMENT: Set the virtual method table pointer at this+0x0 to the vtable global off_5A1440 [field:this:0x00000000, global:0x005A1440, source:raw]
    // ASSIGNMENT: Bind the data source interface pointer at this+0x31C to the global object dword_7CE7F0 [field:this:0x0000031C, global:0x007CE7F0, source:raw]
    // ASSIGNMENT: Configure the value-count field at this+0x324 to 2 (two-state component) [field:this:0x00000324, source:raw]
    // ASSIGNMENT: Set the initial/current state value at this+0x328 to 0 [field:this:0x00000328, source:raw]
    // ASSIGNMENT: Set the state-range/value field at this+0x32C to 1 [field:this:0x0000032C, source:raw]
    // ASSIGNMENT: Set the state-range/value field at this+0x330 to 1 [field:this:0x00000330, source:raw]
    // ASSIGNMENT: Write the unique component ID 244 to this+0x334 [field:this:0x00000334, source:raw]
    // CALL: Insert text handle global off_5BE704 into the linked list of UI handles with index -1 [callee:0x00486F30, global:0x005BE704, source:raw]
    // CALL: Insert registered-data global off_5C32A4 into the linked list of UI handles with index -1 [callee:0x00486F30, global:0x005C32A4, source:raw]
    // CALL: Insert registered-control global aHigh (0x005C32A8) into the linked list of UI handles with index -1 [callee:0x00486F30, global:0x005C32A8, source:raw]
    // CALL: Post-construction dispatch: SwitchOnActionIDVirtualCall(this) invoked after all fields and handles are installed [callee:0x004670E0, source:raw]
    // RETURN: Return the initialized this pointer [source:raw]

    // Conservative worker pseudocode:
    //   UIComponentConstructor(this) {
    //     ShortComputation_6d60(this, 1);
    //     this->vtable = &off_5A1440;
    //     this->dataSource = &dword_7CE7F0;
    //     this[0x324/4] = 2; this[0x328/4] = 0;
    //     this[0x32C/4] = 1; this[0x330/4] = 1;
    //     this[0x334/4] = 244;
    //     LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1);
    //     LinkedListInsertWithNodeAllocation(this, &off_5C32A4, -1);
    //     LinkedListInsertWithNodeAllocation(this, &aHigh, -1);
    //     SwitchOnActionIDVirtualCall(this);
    //     return this;
    //   }
    // UNRESOLVED: The exact role of the three inserted handle globals (off_5BE704, off_5C32A4, aHigh) as text/data/control elements is DERIVED from the skeleton fill, not proven by this packet
    // UNRESOLVED: The meaning of the 2/0/1/1 state block at this+0x324..+0x330 (value count, current value, range bounds) is a DERIVED interpretation
    // UNRESOLVED: The identity and behavior of the data source object dword_7CE7F0 and the post-init virtual dispatch are not documented in this packet
}
