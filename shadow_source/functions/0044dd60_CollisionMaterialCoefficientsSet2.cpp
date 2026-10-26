// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044DD60
// Canonical corpus name: CollisionMaterialCoefficientsSet2
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionMaterialCoefficientsSet2_0044dd60.c

void UnknownObject::CollisionMaterialCoefficientsSet2()
{
    // Unconditional initializer for collision material coefficients set 2: writes material ID 52 to dword_7CCE10 and zeroes five following coefficient fields at 0x007CCE14 through 0x007CCE24. Returns 0. No arguments, no guards, no calls.
    // ASSIGNMENT: Initialize the return value result to 0. [source:raw]
    // ASSIGNMENT: Write material ID 52 to dword_7CCE10. [global:0x007CCE10, source:raw]
    // ASSIGNMENT: Zero dword_7CCE14. [global:0x007CCE14, source:raw]
    // ASSIGNMENT: Zero dword_7CCE18. [global:0x007CCE18, source:raw]
    // ASSIGNMENT: Zero dword_7CCE1C. [global:0x007CCE1C, source:raw]
    // ASSIGNMENT: Zero dword_7CCE20. [global:0x007CCE20, source:raw]
    // ASSIGNMENT: Zero dword_7CCE24. [global:0x007CCE24, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionMaterialCoefficientsSet2() {
    //     dword_7CCE10 = 52;
    //     dword_7CCE14 = 0;
    //     dword_7CCE18 = 0;
    //     dword_7CCE1C = 0;
    //     dword_7CCE20 = 0;
    //     dword_7CCE24 = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic role of each zeroed coefficient field (0x007CCE14 through 0x007CCE24) is unknown from this function alone.
    // UNRESOLVED: Caller context and whether this coefficient block is one entry of a larger material table are not evidenced here.
}
