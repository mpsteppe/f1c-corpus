// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050DF95
// Canonical corpus name: ThunkViaIndirectJump
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkViaIndirectJump_0050df95.c

void UnknownObject::ThunkViaIndirectJump()
{
    // Thunk on the AI subsystem path. It loads the function pointer stored in global off_5D7878 and calls it indirectly, returning whatever the callee produced. Its only caller is QuaternionSlERP.
    // CALL: Indirect call through the function pointer held in global off_5D7878 (0x005D7878). [global:0x005D7878]
    // RETURN: Return the value produced by the indirectly-called function. [source:raw]
    // UNRESOLVED: The concrete target of off_5D7878 is not resolved; the thunk dispatches to whatever the global currently points at.
}
