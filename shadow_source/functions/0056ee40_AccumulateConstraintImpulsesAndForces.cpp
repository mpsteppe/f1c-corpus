// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056EE40
// Canonical corpus name: sub_56EE40
// Owner: ConstraintForceAccumulator [DERIVED]
// Raw source: functions/sub_56EE40_0056ee40.c

void ConstraintForceAccumulator::AccumulateConstraintImpulsesAndForces()
{
    // Accumulates angular momentum and force contributions from constraint rows across three body groups (wheel, suspension, constraint). Each group reads per-body state entries from a shared state vector pointer (this+0x2C) and applies scaled 3D vectors into paired body force/impulse accumulator slots via AccumulateAngularMomentum and F_3DVectorSubtractWithCrossProduct.
    // GUARD: Wheel group: enter when wheel body count this[2] (this+0x8) is greater than 0 [guard:0, field:this:0x00000008, source:raw]
    // LOOP: Iterate wheel bodies in the array this[3] (this+0xC) with stride 48; for each body, resolve its constraint id at +8 and use it to index the state vector this[11] (this+0x2C) to build a 3D vector [field:this:0x0000000C, field:this:0x0000002C, source:raw]
    // CALL: AccumulateAngularMomentum(body, body+24, vector) per wheel body (0x00569AD0) [callee:0x00569AD0, source:raw]
    // CALL: F_3DVectorSubtractWithCrossProduct(body, body+24, vector) per wheel body (0x00569B70) [callee:0x00569B70, source:raw]
    // GUARD: Suspension group: enter when suspension body count this[4] (this+0x10) is greater than 0 [guard:1, field:this:0x00000010, source:raw]
    // LOOP: Iterate suspension bodies in the array this[5] (this+0x14) with stride 48; combine state vector entries (this+0x2C) with per-body coefficient rows (offsets 72/80/88/96/104/112) and accumulate the weighted result into a body force slot at +332, subtracting the paired weighted result from the partner body force slot [field:this:0x00000014, field:this:0x0000002C, source:raw]
    // CALCULATION: Constraint group: scale the state vector entry (this+0x2C) by constraint coefficients (offsets 64/72/80) to form the applied impulse vector [field:this:0x0000002C, source:raw]
    // LOOP: Iterate constraints in the array this[7] (this+0x1C) with stride 72 while the index is below the constraint count this[6] (this+0x18) [field:this:0x00000018, field:this:0x0000001C, source:raw]
    // CALL: AccumulateAngularMomentum(body, constraint+24, scaled vector) per constraint (0x00569AD0) [callee:0x00569AD0, source:raw]
    // CALL: F_3DVectorSubtractWithCrossProduct(body, body+24, scaled vector) per constraint (0x00569B70) [callee:0x00569B70, source:raw]
    // RETURN: Return the constraint count this[6] [field:this:0x00000018, source:raw]

    // Conservative worker pseudocode:
    //   // for wheel in this[3][0..this[2]): vec = state[this[11], id]; AccumulateAngularMomentum(wheel, wheel+24, vec); F_3DVectorSubtractWithCrossProduct(wheel, wheel+24, vec)
    //   // for susp in this[5][0..this[4]): add weighted state rows to body force slot +332, subtract weighted rows from partner body slot
    //   // for c in this[7][0..this[6]): scale state entry by coefficients; AccumulateAngularMomentum and F_3DVectorSubtractWithCrossProduct
    // UNRESOLVED: Exact body struct layout (offsets 24, 332, and the coefficient rows 64/72/80/88/96/104/112) comes from raw indexing; field semantics are DERIVED
    // UNRESOLVED: Owner class ConstraintForceAccumulator is an abi lead (LEGACY trust) and is not independently confirmed
}
