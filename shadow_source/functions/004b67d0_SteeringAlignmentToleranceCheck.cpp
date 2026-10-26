// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B67D0
// Canonical corpus name: SteeringAlignmentToleranceCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SteeringAlignmentToleranceCheck_004b67d0.c

void UnknownObject::SteeringAlignmentToleranceCheck()
{
    // Checks whether an angular difference a2 is within a tolerance scaled by field 0x9AC (an index 0..3) and an additional factor a3. Selects a base tolerance v8 from a switch on (this[0x9AC] - 1); returns 1 immediately when |a2| <= v8; otherwise selects a multiplier v6 from a second switch, computes v7 = max(v8 * 2, v6 * a3), and returns 1 when |a2| <= v7.
    // CALCULATION: Compute switch selector v3 = this[0x9AC] - 1. [source:raw, field:this:0x000009AC]
    // GUARD: First switch on v3 (case 0..3, default): select base tolerance v8 as 0.049087387 / 0.024543693 / 0.016362462 / 0.012271847, default 0.098174773. [source:raw, global:0x004B689C]
    // CALCULATION: Compute absolute value of a2 (|a2|). [source:raw]
    // GUARD: Guard: if |a2| <= v8, return 1 (angle already within base tolerance). [source:raw]
    // GUARD: Second switch on v3 (case 0..3, default): select multiplier tolerance v6 as 0.088799998 / 0.066699997 / 0.022500001 / 0.015, default 0.1. [source:raw, global:0x004B68AC]
    // CALCULATION: Compute v9 = v8 + v8 and v7 = v6 * a3; if v9 > v7 then v7 = v9, yielding v7 = max(2 * v8, v6 * a3). [source:raw]
    // RETURN: Return (|a2| <= v7). [source:raw]

    // Conservative worker pseudocode:
    //   bool SteeringAlignmentToleranceCheck(int* this, float angle, float factor) {
    //     int idx = this[0x9AC / 4] - 1;
    //     float base_tol;
    //     switch (idx) {
    //       case 0: base_tol = 0.049087387f; break;
    //       case 1: base_tol = 0.024543693f; break;
    //       case 2: base_tol = 0.016362462f; break;
    //       case 3: base_tol = 0.012271847f; break;
    //       default: base_tol = 0.098174773f; break;
    //     }
    //     float a = fabs(angle);
    //     if (a <= base_tol) return true;
    //     float mult_tol;
    //     switch (idx) {
    //       case 0: mult_tol = 0.088799998f; break;
    //       case 1: mult_tol = 0.066699997f; break;
    //       case 2: mult_tol = 0.022500001f; break;
    //       case 3: mult_tol = 0.015f; break;
    //       default: mult_tol = 0.1f; break;
    //     }
    //     float limit = mult_tol * factor;
    //     if (base_tol + base_tol > limit) limit = base_tol + base_tol;
    //     return a <= limit;
    //   }
    // UNRESOLVED: Field 0x9AC is a difficulty/assist index 0..3; its exact meaning and setter are not evidenced here.
    // UNRESOLVED: a3 factor semantics (input to the scaled tolerance) are caller-dependent, not defined in this function.
    // UNRESOLVED: flt_59E84C, flt_5ACD44, flt_5ACD58, flt_5ACD5C, flt_5ACD60 are listed as read globals but do not appear in the raw decompilation; which tolerance constant each supplies is not determinable from this packet.
    // UNRESOLVED: fabs is an intrinsic; no callee evidence exists for it.
}
