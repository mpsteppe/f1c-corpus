// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00593C9C
// Canonical corpus name: SEHWrapperDispatchingToHandlerFunction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SEHWrapperDispatchingToHandlerFunction_00593c9c.c

void UnknownObject::SEHWrapperDispatchingToHandlerFunction()
{
    // Dispatch wrapper for a registered CRT-style termination handler and a fixed cleanup sequence. If the TLS slot-24 entry from TLSValueRetrievalWithInit is non-null, the registered handler is invoked through the slot. Then a fixed cleanup sequence runs (sub_5932F3(0xA), sub_597388(22), sub_589CB5(3)) and the function returns the result of sub_597388 with the passed parameter.
    // GUARD: Check whether TLSValueRetrievalWithInit() slot 24 is non-null; the registered handler is invoked only when it is set. [callee:0x0058E0C7, source:raw]
    // CALL: Invoke the registered termination/cleanup handler stored at TLS slot 24 through the pointer read from TLSValueRetrievalWithInit(). [callee:0x0058E0C7, source:raw]
    // CALL: Run cleanup step sub_5932F3 with immediate parameter 0xA. [source:raw]
    // CALL: Run cleanup step sub_597388 with immediate parameter 22. [source:raw]
    // CALL: Run cleanup step sub_589CB5 with immediate parameter 3. [source:raw]
    // CALL: Run final step sub_597388 with the function's own parameter a1. [source:raw]
    // RETURN: Return the result of sub_597388(a1). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_593C9C(int a1) {
    //     if (TLSValueRetrievalWithInit()[24]) {
    //       ((void(*)(void))TLSValueRetrievalWithInit()[24])();
    //     }
    //     sub_5932F3(0xA);
    //     sub_597388(22);
    //     sub_589CB5(3);
    //     return sub_597388(a1);
    //   }
    // UNRESOLVED: Purpose of each fixed cleanup call (sub_5932F3, sub_597388, sub_589CB5) is not grounded beyond the raw source sequence.
    // UNRESOLVED: The exact type and semantics of the TLS slot-24 handler are unknown.
    // UNRESOLVED: Global-side references reported by static analysis (ScriptFrameProcessor 0x0058895C, stru_5B9988 0x005B9988, and the TEB-range bytes 0xFF00000000001695/0xFF00000000001699/0xFF0000000000169B) are not visible in the raw source body and remain unplaced.
}
