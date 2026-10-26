// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E887
// Canonical corpus name: VectorNormalization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VectorNormalization_0050e887.c

void UnknownObject::VectorNormalization()
{
    // Normalizes the 3D vector a2 (x,y,z) to unit length, writing the result into a1. Computes the squared length v8 from the three components. When FloatRangeCheck reports v8 is already within tolerance of 1.0, copies a2 into a1 verbatim (skipping the copy when a1 == a2). Otherwise, if v8 is above the minimum-normal threshold, scales each component by 1/sqrt(v8) and stores the normalized vector in a1; if v8 is at or below the degenerate threshold, writes zeros into all three components. Returns the output pointer a1.
    // CALCULATION: Compute v8 = a2[0]*a2[0] + a2[1]*a2[1] + a2[2]*a2[2], the squared length of the input vector. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALL: Call FloatRangeCheck(v8, 1.0) to test whether the squared length is already within tolerance of 1.0 (the near-zero epsilon flt_5ADE40 at 0x005ADE40 is the tolerance this range check is built on). [callee:0x0050C042, global:0x005ADE40, source:raw]
    // GUARD: When the vector is already unit-length, copy a2 verbatim into a1 (three components), returning immediately when a1 == a2. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // GUARD: When v8 is at or below 1.1754944e-38 (the minimum-normal threshold sourced from flt_59E43C at 0x0059E43C), treat the vector as degenerate and write 0.0 into all three components of a1. [global:0x0059E43C, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: When v8 is above the degenerate threshold, compute v5 = 1.0 / sqrt(v8) and scale each component of a2 into the local buffer v7. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write the normalized components into a1: a1[0]=v7[0], a1[1]=v7[1], a1[2]=v7[2]. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // RETURN: Return the output pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   float* VectorNormalization(float* a1, float* a2) {
    //     float v8 = a2[0]*a2[0] + a2[1]*a2[1] + a2[2]*a2[2];
    //     if (FloatRangeCheck(v8, 1.0f)) {
    //       if (a1 == a2) return a1;
    //       a1[0] = a2[0]; a1[1] = a2[1]; a1[2] = a2[2];
    //       return a1;
    //     }
    //     if (v8 > 1.1754944e-38f) {
    //       float v5 = 1.0f / sqrt(v8);
    //       float v7[3] = { a2[0] * v5, a2[1] * v5, a2[2] * v5 };
    //       a1[0] = v7[0]; a1[1] = v7[1]; a1[2] = v7[2];
    //       return a1;
    //     }
    //     a1[0] = 0.0f; a1[1] = 0.0f; a1[2] = 0.0f;
    //     return a1;
    //   }
    // UNRESOLVED: The assignment of flt_5ADE40 (0x005ADE40) as the FloatRangeCheck epsilon and flt_59E43C (0x0059E43C) as the minimum-normal threshold is a DERIVED correspondence based on existing analysis; the raw source inlines the literal constants (1.0 and 1.1754944e-38) and does not itself name either global.
    // UNRESOLVED: The owning object of this vector math utility is unknown.
}
