// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043EBD0
// Canonical corpus name: PhysicsForceScaleDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsForceScaleDispatch_0043ebd0.c

void UnknownObject::PhysicsForceScaleDispatch()
{
    // Force-split dispatch for a vehicle physics input: scales the incoming force a2 by 0.25 into SuspensionDamperForceAccumulation and by 0.75 into ClampedSpringIntegrator, distributing a single input between the damper and spring subsystems.
    // CALL: Dispatch the 0.25-scaled input to SuspensionDamperForceAccumulation on this. [callee:0x0043E890, source:raw]
    // CALL: Dispatch the 0.75-scaled input to ClampedSpringIntegrator on v2. [callee:0x0043E980, source:raw]
    // CALCULATION: Scale the input a2 by 0.25 for the damper path and by 0.75 for the spring path. [source:raw]
    // CALCULATION: Read the global scale constants dbl_59EA60 and dbl_59EB50 referenced by this dispatch; the exact mapping to the 0.25/0.75 factors is not established here. [global:0x0059EA60, global:0x0059EB50, source:raw]
    // CALL: Called by FloatParameterForwarder to feed a float parameter into the suspension force path. [caller:0x004ED1C0, source:raw]

    // Conservative worker pseudocode:
    //   void sub_43EBD0(double *this, double a2) {
    //     SuspensionDamperForceAccumulation(this, a2 * 0.25);
    //     ClampedSpringIntegrator(v2, a2 * 0.75);
    //   }
    // UNRESOLVED: The link between the global doubles dbl_59EA60 / dbl_59EB50 and the literal scale factors 0.25 / 0.75 is inferred; the raw source shows the literals directly.
    // UNRESOLVED: In the raw source v2 is an uninitialized ecx register passed as the spring-integrator this pointer, so the spring owner object is not established.
}
