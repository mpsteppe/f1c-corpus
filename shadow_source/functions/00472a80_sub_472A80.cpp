// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00472A80
// Canonical corpus name: sub_472A80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_472A80_00472a80.c

void UnknownObject::sub_472A80()
{
    // Straight-line initializer. Calls ShortComputation_6d60(this, 1) first, installs vtable off_5A2280 at this+0x0, stores data reference unk_7D1334 at this+0x31C, writes state/flag literals 1,0,1,1 at this+0x324..+0x330, stores value 263 at this+0x338, appends two linked-list nodes (off_5BE704 and the "On" string handle aOn) with value -1, then runs SwitchOnActionIDVirtualCall(this) and returns this. Shape matches a UI element constructor; exact field semantics are DERIVED from existing analysis only.
    // CALL: Call ShortComputation_6d60(this, 1) to run the shared base-field initialization with argument 1. [callee:0x00466D60, source:raw]
    // ASSIGNMENT: Install vtable pointer off_5A2280 at this+0x0. [field:this:0x00000000, global:0x005A2280, source:raw]
    // ASSIGNMENT: Store pointer unk_7D1334 at this+0x31C (this[199]); role is a data reference assigned during construction. [field:this:0x0000031C, global:0x007D1334, source:raw]
    // ASSIGNMENT: Set this+0x324 (this[201]) to 1. [field:this:0x00000324, source:raw]
    // ASSIGNMENT: Set this+0x328 (this[202]) to 0. [field:this:0x00000328, source:raw]
    // ASSIGNMENT: Set this+0x32C (this[203]) to 1. [field:this:0x0000032C, source:raw]
    // ASSIGNMENT: Set this+0x330 (this[204]) to 1. [field:this:0x00000330, source:raw]
    // ASSIGNMENT: Set this+0x338 (this[206]) to 263, a counter/limit/value preset. [field:this:0x00000338, source:raw]
    // CALL: Insert linked-list node from handle off_5BE704 with value -1 via LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1). [callee:0x00486F30, global:0x005BE704, source:raw]
    // CALL: Insert linked-list node from handle aOn ("On") with value -1 via LinkedListInsertWithNodeAllocation(this, &aOn, -1). [callee:0x00486F30, global:0x005C32C8, source:raw]
    // CALL: Run SwitchOnActionIDVirtualCall(this) to finish construction-time virtual dispatch. [callee:0x004670E0, source:raw]
    // RETURN: Return this, the fully initialized object. [function:0x00472A80, source:raw]

    // Conservative worker pseudocode:
    //   ShortComputation_6d60(this, 1);
    //   this[0] = &off_5A2280;
    //   this[199] = &unk_7D1334;
    //   this[201] = 1; this[202] = 0; this[203] = 1; this[204] = 1;
    //   this[206] = 263;
    //   LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1);
    //   LinkedListInsertWithNodeAllocation(this, &aOn, -1);
    //   SwitchOnActionIDVirtualCall(this);
    //   return this;
    // UNRESOLVED: Exact semantics of the literal block at +0x324..+0x330 and the preset 263 at +0x338 are unverified; existing analysis labels this a UI element with an "On" label (DERIVED).
    // UNRESOLVED: Purpose of the two linked-list handles off_5BE704 and aOn ("On") is unverified.
    // UNRESOLVED: Owner class is unknown; no static caller found.
}
