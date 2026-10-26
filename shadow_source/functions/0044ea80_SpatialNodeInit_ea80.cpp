// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044EA80
// Canonical corpus name: SpatialNodeInit_ea80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpatialNodeInit_ea80_0044ea80.c

void UnknownObject::SpatialNodeInit_ea80()
{
    // Unconditional single-block initialization of six adjacent DWORD globals. Writes an element-count-like tag of 95 into dword_7CA4E0, zeroes four following fields (dword_7CA4E4/0E8/0EC/0F0), and writes 9000 as a max-search-distance-like value into dword_7CA4F4. Returns constant 0.
    // ASSIGNMENT: dword_7CA4E0 = 95 (tag / element count literal). [global:0x007CA4E0, source:raw]
    // ASSIGNMENT: dword_7CA4E4 = 0. [global:0x007CA4E4, source:raw]
    // ASSIGNMENT: dword_7CA4E8 = 0. [global:0x007CA4E8, source:raw]
    // ASSIGNMENT: dword_7CA4EC = 0. [global:0x007CA4EC, source:raw]
    // ASSIGNMENT: dword_7CA4F0 = 0. [global:0x007CA4F0, source:raw]
    // ASSIGNMENT: dword_7CA4F4 = 9000 (max search distance literal). [global:0x007CA4F4, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   dword_7CA4E0 = 95;
    //   dword_7CA4E4 = 0;
    //   dword_7CA4E8 = 0;
    //   dword_7CA4EC = 0;
    //   dword_7CA4F0 = 0;
    //   dword_7CA4F4 = 9000;
    //   return 0;
    // UNRESOLVED: Semantic roles of the six globals are not established by the packet; the DERIVED names in existing analysis (element count, wheel setting, max search distance) are unverified.
    // UNRESOLVED: Owner object identity is not established by the packet.
    // UNRESOLVED: No static callers recorded, so the init's invocation context is unknown.
}
