// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043E4B0
// Canonical corpus name: RigidBodyConstraintSolve
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RigidBodyConstraintSolve_0043e4b0.c

void UnknownObject::RigidBodyConstraintSolve()
{
    // Rigid-body constraint position solve. Saves the FPU control word, converts Euler angles to a 3x3 rotation matrix, transforms the body position (this+0x15FC/+0x1604/+0x160C) into the target frame, computes the position error between the supplied pose a2 and the transformed position, and applies the constraint correction via sub_56F100. Clears the constraint enable flag at this+0xB4 and initializes four wheel-constraint entries at this+0x3A8 (stride 281 dwords) with disabled values (-1 / -1048577), then restores the FPU control word if it changed.
    // CALL: FPUControlWordMaskExtract(512) captures the current FPU control word so it can be restored before returning if the mask differs from 512 [callee:0x00567740, source:raw]
    // CALL: EulerAnglesTo33RotationMatrix(a3) converts the Euler angles argument into the 3x3 rotation matrix held in the stack locals v12..v20 [callee:0x0056BD40, source:raw]
    // CALCULATION: v5 = *(this + 0x15F0): load the body object pointer that is passed to the constraint correction call [field:this:0x000015F0, source:raw]
    // CALCULATION: Transform the body position (three doubles read at this+0x15FC, this+0x1604, this+0x160C) through the rotation-matrix rows: the three dot products become v6, v7 and v11 [field:this:0x000015FC, field:this:0x00001604, field:this:0x0000160C, source:raw]
    // CALCULATION: Build the position error vector v10[0..2] = a2[0..2] - (v6, v7, v11): the supplied pose minus the rotated body position [source:raw]
    // CALL: sub_56F100(v5, v10, a3, 0) applies the constraint correction using the body pointer, the position error vector, the Euler angles and a flag argument of 0 [callee:0x0056F100, field:this:0x000015F0, source:raw]
    // ASSIGNMENT: Clear this+0xB4 to 0 (constraint enable flag reset) [field:this:0x000000B4, source:raw]
    // LOOP: Walk 4 wheel-constraint entries starting at this+0x3A8 with a stride of 281 dwords (1124 bytes); each entry receives the disabled pair -1 (this+0x3A8) and -1048577 (this+0x3AC) [field:this:0x000003A8, field:this:0x000003AC, source:raw]
    // GUARD: If the captured FPU control word v4 differs from 512, restore it by calling EmptyStub_7780(v4) [callee:0x00567780, source:raw]
    // RETURN: Return the loop pointer (or the FPU-restore result); this is the rigid-body constraint position solve invoked per frame by AIVehiclePathPositionTracking (004EF7C0) [caller:0x004EF7C0, source:raw]

    // Conservative worker pseudocode:
    //   saved_fpu = FPUControlWordMaskExtract(512);
    //   EulerAnglesTo33RotationMatrix(euler);
    //   body = this[0x15F0/4];
    //   v6  = M[0][0]*body[0x15FC] + M[0][1]*body[0x1604] + M[0][2]*body[0x160C];
    //   v7  = M[1][0]*body[0x15FC] + M[1][1]*body[0x1604] + M[1][2]*body[0x160C];
    //   v11 = M[2][0]*body[0x15FC] + M[2][1]*body[0x1604] + M[2][2]*body[0x160C];
    //   err = { a2[0]-v6, a2[1]-v7, a2[2]-v11 };
    //   sub_56F100(body, err, euler, 0);
    //   this[0xB4/4] = 0;
    //   for (4 entries, stride 281 dwords from this+0x3A8):
    //     entry[0x3A8] = -1; entry[0x3AC] = -1048577; (pair repeated twice per walk)
    //   if (saved_fpu != 512) EmptyStub_7780(saved_fpu);
    //   return walk_ptr;
    // UNRESOLVED: The exact physical meaning of the per-entry -1 / -1048577 initializers at this+0x3A8 is not documented in this packet; the skeleton fill labels them wheel-constraint disabled values
    // UNRESOLVED: The constraint correction routine sub_56F100 is not inlined here, so the effect of the error vector on the body is resolved only at the callee
}
