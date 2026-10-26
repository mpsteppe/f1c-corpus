// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055C650
// Canonical corpus name: sub_55C650
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55C650_0055c650.c

void UnknownObject::D3DFormatToFourCCLookup()
{
    // Maps a (bit depth, format identifier) pair to an output FourCC-style code written through the a1 output pointer. a3 selects the bit-depth branch (32, 24, 16, 8, or 0) and a2 the format identifier (4..13). Matched pairs write a small palette of format codes (20, 21, 23, 25, 41) and, for the zero bit-depth branch, a second group of larger compression codes (827611204, 844388420, 861165636, 877942852, 894720068). Unmatched combinations return without writing *a1.
    // GUARD: a3 is tested for zero: the non-zero path dispatches on explicit bit depths 32, 24, 16 and 8, while the zero path dispatches on format identifiers alone [source:raw]
    // GUARD: Bit depth 32 with format identifier 8 writes literal 21 through *a1; any other format identifier returns without writing [field:this:0x00000000, source:raw]
    // GUARD: Bit depth 24 with format identifier 7 writes literal 20 through *a1; any other format identifier returns without writing [field:this:0x00000000, source:raw]
    // GUARD: Bit depth 16 with format identifier 6 writes literal 23, or format identifier 5 writes literal 25, through *a1; other identifiers return without writing [field:this:0x00000000, source:raw]
    // GUARD: Bit depth 8 with format identifier 4 writes literal 41 through *a1; any other identifier returns without writing [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero bit depth: format identifiers 8, 7, 6, 5, 4 write 21, 20, 23, 25, 41 respectively; identifiers 9, 10, 11, 12, 13 write the large compression codes 827611204, 844388420, 861165636, 877942852, 894720068 [field:this:0x00000000, source:raw]
    // RETURN: Returns a1 (the output pointer); called by sub_53E070 (0053E070), sub_53F3F0 (0053F3F0), sub_53F720 (0053F720), DirectXDeviceSurfaceCreationWithFormatCapability (0053FD40), sub_554E90 (00554E90) and KeyEventDispatchToSubHandlers (0055C7F0) [caller:0x0053E070, caller:0x0053F3F0, caller:0x0053F720, caller:0x0053FD40, caller:0x00554E90, caller:0x0055C7F0, source:raw]

    // Conservative worker pseudocode:
    //   code = 0;
    //   if (a3 == 32) { if (a2 == 8)  code = 21; }
    //   else if (a3 == 24) { if (a2 == 7) code = 20; }
    //   else if (a3 == 16) { if (a2 == 6) code = 23; else if (a2 == 5) code = 25; }
    //   else if (a3 == 8)  { if (a2 == 4) code = 41; }
    //   else if (a3 == 0) {
    //     switch (a2) {
    //       case 8: code = 21; break;
    //       case 7: code = 20; break;
    //       case 6: code = 23; break;
    //       case 5: code = 25; break;
    //       case 4: code = 41; break;
    //       case 9:  code = 827611204; break;
    //       case 10: code = 844388420; break;
    //       case 11: code = 861165636; break;
    //       case 12: code = 877942852; break;
    //       case 13: code = 894720068; break;
    //     }
    //   }
    //   if (code != 0 && a1) *a1 = code;
    //   return a1;
    // UNRESOLVED: The 32-bit group of codes (827611204, 844388420, 861165636, 877942852, 894720068) are labeled DXT compression FourCC codes in the skeleton fill, but the exact format enumeration is unverifiable from this packet
    // UNRESOLVED: The relationship between the bit-depth branches and the zero-depth branch is asymmetric in the raw source (zero depth accepts formats 9..13 that the other branches reject); the intended format list is not documented here
}
