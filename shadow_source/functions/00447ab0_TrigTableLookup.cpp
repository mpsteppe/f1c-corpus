// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00447AB0
// Canonical corpus name: TrigTableLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TrigTableLookup_00447ab0.c

void UnknownObject::TrigTableLookup()
{
    // Linear-interpolated lookup into a 256-entry single-precision trig table. Reads the double input at this[12] (byte offset 0x60), scales it by 4.0 and subtracts 0.5, then uses the integer-truncated result as a byte table index and the fractional part to interpolate between that entry and the next. Returns the interpolated double. No branches, no calls.
    // ASSIGNMENT: Read the input double this[12] (byte offset 0x60) and scale it by 4.0 into v4. [field:this:0x00000060, source:raw]
    // CALCULATION: v3 = v4 - 0.5, offsetting the scaled value before index truncation. [source:raw]
    // ASSIGNMENT: Read the lower table entry: v1 = flt_8AAE74[(unsigned __int8)(int)v3], index wrapped to a byte. [global:0x008AAE74, source:raw]
    // CALCULATION: Compute the fractional interpolation weight (v4 - (double)(int)v3) between the two adjacent table entries. [source:raw]
    // CALCULATION: Interpolate: v1 + (flt_8AAE74[(unsigned __int8)((int)v3 + 1)] - v1) * fraction. [global:0x008AAE74, source:raw]
    // RETURN: Return the interpolated trig table value. [source:raw]

    // Conservative worker pseudocode:
    //   double sub_447AB0(double *this) {
    //     double v4 = this[12] * 4.0;
    //     double v3 = v4 - 0.5;
    //     int i = (int)v3;
    //     double v1 = flt_8AAE74[(unsigned char)i];
    //     return v1 + (flt_8AAE74[(unsigned char)(i + 1)] - v1) * (v4 - (double)i);
    //   }
    // UNRESOLVED: Skeleton facts list global 0x0059E7D8 (dbl_59E7D8) and 0x0059E880 (dbl_59E880) as referenced, but the raw decompiled source reads neither; the discrepancy is unresolved.
    // UNRESOLVED: Owner object and the semantics of the trig table (sine/cosine/heading tables) are unknown; callers RandomPhysicsParameterGenerator (0x00447B10) and TireFrictionCurveEval (0x00447BB0) are the only consumers.
}
