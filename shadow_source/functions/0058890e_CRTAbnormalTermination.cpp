// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058890E
// Canonical corpus name: CRTAbnormalTermination
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CRTAbnormalTermination_0058890e.c

void UnknownObject::CRTAbnormalTermination()
{
    // CRT-style abnormal-termination probe. Reads the current thread's SEH registration list head from the TEB, and only when the head registration's handler matches the FlagCheckHandler global does it report whether the second registration record links back into the handler's saved parameter block. Defaults to 0 (no abnormal termination) in all other cases. Called from SEHWrapperAroundCRTFunctionCall.
    // ASSIGNMENT: Initialize result to 0, the default false/negative answer. [source:raw]
    // ASSIGNMENT: Read the SEH exception list head from NtCurrentTeb()->NtTib.ExceptionList. [source:raw]
    // GUARD: If the head registration's Handler is not the FlagCheckHandler global, fall through and return the default result 0. [source:raw, global:0x00588884]
    // CALCULATION: When the handler matches, return whether the second registration record's Next field equals the dword read at index 3 of the handler's saved parameter block. [source:raw]
    // RETURN: Return result (0) on the non-matching-handler path. [source:raw]

    // Conservative worker pseudocode:
    //   BOOL sub_58890E() {
    //     BOOL result = 0;
    //     _EXCEPTION_REGISTRATION_RECORD *ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
    //     if ((int (__cdecl *)(int, int, int, _DWORD *))ExceptionList->Handler == FlagCheckHandler)
    //       return ExceptionList[1].Next == (_EXCEPTION_REGISTRATION_RECORD *)*((_DWORD *)ExceptionList[1].Handler + 3);
    //     return result;
    //   }
    // UNRESOLVED: Exact layout and meaning of the exception registration records and of the FlagCheckHandler parameter block (CRT _except_handler3 convention) is not established here.
    // UNRESOLVED: Identity of the FlagCheckHandler global and how it is installed is outside this function's scope.
}
