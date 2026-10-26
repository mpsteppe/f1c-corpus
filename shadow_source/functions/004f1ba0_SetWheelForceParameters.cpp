// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F1BA0
// Canonical corpus name: WheelForceParameterSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelForceParameterSet_004f1ba0.c

void UnknownObject::SetWheelForceParameters()
{
    // Conditional wheel force/torque parameter setter. If enable flag this+0x32BC is non-zero, stores the four float parameters a2..a5 into wheel-force struct fields (this+0x3664, +0x375C, +0x3854, +0x394C). Otherwise bypasses storage and directly applies a2..a5 as force/torque to a rigid body via ForceTorqueApplicationToRigidBodyWithInertiaTens, passing the dbl_7C7428 scalar as the inertia-tensor argument. Called from PitStopProgress during pit-stop wheel operations.
    // GUARD: Branch on enable flag this+0x32BC: non-zero selects field-storage path, zero selects direct-apply path. [field:this:0x000032BC, source:raw]
    // ASSIGNMENT: Store parameter a2 into wheel-force field this+0x3664. [field:this:0x00003664, source:raw]
    // ASSIGNMENT: Store parameter a3 into wheel-force field this+0x375C. [field:this:0x0000375C, source:raw]
    // ASSIGNMENT: Store parameter a4 into wheel-force field this+0x3854. [field:this:0x00003854, source:raw]
    // ASSIGNMENT: Store parameter a5 into wheel-force field this+0x394C. [field:this:0x0000394C, source:raw]
    // CALL: Direct-apply path: call ForceTorqueApplicationToRigidBodyWithInertiaTens with global dbl_7C7428 and parameters a2..a5. [global:0x007C7428, source:raw]

    // Conservative worker pseudocode:
    //   if (this->enableFlag != 0) {
    //       this->wheelForce1 = a2;
    //       this->wheelForce2 = a3;
    //       this->wheelForce3 = a4;
    //       this->wheelForce4 = a5;
    //   } else {
    //       ForceTorqueApplicationToRigidBodyWithInertiaTens(&dbl_7C7428, a2, a3, a4, a5);
    //   }
    // UNRESOLVED: dbl_7C7428 is the inertia-tensor argument to the direct-apply helper; its exact meaning (single inertia value vs struct base) is unconfirmed.
    // UNRESOLVED: The four fields at +0x3664/+0x375C/+0x3854/+0x394C are recalculated every frame elsewhere, so stored values are transient (persistence verdict: recalced).
    // UNRESOLVED: Callee identity of the helper is provided only by name in existing analysis; no callee address evidence is in the packet.
}
