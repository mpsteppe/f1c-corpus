// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005175F4
// Canonical corpus name: sub_5175F4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5175F4_005175f4.c

void UnknownObject::TransformVectorByMatrix()
{
    // 3-element vector-matrix transform: each output component is the dot product of input vector a2 with one 3-float column of matrix a3 (columns laid out with a 4-float stride), storing a1[0] at this+0x0, a1[1] at this+0x4, a1[2] at this+0x8, then returning a1.
    // CALCULATION: Compute output component 0: *a2*a3[0] + a2[1]*a3[4] + a2[2]*a3[8] (dot of a2 with matrix column 0). [source:raw]
    // CALCULATION: Compute intermediate v3: *a2*a3[1] + a2[1]*a3[5] + a2[2]*a3[9] (dot of a2 with matrix column 1). [source:raw]
    // CALCULATION: Compute intermediate v4: *a2*a3[2] + a2[1]*a3[6] + a2[2]*a3[10] (dot of a2 with matrix column 2). [source:raw]
    // ASSIGNMENT: Store output component 0 into this+0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store output component 1 (v3) into this+0x4. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Store output component 2 (v4) into this+0x8. [field:this:0x00000008, source:raw]
    // RETURN: Return the output vector a1. [function:0x005175F4, source:raw]

    // Conservative worker pseudocode:
    //   float* sub_5175F4(float* a1, float* a2, float* a3) {
    //     a1[0] = a2[0]*a3[0] + a2[1]*a3[4] + a2[2]*a3[8];
    //     a1[1] = a2[0]*a3[1] + a2[1]*a3[5] + a2[2]*a3[9];
    //     a1[2] = a2[0]*a3[2] + a2[1]*a3[6] + a2[2]*a3[10];
    //     return a1;
    //   }
    // UNRESOLVED: Whether a3 is row-major (result is transpose product) or column-major cannot be determined from this function alone.
    // UNRESOLVED: The fourth float of each matrix row (stride 4) is not read here; its role depends on the caller.
    // UNRESOLVED: The cluster-copy prelabel describing this as a structural twin of TripleFieldSetter_6280 conflicts with the math in the raw source; the raw source interpretation is retained.
}
