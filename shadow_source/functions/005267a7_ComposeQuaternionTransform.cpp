// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005267A7
// Canonical corpus name: QuaternionTransformComposition
// Owner: QuaternionTransformComposition [DERIVED]
// Raw source: functions/QuaternionTransformComposition_005267a7.c

void QuaternionTransformComposition::ComposeQuaternionTransform()
{
    // Compose a 3D transform from up to three inputs selected by the null-state of a6/a7/a8 (switch driven by a jump table), apply the resulting transform to vector a4 writing a3 via F_4DVectorTransform, then optionally apply an MMX packed-float weight blend to a3's output using a5's integer weights. Returns a3.
    // GUARD: Switch on null-state combination of a6/a7/a8: key = (a6 != 0) | (2 * ((a7 != 0) | (2 * (a8 != 0)))), dispatch via jump table global:0x0052690F; selects which transform source (or composition path) feeds F_4DVectorTransform. [global:0x0052690F, function:0x005267A7, source:raw]
    // ASSIGNMENT: Case 0 (all of a6/a7/a8 null): initialize local v11 to identity — all twelve components set 0.0, diagonal elements set 1.0 — and point v8 at v11. [source:raw]
    // ASSIGNMENT: Case 1: passthrough, v8 = a6. [source:raw]
    // ASSIGNMENT: Case 2: passthrough, v8 = a7. [source:raw]
    // ASSIGNMENT: Case 4: passthrough, v8 = a8. [source:raw]
    // CALL: Case 3: compose a6 and a7 into local v11 via F_8SIMDMatrixPackedFloatOperation (a1, a2, &v11, a7, a6); 3DNow! state flushed with _m_femms before/after. [callee:0x005265DB, source:raw]
    // CALL: Case 5: compose a6 and a8 into local v11 via F_8SIMDMatrixPackedFloatOperation (a1, a2, &v11, a8, a6). [callee:0x005265DB, source:raw]
    // CALL: Case 6: compose a7 and a8 into local v11 via F_8SIMDMatrixPackedFloatOperation (a1, a2, &v11, a8, a7). [callee:0x005265DB, source:raw]
    // CALL: Case 7 (all three present): compose a8 and a7 into v11, then compose a6 into the running result via second F_8SIMDMatrixPackedFloatOperation (a1, a2, &v11, &v11, a6). [callee:0x005265DB, source:raw]
    // CALL: Apply the selected/composed transform v8 to vector a4, storing result in a3, via F_4DVectorTransform(a3, a4, v8). [callee:0x00526550, source:raw]
    // GUARD: if (a5) — a5 non-null selects an additional MMX/3DNow packed-float weight blend applied to the a3 output. [source:raw]
    // CALCULATION: MMX packed-float blend: combine a3 components against integer weights from a5[0..2] — blendScalar = pfadd(pfmul(cvt(a3[1]low), pfsub(punpckhdq(a5[2],a5[2]), a5[2])), a5[2]); a3[0] = pfadd(pfmul(pfadd(pxor(a3[0], signMask), packedOne), pfmul(pi2fd(a5[1]), packedHalf)), pi2fd(a5[0])), using packed-float constants loaded from globals 0x005AF980, 0x005AF988, 0x005AF990. [source:raw, global:0x005AF980, global:0x005AF988, global:0x005AF990]
    // ASSIGNMENT: Store the blended scalar (v9) back into the low dword of a3[1]. [source:raw]
    // RETURN: Return a3, the transformed (and optionally blended) vector output. [source:raw, function:0x005267A7]

    // Conservative worker pseudocode:
    //   // Compose up to three transform inputs chosen by a6/a7/a8 null-state, apply to vector, optionally blend.
    //   transformSource = &composedTransform;
    //   key = (a6 != 0) | (2 * ((a7 != 0) | (2 * (a8 != 0))));
    //   switch (key):
    //     case 0: composedTransform = identity;
    //     case 1: transformSource = a6;
    //     case 2: transformSource = a7;
    //     case 4: transformSource = a8;
    //     cases 3/5/6/7: F_8SIMDMatrixPackedFloatOperation(a1, a2, &composedTransform, ...);
    //   F_4DVectorTransform(a3, a4, transformSource);
    //   if (a5) { MMX packed-float weight blend of a3 using a5[0..2]; }
    //   return a3;
    // UNRESOLVED: Exact mathematical semantics of the a5 blend formula (which components of a3 are weighted and how a5 integer values map to a linear interpolation factor) are opaque in the MMX/3DNow intrinsics and only DERIVED as a weight blend.
    // UNRESOLVED: Roles of the MMX register parameters a1/a2 passed into F_8SIMDMatrixPackedFloatOperation are unknown.
    // UNRESOLVED: Which specific packed-float constant each of globals 0x005AF980 / 0x005AF988 / 0x005AF990 holds (sign-mask, packed 1.0, packed 0.5 respectively by inference from the inline literals) is not confirmed.
    // UNRESOLVED: Composition ordering semantics for case 7 (which input is applied first in the transform chain) are unverified.
    // UNRESOLVED: The blend modifies only part of the a3 quadwords (a3[0] full word, a3[1] low dword); whether remaining components stay untransformed is unconfirmed.
}
