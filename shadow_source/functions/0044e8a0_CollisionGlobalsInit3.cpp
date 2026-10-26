// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E8A0
// Canonical corpus name: CollisionGlobalsInit3
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalsInit3_0044e8a0.c

void UnknownObject::CollisionGlobalsInit3()
{
    // Unconditional collision-block initializer: writes tag 90 into dword_7CA534, zeroes the five following collision-globals fields (dword_7CA538 through dword_7CA548), and returns 0. No branches, calls, or struct fields. The canonical/abi name marks this as the third collision-globals init block (LEGACY); the semantic role of each global is not established from this packet.
    // ASSIGNMENT: dword_7CA534 = 90 (block tag). [global:0x007CA534, source:raw]
    // ASSIGNMENT: dword_7CA538 = 0. [global:0x007CA538, source:raw]
    // ASSIGNMENT: dword_7CA53C = 0. [global:0x007CA53C, source:raw]
    // ASSIGNMENT: dword_7CA540 = 0. [global:0x007CA540, source:raw]
    // ASSIGNMENT: dword_7CA544 = 0. [global:0x007CA544, source:raw]
    // ASSIGNMENT: dword_7CA548 = 0. [global:0x007CA548, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionGlobalsInit3() {
    //     dword_7CA534 = 90;
    //     dword_7CA538 = 0; dword_7CA53C = 0; dword_7CA540 = 0; dword_7CA544 = 0; dword_7CA548 = 0;
    //     return 0;
    //   }
    // UNRESOLVED: The semantic role of each 0x7CA534-region global is not recoverable from this packet; existing analysis labels dword_7CA534 AudioSourceDepth, dword_7CA544 Dword_Unknown_Render4 and dword_7CA548 RenderStateID_548 (all DERIVED).
    // UNRESOLVED: No static callers are recorded and the function is not on the frame path, so where this block init runs is unverified.
}
