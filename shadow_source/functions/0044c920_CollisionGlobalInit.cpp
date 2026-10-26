// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044C920
// Canonical corpus name: CollisionGlobalInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalInit_0044c920.c

void UnknownObject::CollisionGlobalInit()
{
    // Straight-line collision-global initialization. Writes four global fields with no guard: dword_7CCA6C = 9, flt_7CCA70 = 0.0, flt_7CCA74 = 0.0, dword_7CCA78 = 1065353216 (float32 pattern of 1.0). No callees, no arguments, no return value; canonical/abi name suggests a collision subsystem init entry point but no caller or field evidence grounds the roles of the individual globals.
    // ASSIGNMENT: Write 9 into dword_7CCA6C; existing analysis labels this as the collision state/type integer field initialized to 9 (DERIVED). [source:raw, global:0x007CCA6C]
    // ASSIGNMENT: Write 0.0 into flt_7CCA70; existing analysis labels it a zero-initialized collision threshold (DERIVED). [source:raw, global:0x007CCA70]
    // ASSIGNMENT: Write 0.0 into flt_7CCA74; zero-initialized float field (DERIVED label DriverStatThreshold in existing analysis). [source:raw, global:0x007CCA74]
    // ASSIGNMENT: Write 1065353216 into dword_7CCA78; the value as a float32 is 1.0 (existing analysis labels the field FloatInit). The decimal spelling is preserved from the packet. [source:raw, global:0x007CCA78]

    // Conservative worker pseudocode:
    //   void CollisionGlobalInit(void) {
    //     dword_7CCA6C = 9;
    //     flt_7CCA70 = 0.0;
    //     flt_7CCA74 = 0.0;
    //     dword_7CCA78 = 1065353216; /* float32 1.0 * /
    //   }
    // UNRESOLVED: The semantic role of each written global is grounded only in DERIVED labels from existing analysis, not in packet-visible callers, fields, or string evidence.
    // UNRESOLVED: No static callers are recorded, so the function's place in the collision init sequence is unverified.
    // UNRESOLVED: dword_7CCA78 holds 1065353216; interpreting it as the float32 value 1.0 is an inference from its bit layout, not a packet literal.
}
