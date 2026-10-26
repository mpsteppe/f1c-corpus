// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044C6E0
// Canonical corpus name: GlobalStateInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalStateInitializer_0044c6e0.c

void UnknownObject::initializeGlobalState()
{
    // Unconditional one-time initialization of four module globals: an engine-type selector set to 3, two float thresholds cleared to 0.0, and a scale field holding the float 1.0 bit pattern (1065353216).
    // ASSIGNMENT: dword_7CA3E8 (0x007CA3E8) set to literal 3 [global:0x007CA3E8]
    // ASSIGNMENT: flt_7CA3EC (0x007CA3EC) set to 0.0 [global:0x007CA3EC]
    // ASSIGNMENT: flt_7CA3F0 (0x007CA3F0) set to 0.0 [global:0x007CA3F0]
    // ASSIGNMENT: dword_7CA3F4 (0x007CA3F4) set to 1065353216 (stored float 1.0) [global:0x007CA3F4]

    // Conservative worker pseudocode:
    //   dword_7CA3E8 = 3;
    //   flt_7CA3EC = 0.0f;
    //   flt_7CA3F0 = 0.0f;
    //   dword_7CA3F4 = 1065353216;
}
