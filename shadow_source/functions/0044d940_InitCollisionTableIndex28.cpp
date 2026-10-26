// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D940
// Canonical corpus name: CollisionGlobalInitC
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalInitC_0044d940.c

void UnknownObject::InitCollisionTableIndex28()
{
    // Unconditional one-shot initialization: sets dword_7CCDC8 to 28 and zeroes five adjacent globals (0x007CCDCC through 0x007CCDDC), then returns 0. No arguments, no calls, no guards.
    // ASSIGNMENT: Initialize return value to 0. [function:0x0044D940, source:raw]
    // ASSIGNMENT: Write literal 28 into dword_7CCDC8. [global:0x007CCDC8, source:raw]
    // ASSIGNMENT: Zero dword_7CCDCC. [global:0x007CCDCC, source:raw]
    // ASSIGNMENT: Zero dword_7CCDD0. [global:0x007CCDD0, source:raw]
    // ASSIGNMENT: Zero dword_7CCDD4. [global:0x007CCDD4, source:raw]
    // ASSIGNMENT: Zero dword_7CCDD8. [global:0x007CCDD8, source:raw]
    // ASSIGNMENT: Zero dword_7CCDDC. [global:0x007CCDDC, source:raw]
    // RETURN: Return 0. [function:0x0044D940, source:raw]

    // Conservative worker pseudocode:
    //   int InitCollisionTableIndex28() {
    //     dword_7CCDC8 = 28;
    //     dword_7CCDCC = 0;
    //     dword_7CCDD0 = 0;
    //     dword_7CCDD4 = 0;
    //     dword_7CCDD8 = 0;
    //     dword_7CCDDC = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic role of the six written globals (the existing fill's 'collision object index' reading is DERIVED and unverified).
    // UNRESOLVED: Whether the six adjacent globals form a single table/struct (offsets are contiguous but equality of ownership is unproven).
}
