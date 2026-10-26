// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00447BB0
// Canonical corpus name: TireFrictionCurveEval
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireFrictionCurveEval_00447bb0.c

void UnknownObject::TireFrictionCurveEval()
{
    // Piecewise evaluation of a tire friction curve from a slip input (double at this+0x19C). Saturation: returns 58.5 when slip >= 4.4 and 0.0 when slip <= 0.0. Otherwise clamps the negative ramp v2 = max(slip - 0.4, 0.0), clamps the upper input to 4.0, and returns (TrigTableLookup(this) * (v3 * 0.25 - v2 * 0.25) + v2 * 0.25) * 58.5, i.e. a table-shaped interpolation between the two ramp arms scaled by 58.5.
    // GUARD: Saturation clamp: when the slip input (this+0x19C) is >= 4.4 return the saturated output 58.5 immediately. [field:this:0x0000019C, global:0x0059EF10, global:0x0059EF00, source:raw]
    // GUARD: No-slip clamp: when the slip input (this+0x19C) is <= 0.0 return 0.0 immediately. [field:this:0x0000019C, global:0x0059E430, global:0x0059E440, source:raw]
    // CALCULATION: Negative ramp arm: v2 = slip - 0.4 (inflection threshold), clamped to >= 0.0. [field:this:0x0000019C, global:0x0059E7D8, source:raw]
    // CALCULATION: Upper input clamp: v3 = min(slip, 4.0). [field:this:0x0000019C, global:0x0059EF10, source:raw]
    // CALL: Call TrigTableLookup(this) to obtain the curve-shape modifier used to blend the two ramp arms. [callee:0x00447AB0, field:this:0x0000019C, source:raw]
    // CALCULATION: Blend the ramp arms and scale: (TrigTableLookup(this) * (v3 * 0.25 - v2 * 0.25) + v2 * 0.25) * 58.5. [callee:0x00447AB0, global:0x0059EB50, global:0x0059EC80, global:0x0059EF08, source:raw]
    // RETURN: Return the evaluated friction value (58.5, 0.0, or the interpolated curve value). [source:raw]

    // Conservative worker pseudocode:
    //   double TireFrictionCurveEval(double *this) {
    //     double slip = *(double *)((char *)this + 0x19C);
    //     if (slip >= 4.4) return 58.5;
    //     if (slip <= 0.0) return 0.0;
    //     double v2 = slip - 0.4;
    //     if (v2 < 0.0) v2 = 0.0;
    //     double v3 = (slip >= 4.0) ? 4.0 : slip;
    //     return (TrigTableLookup(this) * (v3 * 0.25 - v2 * 0.25) + v2 * 0.25) * 58.5;
    //   }
    // UNRESOLVED: The exact pairing of the inlined literals (4.4, 4.0, 0.4, 0.25, 58.5) to the read-only globals is taken from existing_analysis DERIVED labels and is not visible in the raw decompiled source.
    // UNRESOLVED: The roles of dbl_59E430, flt_59E440, dbl_59E7D8, dbl_59EB50, dbl_59EC80, flt_59EF00, dbl_59EF08, dbl_59EF10 are inferred from existing_analysis; their memory content is not verifiable from the packet.
}
