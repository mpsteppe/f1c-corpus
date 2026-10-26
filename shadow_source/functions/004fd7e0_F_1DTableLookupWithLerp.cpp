// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FD7E0
// Canonical corpus name: F_1DTableLookupWithLerp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_1DTableLookupWithLerp_004fd7e0.c

void UnknownObject::F_1DTableLookupWithLerp()
{
    // 1D float table lookup with linear interpolation. Guards on the input coordinate a2: when a2 >= 3.75 it returns the high-bound sentinel entry this[40] (offset 0xA0) directly; otherwise it scales the coordinate by 4.0, extracts an integer table index via CRTFtol, and linearly interpolates between adjacent entries this[idx+25] and this[idx+26] using the float-rounding remainder. Physics/vehicle subsystem; called per-frame by sub_4423B0 and sub_4EE2D0.
    // GUARD: If a2 >= 3.75, return this[40] (the sentinel/high-bound entry at offset 0xA0) without interpolating [field:this:0x000000A0, source:raw]
    // CALCULATION: Compute the double table coordinate v4 = a2 * 4.0 and keep a float copy v7 = v4; the float rounding loss (v7 - v4) later becomes the interpolation fraction [source:raw]
    // CALL: sub_5895A2(v4) processes the coordinate value before index extraction [callee:0x005895A2, source:raw]
    // CALCULATION: CRTFtol(v4) truncates the coordinate to the integer table index v5 [callee:0x00587BDC, source:raw]
    // CALCULATION: Linear interpolation between adjacent table entries: v6 = this[v5+25] (lower), result = (this[v5+26] - v6) * (v7 - v4) + v6 [source:raw]
    // RETURN: Return the interpolated value as a double [source:raw]

    // Conservative worker pseudocode:
    //   double F_1DTableLookupWithLerp(float* this, float a2) {
    //       if (a2 >= 3.75f) {
    //           return this[40];
    //       }
    //       double coord = a2 * 4.0;
    //       float coordF = (float)coord;
    //       sub_5895A2(coord);
    //       int idx = CRTFtol(coord);
    //       double lo = this[idx + 25];
    //       double hi = this[idx + 26];
    //       return (hi - lo) * (coordF - coord) + lo;
    //   }
    // UNRESOLVED: Globals flt_59E46C (0x0059E46C) and flt_5AD2D0 (0x005AD2D0) are flagged by packet facts but do not appear in the raw decompiled source; they are likely inputs or parameters supplied by callers rather than read here
    // UNRESOLVED: The precise purpose of sub_5895A2 is unknown; the float copy v7 of v4 implies a double-to-float narrowing that produces the interpolation fraction
    // UNRESOLVED: Table base entries this[v5+25]/this[v5+26] (float indices 25/26) have no dedicated packet field evidence ref
    // UNRESOLVED: Constant 3.75 acts as a hard high clamp; the equivalent low-bound behaviour is not visible in this function
}
