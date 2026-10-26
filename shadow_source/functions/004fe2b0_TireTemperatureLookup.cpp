// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FE2B0
// Canonical corpus name: sub_4FE2B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4FE2B0_004fe2b0.c

void UnknownObject::TireTemperatureLookup()
{
    // Maps a temperature category name (passed as string a1) to a numeric tire temperature/pressure value. Uses sub_588410, which returns 0 on a string match, in a cascading chain: the first category pointer off_5D6FD4 maps to 32.5, Warm to 26.25, Medium to 20.0, Cool to 13.75, Cold to a value computed by sub_58850F, and any unmatched name falls through to the default 7.5. Every input resolves to a value on some path.
    // CALL: Compare a1 against the first category name pointer off_5D6FD4 using sub_588410. [callee:0x00588410, global:0x005D6FD4, source:raw]
    // GUARD: If sub_588410 returns 0 (match on the first category), return 32.5. [source:raw]
    // CALL: Compare a1 against the Warm category string aWarm. [callee:0x00588410, global:0x005D6FCC, source:raw]
    // GUARD: If the Warm category matches, return 26.25. [source:raw]
    // CALL: Compare a1 against the Medium category string aMedium. [callee:0x00588410, global:0x005C6EB8, source:raw]
    // GUARD: If the Medium category matches, return 20.0. [source:raw]
    // CALL: Compare a1 against the Cool category string aCool. [callee:0x00588410, global:0x005D6FC4, source:raw]
    // GUARD: If the Cool category matches, return 13.75. [source:raw]
    // CALL: Compare a1 against the Cold category string aCold. [callee:0x00588410, global:0x005D6FBC, source:raw]
    // CALL: When a1 matches the Cold category, compute the value by calling sub_58850F(a1) and return it. [callee:0x0058850F, global:0x005D6FBC, source:raw]
    // RETURN: Fall back to the default value 7.5 when no category matched. [source:raw]

    // Conservative worker pseudocode:
    //   double sub_4FE2B0(int a1) {
    //     if (!sub_588410(a1, &off_5D6FD4)) return 32.5;
    //     if (!sub_588410(a1, aWarm))   return 26.25;
    //     if (!sub_588410(a1, aMedium)) return 20.0;
    //     if (!sub_588410(a1, aCool))   return 13.75;
    //     if (sub_588410(a1, aCold))    return sub_58850F(a1);
    //     return 7.5;
    //   }
    // UNRESOLVED: sub_588410 return convention (0 meaning a match) is inferred from the !result usage pattern, not documented in this packet.
    // UNRESOLVED: String content of off_5D6FD4 (the first, highest-value category) is not shown; it is a name pointer only.
    // UNRESOLVED: The floats flt_59E8EC, flt_59E8F4, flt_5AD328, flt_5AD32C and flt_5AD330 are listed as read globals of the packet but are not referenced by this function's raw source; their association here is unresolved.
    // UNRESOLVED: Whether the returned value is a temperature or a pressure and the meaning of the sub_58850F computation for Cold are not determinable from this function alone.
}
