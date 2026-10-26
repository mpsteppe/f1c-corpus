// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004432F0
// Canonical corpus name: DamperSpringForceComputationWithAntiRoll
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DamperSpringForceComputationWithAntiRoll_004432f0.c

void UnknownObject::ComputeDamperSpringAndAntiRollForces()
{
    // Per-corner suspension force computation for one wheel axle. Clamps the left/right suspension travel averages to [0.0, max travel], writes the total damper force to this+0x1B9C from a spring rate, a velocity-dependent coefficient and an intercept, transforms the wheel contact point and the anti-roll direction into the chassis frame, runs a 6x6 quadratic-form coupling solve (0x00436230) to derive force/moment pairs, accumulates angular momentum into the chassis rigid body (0x00435E00/0x00569AD0), conditionally computes helper-spring abutment force when the helper flag is set and vertical displacement is negative, solves wheel-ground contact forces for both corners (0x00443150), then computes first and second anti-roll bar coupling forces (guarded by enable flags and linked-object pointers) and finally adds the summed coupling moments into the chassis angular momentum fields at +0x14C/+0x154/+0x15C. Invoked per physics tick from PhysicsIntegrationStep (0x00441D60).
    // CALCULATION: Average the first suspension travel pair: v41 = (*(this+0x16F8) + *(this+0x16F0)) * 0.5. [field:this:0x000016F0, field:this:0x000016F8, source:raw]
    // CALCULATION: Clamp v41 into [0.0, max travel]: negative becomes 0.0, above *(this+0x1AF4) is capped at the max (dword pair 0x1AF4/0x1AF8). [field:this:0x00001AF4, field:this:0x00001AF8, source:raw]
    // CALCULATION: Average the second suspension travel pair: v40 = (*(this+0x1708) + *(this+0x1700)) * 0.5. [field:this:0x00001700, field:this:0x00001708, source:raw]
    // CALCULATION: Clamp v40 into [0.0, max travel] using the same limit pair *(this+0x1AF4)/*(this+0x1AF8). [field:this:0x00001AF4, field:this:0x00001AF8, source:raw]
    // CALCULATION: Write the total damper force to this+0x1B9C: fabs(v41 - v40) * *(this+0x1AEC) + (v40 + v41) * *(this+0x1AE4) * 0.5 + *(this+0x1ADC). [field:this:0x00001B9C, field:this:0x00001AEC, field:this:0x00001AE4, field:this:0x00001ADC, source:raw]
    // CALL: Read the wheel contact point vector from shared vehicle state *(this+0x1F00) at +0x3A64/+0x3A68/+0x3A6C and transform it into the chassis frame via Mat3x3MulVec (0x004388D0) using the chassis orientation matrix at *(this+0x15F0)+0x1C, producing v54/v55/v56. [callee:0x004388D0, field:*(this+0x1F00):0x00003A64, field:*(this+0x1F00):0x00003A68, field:*(this+0x1F00):0x00003A6C, field:this:0x00001F00, field:this:0x000015F0, source:raw]
    // CALL: Transform the anti-roll direction vector at this+0x1AFC into the chassis frame via Matrix3x3VectorMultiply (0x00435E00) on the chassis matrix, writing v51. [callee:0x00435E00, field:this:0x000015F0, source:raw]
    // CALCULATION: Transform the suspension attachment arm (chassis +0x64) and the lever-arm/direction vector (chassis +0x7C) via Mat3x3MulVec (0x004388D0), then subtract the contact point: v37 -= v54, v38 -= v55, v39 -= v56, forming the chassis-local relative displacement. [callee:0x004388D0, field:*(this+0x15F0):0x00000064, field:*(this+0x15F0):0x0000006C, field:*(this+0x15F0):0x00000074, field:*(this+0x15F0):0x0000007C, field:*(this+0x15F0):0x00000084, field:*(this+0x15F0):0x0000008C, source:raw]
    // CALL: Solve the 6x6 coupling via QuadraticForm6x6 (0x00436230) over (this+0x1B14, &v37, v63, &v45, &v42), producing force v45 and moment v42. [callee:0x00436230, source:raw]
    // CALL: Transform the coupling force v45 into the world frame via Matrix3x3VectorMultiply (0x00435E00) and accumulate the resulting torque into the chassis angular momentum via AccumulateAngularMomentum (0x00569AD0) at +0x14C/+0x154/+0x15C. [callee:0x00435E00, callee:0x00569AD0, field:*(this+0x15F0):0x0000014C, field:*(this+0x15F0):0x00000154, field:*(this+0x15F0):0x0000015C, source:raw]
    // GUARD: Guard entering the helper-spring block: only when the helper-spring enable flag *(this+0x1BBC) is set AND the vertical displacement v39 is negative (compression). [field:this:0x00001BBC, source:raw]
    // CALCULATION: Compute the helper-spring abutment force v11 = (v40 * *(this+0x1BD0) * v40 + v40 * *(this+0x1BC8) + v41 * *(this+0x1BD8) + *(this+0x1BC0)) * v10, where v10 is a cos-squared lateral falloff factor built from the displacement ratio and *(this+0x1BE0). [field:this:0x00001BC0, field:this:0x00001BC8, field:this:0x00001BD0, field:this:0x00001BD8, field:this:0x00001BE0, source:raw]
    // CALL: When the helper force v11 is negative, scale it by v39^2 across the chassis matrix elements (+0x24/+0x3C/+0x54), transform the direction at this+0x1BE8 via Matrix3x3VectorMultiply (0x00435E00) and accumulate the torque via AccumulateAngularMomentum (0x00569AD0). [callee:0x00435E00, callee:0x00569AD0, field:*(this+0x15F0):0x00000024, field:*(this+0x15F0):0x0000003C, field:*(this+0x15F0):0x00000054, source:raw]
    // CALL: Solve wheel-ground contact forces for both corners: WheelContactForceSolver (0x00443150) on this+0x1838 and this+0x189C, both seeded with the contact point v54. [callee:0x00443150, source:raw]
    // GUARD: Guard entering the first anti-roll bar block: only when the first ARB enable flag *(this+0x1900) is non-zero. [field:this:0x00001900, source:raw]
    // GUARD: Within the first ARB block, read the front linked-object pointer at *(*(this+0x1F00)+0xCD4); compute only when the pointer is null OR the flag at that object +0x40 is set. [field:*(this+0x1F00):0x00000CD4, field:this:0x00001F00, source:raw]
    // CALCULATION: Clamp the first ARB displacement *(this+0x1908/0x190C) into [0.0, *(this+0x1910/0x1914)]. Below 0 it is set to 0; above the limit it is capped. [field:this:0x00001908, field:this:0x0000190C, field:this:0x00001910, field:this:0x00001914, source:raw]
    // CALCULATION: Build the first-ARB relative displacement v37/v38/v39: cross product of the lever vector (this+0x1918/0x1920/0x1928) with chassis matrix rows (+0x84/+0x8C/+0x7C), offset by the arm (+0x64/+0x6C/+0x74), transformed and subtracted from the contact point. [field:this:0x00001918, field:this:0x00001920, field:this:0x00001928, field:*(this+0x15F0):0x00000064, field:*(this+0x15F0):0x0000006C, field:*(this+0x15F0):0x00000074, field:*(this+0x15F0):0x00000084, field:*(this+0x15F0):0x0000008C, source:raw]
    // CALCULATION: Write the first-ARB coupling force to this+0x19E0: v23 * (*(this+0x1938) * displacement + *(this+0x1930)), where v23 is the cos-squared falloff built from *(this+0x1940). [field:this:0x000019E0, field:this:0x00001930, field:this:0x00001938, field:this:0x00001940, source:raw]
    // CALL: Run the second 6x6 solve QuadraticForm6x6 (0x00436230) over (this+0x1960, &v37, v63, &v45, &v57), transform v45 via Matrix3x3VectorMultiply (0x00435E00), accumulate torque about the lever base this+0x1918 via AccumulateAngularMomentum (0x00569AD0), and fold v57/v58/v59 into v42/v43/v44. [callee:0x00436230, callee:0x00435E00, callee:0x00569AD0, field:this:0x00001918, source:raw]
    // GUARD: Guard entering the second anti-roll bar block: only when the second ARB enable flag *(this+0x1A08) is non-zero. [field:this:0x00001A08, source:raw]
    // GUARD: Within the second ARB block, read the rear linked-object pointer at *(*(this+0x1F00)+0xD18); compute only when the pointer is null OR the flag at that object +0x40 is set. [field:*(this+0x1F00):0x00000D18, field:this:0x00001F00, source:raw]
    // CALCULATION: Transform the second-ARB direction at this+0x1A1C via Matrix3x3VectorMultiply (0x00435E00) into v51, then build the relative displacement v37/v38/v39 from cross products with chassis matrix rows (+0x84/+0x8C/+0x7C) offset by the arm (+0x64/+0x6C/+0x74). [callee:0x00435E00, field:*(this+0x15F0):0x00000064, field:*(this+0x15F0):0x0000006C, field:*(this+0x15F0):0x00000074, field:*(this+0x15F0):0x0000007C, field:*(this+0x15F0):0x00000084, field:*(this+0x15F0):0x0000008C, source:raw]
    // CALCULATION: Write the second-ARB coupling force to this+0x1AB4: v32 * *(this+0x1A0C), where v32 is the cos-squared falloff built from *(this+0x1A14). [field:this:0x00001AB4, field:this:0x00001A0C, field:this:0x00001A14, source:raw]
    // CALL: Run the third 6x6 solve QuadraticForm6x6 (0x00436230) over (this+0x1A34, &v37, v63, &v45, &v57), transform v45 into v60 with the chassis matrix rows (+0x1C/+0x24/+0x2C, +0x34/+0x3C/+0x44, +0x4C/+0x54/+0x5C), accumulate torque about v51 via AccumulateAngularMomentum (0x00569AD0), and fold v57/v58/v59 into v42/v43/v44. [callee:0x00436230, callee:0x00569AD0, field:*(this+0x15F0):0x0000001C, field:*(this+0x15F0):0x00000024, field:*(this+0x15F0):0x0000002C, field:*(this+0x15F0):0x00000034, field:*(this+0x15F0):0x0000003C, field:*(this+0x15F0):0x00000044, field:*(this+0x15F0):0x0000004C, field:*(this+0x15F0):0x00000054, field:*(this+0x15F0):0x0000005C, source:raw]
    // CALCULATION: Final accumulation into chassis angular momentum: combine v42/v43/v44 with the matrix elements (+0x1C/+0x24/+0x2C, +0x34/+0x3C/+0x44, +0x4C/+0x54/+0x5C) and add into *(chassis+0x14C), *(chassis+0x154), *(chassis+0x15C). [field:*(this+0x15F0):0x0000014C, field:*(this+0x15F0):0x00000154, field:*(this+0x15F0):0x0000015C, field:*(this+0x15F0):0x0000001C, field:*(this+0x15F0):0x00000024, field:*(this+0x15F0):0x0000002C, field:*(this+0x15F0):0x00000034, field:*(this+0x15F0):0x0000003C, field:*(this+0x15F0):0x00000044, field:*(this+0x15F0):0x0000004C, field:*(this+0x15F0):0x00000054, field:*(this+0x15F0):0x0000005C, source:raw]
    // CALL: Invoked from PhysicsIntegrationStep (0x00441D60) on the per-frame physics tick. [caller:0x00441D60]

    // Conservative worker pseudocode:
    //   void ComputeDamperSpringAndAntiRollForces(int this) {
    //     v41 = clamp((*(this+0x16F8) + *(this+0x16F0)) * 0.5, 0.0, *(this+0x1AF4));
    //     v40 = clamp((*(this+0x1708) + *(this+0x1700)) * 0.5, 0.0, *(this+0x1AF4));
    //     *(this+0x1B9C) = fabs(v41 - v40) * *(this+0x1AEC) + (v40 + v41) * *(this+0x1AE4) * 0.5 + *(this+0x1ADC);
    //     Mat3x3MulVec(*(this+0x15F0)+0x1C, *(*(this+0x1F00)+0x3A64), &v54);
    //     Matrix3x3VectorMultiply(*(this+0x15F0)+0x1C, this+0x1AFC, &v51);
    //     Mat3x3MulVec(*(this+0x15F0)+0x1C, *(this+0x15F0)+0x64, &v37);
    //     Mat3x3MulVec(*(this+0x15F0)+0x1C, *(this+0x15F0)+0x7C, v63);
    //     v37 -= v54; v38 -= v55; v39 -= v56;
    //     QuadraticForm6x6(this+0x1B14, &v37, v63, &v45, &v42);
    //     Matrix3x3VectorMultiply(*(this+0x15F0)+0x1C, &v45, &v60);
    //     AccumulateAngularMomentum(&v51, &v60);
    //     if (*(this+0x1BBC) && v39 < 0.0) {
    //       v11 = (v40*0x1BD0*v40 + v40*0x1BC8 + v41*0x1BD8 + 0x1BC0) * falloff(0x1BE0);
    //       if (v11 < 0.0) { build v60; Matrix3x3VectorMultiply(..., this+0x1BE8, &v51); AccumulateAngularMomentum(&v51, &v60); }
    //     }
    //     WheelContactForceSolver(this, this+0x1838, &v54);
    //     WheelContactForceSolver(this, this+0x189C, &v54);
    //     if (*(this+0x1900)) {
    //       if (!*(*(this+0x1F00)+0xCD4) || *(*(*(this+0x1F00)+0xCD4)+0x40)) {
    //         clamp ARB disp *(this+0x1908) to [0, *(this+0x1910)];
    //         *(this+0x19E0) = falloff(0x1940) * (*(this+0x1938)*disp + *(this+0x1930));
    //         QuadraticForm6x6(this+0x1960, &v37, v63, &v45, &v57);
    //         Matrix3x3VectorMultiply(..., &v45, &v60);
    //         AccumulateAngularMomentum(this+0x1918, &v60);
    //         v42 += v57; v43 += v58; v44 += v59;
    //       }
    //     }
    //     if (*(this+0x1A08)) {
    //       if (!*(*(this+0x1F00)+0xD18) || *(*(*(this+0x1F00)+0xD18)+0x40)) {
    //         *(this+0x1AB4) = falloff(0x1A14) * *(this+0x1A0C);
    //         QuadraticForm6x6(this+0x1A34, &v37, v63, &v45, &v57);
    //         Matrix3x3VectorMultiply(..., &v45, &v60);
    //         AccumulateAngularMomentum(&v51, &v60);
    //         v42 += v57; v43 += v58; v44 += v59;
    //       }
    //     }
    //     *(m+0x14C) += v43*0x24 + v44*0x2C + v42*0x1C;
    //     *(m+0x154) += v42*0x34 + v44*0x44 + v43*0x3C;
    //     *(m+0x15C) += v42*0x4C + v44*0x5C + v43*0x54;
    //   }
    // UNRESOLVED: Fields *(this+0x1F00)+0xD14 and +0xD58 are read per the deterministic fact table but do not appear in the decompiled body; their role in suspension/ARB state is unknown.
    // UNRESOLVED: Globals dbl_59E420, dbl_59E430 and dbl_59E880 are read per the deterministic fact table but absent from the decompiled body; they are likely constant-pool doubles (candidates: a 1.0 constant, a ~0.0 zero sentinel, and a half-step/lower-threshold constant) but the mapping is not proven here.
    // UNRESOLVED: Offsets this+0x1AFC (direction), +0x1B14 (first 6x6 matrix), +0x1BE8 (helper direction), +0x1838/+0x189C (wheel contact solver buffers), +0x1960/+0x1A34 (ARB 6x6 matrices) and +0x1A1C (second ARB direction) are dereferenced in the body but have no deterministic field entry; they remain raw-source-only evidence.
    // UNRESOLVED: Whether the ARB linked-object null/flag guards mean 'no linked car' or 'linked car ready' is ambiguous from this function alone.
}
