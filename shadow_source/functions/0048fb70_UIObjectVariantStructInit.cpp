// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048FB70
// Canonical corpus name: ShortComputation_fb70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_fb70_0048fb70.c

void UnknownObject::UIObjectVariantStructInit()
{
    // UI-object variant initialization. Calls ShortComputation_5e30 for the base struct init, installs the off_5AC5F0 vtable pointer into this+0x0, zeroes the counter/resource field at this+0xE0, and sets the no-selection sentinel -1 at this+0xE4. Returns this.
    // CALL: Base struct initialization performed first via ShortComputation_5e30 [callee:0x00485E30, source:raw]
    // ASSIGNMENT: Installs the off_5AC5F0 vtable pointer into this+0x0 [field:this:0x00000000, global:0x005AC5F0, source:raw]
    // ASSIGNMENT: Zeroes the counter/resource field at this+0xE0 [field:this:0x000000E0, source:raw]
    // ASSIGNMENT: Sets the no-selection/invalid-handle sentinel -1 at this+0xE4 [field:this:0x000000E4, source:raw]
    // RETURN: Returns the initialized this pointer [function:0x0048FB70, source:raw]
    // STATE_TRANSITION: Used as a construction path by sub_478110, ShortComputation_81e0 and ObjectConstructorWithVTable_8280 [caller:0x00478110, caller:0x004781E0, caller:0x00478280, source:raw]

    // Conservative worker pseudocode:
    //   ShortComputation_5e30(this);
    //   *(vtable_t**)this = &off_5AC5F0;
    //   this[56] = 0;
    //   this[57] = -1;
    //   return this;
    // UNRESOLVED: The concrete class identity is not recoverable from this packet; owner stays UnknownObject
    // UNRESOLVED: off_5AC5F0 vtable layout and the meaning of the -1 sentinel at this+0xE4 are not established from this packet alone
}
