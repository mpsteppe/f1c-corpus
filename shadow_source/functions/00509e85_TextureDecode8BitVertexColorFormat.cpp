// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00509E85
// Canonical corpus name: F_8BitVertexColorDecoder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_8BitVertexColorDecoder_00509e85.c

void UnknownObject::TextureDecode8BitVertexColorFormat()
{
    // Decodes 8-bit palette-indexed texture data with an 8-bit alpha byte to 32-bit float RGBA. Computes the source pixel pointer as this[6] (field 0x18) plus a3 * this[1045] (field 0x1054) plus a2 * this[1044] (field 0x1050). Loops over this[1046] (field 0x1058) pixels, consuming two bytes per pixel. The first byte indexes a this-relative palette table of 4-float entries and copies the entry's four floats (RGB and an initial alpha) into the output pixel; the second byte is then scaled by 0.0039215689 (the 1/255 float folded from flt_59E460) and overwrites the output alpha channel. If this[4] (field 0x10) is non-zero, calls ContactManifoldCleanup on the decoded float RGBA buffer.
    // CALCULATION: Compute the source pixel pointer as this[6] (field 0x18) plus a3 * this[1045] (field 0x1054) plus a2 * this[1044] (field 0x1050). [field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: Iterate over this[1046] (field 0x1058) pixels, consuming two bytes per pixel (end pointer is src + 2 * this[1046]) and writing four floats per pixel. [field:this:0x00001058, source:raw]
    // CALCULATION: Look up a 4-float palette entry using the first pixel byte as an index into a this-relative palette table (v7 = &this[4 * *v4 + 12]) and copy the entry's four floats to the output RGB channels and an initial alpha. [source:raw]
    // CALCULATION: Decode the output alpha as the second pixel byte scaled by 0.0039215689, overwriting the alpha slot of the just-written output pixel. [global:0x0059E460, source:raw]
    // ASSIGNMENT: Advance the input pointer by two bytes and the output pointer by four floats each iteration. [source:raw]
    // GUARD: If this[4] (field 0x10) is non-zero, run the post-processing cleanup on the decoded buffer. [field:this:0x00000010, source:raw]
    // CALL: Call ContactManifoldCleanup(this, output_base) where output_base is computed as the base of the decoded float RGBA buffer (a4 - 4 * this[1046]). [callee:0x00507845, field:this:0x00000010, field:this:0x00001058, source:raw]

    // Conservative worker pseudocode:
    //   src = (byte*)(this[6] + a3 * this[1045] + a2 * this[1044]);
    //   out = a4;
    //   end = src + 2 * this[1046];
    //   for (p = src; p < end; p += 2) {
    //       pal = (float*)&this[4 * p[0] + 12];
    //       out[0] = pal[0];
    //       out[1] = pal[1];
    //       out[2] = pal[2];
    //       out[3] = pal[3];
    //       out[3] = (float)p[1] * 0.0039215689;
    //       out += 4;
    //   }
    //   if (this[4])
    //       ContactManifoldCleanup((int)this, (unsigned int)out - 4 * this[1046]);
    // UNRESOLVED: The palette table base (this[12], referenced by the raw source as &this[4 * *v4 + 12]) is not present as a packet field evidence reference; its exact offset and layout are inferred from source only.
    // UNRESOLVED: The float global flt_59E460 folded into the 0.0039215689 literal is not directly evidenced as the source of that constant.
    // UNRESOLVED: ContactManifoldCleanup's actual effect (the name is corpus-assigned) is not evidenced from this function alone.
    // UNRESOLVED: The general meaning of this[4] (field 0x10) is not evidenced beyond gating the cleanup call.
    // UNRESOLVED: The packet canonical name labels the format VertexColor; the decode is palette-indexed RGB plus an alpha byte, but the owning texture container type is unknown.
}
