// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587B97
// Canonical corpus name: InitCRTFloatConversionFunctionPointers
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitCRTFloatConversionFunctionPointers_00587b97.c

void UnknownObject::InitCRTFloatConversionFunctionPointers()
{
    // Populates six CRT float-conversion function pointer globals: off_5E6730 and off_5E6744 receive CfltcvtCRTFloatConversionDispatch (0x0058C07F), off_5E6734 receives sub_58BD29 (0x0058BD29), off_5E6738 receives sub_58BD8F (0x0058BD8F), off_5E673C receives sub_58BCCF (0x0058BCCF), and off_5E6740 receives sub_58BD77 (0x0058BD77). Returns CfltcvtCRTFloatConversionDispatch. Called by InitWrapperCalling3Subroutines (0x00587B7F).
    // ASSIGNMENT: off_5E6730[0] = CfltcvtCRTFloatConversionDispatch (0x0058C07F) — CRT function table entry 0. [source:raw, global:0x005E6730, global:0x0058C07F]
    // ASSIGNMENT: off_5E6734[0] = sub_58BD29 (0x0058BD29) — float conversion routine. [source:raw, global:0x005E6734, global:0x0058BD29]
    // ASSIGNMENT: off_5E6738[0] = sub_58BD8F (0x0058BD8F) — float conversion routine. [source:raw, global:0x005E6738, global:0x0058BD8F]
    // ASSIGNMENT: off_5E673C[0] = sub_58BCCF (0x0058BCCF) — float conversion routine. [source:raw, global:0x005E673C, global:0x0058BCCF]
    // ASSIGNMENT: off_5E6740[0] = sub_58BD77 (0x0058BD77) — float conversion routine. [source:raw, global:0x005E6740, global:0x0058BD77]
    // ASSIGNMENT: off_5E6744 = CfltcvtCRTFloatConversionDispatch (0x0058C07F) — CRT dispatch function pointer. [source:raw, global:0x005E6744, global:0x0058C07F]
    // RETURN: Return CfltcvtCRTFloatConversionDispatch (0x0058C07F). [source:raw, global:0x0058C07F, function:0x00587B97]

    // Conservative worker pseudocode:
    //   int (__cdecl *sub_587B97())(int, int, int, int, int) {
    //     off_5E6730[0] = CfltcvtCRTFloatConversionDispatch;
    //     off_5E6734[0] = sub_58BD29;
    //     off_5E6738[0] = sub_58BD8F;
    //     off_5E673C[0] = sub_58BCCF;
    //     off_5E6740[0] = sub_58BD77;
    //     off_5E6744 = CfltcvtCRTFloatConversionDispatch;
    //     return CfltcvtCRTFloatConversionDispatch;
    //   }
    // UNRESOLVED: The CRT table represented by off_5E6730..off_5E6744 and the dispatch semantics of CfltcvtCRTFloatConversionDispatch are not established by this packet.
    // UNRESOLVED: Why two entries (off_5E6730 and off_5E6744) both receive the same dispatch routine is unresolved.
    // UNRESOLVED: Caller InitWrapperCalling3Subroutines (0x00587B7F) is outside this packet; its other init responsibilities are unknown.
}
