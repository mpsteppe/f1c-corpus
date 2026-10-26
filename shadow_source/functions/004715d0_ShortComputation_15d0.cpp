// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004715D0
// Canonical corpus name: ShortComputation_15d0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_15d0_004715d0.c

void UnknownObject::ShortComputation_15d0()
{
    // Straight-line initializer. Calls ShortComputation_6d60(this, 1) first, installs vtable off_5A0F00 at this+0x0, stores data reference dword_7CE850 at this+0x31C, writes state/flag literals 1,0,1,1 at this+0x324..+0x330, stores component ID 237 at this+0x334, appends two linked-list nodes (off_5BE704 and the "On" string handle aOn) with value -1, then runs SwitchOnActionIDVirtualCall(this) and returns this. Shape matches a UI element constructor; exact field semantics are DERIVED from existing analysis only.
    // CALL: Call ShortComputation_6d60(this, 1) to run the shared base-field initialization with argument 1. [callee:0x00466D60, source:raw]
    // ASSIGNMENT: Install vtable pointer off_5A0F00 at this+0x0. [field:this:0x00000000, global:0x005A0F00, source:raw]
    // ASSIGNMENT: Store pointer dword_7CE850 at this+0x31C (this[199]); role is a data reference assigned during construction. [field:this:0x0000031C, global:0x007CE850, source:raw]
    // ASSIGNMENT: Set this+0x324 (this[201]) to 1. [field:this:0x00000324, source:raw]
    // ASSIGNMENT: Set this+0x328 (this[202]) to 0. [field:this:0x00000328, source:raw]
    // ASSIGNMENT: Set this+0x32C (this[203]) to 1. [field:this:0x0000032C, source:raw]
    // ASSIGNMENT: Set this+0x330 (this[204]) to 1. [field:this:0x00000330, source:raw]
    // ASSIGNMENT: Set this+0x334 (this[205]) to 237, the component identifier. [field:this:0x00000334, source:raw]
    // CALL: Insert linked-list node from handle off_5BE704 with value -1 via LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1). [callee:0x00486F30, global:0x005BE704, source:raw]
    // CALL: Insert linked-list node from handle aOn ("On") with value -1 via LinkedListInsertWithNodeAllocation(this, &aOn, -1). [callee:0x00486F30, global:0x005C32C8, source:raw]
    // CALL: Run SwitchOnActionIDVirtualCall(this) to finish construction-time virtual dispatch. [callee:0x004670E0, source:raw]
    // RETURN: Return this, the fully initialized object. [function:0x004715D0, source:raw]

    // Conservative worker pseudocode:
    //   ShortComputation_6d60(this, 1);
    //   this[0] = &off_5A0F00;
    //   this[199] = &dword_7CE850;
    //   this[201] = 1; this[202] = 0; this[203] = 1; this[204] = 1;
    //   this[205] = 237;
    //   LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1);
    //   LinkedListInsertWithNodeAllocation(this, &aOn, -1);
    //   SwitchOnActionIDVirtualCall(this);
    //   return this;
    // UNRESOLVED: Exact semantics of the literal block at +0x324..+0x334 (flags vs min/max vs ID) are unverified; existing analysis labels this a UI component with ID 237 (DERIVED).
    // UNRESOLVED: Purpose of the two linked-list handles off_5BE704 and aOn ("On") is unverified.
    // UNRESOLVED: Owner class is unknown; no static caller found.
}
