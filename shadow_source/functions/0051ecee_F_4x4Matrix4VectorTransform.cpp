// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051ECEE
// Canonical corpus name: F_4x4Matrix4VectorTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4x4Matrix4VectorTransform_0051ecee.c

void UnknownObject::F_4x4Matrix4VectorTransform()
{
    // 4x4 matrix times 3-component vector transform. Multiplies the matrix at a3 by the vector at a2 and stores the result in a1. The (a3 & 0xF) guard selects between aligned (columns at +0, +16, +32, +48) and unaligned (columns at +8, +24, +40, +56) column loads; each output lane is the sum of three column-by-component products plus the matrix translation column.
    // GUARD: Test (a3 & 0xF) to branch between the aligned and unaligned matrix column load paths. [source:raw]
    // CALCULATION: Load the input vector (three components) from a2 and splat each component across the SIMD lanes. [source:raw]
    // CALCULATION: For each matrix column, multiply the column by the corresponding vector component and accumulate the three products. [source:raw]
    // CALCULATION: Add the translation column (fourth column) to the accumulated product. [source:raw]
    // ASSIGNMENT: Store the transformed vector into the output pointer a1 (this field 0). [field:this:0x00000000]
    // RETURN: Return the output pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   if ((matrix & 0xF) != 0)
    //     load columns at +8, +24, +40, +56;
    //   else
    //     load columns at +0, +16, +32, +48;
    //   out = col[0] * v.x + col[1] * v.y + col[2] * v.z + col[3];
    //   *a1 = out; return a1;
    // UNRESOLVED: The packet prelabel assigns this function as a structural twin of FloatClamp (004646c0), but the matrix-vector multiply shape does not match clamping semantics; the cluster-copy label is treated as DERIVED and not relied on.
    // UNRESOLVED: Whether the matrix is row-major or column-major is not determinable from this function alone; the column offsets are reported exactly as they appear in the source.
}
