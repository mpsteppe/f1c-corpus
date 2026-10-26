// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E7E0
// Canonical corpus name: InitializeCollisionGlobalsC
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitializeCollisionGlobalsC_0044e7e0.c

void UnknownObject::InitializeCollisionGlobalsC()
{
    // Unconditional static initializer for a six-dword collision global block (0x007CD080..0x007CD094): stores block tag 88, zeroes four state/render dwords, and stores threshold 18000. No branches, no calls, returns 0.
    // ASSIGNMENT: Write block tag 88 to dword_7CD080. [global:0x007CD080, source:raw]
    // ASSIGNMENT: Write 0 to dword_7CD084. [global:0x007CD084, source:raw]
    // ASSIGNMENT: Write 0 to dword_7CD088. [global:0x007CD088, source:raw]
    // ASSIGNMENT: Write 0 to dword_7CD08C. [global:0x007CD08C, source:raw]
    // ASSIGNMENT: Write 0 to dword_7CD090. [global:0x007CD090, source:raw]
    // ASSIGNMENT: Write threshold 18000 to dword_7CD094. [global:0x007CD094, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   dword_7CD080 = 88;
    //   dword_7CD084 = 0;
    //   dword_7CD088 = 0;
    //   dword_7CD08C = 0;
    //   dword_7CD090 = 0;
    //   dword_7CD094 = 18000;
    //   return 0;
    // UNRESOLVED: No callers found statically; the object owning the 0x007CD080..0x007CD094 block is unknown. Roles in existing analysis (Dword_Unknown_Render2, AudioEngine_SharedGain2) are DERIVED and unproven.
}
