// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A4830
// Canonical corpus name: TireCompoundNameIDMapping
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireCompoundNameIDMapping_004a4830.c

void UnknownObject::TireCompoundNameToId()
{
    // Maps a tire-compound name string to a compound id by a chain of string comparisons against five compound literals via sub_588410 (which returns 0 on an exact match). Exact match against Hard returns 2, Soft returns 3, Intermediate returns 4. The wet string is tested with the opposite polarity: a non-wet input falls into a nested monsoon comparison returning 6 when Monsoon matches and 1 otherwise, while a wet input falls through to the default return 5. Net mapping per the raw source: Hard=2, Soft=3, Intermediate=4, Wet=5, Monsoon=6, any other string=1.
    // CALL: Compare the input string against aHardCompound (0x005CD534) via sub_588410 (0x00588410); returns 0 on an exact match [callee:0x00588410, global:0x005CD534, source:raw]
    // RETURN: Exact match against the Hard compound returns compound id 2 [source:raw]
    // CALL: Compare the input string against aSoftCompound (0x005CD524) via sub_588410 [callee:0x00588410, global:0x005CD524, source:raw]
    // RETURN: Exact match against the Soft compound returns compound id 3 [source:raw]
    // CALL: Compare the input string against aIntermediateCo (0x005CD50C) via sub_588410 [callee:0x00588410, global:0x005CD50C, source:raw]
    // RETURN: Exact match against the Intermediate compound returns compound id 4 [source:raw]
    // CALL: Compare the input string against aWetCompound (0x005C7224) via sub_588410; unlike the earlier checks this branch is taken when the comparison returns non-zero, i.e. when the input is NOT the wet compound [callee:0x00588410, global:0x005C7224, source:raw]
    // GUARD: If the wet comparison does not match (non-zero), a nested comparison against aMonsoonCompoun selects the returned id; if the input IS the wet compound, control falls through to the default return 5 [global:0x005C7224, source:raw]
    // CALL: Compare the input string against aMonsoonCompoun (0x005CD4F8) via sub_588410 [callee:0x00588410, global:0x005CD4F8, source:raw]
    // RETURN: Non-wet branch result: return 6 when the Monsoon comparison matches (0), return 1 when it does not match (non-zero) [source:raw]
    // RETURN: Default fall-through (input matches the wet compound) returns compound id 5 [global:0x005C7224, source:raw]
    // CALL: Shared compound-name classification helper reached from AI and pit paths: sub_429960, RandomWeightedTierSelection (00429fd0), AIPushLap (0042a180), GuardedCallWithCheck (004a5c10) and sub_4F18C0 [caller:0x00429960, caller:0x00429FD0, caller:0x0042A180, caller:0x004A5C10, caller:0x004F18C0, source:raw]

    // Conservative worker pseudocode:
    //   int TireCompoundNameToId(this, compoundName) {
    //     if (sub_588410(this, aHardCompound) == 0)      // "Hard"
    //       return 2;
    //     if (sub_588410(this, aSoftCompound) == 0)      // "Soft"
    //       return 3;
    //     if (sub_588410(this, aIntermediateCo) == 0)    // "Intermediate"
    //       return 4;
    //     if (sub_588410(this, aWetCompound) != 0) {     // NOT "Wet"
    //       return sub_588410(this, aMonsoonCompoun) == 0 ? 6 : 1;  // "Monsoon" -> 6, other -> 1
    //     }
    //     return 5;                                       // "Wet" -> 5
    //   }
    // UNRESOLVED: Semantic meaning of the returned compound ids 1-6 (the game's internal tire-compound enum) is not visible in this packet.
    // UNRESOLVED: Exact string contents of the five compound literals are not in the packet; literal addresses are known only.
    // UNRESOLVED: sub_588410 is treated as a string-equality helper returning 0 on match per prior analysis; that behavior is not proven by this packet alone.
    // UNRESOLVED: The wet comparison deliberately uses inverted polarity relative to the other three; whether that is a source-level ordering artifact or a genuine semantic branch is unresolved.
}
