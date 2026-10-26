// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00569C10
// Canonical corpus name: sub_569C10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_569C10_00569c10.c

void UnknownObject::IntegrateRigidBodyPositionAndAngularVelocity()
{
    // One rigid-body integration step on the vehicle physics tick. Advances linear position (this+4/+12/+20) with an a2-scaled velocity Euler step, staging copies of each previous state block (this+356, this+380, this+452, this+476, this+500, this+524), advances linear velocity (this+100/+108/+116) using the a2-scaled velocity factor this+180, scales the angular momentum into a vector, passes it to sub_56C020, advances angular momentum (this+148/+156/+164), runs F_3x3InertiaTensorTransform, and writes the inertia-transformed result back to angular velocity (this+124/+132/+140). Returns the integer result of the inertia transform.
    // ASSIGNMENT: Linear position X advance: v3 = a2 * this+100 + this+4, staging copy this+356 = this+4 (0x18 bytes) before committing this+4 = v3 [field:this:0x00000004, field:this:0x00000064, source:raw]
    // ASSIGNMENT: Linear position Y advance: v4 = a2 * this+108 + this+12, staging copy this+380 = this+28 (0x48 bytes) before committing this+12 = v4 [field:this:0x0000000C, field:this:0x0000006C, source:raw]
    // ASSIGNMENT: Linear position Z advance: v5 = a2 * this+116 + this+20, staging copy this+452 = this+100 (0x18 bytes) before committing this+20 = v5 [field:this:0x00000014, field:this:0x00000074, source:raw]
    // ASSIGNMENT: Linear velocity X advance: factor v6 = a2 * this+180; v7 = v6 * this+308 + this+100, staging copy this+476 = this+148 (0x18 bytes) before committing this+100 = v7 [field:this:0x000000B4, field:this:0x00000064, field:this:0x00000134, source:raw]
    // ASSIGNMENT: Linear velocity Y advance: v8 = v6 * this+316 + this+108, staging copy this+500 = this+308 (0x18 bytes) before committing this+108 = v8 [field:this:0x0000006C, field:this:0x0000013C, source:raw]
    // ASSIGNMENT: Linear velocity Z advance: v9 = v6 * this+324 + this+116, staging copy this+524 = this+332 (0x18 bytes) before committing this+116 = v9 [field:this:0x00000074, field:this:0x00000144, source:raw]
    // ASSIGNMENT: Angular momentum scaled into v11: v11[0] = a2 * this+124, v11[1] = a2 * this+132, v11[2] = a2 * this+140 [field:this:0x0000007C, field:this:0x00000084, field:this:0x0000008C, source:raw]
    // CALL: sub_56C020 invoked with the scaled angular-momentum vector v11 [callee:0x0056C020, source:raw]
    // ASSIGNMENT: Angular momentum advance: this+148 = a2 * this+332 + this+148; this+156 = a2 * this+340 + this+156; this+164 = a2 * this+348 + this+164 [field:this:0x00000094, field:this:0x0000009C, field:this:0x000000A4, field:this:0x0000014C, field:this:0x00000154, field:this:0x0000015C, source:raw]
    // CALL: F_3x3InertiaTensorTransform transforms the inertia tensor against the momentum state; its return value becomes the function result [callee:0x005692A0, source:raw]
    // ASSIGNMENT: Inertia-tensor result written back to angular velocity: this+124 = this+236 * this+148 + this+244 * this+156 + this+252 * this+164; this+132 = this+260 * this+148 + this+268 * this+156 + this+276 * this+164; this+140 = this+284 * this+148 + this+292 * this+156 + this+300 * this+164 [field:this:0x00000094, field:this:0x0000009C, field:this:0x000000A4, field:this:0x000000EC, field:this:0x000000F4, field:this:0x000000FC, field:this:0x00000104, field:this:0x0000010C, field:this:0x00000114, field:this:0x0000011C, field:this:0x00000124, field:this:0x0000012C, source:raw]
    // RETURN: Returns the integer result of F_3x3InertiaTensorTransform [callee:0x005692A0, source:raw]
    // CALL: Invoked per frame tick by VehiclePhysicsVelocityAngularVelocityIntegrator (00459AE0) and by IteratePhysicsBodiesCallUpdateFunction (0056F020) [caller:0x00459AE0, caller:0x0056F020, source:raw]

    // Conservative worker pseudocode:
    //   v3 = a2 * this+100 + this+4;  copy 24 bytes from this+4 to this+356;  this+4  = v3;
    //   v4 = a2 * this+108 + this+12; copy 72 bytes from this+28 to this+380; this+12 = v4;
    //   v5 = a2 * this+116 + this+20; copy 24 bytes from this+100 to this+452; this+20 = v5;
    //   v6 = a2 * this+180;
    //   v7 = v6 * this+308 + this+100; copy 24 bytes from this+148 to this+476; this+100 = v7;
    //   v8 = v6 * this+316 + this+108; copy 24 bytes from this+308 to this+500; this+108 = v8;
    //   v9 = v6 * this+324 + this+116; copy 24 bytes from this+332 to this+524; this+116 = v9;
    //   v11 = { a2 * this+124, a2 * this+132, a2 * this+140 };
    //   sub_56C020(v11);
    //   this+148 = a2 * this+332 + this+148;
    //   this+156 = a2 * this+340 + this+156;
    //   this+164 = a2 * this+348 + this+164;
    //   result = F_3x3InertiaTensorTransform(this);
    //   this+124 = this+236 * this+148 + this+244 * this+156 + this+252 * this+164;
    //   this+132 = this+260 * this+148 + this+268 * this+156 + this+276 * this+164;
    //   this+140 = this+284 * this+148 + this+292 * this+156 + this+300 * this+164;
    //   return result;
    // UNRESOLVED: The six staging copies target byte offsets (356, 380, 452, 476, 500, 524) that are absent from the packet field table; their role (preserving previous-position blocks) is described only from the raw source
    // UNRESOLVED: The rigid-body record layout and the meaning of sub_56C020's vector input are not defined by this packet
}
