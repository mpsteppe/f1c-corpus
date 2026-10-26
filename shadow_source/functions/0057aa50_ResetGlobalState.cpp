// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057AA50
// Canonical corpus name: sub_57AA50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57AA50_0057aa50.c

void UnknownObject::ResetGlobalState()
{
    // Straight-line reset routine: writes 0 to four global DWORDs at 0x008D3BFC, 0x008D3C00, 0x008D3C04, 0x008D3C08 and returns 0. No branches, no calls, no struct-field access. The packet carries no semantic names for these globals (dword_8D3BFC etc. only); the existing-analysis prose labels (ModuleInitListHead / GenericListTail / TaskListTail / PoolAllocCounter) are DERIVED and not grounded in the packet, so they are not endorsed here.
    // ASSIGNMENT: dword_8D3BFC (0x008D3BFC) = 0 [global:0x008D3BFC]
    // ASSIGNMENT: dword_8D3C00 (0x008D3C00) = 0 [global:0x008D3C00]
    // ASSIGNMENT: dword_8D3C04 (0x008D3C04) = 0 [global:0x008D3C04]
    // ASSIGNMENT: dword_8D3C08 (0x008D3C08) = 0 [global:0x008D3C08]
    // RETURN: return 0 (result initialized to 0 before the global writes; single exit path) [function:0x0057AA50, source:raw]

    // Conservative worker pseudocode:
    //   dword_8D3BFC = 0;
    //   dword_8D3C00 = 0;
    //   dword_8D3C04 = 0;
    //   dword_8D3C08 = 0;
    //   return 0;
    // UNRESOLVED: Semantic purpose of the four globals is unknown from the packet; they are written but the packet contains no consumers or names beyond dword_8D3BFC/dword_8D3C00/dword_8D3C04/dword_8D3C08.
    // UNRESOLVED: Callers are absent from the packet (callers: []), so trigger context (init vs reset vs per-frame) is unknown.
}
