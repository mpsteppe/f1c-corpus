// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D7C0
// Canonical corpus name: CollisionStaticInit18
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionStaticInit18_0044d7c0.c

void UnknownObject::InitCollisionTable()
{
    // Unconditional one-shot initialization: sets global dword_7CCC08 to 24 and zeroes five adjacent globals (0x007CCC0C through 0x007CCC1C), then returns 0. No arguments, no calls, no guards.
    // ASSIGNMENT: Initialize return value to 0. [function:0x0044D7C0, source:raw]
    // ASSIGNMENT: Write literal 24 into dword_7CCC08. [global:0x007CCC08, source:raw]
    // ASSIGNMENT: Zero dword_7CCC0C. [global:0x007CCC0C, source:raw]
    // ASSIGNMENT: Zero dword_7CCC10. [global:0x007CCC10, source:raw]
    // ASSIGNMENT: Zero dword_7CCC14. [global:0x007CCC14, source:raw]
    // ASSIGNMENT: Zero dword_7CCC18. [global:0x007CCC18, source:raw]
    // ASSIGNMENT: Zero dword_7CCC1C. [global:0x007CCC1C, source:raw]
    // RETURN: Return 0. [function:0x0044D7C0, source:raw]

    // Conservative worker pseudocode:
    //   int InitCollisionTable() {
    //     dword_7CCC08 = 24;
    //     dword_7CCC0C = 0;
    //     dword_7CCC10 = 0;
    //     dword_7CCC14 = 0;
    //     dword_7CCC18 = 0;
    //     dword_7CCC1C = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic role of the six written globals (the existing fill's 'render state table' reading is DERIVED and unverified).
    // UNRESOLVED: Whether the six adjacent globals form a single table/struct (offsets are contiguous but equality of ownership is unproven).
}
