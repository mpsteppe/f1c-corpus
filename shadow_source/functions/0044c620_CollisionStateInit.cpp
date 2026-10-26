// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044C620
// Canonical corpus name: CollisionStateInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionStateInit_0044c620.c

void UnknownObject::CollisionStateInit()
{
    // Straight-line initializer that writes default values to four global collision-state parameters: dword_7CA490 = 1, flt_7CA494 = 0.0, flt_7CA498 = 0.0, and dword_7CA49C = 1065353216 (the raw bit pattern that represents 1.0f). No guards, fields, or callees; void return.
    // ASSIGNMENT: Set dword_7CA490 to 1 (analysis prose labels it the collision cell initial count, DERIVED). [global:0x007CA490, source:raw]
    // ASSIGNMENT: Set flt_7CA494 to 0.0. [global:0x007CA494, source:raw]
    // ASSIGNMENT: Set flt_7CA498 to 0.0. [global:0x007CA498, source:raw]
    // ASSIGNMENT: Set dword_7CA49C to the decimal literal 1065353216, kept as a raw dword (the analysis prose reads it as the IEEE-754 bit pattern of 1.0, DERIVED). [global:0x007CA49C, source:raw]

    // Conservative worker pseudocode:
    //   void CollisionStateInit() {
    //     dword_7CA490 = 1;
    //     flt_7CA494 = 0.0f;
    //     flt_7CA498 = 0.0f;
    //     dword_7CA49C = 1065353216;
    //   }
    // UNRESOLVED: dword_7CA49C is written as the decimal integer 1065353216; treating it as the single-precision bit pattern of 1.0 is DERIVED from analysis prose only, with no independent evidence in the packet.
    // UNRESOLVED: The semantics of the four globals (collision cell count, thresholds, scale) are DERIVED names from analysis prose; no runtime evidence links them to collision code.
    // UNRESOLVED: No callers are recorded in the packet, so when this initializer runs is unknown.
}
