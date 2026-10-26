// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B50C0
// Canonical corpus name: UtilityFunction_50c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_50c0_004b50c0.c

void UnknownObject::UtilityFunction_50c0()
{
    // Bounds predicate on a float parameter a2 against two fields of `this`: field at +0x84 (this[33]) is the lower bound and field at +0x88 (this[34]) is the upper bound. The sentinel value -1.0e32 in either field disables that bound check, allowing open-ended or fully bounded range tests. Returns true when both applicable comparisons hold.
    // GUARD: If lower-bound field this[33] (+0x84) equals the sentinel -1.0e32, the lower comparison is bypassed (no lower bound). [field:this:0x00000084, source:raw]
    // CALCULATION: Otherwise require a2 >= (double)this[33] using the lower-bound field at +0x84. [field:this:0x00000084, source:raw]
    // GUARD: If upper-bound field this[34] (+0x88) equals the sentinel -1.0e32, the upper comparison is bypassed (no upper bound). [field:this:0x00000088, source:raw]
    // CALCULATION: Otherwise require a2 <= (double)this[34] using the upper-bound field at +0x88. [field:this:0x00000088, source:raw]
    // RETURN: Return the conjunction of the two (possibly sentinel-bypassed) bound checks as a boolean. [source:raw]

    // Conservative worker pseudocode:
    //   return (this[33] == -1.0e32 || a2 >= (double)this[33])
    //       && (this[34] == -1.0e32 || a2 <= (double)this[34]);
    // UNRESOLVED: The class owning the bounds fields at +0x84/+0x88 is not identified by the packet.
    // UNRESOLVED: flt_5ACD10 is listed as a read global but does not appear in the raw source; its role here is unknown.
}
