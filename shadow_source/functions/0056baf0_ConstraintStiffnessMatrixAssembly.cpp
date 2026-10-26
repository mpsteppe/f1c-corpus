// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056BAF0
// Canonical corpus name: ConstraintStiffnessMatrixAssembly
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstraintStiffnessMatrixAssembly_0056baf0.c

void UnknownObject::ConstraintStiffnessMatrixAssembly()
{
    // Assembles diagonal and off-diagonal blocks of a sparse constraint stiffness matrix for a contact-constraint solver. Iterates the constraint entries (stride 88) from this+0x240, computing cross products of constraint axes, transforming them through the world inverse inertia tensor (this+0xEC) via Matrix3x3VectorMultiply, scaling by inverse mass (this+0xB4), and accumulating into the sparse block matrix reached through the row-pointer table at this+0x228. Called by InertialTensorVectorTransform.
    // ASSIGNMENT: Read the constraint count from this+0x23C as the loop bound and initial result value. [source:raw, field:this:0x0000023C, function:0x0056BAF0]
    // GUARD: Guard on count > 0; when zero the function returns immediately without touching the matrix. [source:raw, field:this:0x0000023C]
    // LOOP: Outer loop over constraint rows (index v3), walking the entry buffer at this+0x240 with a byte stride of 88 per entry. [source:raw, field:this:0x00000240]
    // CALCULATION: Load per-entry fields: axis component doubles at +24/+32/+40/+64/+72/+80, an index dword v8 at +48 and a type byte v33 at +52 relative to the entry base. [source:raw, field:this:0x00000240]
    // CALCULATION: Compute the three cross-product components of the constraint axes into v42[0..2] from products of the +24/+32/+40 and +64/+72/+80 doubles. [source:raw, field:this:0x00000240]
    // CALL: Call Matrix3x3VectorMultiply(world inverse inertia at this+0xEC, cross-product v42, out v36) to transform the cross product into world space. [source:raw, callee:0x00435E00, field:this:0x00000228]
    // CALCULATION: Scale axis components by the inverse mass (this+0xB4) into v39/v40/v41 and assemble the diagonal block contribution v13/v14 from the transformed v36/v37/v38 and the entry axes. [source:raw, field:this:0x000000B4]
    // ASSIGNMENT: Resolve the diagonal matrix element via the row-pointer table at this+0x228 (indexed by v8) plus 8*v8, and accumulate the computed block into it. [source:raw, field:this:0x00000228, field:this:0x000000B4]
    // LOOP: Inner loop over subsequent constraints j (byte stride 88) while the row index is below the count, for the off-diagonal blocks. [source:raw, field:this:0x0000023C, field:this:0x00000240]
    // CALCULATION: Compute the off-diagonal coupling term v25 between row i (index v8) and column j (index v24) from the transformed axes and the other entry's axis components. [source:raw, field:this:0x00000240]
    // GUARD: Branch on whether the two entries share the same type byte (v33 == entry+52): additive for matching types, subtractive otherwise. [source:raw, field:this:0x00000240]
    // ASSIGNMENT: Accumulate the off-diagonal block: add v25 to the symmetric element when types match, else subtract it, addressing the sparse cell (row, col) through the this+0x228 row-pointer table using the smaller of v8/v24 as one index. [source:raw, field:this:0x00000228]
    // RETURN: Return the last row index, consumed by the caller InertialTensorVectorTransform. [source:raw, caller:0x0056A240]

    // Conservative worker pseudocode:
    //   int sub_56BAF0(int this) {
    //     int count = *(_DWORD*)(this + 572);
    //     if (count <= 0) return count;
    //     int i = 1;
    //     int off = 0;
    //     do {
    //       int base = *(_DWORD*)(this + 576) + off;
    //       double c[3] = { cross(axis0(base), axis1(base)) };
    //       Matrix3x3VectorMultiply((double*)(this + 236), c, &out);
    //       // assemble diagonal block using inverse mass (this+180), accumulate at this+552 table
    //       if (i < count) {
    //         for (int j = off + 88; j < count * 88; j += 88) {
    //           double term = coupling(out, other_entry);
    //           if (type(base) == type(other)) add; else subtract;
    //         }
    //       }
    //       off += 88;
    //     } while (i++ < count);
    //     return i;
    //   }
    // UNRESOLVED: Meaning of the type byte at entry+52 (contact vs non-contact) that selects add/subtract accumulation is DERIVED from control flow, not confirmed.
    // UNRESOLVED: The precise sparse-matrix layout behind the row-pointer table at this+0x228 and the 8-byte element size are inferred from indexing, not confirmed.
    // UNRESOLVED: Entry stride 88 and the axis field layout within each 88-byte constraint record are inferred from the loop arithmetic.
}
