// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00455260
// Canonical corpus name: sub_455260
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_455260_00455260.c

void UnknownObject::StringTableLookupByType()
{
    // Two-way string-table lookup (stdcall): discriminates on the dword at offset 0x0 of a1. When the discriminator is 0, indexes the table1 pair (aPause_0 / aEmpty_0) with the dword at offset 0x4; when it is 1, indexes the table2 (aEmpty) with the same offset; any other discriminator returns null. Out-of-range indexes fall back to the byte_5EA438 table base. Called by MessageNameBufferUpdate (0x0046AD50) and sub_4B9FD0 (0x004B9FD0) to resolve message/pause strings.
    // GUARD: Dispatch on discriminator field at a1 offset 0x0: value 0 selects the table1 path, value 1 selects the table2 path, and any other value returns null; matches the Two_Way_Dispatch_by_Index ABI shape. [field:this:0x00000000, guard:0, abi:lead, source:raw]
    // CALCULATION: Table1 path (discriminator 0): read index v3 = a1[1]; when v3 < 128 and (unsigned)v3 < 0x5A return &aPause_0[16 * v3]; when (unsigned)(v3 - 128) < 0x58 return &aEmpty_0[16 * v3 - 2048]; otherwise fall through to the default byte_5EA438 result. [field:this:0x00000004, source:raw]
    // CALCULATION: Table2 path (discriminator 1): read index v2 = a1[1]; when v2 < 0x6E return &aEmpty[9 * v2]; otherwise fall through to the default byte_5EA438 result. [field:this:0x00000004, source:raw]
    // GUARD: Unknown discriminator (a1[0] neither 0 nor 1) returns null immediately. [field:this:0x00000000, source:raw]
    // RETURN: Default return is the byte_5EA438 table base pointer, taken when the selected index exceeds its table bounds. [source:raw, function:0x00455260]
    // CALL: Invoked by MessageNameBufferUpdate (0x0046AD50) and sub_4B9FD0 (0x004B9FD0) to resolve message/pause string names. [caller:0x0046AD50, caller:0x004B9FD0, source:raw]

    // Conservative worker pseudocode:
    //   char *sub_455260(int *desc) {
    //     int idx = desc[1];
    //     if (desc[0] == 0) {
    //       if (idx < 128 && (unsigned)idx < 0x5A) return &aPause_0[16 * idx];
    //       if ((unsigned)(idx - 128) < 0x58) return &aEmpty_0[16 * idx - 2048];
    //     } else if (desc[0] == 1) {
    //       if ((unsigned)idx < 0x6E) return &aEmpty[9 * idx];
    //     } else {
    //       return 0;
    //     }
    //     return byte_5EA438;
    //   }
    // UNRESOLVED: Identity of the two string tables (aEmpty, aPause_0, aEmpty_0) and the byte_5EA438 base pointer are not resolvable from this function alone
    // UNRESOLVED: Semantic meaning of the discriminator values 0/1 (message vs pause context) is inferred from caller names only, not from this packet
}
