// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F3090
// Canonical corpus name: FenderAeroSetupSectionReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FenderAeroSetupSectionReader_004f3090.c

void UnknownObject::FenderAeroSetupSectionReader()
{
    // Parses the fender aerodynamics setup section of a vehicle file. Loops over lines read by LineInputReader(384), uses sub_5651B0 on a4 to detect the end of section (result 1 breaks) or skip non-data lines, and for data lines parses fender center/drag/lift/sideways parameter fields via sub_565AA0 into this-relative output slots. Sets this+0x0 to 1 when the FenderCenter line parses, and calls CRTMathHelper_e1f0 to fill a per-vehicle indexed flare range/setting block.
    // LOOP: Loop reading lines via LineInputReader(384) until it returns 0. [callee:0x005351D0, caller:0x004F4270, source:raw]
    // GUARD: For each line call sub_5651B0(a4): result 1 breaks the loop (end of section); any non-zero, non-1 result skips the line as not a data line. [callee:0x005651B0, source:raw]
    // GUARD: Only when sub_5651B0 returned 0 (data line) parse the parameter fields below. [source:raw]
    // CALL: Call sub_565AA0(aFendercenter, this+60, this+68, this+76, 0); on non-zero return set this+0x0 (init literal 1) to 1. [global:0x005D535C, field:this:0x00000000, callee:0x00565AA0, source:raw]
    // CALL: Call sub_565AA0(aFenderdragpara, this+4, this+12, this+20, 0) to parse the fender drag parameter triple. [global:0x005D5348, callee:0x00565AA0, source:raw]
    // CALL: Call sub_565AA0(aFenderliftpara, this+28, this+36, this+44, 0) to parse the fender lift parameter triple. [global:0x005D5334, callee:0x00565AA0, source:raw]
    // CALL: Call sub_565AA0(aFendersideways, this+52, 0, 0, 0) to parse the fender sideways parameter (single value). [global:0x005D5324, callee:0x00565AA0, source:raw]
    // CALL: Call CRTMathHelper_e1f0((char*)((a2 << 6) + a5 + 2992), a4, aFenderflareran, aFenderflareset, 1.0) to compute indexed flare range/setting values into the per-vehicle output block. [callee:0x0042E1F0, global:0x005D52FC, global:0x005D5310, source:raw]
    // RETURN: Return the last line-read / section-marker result (0 when the loop ended, 1 on end-of-section break). [source:raw]

    // Conservative worker pseudocode:
    //   while ((r = LineInputReader(384)) != 0) {
    //     if (sub_5651B0(a4) == 1) break;
    //     if (sub_5651B0(a4) == 0) {
    //       if (sub_565AA0(aFendercenter, this+60, this+68, this+76, 0)) *this = 1;
    //       sub_565AA0(aFenderdragpara, this+4, this+12, this+20, 0);
    //       sub_565AA0(aFenderliftpara, this+28, this+36, this+44, 0);
    //       sub_565AA0(aFendersideways, this+52, 0, 0, 0);
    //       CRTMathHelper_e1f0((char*)((a2 << 6) + a5 + 2992), a4, aFenderflareran, aFenderflareset, 1.0);
    //     }
    //   }
    //   return r;
    // UNRESOLVED: Offset destinations this+4..this+76 (drag/lift/sideways/center outputs) appear in the raw source but are not in the packet field table; only this+0x0 has a field evidence ref.
    // UNRESOLVED: The role of a4 (section marker parameter) and the exact meaning of the CRTMathHelper_e1f0 index arithmetic (a2 << 6 + a5 + 2992) are not confirmed by the packet.
    // UNRESOLVED: sub_5651B0 is invoked twice per line in the raw source (once for the break check, once for the data-line check); behaviour of intermediate values is unchanged.
}
