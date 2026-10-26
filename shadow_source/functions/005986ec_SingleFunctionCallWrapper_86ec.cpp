// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005986EC
// Canonical corpus name: SingleFunctionCallWrapper_86ec
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleFunctionCallWrapper_86ec_005986ec.c

void UnknownObject::SingleFunctionCallWrapper_86ec()
{
    // Thin delegation wrapper: passes the address of the global PhysicsStateWrapper as the argument to BooleanToIntConversion and returns the conversion result directly.
    // CALL: Call BooleanToIntConversion with the address of the global PhysicsStateWrapper (read at 0x005986F8) as its single argument. [callee:0x00587B3E, global:0x005986F8, source:raw]
    // RETURN: Return the integer result produced by BooleanToIntConversion. [source:raw, function:0x005986EC]

    // Conservative worker pseudocode:
    //   int SingleFunctionCallWrapper_86ec() {
    //     return BooleanToIntConversion((int)PhysicsStateWrapper);
    //   }
    // UNRESOLVED: Semantic purpose of BooleanToIntConversion and of the PhysicsStateWrapper global is not established by this packet.
    // UNRESOLVED: No callers are recorded, so the context that invokes this wrapper is unknown.
}
