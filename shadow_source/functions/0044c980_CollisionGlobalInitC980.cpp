// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044C980
// Canonical corpus name: CollisionGlobalInit_c980
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalInit_c980_0044c980.c

void UnknownObject::CollisionGlobalInitC980()
{
    // Straight-line collision-global initialization with no guard. Writes four globals: dword_7CCF80 = 10, flt_7CCF84 = 0.0, dword_7CCF88 = -1082130432 (float32 pattern of -1.0), flt_7CCF8C = 0.0. No callees, no arguments, no return value. Existing analysis labels dword_7CCF80 a max contact count (10) and dword_7CCF88 a -1.0 contact sentinel, both DERIVED.
    // ASSIGNMENT: Write 10 into dword_7CCF80; existing analysis labels it MaxContactCount initialized to 10 (DERIVED). [source:raw, global:0x007CCF80]
    // ASSIGNMENT: Write 0.0 into flt_7CCF84; zero-initialized float field (DERIVED label VehicleSetupFloat_7CCF84 in existing analysis). [source:raw, global:0x007CCF84]
    // ASSIGNMENT: Write -1082130432 into dword_7CCF88; the value as a float32 is -1.0, which existing analysis labels a collision contact sentinel (DERIVED). The decimal spelling is preserved from the packet. [source:raw, global:0x007CCF88]
    // ASSIGNMENT: Write 0.0 into flt_7CCF8C; zero-initialized float field (DERIVED label Flt_CopilotThreshold in existing analysis). [source:raw, global:0x007CCF8C]

    // Conservative worker pseudocode:
    //   void CollisionGlobalInitC980(void) {
    //     dword_7CCF80 = 10;
    //     flt_7CCF84 = 0.0;
    //     dword_7CCF88 = -1082130432; /* float32 -1.0 * /
    //     flt_7CCF8C = 0.0;
    //   }
    // UNRESOLVED: The semantic role of each written global is grounded only in DERIVED labels from existing analysis, not in packet-visible callers, fields, or string evidence.
    // UNRESOLVED: No static callers are recorded, so the function's place in the collision init sequence is unverified.
    // UNRESOLVED: dword_7CCF88 holds -1082130432; interpreting it as the float32 value -1.0 is an inference from its bit layout, not a packet literal.
}
