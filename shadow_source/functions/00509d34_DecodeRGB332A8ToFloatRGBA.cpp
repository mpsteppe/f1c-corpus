// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00509D34
// Canonical corpus name: TextureDecodeRGB565
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureDecodeRGB565_00509d34.c

void UnknownObject::DecodeRGB332A8ToFloatRGBA()
{
    // Decodes packed 16-bit ARGB texture pixels (one RGB332 byte plus one alpha byte) to 32-bit float RGBA. Computes the source pixel pointer as this[6] (field 0x18) plus a3 * this[1045] (field 0x1054) plus a2 * this[1044] (field 0x1050). For this[1046] (field 0x1058) pixels it extracts 3-bit red, 3-bit green and 2-bit blue (scaled by 0.14285715 and 0.33333334) from the first byte and an eight-bit alpha (scaled by 0.0039215689) from the second byte, writing four floats per pixel. If this[4] (field 0x10) is non-zero, calls ContactManifoldCleanup on the decoded float RGBA buffer.
    // CALCULATION: Compute the source pixel pointer as this[6] (field 0x18) plus a3 * this[1045] (field 0x1054) plus a2 * this[1044] (field 0x1050). [field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: Iterate over this[1046] (field 0x1058) pixels, consuming two bytes per pixel and writing four floats per pixel. [field:this:0x00001058, source:raw]
    // CALCULATION: Decode the four channels: red = ((*v5 >> 5) & 7) * 0.14285715, green = ((*v5 >> 2) & 7) * 0.14285715, blue = (*v5 & 3) * 0.33333334, alpha = *(v5 + 1) * 0.0039215689, using float scales held in the global constants. [global:0x0059E460, global:0x0059E98C, global:0x005AD210, source:raw]
    // ASSIGNMENT: Advance the input pointer by two bytes and the output pointer by four floats each iteration. [source:raw]
    // GUARD: If this[4] (field 0x10) is non-zero, run the post-processing cleanup on the decoded buffer. [field:this:0x00000010, source:raw]
    // CALL: Call ContactManifoldCleanup(this, output_start) where output_start is the base of the decoded float RGBA buffer. [callee:0x00507845, field:this:0x00000010, source:raw]

    // Conservative worker pseudocode:
    //   src = (byte*)(this[6] + a3 * this[1045] + a2 * this[1044]);
    //   out = a4;
    //   for (i = 0; i < this[1046]; i++) {
    //       p = src;
    //       out[0] = (float)((p[0] >> 5) & 7) * 0.14285715;
    //       out[1] = (float)((p[0] >> 2) & 7) * 0.14285715;
    //       out[2] = (float)(p[0] & 3) * 0.33333334;
    //       out[3] = (float)p[1] * 0.0039215689;
    //       src += 2;
    //       out += 4;
    //   }
    //   if (this[4])
    //       ContactManifoldCleanup((int)this, (unsigned int)out - 4 * this[1046]);
    // UNRESOLVED: The exact assignment of the float globals flt_59E460, flt_59E98C and flt_5AD210 to the channel scales 0.14285715, 0.33333334 and 0.0039215689 is not directly evidenced; Hex-Rays folded them into literals. The existing_analysis names (AlphaScaleFactor, AccelerationTuningFactor, ThreeBitChannelScale) are DERIVED and unverified.
    // UNRESOLVED: ContactManifoldCleanup's actual effect (the name is corpus-assigned) is not evidenced from this function alone.
    // UNRESOLVED: The general meaning of this[4] (field 0x10) is not evidenced beyond gating the cleanup call.
}
