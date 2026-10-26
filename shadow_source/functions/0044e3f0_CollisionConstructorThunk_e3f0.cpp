// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E3F0
// Canonical corpus name: CollisionConstructorThunk_e3f0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionConstructorThunk_e3f0_0044e3f0.c

void UnknownObject::CollisionConstructorThunk_e3f0()
{
    // Single-call thunk that passes the function pointer stored in global nullsub_174 (0x0044E400) to BooleanToIntConversion at 0x00587B3E and returns its integer result. No fields, guards, or callers are evidenced. The raw source is a direct tail-delegation of one global to one callee.
    // CALL: Call BooleanToIntConversion at 0x00587B3E with the value of global nullsub_174 (0x0044E400) as its argument. [callee:0x00587B3E, global:0x0044E400, source:raw]
    // RETURN: Return the integer result produced by BooleanToIntConversion. [function:0x0044E3F0, source:raw]

    // Conservative worker pseudocode:
    //   return BooleanToIntConversion((int)nullsub_174);
    // UNRESOLVED: Purpose of the BooleanToIntConversion call is not established; the global nullsub_174 is a function pointer with no evidenced behavior here.
}
