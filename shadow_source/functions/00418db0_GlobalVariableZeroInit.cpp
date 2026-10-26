// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00418DB0
// Canonical corpus name: GlobalVariableZeroInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalVariableZeroInit_00418db0.c

void UnknownObject::GlobalVariableZeroInit()
{
    // Unconditional global state reset: writes 0 into four consecutive global dwords dword_5EBB18 through dword_5EBB24. Always returns 0.
    // ASSIGNMENT: Zero dword_5EBB18. [global:0x005EBB18]
    // ASSIGNMENT: Zero dword_5EBB1C. [global:0x005EBB1C]
    // ASSIGNMENT: Zero dword_5EBB20. [global:0x005EBB20]
    // ASSIGNMENT: Zero dword_5EBB24. [global:0x005EBB24]
    // RETURN: Return 0. [abi:lead, function:0x00418DB0, source:raw]

    // Conservative worker pseudocode:
    //   int GlobalVariableZeroInit() {
    //     dword_5EBB18 = 0;
    //     dword_5EBB1C = 0;
    //     dword_5EBB20 = 0;
    //     dword_5EBB24 = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic purpose of the four consecutive globals dword_5EBB18..dword_5EBB24 is unknown.
}
