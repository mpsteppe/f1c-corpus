// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005118C1
// Canonical corpus name: TwoStepDelegation
// Owner: CallbackDispatchLayer [DERIVED]
// Raw source: functions/TwoStepDelegation_005118c1.c

void CallbackDispatchLayer::dispatchTwoStep()
{
    // Two-step delegation wrapper. First calls sub_5117C8(a1, a2), then calls CallbackDispatch(a1, &stack_buffer) and returns the resulting function pointer. The 80-byte stack buffer v3 is used only as an output area for the dispatch call; its contents and the meaning of a1/a2 are unknown.
    // CALL: Call sub_5117C8(a1, a2) — first step of the two-step delegation, consuming the caller-supplied arguments. [callee:0x005117C8]
    // CALL: Call CallbackDispatch(a1, &v3) with a pointer to an 80-byte stack buffer as the second argument; its return value becomes the returned function pointer. [callee:0x00511887]
    // RETURN: Return the function pointer produced by CallbackDispatch. [function:0x005118C1, source:raw]

    // Conservative worker pseudocode:
    //   two_step_delegation(a1, a2)
    //       sub_5117C8(a1, a2);
    //       byte v3[80];
    //       return (function_pointer)CallbackDispatch(a1, &v3);
    // UNRESOLVED: Purpose and contents of the 80-byte stack buffer v3 passed to CallbackDispatch.
    // UNRESOLVED: Meaning of arguments a1 and a2.
    // UNRESOLVED: What the returned function pointer is used for; semantics of the produced delegate.
}
