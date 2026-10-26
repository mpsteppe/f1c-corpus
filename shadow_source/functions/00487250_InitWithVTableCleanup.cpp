// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487250
// Canonical corpus name: InitWithVTableCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitWithVTableCleanup_00487250.c

void UnknownObject::InitWithVTableCleanup()
{
    // Writes the object's vtable pointer off_5AB968 into this+0, then delegates to the shared cleanup helper sub_485EB0 on this and returns its result. A vtable-reset-before-cleanup fragment; whether it runs on the constructor or destructor path is not established by this function alone.
    // ASSIGNMENT: Write vtable pointer off_5AB968 into the vtable slot at this+0 before any cleanup. [field:this:0x00000000, global:0x005AB968, source:raw, function:0x00487250, abi:lead]
    // CALL: Call the shared cleanup helper sub_485EB0 on this to continue initialization or teardown. [source:raw]
    // RETURN: Return the cleanup helper's result. [source:raw]

    // Conservative worker pseudocode:
    //   *this = &off_5AB968;
    //   return sub_485EB0(this);
    // UNRESOLVED: The exact class owning the off_5AB968 vtable and the semantics of sub_485EB0 (cleanup vs further initialization) are not evidenced by this packet.
    // UNRESOLVED: Whether this is a constructor or destructor fragment is ambiguous from this function alone; its callers include both construction and destruction paths.
}
