// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00514FEE
// Canonical corpus name: KeyframeQuadInterpolationWithBitPackedSelector
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/KeyframeQuadInterpolationWithBitPackedSelector_00514fee.c

void UnknownObject::DxtBlockDecompressor()
{
    // Decode one 4x4 DXT/BC-style block into 16 float4 colors. Reads two 16-bit endpoint colors from a2[0] and a2[1], decodes each to a float4 via F_16BitColorToFloat4Decoder, then builds a 4-color palette: when endpoint word 0 > endpoint word 1 the palette holds 1/3 and 2/3 interpolation points (4-color mode); otherwise it holds one midpoint plus four zero slots (transparent 2-color mode). A 32-bit selector mask at a2+4 supplies 2 selector bits per pixel; each pixel copies the chosen palette float4 into the output array a1 (four consecutive floats per pixel).
    // CALL: Decode the first 16-bit endpoint color at a2[0] into the four-float buffer v15..v18 via F_16BitColorToFloat4Decoder [callee:0x00513D63, source:raw]
    // CALL: Decode the second 16-bit endpoint color at a2[1] into the four-float buffer v19..v22 via F_16BitColorToFloat4Decoder [callee:0x00513D63, source:raw]
    // CALCULATION: When endpoint word 0 > endpoint word 1, build the 4-color palette: per channel, the two midpoints are computed at 0.33333334 and 0.66666669 fractions between the two decoded endpoints [source:raw]
    // CALCULATION: Otherwise (word 0 <= word 1) build the 2-color palette: per channel a single 0.5 midpoint, with the remaining palette slots zeroed (0.0) [source:raw]
    // LOOP: Expand the 32-bit selector mask (read at a2+4): 16 iterations, each taking 2 selector bits, selecting the corresponding palette float4 and writing it to the output array at a1 (floats at a1[0..3], advancing 4 floats per pixel, which corresponds to this+0x0 / +0x4 / +0x8 / +0xC) [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // RETURN: Return 0; DXT-style block decompression helper called by sub_51512C (0051512c) and sub_5151AF (005151af) [function:0x00514FEE, caller:0x0051512C, caller:0x005151AF, source:raw]

    // Conservative worker pseudocode:
    //   color0 = a2[0]; color1 = a2[1];
    //   F_16BitColorToFloat4Decoder(&pal[0], color0);
    //   F_16BitColorToFloat4Decoder(&pal[4], color1);
    //   if (color0 > color1) {  // 4-color mode
    //     pal[8]  = pal[0] + (pal[4] - pal[0]) * 0.33333334;   // per channel
    //     pal[12] = pal[0] + (pal[4] - pal[0]) * 0.66666669;   // per channel
    //   } else {                 // 2-color mode
    //     pal[8..11] = pal[0] + (pal[4] - pal[0]) * 0.5;       // per channel
    //     pal[12..15] = 0.0;
    //   }
    //   selector = a2[4];  // 32-bit selector mask
    //   for (pixel = 0; pixel < 16; ++pixel) {
    //     index = (selector >> (2 * pixel)) & 3;
    //     a1[0] = pal[4*index+0]; a1[1] = pal[4*index+1]; a1[2] = pal[4*index+2]; a1[3] = pal[4*index+3];
    //     a1 += 4;
    //   }
    //   return 0;
    // UNRESOLVED: Three read-only globals (flt_59E450, flt_59E98C, flt_5AD1F4) are flagged by packet facts but appear nowhere in the raw decompiled source; the skeleton labels them as constants (degrees-to-radians, acceleration tuning, audio lerp) which are unverifiable from this packet
    // UNRESOLVED: The interpolation fractions 0.33333334 / 0.66666669 / 0.5 are the only literal values; the 2-color branch zeroing slots 3 and 4 matches BC1 transparent-style but that interpretation is inferred
}
