// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044C740
// Canonical corpus name: CollisionGridInit4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGridInit4_0044c740.c

void UnknownObject::CollisionGridInit4()
{
    // Straight-line initializer writing four globals in the 0x7CA470 collision-grid block: sets the grid size to 4, zeroes two float fields, and stores the integer bit pattern -1082130432 into dword_7CA478. No branches and no calls.
    // ASSIGNMENT: Set dword_7CA470 = 4, the collision grid size for this block. [global:0x007CA470, source:raw]
    // ASSIGNMENT: Set flt_7CA474 = 0.0. [global:0x007CA474, source:raw]
    // ASSIGNMENT: Set dword_7CA478 = -1082130432, the integer literal stored by the raw source (interpreted by the existing analysis as the IEEE-754 bit pattern of -1.0f). [global:0x007CA478, source:raw]
    // ASSIGNMENT: Set flt_7CA47C = 0.0. [global:0x007CA47C, source:raw]

    // Conservative worker pseudocode:
    //   void CollisionGridInit4() {
    //     dword_7CA470 = 4;
    //     flt_7CA474 = 0.0;
    //     dword_7CA478 = -1082130432;
    //     flt_7CA47C = 0.0;
    //   }
    // UNRESOLVED: The meaning of the literal -1082130432 in dword_7CA478: the raw source stores it as an integer; the interpretation as a -1.0f float sentinel comes only from the existing skeleton analysis and is not verifiable in this function.
    // UNRESOLVED: No static callers or frame-path evidence exist in the packet, so when this initializer runs is unknown.
}
