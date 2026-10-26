// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057AE80
// Canonical corpus name: CallbackRegistrationForCleanupRoutine_ae80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CallbackRegistrationForCleanupRoutine_ae80_0057ae80.c

void UnknownObject::CallbackRegistrationForCleanupRoutine()
{
    // Thunk that reads the address of sub_57AE90 and passes it to BooleanToIntConversion, returning the integer result.
    // CALL: Call BooleanToIntConversion with the address of the cleanup routine sub_57AE90 (read from global 0x0057AE90). [callee:0x00587B3E, global:0x0057AE90, source:raw]
    // RETURN: Return the result of the BooleanToIntConversion call. [callee:0x00587B3E, source:raw]

    // Conservative worker pseudocode:
    //   return BooleanToIntConversion((int)sub_57AE90);
    // UNRESOLVED: Purpose of sub_57AE90 unknown; no analysis evidence for the referenced routine.
}
