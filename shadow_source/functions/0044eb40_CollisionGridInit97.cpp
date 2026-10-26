// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044EB40
// Canonical corpus name: CollisionGridInit97
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGridInit97_0044eb40.c

void UnknownObject::CollisionGridInit97()
{
    // Straight-line initializer writing six consecutive globals in the 0x7CA51C collision-grid block: sets the grid size/tag to 97, zeroes five state fields, sets the maximum distance to 27000, and returns 0. No branches and no calls.
    // ASSIGNMENT: Set dword_7CA51C = 97, the collision grid size/tag for this block. [global:0x007CA51C, source:raw]
    // ASSIGNMENT: Set dword_7CA520 = 0. [global:0x007CA520, source:raw]
    // ASSIGNMENT: Set dword_7CA524 = 0. [global:0x007CA524, source:raw]
    // ASSIGNMENT: Set dword_7CA528 = 0. [global:0x007CA528, source:raw]
    // ASSIGNMENT: Set dword_7CA52C = 0. [global:0x007CA52C, source:raw]
    // ASSIGNMENT: Set dword_7CA530 = 27000, the collision maximum distance for this block. [global:0x007CA530, source:raw]
    // RETURN: Return the constant 0. [function:0x0044EB40, source:raw]

    // Conservative worker pseudocode:
    //   int CollisionGridInit97() {
    //     dword_7CA51C = 97;
    //     dword_7CA520 = 0;
    //     dword_7CA524 = 0;
    //     dword_7CA528 = 0;
    //     dword_7CA52C = 0;
    //     dword_7CA530 = 27000;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic roles of the zeroed globals (dword_7CA520, dword_7CA524, dword_7CA528, dword_7CA52C) are not verifiable from this function alone; they are contiguous state fields of the collision grid block.
    // UNRESOLVED: The relationship of this block (0x7CA51C) to the other collision-grid init blocks is not established here.
    // UNRESOLVED: No static callers or frame-path evidence exist in the packet, so when this initializer runs is unknown.
}
