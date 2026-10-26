// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00475040
// Canonical corpus name: VTableSetterWithSubCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableSetterWithSubCall_00475040.c

void UnknownObject::UIObjectInitWithVTableCleanup()
{
    // Initializes a UI object: installs the vtable pointer off_5A42C0 into this + 0x0, then calls the sub-init routine InitWithVTableCleanup (FUN_00487250 per abi:lead) and returns its result. No guards; the function always executes fully.
    // ASSIGNMENT: Install the vtable pointer off_5A42C0 into this + 0x0, identifying the UI object type. [field:this:0x00000000, global:0x005A42C0, source:raw]
    // CALL: Call InitWithVTableCleanup(this) (FUN_00487250 per abi:lead) to complete initialization after the vtable swap. [abi:lead, source:raw]
    // RETURN: Return the result of InitWithVTableCleanup. [function:0x00475040, source:raw]

    // Conservative worker pseudocode:
    //   *this = &off_5A42C0;
    //   return InitWithVTableCleanup(this);
    // UNRESOLVED: InitWithVTableCleanup (FUN_00487250) is named in abi:lead and the raw source but is not listed in the packet callee table; its behavior and return semantics are not established by this packet.
    // UNRESOLVED: The exact object type behind this vtable pointer and the meaning of the returned integer are not derivable from this packet.
    // UNRESOLVED: The caller ConditionalFreeWithFlagCheck (0x00475020) is known but the call context is not present in the packet.
}
