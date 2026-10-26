// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044C800
// Canonical corpus name: CollisionRegionInit5
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionRegionInit5_0044c800.c

void UnknownObject::CollisionRegionInit5()
{
    // Initializes four collision-region globals: sets the region-type word at 0x007CA3C8 to 6, the dword at 0x007CA3D0 to the literal -1082130432 (the IEEE-754 bit pattern of -1.0f, preserved as written), and two float fields to 0.0. Unconditional writes, no guards and no callees.
    // ASSIGNMENT: Write the integer literal 6 to dword_7CA3C8 at 0x007CA3C8. [source:raw, function:0x0044C800, global:0x007CA3C8]
    // ASSIGNMENT: Write 0.0f to flt_7CA3CC at 0x007CA3CC. [source:raw, function:0x0044C800, global:0x007CA3CC]
    // ASSIGNMENT: Write the integer literal -1082130432 (float -1.0f bit pattern) to dword_7CA3D0 at 0x007CA3D0. [source:raw, function:0x0044C800, global:0x007CA3D0]
    // ASSIGNMENT: Write 0.0f to flt_7CA3D4 at 0x007CA3D4. [source:raw, function:0x0044C800, global:0x007CA3D4]

    // Conservative worker pseudocode:
    //   void CollisionRegionInit5() {
    //     dword_7CA3C8 = 6;
    //     flt_7CA3CC = 0.0;
    //     dword_7CA3D0 = -1082130432;
    //     flt_7CA3D4 = 0.0;
    //   }
    // UNRESOLVED: The region-init role is carried only by the canonical/abi name (LEGACY trust); no caller or field evidence grounds what the initialized region type is used for.
    // UNRESOLVED: The -1.0f bit pattern is written as a signed integer literal in source; whether it is consumed as a float or int elsewhere is unrecoverable from this packet.
}
