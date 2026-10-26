// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D21D0
// Canonical corpus name: sub_4D21D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D21D0_004d21d0.c

void UnknownObject::sub_4D21D0()
{
    // Reads the global race-phase variable dword_7C56A8 and returns 0 when its value is 0 through 4 (inclusive) and 1 otherwise. The ABI name 'Race_Phase_Check' (LEGACY) suggests it is a phase-membership predicate, but the packet provides no direct evidence for that meaning.
    // GUARD: Branch on the value of global race-phase variable dword_7C56A8 via switch/jump-table dispatch. [global:0x007C56A8, source:raw]
    // RETURN: Return 0 when dword_7C56A8 is one of cases 0, 1, 2, 3, or 4. [source:raw]
    // RETURN: Return 1 for the default case (dword_7C56A8 outside the 0..4 range). [source:raw]

    // Conservative worker pseudocode:
    //   switch (dword_7C56A8) {
    //     case 0: case 1: case 2: case 3: case 4: result = 0; break;
    //     default: result = 1; break;
    //   }
    //   return result;
    // UNRESOLVED: Semantic meaning of the 0..4 phase values and which membership yields 0 vs 1 is not evidenced in the packet.
    // UNRESOLVED: jpt_4D21E1 (jump table) and byte_4D21F8 are compiler artifacts of the switch and do not appear in the raw source; their contents are not needed for the semantics.
}
