// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059AAA3
// Canonical corpus name: ShortComputation_aaa3
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_aaa3_0059aaa3.c

void UnknownObject::booleanToIntFromPhysicsState()
{
    // Short straight-line wrapper that reads global PhysicsStateWrapper_aaaf, passes it cast to int into BooleanToIntConversion, and returns the conversion result.
    // CALL: Call BooleanToIntConversion, passing the int-cast value read from global PhysicsStateWrapper_aaaf as its argument [callee:0x00587B3E, global:0x0059AAAF]
    // RETURN: Return the result of the BooleanToIntConversion call [function:0x0059AAA3, source:raw]

    // Conservative worker pseudocode:
    //   int booleanToIntFromPhysicsState(void) {
    //       return BooleanToIntConversion((int)PhysicsStateWrapper_aaaf);
    //   }
    // UNRESOLVED: Semantics of global PhysicsStateWrapper_aaaf are unknown; the read value is only observed as an int argument to BooleanToIntConversion.
}
