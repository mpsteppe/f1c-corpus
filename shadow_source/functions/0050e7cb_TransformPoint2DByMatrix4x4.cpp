// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E7CB
// Canonical corpus name: sub_50E7CB
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50E7CB_0050e7cb.c

void UnknownObject::TransformPoint2DByMatrix4x4()
{
    // Transforms a 2D point a2 (x, y) by a 4x4 matrix a3 into output point a1, computing the homogeneous triple (X, Y, w) where w = a2[0]*a3[3] + a2[1]*a3[7] + a3[15], and then optionally perspective-dividing X/Y by w when FloatRangeCheck reports that w is not approximately 1.0. Returns the output point pointer a1.
    // CALCULATION: Compute the intermediate homogeneous Y component v3 = a2[0]*a3[1] + a2[1]*a3[5] + a3[13]. [source:raw]
    // CALCULATION: Compute the homogeneous w component v4 = a2[0]*a3[3] + a2[1]*a3[7] + a3[15]. [source:raw]
    // ASSIGNMENT: Write the output X component: *a1 = a2[0]*a3[0] + a2[1]*a3[4] + a3[12]. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write the output Y component: a1[1] = v3, then stage w as v8 = v4. [field:this:0x00000004, source:raw]
    // CALL: Call FloatRangeCheck(v8, 1.0) to test whether w is approximately 1.0. [callee:0x0050C042, source:raw]
    // GUARD: When FloatRangeCheck returns false (v5 true, meaning w is not approximately 1.0), take the perspective-divide path; otherwise the computed X/Y are left verbatim. [callee:0x0050C042, source:raw]
    // CALCULATION: Compute the perspective-divide factor v7 = 1.0 / v8. [source:raw]
    // ASSIGNMENT: Perspective-divide the output components: *a1 = v7 * *a1 and a1[1] = v7 * a1[1]. [field:this:0x00000000, field:this:0x00000004, source:raw]
    // RETURN: Return the output point pointer a1. [function:0x0050E7CB, source:raw]

    // Conservative worker pseudocode:
    //   float *sub_50E7CB(float *out, float *pt, float *m) {
    //     float y = pt[0]*m[1] + pt[1]*m[5] + m[13];
    //     float w = pt[0]*m[3] + pt[1]*m[7] + m[15];
    //     out[0] = pt[0]*m[0] + pt[1]*m[4] + m[12];
    //     out[1] = y;
    //     if (!FloatRangeCheck(w, 1.0f)) {
    //       float invW = 1.0f / w;
    //       out[0] *= invW;
    //       out[1] *= invW;
    //     }
    //     return out;
    //   }
    // UNRESOLVED: Matrix layout is inferred column-major from the access pattern (a3[0]/a3[4]/a3[12] for X, a3[1]/a3[5]/a3[13] for Y, a3[3]/a3[7]/a3[15] for w); not independently evidenced.
    // UNRESOLVED: FloatRangeCheck's exact tolerance for 'approximately 1.0' is defined in the callee 0x0050C042, not in this function.
    // UNRESOLVED: The class owner of a1/a2/a3 is unknown (owner UNKNOWN); equal offsets on unrelated pointers are not proof of shared identity.
    // UNRESOLVED: The 2D point is transformed with no a2[2] term, so any z component is not consumed here; whether this is a deliberately 2D variant of the nearby 3D point-transform routine is inferred, not proven.
}
