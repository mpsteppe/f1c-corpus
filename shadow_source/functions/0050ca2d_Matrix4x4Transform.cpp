// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050CA2D
// Canonical corpus name: Matrix4x4Transform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Matrix4x4Transform_0050ca2d.c

void UnknownObject::Matrix4x4Transform()
{
    // Transforms a 4-component vector (a2) by a 4x4 row-major matrix (a3, 16 floats) and writes the resulting 4-component vector to a1 (this). Each output component is the dot product of one matrix row with the input vector; a1 is returned. No branches, calls, guards, or globals. The recovered ABI lead names the routine Matrix4x4Transform; the prelabel marks it a structural twin of the affine transform family.
    // CALCULATION: Compute output component 0: v4 = a2[0]*a3[0] + a2[1]*a3[4] + a2[2]*a3[8] + a2[3]*a3[12] (dot product of matrix row 0 with the input vector; first product written as a3[0]*a2[0]). [source:raw]
    // CALCULATION: Compute output component 1: v5 = a2[0]*a3[1] + a2[1]*a3[5] + a2[2]*a3[9] + a2[3]*a3[13] (dot product of matrix row 1 with the input vector). [source:raw]
    // CALCULATION: Compute output component 2: v6 = a2[0]*a3[2] + a2[1]*a3[6] + a2[2]*a3[10] + a2[3]*a3[14] (dot product of matrix row 2 with the input vector). [source:raw]
    // CALCULATION: Compute output component 3: v7 = a2[0]*a3[3] + a2[1]*a3[7] + a2[2]*a3[11] + a2[3]*a3[15] (dot product of matrix row 3 with the input vector). [source:raw]
    // ASSIGNMENT: Store computed component 0 into this+0x0 (*a1 = v4). [source:raw, field:this:0x00000000]
    // ASSIGNMENT: Store computed component 1 into this+0x4 (a1[1] = v5). [source:raw, field:this:0x00000004]
    // ASSIGNMENT: Store computed component 2 into this+0x8 (a1[2] = v6). [source:raw, field:this:0x00000008]
    // ASSIGNMENT: Store computed component 3 into this+0xC (a1[3] = v7). [source:raw, field:this:0x0000000C]
    // RETURN: Return the output vector pointer a1 (this); the recovered ABI lead names the routine Matrix4x4Transform. [source:raw, function:0x0050CA2D, abi:lead]

    // Conservative worker pseudocode:
    //   // a1 = this (output 4-vector); a2 = input 4-vector; a3 = 4x4 row-major matrix
    //   a1[0] = a2[0]*a3[0] + a2[1]*a3[4] + a2[2]*a3[8]  + a2[3]*a3[12];
    //   a1[1] = a2[0]*a3[1] + a2[1]*a3[5] + a2[2]*a3[9]  + a2[3]*a3[13];
    //   a1[2] = a2[0]*a3[2] + a2[1]*a3[6] + a2[2]*a3[10] + a2[3]*a3[14];
    //   a1[3] = a2[0]*a3[3] + a2[1]*a3[7] + a2[2]*a3[11] + a2[3]*a3[15];
    //   return a1;
    // UNRESOLVED: Concrete struct types of the two input pointers (a2 vector, a3 matrix) are not described by packet evidence; only their float-array indexing pattern is known.
    // UNRESOLVED: Row-major matrix layout is inferred from the stride-4 index pattern (rows at a3[0..3], a3[4..7], a3[8..11], a3[12..15]); it is not independently confirmed.
    // UNRESOLVED: canonical_name Matrix4x4Transform carries LEGACY ABI trust only; no runtime or cross-reference evidence in the packet confirms the name.
    // UNRESOLVED: The prelabel records a cluster-copy structural twin relationship to 0050c525; no evidence ref for that relation is in the allowed set, so it is not used as a fact.
}
