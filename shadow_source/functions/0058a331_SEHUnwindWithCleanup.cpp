// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A331
// Canonical corpus name: SEHUnwindHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SEHUnwindHandler_0058a331.c

void UnknownObject::SEHUnwindWithCleanup()
{
    // SEH unwind handler (__userpurge, a1@ebx, eax result): calls RtlUnwind to a known landing pad (loc_58A359), clears the UNWIND bit (0x02) from ExceptionRecord->ExceptionFlags, then stores the current NtTib.ExceptionList into the caller's exception-registration pointer and returns it. Standard CRT-style SEH unwind-with-cleanup helper invoked by rendering dispatch paths.
    // CALL: Invoke RtlUnwind with TargetFrame, landing pad loc_58A359, ExceptionRecord and NULL ExceptionFrame to unwind stack frames up to the target frame. [callee:0x0059B24A, global:0x0058A359, source:raw]
    // ASSIGNMENT: Clear the UNWIND bit: AND ExceptionRecord->ExceptionFlags with 0xFD (mask off bit 0x02) and store back. [function:0x0058A331, source:raw]
    // ASSIGNMENT: Read the current NtTib.ExceptionList from the calling thread's TEB and store it into the caller-provided exception registration record pointer (a1, this:0x0), repointing the handler chain. [field:this:0x00000000, source:raw]
    // RETURN: Return the updated exception-list pointer as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   RtlUnwind(TargetFrame, &loc_58A359, ExceptionRecord, NULL);
    //   ExceptionRecord->ExceptionFlags &= 0xFD;
    //   *a1 = NtCurrentTeb()->NtTib.ExceptionList;
    //   return *a1;
    // UNRESOLVED: ExceptionRecord fields (ExceptionFlags) are not exposed as packet fields; the flag clear is source-backed only.
    // UNRESOLVED: Frame path is NOT_FOUND; call frequency from tick root is unknown.
}
