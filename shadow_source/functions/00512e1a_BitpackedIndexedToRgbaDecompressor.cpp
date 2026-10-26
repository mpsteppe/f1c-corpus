// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00512E1A
// Canonical corpus name: sub_512E1A
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_512E1A_00512e1a.c

void UnknownObject::BitpackedIndexedToRgbaDecompressor()
{
    // Two-phase bit-packed indexed texture decoder. Phase 1 (guarded on this+0x8 == 3) unpacks 4-bit, 2-bit or 1-bit planar fields from a packed source buffer into one byte per pixel, then stores this+0x9 = 8 and the processed pixel count into this+0x4. Phase 2 (guarded on this+0x9 == 8) looks each byte up in an RGB palette (base a3, 2 bytes stride per index) writing RGB output, or RGB plus an alpha byte sourced from secondary table a4 when a4 is non-zero. Output format state is recorded in this+0x8 (6=RGBA / 2=RGB), this+0xA (4 / 3 bytes per pixel) and this+0xB (32 / 24 stride), with the final output byte count written to this+0x4.
    // GUARD: Enter the bit-unpack phase only when this+0x8 == 3 (phase marker); otherwise the whole body is skipped [guard:0, field:this:0x00000008, source:raw]
    // CALCULATION: When this+0x9 < 8, dispatch on bit depth: 4-bit branch (this+0x9 == 4) shifts nibbles out of the packed buffer (offset a2 + (count-1)/2) and writes one byte per pixel, walking the destination backwards [field:this:0x00000009, field:this:0x00000000, source:raw]
    // CALCULATION: 2-bit branch (this+0x9 == 2) shifts 2-bit fields out of the packed buffer (offset a2 + (count-1)/4), writing one byte per pixel [field:this:0x00000009, field:this:0x00000000, source:raw]
    // CALCULATION: 1-bit branch (this+0x9 == 1) shifts single bits out of the packed buffer (offset a2 + (count-1)/8), writing one byte per pixel [field:this:0x00000009, field:this:0x00000000, source:raw]
    // ASSIGNMENT: After any unpack branch: this+0x9 set to 8, this+0xB set to 8, and this+0x4 set to the pixel count (a1[1] = result) [field:this:0x00000009, field:this:0x0000000B, field:this:0x00000004, source:raw]
    // GUARD: Color-lookup phase entered only when this+0x9 == 8 (the state byte set at the end of unpacking) [guard:1, field:this:0x00000009, source:raw]
    // CALCULATION: RGBA path (a4 non-zero): per pixel, index below a5 reads an alpha byte from table a4, otherwise writes -1; RGB triple read from the a3 palette at 2*index stride; output advances 4 bytes per pixel [field:this:0x00000000, field:this:0x00000009, source:raw]
    // CALCULATION: RGB path (a4 zero): per pixel, three palette bytes read from a3 at 2*index stride; output advances 3 bytes per pixel [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Record output format: RGBA path sets this+0xB = 32, this+0x8 = 6, this+0xA = 4; RGB path sets this+0xB = 24, this+0x8 = 2, this+0xA = 3; both set this+0x9 = 8 and this+0x4 = output byte count [field:this:0x00000009, field:this:0x0000000B, field:this:0x00000008, field:this:0x0000000A, field:this:0x00000004, source:raw]
    // RETURN: Return the pixel count; invoked by sub_51389E (0051389e) as part of the indexed-texture decode path [function:0x00512E1A, caller:0x0051389E, source:raw]

    // Conservative worker pseudocode:
    //   result = this+0x0;  // pixel count
    //   if (this+0x8 == 3) {  // bit-unpack phase
    //     depth = this+0x9;
    //     if (depth < 8) {
    //       if (depth == 4) for each pixel: out[i] = (src >> shift4) & 0xF; shift4 advances 4 bits per pixel across nibble pairs;
    //       else if (depth == 2) for each pixel: out[i] = (src >> shift2) & 3; shift2 advances 2 bits per pixel;
    //       else for each pixel: out[i] = (src >> shift1) & 1; shift1 advances 1 bit per pixel;
    //       this+0x9 = 8; this+0xB = 8; this+0x4 = result;
    //     }
    //     if (this+0x9 == 8) {  // color-lookup phase
    //       if (a4) {  // RGBA output
    //         for each pixel idx = src[i]:
    //           out[4i] = (idx < a5) ? table_a4[idx] : -1;
    //           out[4i+1..3] = palette[a3 + 2*idx + 0], palette[a3 + 2*idx + 1], palette[a3 + 2*idx + 2];
    //         this+0xB = 32; this+0x8 = 6; this+0xA = 4;
    //       } else {  // RGB output
    //         for each pixel idx = src[i]:
    //           out[3i+0..2] = palette[a3 + 2*idx + 0..2];
    //         this+0xB = 24; this+0x8 = 2; this+0xA = 3;
    //       }
    //       this+0x9 = 8; this+0x4 = outputByteCount;
    //     }
    //   }
    //   return result;
    // UNRESOLVED: The exact class owning the state object at a1 is not known; the skeleton labels it a texture format/phase descriptor
    // UNRESOLVED: The palette entry layout (2-byte stride per index over a3) is inferred from the address arithmetic in the lookup loops
}
