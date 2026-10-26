// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E0D3
// Canonical corpus name: IndirectJumpThunk_e0d3
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndirectJumpThunk_e0d3_0050e0d3.c

void UnknownObject::IndirectCallThunk()
{
    // Thunk that reads the function pointer stored in the global dword_5D78A8 and calls it indirectly, returning whatever the target produced. No static callee exists because the target is resolved at runtime through the global. Called by QuaternionSlERP (0x0050F258).
    // CALL: Reads the call target stored at global dword_5D78A8 and invokes it indirectly; the callee is resolved at runtime, matching the legacy ABI label Indirect_jump_through_DAT_005d78a8. [abi:lead, global:0x005D78A8, source:raw]
    // RETURN: Returns the value produced by the indirect call as the thunk's own result. [source:raw]
    // CALL: Reached from QuaternionSlERP (0x0050F258) as an indirect dispatch site within that caller. [caller:0x0050F258, source:raw]

    // Conservative worker pseudocode:
    //   int IndirectCallThunk(void) {
    //     return ((int (__stdcall *)(void))dword_5D78A8)();
    //   }
    // UNRESOLVED: The concrete function the global dword_5D78A8 points to is unknown; no static callee and no prototype are recorded for it.
    // UNRESOLVED: Calling convention of the target is not evidenced (packet prototype is null); __stdcall above is assumed for illustration only.
    // UNRESOLVED: Why QuaternionSlERP dispatches through a runtime pointer (vtable-style override, plugin slot, or data-driven selection) is not established.
}
