// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F6950
// Canonical corpus name: QuadraticForceModel
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuadraticForceModel_004f6950.c

void UnknownObject::ComputeQuadraticForce()
{
    // Computes a quadratic force/torque model: given input a2, fills torque *a4 and force components a3[0..2] using quadratic polynomials in a2 plus two absolute-value force components read from object doubles. Gated by an enable byte at this+0x2F8; when disabled all four outputs are zeroed. Called from WheelForceAggregate, CollisionEnergy and SuspensionAndWheelPhysics.
    // GUARD: Enable gate: when the byte at this+0x2F8 is non-zero compute all outputs, otherwise zero them. [field:this:0x000002F8, source:raw]
    // CALCULATION: Torque: *a4 = a2 * (double at this+0x324) * a2 + a2 * (double at this+0x31C) + (double at this+0x314) — quadratic in a2. [field:this:0x00000314, field:this:0x0000031C, field:this:0x00000324, source:raw]
    // ASSIGNMENT: Force component a3[0] = fabs(double at this+0x34C). [field:this:0x0000034C, source:raw]
    // ASSIGNMENT: Force component a3[1] = fabs(double at this+0x384). [field:this:0x00000384, source:raw]
    // CALCULATION: Force component a3[2] = a2 * (double at this+0x30C) * a2 + a2 * (double at this+0x304) + (double at this+0x2FC) — quadratic in a2. [field:this:0x000002FC, field:this:0x00000304, field:this:0x0000030C, source:raw]
    // ASSIGNMENT: Disabled path: zero *a4 and a3[0..2]. [field:this:0x000002F8, source:raw]
    // RETURN: Return the a3 pointer. [source:raw]

    // Conservative worker pseudocode:
    //   float *ComputeQuadraticForce(int this, float input, float *force, float *torque) {
    //     if (*(_BYTE *)(this + 0x2F8)) {
    //       *torque = input * *(double *)(this + 0x324) * input + input * *(double *)(this + 0x31C) + *(double *)(this + 0x314);
    //       force[0] = fabs(*(double *)(this + 0x34C));
    //       force[1] = fabs(*(double *)(this + 0x384));
    //       force[2] = input * *(double *)(this + 0x30C) * input + input * *(double *)(this + 0x304) + *(double *)(this + 0x2FC);
    //     } else {
    //       *torque = 0.0f;
    //       force[0] = force[1] = force[2] = 0.0f;
    //     }
    //     return force;
    //   }
    // UNRESOLVED: Coefficients are read as doubles from this+764..900; the physical meaning of each coefficient (enable byte, quadratic terms, absolute-value terms) is unproven and caller-dependent.
}
