// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00526EBE
// Canonical corpus name: sub_526EBE
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_526EBE_00526ebe.c

void UnknownObject::QuarticInterpPacked()
{
    // Straight-line 3DNow! (__m64) helper that builds higher-order blend-weight coefficients from a packed-float factor t derived from a6, then blends four packed-float control points (a2-a5) into the 64-bit output pair at a1[0], scaled by 0.5. No branches, no calls. Caller, subsystem, and actual interpolation basis are unknown.
    // CALCULATION: Factor t obtained from a6: _mm_cvtsi32_si64(a6) then _m_punpckldq(v6,v6) broadcasts the low dword bit-pattern of a6 to both float lanes (treated as packed single-precision bits). [function:0x00526EBE, source:raw]
    // CALCULATION: Build packed pair v8 = (1.0f, t) by _m_punpckldq(v6, 1065353216LL); the decimal literal 1065353216 is the single-precision bit pattern for 1.0f. [source:raw]
    // CALCULATION: Compute t^2 and t^3 lane-wise: v9 = _m_pfmul(_m_pfmul(v7,v7), v8) yields low lane t^2 and high lane t^3. [source:raw]
    // CALCULATION: Difference terms: v12 = v9 - v11 with v11 = _m_pfmul(v8,v8) = (1.0f, t^2), giving low lane (t^2 - 1.0f) and high lane (t^3 - t^2). [source:raw]
    // CALCULATION: Scale difference terms by the packed constant 0x4000000040400000LL (two single-precision values: 3.0f in the low dword, 2.0f in the high dword): v13 = _m_pfmul(v12, 0x4000000040400000LL); then v14 = _m_punpckldq(v13, v12) gathers low dwords into (3*(t^2-1.0f), t^2-1.0f). [source:raw]
    // CALCULATION: Sign-flip lane pair via _m_pxor(_m_punpckldq(v10,v10), 0x8000000000000000) negates the broadcast of v8's low dword (1.0f); combining with _m_punpckldq(v11,v11) and subtracting v14 yields v15 = (1.0f-t^2, 3*(1.0f-t^2)). [source:raw]
    // CALCULATION: High-order pair v16 = v14 - _m_punpckhdq(v13, 0) places v13's high lane (2*(t^3-t^2)) in the low dword, yielding v16 = (3*(t^2-1.0f) - 2*(t^3-t^2), t^2-1.0f). [source:raw]
    // CALCULATION: Four per-lane weight broadcasts: punpckldq(v16,v16) = w0, punpckhdq(v15,v15) = w1, punpckldq(v15,v15) = w2, punpckhdq(v16,v16) = w3; each applied lane-wise against control points a3, a2, a4, a5 respectively. [source:raw]
    // ASSIGNMENT: Blend and store: a1->m64_u64 = _m_pfmul( w0*a3 + w1*a2 + w2*a4 + w3*a5, 0x3F0000003F000000LL ) where the final packed scale is (0.5f, 0.5f); full 64-bit write to this+0x0. [source:raw, field:this:0x00000000]
    // RETURN: Return the input output pointer a1 after _m_femms() (3DNow! state exit). [function:0x00526EBE, source:raw]

    // Conservative worker pseudocode:
    //   t = (float)(int)a6;
    //   t2 = t * t;
    //   t3 = t2 * t;
    //   w0 = 5.0f*t2 - 2.0f*t3 - 3.0f;   // v16 low lane
    //   w1 = 3.0f * (1.0f - t2);         // v15 high lane
    //   w2 = 1.0f - t2;                  // v15 low lane
    //   w3 = t2 - 1.0f;                  // v16 high lane
    //   out.low  = 0.5f * (w0*a3.low  + w1*a2.low  + w2*a4.low  + w3*a5.low);
    //   out.high = 0.5f * (w0*a3.high + w1*a2.high + w2*a4.high + w3*a5.high);
    //   a1->m64_u64 = out;
    //   return a1;
    // UNRESOLVED: No owner/subsystem or caller evidence; function is top-level (or indirect-only) in the static graph, so the interpolation's domain (angle, position, etc.) is unknown.
    // UNRESOLVED: The four read globals 0x005AF900, 0x005AF910, 0x005AF920, 0x005AF968 are read per the deterministic facts, but the raw body folds all constants to inline immediates (1.0f, (3.0f,2.0f), 0x8000000000000000 sign-flip, 0.5f scale); the exact address-to-constant mapping is not determinable from this packet.
    // UNRESOLVED: a6 is consumed as integer bit-pattern for a packed float; whether callers pass raw float bits or a scalar that must be interpreted differently is unverified.
    // UNRESOLVED: The weight basis does not obviously normalize (weight sum = 2*t^2*(1-t)); whether this is an intended derivative-mixed quartic or a specific established spline is unverified.
}
