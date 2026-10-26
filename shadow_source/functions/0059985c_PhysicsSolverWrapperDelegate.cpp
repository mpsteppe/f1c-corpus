// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059985C
// Canonical corpus name: DelegationWithStaticArg_985c
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DelegationWithStaticArg_985c_0059985c.c

void UnknownObject::PhysicsSolverWrapperDelegate()
{
    // Trivial delegation thunk: reads the global PhysicsSolverWrapper and forwards its value as the integer argument to BooleanToIntConversion, returning the conversion result directly. No branches, no local state.
    // ASSIGNMENT: Load the global PhysicsSolverWrapper from 0x00599868 as the integer argument passed to the callee. [global:0x00599868]
    // CALL: Call BooleanToIntConversion with the loaded global value as its sole argument. [callee:0x00587B3E, source:raw]
    // RETURN: Return the result of BooleanToIntConversion unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int PhysicsSolverWrapperDelegate() {
    //     return BooleanToIntConversion((int)PhysicsSolverWrapper);
    //   }
    // UNRESOLVED: Semantic role of the global PhysicsSolverWrapper (value interpreted as a boolean by the callee) is caller-dependent and unknown here.
}
