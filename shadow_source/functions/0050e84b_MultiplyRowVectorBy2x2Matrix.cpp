// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E84B
// Canonical corpus name: ArithmeticComparison_e84b
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_e84b_0050e84b.c

void UnknownObject::MultiplyRowVectorBy2x2Matrix()
{
    // Element-wise 2x2 transform: writes two floats into the output pointer a1 (offsets 0 and 4) computed as a row-vector times a 2x2 matrix, where the matrix is read through a3 with a column stride of 4 floats (a3[0], a3[1] and a3[4], a3[5]) and the input vector is read through a2. Returns the output pointer a1 unchanged.
    // CALCULATION: Compute v6 = a3[4] * a2[1] + a2[0] * a3[0], the first output component. [source:raw]
    // CALCULATION: Compute v3 = a3[1] * a2[0], the first term of the second output component. [source:raw]
    // CALCULATION: Compute v4 = a3[5] * a2[1], the second term of the second output component. [source:raw]
    // ASSIGNMENT: Write v6 to a1[0], the output float at field offset 0. [field:this:0x00000000, source:raw]
    // CALCULATION: Compute v7 = v3 + v4 to form the second output component. [source:raw]
    // ASSIGNMENT: Write v7 to a1[1], the output float at field offset 4. [field:this:0x00000004, source:raw]
    // RETURN: Return the output pointer a1 unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   float *sub_50E84B(float *out, float *vec, float *mat) {
    //     float c0 = mat[4] * vec[1] + vec[0] * mat[0];
    //     float c1 = mat[1] * vec[0] + mat[5] * vec[1];
    //     out[0] = c0;
    //     out[1] = c1;
    //     return out;
    //   }
    // UNRESOLVED: The physical meaning of the input vector and matrix elements is unknown; the abi label 'Arithmetic_Comparison_2x2_Matrix_Multiply' supports a matrix-multiply reading but the non-contiguous 4-float column stride of a3 is not proven to be a rotation or any other geometric transform.
    // UNRESOLVED: The DERIVED structural-twin prelabel (FlagSetterWithOR, 004a3560) describes a flag-setting behavior that does not match this arithmetic body; the cluster-copy label appears to be a mislabel and is not adopted.
}
