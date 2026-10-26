// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D700
// Canonical corpus name: CollisionGlobalInit_d700
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalInit_d700_0044d700.c

void UnknownObject::CollisionGlobalInit()
{
    // Straight-line collision-globals initializer: stores count literal 22 into dword_7CCC98[0] and zeroes the five immediately following dwords (0x7CCC9C .. 0x7CCCAC). Always returns 0. No guards, no calls.
    // ASSIGNMENT: Initialize result to 0; the function always returns 0. [source:raw]
    // ASSIGNMENT: Write literal 22 into dword_7CCC98[0], the collision-count initial value. [global:0x007CCC98, source:raw]
    // ASSIGNMENT: Zero dword_7CCC9C (CollisionGlobalsInitBlock field). [global:0x007CCC9C, source:raw]
    // ASSIGNMENT: Zero dword_7CCCA0 (collision global slot 3). [global:0x007CCCA0, source:raw]
    // ASSIGNMENT: Zero dword_7CCCA4 (collision global slot 4). [global:0x007CCCA4, source:raw]
    // ASSIGNMENT: Zero dword_7CCCA8 (collision global slot 5). [global:0x007CCCA8, source:raw]
    // ASSIGNMENT: Zero dword_7CCCAC (CollisionZeroField tail slot). [global:0x007CCCAC, source:raw]
    // RETURN: Return result (0). [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionGlobalInit() {
    //     dword_7CCC98[0] = 22;
    //     dword_7CCC9C = 0; dword_7CCCA0 = 0;
    //     dword_7CCCA4 = 0; dword_7CCCA8 = 0;
    //     dword_7CCCAC = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic meaning of the count literal 22 and the five zeroed slots is not evidenced beyond the adjacent-block naming in the prose analysis.
    // UNRESOLVED: Owner object is unknown; no caller or frame-path evidence ties this initializer to a named subsystem object.
}
