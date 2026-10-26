// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00455FD0
// Canonical corpus name: AngleNormalization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AngleNormalization_00455fd0.c

void UnknownObject::AngleNormalization()
{
    // Normalizes a floating-point angle in place against +PI and -PI. Values at or below +PI are left unchanged when already at or above -PI, and are wrapped upward by 2*PI when below -PI. Values above +PI are reflected by replacing *this with 2*PI - *this rather than subtracting 2*PI (the difference from its structural twin AngleWrap 00455f90). Uses the +PI constant at 0x0059EFA4 and the 2*PI constant at 0x0059EFA8. Called by CollisionResponseFilter (004584c0).
    // GUARD: Compares *this against +PI (flt_59EFA4, 3.1415927) and branches to the reflection path when it is strictly greater [field:this:0x00000000, global:0x0059EFA4, source:raw]
    // GUARD: On the less-or-equal path, checks whether *this is below -PI (flt_59EFA4 negated, -3.1415927) [field:this:0x00000000, global:0x0059EFA4, source:raw]
    // ASSIGNMENT: When *this < -PI, wraps upward by adding 2*PI (flt_59EFA8, 6.2831855) into this+0x0 [field:this:0x00000000, global:0x0059EFA8, source:raw]
    // ASSIGNMENT: When *this > +PI, replaces this+0x0 with 2*PI - *this (flt_59EFA8 minus the current value), reflecting rather than subtracting [field:this:0x00000000, global:0x0059EFA8, source:raw]
    // RETURN: Returns void; the normalized angle remains in this+0x0 [source:raw]
    // CALL: Invoked by CollisionResponseFilter (004584c0) to normalize a collision angle before further processing [caller:0x004584C0, source:raw]

    // Conservative worker pseudocode:
    //   void AngleNormalization(float* this) {
    //     if (*this <= 3.1415927f) {
    //       if (-3.1415927f > *this) *this = *this + 6.2831855f;
    //     } else {
    //       *this = 6.2831855f - *this;
    //     }
    //   }
    // UNRESOLVED: The two PI constants are read from global floats (flt_59EFA4, flt_59EFA8); their write sites are outside this packet
    // UNRESOLVED: The reflection formula (2*PI - *this) in the greater-than-PI branch differs from the plain 2*PI subtraction in the structural twin 00455f90; the semantic intent (wrap vs reflect) is not resolved by this packet alone
}
