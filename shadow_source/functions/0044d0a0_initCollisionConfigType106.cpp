// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D0A0
// Canonical corpus name: CollisionGlobalInit_d0a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalInit_d0a0_0044d0a0.c

void UnknownObject::initCollisionConfigType106()
{
    // Initializes a 16-byte collision configuration block at 0x007CCF90: writes a type/count tag 106, two float fields to 0.0, and a final field to the decimal literal 1065353216 (plausibly 1.0f as a float). Unconditional writes, no calls, no guards.
    // ASSIGNMENT: Write type/count tag 106 to dword_7CCF90. [global:0x007CCF90, source:raw]
    // ASSIGNMENT: Write 0.0 to flt_7CCF94. [global:0x007CCF94, source:raw]
    // ASSIGNMENT: Write 0.0 to flt_7CCF98. [global:0x007CCF98, source:raw]
    // ASSIGNMENT: Write decimal literal 1065353216 (plausibly 1.0f as a float, stored in a dword) to dword_7CCF9C. [global:0x007CCF9C, source:raw]

    // Conservative worker pseudocode:
    //   dword_7CCF90 = 106;
    //   flt_7CCF94 = 0.0;
    //   flt_7CCF98 = 0.0;
    //   dword_7CCF9C = 1065353216;
    // UNRESOLVED: Owner identity unknown; function has no static callers found.
    // UNRESOLVED: Literal 1065353216 is stored as a dword; its intended type (float value 1.0f vs integer) is ambiguous from the raw source.
    // UNRESOLVED: Semantic meaning of the block (collision thresholds vs unrelated state) is uncertain; existing analysis labels conflict.
    // UNRESOLVED: Caller/invocation path unknown (on_frame_path false).
}
