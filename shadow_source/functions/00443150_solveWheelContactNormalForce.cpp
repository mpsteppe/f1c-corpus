// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00443150
// Canonical corpus name: WheelContactForceSolver
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelContactForceSolver_00443150.c

void UnknownObject::solveWheelContactNormalForce()
{
    // Solves the wheel-ground contact normal force for one contact. Rotates the wheel contact point (copied from the contact buffer at a2+76) into world space via the body rotation matrix at v3+28 (v3 = this[1404]), builds the contact-point velocity as a cross product of the rotated contact with the body vector at v3+124/132/140 plus the world angular velocity at v3+100/108/116, rotates the slip velocity back into the body frame, then when the normal slip component is negative (penetration) computes a friction-modulated normal force and an orthogonal damping force and accumulates the resulting angular momentum into the body via AccumulateAngularMomentum. Invoked per physics tick from DamperSpringForceComputationWithAntiRoll (0x004432F0) for each wheel corner.
    // GUARD: Guard: entire computation runs only when the contact-active flag byte at a2[0] is non-zero; otherwise the function returns immediately. [source:raw]
    // ASSIGNMENT: Copy the local contact position (3 doubles) from a2+76 into v18. [source:raw]
    // ASSIGNMENT: Load the rigid-body state pointer: v3 = this[1404] (this+0x15F0). [field:this:0x000015F0, source:raw]
    // CALL: Rotate the contact position to world space: Matrix3x3VectorMultiply on the body rotation matrix at v3+28 (this+0x160C), writing the world contact position to v13/v14/v15. [callee:0x00435E00, field:this:0x0000160C, source:raw]
    // CALCULATION: Cross-product of the rotated contact position with the body vector at v3+124/132/140: v4 = v15*(v3+132) - v14*(v3+140), v5 = v13*(v3+140) - v15*(v3+124), v17 = v14*(v3+124) - v13*(v3+132). [field:this:0x0000166C, field:this:0x00001674, field:this:0x0000167C, source:raw]
    // CALCULATION: Add the body world angular velocity (v3+100/108/116) to the cross-product terms to form the contact-point velocity vector: v16[0] = v4 + *(v3+100), v16[1] = v5 + *(v3+108), v17 = v17 + *(v3+116). [field:this:0x00001654, field:this:0x0000165C, field:this:0x00001664, source:raw]
    // CALL: Rotate the velocity vector into the body frame via Mat3x3MulVec on the same body matrix at v3+28, writing the body-frame slip velocity back into v18. [callee:0x004388D0, field:this:0x0000160C, source:raw]
    // CALCULATION: Subtract the reference velocity from the slip: v18[0] = v18[0] - a3[0]; normal slip v6 = v18[2] - a3[2]. Only components [0] and [2] of a3 are consumed. [source:raw]
    // GUARD: Guard entering the force-computation block: only when the normal slip v6 is negative (penetration / pressing), compared against the zero constant. [global:0x0059E430, source:raw]
    // CALCULATION: Compute squared velocity magnitudes: v7 = v6 * v6 (squared normal slip), v12 = v7, v8 = v18[0]*v18[0] + v7 (squared tangential plus squared normal). [source:raw]
    // CALCULATION: Friction reduction factor v9: if v8 <= 0.0 then v9 = 1.0, else v9 = 1.0 - (1.0 - (v7/v8)*(v7/v8)*(v7/v8)*(v7/v8)) * *(a2+68). Uses the one-double constant pool value. [global:0x0059E420, source:raw]
    // CALCULATION: Force magnitudes: v10 = v9 * *(a2+52) * v12 (friction-modulated normal component from the spring parameter) and v11 = *(a2+60) * v12 (damping/tangential component). [source:raw]
    // ASSIGNMENT: Assemble the world-space contact force from the rotation-matrix columns scaled by v10/v11 (with the zero-constant matrix terms): v18[0] = v11*(v3+44) + v10*(v3+36) + (v3+28)*0.0, v18[1] = v11*(v3+68) + v10*(v3+60) + (v3+52)*0.0, v18[2] = v11*(v3+92) + v10*(v3+84) + (v3+76)*0.0. [field:this:0x0000160C, field:this:0x00001614, field:this:0x0000161C, field:this:0x00001624, field:this:0x0000162C, field:this:0x00001634, field:this:0x0000163C, field:this:0x00001644, field:this:0x0000164C, global:0x0059E430, source:raw]
    // CALL: Accumulate the resulting angular momentum into the body: AccumulateAngularMomentum with the world contact position (&v13) as lever arm and the assembled force v18. [callee:0x00569AD0, source:raw]
    // RETURN: Void return; no output values are written back to the caller. [source:raw]

    // Conservative worker pseudocode:
    //   void solveWheelContactNormalForce(int this, int a2, double* a3) {
    //     if (!*(byte*)a2) return;
    //     double v18[3]; memcpy(v18, a2 + 76, 24);
    //     int v3 = *(int*)(this + 0x15F0);
    //     Matrix3x3VectorMultiply(v3 + 28, v18, &v13);
    //     v4 = v15*(v3+132) - v14*(v3+140);
    //     v5 = v13*(v3+140) - v15*(v3+124);
    //     v17 = v14*(v3+124) - v13*(v3+132);
    //     v16[0] = v4 + *(double*)(v3+100);
    //     v16[1] = v5 + *(double*)(v3+108);
    //     v17 = v17 + *(double*)(v3+116);
    //     Mat3x3MulVec(v3 + 28, v16, v18);
    //     v18[0] -= a3[0];
    //     v6 = v18[2] - a3[2];
    //     if (v6 < 0.0) {
    //       v7 = v6 * v6;
    //       v8 = v18[0]*v18[0] + v7;
    //       v9 = (v8 <= 0.0) ? 1.0 : 1.0 - (1.0 - pow(v7/v8, 4.0)) * *(double*)(a2+68);
    //       v10 = v9 * *(double*)(a2+52) * v7;
    //       v11 = *(double*)(a2+60) * v7;
    //       v18[0] = v11*(v3+44) + v10*(v3+36) + (v3+28)*0.0;
    //       v18[1] = v11*(v3+68) + v10*(v3+60) + (v3+52)*0.0;
    //       v18[2] = v11*(v3+92) + v10*(v3+84) + (v3+76)*0.0;
    //       AccumulateAngularMomentum(&v13, v18);
    //     }
    //   }
    // UNRESOLVED: The body vector at v3+124/132/140 used in the contact-point velocity cross product has no deterministic field meaning in the packet; the fill's field table labels this+0x166C..0x167C (which maps to that range) as body force/torque accumulators, which conflicts with the raw matrix/velocity usage observed here. Its physical identity (inertia-related lever term, extra world-space axis, etc.) is unresolved.
    // UNRESOLVED: a3 is consumed only at components [0] and [2]; its full layout and exact role (reference/road-surface velocity vs target slip) is ambiguous from this function alone.
    // UNRESOLVED: Globals dbl_59E420 / dbl_59E430 are treated here as the 1.0 and ~0.0 constants (DERIVED per the fill), but their exact values are not proven by this function's body.
    // UNRESOLVED: The world contact position v13 is passed to AccumulateAngularMomentum as the torque lever arm; whether that call only accumulates moment (and any linear force path exists elsewhere) is not visible in this function.
}
