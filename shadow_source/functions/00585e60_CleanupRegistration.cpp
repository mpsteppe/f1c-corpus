// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585E60
// Canonical corpus name: CleanupRegistration_5e60
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CleanupRegistration_5e60_00585e60.c

void UnknownObject::CleanupRegistration()
{
    // Thunk that reads the address of sub_585E70 and passes it to BooleanToIntConversion, returning the integer result.
    // CALL: Call BooleanToIntConversion with the address of the cleanup routine sub_585E70 (read from global 0x00585E70). [callee:0x00587B3E, global:0x00585E70, source:raw]
    // RETURN: Return the result of the BooleanToIntConversion call. [callee:0x00587B3E, source:raw]

    // Conservative worker pseudocode:
    //   return BooleanToIntConversion((int)sub_585E70);
    // UNRESOLVED: Purpose of sub_585E70 unknown; no analysis evidence for the referenced routine.
}
