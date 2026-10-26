// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E0F0
// Canonical corpus name: CollisionStaticDataRegistration_e0f0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionStaticDataRegistration_e0f0_0044e0f0.c

void UnknownObject::CollisionStaticDataRegistration()
{
    // Trivial registration stub in the vehicle/collision subsystem. Reads the function pointer stored at global 0x0044E100 (nullsub_166), feeds its address into BooleanToIntConversion (0x00587B3E) and returns the converted result. No guard, field access or state change. The identity and purpose of the static-data callback at 0x0044E100 are not established by this packet.
    // CALL: Load nullsub_166 (function pointer at 0x0044E100) and pass its address to BooleanToIntConversion (0x00587B3E) [callee:0x00587B3E, global:0x0044E100, source:raw]
    // RETURN: Return the int conversion result of the BooleanToIntConversion call [callee:0x00587B3E, function:0x0044E0F0, source:raw]

    // Conservative worker pseudocode:
    //   return BooleanToIntConversion((int)nullsub_166);
    // UNRESOLVED: nullsub_166 at 0x0044E100 is a null stub; whether it is a registration table slot or a degenerate function pointer is unverified
    // UNRESOLVED: Why the function converts a callback address to an int and returns it (rather than registering it) is not explained by this packet
}
