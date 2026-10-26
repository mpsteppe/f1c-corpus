// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044ECC0
// Canonical corpus name: CollisionTableInit65
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionTableInit65_0044ecc0.c

void UnknownObject::CollisionTableInit65()
{
    // Unconditional initializer for a fixed collision-table block (dword_7CA458 through dword_7CA46C): writes table tag literal 101, zeroes four consecutive table fields, and sets the table index/threshold literal 27000. Returns 0. No branches, no callees, no inputs.
    // ASSIGNMENT: Write table tag literal 101 to dword_7CA458. [global:0x007CA458, source:raw]
    // ASSIGNMENT: Zero the four consecutive table fields dword_7CA45C, dword_7CA460, dword_7CA464 and dword_7CA468. [global:0x007CA45C, global:0x007CA460, global:0x007CA464, global:0x007CA468, source:raw]
    // ASSIGNMENT: Write table index/threshold literal 27000 to dword_7CA46C. [global:0x007CA46C, source:raw]
    // RETURN: Return 0 as the fixed result. [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionTableInit65() {
    //     dword_7CA458 = 101;
    //     dword_7CA45C = 0;
    //     dword_7CA460 = 0;
    //     dword_7CA464 = 0;
    //     dword_7CA468 = 0;
    //     dword_7CA46C = 27000;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic meaning of the fixed 101 tag and the 27000 index is not evidenced in this packet; the layout mirrors the neighbouring collision-region init blocks.
    // UNRESOLVED: Owner object holding the dword_7CA458..dword_7CA46C block is unknown; globals are untyped dwords.
}
