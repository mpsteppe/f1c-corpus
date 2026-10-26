// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FE0D0
// Canonical corpus name: WeatherNameWetnessMultiplier
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WeatherNameWetnessMultiplier_004fe0d0.c

void UnknownObject::WeatherNameWetnessMultiplier()
{
    // Returns a wetness multiplier by comparing the weather name string a1 against known category strings via sub_588410: Best yields 0.030000001, Nice 0.30000001, Clear 0.60000002, Overcast 0.64999998, Drizzle 0.73000002, Rain 0.85000002, Monsoon 0.96999997. An unmatched name falls back to sub_58850F(a1) * 0.0099999998 clamped to [0.0, 1.0]. Called by sub_4FE350 (004fe350).
    // GUARD: If sub_588410(a1, aBest) returns 0 (name matches Best), return 0.030000001 [callee:0x00588410, global:0x005D6FA4, source:raw]
    // GUARD: If sub_588410(a1, aNice) returns 0 (name matches Nice), return 0.30000001 [callee:0x00588410, global:0x005D6F9C, source:raw]
    // GUARD: If sub_588410(a1, aClear_0) returns 0 (name matches Clear), return 0.60000002 [callee:0x00588410, global:0x005D6F94, source:raw]
    // GUARD: If sub_588410(a1, aOvercast) returns 0 (name matches Overcast), return 0.64999998 [callee:0x00588410, global:0x005C6E8C, source:raw]
    // GUARD: If sub_588410(a1, aDrizzle) returns 0 (name matches Drizzle), return 0.73000002 [callee:0x00588410, global:0x005D6F8C, source:raw]
    // GUARD: If sub_588410(a1, aRain_0) returns 0 (name matches Rain), return 0.85000002 [callee:0x00588410, global:0x005D6F84, source:raw]
    // GUARD: If sub_588410(a1, aMonsoon) returns 0 (name matches Monsoon), return 0.96999997 [callee:0x00588410, global:0x005C6E7C, source:raw]
    // CALCULATION: result = sub_58850F(a1) * 0.0099999998; fallback multiplier from a continuous per-name value [callee:0x0058850F, source:raw]
    // GUARD: Clamp: if result is less than 0.0 return 0.0 [source:raw]
    // GUARD: Clamp: if result is greater than 1.0 return 1.0 [source:raw]
    // RETURN: Return the clamped computed result [function:0x004FE0D0, source:raw]

    // Conservative worker pseudocode:
    //   if (sub_588410(a1, aBest) == 0) return 0.030000001;
    //   if (sub_588410(a1, aNice) == 0) return 0.30000001;
    //   if (sub_588410(a1, aClear_0) == 0) return 0.60000002;
    //   if (sub_588410(a1, aOvercast) == 0) return 0.64999998;
    //   if (sub_588410(a1, aDrizzle) == 0) return 0.73000002;
    //   if (sub_588410(a1, aRain_0) == 0) return 0.85000002;
    //   if (sub_588410(a1, aMonsoon) == 0) return 0.96999997;
    //   result = sub_58850F(a1) * 0.0099999998;
    //   if (result < 0.0) return 0.0;
    //   if (result > 1.0) return 1.0;
    //   return result;
    // UNRESOLVED: sub_588410 return semantics (exact string equality versus match by value) are not documented; the fixed-multiplier returns are interpreted as firing on a match per the prelabel analysis
    // UNRESOLVED: sub_58850F's per-name value source is not documented
    // UNRESOLVED: Ten read-only float globals (flt_59E43C, flt_59E440, flt_59E444, flt_59E4E8, flt_59E8B4, flt_59E8F8, flt_59E908, flt_5AD31C, flt_5AD320, flt_5AD324) are flagged by packet facts but appear nowhere in the raw decompiled source; their role is not verifiable here
}
