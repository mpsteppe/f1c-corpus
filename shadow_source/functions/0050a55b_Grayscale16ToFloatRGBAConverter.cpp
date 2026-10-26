// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050A55B
// Canonical corpus name: F_16BitGrayscaleToRGBATextureConverter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_16BitGrayscaleToRGBATextureConverter_0050a55b.c

void UnknownObject::Grayscale16ToFloatRGBAConverter()
{
    // Converts unsigned 16-bit grayscale texture data from a row/slice-addressed source buffer into 32-bit float RGBA output where R = G = B = luminance (uint16 * 0.000015259022) and A = 1.0, then optionally runs a post-process cleanup over the decoded output when the object's +0x10 flag is set.
    // CALCULATION: Compute the source buffer base: this+0x18 plus a3 slices (stride this+0x1054) plus a2 rows (stride this+0x1050). [field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: Iterate this+0x1058 source uint16 grayscale values, emitting one float4 per value. [field:this:0x00001058, source:raw]
    // ASSIGNMENT: Read the uint16 luminance value and scale it by 0.000015259022. [source:raw]
    // ASSIGNMENT: Write the scaled luminance to the R, G and B output slots (a4[0], a4[1], a4[2]). [source:raw]
    // ASSIGNMENT: Write A = 1.0 into the alpha output slot on every loop iteration. [source:raw]
    // GUARD: When the object flag at this+0x10 is non-zero, run the post-process step over the decoded output buffer. [field:this:0x00000010, source:raw]
    // CALL: Call ContactManifoldCleanup with the object and the start of the decoded float RGBA buffer. [callee:0x00507845, source:raw]

    // Conservative worker pseudocode:
    //   void sub_50A55B(Object* this, int a2, int a3, float* a4) {
    //     unsigned short* v4 = this[6] + a3 * this[1045] + a2 * this[1044];
    //     for (unsigned short* i = &v4[this[1046]]; v4 < i; a4[3] = 1.0f) {
    //       float v7 = (float)*v4++ * 0.000015259022f;
    //       a4[2] = v7;
    //       a4[1] = v7;
    //       a4[0] = v7;
    //       a4 += 4;
    //     }
    //     if (this[4]) ContactManifoldCleanup(this, a4 - 4 * this[1046]);
    //   }
    // UNRESOLVED: The packet lists the global flt_5AD290 as the luminance scale, but the raw source renders the scale as the inline literal 0.000015259022; the global cannot be confirmed as the same constant from this packet alone.
    // UNRESOLVED: The identity and exact purpose of the ContactManifoldCleanup post-process step is inherited from a skeleton name and not verifiable from this packet.
}
