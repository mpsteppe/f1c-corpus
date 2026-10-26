// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D760
// Canonical corpus name: CollisionGlobalStructInit_d760
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalStructInit_d760_0044d760.c

void UnknownObject::CollisionGlobalStructInit()
{
    // Straight-line collision configuration-block initializer: stores count literal 23 into dword_7CCC20[0] and zeroes the five immediately following dwords (0x7CCC24 .. 0x7CCC34). Always returns 0. No guards, no calls.
    // ASSIGNMENT: Initialize result to 0; the function always returns 0. [source:raw]
    // ASSIGNMENT: Write literal 23 into dword_7CCC20[0], the first element of the collision configuration block. [global:0x007CCC20, source:raw]
    // ASSIGNMENT: Zero dword_7CCC24 (config field slot 2). [global:0x007CCC24, source:raw]
    // ASSIGNMENT: Zero dword_7CCC28 (config field slot 3). [global:0x007CCC28, source:raw]
    // ASSIGNMENT: Zero dword_7CCC2C (config field slot 4). [global:0x007CCC2C, source:raw]
    // ASSIGNMENT: Zero dword_7CCC30 (config field slot 5). [global:0x007CCC30, source:raw]
    // ASSIGNMENT: Zero dword_7CCC34 (CollisionConfigVar2 tail slot). [global:0x007CCC34, source:raw]
    // RETURN: Return result (0). [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionGlobalStructInit() {
    //     dword_7CCC20[0] = 23;
    //     dword_7CCC24 = 0; dword_7CCC28 = 0;
    //     dword_7CCC2C = 0; dword_7CCC30 = 0;
    //     dword_7CCC34 = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic meaning of the count literal 23 and the five zeroed slots is not evidenced beyond the adjacent-block naming in the prose analysis.
    // UNRESOLVED: Owner object is unknown; no caller or frame-path evidence ties this initializer to a named subsystem object.
}
