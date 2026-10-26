// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005098B7
// Canonical corpus name: TextureDecode16BitRGB565Format
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureDecode16BitRGB565Format_005098b7.c

void UnknownObject::TextureDecode16BitRGB565Format()
{
    // Decodes packed 16-bit texture words to float RGBA: computes the source pointer from this[6] plus a2/a3 scaled by the row-pitch and slice-stride fields, loops over this[1046] pixels reading 2 bytes each, extracts three 5-bit channels (R=(word>>10)&0x1F, G=(word>>5)&0x1F, B=word&0x1F), scales each by 0.032258064 (presumed flt_5ACCD4), writes four float outputs in RGBA order with alpha fixed to 1.0, then optionally runs ContactManifoldCleanup when this[4] is non-zero.
    // CALCULATION: Source pointer v5 = this[0x18] (this[6]) + a3 * this[0x1054] (this[1045]) + a2 * this[0x1050] (this[1044]); a2 and a3 index into the pixel data via the row-pitch and slice-stride fields. [field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: for-loop over this[0x1058] (this[1046]) pixels: read a 16-bit word at v5, extract R=(word>>10)&0x1F, G=(word>>5)&0x1F, B=word&0x1F, scale each channel by 0.032258064 (presumed flt_5ACCD4), write four float outputs in RGBA order with the alpha slot fixed to 1.0, and advance the source pointer 2 bytes per pixel. [field:this:0x00001058, global:0x005ACCD4, source:raw]
    // GUARD: Guard on this[0x10] (this[4]): if non-zero, ContactManifoldCleanup(this, output_buffer_start) is called on the decoded float buffer, where output_buffer_start is a4 minus 4 * this[1046] floats. [field:this:0x00000010, callee:0x00507845, source:raw]

    // Conservative worker pseudocode:
    //   void TextureDecode16BitRGB565Format(this, a2, a3, a4) {
    //     v5 = (BYTE*)(this[6] + a3 * this[1045] + a2 * this[1044]);
    //     for (i = v5 + 2 * this[1046]; v5 < i; a4[3] = 1.0) {
    //       w = *(WORD*)v5;
    //       a4[0] = (double)((w >> 10) & 0x1F) * 0.032258064;
    //       a4[1] = (double)((w >> 5) & 0x1F) * 0.032258064;
    //       a4[2] = (double)(w & 0x1F) * 0.032258064;
    //       a4 += 4; v5 += 2;
    //     }
    //     if (this[4]) ContactManifoldCleanup((int)this, (unsigned int)(a4 - 4 * this[1046]));
    //   }
    // UNRESOLVED: The channel layout is 5 bits per channel (R=(word>>10)&0x1F, G=(word>>5)&0x1F, B=word&0x1F, top bit unused) -- RGB555 in a 16-bit word -- despite the canonical name TextureDecode16BitRGB565Format.
    // UNRESOLVED: The 0.032258064 scale (1/31) is presumed to come from flt_5ACCD4 (0x005ACCD4); the binding is inferred, not proven.
    // UNRESOLVED: ContactManifoldCleanup (0x00507845) is named for collision/contact work yet here operates on the decoded texture buffer; its post-processing role is unknown.
}
