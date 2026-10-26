// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00509CC2
// Canonical corpus name: TextureDecode8BitAlphaOnlyFormat
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureDecode8BitAlphaOnlyFormat_00509cc2.c

void UnknownObject::TextureDecode8BitAlphaOnlyFormat()
{
    // Decodes 8-bit alpha-only texture data to 32-bit float RGBA. Computes the source pixel pointer as this[6] (field 0x18) plus a3 * this[1045] (field 0x1054) plus a2 * this[1044] (field 0x1050). Loops over this[1046] (field 0x1058) pixels, consuming one byte per pixel, and writes RGB as 0.0 with the alpha channel set to the byte scaled by 0.0039215689 (the 1/255 float held in flt_59E460), writing four floats per pixel. If this[4] (field 0x10) is non-zero, calls ContactManifoldCleanup on the decoded float RGBA buffer.
    // CALCULATION: Compute the source pixel pointer as this[6] (field 0x18) plus a3 * this[1045] (field 0x1054) plus a2 * this[1044] (field 0x1050). [field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: Iterate over this[1046] (field 0x1058) pixels (this[1046] bytes), consuming one byte per pixel and writing four floats per pixel. [field:this:0x00001058, source:raw]
    // CALCULATION: Set the red, green and blue channels to 0.0 for each pixel. [source:raw]
    // CALCULATION: Decode the alpha channel as the byte value * 0.0039215689. [global:0x0059E460, source:raw]
    // ASSIGNMENT: Advance the input pointer by one byte and the output pointer by four floats each iteration. [source:raw]
    // GUARD: If this[4] (field 0x10) is non-zero, run the post-processing cleanup on the decoded buffer. [field:this:0x00000010, source:raw]
    // CALL: Call ContactManifoldCleanup(this, output_base) where output_base is computed as the base of the decoded float RGBA buffer (a4 - 4 * this[1046]). [callee:0x00507845, field:this:0x00000010, field:this:0x00001058, source:raw]

    // Conservative worker pseudocode:
    //   src = (byte*)(this[6] + a3 * this[1045] + a2 * this[1044]);
    //   out = a4;
    //   end = src + this[1046];
    //   for (p = src; p < end; p++) {
    //       out[0] = 0.0f;
    //       out[1] = 0.0f;
    //       out[2] = 0.0f;
    //       out[3] = (float)*p * 0.0039215689;
    //       out += 4;
    //   }
    //   if (this[4])
    //       ContactManifoldCleanup((int)this, (unsigned int)out - 4 * this[1046]);
    // UNRESOLVED: The exact assignment of the float global flt_59E460 to the alpha scale 0.0039215689 is not directly evidenced; Hex-Rays folded the value into a literal.
    // UNRESOLVED: ContactManifoldCleanup's actual effect (the name is corpus-assigned) is not evidenced from this function alone.
    // UNRESOLVED: The general meaning of this[4] (field 0x10) is not evidenced beyond gating the cleanup call.
    // UNRESOLVED: The packet's canonical name says AlphaOnly; the raw source zeroes the RGB channels, consistent with that, but the owning texture container type is unknown.
}
