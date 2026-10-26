// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044DD00
// Canonical corpus name: CollisionRegionInit2
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionRegionInit2_0044dd00.c

void UnknownObject::CollisionRegionInit2()
{
    // Initializes a collision region: stores type value 51 in dword_7CCE88 and zeroes the five following region parameter fields (dword_7CCE8C through dword_7CCE9C). All writes are unconditional; the function returns 0.
    // ASSIGNMENT: Write the literal 51 (region type) to dword_7CCE88. [global:0x007CCE88, source:raw]
    // ASSIGNMENT: Zero dword_7CCE8C. [global:0x007CCE8C, source:raw]
    // ASSIGNMENT: Zero dword_7CCE90. [global:0x007CCE90, source:raw]
    // ASSIGNMENT: Zero dword_7CCE94. [global:0x007CCE94, source:raw]
    // ASSIGNMENT: Zero dword_7CCE98. [global:0x007CCE98, source:raw]
    // ASSIGNMENT: Zero dword_7CCE9C. [global:0x007CCE9C, source:raw]
    // RETURN: Return 0 (result initialized to 0 and never modified). [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionRegionInit2() {
    //     int result = 0;
    //     dword_7CCE88 = 51;
    //     dword_7CCE8C = 0;
    //     dword_7CCE90 = 0;
    //     dword_7CCE94 = 0;
    //     dword_7CCE98 = 0;
    //     dword_7CCE9C = 0;
    //     return result;
    //   }
    // UNRESOLVED: Semantic meaning of the 51 literal (interpreted as a collision region type by the fill, but unverified).
    // UNRESOLVED: Meaning of the five zeroed region parameter fields; no reader evidence in this packet.
}
