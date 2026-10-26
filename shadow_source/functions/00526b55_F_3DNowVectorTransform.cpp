// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00526B55
// Canonical corpus name: F_3DNowVectorTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DNowVectorTransform_00526b55.c

void UnknownObject::F_3DNowVectorTransform()
{
    // Vector transform helper: builds a 4x4 transform into the local v17 array by selecting up to three optional matrix inputs a6/a7/a8 via an 8-case jump-table switch (global 0x00526C88), inverting or composing them with F_4x4MatrixInversion / F_8SIMDMatrixPackedFloatOperation, then transforms an input vector into a3 through F_4DVectorTransform. When a5 is non-null the input is first blended toward a4 using 3DNow! reciprocal/scale math with packed-float constants (globals 0x005AF980/0x005AF988/0x005AF998); otherwise a4 is transformed directly. Returns a3.
    // GUARD: Switch on (a6 != 0) | (2 * ((a7 != 0) | (2 * (a8 != 0)))); the 8-case dispatch (8-way jump table at global 0x00526C88) selects which of a6/a7/a8 supply the matrix input and whether compose is needed. [source:raw, global:0x00526C88]
    // CALL: Case 0: sub_522B22 builds an identity/default matrix into local v17. [callee:0x00522B22]
    // CALL: Cases 1/2/4: F_4x4MatrixInversion inverts the single supplied input (a6, a7, or a8 respectively) into v17. [callee:0x005257C0]
    // CALL: Cases 3/5/6/7: F_8SIMDMatrixPackedFloatOperation composes the supplied matrix inputs (a6/a7/a8) into v17; case 7 composes twice, and cases 3/5/6 then fall through to an extra F_4x4MatrixInversion of v17 (LABEL_11). [callee:0x005265DB, callee:0x005257C0]
    // GUARD: Guard a5 != 0 selects the blend path (compute a weighted mix between a4 and a5) versus the direct transform of a4. [source:raw]
    // CALCULATION: Blend math: reciprocal of the a5 scale via _m_pfrcp/_m_pfrcpit1/_m_pfrcpit2, differences between a4 and a5 quads, and packed-float scale/one/sign constants read from globals 0x005AF980, 0x005AF988 and 0x005AF998 to normalize the interpolated vector component. [global:0x005AF980, global:0x005AF988, global:0x005AF998, source:raw]
    // ASSIGNMENT: Write the blended component into a3: a3->m64_u64 receives the transformed first quad (sign-flipped via pxor), a3[1].m64_i32[0] receives the integer-converted second component. [source:raw]
    // CALL: F_4DVectorTransform(a3, a3|a4, v17) applies the composed/inverted transform to the (optionally blended) input vector, storing into a3. [callee:0x00526550]
    // RETURN: Return the output vector pointer a3. [source:raw, function:0x00526B55]

    // Conservative worker pseudocode:
    //   // a6/a7/a8: up to three optional 4x4 matrix inputs (NULL means 'not present').
    //   // a4: source vector. a5: optional blend target/weight vector. a3: output.
    //   void* F_3DNowVectorTransform(__m64* out, __m64* vec, __m64* blend, __m64* m1, __m64* m2, __m64* m3) {
    //     __m64 tmp[8];
    //     switch ((m1!=0) | (2*((m2!=0) | (2*(m3!=0))))) {
    //       case 0: build_identity(tmp); break;
    //       case 1: invert(tmp, 0, m1); break;
    //       case 2: invert(tmp, 0, m2); break;
    //       case 3: compose(tmp, m2, m1); goto invert_tmp;
    //       case 4: invert(tmp, 0, m3); break;
    //       case 5: compose(tmp, m3, m1); goto invert_tmp;
    //       case 6: compose(tmp, m3, m2); goto invert_tmp;
    //       case 7: compose(tmp, m3, m2); compose(tmp, tmp, m1);
    //       invert_tmp: invert(tmp, 0, tmp); break;
    //     }
    //     if (blend) {
    //       _m_femms();
    //       // 3DNow reciprocal-scale blend of vec toward blend into out
    //       _m_femms();
    //       F_4DVectorTransform(out, out, tmp);
    //     } else {
    //       F_4DVectorTransform(out, vec, tmp);
    //     }
    //     return out;
    //   }
    // UNRESOLVED: Class owner unknown; owner is UnknownObject/UNKNOWN.
    // UNRESOLVED: Semantics of a6/a7/a8 (e.g. parent/child/inverse transforms) are caller-determined.
    // UNRESOLVED: The blend weighting scale a5 and the constants at 0x005AF980/0x005AF988/0x005AF998 are not individually identified beyond 'read packed-float constants'.
    // UNRESOLVED: The extra F_4x4MatrixInversion at LABEL_11 for cases 3/5/6/7 inverts the composed result.
}
