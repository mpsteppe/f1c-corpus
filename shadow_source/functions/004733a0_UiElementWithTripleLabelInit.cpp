// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004733A0
// Canonical corpus name: ReferencesGlobalState_33a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ReferencesGlobalState_33a0_004733a0.c

void UnknownObject::UiElementWithTripleLabelInit()
{
    // UI-element constructor/initializer. Calls the shared base initializer ShortComputation_6d60(this, 1), then sets the vtable pointer to off_5A27C0 at this[0], stores a pointer to the global reference dword_7D02E4 at this[199] (offset 0x31C), writes the literal flag fields at this[201..204] (3/0/3/3) and value 270 at this[205] (0x334), and registers four text-handle nodes into the linked list: off_5BE704 followed by three copies of the "On" label handle aOn. Returns this.
    // CALL: Call the shared base initializer ShortComputation_6d60(this, 1). [callee:0x00466D60, source:raw]
    // ASSIGNMENT: Set the vtable pointer at this[0] to &off_5A27C0. [field:this:0x00000000, global:0x005A27C0, source:raw]
    // ASSIGNMENT: Store the pointer to the global reference dword_7D02E4 at this[199] (offset 0x31C). [field:this:0x0000031C, global:0x007D02E4, source:raw]
    // ASSIGNMENT: Write literal 3 to this[201] (0x324), 0 to this[202] (0x328), 3 to this[203] (0x32C) and 3 to this[204] (0x330). [field:this:0x00000324, field:this:0x00000328, field:this:0x0000032C, field:this:0x00000330, source:raw]
    // ASSIGNMENT: Write literal 270 to this[205] (offset 0x334). [field:this:0x00000334, source:raw]
    // CALL: Insert a linked-list node carrying the text handle &off_5BE704 via LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1). [callee:0x00486F30, global:0x005BE704, source:raw]
    // CALL: Insert a linked-list node carrying the "On" label handle via LinkedListInsertWithNodeAllocation(this, aOn, -1) (first of three). [callee:0x00486F30, global:0x005C32C8, source:raw]
    // CALL: Insert a second linked-list node carrying the "On" label handle via LinkedListInsertWithNodeAllocation(this, aOn, -1). [callee:0x00486F30, global:0x005C32C8, source:raw]
    // CALL: Insert a third linked-list node carrying the "On" label handle via LinkedListInsertWithNodeAllocation(this, aOn, -1). [callee:0x00486F30, global:0x005C32C8, source:raw]
    // RETURN: Return this. [function:0x004733A0, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* sub_4733A0(this) {
    //     ShortComputation_6d60(this, 1);
    //     this[0]   = &off_5A27C0;
    //     this[199] = &dword_7D02E4;
    //     this[201] = 3; this[202] = 0; this[203] = 3; this[204] = 3;
    //     this[205] = 270;
    //     LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1);
    //     LinkedListInsertWithNodeAllocation(this, aOn, -1);
    //     LinkedListInsertWithNodeAllocation(this, aOn, -1);
    //     LinkedListInsertWithNodeAllocation(this, aOn, -1);
    //     return this;
    //   }
    // UNRESOLVED: Exact meaning of the flag fields at offsets 0x324, 0x328, 0x32C and 0x330 (values 3/0/3/3) is not established by the raw source.
    // UNRESOLVED: Purpose of the value 270 at offset 0x334 is unknown.
    // UNRESOLVED: Why three copies of the "On" label handle aOn are inserted (triple-label layout) is not grounded in the raw source.
    // UNRESOLVED: Semantics of ShortComputation_6d60(this, 1) as base initializer are not grounded here.
    // UNRESOLVED: Legacy ABI naming References_Global_State_Object_Constructor is not evidence of a specific class identity.
}
