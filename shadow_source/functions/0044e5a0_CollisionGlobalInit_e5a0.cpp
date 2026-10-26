// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E5A0
// Canonical corpus name: CollisionGlobalInit_e5a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalInit_e5a0_0044e5a0.c

void UnknownObject::CollisionGlobalInit_e5a0()
{
    // Unconditional one-time initializer for the first block of collision-system globals starting at 0x007CC9FC. Sets a system block tag (82), zeroes four following state fields, and returns 0.
    // ASSIGNMENT: Set dword_7CC9FC to 82 (collision system block tag). [global:0x007CC9FC, source:raw]
    // ASSIGNMENT: Zero dword_7CCA00. [global:0x007CCA00, source:raw]
    // ASSIGNMENT: Zero dword_7CCA04. [global:0x007CCA04, source:raw]
    // ASSIGNMENT: Zero dword_7CCA08. [global:0x007CCA08, source:raw]
    // ASSIGNMENT: Zero dword_7CCA0C. [global:0x007CCA0C, source:raw]
    // ASSIGNMENT: Zero dword_7CCA10. [global:0x007CCA10, source:raw]
    // RETURN: Return 0. [function:0x0044E5A0, source:raw]

    // Conservative worker pseudocode:
    //   int CollisionGlobalInit_e5a0(void) {
    //     dword_7CC9FC = 82;
    //     dword_7CCA00 = 0;
    //     dword_7CCA04 = 0;
    //     dword_7CCA08 = 0;
    //     dword_7CCA0C = 0;
    //     dword_7CCA10 = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic role of each global in the 0x007CC9FC block is not packet-evidenced; the DERIVED names in existing analysis (CollisionSystemData, AudioMixThreshold, CollisionGridData) are unverified proposals, not facts.
    // UNRESOLVED: Relationship to the second collision-global block init is unknown.
}
