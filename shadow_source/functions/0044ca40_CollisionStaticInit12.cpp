// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CA40
// Canonical corpus name: CollisionStaticInit12
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionStaticInit12_0044ca40.c

void UnknownObject::CollisionStaticInit12()
{
    // Straight-line collision-static initialization with no guard. Writes four globals: dword_7CCA7C = 12, flt_7CCA80 = 0.0, dword_7CCA84 = -1082130432 (float32 pattern of -1.0), flt_7CCA88 = 0.0. No callees, no arguments, no return value. Canonical/abi name implies a static collision type-12 init; the 12 written into dword_7CCA7C is consistent with a type selector, but the type's meaning is not grounded in packet evidence.
    // ASSIGNMENT: Write 12 into dword_7CCA7C; existing analysis labels it a static collision type ID set to 12 (DERIVED), consistent with the canonical name CollisionStaticInit12. [source:raw, global:0x007CCA7C]
    // ASSIGNMENT: Write 0.0 into flt_7CCA80; zero-initialized float field (DERIVED label RenderState_7CCA80 in existing analysis). [source:raw, global:0x007CCA80]
    // ASSIGNMENT: Write -1082130432 into dword_7CCA84; the value as a float32 is -1.0 (DERIVED label CameraInitFloat in existing analysis). The decimal spelling is preserved from the packet. [source:raw, global:0x007CCA84]
    // ASSIGNMENT: Write 0.0 into flt_7CCA88; zero-initialized float field (DERIVED label AudioEngine_MinVol_Type5 in existing analysis). [source:raw, global:0x007CCA88]

    // Conservative worker pseudocode:
    //   void CollisionStaticInit12(void) {
    //     dword_7CCA7C = 12;
    //     flt_7CCA80 = 0.0;
    //     dword_7CCA84 = -1082130432; /* float32 -1.0 * /
    //     flt_7CCA88 = 0.0;
    //   }
    // UNRESOLVED: The semantic role of each written global is grounded only in DERIVED labels from existing analysis, not in packet-visible callers, fields, or string evidence.
    // UNRESOLVED: No static callers are recorded, so the function's place in the collision static init sequence is unverified.
    // UNRESOLVED: dword_7CCA84 holds -1082130432; interpreting it as the float32 value -1.0 is an inference from its bit layout, not a packet literal.
}
