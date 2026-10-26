// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047ABB0
// Canonical corpus name: Return0Stub
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Return0Stub_0047abb0.c

void UnknownObject::Return0Stub()
{
    // Parameterless stub that always returns integer constant 0. Dispatched to from five flag-related call sites (FlagSetInit, CallFlagSet, DeferredDeactivation, FlagCheckWithConditionalPathDispatch, TextureFlagTestWithDispatch) as a constant-zero result path; the stub body performs no state changes and reads nothing.
    // RETURN: Return the integer constant 0 unconditionally; no arguments are consumed and no memory is read or written. [source:raw, function:0x0047ABB0]
    // CALL: Called by FlagSetInit (0x00479EB0) as a constant-zero result provider during flag-set initialization. [caller:0x00479EB0, source:raw]
    // CALL: Called by CallFlagSet (0x00479ED0) as a constant-zero result provider during flag-set dispatch. [caller:0x00479ED0, source:raw]
    // CALL: Called by DeferredDeactivation (0x0052E320) as a constant-zero result provider in a deferred deactivation path. [caller:0x0052E320, source:raw]
    // CALL: Called by FlagCheckWithConditionalPathDispatch (0x005575F0) as a constant-zero result provider in a flag-check dispatch path. [caller:0x005575F0, source:raw]
    // CALL: Called by TextureFlagTestWithDispatch (0x00557630) as a constant-zero result provider in a texture-flag dispatch path. [caller:0x00557630, source:raw]

    // Conservative worker pseudocode:
    //   int sub_47ABB0(void) {
    //     return 0;
    //   }
    // UNRESOLVED: Why five distinct flag/dispatch call sites share this single zero-return stub instead of inlining the constant is unknown.
    // UNRESOLVED: The shared state (if any) that the constant-zero result stands for in each caller is unknown.
}
