// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A2A6
// Canonical corpus name: CRTAmsgExit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CRTAmsgExit_0058a2a6.c

void UnknownObject::CRTAmsgExit()
{
    // C runtime error-exit handler matching the CRT _amsg_exit pattern (ABI name CRT___amsg_exit). If the flag dword_8D3EBC equals 1 it calls sub_5932BA (display of the error/assertion dialog), then calls sub_5932F3 with the incoming error code NumberOfBytesWritten, and finally calls the registered exit-function pointer off_5E65B0 with the argument 0xFF, returning its result. Called by CRT stubs for allocation failures and runtime errors (MemoryAllocationStub, CriticalSectionLazyInitEnter, TLSValueRetrievalWithInit, sub_592AF4, sub_592BAD, sub_592F2C, AmsgExitRuntimeError, NullTerminatedIntArrayCopyWithAlloc).
    // GUARD: If dword_8D3EBC == 1, call sub_5932BA to display the error/assertion dialog. [global:0x008D3EBC, callee:0x005932BA, source:raw]
    // CALL: Call sub_5932F3 with the incoming NumberOfBytesWritten to process the error/exit code. [callee:0x005932F3, source:raw]
    // CALL: Call the registered exit function pointer off_5E65B0 with argument 0xFF and return its result. [global:0x005E65B0, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_8D3EBC == 1) sub_5932BA();
    //   sub_5932F3(NumberOfBytesWritten);
    //   return off_5E65B0(0xFF);
    // UNRESOLVED: sub_589CB5 appears in the fact table as a callee but is not called anywhere in the raw source body; its relationship is unclear.
    // UNRESOLVED: The identity of the function pointer off_5E65B0 and the exact meaning of dword_8D3EBC are DERIVED from existing analysis only; the packet carries no symbol metadata.
    // UNRESOLVED: Semantics of the 0xFF argument passed to the exit function are not established beyond the literal.
}
