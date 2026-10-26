// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D8E0
// Canonical corpus name: InitializeCollisionGlobalsA
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitializeCollisionGlobalsA_0044d8e0.c

void UnknownObject::InitCollisionTableIndex27()
{
    // Unconditional one-shot initialization: sets dword_7CCDE0 to 27 and zeroes five adjacent globals (0x007CCDE4 through 0x007CCDF4), then returns 0. No arguments, no calls, no guards.
    // ASSIGNMENT: Initialize return value to 0. [function:0x0044D8E0, source:raw]
    // ASSIGNMENT: Write literal 27 into dword_7CCDE0[0]. [global:0x007CCDE0, source:raw]
    // ASSIGNMENT: Zero dword_7CCDE4. [global:0x007CCDE4, source:raw]
    // ASSIGNMENT: Zero dword_7CCDE8. [global:0x007CCDE8, source:raw]
    // ASSIGNMENT: Zero dword_7CCDEC. [global:0x007CCDEC, source:raw]
    // ASSIGNMENT: Zero dword_7CCDF0. [global:0x007CCDF0, source:raw]
    // ASSIGNMENT: Zero dword_7CCDF4. [global:0x007CCDF4, source:raw]
    // RETURN: Return 0. [function:0x0044D8E0, source:raw]

    // Conservative worker pseudocode:
    //   int InitCollisionTableIndex27() {
    //     dword_7CCDE0[0] = 27;
    //     dword_7CCDE4 = 0;
    //     dword_7CCDE8 = 0;
    //     dword_7CCDEC = 0;
    //     dword_7CCDF0 = 0;
    //     dword_7CCDF4 = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic role of the six written globals (the existing fill's 'render state pointer' reading is DERIVED and unverified).
    // UNRESOLVED: Whether the six adjacent globals form a single table/struct (offsets are contiguous but equality of ownership is unproven).
}
