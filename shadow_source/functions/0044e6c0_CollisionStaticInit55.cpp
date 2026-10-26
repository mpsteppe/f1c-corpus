// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E6C0
// Canonical corpus name: CollisionStaticInit55
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionStaticInit55_0044e6c0.c

void UnknownObject::CollisionStaticInit55()
{
    // Unconditional static initializer for a six-dword collision global block (0x007CD064..0x007CD078): stores block tag 85, zeroes four state/mapping dwords, and stores threshold 27000. No branches, no calls, returns 0.
    // ASSIGNMENT: Write block tag 85 to dword_7CD064. [global:0x007CD064, source:raw]
    // ASSIGNMENT: Write 0 to dword_7CD068. [global:0x007CD068, source:raw]
    // ASSIGNMENT: Write 0 to dword_7CD06C. [global:0x007CD06C, source:raw]
    // ASSIGNMENT: Write 0 to dword_7CD070. [global:0x007CD070, source:raw]
    // ASSIGNMENT: Write 0 to dword_7CD074. [global:0x007CD074, source:raw]
    // ASSIGNMENT: Write threshold 27000 to dword_7CD078. [global:0x007CD078, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   dword_7CD064 = 85;
    //   dword_7CD068 = 0;
    //   dword_7CD06C = 0;
    //   dword_7CD070 = 0;
    //   dword_7CD074 = 0;
    //   dword_7CD078 = 27000;
    //   return 0;
    // UNRESOLVED: No callers found statically; the object owning the 0x007CD064..0x007CD078 block is unknown. Roles in existing analysis (CollisionObjectMapping, SoundBank_VolumeFL, Flt_Threshold_CD078) are DERIVED and unproven.
}
