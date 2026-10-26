// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E360
// Canonical corpus name: AudioFilterParameterDefaults
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioFilterParameterDefaults_0044e360.c

void UnknownObject::AudioFilterParameterDefaults()
{
    // Unconditional init of a six-dword audio filter parameter block: sets dword_7CD118 to 76 (filter type identifier), zeroes dword_7CD11C through dword_7CD128, sets dword_7CD12C to 18000 (render threshold), and returns 0. No calls and no guards.
    // ASSIGNMENT: dword_7CD118 = 76 (filter type/identifier). [global:0x007CD118, source:raw]
    // ASSIGNMENT: dword_7CD11C = 0. [global:0x007CD11C, source:raw]
    // ASSIGNMENT: dword_7CD120 = 0. [global:0x007CD120, source:raw]
    // ASSIGNMENT: dword_7CD124 = 0. [global:0x007CD124, source:raw]
    // ASSIGNMENT: dword_7CD128 = 0. [global:0x007CD128, source:raw]
    // ASSIGNMENT: dword_7CD12C = 18000 (render threshold literal). [global:0x007CD12C, source:raw]
    // RETURN: Return 0 (no calls, no guards; all writes unconditional). [source:raw]

    // Conservative worker pseudocode:
    //   int AudioFilterParameterDefaults() {
    //     dword_7CD118 = 76;
    //     dword_7CD11C = 0; dword_7CD120 = 0; dword_7CD124 = 0; dword_7CD128 = 0;
    //     dword_7CD12C = 18000;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic role of the literal 76 and the meaning of the 18000 threshold are not established; the existing analysis labels dword_7CD12C render threshold (DERIVED) with no consumer evidence.
    // UNRESOLVED: The audio subsystem association is inferred from the ABI name Audio_Filter_Parameter_Defaults and the declared name; no callers or callees are recorded statically (top-level or indirect-only).
}
