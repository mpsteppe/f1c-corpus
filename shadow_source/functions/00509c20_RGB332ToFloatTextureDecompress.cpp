// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00509C20
// Canonical corpus name: RGB332ToFloatTextureDecompress
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RGB332ToFloatTextureDecompress_00509c20.c

void UnknownObject::RGB332ToFloatTextureDecompress()
{
    // Decodes an 8-bit RGB332-packed texture block to 32-bit float RGBA. Computes the source byte pointer as this[6] (+0x18) + a3 * this[1045] (+0x1054) + a2 * this[1044] (+0x1050), then loops over this[1046] (+0x1058) source bytes, expanding each into 4 consecutive floats: red = (top 3 bits) * 0.14285715, green = (middle 3 bits) * 0.14285715, blue = (low 2 bits) * 0.33333334, alpha = 1.0. If the this[4] (+0x10) flag is set, calls ContactManifoldCleanup on the decoded float buffer before returning.
    // CALCULATION: Compute the source block base pointer: this[6] (+0x18) + a3 * this[1045] (+0x1054) + a2 * this[1044] (+0x1050), selecting the row (a3) and slice (a2) within the texture. [field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: Iterate over this[1046] (+0x1058) source bytes, from v5 to v5 + this[1046], decoding each byte into 4 consecutive floats; a4 advances by 4 floats per byte. [field:this:0x00001058, source:raw]
    // CALCULATION: Write the red float as (*v5 >> 5) * 0.14285715 (top 3 bits scaled by ~1/7); the scale constant is materialized from read global 0x005AD210. [global:0x005AD210, source:raw]
    // CALCULATION: Write the green float as ((*v5 >> 2) & 7) * 0.14285715 (middle 3 bits scaled by ~1/7); the scale constant is materialized from read global 0x005AD210. [global:0x005AD210, source:raw]
    // CALCULATION: Write the blue float as (*v5 & 3) * 0.33333334 (low 2 bits scaled by ~1/3); the scale constant is materialized from read global 0x0059E98C. [global:0x0059E98C, source:raw]
    // ASSIGNMENT: Write the alpha float 1.0 to *(a4 - 1) as the loop increment step of each iteration. [source:raw]
    // GUARD: If this[4] (+0x10 flag) is non-zero, run the post-processing pass on the decoded float buffer. [field:this:0x00000010, source:raw]
    // CALL: Call ContactManifoldCleanup(this, output buffer base), where the base is a4 - 4 * this[1046] floats after the loop, i.e. the start of the decoded float RGBA buffer. [callee:0x00507845, field:this:0x00001058, source:raw]
    // RETURN: Return (void); execution ends after the optional post-processing pass. [source:raw]

    // Conservative worker pseudocode:
    //   float *RGB332ToFloatTextureDecompress(int a2, int a3, float *a4) {
    //     byte *v5 = (byte *)(this[6] + a3 * this[1045] + a2 * this[1044]);
    //     byte *end = v5 + this[1046];
    //     for (; v5 < end; ++v5) {
    //       a4[0] = (float)(v5[0] >> 5) * 0.14285715f;
    //       a4[1] = (float)((v5[0] >> 2) & 7) * 0.14285715f;
    //       a4[2] = (float)(v5[0] & 3) * 0.33333334f;
    //       a4[3] = 1.0f;
    //       a4 += 4;
    //     }
    //     if (this[4])
    //       ContactManifoldCleanup((int)this, (unsigned int)(a4 - 4 * this[1046]));
    //   }
    // UNRESOLVED: The two read globals 0x0059E98C and 0x005AD210 carry the scale constants, but the exact pairing to the ~1/7 and ~1/3 multipliers is not proven by the raw source, which shows inline literals.
    // UNRESOLVED: The semantics of the +0x10 post-process flag and the ContactManifoldCleanup pass are inherited from existing analysis (DERIVED), not independently confirmed.
    // UNRESOLVED: The channel-to-float mapping (top 3 bits -> red, middle 3 bits -> green, low 2 bits -> blue) is inferred from the bit arithmetic and the RGB332 packing scheme in existing analysis; not independently proven.
    // UNRESOLVED: No caller or owner evidence exists; the owning object and invocation context are unknown.
}
