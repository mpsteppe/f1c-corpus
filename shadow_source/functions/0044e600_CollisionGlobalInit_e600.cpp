// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E600
// Canonical corpus name: CollisionGlobalInit_e600
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalInit_e600_0044e600.c

void UnknownObject::CollisionGlobalInit_e600()
{
    // Unconditional one-time initializer for the second block of collision-system globals starting at 0x007CCA2C. Sets a system block tag (83), zeroes four following state fields, sets a maximum-distance value (9000), and returns 0.
    // ASSIGNMENT: Set dword_7CCA2C to 83 (collision system block tag). [global:0x007CCA2C, source:raw]
    // ASSIGNMENT: Zero dword_7CCA30. [global:0x007CCA30, source:raw]
    // ASSIGNMENT: Zero dword_7CCA34. [global:0x007CCA34, source:raw]
    // ASSIGNMENT: Zero dword_7CCA38. [global:0x007CCA38, source:raw]
    // ASSIGNMENT: Zero dword_7CCA3C. [global:0x007CCA3C, source:raw]
    // ASSIGNMENT: Set dword_7CCA40 to 9000 (maximum-distance value). [global:0x007CCA40, source:raw]
    // RETURN: Return 0. [function:0x0044E600, source:raw]

    // Conservative worker pseudocode:
    //   int CollisionGlobalInit_e600(void) {
    //     dword_7CCA2C = 83;
    //     dword_7CCA30 = 0;
    //     dword_7CCA34 = 0;
    //     dword_7CCA38 = 0;
    //     dword_7CCA3C = 0;
    //     dword_7CCA40 = 9000;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic role of each global in the 0x007CCA2C block is not packet-evidenced; the DERIVED names in existing analysis (CollisionContactCount, ControlStateStore, CollisionMaxDistance) are unverified proposals, not facts.
    // UNRESOLVED: Relationship to the first collision-global block init is unknown.
}
