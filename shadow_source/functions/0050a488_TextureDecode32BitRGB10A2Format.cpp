// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050A488
// Canonical corpus name: TextureDecode32BitRGB10A2Format
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureDecode32BitRGB10A2Format_0050a488.c

void UnknownObject::TextureDecode32BitRGB10A2Format()
{
    // Decodes 32-bit packed RGB10A2 texture data into float RGBA. Computes a source pointer from offset 0x18 plus row/slice strides at 0x1050/0x1054, then loops this[0x1058] times extracting three 10-bit sign-extended color channels (scaled by 0.001953125) and a 2-bit alpha (scaled by 0.33333334) per pixel, writing four floats per output element. When the flag at 0x10 is non-zero, runs ContactManifoldCleanup over the decoded buffer.
    // CALCULATION: Compute the source pixel pointer v4 = (DWORD*)(this[0x18] + a3 * this[0x1054] + a2 * this[0x1050]), indexing a pixel row (a3) and column (a2) into the source data pointer at offset 0x18 using the row stride 0x1054 and slice stride 0x1050. [source:raw, field:this:0x00000018, field:this:0x00001050, field:this:0x00001054]
    // LOOP: Iterate i = &v4[this[0x1058]]; v4 < i; over the pixel count at offset 0x1058, advancing v4 one DWORD per pixel. [source:raw, field:this:0x00001058]
    // CALCULATION: Extract the three 10-bit color fields with sign extension: R from bits 0-9, G from bits 10-19, B from bits 20-29 of the packed DWORD. [source:raw]
    // CALCULATION: Scale each extracted channel by 0.001953125 into float R, G, B output values. [source:raw]
    // ASSIGNMENT: Write float RGBA for the pixel: R, G, B channels followed by alpha = (double)(*v4 >> 30) * 0.33333334, advancing a4 by 4 floats per pixel. [source:raw]
    // GUARD: Guard on this[4] (flag at offset 0x10): if non-zero, run the post-process step over the decoded output buffer. [source:raw, field:this:0x00000010]
    // CALL: Call ContactManifoldCleanup(this, buffer-start) where buffer-start is a4 backed up by 4 * this[0x1058] floats, as the conditional post-process over the decoded RGBA buffer. [callee:0x00507845, source:raw]

    // Conservative worker pseudocode:
    //   void DecodeRGB10A2(DWORD* this, int a2, int a3, float* a4) {
    //     DWORD* v4 = (DWORD*)(this[6] + a3 * this[1045] + a2 * this[1044]);
    //     for (DWORD* i = &v4[this[1046]]; v4 < i; ) {
    //       a4[0] = (double)signext10((short)(v4[0] << 6) >> 6) * 0.001953125;
    //       a4[1] = (double)signext10((short)((WORD)(v4[0] >> 10) << 6) >> 6) * 0.001953125;
    //       a4[2] = (double)signext10((short)(v4[0] >> 20 << 6) >> 6) * 0.001953125;
    //       a4[3] = (double)(v4[0] >> 30) * 0.33333334;
    //       v4++; a4 += 4;
    //     }
    //     if (this[4]) ContactManifoldCleanup((int)this, (unsigned int)(a4 - 4 * this[1046]));
    //   }
    // UNRESOLVED: The packet's global list names three read floats (flt_59E4D8, flt_59E98C, flt_5ADB14); whether they feed the inlined 0.001953125 / 0.33333334 scales or are unrelated reads is not verifiable from this function's raw source.
    // UNRESOLVED: ContactManifoldCleanup post-process semantics (what the flag at 0x10 selects) are not established here.
    // UNRESOLVED: The sign-extension of the 10-bit channels implies a [-1,1] float range, which is a DERIVED interpretation, not a packet literal.
    // UNRESOLVED: The decode assumes little-endian packed DWORD pixel layout; a2/a3 semantics as column/row indices are inferred from stride arithmetic.
}
