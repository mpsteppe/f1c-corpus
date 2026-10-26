// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00569A20
// Canonical corpus name: ApplyImpulseToRigidBodyWithTorque
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ApplyImpulseToRigidBodyWithTorque_00569a20.c

void UnknownObject::ApplyImpulseToRigidBodyWithTorque()
{
    // Applies an impulse vector a3 to a rigid body at a world-space application point a2. The impulse is accumulated component-wise into the linear momentum fields at bytes 0x134, 0x13C and 0x144. The lever arm is computed as the difference between the application point and the body position read at bytes 0x4, 0xC and 0x14. The torque is formed as the cross product of the lever arm and the impulse and accumulated into the angular momentum fields at bytes 0x14C, 0x154 and 0x15C. Returns the impulse vector pointer a3. No branches, globals or calls.
    // ASSIGNMENT: Accumulate the impulse x into the linear momentum x field at byte 0x134. [field:this:0x00000134, source:raw]
    // ASSIGNMENT: Accumulate the impulse y into the linear momentum y field at byte 0x13C. [field:this:0x0000013C, source:raw]
    // ASSIGNMENT: Accumulate the impulse z into the linear momentum z field at byte 0x144. [field:this:0x00000144, source:raw]
    // CALCULATION: Compute the lever arm r = a2 - body position: v4 = a2[0] - position at 0x4, v5 = a2[1] - position at 0xC, v6 = a2[2] - position at 0x14. [field:this:0x00000004, field:this:0x0000000C, field:this:0x00000014, source:raw]
    // CALCULATION: Compute the intermediate cross-product terms used for the angular momentum accumulation: v8 = v6 * a3[0] - v4 * a3[2] and v7 = v4 * a3[1] - v5 * a3[0]. [source:raw]
    // ASSIGNMENT: Accumulate the torque x into the angular momentum x field at byte 0x14C: this+0x14C += v5 * a3[2] - v6 * a3[1]. [field:this:0x0000014C, source:raw]
    // ASSIGNMENT: Accumulate the torque y into the angular momentum y field at byte 0x154: this+0x154 += v8. [field:this:0x00000154, source:raw]
    // ASSIGNMENT: Accumulate the torque z into the angular momentum z field at byte 0x15C: this+0x15C += v7. [field:this:0x0000015C, source:raw]
    // RETURN: Return the impulse vector pointer a3. [source:raw]

    // Conservative worker pseudocode:
    //   double* ApplyImpulseToRigidBodyWithTorque(int this, double* a2, double* a3) {
    //       *(double*)(this + 308) += a3[0];   // linear momentum x, byte 0x134
    //       *(double*)(this + 316) += a3[1];   // linear momentum y, byte 0x13C
    //       *(double*)(this + 324) += a3[2];   // linear momentum z, byte 0x144
    //       v4 = a2[0] - *(double*)(this + 4); // lever arm x
    //       v5 = a2[1] - *(double*)(this + 12);// lever arm y
    //       v6 = a2[2] - *(double*)(this + 20);// lever arm z
    //       *(double*)(this + 332) += v5 * a3[2] - v6 * a3[1]; // angular momentum x, byte 0x14C
    //       *(double*)(this + 340) += v6 * a3[0] - v4 * a3[2]; // angular momentum y, byte 0x154
    //       *(double*)(this + 348) += v4 * a3[1] - v5 * a3[0]; // angular momentum z, byte 0x15C
    //       return a3;
    //   }
    // UNRESOLVED: The owner object identity (rigid body) is DERIVED from behavior and caller context; it is not established by packet evidence.
    // UNRESOLVED: The position fields at 0x4/0xC/0x14 and the momentum fields are named from the caller's collision-response context, not from packet-internal evidence.
    // UNRESOLVED: Whether the momentum fields represent instantaneous momentum or accumulated impulse for constraint iteration is not distinguishable from this packet alone.
}
