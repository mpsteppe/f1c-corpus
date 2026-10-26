// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E420
// Canonical corpus name: CollisionStateInit4e
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionStateInit4e_0044e420.c

void UnknownObject::CollisionStateInit()
{
    // Initializes a collision state block at a fixed global address: stores a type tag of 78 into the first word and zeroes five following state words. Always executes unconditionally and returns 0.
    // ASSIGNMENT: Store the state type tag 78 into the first word of the collision state block. [global:0x007CD004]
    // ASSIGNMENT: Zero the second state word. [global:0x007CD008]
    // ASSIGNMENT: Zero the third state word. [global:0x007CD00C]
    // ASSIGNMENT: Zero the fourth state word. [global:0x007CD010]
    // ASSIGNMENT: Zero the fifth state word. [global:0x007CD014]
    // ASSIGNMENT: Zero the sixth state word. [global:0x007CD018]
    // RETURN: Return 0 unconditionally. [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionStateInit() {
    //     dword_7CD004 = 78;
    //     dword_7CD008 = 0;
    //     dword_7CD00C = 0;
    //     dword_7CD010 = 0;
    //     dword_7CD014 = 0;
    //     dword_7CD018 = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Identity and layout of the object owning the six-word block starting at 0x7CD004.
    // UNRESOLVED: Semantic meaning of the state type tag 78 and of each of the five zeroed state words.
}
