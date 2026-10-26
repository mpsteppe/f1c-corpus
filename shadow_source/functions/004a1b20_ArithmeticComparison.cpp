// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A1B20
// Canonical corpus name: ArithmeticComparison
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_004a1b20.c

void UnknownObject::ArithmeticComparison()
{
    // Appends one of two global string constants to the destination string a1: selects global a1 (0x005CD138) by default, switching to global a0 (0x005CD12C) when the byte at a2 is zero, then concatenates the selection onto a1 with strcat. Returns 0 unconditionally. Invoked by ConfigKeyValueSerialize (0x004B1C80) to serialize a config value as text; the a0/a1 globals are the two candidate text fragments chosen by the a2 byte.
    // ASSIGNMENT: Default the text selection v2 to the read-global a1 (0x005CD138). [global:0x005CD138, source:raw]
    // GUARD: When the byte at a2 (*a2) is zero, switch the text selection to the read-global a0 (0x005CD12C). [global:0x005CD12C, source:raw]
    // CALL: strcat(a1, v2) appends the selected global text fragment to the destination string; strcat is an implicit CRT call not listed in the packet's callees. [caller:0x004B1C80, source:raw]
    // RETURN: Return 0 unconditionally. [source:raw]

    // Conservative worker pseudocode:
    //   int ArithmeticComparison(char *dst, const char *flag) {
    //     const char *text = global_a1;  // read-global at 0x005CD138
    //     if (!*flag) text = global_a0;  // read-global at 0x005CD12C
    //     strcat(dst, text);
    //     return 0;
    //   }
    // UNRESOLVED: The contents of globals a0 (0x005CD12C) and a1 (0x005CD138) are not evidenced by the packet; docs/12 names them PrefixStringB and StringPrefixA (DERIVED), suggesting the a2 byte selects between two serialized-value text fragments, but that reading is unconfirmed.
    // UNRESOLVED: strcat is reconstructed from the raw source text; it is an implicit CRT call with no packet callee evidence entry.
    // UNRESOLVED: The decompiled body reuses the parameter name a1 for the read-global a1 (0x005CD138); the two referents are distinct.
}
