## QRDecomposition_0053b6f0 — QRDecompose3x3

**Summary:** Performs QR decomposition on a 3x3 matrix using Givens rotations with up to 50 iterations for eigenvalue computation. Accumulates eigenvectors in the output matrix. Applies convergence thresholds and early exit when off-diagonal sum reaches zero. Part of physics/math library for matrix diagonalization.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_549470 (00549470), BoundingBoxComputationFromVertexData (0054e270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | input 3x3 matrix (first element a1[0]), source matrix being decomposed |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (~0.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (lower threshold constant) |
| 0059ea20 | dbl_59EA20 | R | QREpsilonThreshold [DERIVED] |
| 005b8970 | dbl_5B8970 | R | QRConvergenceThreshold [DERIVED] (early convergence threshold) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**
- Off-diagonal sum == 0.0: early exit (matrix already diagonalized)
- Iteration count >= 4: shift = 0 (pure QR); before iteration 4: shift = total * 0.0222 (Wilkinson shift)
- Sub-diagonal element zeroing: if |a[i][j]| < threshold (100 * |a[j][j]| comparison), treat as zero
- Max 50 iterations; loop exits after convergence
