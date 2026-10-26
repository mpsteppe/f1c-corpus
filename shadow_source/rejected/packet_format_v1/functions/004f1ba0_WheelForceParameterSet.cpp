// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F1BA0
// Canonical corpus name: WheelForceParameterSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelForceParameterSet_004f1ba0.c

void UnknownObject::WheelForceParameterSet()
{
    // Stores four wheel force/torque parameters into struct fields (0x3664/0x375C/0x3854/0x394C) when the enable flag at this+0x32BC is non-zero; otherwise applies them directly to the rigid body via ForceTorqueApplicationToRigidBodyWithInertiaTens using dbl_7C7428. Called during pit-stop wheel operations by PitStopProgress.
    // GUARD: Branch on enable flag at this+0x32BC: non-zero stores parameters into struct fields, zero applies them directly. [field:this:0x00012988]
    // ASSIGNMENT: Store a2 into wheel force parameter 1 at this+0x3664. [field:this:0x00013924]
    // ASSIGNMENT: Store a3 into wheel force parameter 2 at this+0x375C. [field:this:0x00014172]
    // ASSIGNMENT: Store a4 into wheel force parameter 3 at this+0x3854. [field:this:0x00014420]
    // ASSIGNMENT: Store a5 into wheel force parameter 4 at this+0x394C. [field:this:0x00014668]
    // CALL: Apply force/torque parameters directly to the rigid body via ForceTorqueApplicationToRigidBodyWithInertiaTens(&dbl_7C7428, a2, a3, a4, a5) when the enable flag is zero. [global:0x007C7428, function:0x004F1BA0]

    // Conservative worker pseudocode:
    //   if (enable_flag_at_0x32BC) {
    //     wheel_force_1 = a2;
    //     wheel_force_2 = a3;
    //     wheel_force_3 = a4;
    //     wheel_force_4 = a5;
    //   } else {
    //     ForceTorqueApplicationToRigidBodyWithInertiaTens(&dbl_7C7428, a2, a3, a4, a5);
    //   }
    // UNRESOLVED: caller is context reference, not used in reconstruction
    // UNRESOLVED: force/torque units and sign conventions not derivable from packet
}
