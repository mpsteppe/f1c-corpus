// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00431C00
// Canonical corpus name: PhysicsGlobalStateInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsGlobalStateInit_00431c00.c

void UnknownObject::PhysicsGlobalStateInit()
{
    // Resets a contiguous block of global physics-state dwords starting at dword_7C73E8. Sets three sentinel dwords (dword_7C73EC, dword_7C73F4, dword_7C73FC) to -1, zeroes the remaining eleven dwords (dword_7C73E8, dword_7C73F0, dword_7C73F8, dword_7C7404, dword_7C7408, dword_7C740C, dword_7C7410, dword_7C7418, dword_7C741C, dword_7C7420, dword_7C7424), then calls DualLinkedListCleanup on dword_7C73E8 and returns its result.
    // ASSIGNMENT: Set the three sentinel dwords to -1: dword_7C73EC, dword_7C73F4 and dword_7C73FC. [global:0x007C73EC, global:0x007C73F4, global:0x007C73FC, source:raw]
    // ASSIGNMENT: Set the block head dword_7C73E8 to 0. [global:0x007C73E8, source:raw]
    // ASSIGNMENT: Zero dword_7C73F0 and dword_7C73F8. [global:0x007C73F0, global:0x007C73F8, source:raw]
    // ASSIGNMENT: Zero dword_7C7404. [global:0x007C7404, source:raw]
    // ASSIGNMENT: Zero dword_7C7408. [global:0x007C7408, source:raw]
    // ASSIGNMENT: Zero dword_7C740C. [global:0x007C740C, source:raw]
    // ASSIGNMENT: Zero dword_7C7410. [global:0x007C7410, source:raw]
    // ASSIGNMENT: Zero dword_7C7418. [global:0x007C7418, source:raw]
    // ASSIGNMENT: Zero dword_7C741C. [global:0x007C741C, source:raw]
    // ASSIGNMENT: Zero dword_7C7420. [global:0x007C7420, source:raw]
    // ASSIGNMENT: Zero dword_7C7424. [global:0x007C7424, source:raw]
    // CALL: DualLinkedListCleanup(&dword_7C73E8) tears down the state block; its return value is returned by this function. [global:0x007C73E8, source:raw]
    // RETURN: Return the DualLinkedListCleanup result. [abi:lead, function:0x00431C00, source:raw]

    // Conservative worker pseudocode:
    //   int PhysicsGlobalStateInit() {
    //     dword_7C73EC = -1;
    //     dword_7C73F4 = -1;
    //     dword_7C73FC = -1;
    //     dword_7C73E8 = 0;
    //     dword_7C73F0 = 0;
    //     dword_7C73F8 = 0;
    //     dword_7C7404 = 0;
    //     dword_7C7408 = 0;
    //     dword_7C740C = 0;
    //     dword_7C7410 = 0;
    //     dword_7C7418 = 0;
    //     dword_7C741C = 0;
    //     dword_7C7420 = 0;
    //     dword_7C7424 = 0;
    //     return DualLinkedListCleanup(&dword_7C73E8);
    //   }
    // UNRESOLVED: DualLinkedListCleanup is called in the raw source but has no callee evidence ref in the packet, so its address is not recorded here.
    // UNRESOLVED: The semantic meaning of the three -1 sentinel dwords and of the zeroed block at dword_7C73E8 is not established by the packet alone.
}
