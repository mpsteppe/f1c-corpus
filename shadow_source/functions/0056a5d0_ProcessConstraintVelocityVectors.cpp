// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056A5D0
// Canonical corpus name: sub_56A5D0
// Owner: VehicleConstraintSolver [DERIVED]
// Raw source: functions/sub_56A5D0_0056a5d0.c

void VehicleConstraintSolver::ProcessConstraintVelocityVectors()
{
    // Processes joint constraint velocity vectors for the vehicle physics constraint solver: forms a reference velocity by adding the traction-scaled angular velocity (dbl_5E5240 * omega) to the incoming constraint velocity vector, then for each joint entry (stride 132) transforms the constraint axis and the linked body's frame vector through their rotation matrices (Matrix3x3VectorMultiply), computes a normalized cross product scaled by dbl_5E5238, and accumulates or subtracts the weighted dot-product terms into the force buffer at this+0x224 indexed by body id.
    // CALCULATION: Computes the reference velocity offset: for each component adds the traction constant dbl_5E5240 times the angular velocity component (this+0x7C, this+0x84, this+0x8C) to the incoming constraint velocity vector a2. [global:0x005E5240, field:this:0x0000007C, field:this:0x00000084, field:this:0x0000008C]
    // GUARD: Iterates joint constraints only while the joint count at this+0x234 is positive; otherwise returns zero without touching the force buffer. [guard:0, field:this:0x00000234]
    // LOOP: Loops over joint constraint entries in the buffer at this+0x238, stride 132, while the index is below the joint count at this+0x234; for each entry reads the linked body id at +124, a frame descriptor field at +120 and the sign byte at +128. [field:this:0x00000238, field:this:0x00000234]
    // CALCULATION: Computes the triple-product scalar v17 = angular velocity dot (cross of the two constraint axis column triples read at +72/+80/+88 and +96/+104/+112) and the two omega-dot-column terms v25 and v26. [field:this:0x0000007C, field:this:0x00000084, field:this:0x0000008C, field:this:0x00000238]
    // CALL: Transforms the joint-frame axis vector (the current joint entry) by the 3x3 rotation matrix at this+28 via Matrix3x3VectorMultiply, when the sign byte is set. [callee:0x00435E00, field:this:0x00000238]
    // CALL: Transforms the linked body's frame vector by its own rotation matrix (rotation matrix and vector obtained through the descriptor at joint+120, dereferenced at +12 and +16) via Matrix3x3VectorMultiply, when the sign byte is set. [callee:0x00435E00, field:this:0x00000238]
    // CALL: Computes the cross product of the two transformed vectors and normalizes it via CrossProductNormalize, then scales the three result components by the traction-constant-squared global dbl_5E5238. [callee:0x0056C540, global:0x005E5238]
    // ASSIGNMENT: Accumulates the weighted velocity terms into the force buffer at this+0x224, indexed by body id with two double slots per entry: when the sign byte is set the weighted dot terms are subtracted from the buffer, when clear they are added, both cases folding in the omega-dot terms v25/v26 times v17. [field:this:0x00000224, field:this:0x00000238]
    // RETURN: Returns the number of joint constraints processed, which equals the joint count at this+0x234 when the loop ran. [field:this:0x00000234]

    // Conservative worker pseudocode:
    //   vRef = tractionConstant * angularVelocity + a2;
    //   if (jointCount(this+0x234) <= 0) return 0;
    //   for (i = 0; i < jointCount; i++) {
    //       entry = jointBuffer(this+0x238) + i*132;
    //       body = entry[124]; flag = entry[128];
    //       triple = omega . (cross(entryCol0, entryCol1));
    //       if (flag) {
    //           Matrix3x3VectorMultiply(this+28, entry, v27);
    //           Matrix3x3VectorMultiply(desc(entry[120])->rot+28, desc(entry[120])->vec, v28);
    //           CrossProductNormalize(v27 cross v28); scale by tractionConstantSq;
    //           force[body] -= dot(scaled, entryCols) - omegaDot * triple;
    //       } else {
    //           force[body] += vRef . entryCols - omegaDot * triple;
    //       }
    //   }
    //   return jointCount;
    // UNRESOLVED: The 3x3 rotation matrix at this+28 and the body-frame descriptor chain reached through joint+120 (dereferenced at +12 and +16) are only partially resolved.
    // UNRESOLVED: CrossProductNormalize operand order and the resulting axis convention are unconfirmed.
    // UNRESOLVED: Force buffer stride and the exact role of the two double slots per body are unconfirmed.
    // UNRESOLVED: The meanings of dbl_5E5238 (squared) versus dbl_5E5240 (base) as traction constants come from prior DERIVED prose, not runtime proof.
}
