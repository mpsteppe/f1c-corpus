// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D190
// Canonical corpus name: CollisionStaticDataRegistration_d190
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionStaticDataRegistration_d190_0044d190.c

void UnknownObject::CollisionStaticDataRegistration()
{
    // Registration thunk in the collision subsystem: reads the nullsub_64 stub pointer (global at 0x0044D1A0), casts it to int and forwards it to BooleanToIntConversion (0x00587B3E), returning the conversion result. Because the pointer is a non-null placeholder stub, the function reports a non-zero (registered) status. Owner and exact registration contract are unknown.
    // ASSIGNMENT: Load the nullsub_64 stub pointer from global 0x0044D1A0 and cast it to int as the argument to the conversion helper. [global:0x0044D1A0, source:raw]
    // CALL: Call BooleanToIntConversion (0x00587B3E) with the cast nullsub_64 pointer and produce the boolean-converted result. [callee:0x00587B3E, source:raw]
    // RETURN: Return the BooleanToIntConversion result directly; the function is a straight-line wrapper with no local state. [function:0x0044D190, source:raw]

    // Conservative worker pseudocode:
    //   int CollisionStaticDataRegistration() {
    //     return BooleanToIntConversion((int)nullsub_64);
    //   }
    // UNRESOLVED: BooleanToIntConversion (0x00587B3E) is only identified by name; the exact non-zero to true mapping is inferred, not proven by this packet.
    // UNRESOLVED: nullsub_64 is a no-op placeholder stub; what static collision data registration it represents is implied only by the ABI lead name.
    // UNRESOLVED: Owner and the registration contract this thunk participates in are unknown.
}
