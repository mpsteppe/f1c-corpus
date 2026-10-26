// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E840
// Canonical corpus name: CollisionGlobalInitE
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalInitE_0044e840.c

void UnknownObject::CollisionGlobalInitE()
{
    // Unconditional static initializer for a six-dword collision global block (0x007CD01C..0x007CD030): stores block tag 89, zeroes four object-index/data dwords, and stores threshold 27000. No branches, no calls, returns 0.
    // ASSIGNMENT: Write block tag 89 to dword_7CD01C. [global:0x007CD01C, source:raw]
    // ASSIGNMENT: Write 0 to dword_7CD020. [global:0x007CD020, source:raw]
    // ASSIGNMENT: Write 0 to dword_7CD024. [global:0x007CD024, source:raw]
    // ASSIGNMENT: Write 0 to dword_7CD028. [global:0x007CD028, source:raw]
    // ASSIGNMENT: Write 0 to dword_7CD02C. [global:0x007CD02C, source:raw]
    // ASSIGNMENT: Write threshold 27000 to dword_7CD030. [global:0x007CD030, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   dword_7CD01C = 89;
    //   dword_7CD020 = 0;
    //   dword_7CD024 = 0;
    //   dword_7CD028 = 0;
    //   dword_7CD02C = 0;
    //   dword_7CD030 = 27000;
    //   return 0;
    // UNRESOLVED: No callers found statically; the object owning the 0x007CD01C..0x007CD030 block is unknown. Roles in existing analysis (CollisionObjectIndex, CollisionDataBlock, CollisionLimit) are DERIVED and unproven.
}
