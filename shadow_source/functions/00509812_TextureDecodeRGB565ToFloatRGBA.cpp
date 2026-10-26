// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00509812
// Canonical corpus name: VertexTextureDecoderRGB565
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VertexTextureDecoderRGB565_00509812.c

void UnknownObject::TextureDecodeRGB565ToFloatRGBA()
{
    // Decodes 16-bit packed RGB565 source texels into 32-bit float RGBA output, four floats per pixel with alpha written as 1.0. The source texel address is computed from the base pixel-data pointer (this+0x18) plus a3 times the slice stride (this+0x1054) plus a2 times the row pitch (this+0x1050), decoding *(this+0x1058) texels. Channel extraction: red = bits 15..11 scaled by 0.032258064, green = bits 10..5 scaled by 0.015873017, blue = bits 4..0 scaled by 0.032258064. When the flag at this+0x10 is non-zero, ContactManifoldCleanup (0x00507845) is invoked on the decoded output buffer afterwards.
    // CALCULATION: Source pointer v5 = *(this+0x18) + a3 * *(this+0x1054) + a2 * *(this+0x1050) locates the first 16-bit texel of the requested row and slice. [function:0x00509812, field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: Iterate while v5 < i where i = &v5[*(this+0x1058)]; each iteration consumes one 16-bit texel and emits 4 output floats. [field:this:0x00001058, source:raw]
    // CALCULATION: Red channel: a4[0] = (*v5 >> 11) * 0.032258064; the scale factor is supplied by the read-only float globals flt_5ACCD4 and flt_5ACCDC. [global:0x005ACCD4, global:0x005ACCDC, source:raw]
    // CALCULATION: Green channel: a4[1] = ((*v5 >> 5) & 0x3F) * 0.015873017. [source:raw]
    // CALCULATION: Blue channel: a4[2] = (*v5 & 0x1F) * 0.032258064, read from the low byte of the texel before the source pointer advances. [source:raw]
    // ASSIGNMENT: Alpha channel: the loop-increment write stores 1.0 to a4[3] for every emitted pixel. [source:raw]
    // GUARD: When the flag at this+0x10 is non-zero, the decoded output buffer is post-processed. [field:this:0x00000010, source:raw]
    // CALL: ContactManifoldCleanup(this, &a4[-4 * *(this+0x1058)]) runs on the guard path, receiving the start of the decoded float RGBA buffer. [callee:0x00507845, field:this:0x00000010, field:this:0x00001058, source:raw]

    // Conservative worker pseudocode:
    //   void TextureDecodeRGB565ToFloatRGBA(DWORD* this, int x, int y, float* a4) {
    //       WORD* src = (WORD*)(*(this+0x18) + y * *(this+0x1054) + x * *(this+0x1050));
    //       WORD* end = &src[*(this+0x1058)];
    //       for (; src < end; src++, a4 += 4) {
    //           a4[0] = (*src >> 11)        * 0.032258064f;   // R (5 bits)
    //           a4[1] = ((*src >> 5) & 0x3F) * 0.015873017f;   // G (6 bits)
    //           a4[2] = (*src & 0x1F)       * 0.032258064f;   // B (5 bits)
    //           a4[3] = 1.0f;                                   // A
    //       }
    //       if (*(this+0x10)) ContactManifoldCleanup(this, a4 - 4 * *(this+0x1058));
    //   }
    // UNRESOLVED: The exact pairing of read-only globals flt_5ACCD4 and flt_5ACCDC with the three channel-scale multiplies is not proven: the raw source shows the 0.032258064 scale twice (R and B) and 0.015873017 once (G) while two distinct scale globals are referenced.
    // UNRESOLVED: ContactManifoldCleanup (0x00507845) is a legacy mislabel; the actual purpose of the post-decode step it performs is not established by this packet.
    // UNRESOLVED: Which stride (row pitch this+0x1050 versus slice stride this+0x1054) multiplies a2 versus a3 is DERIVED from the raw source operand order, not from a named struct contract.
}
