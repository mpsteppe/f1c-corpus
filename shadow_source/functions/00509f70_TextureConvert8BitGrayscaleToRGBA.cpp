// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00509F70
// Canonical corpus name: F_8BitGrayscaleToRGBATextureConverter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_8BitGrayscaleToRGBATextureConverter_00509f70.c

void UnknownObject::TextureConvert8BitGrayscaleToRGBA()
{
    // Converts 8-bit grayscale texture data to 32-bit float RGBA. Computes the source pixel pointer as this[6] (field 0x18) plus a3 * this[1045] (field 0x1054) plus a2 * this[1044] (field 0x1050). Loops over this[1046] (field 0x1058) pixels, consuming one byte per pixel, writes the byte scaled by 0.0039215689 (the 1/255 float folded from flt_59E460) to all three RGB channels, and sets the alpha channel to 1.0 for each pixel, writing four floats per pixel. If this[4] (field 0x10) is non-zero, calls ContactManifoldCleanup on the decoded float RGBA buffer.
    // CALCULATION: Compute the source pixel pointer as this[6] (field 0x18) plus a3 * this[1045] (field 0x1054) plus a2 * this[1044] (field 0x1050). [field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: Iterate over this[1046] (field 0x1058) pixels, consuming one byte per pixel (end pointer is src + this[1046]) and writing four floats per pixel. [field:this:0x00001058, source:raw]
    // CALCULATION: Decode the grayscale value as the byte scaled by 0.0039215689 and write it to all three RGB channels of the output pixel. [global:0x0059E460, source:raw]
    // ASSIGNMENT: Set the alpha channel of the output pixel to 1.0. [source:raw]
    // ASSIGNMENT: Advance the input pointer by one byte and the output pointer by four floats each iteration. [source:raw]
    // GUARD: If this[4] (field 0x10) is non-zero, run the post-processing cleanup on the decoded buffer. [field:this:0x00000010, source:raw]
    // CALL: Call ContactManifoldCleanup(this, output_base) where output_base is computed as the base of the decoded float RGBA buffer (a4 - 4 * this[1046]). [callee:0x00507845, field:this:0x00000010, field:this:0x00001058, source:raw]

    // Conservative worker pseudocode:
    //   src = (byte*)(this[6] + a3 * this[1045] + a2 * this[1044]);
    //   out = a4;
    //   end = src + this[1046];
    //   for (p = src; p < end; p++) {
    //       g = (float)*p * 0.0039215689;
    //       out[0] = g;
    //       out[1] = g;
    //       out[2] = g;
    //       out[3] = 1.0f;
    //       out += 4;
    //   }
    //   if (this[4])
    //       ContactManifoldCleanup((int)this, (unsigned int)out - 4 * this[1046]);
    // UNRESOLVED: The float global flt_59E460 folded into the 0.0039215689 literal is not directly evidenced as the source of that constant.
    // UNRESOLVED: ContactManifoldCleanup's actual effect (the name is corpus-assigned) is not evidenced from this function alone.
    // UNRESOLVED: The general meaning of this[4] (field 0x10) is not evidenced beyond gating the cleanup call.
    // UNRESOLVED: The packet canonical name labels the format GrayscaleToRGBA; the alpha channel is hard-coded to 1.0, but the owning texture container type is unknown.
}
