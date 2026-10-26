// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00593CFD
// Canonical corpus name: SEHGuardedFunctionPointerCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SEHGuardedFunctionPointerCall_00593cfd.c

void UnknownObject::SEHGuardedFunctionPointerCall()
{
    // Installs a C++ SEH guard frame (__except_handler3, scope table stru_5B99A0, handler ScriptFrameProcessor) linked onto the current thread's TEB exception list, then conditionally calls optional global function pointer off_5E7960 with the first saved argument if it is non-null, and finally delegates to SEHWrapperDispatchingToHandlerFunction for disposal/return. Callers span binary-search, script, and virtual-call dispatch paths.
    // STATE_TRANSITION: Establish the SEH guard frame: scope table = stru_5B99A0, exception handler = ScriptFrameProcessor, and Next linked to the current TEB exception-list head. [global:0x0058895C, global:0x005B99A0, source:raw]
    // ASSIGNMENT: Save the incoming register arguments: exc_ptr = a1, and parameters a2/a3/a4 stored into the local v6 word array; old_esp is set to point at v6 for unwind reconstruction. [source:raw]
    // ASSIGNMENT: Initialize the SEH TryLevel to 0 (no active guarded section). [source:raw]
    // GUARD: Guard on off_5E7960 being non-null before calling through it. [global:0x005E7960]
    // STATE_TRANSITION: Enter the guarded section: TryLevel set to 1 around the function-pointer call. [source:raw]
    // CALL: Call the optional global function pointer off_5E7960 with the first saved argument v6[0]. [global:0x005E7960]
    // STATE_TRANSITION: Leave the guarded section: TryLevel reset to 0 after the call completes. [source:raw]
    // STATE_TRANSITION: Mark the frame as no longer protected: TryLevel set to -1 before final dispatch. [source:raw]
    // RETURN: Return the result of SEHWrapperDispatchingToHandlerFunction(a5). [callee:0x00593C9C]

    // Conservative worker pseudocode:
    //   int sub_593CFD(EXCEPTION_POINTERS *exc, int a2, int a3, int a4, int a5) {
    //     int v6[3] = { a3, a4, a2 };
    //     ms_exc.registration.ScopeTable = &stru_5B99A0;
    //     ms_exc.registration.ExceptionHandler = ScriptFrameProcessor;
    //     ms_exc.registration.Next = TEB.ExceptionList;
    //     ms_exc.exc_ptr = exc;
    //     ms_exc.old_esp = (DWORD)&v6;
    //     ms_exc.TryLevel = 0;
    //     if (off_5E7960) { ms_exc.TryLevel = 1; off_5E7960(v6[0]); ms_exc.TryLevel = 0; }
    //     ms_exc.TryLevel = -1;
    //     return SEHWrapperDispatchingToHandlerFunction(a5);
    //   }
    // UNRESOLVED: Purpose of off_5E7960 and the semantics of a5 are caller-determined; the raw source does not name them.
    // UNRESOLVED: TEB-relative byte globals (byte_FF00000000001695/...699/...69B) are compiler SEH bookkeeping writes during frame registration; exact meaning is not established here.
}
