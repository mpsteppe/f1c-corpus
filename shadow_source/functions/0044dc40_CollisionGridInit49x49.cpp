// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044DC40
// Canonical corpus name: CollisionGridInit49x49
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGridInit49x49_0044dc40.c

void UnknownObject::CollisionGridInit49x49()
{
    // Collision-grid initializer: writes element 0 of the array global dword_7CCE58 (0x007CCE58) with the literal 49 (the grid dimension) and zeroes the five consecutive state fields at 0x007CCE5C through 0x007CCE6C, then returns 0. No calls, no guards. The five zeroed fields' semantic roles are not evidenced in this packet.
    // ASSIGNMENT: Element 0 of array global dword_7CCE58 (0x007CCE58) is written with the literal 49, the 49x49 grid dimension [global:0x007CCE58, source:raw]
    // ASSIGNMENT: dword_7CCE5C (0x007CCE5C) is zeroed [global:0x007CCE5C, source:raw]
    // ASSIGNMENT: dword_7CCE60 (0x007CCE60) is zeroed [global:0x007CCE60, source:raw]
    // ASSIGNMENT: dword_7CCE64 (0x007CCE64) is zeroed [global:0x007CCE64, source:raw]
    // ASSIGNMENT: dword_7CCE68 (0x007CCE68) is zeroed [global:0x007CCE68, source:raw]
    // ASSIGNMENT: dword_7CCE6C (0x007CCE6C) is zeroed [global:0x007CCE6C, source:raw]
    // RETURN: The function returns the integer 0 [source:raw]

    // Conservative worker pseudocode:
    //   dword_7CCE58[0] = 49;
    //   dword_7CCE5C = 0;
    //   dword_7CCE60 = 0;
    //   dword_7CCE64 = 0;
    //   dword_7CCE68 = 0;
    //   dword_7CCE6C = 0;
    //   return 0;
    // UNRESOLVED: Semantic purpose of the five zeroed globals at 0x007CCE5C-0x007CCE6C is not resolvable from this packet (DERIVED prose names in the existing analysis are not packet evidence)
    // UNRESOLVED: No caller or call frequency evidence exists in this packet, so invocation context is unknown
}
