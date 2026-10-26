// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00423B10
// Canonical corpus name: VehicleDynamics
// Owner: RelativeSpeedCalculator [DERIVED]
// Raw source: functions/VehicleDynamics_00423b10.c

void RelativeSpeedCalculator::computeRelativeSpeed()
{
    // Computes signed relative speed against a target vehicle for AI steering. When flag a4 is true it computes the longitudinal (closing) speed via a dot product of the target's position offset with a direction vector, stores the signed magnitude in this[9], and stores a normalized relative speed in this[12] (guarded against a zero-length direction). When a4 is false it computes the lateral speed via a 2D cross product and stores its signed magnitude in this[9] only.
    // GUARD: Branch on the a4 parameter: non-zero selects the longitudinal (dot-product) branch, zero selects the lateral (cross-product) branch. No early return; exactly one branch executes. [source:raw]
    // CALCULATION: Longitudinal branch: read the target object pointer from this[0], then compute v5 = (targetPositionX(0x34E0) - a2[37]) * a2[41] + (targetPositionY(0x34E8) - a2[39]) * a2[43], a dot product of the target position offset with direction components a2[41]/a2[43]. [field:this:0x00000000, field:obj:0x000034E0, field:obj:0x000034E8]
    // CALCULATION: Longitudinal branch: form v18 = a2[41] * v5 and v21 = a2[43] * v5, then take the square root of v21*v21 + v18*v18, negating the result when FPU condition flags C0/C3 were set. [source:raw]
    // ASSIGNMENT: Longitudinal branch: store the signed magnitude in this[9] (this+0x24). [field:this:0x00000024]
    // CALCULATION: Longitudinal branch: compute v11 = a2[43]*a2[43] + a2[41]*a2[41] (squared direction length). [source:raw]
    // GUARD: Longitudinal branch: if v11 equals the zero threshold (flt_59E440), write this[12] = 0.0; otherwise divide (targetVelocityX(0x34F8) * a2[41] + targetVelocityY(0x3500) * a2[43]) by v11 and store in this[12] (this+0x30). [global:0x0059E440, field:obj:0x000034F8, field:obj:0x00003500, field:this:0x00000030]
    // CALCULATION: Lateral branch: compute v12 = (targetPositionY(0x34E8) - a2[39]) * a2[41] - (targetPositionX(0x34E0) - a2[37]) * a2[43], a 2D cross product of the position offset with the direction components. [field:obj:0x000034E8, field:obj:0x000034E0]
    // CALCULATION: Lateral branch: form v20 = -a2[43] * v12 and v22 = a2[41] * v12, take the square root of v22*v22 + v20*v20, and negate the result when FPU condition flags C0/C3 were NOT set. [source:raw]
    // ASSIGNMENT: Lateral branch: store the signed magnitude in this[9] (this+0x24). [field:this:0x00000024]

    // Conservative worker pseudocode:
    //   if (a4) {
    //     v5 = dot(targetPos - a2[37..39], dir(a2[41],a2[43]))
    //     this[9] = sign * sqrt((a2[43]*v5)^2 + (a2[41]*v5)^2)
    //     len2 = a2[43]^2 + a2[41]^2
    //     this[12] = len2 == 0 ? 0.0 : dot(targetVel(0x34F8,0x3500), dir) / len2
    //   } else {
    //     v12 = cross(targetPos - a2[37..39], dir)
    //     this[9] = sign * sqrt((a2[41]*v12)^2 + (-a2[43]*v12)^2)
    //   }
    // UNRESOLVED: The direction components a2[41]/a2[43] and the meaning of a2[37]/a2[39] are not named in the packet; inferred as direction vector and reference position from the dot/cross structure.
    // UNRESOLVED: The sign selection reads FPU condition-code flags (C0/C3) from a comparison the decompiler did not materialize; the exact comparison is not recovered.
    // UNRESOLVED: field:this:0x00000000 is a pointer to the target object whose obj+0x34E0..0x3500 fields are read; the object type is not named.
}
