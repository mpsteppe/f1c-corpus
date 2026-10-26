// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E300
// Canonical corpus name: SpatialNodeInit_e300
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpatialNodeInit_e300_0044e300.c

void UnknownObject::SpatialNodeInit_e300()
{
    // Unconditional single-block initialization of six adjacent DWORD globals. Writes an element-count-like tag of 75 into dword_7CD0B0, zeroes four following fields (dword_7CD0B4/0B8/0BC/0C0), and writes 9000 as a max-search-distance-like value into dword_7CD0C4. Returns constant 0.
    // ASSIGNMENT: dword_7CD0B0 = 75 (tag / element count literal). [global:0x007CD0B0, source:raw]
    // ASSIGNMENT: dword_7CD0B4 = 0. [global:0x007CD0B4, source:raw]
    // ASSIGNMENT: dword_7CD0B8 = 0. [global:0x007CD0B8, source:raw]
    // ASSIGNMENT: dword_7CD0BC = 0. [global:0x007CD0BC, source:raw]
    // ASSIGNMENT: dword_7CD0C0 = 0. [global:0x007CD0C0, source:raw]
    // ASSIGNMENT: dword_7CD0C4 = 9000 (max search distance literal). [global:0x007CD0C4, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   dword_7CD0B0 = 75;
    //   dword_7CD0B4 = 0;
    //   dword_7CD0B8 = 0;
    //   dword_7CD0BC = 0;
    //   dword_7CD0C0 = 0;
    //   dword_7CD0C4 = 9000;
    //   return 0;
    // UNRESOLVED: Semantic roles of the six globals are not established by the packet; the DERIVED names in existing analysis (element count, material config, max search distance) are unverified.
    // UNRESOLVED: Owner object identity is not established by the packet.
    // UNRESOLVED: No static callers recorded, so the init's invocation context is unknown.
}
