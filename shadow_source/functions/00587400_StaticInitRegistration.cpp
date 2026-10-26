// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587400
// Canonical corpus name: StaticInitRegistration_7400
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StaticInitRegistration_7400_00587400.c

void UnknownObject::StaticInitRegistration()
{
    // Thunk that reads the address of sub_587410 and passes it to BooleanToIntConversion, returning the integer result.
    // CALL: Call BooleanToIntConversion with the address of the static-init routine sub_587410 (read from global 0x00587410). [callee:0x00587B3E, global:0x00587410, source:raw]
    // RETURN: Return the result of the BooleanToIntConversion call. [callee:0x00587B3E, source:raw]

    // Conservative worker pseudocode:
    //   return BooleanToIntConversion((int)sub_587410);
    // UNRESOLVED: Purpose of sub_587410 unknown; no analysis evidence for the referenced routine.
}
