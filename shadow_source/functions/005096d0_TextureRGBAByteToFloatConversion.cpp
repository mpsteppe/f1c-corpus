// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005096D0
// Canonical corpus name: TextureRGBAByteToFloatConversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureRGBAByteToFloatConversion_005096d0.c

void UnknownObject::TextureRGBAByteToFloatConversion()
{
    // Converts packed 32-bit RGBA byte texture data (4 bytes per pixel) to 32-bit float RGBA, scaling every byte channel (including alpha) by 0.0039215689 via the packet-listed global flt_59E460 folded to a literal. The source run is selected from field +0x18 using the pitch in +0x1050 and slice stride in +0x1054; the loop iterates over the pixel count in field +0x1058 (4 bytes per sample). When field +0x10 is non-zero, the decoded output start is passed to ContactManifoldCleanup for post-processing. The packet-listed global flt_5ADB14 does not appear in the decompiled source and is left unresolved.
    // CALCULATION: Compute the source base pointer v4 = this[6] (field +0x18) + a3 * this[1045] (field +0x1054) + a2 * this[1044] (field +0x1050), selecting the RGBA run for tile (a2, a3). [field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: for loop from v4 while v4 < v4 + 4 * this[1046] (field +0x1058), consuming 4 source bytes per RGBA sample. [field:this:0x00001058, source:raw]
    // CALCULATION: Convert the B, G and R byte channels to floats with the scale global flt_59E460 (folded literal 0.0039215689) and store them, advancing 4 bytes in and 4 floats out per pixel. [global:0x0059E460, source:raw]
    // ASSIGNMENT: Write the alpha channel as the source alpha byte (v4 - 1) scaled by the same 0.0039215689 factor via the loop increment expression. [global:0x0059E460, source:raw]
    // GUARD: Guard on this[4] (field +0x10): when non-zero a post-processing pass runs on the decoded buffer. [field:this:0x00000010, source:raw]
    // CALL: Call ContactManifoldCleanup(this, &a4[-4 * this[1046]]); recovers the output buffer start using field +0x1058. [callee:0x00507845, field:this:0x00001058, source:raw]

    // Conservative worker pseudocode:
    //   void sub_5096D0(void *this, int a2, int a3, float *a4) {
    //     unsigned v4 = this[6] + a3 * this[1045] + a2 * this[1044];
    //     for (unsigned i = v4 + 4 * this[1046]; v4 < i; *(a4 - 1) = (double)*(unsigned __int8*)(v4 - 1) * 0.0039215689) {
    //       *a4    = (double)*(unsigned __int8*)(v4 + 2) * 0.0039215689;  // B
    //       a4[1]  = (double)*(unsigned __int8*)(v4 + 1) * 0.0039215689;  // G
    //       *(a4+2) = (double)(unsigned __int8)*(_DWORD*)v4 * 0.0039215689; // R
    //       v4 += 4; a4 += 4;
    //     }
    //     if (this[4]) ContactManifoldCleanup((int)this, (unsigned int)&a4[-4 * this[1046]]);
    //   }
    // UNRESOLVED: global:0x005ADB14 is listed in the packet but does not appear in the decompiled source; the analysis label (360.0 degree wrap) appears unrelated to byte-to-float conversion.
    // UNRESOLVED: The callee ContactManifoldCleanup (0x00507845) name is domain-mismatched for a texture decoder; it likely post-processes the decoded float buffer.
    // UNRESOLVED: The exact role of the scale global flt_59E460 (labeled alpha scale in the analysis) is not confirmed.
}
