// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056C740
// Canonical corpus name: F_33MatrixMultiply
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_33MatrixMultiply_0056c740.c

void UnknownObject::Matrix33Multiply()
{
    // Multiplies two 3x3 matrices a1 and a2 (each nine doubles at offsets 0x0..0x40) and stores the result in a3. Each of the nine output entries is a dot product of one row of a1 with one column of a2. Returns the unmodified output pointer a3. Structural twin of Matrix3x3VectorMultiply (00435e00) per cluster_copy prelabel. Called from suspension and collision transform paths.
    // ASSIGNMENT: result = a3, so the caller receives back the output matrix pointer. [source:raw]
    // CALCULATION: a3[0] = a1[0]*a2[0] + a1[1]*a2[3] + a1[2]*a2[6]: row 0 of a1 times column 0 of a2. [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, source:raw]
    // CALCULATION: a3[1] = a1[0]*a2[1] + a1[1]*a2[4] + a1[2]*a2[7]: row 0 of a1 times column 1 of a2. [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, source:raw]
    // CALCULATION: a3[2] = a1[0]*a2[2] + a1[1]*a2[5] + a1[2]*a2[8]: row 0 of a1 times column 2 of a2. [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, source:raw]
    // CALCULATION: a3[3] = a1[3]*a2[0] + a1[4]*a2[3] + a1[5]*a2[6]: row 1 of a1 times column 0 of a2. [field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, source:raw]
    // CALCULATION: a3[4] = a1[3]*a2[1] + a1[4]*a2[4] + a1[5]*a2[7]: row 1 of a1 times column 1 of a2. [field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, source:raw]
    // CALCULATION: a3[5] = a1[3]*a2[2] + a1[4]*a2[5] + a1[5]*a2[8]: row 1 of a1 times column 2 of a2. [field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, source:raw]
    // CALCULATION: a3[6] = a1[6]*a2[0] + a1[7]*a2[3] + a1[8]*a2[6]: row 2 of a1 times column 0 of a2. [field:this:0x00000030, field:this:0x00000038, field:this:0x00000040, source:raw]
    // CALCULATION: a3[7] = a1[6]*a2[1] + a1[7]*a2[4] + a1[8]*a2[7]: row 2 of a1 times column 1 of a2. [field:this:0x00000030, field:this:0x00000038, field:this:0x00000040, source:raw]
    // CALCULATION: a3[8] = a1[6]*a2[2] + a1[7]*a2[5] + a1[8]*a2[8]: row 2 of a1 times column 2 of a2. [field:this:0x00000030, field:this:0x00000038, field:this:0x00000040, source:raw]
    // RETURN: Return result, which is the unmodified a3 pointer. [source:raw]

    // Conservative worker pseudocode:
    //   double *sub_56C740(double *a, double *b, double *out) {
    //     out[0] = a[0]*b[0] + a[1]*b[3] + a[2]*b[6];
    //     out[1] = a[0]*b[1] + a[1]*b[4] + a[2]*b[7];
    //     out[2] = a[0]*b[2] + a[1]*b[5] + a[2]*b[8];
    //     out[3] = a[3]*b[0] + a[4]*b[3] + a[5]*b[6];
    //     out[4] = a[3]*b[1] + a[4]*b[4] + a[5]*b[7];
    //     out[5] = a[3]*b[2] + a[4]*b[5] + a[5]*b[8];
    //     out[6] = a[6]*b[0] + a[7]*b[3] + a[8]*b[6];
    //     out[7] = a[6]*b[1] + a[7]*b[4] + a[8]*b[7];
    //     out[8] = a[6]*b[2] + a[7]*b[5] + a[8]*b[8];
    //     return out;
    //   }
    // UNRESOLVED: Row-major layout is inferred from the index pattern; a column-major interpretation is equally compatible with the field offsets.
    // UNRESOLVED: Caller 0x0056F100 (sub_56F100) is unnamed; the transform semantics in the collision path depend on it.
    // UNRESOLVED: The cluster_copy prelabel names 00435e00 as a structural twin, but that equivalence was not verified here.
}
