// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048FE60
// Canonical corpus name: UIComponentInit5
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIComponentInit5_0048fe60.c

void UnknownObject::UIComponentInit5()
{
    // Initializes a UI component. Calls the base initializer ShortComputation_5e30 (00485E30), installs the off_5AC6B0 vtable at this (offset 0x0), then sets field 0xE0 (this[56]) to 1 and field 0xE4 (this[57]) to 0. Called by SessionFlagPointerSelector (0046FE80), SeasonDatabaseObjectFactory (0047F440) and sub_493FC0 (00493FC0).
    // CALL: Invokes the base initialization routine ShortComputation_5e30 (00485E30) before derived fields are set [callee:0x00485E30, source:raw]
    // ASSIGNMENT: Vtable pointer at this (offset 0x0) is set to the off_5AC6B0 dispatch table [field:this:0x00000000, global:0x005AC6B0, source:raw]
    // ASSIGNMENT: this[56] (byte offset 0xE0) is set to 1, a UI state/flag field [field:this:0x000000E0, source:raw]
    // ASSIGNMENT: this[57] (byte offset 0xE4) is set to 0, a UI state/flag field [field:this:0x000000E4, source:raw]
    // RETURN: Returns this after initialization is complete [function:0x0048FE60, source:raw]
    // CALL: Invoked by SessionFlagPointerSelector (0046FE80), SeasonDatabaseObjectFactory (0047F440) and sub_493FC0 (00493FC0) when constructing a UI component [caller:0x0046FE80, caller:0x0047F440, caller:0x00493FC0, source:raw]

    // Conservative worker pseudocode:
    //   ShortComputation_5e30(this);
    //   *this = &off_5AC6B0;
    //   this[56] = 1;
    //   this[57] = 0;
    //   return this;
    // UNRESOLVED: The semantic meaning of the 0xE0 and 0xE4 state fields (whether flags, counters, or state enums) is not determinable from this packet alone
}
