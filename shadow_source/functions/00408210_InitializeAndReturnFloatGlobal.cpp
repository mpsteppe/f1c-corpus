// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00408210
// Canonical corpus name: DelegationWrapperToFUN00408280
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DelegationWrapperToFUN00408280_00408210.c

void UnknownObject::InitializeAndReturnFloatGlobal()
{
    // Initialization/teardown delegation wrapper: clears a slot inside the global block at algn_5EA4EC, invokes StructInitWithConditionalNotify, then returns the address of the adjacent global float flt_5EA4E8. The callee name suggests a struct-init routine that may conditionally notify, but the function identity is caller-supplied and not evidenced here.
    // ASSIGNMENT: Clear slot index 17 in the global block algn_5EA4EC by storing 0. [source:raw]
    // CALL: Invoke StructInitWithConditionalNotify to perform conditional struct initialization. [source:raw]
    // RETURN: Return the address of the global float flt_5EA4E8. [global:0x005EA4E8, source:raw]

    // Conservative worker pseudocode:
    //   float *sub_408210() {
    //     algn_5EA4EC[17] = 0;
    //     StructInitWithConditionalNotify();
    //     return &flt_5EA4E8;
    //   }
    // UNRESOLVED: StructInitWithConditionalNotify is absent from the packet callee evidence; its address and side effects are unknown.
    // UNRESOLVED: algn_5EA4EC is absent from the packet global evidence; the meaning of slot 17 and its relation to flt_5EA4E8 are unknown.
    // UNRESOLVED: Purpose of returning &flt_5EA4E8 (single float vs start of a float array) is unknown.
}
