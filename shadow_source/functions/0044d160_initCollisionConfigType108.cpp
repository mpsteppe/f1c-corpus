// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D160
// Canonical corpus name: CollisionGlobalStructInit_d160
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalStructInit_d160_0044d160.c

void UnknownObject::initCollisionConfigType108()
{
    // Initializes a 16-byte collision configuration block at 0x007CCF70: writes a type/count tag 108, two float fields to 0.0, and a final field to the decimal literal 1065353216 (plausibly 1.0f as a float). Unconditional writes, no calls, no guards.
    // ASSIGNMENT: Write type/count tag 108 to dword_7CCF70. [global:0x007CCF70, source:raw]
    // ASSIGNMENT: Write 0.0 to flt_7CCF74. [global:0x007CCF74, source:raw]
    // ASSIGNMENT: Write 0.0 to flt_7CCF78. [global:0x007CCF78, source:raw]
    // ASSIGNMENT: Write decimal literal 1065353216 (plausibly 1.0f as a float, stored in a dword) to dword_7CCF7C. [global:0x007CCF7C, source:raw]

    // Conservative worker pseudocode:
    //   dword_7CCF70 = 108;
    //   flt_7CCF74 = 0.0;
    //   flt_7CCF78 = 0.0;
    //   dword_7CCF7C = 1065353216;
    // UNRESOLVED: Owner identity unknown; function has no static callers found.
    // UNRESOLVED: Literal 1065353216 is stored as a dword; its intended type (float value 1.0f vs integer) is ambiguous from the raw source.
    // UNRESOLVED: This and neighboring init functions write 16-byte blocks at distinct global addresses, suggesting a config struct family; addresses between them are not written by this function.
    // UNRESOLVED: Semantic meaning of the block (collision thresholds vs unrelated state) is uncertain; existing analysis labels conflict.
    // UNRESOLVED: Caller/invocation path unknown (on_frame_path false).
}
