// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050A92D
// Canonical corpus name: VertexColorPackRGBto16
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VertexColorPackRGBto16_0050a92d.c

void UnknownObject::VertexColorPackRGBto16()
{
    // Vertex-color encoder: reads floating-point RGBA vertex color data from the source stream, converts each texel to a luma-plus-two-chroma (YCbCr-like) representation using coefficient constants, offsets and clamps each channel to the 8-bit range, and packs pairs of channels into 16-bit words written to a destination buffer. Runs only while both a work flag (this+0x108C) and an enable flag (this+0x1090) are set, then clears the work flag. The destination WORD pointer is computed from this+0x18 plus pitch/stride products and the starting index.
    // GUARD: Guard: the packing pass runs only when both the work flag this+0x108C and the enable flag this+0x1090 are non-zero. [field:this:0x0000108C, field:this:0x00001090]
    // ASSIGNMENT: v1 = a1[1052]; load the starting vertex index / loop counter seed from this+0x1070. [field:this:0x00001070]
    // CALCULATION: Compute the destination WORD pointer: base this+0x18 plus (this+0x1050 * this+0x1074) plus (this+0x1054 * this+0x1080) plus 2*v1. [field:this:0x00000018, field:this:0x00001050, field:this:0x00001074, field:this:0x00001054, field:this:0x00001080]
    // ASSIGNMENT: v2 = (float*)a1[1051]; source vertex-color float stream read from this+0x106C. [field:this:0x0000106C]
    // GUARD: Guard: the do-while loop runs only while the loop counter is below this+0x1078 (vertex count bound). [field:this:0x00001078]
    // LOOP: Per-texel do-while loop: each iteration advances the source pointer by 8 floats (one RGBA texel plus one stride texel), the destination pointer by 2 WORDs, and the loop counter by 2 dwords. [source:raw]
    // CALCULATION: Luma-like weighted channel sum v12 = 65.481003*v2[4] + 24.966*v2[6] + 128.55299*v2[5], using coefficient constants backed by the conversion-coefficient globals. [global:0x0059E450, global:0x005ADBF8, global:0x005ADBFC, source:raw]
    // CALCULATION: First chroma-like channel v10 = 112.0*v2[2] - 74.203003*v2[1] - 37.797001*v2[0], using coefficient constants backed by the conversion-coefficient globals. [global:0x005ADC00, global:0x005ADC04, global:0x005ADC08, source:raw]
    // CALCULATION: Second chroma-like channel v8 = 112.0*v2[0] - (93.786003*v2[1] + 18.214001*v2[2]), and the second luma sample v14 = 65.481003*v2[0] + 128.55299*v2[1] + 24.966*v2[2] + 0.5, with the 0.5 rounding add-in backed by a conversion-coefficient global. [global:0x005ADC0C, global:0x005ADC10, global:0x005ADC14, source:raw]
    // CALCULATION: Convert to integer channels with offsets: v3 = (int)v14 + 16, v4 = (int)(v12+0.5) + 16, v5 = (int)(v10+0.5) + 128, v6 = (int)(v8+0.5) + 128. [source:raw]
    // GUARD: Clamp v3 to the 8-bit range [0, 255]. [source:raw]
    // GUARD: Clamp v4 to the 8-bit range [0, 255]. [source:raw]
    // GUARD: Clamp v5 to the 8-bit range [0, 255]. [source:raw]
    // GUARD: Clamp v6 to the 8-bit range [0, 255]. [source:raw]
    // ASSIGNMENT: Pack two 16-bit words per texel: first word = (v5 << this+0x1098) | (v3 << this+0x1094), second word = (v6 << this+0x1098) | (v4 << this+0x1094), using the two shift-amount fields. [field:this:0x00001094, field:this:0x00001098, source:raw]
    // STATE_TRANSITION: After the packing loop, clear the work flag: a1[1059] = 0 (this+0x108C). [field:this:0x0000108C, source:raw]
    // RETURN: Return 0. [source:raw, function:0x0050A92D]

    // Conservative worker pseudocode:
    //   int VertexColorPackRGBto16(_DWORD *this) {
    //     if (!this[0x108C/4] || !this[0x1090/4]) return 0;
    //     v1 = this[0x1070/4];
    //     dst = (WORD*)(this[0x18/4] + this[0x1050/4] * this[0x1074/4]
    //                 + this[0x1054/4] * this[0x1080/4] + 2 * v1);
    //     src = (float*)this[0x106C/4];
    //     if (v1 < this[0x1078/4]) {
    //       do {
    //         luma1 = 65.481003*src[4] + 24.966*src[6] + 128.55299*src[5];
    //         c1    = 112.0*src[2] - 74.203003*src[1] - 37.797001*src[0];
    //         c2    = 112.0*src[0] - (93.786003*src[1] + 18.214001*src[2]);
    //         luma2 = 65.481003*src[0] + 128.55299*src[1] + 24.966*src[2] + 0.5;
    //         v3 = (int)luma2 + 16;  v4 = (int)(luma1+0.5) + 16;
    //         v5 = (int)(c1+0.5) + 128;  v6 = (int)(c2+0.5) + 128;
    //         clamp each of v3, v4, v5, v6 to [0, 255];
    //         dst[0] = (v5 << this[0x1098/4]) | (v3 << this[0x1094/4]);
    //         dst[1] = (v6 << this[0x1098/4]) | (v4 << this[0x1094/4]);
    //         v1 += 2; src += 8; dst += 2;
    //       } while (v1 < this[0x1078/4]);
    //     }
    //     this[0x108C/4] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Fields this+0x107C and this+0x1084 are listed as accessed by the deterministic extractor but do not appear in the raw source; their roles are unknown.
    // UNRESOLVED: Which specific coefficient global backs which specific conversion constant is not provable from the packet; the raw source shows the constants as float literals.
}
