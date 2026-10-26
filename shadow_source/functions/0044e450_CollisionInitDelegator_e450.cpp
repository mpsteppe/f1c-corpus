// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E450
// Canonical corpus name: CollisionInitDelegator_e450
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionInitDelegator_e450_0044e450.c

void UnknownObject::CollisionInitDelegator_e450()
{
    // Single-call thunk that passes the function pointer stored in global nullsub_175 (0x0044E460) to BooleanToIntConversion at 0x00587B3E and returns its integer result. No fields, guards, or callers are evidenced. The raw source is a direct tail-delegation of one global to one callee.
    // CALL: Call BooleanToIntConversion at 0x00587B3E with the value of global nullsub_175 (0x0044E460) as its argument. [callee:0x00587B3E, global:0x0044E460, source:raw]
    // RETURN: Return the integer result produced by BooleanToIntConversion. [function:0x0044E450, source:raw]

    // Conservative worker pseudocode:
    //   return BooleanToIntConversion((int)nullsub_175);
    // UNRESOLVED: Purpose of the BooleanToIntConversion call is not established; the global nullsub_175 is a function pointer with no evidenced behavior here.
}
