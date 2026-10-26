// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050A172
// Canonical corpus name: RGB565TextureDecompression
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RGB565TextureDecompression_0050a172.c

void UnknownObject::RGB565TextureDecompression()
{
    // Decodes a 16-bit packed texture block to 32-bit float RGBA. Computes the source pointer as this[6] (+0x18) + a3 * this[1045] (+0x1054) + a2 * this[1044] (+0x1050), then loops over this[1046] (+0x1058) pixels (2 source bytes each), writing 4 floats per pixel: first = sign-extended low 5 bits of the low byte * 0.0625, second = sign-extended 5 bits of (word >> 5) * 0.0625, third = 0.0, fourth = (word >> 10) * 0.015873017. If the this[4] (+0x10) flag is set, calls ContactManifoldCleanup on the decoded float buffer before returning.
    // CALCULATION: Compute the source block base pointer: this[6] (+0x18) + a3 * this[1045] (+0x1054) + a2 * this[1044] (+0x1050), selecting the row (a3) and slice (a2) within the texture. [field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: Iterate over this[1046] (+0x1058) pixels, from v5 to v5 + 2 * this[1046] (2 source bytes per pixel), writing 4 floats per pixel; a4 advances by 4 floats per iteration. [field:this:0x00001058, source:raw]
    // CALCULATION: Write the first float as ((char)(8 * *v5) >> 3) * 0.0625: the low 5 bits of the low byte sign-extended to 8 bits and scaled by ~1/16; scale constant materialized from read global 0x0059E9E0. [global:0x0059E9E0, source:raw]
    // CALCULATION: Write the second float as ((char)(8 * (word >> 5)) >> 3) * 0.0625: bits 5-9 of the 16-bit word sign-extended and scaled by ~1/16; scale constant materialized from read global 0x0059E9E0. [global:0x0059E9E0, source:raw]
    // ASSIGNMENT: Write the third float as 0.0 for every pixel. [source:raw]
    // CALCULATION: Write the fourth float as (word >> 10) * 0.015873017: the 6-bit field at bits 10-15 of the word scaled by ~1/63; scale constant materialized from read global 0x005ACCDC. [global:0x005ACCDC, source:raw]
    // GUARD: If this[4] (+0x10 flag) is non-zero, run the post-processing pass on the decoded float buffer. [field:this:0x00000010, source:raw]
    // CALL: Call ContactManifoldCleanup(this, output buffer base), where the base is a4 - 4 * this[1046] floats after the loop, i.e. the start of the decoded float RGBA buffer. [callee:0x00507845, field:this:0x00001058, source:raw]
    // RETURN: Return (void); execution ends after the optional post-processing pass. [source:raw]

    // Conservative worker pseudocode:
    //   float *RGB565TextureDecompression(int a2, int a3, float *a4) {
    //     byte *v5 = (byte *)(this[6] + a3 * this[1045] + a2 * this[1044]);
    //     byte *end = v5 + 2 * this[1046];
    //     for (; v5 < end; v5 += 2) {
    //       word w = *(word *)v5;
    //       a4[0] = (float)((char)(8 * v5[0]) >> 3) * 0.0625f;
    //       a4[1] = (float)((char)(8 * (w >> 5)) >> 3) * 0.0625f;
    //       a4[2] = 0.0f;
    //       a4[3] = (float)(w >> 10) * 0.015873017f;
    //       a4 += 4;
    //     }
    //     if (this[4])
    //       ContactManifoldCleanup((int)this, (unsigned int)(a4 - 4 * this[1046]));
    //   }
    // UNRESOLVED: The two read globals 0x0059E9E0 and 0x005ACCDC carry the scale constants, but the exact pairing to the ~1/16 and ~1/63 multipliers is not proven by the raw source, which shows inline literals.
    // UNRESOLVED: The sign-extension trick ((char)(8 * x) >> 3) is interpreted as signed 5-bit scaling; an unsigned interpretation is not ruled out by the packet.
    // UNRESOLVED: The third float is written as 0.0, leaving one of the four output components unused; the mapping of the three consumed bit fields to R/G/B/A components is not established beyond the raw arithmetic.
    // UNRESOLVED: The semantics of the +0x10 post-process flag and the ContactManifoldCleanup pass are inherited from existing analysis (DERIVED), not independently confirmed.
    // UNRESOLVED: No caller or owner evidence exists; the owning object and invocation context are unknown.
}
