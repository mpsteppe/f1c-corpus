// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00593446
// Canonical corpus name: sub_593446
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_593446_00593446.c

void UnknownObject::CppExceptionHandlerDispatch()
{
    // C++ exception handler dispatch routine in the CRT exception-handling path. Validates the scope-table magic at *a5 (must equal 0x19930520, otherwise SEHGuardedFunctionPointerCall runs as the fallback), then branches on the ExceptionFlags byte at a1+4 masked with 0x66. When the flag mask is non-zero and a5[1] is set with a6 zero, it dispatches through SEHAwareVirtualCallDispatchLoop(a2, a4, a5, -1). Otherwise, when a5[3] is set, it verifies the exception code at a1+0 equals 0xE06D7363 and the field at a1+0x14 exceeds 0x19930520, loads the handler function pointer from *(a1+28)+8, and calls it with the original eight arguments when non-null; otherwise it falls through to sub_5934E1 and returns 1. Called by ___CxxFrameHandler (0x0058A380), RenderArgsDispatch (0x0058A40A) and RenderStateSetupWithFlagChecks (0x0058A4E5).
    // GUARD: Validate the scope-table magic at *a5 against 429065504 (0x19930520); on mismatch invoke SEHGuardedFunctionPointerCall as the fallback handler. [callee:0x00593CFD, source:raw]
    // GUARD: Test the ExceptionFlags byte at a1+4 masked with 0x66; a non-zero result selects the SEH-aware dispatch path. [field:this:0x00000004, source:raw]
    // GUARD: On the flag path, when a5[1] is non-null and a6 is zero, dispatch through SEHAwareVirtualCallDispatchLoop(a2, a4, a5, -1). [callee:0x0059379B, source:raw]
    // GUARD: When the flag mask at a1+4 is zero, require a5[3] to be non-null before attempting direct C++ exception handling. [source:raw]
    // GUARD: On the a5[3] path, verify this is an MSVC C++ exception: the ExceptionCode at a1+0 equals 0xE06D7363 (guard 0) and the field at a1+0x14 exceeds 0x19930520 (guard 1). [guard:0, guard:1, field:this:0x00000000, field:this:0x00000014, source:raw]
    // CALL: Load the handler function pointer v8 from *(a1+28)+8 (the handler-table slot at field 0x1C plus offset 8) and, when non-null, invoke it with the original eight arguments and return its result. [field:this:0x0000001C, field:*(this+0x1C):0x00000008, source:raw]
    // CALL: When the handler pointer is null or the C++ exception checks fail, fall through to sub_5934E1 with the exception record first and the remaining arguments reordered. [callee:0x005934E1, source:raw]
    // RETURN: Return 1 as the default result when no handler path dispatched. [function:0x00593446, source:raw]

    // Conservative worker pseudocode:
    //   if (*a5 != 0x19930520) SEHGuardedFunctionPointerCall();
    //   if ((*(byte*)(a1+4) & 0x66) != 0) {
    //     if (a5[1] && !a6) SEHAwareVirtualCallDispatchLoop(a2, a4, a5, -1);
    //   } else if (a5[3]) {
    //     if (*(dword*)a1 == 0xE06D7363 && *(dword*)(a1+0x14) > 0x19930520) {
    //       v8 = *(fn**)(*(dword*)(a1+0x1C) + 8);
    //       if (v8) return v8(a1, a2, a3, a4, a5, a6, a7, a8);
    //     }
    //     sub_5934E1(a1, a2, a3, a4, a5, a8, a6, a7);
    //   }
    //   return 1;
    // UNRESOLVED: The layout of the scope table pointed to by a5 (magic at a5[0], flags at a5[1]/a5[3]) is inferred from the checks, not packet-confirmed.
    // UNRESOLVED: What the handler returned by the table call (a1..a8) is used for and the role of sub_5934E1 in cleanup are not established from this packet.
}
