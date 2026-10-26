// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005691D0
// Canonical corpus name: F_3x3RotationTensorMatrixTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3x3RotationTensorMatrixTransform_005691d0.c

void UnknownObject::ComputeInertiaTimesAngularVelocity()
{
    // Rigid-body inertia/rotation helper. Converts the Euler angles passed in a2 to a 3x3 rotation matrix via EulerAnglesTo33RotationMatrix, then transforms the inertia tensor to world space via F_3x3InertiaTensorTransform(this). Finally computes three dot products: each row of the transformed inertia tensor (this+0xEC/0xF4/0xFC, this+0x104/0x10C/0x114, this+0x11C/0x124/0x12C) dotted with the angular-velocity vector at this+0x94/0x9C/0xA4, storing the three scalar results as doubles at this+0x7C, this+0x84 and this+0x8C. Returns the F_3x3InertiaTensorTransform result. Called from seven physics/setup paths (PhysicsStateVectorConversion, sub_438F00, VehiclePhysicsInitializer, sub_43C250, FloatDoubleCoordinateTransform, VehiclePhysicsJointSystemLoader, sub_56F100).
    // CALL: EulerAnglesTo33RotationMatrix(a2) converts the Euler-angle argument into the object's 3x3 rotation matrix before the tensor transform. [callee:0x0056BD40, source:raw]
    // CALL: F_3x3InertiaTensorTransform(this) rotates the inertia tensor into world space; its return value is captured as the function result. [callee:0x005692A0, source:raw]
    // CALCULATION: Output X (double this+0x7C) = this+0xFC * this+0xA4 + this+0xF4 * this+0x9C + this+0xEC * this+0x94 (row 0 of the transformed inertia tensor dotted with the angular velocity). [field:this:0x0000007C, field:this:0x000000FC, field:this:0x000000A4, field:this:0x000000F4, field:this:0x0000009C, field:this:0x000000EC, field:this:0x00000094]
    // CALCULATION: Output Y (double this+0x84) = this+0x114 * this+0xA4 + this+0x10C * this+0x9C + this+0x104 * this+0x94 (row 1 of the transformed inertia tensor dotted with the angular velocity). [field:this:0x00000084, field:this:0x00000114, field:this:0x000000A4, field:this:0x0000010C, field:this:0x0000009C, field:this:0x00000104, field:this:0x00000094]
    // CALCULATION: Output Z (double this+0x8C) = this+0x12C * this+0xA4 + this+0x124 * this+0x9C + this+0x11C * this+0x94 (row 2 of the transformed inertia tensor dotted with the angular velocity). [field:this:0x0000008C, field:this:0x0000012C, field:this:0x000000A4, field:this:0x00000124, field:this:0x0000009C, field:this:0x0000011C, field:this:0x00000094]
    // RETURN: Return the F_3x3InertiaTensorTransform result unchanged. [callee:0x005692A0, source:raw]

    // Conservative worker pseudocode:
    //   EulerAnglesTo33RotationMatrix(a2);
    //   result = F_3x3InertiaTensorTransform(this);
    //   this[0x7C] = this[0xFC]*this[0xA4] + this[0xF4]*this[0x9C] + this[0xEC]*this[0x94];
    //   this[0x84] = this[0x114]*this[0xA4] + this[0x10C]*this[0x9C] + this[0x104]*this[0x94];
    //   this[0x8C] = this[0x12C]*this[0xA4] + this[0x124]*this[0x9C] + this[0x11C]*this[0x94];
    //   return result;
    // UNRESOLVED: All tensor/velocity accesses are 8-byte doubles, so each enumerated offset is the low dword of a double pair spanning the next four bytes; the high dwords are not individually enumerated in the packet field list.
    // UNRESOLVED: The naming of the output (torque vs force) and the exact physical meaning of a2's Euler angles are DERIVED from the fills, not proven by the .c.
}
