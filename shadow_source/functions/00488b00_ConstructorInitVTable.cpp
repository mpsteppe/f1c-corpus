// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00488B00
// Canonical corpus name: ConstructorInitVTable
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorInitVTable_00488b00.c

void UnknownObject::ConstructorInitVTable()
{
    // UI widget constructor: first runs the base initializer ShortComputation_5e30(this), then stores the two constructor parameters a2/a3 into this+0xE0 and this+0xE4, installs the vtable pointer off_5ABC28 at this+0x0, and sets the boolean flag at this+0xE8 to 1. Returns this. Called by seven widget-construction paths including GameOptionsUIConstructor (0047E960).
    // CALL: Run base initializer ShortComputation_5e30(this) to zero/fill base fields before vtable install. [callee:0x00485E30, source:raw]
    // ASSIGNMENT: Store first constructor parameter a2 at this+0xE0. [field:this:0x000000E0, source:raw]
    // ASSIGNMENT: Install the widget vtable pointer off_5ABC28 at this+0x0. [field:this:0x00000000, global:0x005ABC28, source:raw]
    // ASSIGNMENT: Set the boolean flag at this+0xE8 to literal 1 (active/enabled). [field:this:0x000000E8, source:raw]
    // ASSIGNMENT: Store second constructor parameter a3 at this+0xE4. [field:this:0x000000E4, source:raw]
    // RETURN: Return the this pointer. [source:raw]
    // CALL: Invoked by widget/UI construction paths: sub_47DAF0, GameOptionsUIConstructor (0047E960), ShortComputation_eff0 (0047EFF0), VTablePointerConstructor (0047F080), ObjectInitWithFieldZeroing (0048AA40), ConstructorDualSubInit (0048D660), and sub_493FC0. [caller:0x0047DAF0, caller:0x0047E960, caller:0x0047EFF0, caller:0x0047F080, caller:0x0048AA40, caller:0x0048D660, caller:0x00493FC0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_488B00(int this, int a2, int a3) {
    //     ShortComputation_5e30((void*)this);
    //     *(int*)(this + 0xE0) = a2;
    //     *(void**)this = &off_5ABC28;
    //     *(BYTE*)(this + 0xE8) = 1;
    //     *(int*)(this + 0xE4) = a3;
    //     return this;
    //   }
    // UNRESOLVED: Object identity is unknown; the off_5ABC28 vtable and caller set indicate a UI widget, but that identification is DERIVED from existing analysis and not independently confirmed.
    // UNRESOLVED: The semantic roles of constructor parameters a2 and a3 (stored at 0xE0/0xE4) are unverified.
}
