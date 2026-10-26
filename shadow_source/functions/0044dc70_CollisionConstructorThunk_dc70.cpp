// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044DC70
// Canonical corpus name: CollisionConstructorThunk_dc70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionConstructorThunk_dc70_0044dc70.c

void UnknownObject::CollisionConstructorThunk_dc70()
{
    // Thin forwarder: takes the address of the null subroutine thunk at 0x0044DC80, casts it to int, and passes it to BooleanToIntConversion, returning the int result. No fields, globals other than the thunk, or guards are touched.
    // CALL: Calls BooleanToIntConversion, passing the address of global nullsub_154 cast to int as the argument. [callee:0x00587B3E, global:0x0044DC80]
    // RETURN: Returns the int result produced by BooleanToIntConversion. [callee:0x00587B3E, source:raw]

    // Conservative worker pseudocode:
    //   int CollisionConstructorThunk_dc70() {
    //       return BooleanToIntConversion((int)&nullsub_154);
    //   }
    // UNRESOLVED: Why the address of nullsub_154 (a null subroutine thunk) is cast to int and handed to BooleanToIntConversion; likely a function-pointer-to-int conversion or placeholder forwarder whose semantic purpose is unknown.
}
