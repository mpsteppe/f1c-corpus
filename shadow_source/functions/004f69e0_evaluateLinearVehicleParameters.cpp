// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F69E0
// Canonical corpus name: LinearVehicleParameterEvaluation
// Owner: WheelParameterEvaluator [DERIVED]
// Raw source: functions/LinearVehicleParameterEvaluation_004f69e0.c

void WheelParameterEvaluator::evaluateLinearVehicleParameters()
{
    // Evaluates linear combinations of three scalar inputs (a2, a3, a4) against per-field coefficients and biases read from the 'this' object, writing two force-component magnitudes (absolute values) and a combined torque-like output into the output buffers a5 and a6. Unconditional computation on the per-frame physics path.
    // CALCULATION: Compute *a6 = a2 * (this+0x530) + a3 * (this+0x520) + (this+0x4AC): a combined output from inputs a2/a3 and their coefficients plus a bias term. [field:this:0x00000530, field:this:0x00000520, field:this:0x000004AC]
    // ASSIGNMENT: Write a5[0] = fabs(this+0x444): force component 0 is the absolute value of the double at this+0x444. [field:this:0x00000444]
    // ASSIGNMENT: Write a5[1] = fabs(this+0x47C): force component 1 is the absolute value of the double at this+0x47C. [field:this:0x0000047C]
    // CALCULATION: Compute a5[2] = a2 * (this+0x528) + a3 * (this+0x518) + a4 * (this+0x3FC) + (this+0x3F4): force component 2 as a linear combination of a2/a3/a4 with coefficients and a bias. [field:this:0x00000528, field:this:0x00000518, field:this:0x000003FC, field:this:0x000003F4]
    // RETURN: Return a5 (the force-component output buffer) to the caller. [source:raw]

    // Conservative worker pseudocode:
    //   *a6 = a2 * c530 + a3 * c520 + bias4AC
    //   a5[0] = fabs(d444); a5[1] = fabs(d47C)
    //   a5[2] = a2 * c528 + a3 * c518 + a4 * c3FC + bias3F4
    //   return a5
    // UNRESOLVED: The physical meaning of the three inputs (a2/a3/a4) and whether a5 is a force vector or a torque/force mix is not visible from the packet; only linear structure is recovered.
    // UNRESOLVED: The output written through a6 is computed but never read inside this function; its downstream consumer is not in the packet.
}
