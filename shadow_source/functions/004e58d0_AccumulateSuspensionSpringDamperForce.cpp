// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E58D0
// Canonical corpus name: sub_4E58D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4E58D0_004e58d0.c

void UnknownObject::AccumulateSuspensionSpringDamperForce()
{
    // Per-frame suspension spring/damper force accumulation for one suspension corner. Computes a gravity-scaled force from this[0x3514] * -9.81 and projects it into the local frame via the rotation matrix at 0x34B0..0x34D0, derives the displacement vector as the suspension mount position (0x34F8..0x3500) minus the rotated rest anchor (0x3A58..0x3A60), squares each component, combines each squared displacement with its axis stiffness (0x3A64/0x3A68/0x3A6C) using FCOM-flag-dependent add/subtract, and in one axis folds an extra cross-coupling term (0x3A70/0x3A74) into this[0x3558]; the three per-axis results are accumulated into this[0x354C]/this[0x3550]/this[0x3554]. No callees. Invoked from PhysicsIntegrationStateMachine (0x004E4E60).
    // CALCULATION: Compute the gravity-scaled force v1 = this[0x3514] * -9.81. [field:this:0x00003514, source:raw]
    // CALCULATION: Project the gravity force into the local frame using the rotation matrix columns at 0x34B0..0x34D0, producing v27/v28/v29 (the decompiler's zero-weighted matrix terms are preserved). [field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, source:raw]
    // CALCULATION: Derive the displacement vector v23/v2/v3 as the suspension mount position (0x34F8..0x3500) minus the rest anchor (0x3A58..0x3A60) rotated by the matrix; the anchor dot products use 0x34B8/0x34C4/0x34D0 with 0x3A58..0x3A60. [field:this:0x000034F8, field:this:0x000034FC, field:this:0x00003500, field:this:0x00003A58, field:this:0x00003A5C, field:this:0x00003A60, source:raw]
    // CALCULATION: Square each displacement component: v24 = v23*v23, v25 = v2*v2, v26 = v3*v3. [source:raw]
    // CALCULATION: Combine each squared displacement with its axis stiffness coefficient (0x3A64/0x3A68/0x3A6C) and the projected gravity terms; the add/subtract sign is selected by the FCOM flag results v6|v7, v11|v12, v16|v17 producing v8/v13/v18. [field:this:0x00003A64, field:this:0x00003A68, field:this:0x00003A6C, source:raw]
    // CALCULATION: When the third FCOM branch passes, fold an extra cross-coupling term into this[0x3558]: this[0x3558] += (v26 * this[0x3A70]) * this[0x3A74]. [field:this:0x00003558, field:this:0x00003A70, field:this:0x00003A74, source:raw]
    // CALCULATION: Accumulate the per-axis results into the output fields: this[0x354C] += v8, this[0x3550] += v13, this[0x3554] += v18. [field:this:0x0000354C, field:this:0x00003550, field:this:0x00003554, source:raw]
    // CALL: Invoked from PhysicsIntegrationStateMachine (0x004E4E60) on the per-frame physics tick. [caller:0x004E4E60]

    // Conservative worker pseudocode:
    //   void AccumulateSuspensionSpringDamperForce(float* this) {
    //     v1 = this[0x3514] * -9.81;
    //     v27 = v1 * this[0x34BC] + this[0x34C8]*0.0 + this[0x34B0]*0.0;
    //     v28 = v1 * this[0x34C0] + this[0x34CC]*0.0 + this[0x34B4]*0.0;
    //     v29 = v1 * this[0x34C4] + this[0x34D0]*0.0 + this[0x34B8]*0.0;
    //     v30 = this[0x34D0]*this[0x3A60] + this[0x34C4]*this[0x3A5C] + this[0x34B8]*this[0x3A58];
    //     v23 = this[0x34F8] - (rotated anchor X);
    //     v2  = this[0x34FC] - (rotated anchor Y);
    //     v3  = this[0x3500] - v30;
    //     v24 = v23*v23; v25 = v2*v2; v26 = v3*v3;
    //     v8  = sign(v6|v7) ? v24*this[0x3A64] + v27 : v27 - v24*this[0x3A64];
    //     v13 = sign(v11|v12) ? v25*this[0x3A68] + v28 : v28 - v25*this[0x3A68];
    //     if (v16|v17) { v18 = v26*this[0x3A6C] + v29; this[0x3558] += (v26*this[0x3A70]) * this[0x3A74]; }
    //     else v18 = v29 - v26*this[0x3A6C];
    //     this[0x354C] += v8;
    //     this[0x3550] += v13;
    //     this[0x3554] += v18;
    //   }
    // UNRESOLVED: Globals flt_59E440 and dbl_59ED50 are read per the deterministic fact table but do not appear in the decompiled body; they likely supply the -9.81 gravity and ~0.0 literals, but the mapping is not proven.
    // UNRESOLVED: The conditional sign flips (v6|v7, v11|v12, v16|v17) are FCOM flag results from the squared-displacement comparisons, not deliberate guard branches; the decompiler does not expose the underlying comparison operands.
    // UNRESOLVED: The owning class is unknown; the object layout (rotation matrix, mount position, rest anchor, stiffness coefficients) is inferred from field offsets only.
}
