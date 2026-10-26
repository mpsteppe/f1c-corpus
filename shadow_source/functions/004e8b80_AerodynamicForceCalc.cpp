// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E8B80
// Canonical corpus name: AerodynamicForceCalc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AerodynamicForceCalc_004e8b80.c

void UnknownObject::AerodynamicForceCalc()
{
    // Computes an aerodynamic force from a squared speed input a2 with a weight-compensation term (gravity 9.8100004 scaled by sprung-mass factor), a table lookup with linear interpolation across a 14-entry table indexed by the truncated force value, a drag cross-term, and a quadratic-form branch that returns a corrected speed or 0.0. Invokes sub_5895A2 on the intermediate force with the result discarded.
    // CALCULATION: v4 = a2 * a2 (squared speed input), cached as the base quadratic term. [abi:lead, source:raw]
    // CALCULATION: v6 = (v4 * this+0x3A70 - (v4 * 0.0 - 9.8100004) * this+0x3514) * this+0x3BFC (aero coefficient times squared speed minus weight compensation, scaled by the force factor). [field:this:0x00003A70, field:this:0x00003514, field:this:0x00003BFC, source:raw]
    // CALL: Call sub_5895A2(v6) with the intermediate force value; return value is not used. [callee:0x005895A2, caller:0x00425920, source:raw]
    // CALCULATION: Build lookup index v7 = (int)v6; if v7 >= 14 clamp to 13; if v7 < 0 use table entry 0. Linear interpolation between this+0x3C00 table entries v7 and v7+1: v8 = table[v7] + (table[v7+1] - table[v7]) * (v6 - v7). [field:this:0x00003C00, source:raw]
    // CALCULATION: v10 = v8 * this+0x3518, capped at this+0x3D3C when v10 exceeds it (maximum force cap). [field:this:0x00003518, field:this:0x00003D3C, source:raw]
    // CALCULATION: v15 = this+0x3D44 * this+0x3518 * v4 + v10 (drag/cross-term coefficient times the force factor times squared speed, plus the capped interpolated term). [field:this:0x00003D44, field:this:0x00003518, source:raw]
    // GUARD: When v15 > 0.0: form v13 = v4 - (-a3 * v12 * 4.0) with v12 = v15 * -0.5; if v13 > 0.0 return a2 - (sqrt(v13) - a2) / (v12 + v12) * v15 * a4, else return 0.0. [source:raw]
    // GUARD: When v15 <= 0.0: return a2 if a2 >= 1.0, otherwise return 0.0. [source:raw]
    // RETURN: Return the computed aerodynamic force value from the selected branch. [source:raw]

    // Conservative worker pseudocode:
    //   v4 = a2 * a2;
    //   v6 = (v4 * this[0x3A70] - (v4 * 0.0f - 9.8100004f) * this[0x3514]) * this[0x3BFC];
    //   sub_5895A2(v6);
    //   i = (int)v6; if (i >= 14) i = 13;
    //   v8 = (i >= 0) ? table[i] + (table[i+1] - table[i]) * (v6 - i) : table[0];
    //   v10 = v8 * this[0x3518]; if (v10 > this[0x3D3C]) v10 = this[0x3D3C];
    //   v15 = this[0x3D44] * this[0x3518] * v4 + v10;
    //   if (v15 > 0.0f) { v12 = v15 * -0.5f; v13 = v4 - -a3 * v12 * 4.0f; return (v13 > 0.0f) ? a2 - (sqrt(v13) - a2) / (v12 + v12) * v15 * a4 : 0.0f; }
    //   return (a2 >= 1.0f) ? a2 : 0.0f;
    // UNRESOLVED: Globals flt_59E43C, flt_59E440, flt_59E46C, flt_59E99C, flt_5ACEB8 (listed in existing analysis as physics constants) have no usage site grounded in the raw source.
    // UNRESOLVED: Semantics of sub_5895A2 are unknown; its argument is the intermediate force and its return is discarded.
    // UNRESOLVED: The exact physical meaning of the quadratic branch (speed correction vs distance-based force) is not confirmed by the packet.
}
