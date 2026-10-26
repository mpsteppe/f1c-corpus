// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00515303
// Canonical corpus name: QuantizationColorSpaceConversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuantizationColorSpaceConversion_00515303.c

void UnknownObject::QuantizationColorSpaceConversion()
{
    // BC3/DXT5 alpha-block encoder. Quantizes 16 alpha samples to 4-bit nibbles with error diffusion and packs the nibbles MSB-first into two DWORD outputs (a1, a1+4), then delegates color-block compression to TextureFilterAndLayerCompositing.
    // ASSIGNMENT: clear packed outputs: *a1 = 0 and a1[1] = 0 [field:this:0x00000000, field:this:0x00000004, source:raw]
    // CALCULATION: zero the 16-entry error-diffusion buffer v11 via memset [source:raw]
    // CALL: call FPUControlWordMerger() to configure the FPU control/rounding word for the quantization arithmetic [callee:0x00513E5D]
    // UNKNOWN: loop counter v16 is loaded from register v3 whose initialization is not visible in the decompilation; loop executes while v16 < 16, implying a start of 0 [source:raw]
    // ASSIGNMENT: v15 = a2 + 3 selects the alpha component of each float4 pixel [source:raw]
    // LOOP: iterate 16 pixels; for each accumulate v4 = error v11[v16] + current alpha sample [source:raw]
    // CALCULATION: quantize to a 4-bit nibble: v13 = v4 * 15.0 + 0.5, nibble = (int)v13 [source:raw]
    // ASSIGNMENT: pack nibble MSB-first: a1[v16 >> 3] = (nibble << 28) | (previous value >> 4) [field:this:0x00000000, field:this:0x00000004, source:raw]
    // CALCULATION: compute residual quantization error v9 = v4 - nibble * 0.06666667 (inverse of 15) [source:raw]
    // GUARD: if (v16 & 3) != 3 diffuse error right: v11[v16 + 1] += 0.4375 * v9 [source:raw]
    // GUARD: if v16 < 12 diffuse to the next row: v11[v16 + 4] += 0.3125 * v9; when (v16 & 3) != 0 also down-left v11[v16 + 3] += 0.1875 * v9; when (v16 & 3) != 3 also down-right v11[v16 + 5] += 0.0625 * v9 [source:raw]
    // CALL: delegate color-block compression: return TextureFilterAndLayerCompositing(a2, a1 + 2 dwords, 0) [callee:0x005147EA, field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   out[0] = 0; out[1] = 0;
    //   memset(error, 0, sizeof(error));
    //   FPUControlWordMerger();
    //   pos = 0;                        // v16; register init not visible in decompilation
    //   alpha = samples + 3;            // float4 stride selects the alpha component
    //   for (; pos < 16; pos++, alpha += 4) {
    //       val = error[pos] + *alpha;
    //       nib = (int)(val * 15.0f + 0.5f);
    //       out[pos >> 3] = (nib << 28) | (out[pos >> 3] >> 4);
    //       err = val - (float)nib * 0.06666667f;   // 1/15
    //       if ((pos & 3) != 3) error[pos + 1] += 0.4375f * err;
    //       if (pos < 12) {
    //           if ((pos & 3) != 0) error[pos + 3] += 0.1875f * err;
    //           error[pos + 4] += 0.3125f * err;
    //           if ((pos & 3) != 3) error[pos + 5] += 0.0625f * err;
    //       }
    //   }
    //   return TextureFilterAndLayerCompositing(samples, (int)(out + 2), 0);
    // UNRESOLVED: globals flt_59E450, flt_59E8D8, flt_59E9E0, flt_5AC108, flt_5ADB14, flt_5AF634, flt_5AF638, flt_5AF63C and dword_8B00A0 appear in the packet global list but not in the visible decompiled body; they may be consumed inside FPUControlWordMerger or TextureFilterAndLayerCompositing, or be mis-attributed
    // UNRESOLVED: loop counter v16 initialization is not visible (register v3); the 16-iteration range is DERIVED from the v16 < 16 condition
    // UNRESOLVED: the MSB-first nibble ordering is DERIVED from the shift/pack expression (nibble << 28 | prev >> 4)
}
