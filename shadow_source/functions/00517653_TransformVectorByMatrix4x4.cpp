// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00517653
// Canonical corpus name: sub_517653
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_517653_00517653.c

void UnknownObject::TransformVectorByMatrix4x4()
{
    // Multiplies a 4-component vector (a2) by a 4x4 matrix stored as a flat 16-float array (a3, row-major stride 4) and stores the result in a1. Returns a1. Structural twin of F_4DAffineTransform (0050c525) per packet prelabel.
    // CALCULATION: Compute v3 = a2[0]*a3[1] + a2[1]*a3[5] + a2[2]*a3[9] + a2[3]*a3[13] (second output component, row 1 of matrix). [function:0x00517653, source:raw]
    // CALCULATION: Compute v4 = a2[0]*a3[2] + a2[1]*a3[6] + a2[2]*a3[10] + a2[3]*a3[14] (third output component, row 2 of matrix). [function:0x00517653, source:raw]
    // CALCULATION: Compute v5 = a2[0]*a3[3] + a2[1]*a3[7] + a2[2]*a3[11] + a2[3]*a3[15] (fourth output component, row 3 of matrix). [function:0x00517653, source:raw]
    // ASSIGNMENT: a1[0] = a2[0]*a3[0] + a2[1]*a3[4] + a2[2]*a3[8] + a2[3]*a3[12] (first output component, row 0 of matrix). [field:this:0x00000000, function:0x00517653, source:raw]
    // ASSIGNMENT: a1[1] = v3 (second output component). [field:this:0x00000004, function:0x00517653, source:raw]
    // ASSIGNMENT: a1[2] = v4 (third output component). [field:this:0x00000008, function:0x00517653, source:raw]
    // ASSIGNMENT: a1[3] = v5 (fourth output component). [field:this:0x0000000C, function:0x00517653, source:raw]
    // RETURN: Return a1 (output vector). [function:0x00517653, source:raw]

    // Conservative worker pseudocode:
    //   float* TransformVectorByMatrix4x4(float* out, const float* v, const float* m) {
    //     out[0] = v[0]*m[0]  + v[1]*m[4]  + v[2]*m[8]  + v[3]*m[12];
    //     out[1] = v[0]*m[1]  + v[1]*m[5]  + v[2]*m[9]  + v[3]*m[13];
    //     out[2] = v[0]*m[2]  + v[1]*m[6]  + v[2]*m[10] + v[3]*m[14];
    //     out[3] = v[0]*m[3]  + v[1]*m[7]  + v[2]*m[11] + v[3]*m[15];
    //     return out;
    //   }
    // UNRESOLVED: Whether a3 is row-major (out = M * v, as reconstructed) or column-major (out = v * M) is not proven by this packet alone; stride-4 layout is certain, orientation is not.
    // UNRESOLVED: Semantics of a2[3] (homogeneous w) are unknown; the vector may be a point (w=1) or direction (w=0).
    // UNRESOLVED: No caller evidence links this helper to a specific object class, so owner stays UnknownObject/UNKNOWN despite the 0050c525 cluster twin.
}
