// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D3A0
// Canonical corpus name: CollisionBroadphaseReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionBroadphaseReset_0044d3a0.c

void UnknownObject::CollisionBroadphaseReset()
{
    // Resets the collision broadphase globals: seeds dword_7CCD50 with 13 (0xD), zeroes five adjacent dword fields 0x7CCD54 through 0x7CCD64, and returns 0.
    // ASSIGNMENT: Seed dword_7CCD50 with the literal 13 (0xD); likely a collision bucket/cell index or count. [global:0x007CCD50]
    // ASSIGNMENT: Zero dword_7CCD54, the first of five consecutive bucket state/configuration fields. [global:0x007CCD54]
    // ASSIGNMENT: Zero dword_7CCD58, the second bucket state/configuration field. [global:0x007CCD58]
    // ASSIGNMENT: Zero dword_7CCD5C, the third bucket state/configuration field. [global:0x007CCD5C]
    // ASSIGNMENT: Zero dword_7CCD60, the fourth bucket state/configuration field. [global:0x007CCD60]
    // ASSIGNMENT: Zero dword_7CCD64, the fifth bucket state/configuration field. [global:0x007CCD64]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionBroadphaseReset(void) {
    //     dword_7CCD50 = 13;
    //     dword_7CCD54 = 0;
    //     dword_7CCD58 = 0;
    //     dword_7CCD5C = 0;
    //     dword_7CCD60 = 0;
    //     dword_7CCD64 = 0;
    //     return 0;
    //   }
    // UNRESOLVED: The role of the sentinel value 13 in dword_7CCD50 and the meaning of the five zeroed bucket fields depend on the broadphase implementation, not visible here.
    // UNRESOLVED: The caller that drives this reset is not identified (no static callers in the packet).
}
