// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056AA60
// Canonical corpus name: sub_56AA60
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_56AA60_0056aa60.c

void UnknownObject::BuildConstraintStiffnessMatrixOffDiagonal()
{
    // Assembles the constraint stiffness block matrix for a physics constraint solver. For each entry of a first constraint array it computes nine cross-product terms between the entry's axis vector and the world-space inverse inertia tensor rows, accumulates the diagonal 3x3 block and the off-diagonal 3x3 blocks for every later first-array entry (upper triangle), then accumulates cross 3x3 blocks with every joint constraint and every contact constraint. All blocks are added into a symmetric sparse matrix whose row-pointer table is stored at this+0x228, indexed by constraint id, with add-vs-subtract sign selected by equality of the per-entry type byte. Runs on the per-frame physics tick, invoked by InertialTensorVectorTransform (0x0056A240).
    // ASSIGNMENT: Load the first-array constraint count from this+0x22C into v1 and initialize the row index v2 / v123 to 0 before the outer count check. [field:this:0x0000022C, source:raw]
    // GUARD: Outer guard on the first-array count: proceed only when (this+0x22C) > 0, otherwise return immediately without touching the matrix. [field:this:0x0000022C, source:raw]
    // LOOP: Outer loop over first-array constraint entries (buffer at this+0x230, stride 56). Each iteration reads the entry's axis components at element offsets +24/+32/+40, its id at +48 and its type byte at +52. [field:this:0x00000230, source:raw]
    // CALCULATION: Compute the nine cross-product terms v124..v132 from the row entry's axis vector and the world-space inverse inertia tensor rows at this+0xEC..this+0x12C (three doubles per row). [field:this:0x000000EC, field:this:0x000000F4, field:this:0x000000FC, field:this:0x00000104, field:this:0x0000010C, field:this:0x00000114, field:this:0x0000011C, field:this:0x00000124, field:this:0x0000012C, source:raw]
    // CALCULATION: Accumulate the diagonal 3x3 block for the row constraint id v7: add the per-row cross terms v108/v114/v12/v119/v120/v121 into the matrix row table at this+0x228 at row and column v7. [field:this:0x00000228, source:raw]
    // LOOP: Inner pair loop over first-array entries at or after the current row (column index v8, entry pointer v122 advancing by 56): compute the pair cross terms from the column entry's axis (including this+0xB4 as an additive offset term) for every constraint pair (v7, v19). [field:this:0x000000B4, field:this:0x00000230, source:raw]
    // CALCULATION: Off-diagonal pair block accumulation: add or subtract the computed 3x3 block into the matrix row table at this+0x228 indexed by the two constraint ids v7 and v19, with the sign chosen by whether the row entry's type byte v106 equals the column entry's type byte (+52). [field:this:0x00000228, source:raw]
    // GUARD: Guard on the joint-constraint count: run the joint accumulation loop only when (this+0x234) > 0. [field:this:0x00000234, guard:0, source:raw]
    // LOOP: Joint constraint accumulation loop over the buffer at this+0x238 (stride 132): for each joint entry compute the dot-product contributions of the row cross terms with the joint's axis components (offsets +72/+80/+88 and +96/+104/+112), then add or subtract the 3x3 block into the matrix row table at this+0x228 at row v7 and column joint id (+124), sign from joint type byte (+128) equality with the row entry. [field:this:0x00000238, field:this:0x00000228, source:raw]
    // GUARD: Guard on the contact-constraint count: run the contact accumulation loop only when (this+0x23C) > 0. [field:this:0x0000023C, guard:1, source:raw]
    // LOOP: Contact constraint accumulation loop over the buffer at this+0x240 (stride 88): for each contact entry compute the dot-product contributions of the row cross terms with the contact's axis components (offsets +24/+32/+40 and +64/+72/+80, with this+0xB4 added as an offset term), then add or subtract the 3x3 block into the matrix row table at this+0x228 at row v7 and column contact id (+48), sign from contact type byte (+52) equality with the row entry. [field:this:0x00000240, field:this:0x000000B4, field:this:0x00000228, source:raw]
    // STATE_TRANSITION: Advance the row index (v123 = ++v2), reload the first-array count from this+0x22C, and terminate when the row index reaches the count; otherwise continue with the next first-array entry. [field:this:0x0000022C, source:raw]
    // CALL: Invoked once per frame tick by InertialTensorVectorTransform (0x0056A240); this function performs the constraint stiffness block-matrix assembly for the vehicle physics constraint solver. [caller:0x0056A240, function:0x0056AA60, source:raw]

    // Conservative worker pseudocode:
    //   // Assemble the symmetric constraint stiffness block matrix.
    //   int count = *(int*)(this + 0x22C);          // first-array constraint count
    //   if (count <= 0) return;
    //   for (int r = 0; r < count; ++r) {
    //       char* A = (char*)*(int*)(this + 0x230) + r * 56;   // first-array entry
    //       // A axis (x,y,z) at +24/+32/+40, id at +48, type byte at +52
    //       // v124..v132 = cross products of A's axis with the inverse-inertia rows
    //       //              stored at this+0xEC .. this+0x12C
    //       // accumulate the diagonal 3x3 block for id(A) into matrix this+0x228
    //       for (int c = r + 1; c < count; ++c) {               // off-diagonal pairs
    //           char* B = (char*)*(int*)(this + 0x230) + c * 56;
    //           // accumulate or subtract the 3x3 block for pair (id(A), id(B))
    //           // sign depends on whether A and B share the same type byte
    //       }
    //       for (int j = 0; j < *(int*)(this + 0x234); ++j) {   // joint constraints
    //           // buffer this+0x238, stride 132, joint id at +124, type byte at +128
    //           // accumulate or subtract the 3x3 block for (id(A), jointId)
    //       }
    //       for (int k = 0; k < *(int*)(this + 0x23C); ++k) {   // contact constraints
    //           // buffer this+0x240, stride 88, contact id at +48, type byte at +52
    //           // accumulate or subtract the 3x3 block for (id(A), contactId)
    //           // contact cross terms add this+0xB4 as an offset
    //       }
    //   }
    // UNRESOLVED: The identity of the owning object is not established by the packet; the accumulated block matrix and the this+0x22C..0x240 constraint arrays are interpreted as a vehicle constraint solver, but this role is inferred from the existing analysis fill and call context, not proven here
    // UNRESOLVED: The exact physical meaning of this+0xB4 (interpreted as inverse mass in the existing analysis) is inferred; the packet only shows it added into the cross-product terms
    // UNRESOLVED: The type byte at first-array +52, joint +128 and contact +52 selects add-vs-subtract sign; its possible enum values are not documented in the packet
    // UNRESOLVED: Element sub-field layout of the three constraint buffers (axis/id/type positions and strides 56/132/88) is read directly from the raw decompiled source and is not independently confirmed
}
