// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00520C0E
// Canonical corpus name: SSEReciprocalSquareRootWithNewtonRaphsonQuaterni
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SSEReciprocalSquareRootWithNewtonRaphsonQuaterni_00520c0e.c

void UnknownObject::SSEReciprocalSquareRootWithNewtonRaphsonQuaterni()
{
    // SSE quaternion-to-4x4-rotation-matrix conversion. Loads two low floats of the input quaternion (a2), clears sign bits with mask xmmword_5D8D20, computes the sum of squares, then produces a normalized scalar via an approximate reciprocal square root refined with one Newton-Raphson step using constants dword_5D8D00 and dword_5D8D10. The normalized components are scaled by xmmword_5D8CF0 and combined with the four bias constants xmmword_5D8CE0/5D8CD0/5D8CC0/5D8CB0 to form four SSE rows stored at a1[0..3] (offsets 0x0/0x10/0x20/0x30). Straight-line code, no calls.
    // ASSIGNMENT: result = a1; the return pointer is the output matrix. [source:raw]
    // ASSIGNMENT: v3 = _mm_loadl_ps(a2): load the low 64 bits (two floats) of the input quaternion into an XMM register. [source:raw]
    // CALCULATION: v4 = _mm_and_ps(xmmword_5D8D20, v3): apply the sign-mask to the loaded pair. [global:0x005D8D20, source:raw]
    // CALCULATION: v6 = v4 * v4 (component-wise squares); v7 = v6 + movehl(v6, v6) (partial horizontal add); v8 = v7[0] + shuffle(v7, v7, 1)[0] yields the scalar sum of squares. [source:raw]
    // CALCULATION: v7[0] = 1.0 / fsqrt(v8): approximate reciprocal square root of the sum of squares. [source:raw]
    // CALCULATION: Newton-Raphson refinement: v5[0] = (dword_5D8D10 * v7[0]) * (dword_5D8D00 - (v8 * v7[0]) * v7[0]). [global:0x005D8D00, global:0x005D8D10, source:raw]
    // CALCULATION: v9 = v3 * broadcast(v5): scale the quaternion pair by the refined reciprocal sqrt (normalization). [source:raw]
    // CALCULATION: v10 = xmmword_5D8CF0 * v9: scale the normalized products by the row-scaling constant. [global:0x005D8CF0, source:raw]
    // CALCULATION: Row 0: v12 = (shuffle(v9, v9, 0) * v10) + xmmword_5D8CE0. [global:0x005D8CE0, source:raw]
    // CALCULATION: Row 1: v17 = (v10 * shuffle(v9, v9, 85)) + xmmword_5D8CD0. [global:0x005D8CD0, source:raw]
    // CALCULATION: Row 2: v16 = (shuffle(v9, v9, 170) * v10) + xmmword_5D8CC0. [global:0x005D8CC0, source:raw]
    // CALCULATION: Row 3: v14 = (shuffle(v9, v9, 255) * v10) + xmmword_5D8CB0. [global:0x005D8CB0, source:raw]
    // ASSIGNMENT: Store the four computed rows: *a1 = v12 (offset 0x0), a1[1] = v17 (offset 0x10), a1[2] = v16 (offset 0x20), a1[3] = v14 (offset 0x30). [field:this:0x00000000, field:this:0x00000010, field:this:0x00000020, field:this:0x00000030, source:raw]
    // RETURN: Return the output matrix pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   __m128 *quat_to_matrix(__m128 *out, const float *q) {
    //     __m128 lo = _mm_loadl_ps(q);
    //     __m128 v = _mm_and_ps(xmmword_5D8D20, lo);
    //     __m128 s2 = v * v;
    //     float sum = (s2 + _mm_movehl_ps(s2, s2))[0] + _mm_shuffle_ps(s2, s2, 1)[0];
    //     float inv = 1.0f / _mm_sqrt_ss(sum)[0];
    //     float refined = (dword_5D8D10 * inv) * (dword_5D8D00 - (sum * inv) * inv);
    //     __m128 n = lo * _mm_shuffle_ps(_mm_set1_ps(refined), 0);
    //     __m128 p = xmmword_5D8CF0 * n;
    //     out[0] = (_mm_shuffle_ps(n, n, 0) * p) + xmmword_5D8CE0;
    //     out[1] = (p * _mm_shuffle_ps(n, n, 85)) + xmmword_5D8CD0;
    //     out[2] = (_mm_shuffle_ps(n, n, 170) * p) + xmmword_5D8CC0;
    //     out[3] = (_mm_shuffle_ps(n, n, 255) * p) + xmmword_5D8CB0;
    //     return out;
    //   }
    // UNRESOLVED: Only two low floats of the input are loaded and normalized; the full quaternion component layout (which two components are loaded, and how the remaining two feed the matrix rows) is not evident from the packet source.
    // UNRESOLVED: The concrete float contents of xmmword_5D8CB0-5D8CF0 (the per-row bias and scaling constants) are not decoded in the packet.
    // UNRESOLVED: The row-major vs. column-major layout of the 4x4 output matrix is not determined.
}
