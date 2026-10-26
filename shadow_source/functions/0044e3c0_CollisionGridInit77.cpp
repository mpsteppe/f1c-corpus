// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E3C0
// Canonical corpus name: CollisionGridInit77
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGridInit77_0044e3c0.c

void UnknownObject::CollisionGridInit77()
{
    // Collision-grid initializer: writes the grid dimension global dword_7CD130 (0x007CD130) with the literal 77, zeroes the four consecutive state fields at 0x007CD134 through 0x007CD140, writes dword_7CD144 (0x007CD144) with the literal 27000, then returns 0. No calls, no guards. The zeroed fields' semantic roles are not evidenced in this packet.
    // ASSIGNMENT: Grid dimension global dword_7CD130 (0x007CD130) is written with the literal 77, the 77-wide grid dimension [global:0x007CD130, source:raw]
    // ASSIGNMENT: dword_7CD134 (0x007CD134) is zeroed [global:0x007CD134, source:raw]
    // ASSIGNMENT: dword_7CD138 (0x007CD138) is zeroed [global:0x007CD138, source:raw]
    // ASSIGNMENT: dword_7CD13C (0x007CD13C) is zeroed [global:0x007CD13C, source:raw]
    // ASSIGNMENT: dword_7CD140 (0x007CD140) is zeroed [global:0x007CD140, source:raw]
    // ASSIGNMENT: dword_7CD144 (0x007CD144) is written with the literal 27000, a maximum-distance parameter [global:0x007CD144, source:raw]
    // RETURN: The function returns the integer 0 [source:raw]

    // Conservative worker pseudocode:
    //   dword_7CD130 = 77;
    //   dword_7CD134 = 0;
    //   dword_7CD138 = 0;
    //   dword_7CD13C = 0;
    //   dword_7CD140 = 0;
    //   dword_7CD144 = 27000;
    //   return 0;
    // UNRESOLVED: Semantic purpose of the four zeroed globals at 0x007CD134-0x007CD140 is not resolvable from this packet (DERIVED prose names in the existing analysis are not packet evidence)
    // UNRESOLVED: The exact meaning of the 27000 literal at 0x007CD144 (proposed max distance) is a DERIVED reading of the existing analysis, not packet evidence
    // UNRESOLVED: No caller or call frequency evidence exists in this packet, so invocation context is unknown
}
