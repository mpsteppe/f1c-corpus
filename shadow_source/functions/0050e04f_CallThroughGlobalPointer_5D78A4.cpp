// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E04F
// Canonical corpus name: IndirectJumpThunk
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndirectJumpThunk_0050e04f.c

void UnknownObject::CallThroughGlobalPointer_5D78A4()
{
    // Thunk (int-returning, no arguments) that reads the function pointer stored at the global dword_5D78A4 and tail-calls it, returning the callee's result unchanged. The global is a dispatch/indirect-call slot whose target is not resolvable from this packet.
    // CALL: Indirect call through the global function pointer dword_5D78A4 with no arguments; its return value is forwarded. [global:0x005D78A4, function:0x0050E04F, source:raw]
    // RETURN: Return the result of the indirect call unchanged. [function:0x0050E04F, source:raw]
    // CALL: Invoked by caller QuaternionSlERP (0x0050F258), a math routine that dispatches through this slot. [caller:0x0050F258, source:raw]

    // Conservative worker pseudocode:
    //   int Thunk_5D78A4() {
    //     return dword_5D78A4();
    //   }
    // UNRESOLVED: The resolved target of dword_5D78A4 is unknown; the packet identifies it only as a read-only global function pointer.
    // UNRESOLVED: The ABI name Indirect_Jump_Thunk implies the global holds a jump target established elsewhere, but no evidence resolves the stored value.
}
