// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059706A
// Canonical corpus name: sub_59706A
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59706A_0059706a.c

void UnknownObject::ResetLocaleState()
{
    // Unconditional reset of a set of locale/codepage globals to zero. Zero-fills the 256-byte block at unk_8D47E0, clears the adjacent unk_8D48E0 slot, and zeroes the scalars dword_8D46BC, unk_8D46C0, unk_8D46C4, unk_8D46C8, dword_8D46CC and dword_8D48E4. Always returns 0. There are no branches; every store executes.
    // ASSIGNMENT: Zero-fill the 256-byte block at unk_8D47E0 via memset(&unk_8D47E0, 0, 0x100) [global:0x008D47E0, source:raw]
    // ASSIGNMENT: Clear the adjacent scalar unk_8D48E0 (immediately after the zero-filled block) to 0 (hex spelling withheld: address absent from packet evidence) [source:raw]
    // ASSIGNMENT: Zero dword_8D46BC [global:0x008D46BC, source:raw]
    // ASSIGNMENT: Zero dword_8D46CC [global:0x008D46CC, source:raw]
    // ASSIGNMENT: Zero dword_8D48E4 [global:0x008D48E4, source:raw]
    // ASSIGNMENT: Zero unk_8D46C0 [global:0x008D46C0, source:raw]
    // ASSIGNMENT: Zero unk_8D46C4 and unk_8D46C8 (adjacent scalars following unk_8D46C0; hex spellings withheld: addresses absent from packet evidence) [source:raw]
    // RETURN: Return 0; invoked once from the locale initialization path sub_596E40 (00596e40) [caller:0x00596E40, function:0x0059706A, source:raw]

    // Conservative worker pseudocode:
    //   memset(&unk_8D47E0, 0, 0x100);
    //   unk_8D48E0 = 0;
    //   dword_8D46BC = 0;
    //   dword_8D46CC = 0;
    //   dword_8D48E4 = 0;
    //   unk_8D46C0 = 0;
    //   unk_8D46C4 = 0;
    //   unk_8D46C8 = 0;
    //   return 0;
    // UNRESOLVED: Semantic roles of the individual scalars (code page flags, locale pointers, init flags) are labeled only DERIVED in the existing analysis and cannot be confirmed from this packet alone
    // UNRESOLVED: The 256-byte block at unk_8D47E0 and the grouping of the six nearby scalars suggest one locale/codepage state object, but the object boundary and field layout are not verifiable here
    // UNRESOLVED: unk_8D46C4, unk_8D46C8 and unk_8D48E0 are written by the raw source but are not in the packet global list, so their addresses have no allowed evidence reference
}
