// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D100
// Canonical corpus name: CollisionGlobalInit_d100
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalInit_d100_0044d100.c

void UnknownObject::initCollisionConfigType107()
{
    // Initializes a 16-byte collision configuration block at 0x007CCF60: writes a type/count tag 107, a float field to 0.0, a field to the decimal literal -1082130432 (plausibly -1.0f as a float sentinel), and a final float field to 0.0. Unconditional writes, no calls, no guards.
    // ASSIGNMENT: Write type/count tag 107 to dword_7CCF60. [global:0x007CCF60, source:raw]
    // ASSIGNMENT: Write 0.0 to flt_7CCF64. [global:0x007CCF64, source:raw]
    // ASSIGNMENT: Write decimal literal -1082130432 (plausibly -1.0f as a float sentinel, stored in a dword) to dword_7CCF68. [global:0x007CCF68, source:raw]
    // ASSIGNMENT: Write 0.0 to flt_7CCF6C. [global:0x007CCF6C, source:raw]

    // Conservative worker pseudocode:
    //   dword_7CCF60 = 107;
    //   flt_7CCF64 = 0.0;
    //   dword_7CCF68 = -1082130432;
    //   flt_7CCF6C = 0.0;
    // UNRESOLVED: Owner identity unknown; function has no static callers found.
    // UNRESOLVED: Literal -1082130432 is stored as a dword; its intended type (float value -1.0f vs integer) is ambiguous from the raw source.
    // UNRESOLVED: Semantic meaning of the block (collision thresholds vs unrelated state) is uncertain; existing analysis labels conflict.
    // UNRESOLVED: Caller/invocation path unknown (on_frame_path false).
}
