// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00473330
// Canonical corpus name: ShortComputation_3330
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_3330_00473330.c

void UnknownObject::UiElementWithEnableFlagInit()
{
    // UI-element constructor/initializer. Calls the common base initializer ShortComputation_6d60(this, 1), then sets the vtable pointer to off_5A2700 at this[0], stores a pointer to the global enable flag dword_7CF788 at this[199] (offset 0x31C), writes the literal flag fields at this[201..204] (1/0/1/1) and value 269 at this[205] (0x334), and registers two text-handle nodes into the linked list: off_5BE704 and the "On" label handle aOn. Returns this.
    // CALL: Call the shared base initializer ShortComputation_6d60(this, 1). [callee:0x00466D60, source:raw]
    // ASSIGNMENT: Set the vtable pointer at this[0] to &off_5A2700. [field:this:0x00000000, global:0x005A2700, source:raw]
    // ASSIGNMENT: Store the pointer to the global enable flag dword_7CF788 at this[199] (offset 0x31C). [field:this:0x0000031C, global:0x007CF788, source:raw]
    // ASSIGNMENT: Write literal 1 to this[201] (0x324), 0 to this[202] (0x328), 1 to this[203] (0x32C) and 1 to this[204] (0x330). [field:this:0x00000324, field:this:0x00000328, field:this:0x0000032C, field:this:0x00000330, source:raw]
    // ASSIGNMENT: Write literal 269 to this[205] (offset 0x334). [field:this:0x00000334, source:raw]
    // CALL: Insert a linked-list node carrying the text handle &off_5BE704 via LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1). [callee:0x00486F30, global:0x005BE704, source:raw]
    // CALL: Insert a linked-list node carrying the "On" label handle via LinkedListInsertWithNodeAllocation(this, aOn, -1). [callee:0x00486F30, global:0x005C32C8, source:raw]
    // RETURN: Return this. [function:0x00473330, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* sub_473330(this) {
    //     ShortComputation_6d60(this, 1);
    //     this[0]   = &off_5A2700;
    //     this[199] = &dword_7CF788;
    //     this[201] = 1; this[202] = 0; this[203] = 1; this[204] = 1;
    //     this[205] = 269;
    //     LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1);
    //     LinkedListInsertWithNodeAllocation(this, aOn, -1);
    //     return this;
    //   }
    // UNRESOLVED: Exact meaning of the flag fields at offsets 0x324, 0x328, 0x32C and 0x330 (values 1/0/1/1) is not established by the raw source.
    // UNRESOLVED: Purpose of the value 269 at offset 0x334 is unknown.
    // UNRESOLVED: Semantics of ShortComputation_6d60(this, 1) as base initializer are not grounded here.
    // UNRESOLVED: The list of text-handle nodes (off_5BE704 and aOn) is assumed to form label text entries; node structure and consumption are external.
    // UNRESOLVED: Legacy ABI naming Short_Computation_473330 is not evidence of a specific class identity.
}
