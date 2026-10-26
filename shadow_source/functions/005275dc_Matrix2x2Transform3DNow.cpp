// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005275DC
// Canonical corpus name: Matrix2x23DNow
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Matrix2x23DNow_005275dc.c

void UnknownObject::Matrix2x2Transform3DNow()
{
    // Applies a 2x2 linear transform to four packed input pairs using 3DNow! intrinsics. The four coefficients of the 2x2 matrix in a2 (two __m64) are splatted into replicated pairs (v4, v6 from a2[0]; v7, v8 from a2[1]), then each output pair is the sum of four a3 pairs weighted by those coefficients: output[0] uses a3[0]/a3[2]/a3[4]/a3[6], output[1] uses a3[1]/a3[3]/a3[5]/a3[7]. Results are stored to a1[0] and a1[1]. MMX state is cleared with _m_femms at entry and exit, and the output buffer a1 is returned. The packet's ABI name Matrix2x2_3DNow is LEGACY-trusted.
    // STATE_TRANSITION: Clear MMX/3DNow state via _m_femms at entry. [source:raw]
    // CALCULATION: Splat the two float coefficients of a2[0] (m00, m01) into replicated pairs v4 and v6 via punpckldq/punpckhdq. [field:this:0x00000000, source:raw]
    // CALCULATION: Splat the two float coefficients of a2[1] (m10, m11) into replicated pairs v7 and v8 via punpckldq/punpckhdq. [field:this:0x00000008, source:raw]
    // CALCULATION: Compute output pair 1 as v4*a3[1] + v6*a3[3] + v7*a3[5] + v8*a3[7] using pfmul and pfadd. [source:raw]
    // CALCULATION: Compute output pair 0 as v4*a3[0] + v6*a3[2] + v7*a3[4] + v8*a3[6] using pfmul and pfadd. [source:raw]
    // ASSIGNMENT: Store output pair 0 into a1 at offset 0x0. [field:this:0x00000000]
    // ASSIGNMENT: Store output pair 1 into a1 at offset 0x8. [field:this:0x00000008]
    // STATE_TRANSITION: Clear MMX/3DNow state via _m_femms at exit. [source:raw]
    // RETURN: Return the output buffer pointer a1. [function:0x005275DC, source:raw]

    // Conservative worker pseudocode:
    //   femms();
    //   m00 = splat(a2[0].lo); m01 = splat(a2[0].hi);
    //   m10 = splat(a2[1].lo); m11 = splat(a2[1].hi);
    //   a1[0] = m00*a3[0] + m01*a3[2] + m10*a3[4] + m11*a3[6];
    //   a1[1] = m00*a3[1] + m01*a3[3] + m10*a3[5] + m11*a3[7];
    //   femms();
    //   return a1;
    // UNRESOLVED: Owner is UNKNOWN; the ABI name Matrix2x2_3DNow is LEGACY trust and names the operation, not a recoverable owning class.
    // UNRESOLVED: Whether a3 packs four 2-component vectors (one per column) or two 4-component vectors is not recoverable from this function alone; the column pairing (0,2,4,6) vs (1,3,5,7) is DERIVED from the indexing.
    // UNRESOLVED: No static callers are present in the packet, so the call context of this math routine is unknown.
    // UNRESOLVED: The DERIVED cluster-twin prelabel names the function after 00410AF0, but the raw source here is a 3DNow matrix transform, not an array swap-remove.
}
