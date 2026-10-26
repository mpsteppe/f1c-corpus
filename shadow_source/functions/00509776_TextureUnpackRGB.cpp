// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00509776
// Canonical corpus name: TextureUnpackRGB
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureUnpackRGB_00509776.c

void UnknownObject::TextureUnpackRGB()
{
    // Decodes 24-bit packed RGB888 source texels (one byte per channel plus an ignored byte) into 32-bit float RGBA output, four floats per pixel with alpha written as 1.0. The source texel address is computed from the base pixel-data pointer (this+0x18) plus a3 times the slice stride (this+0x1054) plus a2 times the row pitch (this+0x1050), for a pixel count at this+0x1058. Each of the three color channels is scaled by 0.0039215689 (1/255). When the flag at this+0x10 is non-zero, ContactManifoldCleanup (0x00507845) is invoked on the decoded output buffer afterwards.
    // CALCULATION: Source byte address v4 = *(this+0x18) + a3 * *(this+0x1054) + a2 * *(this+0x1050) locates the first texel of the requested row and slice in the source pixel-data buffer. [function:0x00509776, field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: Iterate while v4 < i where i = v4_start + 4 * *(this+0x1058); each iteration consumes 4 source bytes (three color bytes plus one ignored byte) and emits 4 output floats. [field:this:0x00001058, source:raw]
    // CALCULATION: Red channel: a4[0] = byte(v4+2) * 0.0039215689; the scale factor is supplied by the read-only float globals flt_59E460 and flt_5ADB14. [global:0x0059E460, global:0x005ADB14, source:raw]
    // CALCULATION: Green channel: a4[1] = byte(v4+1) * 0.0039215689. [source:raw]
    // CALCULATION: Blue channel: the low byte of the dword at v4 is scaled by 0.0039215689 and written to a4[2] after the output pointer advances by 4 floats. [source:raw]
    // ASSIGNMENT: Alpha channel: the loop-increment write stores 1.0 to a4[3] for every emitted pixel. [source:raw]
    // GUARD: When the flag at this+0x10 is non-zero, the decoded output buffer is post-processed. [field:this:0x00000010, source:raw]
    // CALL: ContactManifoldCleanup(this, &a4[-4 * *(this+0x1058)]) runs on the guard path, receiving the start of the decoded float RGBA buffer. [callee:0x00507845, field:this:0x00000010, field:this:0x00001058, source:raw]

    // Conservative worker pseudocode:
    //   void TextureUnpackRGB(DWORD* this, int x, int y, float* a4) {
    //       unsigned int src = *(this+0x18) + y * *(this+0x1054) + x * *(this+0x1050);
    //       unsigned int end = src + 4 * *(this+0x1058);
    //       for (; src < end; src += 4, a4 += 4) {
    //           a4[0] = byte(src+2) * 0.0039215689f;   // R
    //           a4[1] = byte(src+1) * 0.0039215689f;   // G
    //           a4[2] = byte(src)   * 0.0039215689f;   // B
    //           a4[3] = 1.0f;                           // A
    //       }
    //       if (*(this+0x10)) ContactManifoldCleanup(this, a4 - 4 * *(this+0x1058));
    //   }
    // UNRESOLVED: The exact pairing of read-only globals flt_59E460 and flt_5ADB14 with the channel-scale multiplies is not proven: the raw source shows a single literal 0.0039215689 for all three channels while two distinct scale globals are referenced.
    // UNRESOLVED: ContactManifoldCleanup (0x00507845) is a legacy mislabel; the actual purpose of the post-decode step it performs is not established by this packet.
    // UNRESOLVED: Which stride (row pitch this+0x1050 versus slice stride this+0x1054) multiplies a2 versus a3 is DERIVED from the raw source operand order, not from a named struct contract.
}
