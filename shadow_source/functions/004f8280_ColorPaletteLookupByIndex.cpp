// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F8280
// Canonical corpus name: ColorPaletteLookupByIndex
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ColorPaletteLookupByIndex_004f8280.c

void UnknownObject::ColorPaletteLookupByIndex()
{
    // Lookup of an RGB color triple by palette index. Writes three output float pointers a2/a3/a4 from one of two hardcoded color groups (bright: indices 0-4 and 43; dark: indices 12-20, 38-41 and 44), or from default RGB values flt_5D67C8/CC/D0 when the index is in neither group. Returns a color component value whose exact meaning is caller-dependent.
    // ASSIGNMENT: Write the default RGB components from flt_5D67C8, flt_5D67CC and flt_5D67D0 into the three output float pointers a2/a3/a4 and seed the return value with a2. [global:0x005D67C8, global:0x005D67CC, global:0x005D67D0, source:raw]
    // GUARD: Dispatch on the palette index a1 via the jump table at jpt_4F82B5 (with adjacent table data at byte_4F8300); indices 0-4 and 43 select the bright group, indices 12-20, 38-41 and 44 select the dark group, and any other index falls through to return the default values. [global:0x004F82F4, global:0x004F8300, source:raw]
    // ASSIGNMENT: Bright palette group: overwrite outputs with dword_5D67B0 (red), dword_5D67B4 (green) and dword_5D67B8 (blue); the return value becomes dword_5D67B4. [global:0x005D67B0, global:0x005D67B4, global:0x005D67B8, source:raw]
    // ASSIGNMENT: Dark palette group: overwrite outputs with dword_5D67BC (red), dword_5D67C0 (green) and dword_5D67C4 (blue); the return value becomes dword_5D67C0. [global:0x005D67BC, global:0x005D67C0, global:0x005D67C4, source:raw]
    // RETURN: Return the selected color component; on the default path this is the a2 pointer value, on the group paths it is the group green component. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4F8280(int index, float *out_r, float *out_g, float *out_b) {
    //     *out_r = flt_5D67C8; *out_g = flt_5D67CC; *out_b = flt_5D67D0;
    //     int result = (int)out_r;
    //     switch (index) {
    //       case 0: case 1: case 2: case 3: case 4: case 43:
    //         *(DWORD *)out_r = dword_5D67B0; result = dword_5D67B4;
    //         *(DWORD *)out_g = dword_5D67B4; *(DWORD *)out_b = dword_5D67B8; break;
    //       case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20:
    //       case 38: case 39: case 40: case 41: case 44:
    //         *(DWORD *)out_r = dword_5D67BC; result = dword_5D67C0;
    //         *(DWORD *)out_g = dword_5D67C0; *(DWORD *)out_b = dword_5D67C4; break;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantic purpose of the returned component value is unknown; its consumer (caller sub_4F70C0) is not analyzed here.
    // UNRESOLVED: Role of adjacent table data byte_4F8300 is unknown beyond being read-only data near the jump table.
    // UNRESOLVED: Owner object or module context for the palette globals is unknown.
}
