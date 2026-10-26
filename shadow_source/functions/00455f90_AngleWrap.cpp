// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00455F90
// Canonical corpus name: AngleWrap
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AngleWrap_00455f90.c

void UnknownObject::AngleWrap()
{
    // Normalizes a floating-point angle in place to the range [-PI, PI]. If the value exceeds +PI it is reduced by 2*PI; if it is below -PI it is increased by 2*PI; values already in range pass through unchanged. Uses the +PI constant at 0x0059EFA4 and the 2*PI constant at 0x0059EFA8. Called by CollisionResponseFilter (004584c0).
    // GUARD: Compares *this against +PI (flt_59EFA4, 3.1415927) and branches to the wrap-down path when it is strictly greater [field:this:0x00000000, global:0x0059EFA4, source:raw]
    // GUARD: On the less-or-equal path, checks whether *this is below -PI (flt_59EFA4 negated, -3.1415927) [field:this:0x00000000, global:0x0059EFA4, source:raw]
    // ASSIGNMENT: When *this < -PI, wraps upward by adding 2*PI (flt_59EFA8, 6.2831855) into this+0x0 [field:this:0x00000000, global:0x0059EFA8, source:raw]
    // ASSIGNMENT: When *this > +PI, wraps downward by subtracting 2*PI (flt_59EFA8, 6.2831855) from this+0x0 [field:this:0x00000000, global:0x0059EFA8, source:raw]
    // RETURN: Returns void; the normalized angle remains in this+0x0 [source:raw]
    // CALL: Invoked by CollisionResponseFilter (004584c0) to normalize a collision angle before further processing [caller:0x004584C0, source:raw]

    // Conservative worker pseudocode:
    //   void AngleWrap(float* this) {
    //     if (*this <= 3.1415927f) {
    //       if (-3.1415927f > *this) *this = *this + 6.2831855f;
    //     } else {
    //       *this = *this - 6.2831855f;
    //     }
    //   }
    // UNRESOLVED: The two PI constants are read from global floats (flt_59EFA4, flt_59EFA8); their write sites are outside this packet
}
