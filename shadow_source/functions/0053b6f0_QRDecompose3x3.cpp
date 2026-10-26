// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053B6F0
// Canonical corpus name: QRDecomposition
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QRDecomposition_0053b6f0.c

void UnknownObject::QRDecompose3x3()
{
    // QR decomposition of a 3x3 double matrix a1 using Givens rotations over at most 50 iterations, writing results through pointer-offset arithmetic into the output matrices a2 and a3. a3 is first initialized to a 3x3 identity (each row a double 0.0 / 1.0-bit-pattern 1072693248), and a1 is copied into the working buffers and into a2. Each iteration sums the absolute values of the off-diagonal entries of a1 and exits early when that sum is zero; otherwise a shift (0.0 after iteration 4, else the sum * 0.02222222222222222) selects a rotation tolerance, off-diagonal pairs below the 100.0 * |value| threshold are zeroed, and Givens coefficients built from sqrt/1.0/0.5 are applied to the rows and columns of the matrices. Eigenvector/sum contributions are accumulated across iterations into the working buffers and written back through a2. Called from sub_549470 and BoundingBoxComputationFromVertexData on the per-frame path.
    // ASSIGNMENT: Initialize a3 as a 3x3 identity matrix: for each of 3 rows memset a 24-byte slot to 0 and write the first dword 0 with the second dword 1072693248 (double 1.0 bit pattern). [source:raw, function:0x0053B6F0, abi:lead]
    // LOOP: Copy the 3x3 input matrix a1 (first element tracked by the field at this+0) into the local buffers v71/v72 and into the working matrix a2 via pointer-offset writes, three columns per row. [field:this:0x00000000, source:raw, function:0x0053B6F0]
    // LOOP: Outer iteration loop over i in 0..49 (up to 50 QR iterations). [source:raw, function:0x0053B6F0]
    // CALCULATION: Compute v12 as the sum of fabs() of the off-diagonal entries of a1; if the sum equals 0.0, break out of the iteration loop (matrix already diagonal). [source:raw, function:0x0053B6F0]
    // CALCULATION: Select the shift v18: 0.0 when the iteration index is >= 4, otherwise v12 * 0.02222222222222222. [source:raw, function:0x0053B6F0]
    // LOOP: Nested Givens sweep over the lower-triangle entries: for each off-diagonal pair, if the iteration is past 4 and the value is unchanged under a 100.0 * |value| perturbation, zero the 8-byte pair; otherwise if |entry| exceeds the shift, compute and apply a rotation. [source:raw, function:0x0053B6F0]
    // CALCULATION: Build the Givens coefficients: ratio v29 from the diagonal difference or from 1.0 / (sqrt(v69*v69 + 1.0) + fabs(v69)) with sign flip, then v30 = 1.0 / sqrt(v29*v29 + 1.0), v67 = v30*v29 and v70 = v67 / (v30 + 1.0). [source:raw, function:0x0053B6F0]
    // ASSIGNMENT: Apply the rotation to matrix rows and columns in a1, a2 and a3 through pointer-offset arithmetic (a1-relative, a2-relative and a3-relative mappings), zeroing each processed off-diagonal 8-byte pair. [source:raw, function:0x0053B6F0]
    // ASSIGNMENT: At the end of each iteration accumulate the per-column contributions v71[j] += v72[j] for j in 0..2 and write the sum back through the a2 offset mapping. [source:raw, function:0x0053B6F0]

    // Conservative worker pseudocode:
    //   a3 = identity(3);
    //   v71, v72 = copy(a1); a2 = copy(a1);
    //   for (i = 0; i < 50; ++i) {
    //     offDiagSum = sum(|a1[r][c]|, r != c);
    //     if (offDiagSum == 0.0) break;
    //     shift = i >= 4 ? 0.0 : offDiagSum * 0.02222222222222222;
    //     // Givens sweep over lower-triangle entries; zero or rotate each pair
    //     accumulate(v71, v72); write through a2;
    //   }
    // UNRESOLVED: The read-only globals dbl_59E420, dbl_59E430, dbl_59E880, dbl_59EA20 and dbl_5B8970 have no visible direct use in the decompiled body; every threshold and constant (1.0, 0.0, 0.5, 100.0, 0.02222222222222222) appears inline, so the globals likely back those literals or are consumed in collapsed paths.
    // UNRESOLVED: The exact meaning of each output matrix (eigenvalues vs eigenvectors, and how a1 remains the input while a2/a3 receive rotations) is not fully recoverable from the packet; the pointer-offset arithmetic obscures which physical matrix each write lands in.
    // UNRESOLVED: The convergence tolerance constants and the 50-iteration cap are evidenced in the code, but their numerical thresholds are not independently grounded.
    // UNRESOLVED: No callees other than the compiler runtime helpers (fabs, sqrt via the literal callbacks) are visible; the function relies on FPU operations only.
}
