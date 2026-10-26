// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D6A0
// Canonical corpus name: CollisionGlobalInit_d6a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalInit_d6a0_0044d6a0.c

void UnknownObject::CollisionGlobalInit()
{
    // Straight-line collision data-block initializer: stores count literal 21 into the first dword of the 0x7CCCC0 block (dword_7CCCC0[0]) and zeroes the five immediately following dwords (0x7CCCC4 .. 0x7CCCD4). Always returns 0. No guards, no calls.
    // ASSIGNMENT: Initialize result to 0; the function always returns 0. [source:raw]
    // ASSIGNMENT: Write literal 21 into dword_7CCCC0[0], the first element of the collision system data block. [global:0x007CCCC0, source:raw]
    // ASSIGNMENT: Zero dword_7CCCC4 (data block slot 2). [global:0x007CCCC4, source:raw]
    // ASSIGNMENT: Zero dword_7CCCC8 (data block slot 3). [global:0x007CCCC8, source:raw]
    // ASSIGNMENT: Zero dword_7CCCCC (data block slot 4). [global:0x007CCCCC, source:raw]
    // ASSIGNMENT: Zero dword_7CCCD0 (data block slot 5). [global:0x007CCCD0, source:raw]
    // ASSIGNMENT: Zero dword_7CCCD4 (CollisionDataBlock tail field). [global:0x007CCCD4, source:raw]
    // RETURN: Return result (0). [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionGlobalInit() {
    //     dword_7CCCC0[0] = 21;
    //     dword_7CCCC4 = 0; dword_7CCCC8 = 0;
    //     dword_7CCCCC = 0; dword_7CCCD0 = 0;
    //     dword_7CCCD4 = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic meaning of the count literal 21 and the five zeroed slots is not evidenced beyond the adjacent-block naming in the prose analysis.
    // UNRESOLVED: Owner object is unknown; no caller or frame-path evidence ties this initializer to a named subsystem object.
}
