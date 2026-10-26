// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005972BD
// Canonical corpus name: sub_5972BD
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5972BD_005972bd.c

void UnknownObject::SEHExceptionFilterDispatch()
{
    // SEH exception filter. Dereferences a1 (EXCEPTION_POINTERS) to its exception record and tests the C++ exception signature: record code equal to 0xE06D7363, parameter[0] equal to 3, parameter[1] equal to 0x19930520. On a full match it dispatches to SEHWrapperDispatchingToHandlerFunction with a1. Otherwise, when the global handler pointer lpfn is non-null and passes CodePointerValidation, it invokes lpfn() and returns its result. Returns 0 when neither path runs.
    // CALCULATION: Load the exception record pointer from *a1, the EXCEPTION_POINTERS.ExceptionRecord field. [field:this:0x00000000, source:raw]
    // GUARD: Guard: exception record code field (v1[0], offset 0x0) equals 0xE06D7363, the C++ exception code. [guard:0, field:obj:0x00000000, source:raw]
    // GUARD: Guard: exception record parameter[0] (v1[4], offset 0x10) equals 3. [guard:1, field:obj:0x00000010, source:raw]
    // GUARD: Guard: exception record parameter[1] (v1[5], offset 0x14) equals 0x19930520. [guard:2, field:obj:0x00000014, source:raw]
    // CALL: When all three signature guards pass, dispatch to SEHWrapperDispatchingToHandlerFunction with a1 (named in raw source; no separate callee evidence ref exists for it). [source:raw]
    // GUARD: Fallback guard: the global handler pointer lpfn is non-null and CodePointerValidation(lpfn) succeeds. [global:0x008D41E4, source:raw]
    // CALL: CodePointerValidation validates that lpfn is a valid code address before it is called. [callee:0x00597359, source:raw]
    // CALL: Indirect call of the validated global handler lpfn with no arguments; its result becomes the function result. [global:0x008D41E4, source:raw]
    // RETURN: Return 0 when neither the SEH signature match nor a valid global-handler path is taken. [source:raw]

    // Conservative worker pseudocode:
    //   int SEHExceptionFilterDispatch(void* pointers) {
    //     void* rec = *(void**)pointers;
    //     if (*(int*)rec == 0xE06D7363 && ((int*)rec)[4] == 3 && ((int*)rec)[5] == 0x19930520)
    //       return SEHWrapperDispatchingToHandlerFunction((int)pointers);
    //     if (lpfn && CodePointerValidation(lpfn))
    //       return lpfn();
    //     return 0;
    //   }
    // UNRESOLVED: SEHWrapperDispatchingToHandlerFunction is named in the raw source but has no callee evidence ref in this packet, so its address and contract are unknown here
    // UNRESOLVED: The meaning of the global handler lpfn's return value and how the caller consumes the filter result are not documented in this packet
}
