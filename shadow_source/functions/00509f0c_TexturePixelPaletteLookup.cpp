// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00509F0C
// Canonical corpus name: TexturePixelPaletteLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TexturePixelPaletteLookup_00509f0c.c

void UnknownObject::TexturePixelPaletteLookup()
{
    // Converts 8-bit palette-indexed texture data into floating-point RGBA output. Computes a source pointer from the struct's source-data field (this[6]) advanced by a2/a3 strides (this[1044]/this[1045]), then loops over this[1046] pixels reading each byte index into the struct's embedded palette table and writing four dwords per pixel to the output buffer a4. When the this[4] flag is non-zero, runs a post-process call (ContactManifoldCleanup) over the produced output range.
    // CALCULATION: Compute the source pointer v4 = this[6] (source pixel data at +0x18) + a3 * this[1045] (stride at +0x1054) + a2 * this[1044] (stride at +0x1050). [field:this:0x00000018, field:this:0x00001054, field:this:0x00001050, source:raw]
    // LOOP: for-loop over this[1046] (+0x1058) pixels, ascending v4 from the computed base to the end pointer at v4 + this[1046]. [field:this:0x00001058, source:raw]
    // CALCULATION: Index into the struct's embedded palette table using the current 8-bit pixel value: v7 = &this[4 * *v4 + 12]. [source:raw]
    // ASSIGNMENT: Write the palette entry to the output buffer: a4[0..2] from the entry, then a4[3] from the entry's second lane (loop step *v8 = v7[1], with v8 = a4 + 3), emitting four dwords per pixel. [source:raw]
    // CALCULATION: Advance the loop: ++v4 over the source bytes and a4 += 4 dwords over the output. [source:raw]
    // GUARD: Run the post-process step only when this[4] (+0x10) flag is non-zero. [field:this:0x00000010, source:raw]
    // CALL: Invoke ContactManifoldCleanup(this, output start) over the decoded output range bounded by this[1046] (+0x1058) pixels. [callee:0x00507845, field:this:0x00001058, source:raw]

    // Conservative worker pseudocode:
    //   void sub_509F0C(_DWORD* this, int a2, int a3, _DWORD* a4) {
    //     unsigned char* v4 = (unsigned char*)(this[6] + a3 * this[1045] + a2 * this[1044]);
    //     for (unsigned char* i = v4 + this[1046]; v4 < i; *((a4 + 3)) = v7[1]) {
    //       _DWORD* v7 = &this[4 * *v4 + 12];
    //       *a4 = *v7++;
    //       a4[1] = *v7++;
    //       a4[2] = *v7;
    //       _DWORD* v8 = a4 + 3;
    //       ++v4;
    //       a4 += 4;
    //     }
    //     if (this[4]) ContactManifoldCleanup((int)this, (unsigned int)&a4[-4 * this[1046]]);
    //   }
    // UNRESOLVED: The 'ContactManifoldCleanup' name for the post-process helper (0x00507845) is likely misleading for an output-buffer step; its real purpose is unknown.
    // UNRESOLVED: Exact base offset of the embedded palette table (indexed via this[4 * index + 12]) is not covered by a packet field; the +12 dword index is grounded in the raw source only.
    // UNRESOLVED: The axis mapping of the a2/a3 strides (this[1044] vs this[1045]) to rows vs slices is ambiguous from this function alone.
}
