// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056B5D0
// Canonical corpus name: sub_56B5D0
// Owner: VehicleConstraintSolver [DERIVED]
// Raw source: functions/sub_56B5D0_0056b5d0.c

void VehicleConstraintSolver::AssembleJointConstraintMatrix()
{
    // Assembles the sparse symmetric constraint stiffness matrix for the vehicle physics constraint solver: reads the world-space inverse inertia tensor rows, builds inverse-inertia-weighted constraint columns for each joint entry (stride 132) and each contact entry (stride 88), and accumulates diagonal and off-diagonal 3x3 blocks into the sparse matrix addressed through the row-pointer table at this+0x228, adding or subtracting each block contribution according to the shared/opposed body-sign byte.
    // GUARD: Contact-constraint inner loop runs only while the contact count at this+0x23C (raw this+572) is positive; the raw source also gates the outer loop on the joint count at this+0x234, which the deterministic extractor did not record as a guard. [guard:0, field:this:0x0000023C, source:raw]
    // CALCULATION: Reads the nine world-space inverse inertia tensor values forming three rows of three doubles at this+0xEC through this+0x12C (offsets 236, 244, 252, 260, 268, 276, 284, 292, 300). [field:this:0x000000EC, field:this:0x000000F4, field:this:0x000000FC, field:this:0x00000104, field:this:0x0000010C, field:this:0x00000114, field:this:0x0000011C, field:this:0x00000124, field:this:0x0000012C]
    // LOOP: Outer loop over joint constraint entries in the buffer at this+0x238, stride 132, running while the index is below the joint count at this+0x234; for each entry it reads two constraint axis column triples (+72/+80/+88 and +96/+104/+112), the linked body id at +124 and the sign byte at +128. [field:this:0x00000238, field:this:0x00000234]
    // CALCULATION: Builds six inverse-inertia-weighted constraint columns: three terms (v52, v53, v54) as each inverse inertia row dotted with the first constraint column, and three terms (v49, v50, v51) as each inverse inertia row dotted with the second constraint column. [field:this:0x000000EC, field:this:0x000000F4, field:this:0x000000FC, field:this:0x00000104, field:this:0x0000010C, field:this:0x00000114, field:this:0x0000011C, field:this:0x00000124, field:this:0x0000012C]
    // ASSIGNMENT: Accumulates the diagonal 3x3 block for the current body id into the sparse matrix: three double entries at row bases fetched through the row-pointer table at this+0x228 (column offset 8*body) receive the weighted terms added to their existing values. [field:this:0x00000228, field:this:0x00000238]
    // LOOP: Off-diagonal pass over the remaining joints (stride 132): recomputes the three off-diagonal block terms for each later joint entry and, depending on whether the two sign bytes at +128 match, adds (equal) or subtracts (differ) the block into entry (v7,v16) or its transpose (v16,v7) via the row-pointer table at this+0x228. [field:this:0x00000228, field:this:0x00000238, field:this:0x00000234]
    // LOOP: Contact pass: iterates contact entries in the buffer at this+0x240, stride 88, while the index is below the contact count at this+0x23C; reads the linked body id at +48, the sign byte at +52 and constraint axis doubles at +24/+32/+40 and +64/+72/+80, computes triple-product-weighted terms, and adds or subtracts them into the matrix via the row-pointer table at this+0x228. [field:this:0x00000240, field:this:0x0000023C, field:this:0x00000228]
    // RETURN: Returns the joint constraint count read from this+0x234, the value that bounds the outer iteration. [field:this:0x00000234]

    // Conservative worker pseudocode:
    //   if (contactCount(this+0x23C) <= 0) return jointCount;
    //   for (i = 0; i < jointCount(this+0x234); i++) {
    //       row = invInertia(236,244,252,260,268,276,284,292,300);
    //       weighted = weightConstraintColumns(row, jointEntry(i));
    //       accumulateDiagonal(matrixTable(this+0x228), bodyId, weighted);
    //       for (j = i+1; j < jointCount; j++)
    //           accumulateOffDiagonal(matrixTable(this+0x228), bodyId(i), bodyId(j), signEq(i,j), weighted(j));
    //       for (c = 0; c < contactCount; c++)
    //           accumulateContact(matrixTable(this+0x228), bodyId(i), bodyId(c), signEq(i,c), weightedContact(c));
    //   }
    // UNRESOLVED: Exact packing of the 3x3 block within the per-body row block (three doubles stored, 8-byte stride) is not fully confirmed.
    // UNRESOLVED: Sign byte at joint+128 / contact+52 selects add versus subtract of block contributions; shared-versus-opposed body frame interpretation is inferred from code, not proven.
    // UNRESOLVED: Sparse matrix is indexed by body id through the row-pointer table at this+0x228; the full storage layout for arbitrary body pairs is unconfirmed.
    // UNRESOLVED: Raw source reads loop counts and buffers at offsets 564/568/572/576 which map to fields 0x234/0x238/0x23C/0x240; only the contact-count guard at 0x23C was recorded by the extractor.
}
