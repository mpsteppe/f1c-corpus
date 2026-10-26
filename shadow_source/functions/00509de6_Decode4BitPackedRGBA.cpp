// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00509DE6
// Canonical corpus name: F_4BitPackedColorDecoder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4BitPackedColorDecoder_00509de6.c

void UnknownObject::Decode4BitPackedRGBA()
{
    // Decodes 4-bit-per-channel packed color texels into float RGBA output. Computes a source pointer from a 2D layout (base this[6], per-column pitch this[1044], per-row pitch this[1045]), iterates this[1046] texels reading 2 packed bytes each, scales each 4-bit nibble by the 1/15 constant at flt_5AC108 (0.06666667), writes three color floats plus a 1.0 alpha per texel, then optionally invokes the callee at 0x00507845 when flag this[4] is set.
    // CALCULATION: Compute the source pointer into the packed texture: v5 = base this[6] (this+0x18) + a3 * this[1045] (this+0x1054 row pitch) + a2 * this[1044] (this+0x1050 column pitch). [field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: Iterate texels: end pointer i = v5 + 2 * this[1046] (this+0x1058), advancing v5 by 2 packed bytes per iteration. [field:this:0x00001058, source:raw]
    // CALCULATION: Decode three 4-bit channels from the two packed bytes and scale each by 0.06666667 (1/15) read from flt_5AC108: low nibble of v5[1], high nibble of v5[0], low nibble of v5[0]. [global:0x005AC108, source:raw]
    // ASSIGNMENT: Write the three scaled color floats and set the alpha float to 1.0, advancing the output pointer a4 by 4 floats per texel. [source:raw]
    // GUARD: When flag this[4] (this+0x10) is nonzero, perform the trailing cleanup call. [field:this:0x00000010, source:raw]
    // CALL: Call the callee at 0x00507845 (named ContactManifoldCleanup) with this as the first argument and the start of the written float buffer (a4 minus 4 * this[1046] floats) as the second. [callee:0x00507845, field:this:0x00001058, source:raw]

    // Conservative worker pseudocode:
    //   void sub_509DE6(int *this, int a2, int a3, float *out) {
    //     unsigned char *src = (unsigned char *)(this[6] + a3 * this[1045] + a2 * this[1044]);
    //     unsigned char *end = src + 2 * this[1046];
    //     float *base = out;
    //     for (; src < end; src += 2) {
    //       out[0] = (float)(src[1] & 15) * 0.06666667f;
    //       out[1] = (float)((src[0] >> 4) & 15) * 0.06666667f;
    //       out[2] = (float)(src[0] & 15) * 0.06666667f;
    //       out[3] = 1.0f;
    //       out += 4;
    //     }
    //     if (this[4]) ContactManifoldCleanup((int)this, (unsigned int)base);
    //   }
    // UNRESOLVED: Channel ordering (which nibble is red vs green vs blue) is inferred from write order, not independently confirmed.
    // UNRESOLVED: The callee name ContactManifoldCleanup (0x00507845) is inconsistent with color decoding; it is likely a stale or twin-inherited label, and the call's true role (finalize/callback) is unresolved.
    // UNRESOLVED: Meaning of the guard flag this[4] (byte offset this+0x10) and the exact a2/a3 grid semantics are unknown.
    // UNRESOLVED: A cluster_copy prelabel (DERIVED) marks this function as a structural twin of TextureDecodeRGBA4, which supports the decode interpretation but is not independently verified.
}
