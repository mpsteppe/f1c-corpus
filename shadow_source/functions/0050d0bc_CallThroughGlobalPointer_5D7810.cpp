// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050D0BC
// Canonical corpus name: ThunkToFUN0050d0afViaGlobalPointer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToFUN0050d0afViaGlobalPointer_0050d0bc.c

void UnknownObject::CallThroughGlobalPointer_5D7810()
{
    // Thunk (int-returning, no arguments) that reads the function pointer stored at the global off_5D7810 and tail-calls it, returning the callee's result unchanged. The global is a dispatch/indirect-call slot whose target is not resolvable from this packet.
    // CALL: Indirect call through the global function pointer off_5D7810 with no arguments; its return value is forwarded. [global:0x005D7810, function:0x0050D0BC, source:raw]
    // RETURN: Return the result of the indirect call unchanged. [function:0x0050D0BC, source:raw]
    // CALL: Invoked by caller sub_50EB73 (0x0050EB73), which drives this dispatch slot. [caller:0x0050EB73, source:raw]

    // Conservative worker pseudocode:
    //   int Thunk_5D7810() {
    //     return off_5D7810();
    //   }
    // UNRESOLVED: The resolved target of off_5D7810 is unknown; the packet identifies it only as a read-only global function pointer.
    // UNRESOLVED: ABI name Thunk_to_FUN_0050d0af_via_Global_Pointer implies the intended target is FUN_0050d0af, but no evidence in the packet confirms the value stored in the global.
}
