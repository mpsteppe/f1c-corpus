// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00421470
// Canonical corpus name: FunctionCallWrapper_1470
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FunctionCallWrapper_1470_00421470.c

void UnknownObject::InitSeasonParentPathArray()
{
    // Initializes a global array of 0/-1 pairs starting at dword_5EC3D0, then registers it as a set of directory paths via ConfigDirectoryPathRegistration and returns the array pointer. Every odd dword slot in the region is set to -1 and every even dword slot is set to 0, effectively clearing a set of (path, flag) entries or sentinel-initializing an array of path records. No guard conditions; the function unconditionally writes the whole region and forwards dword_5EC3D0 to the registration call.
    // ASSIGNMENT: Initialize the pair at dword_5EC3D0: dword_5EC3D0[1] = -1 and dword_5EC3D0[0] = 0. [global:0x005EC3D0, source:raw]
    // ASSIGNMENT: Alternating 0/-1 initialization across the following named dword slots of the array region beginning at dword_5EC3D0 (dword_5EC3D8, dword_5EC3E0, dword_5EC3E8, up to dword_5EC480): each even dword slot is set to 0 and each odd dword slot is set to -1. [global:0x005EC3D0, source:raw]
    // ASSIGNMENT: Final pair in the region: dword_5EC480 = 0 and the trailing named slot algn_5EC484 = -1, completing the alternating pattern. [global:0x005EC3D0, source:raw]
    // CALL: Call ConfigDirectoryPathRegistration(dword_5EC3D0) to register the initialized array as directory paths. [callee:0x004216F0, global:0x005EC3D0, source:raw]
    // RETURN: Return dword_5EC3D0 (pointer to the initialized array). [global:0x005EC3D0, function:0x00421470, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   dword* InitSeasonParentPathArray() {
    //     for (i = 0; i < 46; ++i) { dword_5EC3D0[2*i] = 0; dword_5EC3D0[2*i+1] = -1; }
    //     ConfigDirectoryPathRegistration(dword_5EC3D0);
    //     return dword_5EC3D0;
    //   }
    // UNRESOLVED: callee 0x00587B3E (BooleanToIntConversion) is listed as a callee in the packet but does not appear in the raw source body; it is not invoked by this function.
    // UNRESOLVED: global 0x00421490 (loc_421490) is listed as a global but is the address of the instruction following the function body (return point), not a data global read by this function.
    // UNRESOLVED: The exact element semantics of the alternating 0/-1 array (path pointer / active flag pairs) and the count of entries registered are not stated in the packet; the visible writes cover the named dword slots from dword_5EC3D0 through algn_5EC484.
    // UNRESOLVED: The individual named globals inside the region (dword_5EC3D8, algn_5EC3DC, unk_5EC42C, etc.) are sequential dword slots of the same array region and are not separately evidenced.
}
