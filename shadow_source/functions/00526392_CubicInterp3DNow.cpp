// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00526392
// Canonical corpus name: CubicInterp3DNow
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CubicInterp3DNow_00526392.c

void UnknownObject::CubicInterp3DNow()
{
    // Cubic Hermite spline interpolation over packed float data using 3DNow! SIMD. Builds the four Hermite basis functions (h00 = 2t^3 - 3t^2 + 1, h10 = t^3 - 2t^2 + t, h01 = 3t^2 - 2t^3, h11 = t^3 - t^2) from factor t loaded from parameter a6, blends four input __m64 control-point vectors (a2..a5), and writes the interpolated result into output pointer a1: full packed pair at a1[0] (offset 0x0) and a single low-lane float at a1[1] (offset 0x8). Straight-line code: no branches, no function calls; enters and exits MMX/3DNow state with femms.
    // STATE_TRANSITION: Enter MMX/3DNow state: femms clears MMX state before packed-float arithmetic. [source:raw, function:0x00526392]
    // CALCULATION: Load interpolation factor t from parameter a6 into packed-float lanes via cvtsi32_si64: t occupies the low lane, high lane is zero. [source:raw, function:0x00526392]
    // CALCULATION: Compute powers t^2 = t*t and t^3 = t^2*t, then h11 = t^3 - t^2. [source:raw]
    // CALCULATION: Compute h01 = 3*t^2 - 2*t^3 using packed coefficient 3.0 from global 0x005AF998 and packed coefficient 2.0 from global 0x005AF9A0. [global:0x005AF998, global:0x005AF9A0, source:raw]
    // CALCULATION: Compute h10 = t^3 - 2*t^2 + t using packed coefficient 2.0 from global 0x005AF9A0. [global:0x005AF9A0, source:raw]
    // CALCULATION: Compute h00 = 2*t^3 - 3*t^2 + 1 using packed coefficient 2.0 from global 0x005AF9A0, 3.0 from global 0x005AF998, and 1.0 from global 0x005AF988. [global:0x005AF988, global:0x005AF998, global:0x005AF9A0, source:raw]
    // CALCULATION: Splat each basis value (h11, h01, h10, h00) across both float lanes via punpckldq so both output components use identical coefficients. [source:raw]
    // ASSIGNMENT: Write a1[0] at offset 0x0 (full 64-bit packed pair): h00*a2[0] + h10*a3[0] + h01*a4[0] + h11*a5[0]. Low lane is interpolated component 0; the high lane collapses to a2[0]'s high float because only h00 carries a 1.0 in the high lane. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write a1[1] low-lane float at offset 0x8: h00*a2[1].low + h10*a3[1].low + h01*a4[1].low + h11*a5[1].low, reading the low 32 bits of each control point's second __m64. High lane of a1[1] is left untouched. [field:this:0x00000008, source:raw]
    // STATE_TRANSITION: Exit MMX/3DNow state: femms clears MMX state before returning. [source:raw]
    // RETURN: Return the output pointer a1 (result register set to a1 at function start). [function:0x00526392, source:raw]

    // Conservative worker pseudocode:
    //   // packed 3DNow! lane semantics; t lives in the low lane of the factor register
    //   femms();
    //   t2 = t * t;
    //   t3 = t2 * t;
    //   h11 = t3 - t2;
    //   h01 = 3.0f * t2 - 2.0f * t3;
    //   h10 = t3 - 2.0f * t2 + t;
    //   h00 = 2.0f * t3 - 3.0f * t2 + 1.0f;
    //   a1[0] = h00 * a2[0] + h10 * a3[0] + h01 * a4[0] + h11 * a5[0];
    //   a1[1].low32 = h00 * a2[1].low32 + h10 * a3[1].low32 + h01 * a4[1].low32 + h11 * a5[1].low32;
    //   return a1;
    // UNRESOLVED: Role assignment of the four inputs a2..a5 (which act as endpoints p0/p1 versus tangents m0/m1) is not determinable from this packet; only the grounded basis-to-input binding is h00->a2, h10->a3, h01->a4, h11->a5.
    // UNRESOLVED: Parameter a6 is typed unsigned int by the decompiler; whether it carries a single float bit pattern or other packed data is not determinable statically, and cvtsi32_si64 treats only its low 32 bits as the factor t.
    // UNRESOLVED: Owning class/module is unknown; the function is not on a static frame path and has no static callers or callees in this packet.
}
