// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00475570
// Canonical corpus name: ConditionalChain
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalChain_00475570.c

void UnknownObject::ConditionalNetworkUiRefresh()
{
    // Calls a conditional network-state function with the module-manager global dword_7CD25C, then, if a short computation reports a state change, invokes sub_475150(this) to refresh the UI network list. Always returns 0.
    // CALL: Call ConditionalFunctionCall passing the module-manager global dword_7CD25C as its argument. [callee:0x00461F70, global:0x007CD25C]
    // GUARD: Guard: call sub_475150(this) only when ShortComputation_2140() returns non-zero. [callee:0x00462140, callee:0x00475150]
    // CALL: Call sub_475150(this) to refresh the UI network browser list when the state-change check passes. [callee:0x00475150]
    // RETURN: Return 0 unconditionally regardless of whether the refresh was invoked. [source:raw]

    // Conservative worker pseudocode:
    //   int ConditionalChain(void* this) {
    //     ConditionalFunctionCall(dword_7CD25C);
    //     if (ShortComputation_2140()) sub_475150(this);
    //     return 0;
    //   }
    // UNRESOLVED: Semantics of ShortComputation_2140 (state-change probe) not determinable from this packet.
    // UNRESOLVED: Identity of the object backing this and the role of dword_7CD25C are unknown; it is read-only here.
}
