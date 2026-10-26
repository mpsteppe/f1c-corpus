// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047E940
// Canonical corpus name: ConditionalCallWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalCallWrapper_0047e940.c

void UnknownObject::ConditionalCallWrapper()
{
    // Conditional passthrough wrapper: when argument a1 is non-zero it calls StringCopyWithBufferRealloc(a1) and returns that call's result; when a1 is zero it skips the call and returns a1 (zero) unchanged. Used as a safe indirection so a null/zero argument never reaches the string-copy call. Called from InitFromDataBlock (0047EE5C) and PercentageDisplayFormatter (0047EF3C).
    // ASSIGNMENT: Seed the result with the incoming argument: result = a1, establishing the default return path before the guard. [source:raw]
    // GUARD: Guard on a1 being non-zero; the zero case skips the string-copy call entirely and returns a1 (0) via the seeded result. [source:raw]
    // CALL: When a1 is non-zero, invoke StringCopyWithBufferRealloc(a1) and store its return value into result, overriding the seeded value. [source:raw]
    // RETURN: Return the result: the StringCopyWithBufferRealloc return value on the non-zero path, or the original a1 (zero) on the early path. [function:0x0047E940, source:raw]
    // CALL: Called from InitFromDataBlock (0047EE5C) and PercentageDisplayFormatter (0047EF3C), both formatting/initialization paths that route a possibly-empty string handle through this conditional wrapper. [caller:0x0047EE5C, caller:0x0047EF3C]

    // Conservative worker pseudocode:
    //   int sub_47E940(int a1) {
    //     int result = a1;
    //     if (a1) {
    //       result = StringCopyWithBufferRealloc(a1);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: StringCopyWithBufferRealloc is referenced only by name in the raw source; it has no callee entry or address in this packet, so its location and exact semantics cannot be grounded here.
    // UNRESOLVED: The meaning of a1 (likely a string buffer or handle) and the reason for the null/zero guard (probably buffer-null safety) are inferred from the guard structure and callee name only.
    // UNRESOLVED: The caller names InitFromDataBlock and PercentageDisplayFormatter are legacy ABI-derived and were not independently verified.
}
