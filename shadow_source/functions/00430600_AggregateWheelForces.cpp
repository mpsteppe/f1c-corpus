// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00430600
// Canonical corpus name: WheelForceAggregate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelForceAggregate_00430600.c

void UnknownObject::AggregateWheelForces()
{
    // Aggregates per-wheel force outputs from six indexed parameter triples (index times multiplier plus base) read from the owning physics object, feeds them into polynomial, tire-force, quadratic, and linear force models, and sums the model outputs into the lateral component *a3 and the longitudinal component *a4.
    // CALCULATION: Evaluate parameter triple A as index this+0xE04 times multiplier this+0xDF8 plus base this+0xDF0, producing the polynomial input v9. [field:this:0x00000DF0, field:this:0x00000DF8, field:this:0x00000E04]
    // CALL: Evaluate QuadraticCubicPolynomialEvaluator on the triple-A input, filling outputs v12 and v18. [callee:0x004F3190]
    // CALCULATION: Evaluate parameter triple B as index this+0xE44 times multiplier this+0xE38 plus base this+0xE30, producing the polynomial input v10. [field:this:0x00000E30, field:this:0x00000E38, field:this:0x00000E44]
    // CALL: Evaluate QuadraticCubicPolynomialEvaluator on the triple-B input, filling outputs a2[0] and v17. [callee:0x004F3190]
    // CALCULATION: Evaluate parameter triple C as index this+0x1284 times multiplier this+0x1278 plus base this+0x1270, producing the tire-force input v7. [field:this:0x00001270, field:this:0x00001278, field:this:0x00001284]
    // CALL: Run TireForceTorqueComputation on the triple-C input with time step 0.025, filling outputs v21 and v16. [callee:0x004F68B0]
    // CALCULATION: Evaluate parameter triple D as index this+0x12C4 times multiplier this+0x12B8 plus base this+0x12B0, producing the quadratic-model input v11. [field:this:0x000012B0, field:this:0x000012B8, field:this:0x000012C4]
    // CALL: Run QuadraticForceModel on the triple-D input, filling outputs v20 and v15. [callee:0x004F6950]
    // CALCULATION: Evaluate parameter triple E as index this+0x1304 times multiplier this+0x12F8 plus base this+0x12F0, producing the linear-model input v8. [field:this:0x000012F0, field:this:0x000012F8, field:this:0x00001304]
    // CALCULATION: Evaluate parameter triple F as index this+0x1344 times multiplier this+0x1338 plus base this+0x1330, producing the second linear-model input v6. [field:this:0x00001330, field:this:0x00001338, field:this:0x00001344]
    // CALL: Run LinearVehicleParameterEvaluation with inputs v6 and v8 and time step 0.025, filling outputs v19 and v14. [callee:0x004F69E0]
    // CALL: Run QuadraticForceTorqueCurveEvaluation with time step 0.025, filling output v13. [callee:0x004F6A50]
    // ASSIGNMENT: Sum the lateral components v19[2] + v20[2] + v21[2] + a2[0] + v12 into the output *a3. [source:raw]
    // ASSIGNMENT: Sum the longitudinal components v13 + v14 + v15 + v16 + v17 + v18 into the output *a4. [source:raw]
    // RETURN: Return the output pointer a4 as the result. [source:raw]

    // Conservative worker pseudocode:
    //   float *AggregateWheelForces(int this, float *outLat, float *outLon) {
    //     float v9  = *(double*)(this+0xE04) * *(double*)(this+0xDF8) + *(double*)(this+0xDF0);
    //     QuadraticCubicPolynomialEvaluator(v9, &v12, &v18);
    //     float v10 = *(double*)(this+0xE44) * *(double*)(this+0xE38) + *(double*)(this+0xE30);
    //     QuadraticCubicPolynomialEvaluator(v10, &a2, &v17);
    //     float v7  = *(double*)(this+0x1284) * *(double*)(this+0x1278) + *(double*)(this+0x1270);
    //     TireForceTorqueComputation(v7, 0.025, v21, &v16);
    //     float v11 = *(double*)(this+0x12C4) * *(double*)(this+0x12B8) + *(double*)(this+0x12B0);
    //     QuadraticForceModel(v11, v20, &v15);
    //     float v8  = *(double*)(this+0x1304) * *(double*)(this+0x12F8) + *(double*)(this+0x12F0);
    //     float v6  = *(double*)(this+0x1344) * *(double*)(this+0x1338) + *(double*)(this+0x1330);
    //     LinearVehicleParameterEvaluation(v6, v8, 0.025, v19, &v14);
    //     QuadraticForceTorqueCurveEvaluation(0.025, &v13);
    //     *outLat = v19[2] + v20[2] + v21[2] + a2 + v12;
    //     *outLon = v13 + v14 + v15 + v16 + v17 + v18;
    //     return outLon;
    //   }
    // UNRESOLVED: The owning object class is unproven; the read offsets are consistent with a per-wheel physics parameter block but the packet does not name the owner.
    // UNRESOLVED: Which physical wheel each of the six parameter triples (A through F) corresponds to, and the exact force semantics of the two summed outputs, are not established.
}
