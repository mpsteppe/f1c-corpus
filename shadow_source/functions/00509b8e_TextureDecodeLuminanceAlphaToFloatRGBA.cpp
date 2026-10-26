// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00509B8E
// Canonical corpus name: TextureDecode32BitRGLuminanceAlphaFormat
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureDecode32BitRGLuminanceAlphaFormat_00509b8e.c

void UnknownObject::TextureDecodeLuminanceAlphaToFloatRGBA()
{
    // Decodes 32-bit packed luminance+alpha source texels (two 16-bit half-words per dword) into 32-bit float RGBA output: R and G both carry the luminance value, B is written as 1.0 and alpha is written as 1.0 by the loop increment. The source texel address is computed from the base pixel-data pointer (this+0x18) plus a3 times the slice stride (this+0x1054) plus a2 times the row pitch (this+0x1050), decoding *(this+0x1058) texels. The luminance half-word is scaled by 0.000015259022. When the flag at this+0x10 is non-zero, ContactManifoldCleanup (0x00507845) is invoked on the decoded output buffer afterwards.
    // CALCULATION: Source pointer v4 = *(this+0x18) + a3 * *(this+0x1054) + a2 * *(this+0x1050) locates the first dword texel of the requested row and slice. [function:0x00509B8E, field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: Iterate while v4 < i where i = &v4[*(this+0x1058)]; each iteration consumes one dword texel (two 16-bit half-words) and emits 4 output floats. [field:this:0x00001058, source:raw]
    // CALCULATION: First channel: a4[0] = (unsigned short)*v4 * 0.000015259022; the scale factor is supplied by the read-only float globals flt_5AD290 and flt_5ADB14. [global:0x005AD290, global:0x005ADB14, source:raw]
    // CALCULATION: Second channel: a4[1] = (unsigned short)(v4 - 1) * 0.000015259022 reads the second half-word of the just-consumed dword, duplicating the luminance value. [source:raw]
    // ASSIGNMENT: Third channel: 1.0 is written to a4[2] for every emitted pixel. [source:raw]
    // ASSIGNMENT: Alpha channel: the loop-increment write stores 1.0 to a4[3] for every emitted pixel. [source:raw]
    // GUARD: When the flag at this+0x10 is non-zero, the decoded output buffer is post-processed. [field:this:0x00000010, source:raw]
    // CALL: ContactManifoldCleanup(this, &a4[-4 * *(this+0x1058)]) runs on the guard path, receiving the start of the decoded float RGBA buffer. [callee:0x00507845, field:this:0x00000010, field:this:0x00001058, source:raw]

    // Conservative worker pseudocode:
    //   void TextureDecodeLuminanceAlphaToFloatRGBA(DWORD* this, int x, int y, float* a4) {
    //       DWORD* src = (DWORD*)(*(this+0x18) + y * *(this+0x1054) + x * *(this+0x1050));
    //       DWORD* end = &src[*(this+0x1058)];
    //       for (; src < end; src++, a4 += 4) {
    //           a4[0] = (WORD)*src      * 0.000015259022f;   // R = luminance
    //           a4[1] = (WORD)*(src-1)  * 0.000015259022f;   // G = luminance (upper half)
    //           a4[2] = 1.0f;                                  // B
    //           a4[3] = 1.0f;                                  // A
    //       }
    //       if (*(this+0x10)) ContactManifoldCleanup(this, a4 - 4 * *(this+0x1058));
    //   }
    // UNRESOLVED: The exact pairing of read-only globals flt_5AD290 and flt_5ADB14 with the luminance-scale multiply is not proven: the raw source shows a single literal 0.000015259022 while two distinct scale globals are referenced.
    // UNRESOLVED: The per-channel semantics (luminance duplicated into both R and G, B forced to 1.0) are DERIVED from the existing fill and the loop's write order, not independently proven by a named struct contract.
    // UNRESOLVED: The existing fill labels flt_5ADB14 as DegreeWrap360; that identification appears inconsistent with its use here as a decode scale factor and is not treated as confirmed by this packet.
    // UNRESOLVED: ContactManifoldCleanup (0x00507845) is a legacy mislabel; the actual purpose of the post-decode step it performs is not established by this packet.
}
