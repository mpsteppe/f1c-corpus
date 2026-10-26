// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056A240
// Canonical corpus name: InertialTensorVectorTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InertialTensorVectorTransform_0056a240.c

void UnknownObject::PreConstraintVelocityUpdate()
{
    // Vehicle body velocity update executed ahead of the constraint pass (per-frame tick, called by sub_56ECF0). Computes the gyroscopic torque as the cross product of the body angular velocity (this+0x7C/+0x84/+0x8C) and angular momentum (this+0x94/+0x9C/+0xA4), subtracts it from the applied torque (this+0x14C/+0x154/+0x15C) to obtain the net torque, multiplies the net torque by the world-space inverse inertia matrix (this+0xEC through this+0x12C) to get the angular velocity delta, and derives the linear velocity as the inverse mass (this+0xB4) times the linear momentum (this+0x134/+0x13C/+0x144). The two velocity vectors are then passed to the constraint preparation helpers sub_56A390, sub_56A5D0, sub_56A840, sub_56AA60 and sub_56B5D0, and the function returns the result of ConstraintStiffnessMatrixAssembly(this).
    // CALCULATION: Cross product gyro = omega x L: reads angular velocity (this+0x7C/+0x84/+0x8C) and angular momentum (this+0x94/+0x9C/+0xA4) and computes the three gyroscopic torque components v2/v3/v9 as paired products and differences. [field:this:0x0000007C, field:this:0x00000084, field:this:0x0000008C, field:this:0x00000094, field:this:0x0000009C, field:this:0x000000A4, source:raw]
    // CALCULATION: Net torque = applied torque minus gyroscopic torque: subtracts the three gyroscopic components from the applied torque at this+0x14C/+0x154/+0x15C into v10[0]/v4/v5. [field:this:0x0000014C, field:this:0x00000154, field:this:0x0000015C, source:raw]
    // CALCULATION: Angular velocity delta: multiplies the net torque vector by the world-space inverse inertia matrix (rows at this+0xEC/+0xF4/+0xFC, +0x104/+0x10C/+0x114, +0x11C/+0x124/+0x12C) to produce the three angular velocity delta terms in v8/v9. [field:this:0x000000EC, field:this:0x000000F4, field:this:0x000000FC, field:this:0x00000104, field:this:0x0000010C, field:this:0x00000114, field:this:0x0000011C, field:this:0x00000124, field:this:0x0000012C, source:raw]
    // CALCULATION: Linear velocity from momentum: scales the linear momentum (this+0x134/+0x13C/+0x144) by the inverse mass at this+0xB4 to produce the three linear velocity components in v10. [field:this:0x000000B4, field:this:0x00000134, field:this:0x0000013C, field:this:0x00000144, source:raw]
    // CALL: sub_56A390(v8, v10): combines the angular velocity delta and linear velocity into constraint-space vectors. [callee:0x0056A390, source:raw]
    // CALL: sub_56A5D0(v8): processes/transforms the constraint velocity vectors. [callee:0x0056A5D0, source:raw]
    // CALL: sub_56A840(v8, v10): builds constraint-space velocity deltas from the angular and linear velocity terms. [callee:0x0056A840, source:raw]
    // CALL: sub_56AA60(this): computes body-local constraint data on the body object. [callee:0x0056AA60, source:raw]
    // CALL: sub_56B5D0(this): prepares joint constraint parameters on the body object. [callee:0x0056B5D0, source:raw]
    // RETURN: Returns ConstraintStiffnessMatrixAssembly(this): assembles the constraint stiffness matrix from the prepared data and returns its result. [callee:0x0056BAF0, source:raw]
    // CALL: Invoked by sub_56ECF0 (0x0056ECF0) as the pre-constraint velocity update on the frame path. [caller:0x0056ECF0, source:raw]

    // Conservative worker pseudocode:
    //   // gyro = cross(omega, L) using this+0x7C/+0x84/+0x8C and this+0x94/+0x9C/+0xA4
    //   // netTorque = appliedTorque(this+0x14C/+0x154/+0x15C) - gyro
    //   // angVelDelta = inverseInertiaWorld(this+0xEC..+0x12C) * netTorque
    //   // linVel = (this+0xB4) * momentum(this+0x134/+0x13C/+0x144)
    //   sub_56A390(angVelDelta, linVel);
    //   sub_56A5D0(angVelDelta);
    //   sub_56A840(angVelDelta, linVel);
    //   sub_56AA60(this);
    //   sub_56B5D0(this);
    //   return ConstraintStiffnessMatrixAssembly(this);
    // UNRESOLVED: The specific sub-functions (sub_56A390, sub_56A5D0, sub_56A840, sub_56AA60, sub_56B5D0) are only identified by address; their internal constraint math is not established by this packet.
    // UNRESOLVED: Field semantics (omega, momentum, inverse inertia, applied torque) follow the existing skeleton fill and the ABI name 'Inertial_Tensor_Vector_Transform' at DERIVED/LEGACY trust; the physical meaning of each offset is an interpretation, not independently proven.
}
