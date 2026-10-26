// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CD70
// Canonical corpus name: CollisionInitDelegator_cd70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionInitDelegator_cd70_0044cd70.c

void UnknownObject::CollisionInitDelegator_cd70()
{
    // Trivial thunk. Calls BooleanToIntConversion (0x00587B3E) with the address of the empty stub nullsub_51 (0x0044CD80) cast to int, and returns the int result. No arguments, branches, or fields. The 'vehicle' subsystem tag and the declared name are the only hints that this delegates collision initialization.
    // CALL: Call BooleanToIntConversion with the address of nullsub_51 cast to int. [callee:0x00587B3E, global:0x0044CD80, source:raw]
    // RETURN: Return the int result of the BooleanToIntConversion call. [function:0x0044CD70, source:raw]

    // Conservative worker pseudocode:
    //   return BooleanToIntConversion((int)nullsub_51);
    // UNRESOLVED: Why the address of an empty stub (nullsub_51) is passed to BooleanToIntConversion is unevidenced; the stub's role and the caller of this thunk are unknown.
    // UNRESOLVED: The declared name implies an initialization delegation, but no initialization behavior is evidenced by this packet.
}
