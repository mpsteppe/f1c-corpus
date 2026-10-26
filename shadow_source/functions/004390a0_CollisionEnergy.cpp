// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004390A0
// Canonical corpus name: CollisionEnergy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionEnergy_004390a0.c

void UnknownObject::CollisionEnergy()
{
    // Collision-energy accumulation over a four-element damage-parameter array, followed by six force/torque model evaluations fed by polynomial curve inputs derived from selector/coefficient field pairs. Each model evaluation contributes one float result and the function returns the sum of all six outputs as a double. Called by VehiclePhysicsInitializer (00439210).
    // LOOP: Four-iteration loop over the damage-parameter array: accumulate v2 += damage_selector(int at this+0x144, element stride 704 bytes) * adjacent_double_coefficient + second_adjacent_double. [field:this:0x00000144, source:raw]
    // CALCULATION: First polynomial input: v10 = (int at this+0xE04) * (double at this+0xDF8) + (double at this+0xDF0). [field:this:0x00000E04, field:this:0x00000DF8, field:this:0x00000DF0, source:raw]
    // CALL: Evaluate the first polynomial curve: QuadraticCubicPolynomialEvaluator(v10, out_v20, out_v19). [callee:0x004F3190, source:raw]
    // CALCULATION: Second polynomial input: v11 = (int at this+0xE44) * (double at this+0xE38) + (double at this+0xE30). [field:this:0x00000E44, field:this:0x00000E38, field:this:0x00000E30, source:raw]
    // CALL: Evaluate the second polynomial curve: QuadraticCubicPolynomialEvaluator(v11, out_v21, out_v18). [callee:0x004F3190, source:raw]
    // CALCULATION: Scale the accumulated damage energy: v13 = v2 * 0.1. [source:raw]
    // CALCULATION: Third input: v8 = (int at this+0x1284) * (double at this+0x1278) + (double at this+0x1270). [field:this:0x00001284, field:this:0x00001278, field:this:0x00001270, source:raw]
    // CALL: Evaluate the tire force/torque model: TireForceTorqueComputation(v8, v13, out_v22, out_v17). [callee:0x004F68B0, source:raw]
    // CALCULATION: Fourth input: v12 = (int at this+0x12C4) * (double at this+0x12B8) + (double at this+0x12B0). [field:this:0x000012C4, field:this:0x000012B8, field:this:0x000012B0, source:raw]
    // CALL: Evaluate the quadratic force model: QuadraticForceModel(v12, out_v23, out_v16). [callee:0x004F6950, source:raw]
    // CALCULATION: Fifth and sixth inputs: v9 = (int at this+0x1304) * (double at this+0x12F8) + (double at this+0x12F0), and v7 = (int at this+0x1344) * (double at this+0x1338) + (double at this+0x1330). [field:this:0x00001304, field:this:0x000012F8, field:this:0x000012F0, field:this:0x00001344, field:this:0x00001338, field:this:0x00001330, source:raw]
    // CALL: Evaluate the linear vehicle-parameter model: LinearVehicleParameterEvaluation(v7, v9, v13, out_v24, out_v15). [callee:0x004F69E0, source:raw]
    // CALL: Evaluate the quadratic force/torque curve: QuadraticForceTorqueCurveEvaluation(v13, out_v14). [callee:0x004F6A50, source:raw]
    // RETURN: Return the sum of the six single-float model outputs (out_v14 through out_v19) as a double. [source:raw]
    // CALL: Invoked by VehiclePhysicsInitializer (00439210) during vehicle physics setup. [caller:0x00439210, source:raw]

    // Conservative worker pseudocode:
    //   // a1: vehicle physics object, a2: unused
    //   v2 = 0.0;
    //   ptr = a1 + 312;
    //   for (i = 0; i < 4; ++i) {
    //     selector = *(int*)(ptr + 12);      // first element selector at this+0x144
    //     ptr += 704;
    //     v2 += selector * *(double*)(ptr - 704) + *(double*)(ptr - 712);
    //   }
    //   v10 = (double)*(int*)(a1 + 0xE04) * *(double*)(a1 + 0xDF8) + *(double*)(a1 + 0xDF0);
    //   QuadraticCubicPolynomialEvaluator(v10, &out20, &out19);
    //   v11 = (double)*(int*)(a1 + 0xE44) * *(double*)(a1 + 0xE38) + *(double*)(a1 + 0xE30);
    //   QuadraticCubicPolynomialEvaluator(v11, &out21, &out18);
    //   v13 = v2 * 0.1;
    //   v8 = (double)*(int*)(a1 + 0x1284) * *(double*)(a1 + 0x1278) + *(double*)(a1 + 0x1270);
    //   TireForceTorqueComputation(v8, v13, out22, &out17);
    //   v12 = (double)*(int*)(a1 + 0x12C4) * *(double*)(a1 + 0x12B8) + *(double*)(a1 + 0x12B0);
    //   QuadraticForceModel(v12, out23, &out16);
    //   v9 = (double)*(int*)(a1 + 0x1304) * *(double*)(a1 + 0x12F8) + *(double*)(a1 + 0x12F0);
    //   v7 = (double)*(int*)(a1 + 0x1344) * *(double*)(a1 + 0x1338) + *(double*)(a1 + 0x1330);
    //   LinearVehicleParameterEvaluation(v7, v9, v13, out24, &out15);
    //   QuadraticForceTorqueCurveEvaluation(v13, &out14);
    //   return out14 + out15 + out16 + out17 + out18 + out19;
    // UNRESOLVED: The two double coefficients read per damage-array element sit at element-relative offsets not present in the packet field set; only the first element's selector (this+0x144) is a packet field.
    // UNRESOLVED: Parameter a2 is declared but never referenced by the decompiled body.
    // UNRESOLVED: Globals dbl_59E430 (0x0059E430) and dbl_59EBA0 (0x0059EBA0) are flagged read-only by packet facts but appear nowhere in the raw decompiled source; the skeleton fill's claimed roles cannot be verified from this packet.
}
