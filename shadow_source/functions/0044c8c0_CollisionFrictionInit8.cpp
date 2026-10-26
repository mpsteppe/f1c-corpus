// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044C8C0
// Canonical corpus name: CollisionFrictionInit8
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionFrictionInit8_0044c8c0.c

void UnknownObject::CollisionFrictionInit8()
{
    // Initializes four collision-friction globals: sets the friction/state-type word at 0x007CCFB0 to 8, the dword at 0x007CCFB8 to the literal -1082130432 (the IEEE-754 bit pattern of -1.0f, preserved as written), and two float fields to 0.0. Unconditional writes, no guards and no callees.
    // ASSIGNMENT: Write the integer literal 8 to dword_7CCFB0 at 0x007CCFB0. [source:raw, function:0x0044C8C0, global:0x007CCFB0]
    // ASSIGNMENT: Write 0.0f to flt_7CCFB4 at 0x007CCFB4. [source:raw, function:0x0044C8C0, global:0x007CCFB4]
    // ASSIGNMENT: Write the integer literal -1082130432 (float -1.0f bit pattern) to dword_7CCFB8 at 0x007CCFB8. [source:raw, function:0x0044C8C0, global:0x007CCFB8]
    // ASSIGNMENT: Write 0.0f to flt_7CCFBC at 0x007CCFBC. [source:raw, function:0x0044C8C0, global:0x007CCFBC]

    // Conservative worker pseudocode:
    //   void CollisionFrictionInit8() {
    //     dword_7CCFB0 = 8;
    //     flt_7CCFB4 = 0.0;
    //     dword_7CCFB8 = -1082130432;
    //     flt_7CCFBC = 0.0;
    //   }
    // UNRESOLVED: The friction-init role is carried only by the canonical/abi name (LEGACY trust); no caller or field evidence grounds what the initialized friction state is used for.
    // UNRESOLVED: The -1.0f bit pattern is written as a signed integer literal in source; whether it is consumed as a float or int elsewhere is unrecoverable from this packet.
}
