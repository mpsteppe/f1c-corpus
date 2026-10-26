// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E927
// Canonical corpus name: F_44MatrixTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_44MatrixTransform_0050e927.c

void UnknownObject::TransformPoint3DByMatrix4x4()
{
    // Transforms a 3D point a2 by a 4x4 matrix a3 into output point a1, computing the full homogeneous result (X, Y, Z, w) and then optionally perspective-dividing X/Y/Z by w when FloatRangeCheck reports that w is not approximately 1.0. Returns the output point pointer a1.
    // CALCULATION: Compute output X into *a1: a2[0]*a3[0] + a2[1]*a3[4] + a2[2]*a3[8] + a3[12]. [source:raw, field:this:0x00000000]
    // CALCULATION: Compute output Y into a1[1]: a2[0]*a3[1] + a2[1]*a3[5] + a2[2]*a3[9] + a3[13]. [source:raw, field:this:0x00000004]
    // CALCULATION: Compute output Z into a1[2]: a2[0]*a3[2] + a2[1]*a3[6] + a2[2]*a3[10] + a3[14]. [source:raw, field:this:0x00000008]
    // CALCULATION: Compute the homogeneous w component v9: a2[0]*a3[3] + a2[1]*a3[7] + a2[2]*a3[11] + a3[15]. [source:raw]
    // CALL: Call FloatRangeCheck(w, 1.0) to test whether w is approximately 1.0. [callee:0x0050C042]
    // GUARD: When FloatRangeCheck reports w is not approximately 1.0, perspective-divide the output X/Y/Z components by w; otherwise they are left verbatim. [callee:0x0050C042]
    // CALCULATION: Perspective divide: multiply *a1, a1[1] and a1[2] by 1.0 / w when the divide path is taken. [source:raw, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008]
    // RETURN: Return the output point pointer a1. [source:raw, function:0x0050E927]

    // Conservative worker pseudocode:
    //   float *sub_50E927(float *out, float *v, float *m) {
    //     out[0] = v[0]*m[0]  + v[1]*m[4]  + v[2]*m[8]  + m[12];
    //     out[1] = v[0]*m[1]  + v[1]*m[5]  + v[2]*m[9]  + m[13];
    //     out[2] = v[0]*m[2]  + v[1]*m[6]  + v[2]*m[10] + m[14];
    //     float w = v[0]*m[3] + v[1]*m[7]  + v[2]*m[11] + m[15];
    //     if (!FloatRangeCheck(w, 1.0f)) {
    //       float invW = 1.0f / w;
    //       out[0] *= invW;
    //       out[1] *= invW;
    //       out[2] *= invW;
    //     }
    //     return out;
    //   }
    // UNRESOLVED: Matrix layout is inferred column-major from the access pattern; not independently evidenced.
    // UNRESOLVED: FloatRangeCheck's exact epsilon/tolerance for 'approximately 1.0' lives in the callee, not this function.
    // UNRESOLVED: The class owner of a1/a2/a3 is unknown (owner UNKNOWN); equal offsets on unrelated pointers are not proof of shared identity.
}
