// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FE1E0
// Canonical corpus name: WeatherSeverityGripMultiplier
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WeatherSeverityGripMultiplier_004fe1e0.c

void UnknownObject::WeatherSeverityGripMultiplier()
{
    // Returns a grip/severity multiplier in the range 0.0-1.0 from a weather severity name. The input identifier is compared in cascade against the known severity names; each exact name match returns a fixed multiplier (base name 0.0, "Damp" 0.25, intermediate name 0.5, "Soaked" 0.75, "Monsoon" 1.0). When no named severity matches, a numeric severity value read via sub_58850F is scaled by 0.0099999998 and clamped to the unit interval.
    // CALL: First named-severity match: compares a1 against the base severity name pointer off_5C6E98 via sub_588410; on a match (sub_588410 returns 0) the function returns 0.0 [callee:0x00588410, global:0x005C6E98, source:raw]
    // CALL: Second named-severity match: compares a1 against the "Damp" severity string aDamp via sub_588410; on a match the function returns 0.25 [callee:0x00588410, global:0x005D6FB4, source:raw]
    // CALL: Third named-severity match: compares a1 against the intermediate severity name pointer off_5C7234 via sub_588410; on a match the function returns 0.5 [callee:0x00588410, global:0x005C7234, source:raw]
    // CALL: Fourth named-severity match: compares a1 against the "Soaked" severity string aSoaked via sub_588410; on a match the function returns 0.75 [callee:0x00588410, global:0x005D6FAC, source:raw]
    // CALL: Fifth named-severity match: compares a1 against the "Monsoon" severity string aMonsoon via sub_588410; on a match the function returns 1.0 [callee:0x00588410, global:0x005C6E7C, source:raw]
    // CALCULATION: Fallback path when no named severity matches: multiplies the numeric severity read via sub_58850F(a1) by the scaling factor 0.0099999998 [callee:0x0058850F, source:raw]
    // GUARD: Lower clamp: if the scaled fallback result is below 0.0 the function returns 0.0 [source:raw]
    // GUARD: Upper clamp: if the scaled fallback result exceeds 1.0 the function returns 1.0 [source:raw]
    // RETURN: Returns the scaled fallback result when it lies within the unit interval [source:raw]

    // Conservative worker pseudocode:
    //   double WeatherSeverityGripMultiplier(int a1) {
    //     if (!sub_588410(a1, &off_5C6E98)) return 0.0;
    //     if (!sub_588410(a1, aDamp))      return 0.25;
    //     if (!sub_588410(a1, &off_5C7234)) return 0.5;
    //     if (!sub_588410(a1, aSoaked))    return 0.75;
    //     if (!sub_588410(a1, aMonsoon))   return 1.0;
    //     double r = sub_58850F(a1) * 0.0099999998;
    //     if (r < 0.0) return 0.0;
    //     if (r > 1.0) return 1.0;
    //     return r;
    //   }
    // UNRESOLVED: Six read-only globals (flt_59E43C, flt_59E440, flt_59E444, flt_59E450, flt_59E7F8, flt_59E7FC) are flagged by packet facts but appear nowhere in the raw decompiled source; the skeleton fill labels them physics constants (zero threshold, frame delta, degrees-to-radians, mixing/damping factors), all unverifiable from this packet
    // UNRESOLVED: The exact identity of the two pointer globals off_5C6E98 and off_5C7234 (unknown severity names) is not evidenced; only the string globals aDamp, aSoaked and aMonsoon carry literal text
    // UNRESOLVED: The scaling factor 0.0099999998 applied to the sub_58850F result has no documented unit; the transform from the raw numeric severity to a grip multiplier is not evidenced
    // UNRESOLVED: The meaning of the numeric severity returned by sub_58850F is not evidenced by this packet
}
