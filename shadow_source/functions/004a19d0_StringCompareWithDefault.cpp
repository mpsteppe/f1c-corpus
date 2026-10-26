// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A19D0
// Canonical corpus name: StringCompareWithDefault
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCompareWithDefault_004a19d0.c

void UnknownObject::StringCompareWithDefault()
{
    // String compare against a default: __stdcall helper that sets the output bool *a2 to whether the input string a1 differs (strcmp != 0) from the global string at 0x005CD12C, then returns the constant 1. No guards, callees, or callers evidenced in the packet.
    // CALCULATION: Evaluate strcmp(a1, a0) != 0, i.e. whether a1 differs from the global default string at 0x005CD12C [global:0x005CD12C, source:raw]
    // ASSIGNMENT: Store the inequality result into the output bool *a2 [source:raw]
    // RETURN: Return the constant 1, independent of the comparison result [source:raw]

    // Conservative worker pseudocode:
    //   *a2 = strcmp(a1, a0) != 0;
    //   return 1;
    // UNRESOLVED: The role of the global default string at 0x005CD12C and the meaning of the constant return value 1 are not evidenced in this packet
}
