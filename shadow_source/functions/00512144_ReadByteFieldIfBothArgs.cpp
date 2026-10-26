// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00512144
// Canonical corpus name: ShortComputation_2144
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_2144_00512144.c

void UnknownObject::ReadByteFieldIfBothArgs()
{
    // Guard-conditional byte-field reader. When both object pointers a1 and a2 are non-null, returns the unsigned byte at offset 29 of a2; otherwise returns 0. No side effects; used by sub_50210E as a value lookup helper.
    // GUARD: Guard on a1 being non-null; when null the function returns 0. [source:raw, function:0x00512144]
    // GUARD: Guard on a2 being non-null; when null the function returns 0. [source:raw, function:0x00512144]
    // ASSIGNMENT: Read the unsigned byte at a2 + 29 as the return value. [source:raw]
    // RETURN: Return the byte at a2 + 29 when both guards pass, otherwise 0. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_512144(int a1, int a2) {
    //     if (a1 && a2)
    //       return *(unsigned char *)(a2 + 29);
    //     return 0;
    //   }
    // UNRESOLVED: Identity of a1 and a2 object types is unknown; a2 is a struct whose byte at +29 holds a config-like value, a1 appears to be an enable/ownership guard.
    // UNRESOLVED: Semantic meaning of the byte at offset 29 is not established.
}
