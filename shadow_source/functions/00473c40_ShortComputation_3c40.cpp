// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00473C40
// Canonical corpus name: ShortComputation_3c40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_3c40_00473c40.c

void UnknownObject::ShortComputation_3c40()
{
    // Straight-line initializer. Calls ShortComputation_6d60(this, 1) first, installs vtable off_5A2F40 at this+0x0, stores data reference unk_7CF7D0 at this+0x31C, writes state/flag literals 1,0,1,1 at this+0x324..+0x330, stores value 379 at this+0x334, appends two linked-list nodes (off_5BE704 and the "On" string handle aOn) with value -1, then runs SwitchOnActionIDVirtualCall(this) and returns this. Shape matches a UI element constructor; exact field semantics are DERIVED from existing analysis only.
    // CALL: Call ShortComputation_6d60(this, 1) to run the shared base-field initialization with argument 1. [callee:0x00466D60, source:raw]
    // ASSIGNMENT: Install vtable pointer off_5A2F40 at this+0x0. [field:this:0x00000000, global:0x005A2F40, source:raw]
    // ASSIGNMENT: Store pointer unk_7CF7D0 at this+0x31C (this[199]); role is a data reference assigned during construction. [field:this:0x0000031C, global:0x007CF7D0, source:raw]
    // ASSIGNMENT: Set this+0x324 (this[201]) to 1. [field:this:0x00000324, source:raw]
    // ASSIGNMENT: Set this+0x328 (this[202]) to 0. [field:this:0x00000328, source:raw]
    // ASSIGNMENT: Set this+0x32C (this[203]) to 1. [field:this:0x0000032C, source:raw]
    // ASSIGNMENT: Set this+0x330 (this[204]) to 1. [field:this:0x00000330, source:raw]
    // ASSIGNMENT: Set this+0x334 (this[205]) to 379, a counter/limit/value preset. [field:this:0x00000334, source:raw]
    // CALL: Insert linked-list node from handle off_5BE704 with value -1 via LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1). [callee:0x00486F30, global:0x005BE704, source:raw]
    // CALL: Insert linked-list node from handle aOn ("On") with value -1 via LinkedListInsertWithNodeAllocation(this, &aOn, -1). [callee:0x00486F30, global:0x005C32C8, source:raw]
    // CALL: Run SwitchOnActionIDVirtualCall(this) to finish construction-time virtual dispatch. [callee:0x004670E0, source:raw]
    // RETURN: Return this, the fully initialized object. [function:0x00473C40, source:raw]

    // Conservative worker pseudocode:
    //   ShortComputation_6d60(this, 1);
    //   this[0] = &off_5A2F40;
    //   this[199] = &unk_7CF7D0;
    //   this[201] = 1; this[202] = 0; this[203] = 1; this[204] = 1;
    //   this[205] = 379;
    //   LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1);
    //   LinkedListInsertWithNodeAllocation(this, &aOn, -1);
    //   SwitchOnActionIDVirtualCall(this);
    //   return this;
    // UNRESOLVED: Exact semantics of the literal block at +0x324..+0x330 and the value 379 at +0x334 are unverified; existing analysis labels this a UI element with an "On" label (DERIVED).
    // UNRESOLVED: Purpose of the two linked-list handles off_5BE704 and aOn ("On") is unverified.
    // UNRESOLVED: Owner class is unknown; no static caller found.
}
