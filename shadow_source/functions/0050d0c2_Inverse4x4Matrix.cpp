// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050D0C2
// Canonical corpus name: F_4x4MatrixInverse
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4x4MatrixInverse_0050d0c2.c

void UnknownObject::Inverse4x4Matrix()
{
    // Computes the inverse of a 4x4 matrix by the cofactor/adjugate method. Reads the 16 input elements from a3, computes the 3x3-sub-determinant cofactors, combines them into the determinant v20, and optionally stores it through a2 when a2 is non-NULL. Computes the reciprocal v55 = 1/v20 and uses ArithmeticComparison_a88f on v55 to detect a singular matrix (zero reciprocal). When the matrix is invertible, writes the adjugate scaled by v55 into all 16 output elements of a1 and returns a1; otherwise returns 0 leaving a1 untouched.
    // CALCULATION: Reads the 16 input elements from a3 and computes the 3x3-sub-determinant cofactor products v51/v53/v34/v29/v30/v32 from the bottom-right 2x2 minors of the input matrix. [source:raw]
    // CALCULATION: Combines the cofactors into the first-row minor products v22..v28 and v35 (one per output column) using the input rows 2 and 3 (a3[2], a3[3], a3[6], a3[7], a3[10], a3[11], a3[15]). [source:raw]
    // CALCULATION: Combines the remaining cofactor minors into v50/v39/v37/v31 and v33/v42/v59/v63 (the second-row column products), using the input elements a3[0], a3[1], a3[4], a3[5], a3[8], a3[9], a3[12], a3[13], a3[14]. [source:raw]
    // CALCULATION: Determinant: v20 = v50 * a3[12] + v39 * a3[8] + v37 * a3[4] + v31 * a3[0] (sum of the first-row cofactor column products against the first input row). [source:raw]
    // GUARD: When a2 is non-NULL, store the computed determinant: *a2 = v20. [source:raw]
    // CALCULATION: Reciprocal of the determinant: v55 = 1.0 / v20. [source:raw]
    // CALL: ArithmeticComparison_a88f(v55 as 64-bit): compares the reciprocal determinant against zero to decide whether the matrix is singular; the boolean result gates the output write. [callee:0x0058A88F, source:raw]
    // STATE_TRANSITION: When the comparison reports a non-zero reciprocal (matrix invertible), write the adjugate scaled by v55 into all 16 output elements of a1 (a1[0..15] = adjugate * v55); otherwise a1 is left untouched. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, source:raw]
    // RETURN: Returns a1 (the output matrix pointer) on the invertible path, otherwise returns the comparison result 0. [source:raw]

    // Conservative worker pseudocode:
    //   read 16 input elements from a3;
    //   compute 3x3-sub-determinant cofactors from the 2x2 minors;
    //   det = v50*a3[12] + v39*a3[8] + v37*a3[4] + v31*a3[0];
    //   if (a2) *a2 = det;
    //   inv_det = 1.0 / det;
    //   if (ArithmeticComparison_a88f(inv_det) != 0) {
    //     adj[0..15] = cofactors;
    //     a1[i] = adj[i] * inv_det for i in 0..15;
    //     return a1;
    //   }
    //   return 0;
    // UNRESOLVED: The packet models the output a1 as the this base with 16 fields at 0x0..0x3C; the input matrix a3 is not modeled as fields, so the row/column assignment of the adjugate elements to a1[0..15] is inferred from the raw source order only.
    // UNRESOLVED: ArithmeticComparison_a88f's exact semantics (what it compares and returns) are not documented in the packet beyond the singular-matrix gate; the fill's 'compares reciprocal determinant against zero' reading is adopted at DERIVED trust.
}
