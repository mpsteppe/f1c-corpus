// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00456F70
// Canonical corpus name: CollisionCoefficientApplication
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionCoefficientApplication_00456f70.c

void UnknownObject::CollisionCoefficientApplication()
{
    // Collision force accumulator update. Selects a signed coefficient (0.4 default, 6.0 when a3 == 1, negated when a2 == 0), multiplies it by the input a4, adds the result to the accumulator field this+0xAC (this[43]), then clamps the value via ClampedFloatSetter (00456FB0) and returns its result. Vehicle collision subsystem; called by sub_4085F0 (004085F0).
    // ASSIGNMENT: Start with the default coefficient v4 = 0.40000001 [source:raw]
    // GUARD: If a3 == 1, replace the coefficient with v4 = 6.0 [source:raw]
    // GUARD: If a2 == 0, negate the coefficient: v4 = v4 * -1.0 [source:raw]
    // CALCULATION: v6 = v4 * a4 + this[43] — accumulate the signed coefficient times the input onto the field at this+0xAC [field:this:0x000000AC, source:raw]
    // CALL: Clamp the computed float via ClampedFloatSetter (00456FB0) and return its result [callee:0x00456FB0, source:raw]
    // CALL: Invoked by sub_4085F0 (004085F0) as part of vehicle collision force handling [caller:0x004085F0, source:raw]

    // Conservative worker pseudocode:
    //   v4 = 0.4;
    //   if (a3 == 1) v4 = 6.0;
    //   if (a2 == 0) v4 = v4 * -1.0;
    //   v6 = v4 * a4 + this[43];
    //   return ClampedFloatSetter(LODWORD(v6));
    // UNRESOLVED: Three read-only float globals (flt_59E670, flt_59EF9C, flt_59EFA0) are flagged by packet facts but appear nowhere in the raw decompiled source; their role (possible saturation sentinel or gain constants) is not verifiable here
    // UNRESOLVED: The semantics of the a3 == 1 selector (6.0 vs 0.4) and the a2 negation (direction sign) are taken from the existing analysis fill, not from the raw source alone
}
