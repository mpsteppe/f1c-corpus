// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E330
// Canonical corpus name: CollisionResourceRelease80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionResourceRelease80_0044e330.c

void UnknownObject::CollisionResourceRelease80()
{
    // Single-call thunk that passes the function pointer stored in global nullsub_172 (0x0044E340) to BooleanToIntConversion at 0x00587B3E and returns its integer result. No fields, guards, or callers are evidenced. The raw source is a direct tail-delegation of one global to one callee.
    // CALL: Call BooleanToIntConversion at 0x00587B3E with the value of global nullsub_172 (0x0044E340) as its argument. [callee:0x00587B3E, global:0x0044E340, source:raw]
    // RETURN: Return the integer result produced by BooleanToIntConversion. [function:0x0044E330, source:raw]

    // Conservative worker pseudocode:
    //   return BooleanToIntConversion((int)nullsub_172);
    // UNRESOLVED: Purpose of the BooleanToIntConversion call is not established; the global nullsub_172 is a function pointer with no evidenced behavior here.
}
