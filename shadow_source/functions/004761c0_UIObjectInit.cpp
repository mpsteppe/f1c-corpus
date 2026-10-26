// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004761C0
// Canonical corpus name: UIObjectInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIObjectInit_004761c0.c

void UnknownObject::UIObjectInit()
{
    // Initializes a game-filter UI object. Calls the base UI object constructor, zeroes the query/index field at 0x40 (this[16]), sets the record sentinel field at 0x44 (this[17]) to -1, then installs the off_5A4478 vtable. Called once by GameFilterSetup (00477830).
    // CALL: Invokes the base UI object constructor UIObjectConstructor_fc50 (0048FC50) before any derived fields are set [callee:0x0048FC50, source:raw]
    // ASSIGNMENT: this[16] (byte offset 0x40) is set to 0, the filter query/index field [field:this:0x00000040, source:raw]
    // ASSIGNMENT: this[17] (byte offset 0x44) is set to -1, a record sentinel meaning not set [field:this:0x00000044, source:raw]
    // ASSIGNMENT: Vtable pointer at this (offset 0x0) is set to the off_5A4478 dispatch table for the game filter UI object [field:this:0x00000000, global:0x005A4478, source:raw]
    // RETURN: Returns this after construction is complete [function:0x004761C0, source:raw]
    // CALL: Invoked by GameFilterSetup (00477830) to build the game filter UI object [caller:0x00477830, source:raw]

    // Conservative worker pseudocode:
    //   UIObjectConstructor_fc50(this);
    //   this[16] = 0;
    //   this[17] = -1;
    //   *this = &off_5A4478;
    //   return this;
    // UNRESOLVED: The exact interpretation of the 0x40 and 0x44 fields (query/index versus record sentinel) is derived from the fill's naming, not from independent evidence in this packet
}
