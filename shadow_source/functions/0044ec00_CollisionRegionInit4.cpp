// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044EC00
// Canonical corpus name: CollisionRegionInit4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionRegionInit4_0044ec00.c

void UnknownObject::CollisionRegionInit4()
{
    // Unconditional initializer for a fixed collision-region block (dword_7CA3F8 through dword_7CA40C): writes region type literal 99, zeroes four region/render fields, and sets the region threshold literal 9000. Returns 0. No branches, no callees, no inputs.
    // ASSIGNMENT: Write region type literal 99 to dword_7CA3F8. [global:0x007CA3F8, source:raw]
    // ASSIGNMENT: Zero the four consecutive region fields dword_7CA3FC, dword_7CA400, dword_7CA404 and dword_7CA408. [global:0x007CA3FC, global:0x007CA400, global:0x007CA404, global:0x007CA408, source:raw]
    // ASSIGNMENT: Write region threshold literal 9000 to dword_7CA40C. [global:0x007CA40C, source:raw]
    // RETURN: Return 0 as the fixed result. [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionRegionInit4() {
    //     dword_7CA3F8 = 99;
    //     dword_7CA3FC = 0;
    //     dword_7CA400 = 0;
    //     dword_7CA404 = 0;
    //     dword_7CA408 = 0;
    //     dword_7CA40C = 9000;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic meaning of the fixed 99 tag and the 9000 threshold is not evidenced in this packet; the values match a collision-region block pattern shared with neighboring init functions.
    // UNRESOLVED: Owner object holding the dword_7CA3F8..dword_7CA40C block is unknown; globals are untyped dwords.
}
