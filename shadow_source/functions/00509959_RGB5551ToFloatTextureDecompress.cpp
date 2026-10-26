// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00509959
// Canonical corpus name: RGB5551ToFloatTextureDecompress
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RGB5551ToFloatTextureDecompress_00509959.c

void UnknownObject::RGB5551ToFloatTextureDecompress()
{
    // Decodes packed 16-bit RGB5-5-5-1 texture pixels to 32-bit float RGBA. Computes the source pixel pointer as this[6] (field 0x18) plus a3 * this[1045] (field 0x1054) plus a2 * this[1044] (field 0x1050). Loops over this[1046] (field 0x1058) pixels, consuming two bytes per pixel, and unpacks the 5-bit red, green and blue channels (each scaled by 0.032258064, the 1/31 float held in flt_5ACCD4) plus a 1-bit alpha stored unscaled, writing four floats per pixel. If this[4] (field 0x10) is non-zero, calls ContactManifoldCleanup on the decoded float RGBA buffer.
    // CALCULATION: Compute the source pixel pointer as this[6] (field 0x18) plus a3 * this[1045] (field 0x1054) plus a2 * this[1044] (field 0x1050). [field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: Iterate over this[1046] (field 0x1058) pixels (2 * this[1046] bytes), consuming two bytes per pixel and writing four floats per pixel. [field:this:0x00001058, source:raw]
    // CALCULATION: Decode the red channel as ((uint16 >> 10) & 0x1F) * 0.032258064. [global:0x005ACCD4, source:raw]
    // CALCULATION: Decode the green channel as ((uint16 >> 5) & 0x1F) * 0.032258064. [global:0x005ACCD4, source:raw]
    // CALCULATION: Decode the blue channel as (byte & 0x1F) * 0.032258064. [global:0x005ACCD4, source:raw]
    // CALCULATION: Decode the alpha channel as the 1-bit value (uint16 >> 15), stored without scaling. [source:raw]
    // ASSIGNMENT: Advance the input pointer by two bytes and the output pointer by four floats each iteration. [source:raw]
    // GUARD: If this[4] (field 0x10) is non-zero, run the post-processing cleanup on the decoded buffer. [field:this:0x00000010, source:raw]
    // CALL: Call ContactManifoldCleanup(this, output_base) where output_base is computed as the base of the decoded float RGBA buffer (a4 - 4 * this[1046]). [callee:0x00507845, field:this:0x00000010, field:this:0x00001058, source:raw]

    // Conservative worker pseudocode:
    //   src = (byte*)(this[6] + a3 * this[1045] + a2 * this[1044]);
    //   out = a4;
    //   end = src + 2 * this[1046];
    //   for (p = src; p < end; p += 2) {
    //       word = *(unsigned short*)p;
    //       out[0] = (float)((word >> 10) & 0x1F) * 0.032258064;
    //       out[1] = (float)((word >> 5) & 0x1F) * 0.032258064;
    //       out[2] = (float)(p[0] & 0x1F) * 0.032258064;
    //       out[3] = (float)(word >> 15);
    //       out += 4;
    //   }
    //   if (this[4])
    //       ContactManifoldCleanup((int)this, (unsigned int)out - 4 * this[1046]);
    // UNRESOLVED: The exact assignment of the float global flt_5ACCD4 to the 5-bit channel scale 0.032258064 is not directly evidenced; Hex-Rays folded the value into literals.
    // UNRESOLVED: ContactManifoldCleanup's actual effect (the name is corpus-assigned) is not evidenced from this function alone.
    // UNRESOLVED: The general meaning of this[4] (field 0x10) is not evidenced beyond gating the cleanup call.
    // UNRESOLVED: The 1-bit alpha is emitted as the raw bit (0 or 1), not normalized to a [0,1] float range like the color channels.
}
