// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E480
// Canonical corpus name: CollisionRegionInit3
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionRegionInit3_0044e480.c

void UnknownObject::CollisionRegionInit()
{
    // Initializes a collision region block at a fixed global address: stores a type tag of 79 into the first word, zeroes four following region words, and sets the sixth word to 9000. Always executes unconditionally and returns 0.
    // ASSIGNMENT: Store the region type tag 79 into the first word of the collision region block. [global:0x007CD034]
    // ASSIGNMENT: Zero the second region word. [global:0x007CD038]
    // ASSIGNMENT: Zero the third region word. [global:0x007CD03C]
    // ASSIGNMENT: Zero the fourth region word. [global:0x007CD040]
    // ASSIGNMENT: Zero the fifth region word. [global:0x007CD044]
    // ASSIGNMENT: Set the sixth region word to the threshold value 9000. [global:0x007CD048]
    // RETURN: Return 0 unconditionally. [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionRegionInit() {
    //     dword_7CD034 = 79;
    //     dword_7CD038 = 0;
    //     dword_7CD03C = 0;
    //     dword_7CD040 = 0;
    //     dword_7CD044 = 0;
    //     dword_7CD048 = 9000;
    //     return 0;
    //   }
    // UNRESOLVED: Identity and layout of the object owning the six-word block starting at 0x7CD034.
    // UNRESOLVED: Semantic meaning of the region type tag 79, the four zeroed region words, and the 9000 threshold value.
}
