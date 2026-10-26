// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044C9F4
// Canonical corpus name: SteeringSensitivityInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SteeringSensitivityInit_0044c9f4.c

void UnknownObject::SteeringSensitivityInit()
{
    // Argument-less, branch-free initialization routine. Writes 0.0 to AI global flt_7CCCB8 and writes 1065353216 to the adjacent global dword_7CCCBC. No callees, no returns. The legacy ABI name SteeringSensitivityInit is the only evidence of purpose; the exact runtime role of the two globals is not evidenced by this packet.
    // ASSIGNMENT: Write 0.0 to global flt_7CCCB8. [global:0x007CCCB8, source:raw]
    // ASSIGNMENT: Write 1065353216 to global dword_7CCCBC. [global:0x007CCCBC, source:raw]

    // Conservative worker pseudocode:
    //   void SteeringSensitivityInit() {
    //       flt_7CCCB8 = 0.0;
    //       dword_7CCCBC = 1065353216;
    //   }
    // UNRESOLVED: The exact semantic role of flt_7CCCB8 and dword_7CCCBC (steering-sensitivity state per the legacy ABI name) is not evidenced by this packet; only the two writes are certain.
    // UNRESOLVED: Whether dword_7CCCBC is intended as the integer-coded bit pattern of float 1.0 is not evidenced by the packet.
}
