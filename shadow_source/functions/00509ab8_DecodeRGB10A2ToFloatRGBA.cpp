// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00509AB8
// Canonical corpus name: VertexTextureDecoderRGBA1010102
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VertexTextureDecoderRGBA1010102_00509ab8.c

void UnknownObject::DecodeRGB10A2ToFloatRGBA()
{
    // Decodes packed 32-bit RGBA10/10/10/2 texture words to 32-bit float RGBA. Computes the source pixel pointer as this[6] (field 0x18) plus a3 * this[1045] (field 0x1054) plus a2 * this[1044] (field 0x1050). For this[1046] (field 0x1058) pixels, extracts 10-bit red, 10-bit green and 10-bit blue (each scaled by 0.00097751711) and the 2-bit alpha (scaled by 0.33333334), writing four floats per pixel. If this[4] (field 0x10) is non-zero, calls ContactManifoldCleanup on the decoded float RGBA buffer.
    // CALCULATION: Compute the source pixel pointer as this[6] (field 0x18) plus a3 * this[1045] (field 0x1054) plus a2 * this[1044] (field 0x1050). [field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: Iterate over this[1046] (field 0x1058) pixels, consuming one 32-bit word each and writing four floats per pixel. [field:this:0x00001058, source:raw]
    // CALCULATION: Decode the four channels: red = (pixel & 0x3FF) * 0.00097751711, green = ((pixel >> 10) & 0x3FF) * 0.00097751711, blue = ((pixel >> 20) & 0x3FF) * 0.00097751711, alpha = (pixel >> 30) * 0.33333334, using float scales held in the global constants. [global:0x0059E98C, global:0x005ADB14, global:0x005ADBA4, source:raw]
    // ASSIGNMENT: Advance the input pointer by one word and the output pointer by four floats each iteration. [source:raw]
    // GUARD: If this[4] (field 0x10) is non-zero, run the post-processing cleanup on the decoded buffer. [field:this:0x00000010, source:raw]
    // CALL: Call ContactManifoldCleanup(this, output_start) where output_start is the base of the decoded float RGBA buffer. [callee:0x00507845, field:this:0x00000010, source:raw]

    // Conservative worker pseudocode:
    //   src = (int*)(this[6] + a3 * this[1045] + a2 * this[1044]);
    //   out = a4;
    //   for (i = 0; i < this[1046]; i++) {
    //       px = *src++;
    //       out[0] = (float)(px & 0x3FF) * 0.00097751711;
    //       out[1] = (float)((px >> 10) & 0x3FF) * 0.00097751711;
    //       out[2] = (float)((px >> 20) & 0x3FF) * 0.00097751711;
    //       out[3] = (float)(px >> 30) * 0.33333334;
    //       out += 4;
    //   }
    //   if (this[4])
    //       ContactManifoldCleanup((int)this, (unsigned int)out - 4 * this[1046]);
    // UNRESOLVED: The exact assignment of the float globals flt_59E98C, flt_5ADB14 and flt_5ADBA4 to the channel scales 0.00097751711 and 0.33333334 is not directly evidenced; Hex-Rays folded them into literals. The existing_analysis names (AccelerationTuningFactor, DegreeWrap360, RGB10ChannelScale) are DERIVED and unverified.
    // UNRESOLVED: ContactManifoldCleanup's actual effect (the name is corpus-assigned) is not evidenced from this function alone.
    // UNRESOLVED: The general meaning of this[4] (field 0x10) is not evidenced beyond gating the cleanup call.
}
