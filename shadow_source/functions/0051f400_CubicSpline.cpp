// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051F400
// Canonical corpus name: CubicSpline
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CubicSpline_0051f400.c

void UnknownObject::CubicSpline()
{
    // SSE-accelerated cubic spline interpolation. Takes a float parameter a8 as t, computes t^2 and t^3, evaluates a cubic basis polynomial vector from the four constant vectors xmmword_5D8AC0 (t term), xmmword_5D8AB0 (t^2 term), xmmword_5D8A90 (t^3 term) and the bias dword_5D8AA0, then blends the four 8-byte control-point pairs a4-a7 weighted by the four basis components. Writes the blended pair to output pointer a3 and one trailing dword at a3+8, returning a3. Straight-line code: no guard, no loop, no call.
    // ASSIGNMENT: v8 = a8; a1[0] = t * t; a2[0] = t * (t * t); build t, t^2, t^3 of the spline parameter a8 [source:raw]
    // CALCULATION: v9 = t * xmmword_5D8AC0 + dword_5D8AA0; v10 = v9 + t^2 * xmmword_5D8AB0 + t^3 * xmmword_5D8A90; evaluate the cubic basis polynomial vector v10 from the four spline coefficient constants [global:0x005D8A90, global:0x005D8AA0, global:0x005D8AB0, global:0x005D8AC0, source:raw]
    // CALCULATION: v11 = loadh(a4)*v10.xxxx + loadh(a5)*v10.yyyy + loadh(a6)*v10.zzzz + loadh(a7)*v10.wwww; blend the four 8-byte control-point pairs a4-a7, each weighted by one component of the basis vector v10 [source:raw]
    // ASSIGNMENT: storeh_ps(a3, v11) writes v11 elements [2] and [3] (the blended pair) to output pointer a3; *(int*)(a3+8) = v11 element [0] as a dword [source:raw]
    // RETURN: return a3; yield the output pointer holding the interpolated result [function:0x0051F400, source:raw]

    // Conservative worker pseudocode:
    //   t = a8;
    //   t2 = t * t;
    //   t3 = t * t2;
    //   v9 = t * xmmword_5D8AC0 + dword_5D8AA0;
    //   v10 = v9 + t2 * xmmword_5D8AB0 + t3 * xmmword_5D8A90;
    //   v11 = loadh(a4) * v10.xxxx + loadh(a5) * v10.yyyy + loadh(a6) * v10.zzzz + loadh(a7) * v10.wwww;
    //   *(double*)a3 = high_qword(v11);
    //   *(int*)(a3 + 8) = v11.lane0;
    //   return a3;
    // UNRESOLVED: the dword written at a3+8 is v11 element [0], whose lower lanes of the blend sum are zeroed by loadh; whether this trailing value is intentional (e.g. derivative channel) or vestigial is not established by the packet
    // UNRESOLVED: the exact spline basis is not proven: the coefficient constants xmmword_5D8A90 / 5D8AA0 / 5D8AB0 / 5D8AC0 are un-named in the packet, and the ABI lead Cubic_Spline_Catmull_Rom_Basis_Evaluation (LEGACY trust) is only consistent with, not evidence for, a Catmull-Rom reading
    // UNRESOLVED: a1 and a2 enter as __userpurge register arguments (xmm1, xmm2) and are reused as t^2/t^3 accumulators; the intended caller contract for these vector arguments is unknown
    // UNRESOLVED: no static callers and no frame path exist for this function; the enclosing owner remains UnknownObject
}
