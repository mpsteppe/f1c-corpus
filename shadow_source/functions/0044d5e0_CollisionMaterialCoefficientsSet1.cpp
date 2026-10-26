// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D5E0
// Canonical corpus name: CollisionMaterialCoefficientsSet1
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionMaterialCoefficientsSet1_0044d5e0.c

void UnknownObject::CollisionMaterialCoefficientsSet1()
{
    // Unconditional initializer for collision material coefficients set 1: writes material ID 19 to dword_7CCC80 and zeroes five following coefficient fields at 0x007CCC84 through 0x007CCC94. Returns 0. No arguments, no guards, no calls.
    // ASSIGNMENT: Initialize the return value result to 0. [source:raw]
    // ASSIGNMENT: Write material ID 19 to dword_7CCC80. [global:0x007CCC80, source:raw]
    // ASSIGNMENT: Zero dword_7CCC84. [global:0x007CCC84, source:raw]
    // ASSIGNMENT: Zero dword_7CCC88. [global:0x007CCC88, source:raw]
    // ASSIGNMENT: Zero dword_7CCC8C. [global:0x007CCC8C, source:raw]
    // ASSIGNMENT: Zero dword_7CCC90. [global:0x007CCC90, source:raw]
    // ASSIGNMENT: Zero dword_7CCC94. [global:0x007CCC94, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionMaterialCoefficientsSet1() {
    //     dword_7CCC80 = 19;
    //     dword_7CCC84 = 0;
    //     dword_7CCC88 = 0;
    //     dword_7CCC8C = 0;
    //     dword_7CCC90 = 0;
    //     dword_7CCC94 = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic role of each zeroed coefficient field (0x007CCC84 through 0x007CCC94) is unknown from this function alone.
    // UNRESOLVED: Caller context and whether this coefficient block is one entry of a larger material table are not evidenced here.
}
