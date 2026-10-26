// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00441D60
// Canonical corpus name: PhysicsIntegrationStep
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsIntegrationStep_00441d60.c

void UnknownObject::PhysicsIntegrationStep()
{
    // Performs one physics integration substep on the vehicle physics object in this: runs the counter helper sub_56EB90 on this+0x15AC, two unnamed setup passes sub_4423B0/sub_442C90, and DamperSpringForceComputationWithAntiRoll; conditionally applies velocity damping from speed error when the double at this+0x19C is zero; applies a fixed -9.81 acceleration term to each body in the array at this+0x15B0 (count at this+0x15AC, stride 580); accumulates torques, solves rigid-body constraints against the block at this+0x15F0, and accumulates two batches of linear and angular velocity deltas into that block's linear (block+308) and angular (block+332) accumulators.
    // CALL: Invoke sub_56EB90 on the counter at this+0x15AC. [callee:0x0056EB90, field:this:0x000015AC, source:raw]
    // CALL: Invoke the unnamed setup pass sub_4423B0(this). [callee:0x004423B0, source:raw]
    // CALL: Invoke the unnamed setup pass sub_442C90(this). [callee:0x00442C90, source:raw]
    // CALL: Compute damper and spring forces with anti-roll: DamperSpringForceComputationWithAntiRoll(this). [callee:0x004432F0, source:raw]
    // GUARD: When the double at this+0x19C equals 0.0, apply velocity damping from speed error: VelocityDampingFromSpeedError(this). [field:this:0x0000019C, callee:0x00441AD0, source:raw]
    // LOOP: Loop over *(this+0x15AC) bodies in the array at this+0x15B0 (element stride 580). For each body: copy the value at body+308 back to body+308, accumulate a fixed acceleration term v6 * -9.81 into the vertical velocity accumulator at body+316, and write self-assignment copies at body+312, body+324 and body+328. The compiled double constants dbl_59E430 and dbl_59ED50 supply the scalar constants for this acceleration arithmetic. [guard:0, field:this:0x000015AC, field:this:0x000015B0, field:*(this+0x15F0):0x0000013C, global:0x0059E430, global:0x0059ED50, source:raw]
    // CALL: Accumulate rigid-body torques: RigidBodyTorqueAccumulation(this). [callee:0x00441BB0, source:raw]
    // CALL: Solve rigid-body constraints: RigidBodyConstraintJointSolver(constraint data at this+492, body block *(this+0x15F0), solver parameters this+0x60 and this+0x64). [callee:0x004359A0, field:this:0x000015F0, field:this:0x00000060, field:this:0x00000064, source:raw]
    // CALCULATION: Accumulate the first linear-velocity delta batch into the body block at *(this+0x15F0): add this+0xEC/0xF4/0xFC to block+0x134/0x13C/0x144 (block+308/316/324). [field:*(this+0x15F0):0x00000134, field:*(this+0x15F0):0x0000013C, field:*(this+0x15F0):0x00000144, field:this:0x000000EC, field:this:0x000000F4, field:this:0x000000FC, source:raw]
    // CALCULATION: Accumulate the first angular-velocity delta batch into the body block at *(this+0x15F0): add this+0x104/0x10C/0x114 to block+0x14C/0x154/0x15C (block+332/340/348). [field:*(this+0x15F0):0x0000014C, field:*(this+0x15F0):0x00000154, field:*(this+0x15F0):0x0000015C, field:this:0x00000104, field:this:0x0000010C, field:this:0x00000114, source:raw]
    // CALCULATION: Accumulate the second linear-velocity delta batch into the body block at *(this+0x15F0): add this+0x1F04/0x1F0C/0x1F14 to block+0x134/0x13C/0x144. [field:*(this+0x15F0):0x00000134, field:this:0x00001F04, field:this:0x00001F0C, field:this:0x00001F14, source:raw]
    // CALCULATION: Accumulate the second angular-velocity delta batch into the body block at *(this+0x15F0): add this+0x1F1C/0x1F24/0x1F2C to block+0x14C/0x154/0x15C. [field:*(this+0x15F0):0x0000014C, field:this:0x00001F1C, field:this:0x00001F24, field:this:0x00001F2C, source:raw]
    // RETURN: Return a pointer to the body block angular-velocity accumulator (block+332). [source:raw]

    // Conservative worker pseudocode:
    //   double* PhysicsIntegrationStep(int this) {
    //     int* counter = (int*)(this + 5548);
    //     sub_56EB90(this + 5548);
    //     sub_4423B0(this);
    //     sub_442C90(this);
    //     DamperSpringForceComputationWithAntiRoll(this);
    //     if (*(double*)(this + 412) == 0.0) VelocityDampingFromSpeedError(this);
    //     if (*counter > 0) {
    //       for (int i = 0; i < *counter; ++i) {
    //         char* b = (char*)*(int*)(this + 5552) + i * 580;
    //         double v = *(double*)(b + 172);
    //         *(int*)(b + 308) = *(int*)(b + 308);
    //         *(int*)(b + 312) = *(int*)(b + 312);
    //         *(double*)(b + 316) = v * -9.81 + *(double*)(b + 316);
    //         *(int*)(b + 324) = *(int*)(b + 324);
    //         *(int*)(b + 328) = *(int*)(b + 328);
    //       }
    //     }
    //     RigidBodyTorqueAccumulation(this);
    //     RigidBodyConstraintJointSolver((void*)(this + 492), *(void**)(this + 5616), *(int*)(this + 96), *(int*)(this + 100));
    //     char* body = *(char**)(this + 5616);
    //     for (int k = 0; k < 3; ++k) *(double*)(body + 308 + k*8) += *(double*)(this + 236 + k*8);
    //     for (int k = 0; k < 3; ++k) *(double*)(body + 332 + k*8) += *(double*)(this + 260 + k*8);
    //     for (int k = 0; k < 3; ++k) *(double*)(body + 308 + k*8) += *(double*)(this + 7940 + k*8);
    //     for (int k = 0; k < 3; ++k) *(double*)(body + 332 + k*8) += *(double*)(this + 7964 + k*8);
    //     return (double*)(body + 332);
    //   }
    // UNRESOLVED: Identity and purpose of the unnamed callees sub_56EB90, sub_4423B0 and sub_442C90.
    // UNRESOLVED: Meaning of the per-element body stride 580 and of the fields body+172, body+312, body+324, body+328 that are read or self-copied inside the loop.
    // UNRESOLVED: The -9.81 term is read as gravity acceleration (consistent with the canonical name) but the exact physical interpretation, and which of dbl_59E430/dbl_59ED50 supplies it, is not confirmed.
    // UNRESOLVED: Origin and meaning of the two delta batches (this+0xEC..0xFC and this+0x1F04..0x1F1C) and how they differ from each other.
    // UNRESOLVED: Sole caller is VehiclePhysicsIntegrationStep (0x00441650); no other callers are present in this packet.
}
