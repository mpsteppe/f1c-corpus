// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E900
// Canonical corpus name: CollisionStateInit3
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionStateInit3_0044e900.c

void UnknownObject::CollisionStateInit3()
{
    // Unconditional collision-state initializer: writes tag 91 into dword_7CA564, zeroes the four following fields (dword_7CA568 through dword_7CA574), sets dword_7CA578 = 9000, and returns 0. No branches, calls, or struct fields. The canonical/abi name marks this as the third collision-state init block (LEGACY); the semantic role of each global is not established from this packet.
    // ASSIGNMENT: dword_7CA564 = 91 (block tag). [global:0x007CA564, source:raw]
    // ASSIGNMENT: dword_7CA568 = 0. [global:0x007CA568, source:raw]
    // ASSIGNMENT: dword_7CA56C = 0. [global:0x007CA56C, source:raw]
    // ASSIGNMENT: dword_7CA570 = 0. [global:0x007CA570, source:raw]
    // ASSIGNMENT: dword_7CA574 = 0. [global:0x007CA574, source:raw]
    // ASSIGNMENT: dword_7CA578 = 9000. [global:0x007CA578, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionStateInit3() {
    //     dword_7CA564 = 91;
    //     dword_7CA568 = 0; dword_7CA56C = 0; dword_7CA570 = 0; dword_7CA574 = 0;
    //     dword_7CA578 = 9000;
    //     return 0;
    //   }
    // UNRESOLVED: The semantic role of each 0x7CA564-region global is not recoverable from this packet; existing analysis labels dword_7CA564 AudioBufferPointer, dword_7CA574 VehicleSetupFloat_7CA574 and dword_7CA578 RenderState_A578 (all DERIVED).
    // UNRESOLVED: No static callers are recorded and the function is not on the frame path, so where this state init runs is unverified.
}
