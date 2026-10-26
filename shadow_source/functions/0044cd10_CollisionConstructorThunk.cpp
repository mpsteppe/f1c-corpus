// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CD10
// Canonical corpus name: CollisionConstructorThunk
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionConstructorThunk_0044cd10.c

void UnknownObject::CollisionConstructorThunk()
{
    // Trivial thunk. Calls BooleanToIntConversion (0x00587B3E) with the address of the empty stub nullsub_50 (0x0044CD20) cast to int, and returns the int result. No arguments, branches, or fields. The 'vehicle' subsystem tag and the declared name are the only hints that this wraps a collision object constructor.
    // CALL: Call BooleanToIntConversion with the address of nullsub_50 cast to int. [callee:0x00587B3E, global:0x0044CD20, source:raw]
    // RETURN: Return the int result of the BooleanToIntConversion call. [function:0x0044CD10, source:raw]

    // Conservative worker pseudocode:
    //   return BooleanToIntConversion((int)nullsub_50);
    // UNRESOLVED: Why the address of an empty stub (nullsub_50) is passed to BooleanToIntConversion is unevidenced; the stub's role and the caller of this thunk are unknown.
    // UNRESOLVED: The declared name implies a constructor delegation, but no constructor behavior is evidenced by this packet.
}
