// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A4E5
// Canonical corpus name: RenderStateSetupWithFlagChecks
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RenderStateSetupWithFlagChecks_0058a4e5.c

void UnknownObject::SehUnwindDispatcher()
{
    // Exception-frame dispatch helper for a structured-exception handler. Inspects ExceptionRecord->ExceptionFlags for the unwinding bitmask 0x66; on an unwind pass it sets TargetFrame[9] to 1 and returns 1 (continue unwind). On the normal path it invokes the per-frame cleanup handler sub_593446, then SEHUnwindHandler if TargetFrame[9] was not set by that handler, and finally calls the stored continuation at TargetFrame[6] and returns its result.
    // GUARD: Test ExceptionRecord->ExceptionFlags against the unwind bitmask 0x66; nonzero selects the unwind path. [source:raw]
    // ASSIGNMENT: On the unwind path set TargetFrame[9] to 1 to record that unwinding is in progress. [source:raw]
    // RETURN: Return 1 to continue the unwind pass. [source:raw]
    // CALL: On the normal path call sub_593446(ExceptionRecord, TargetFrame[3], a4, 0, TargetFrame[2], TargetFrame[4], TargetFrame[5], 1) as the per-frame handler. [callee:0x00593446, source:raw]
    // GUARD: If TargetFrame[9] is still 0 after the handler call, invoke SEHUnwindHandler(a1, TargetFrame, ExceptionRecord). [callee:0x0058A331, source:raw]
    // CALL: Call the continuation function pointer stored at TargetFrame[6]. [source:raw]
    // RETURN: Return the continuation function's result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_58A4E5(_EXCEPTION_REGISTRATION_RECORD **reg, PEXCEPTION_RECORD rec, _DWORD *frame, int a4) {
    //     if ((rec->ExceptionFlags & 0x66) != 0) { frame[9] = 1; return 1; }
    //     sub_593446(rec, frame[3], a4, 0, frame[2], frame[4], frame[5], 1);
    //     if (!frame[9]) SEHUnwindHandler(reg, frame, rec);
    //     return ((int (*)(void))frame[6])();
    //   }
    // UNRESOLVED: Layout of TargetFrame and the meaning of slots 2..9 is unproven; slot 9 acts as a state flag shared with sub_593446.
    // UNRESOLVED: Semantics of the 0x66 exception-flag bitmask and of argument a4 are not established.
    // UNRESOLVED: Legacy ABI name 'Render_State_Setup_with_Flag_Checks' conflicts with the raw source, which shows SEH frame dispatch; the source reading is preferred.
}
