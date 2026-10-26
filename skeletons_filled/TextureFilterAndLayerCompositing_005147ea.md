## TextureFilterAndLayerCompositing_005147ea — DxtBlockCompressor

**Summary:** Compress 4×4 float4 pixel block to DXT/BC format: compute two endpoint colors via OBB projection, quantize to 16-bit 5:6:5, build 2-bit selector bitmask per pixel. Early exit if all pixels transparent (alpha<0.5).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FileIOWrapper (005152eb), QuantizationColorSpaceConversion (00515303), sub_515417 (00515417)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | float G — green channel of input pixel |
| this | 0x8 | R | — | float B — blue channel of input pixel |
| this | 0xC | R | — | float A — alpha channel, tested against 0.5 for transparency |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | near-zero threshold |
| 0059e450 | flt_59E450 | R | degrees-to-radians constant |
| 0059e98c | flt_59E98C | R | acceleration tuning factor |
| 0059e9e0 | flt_59E9E0 | R | color channel scale factor |
| 005accd0 | flt_5ACCD0 | R | 31.0 — R/B 5-bit quantization multiplier |
| 005accd4 | flt_5ACCD4 | R | 0.032258064 — red/blue decode scale (1/31) |
| 005accd8 | flt_5ACCD8 | R | 63.0 — G 6-bit quantization multiplier |
| 005accdc | flt_5ACCDC | R | 0.015873017 — green decode scale (1/63) |
| 005ad1f4 | flt_5AD1F4 | R | audio lerp coefficient |
| 005adb14 | flt_5ADB14 | R | 360.0 degree wrap |
| 005af618 | unk_5AF618 | R | image palette data table (v94==4) |
| 005af628 | unk_5AF628 | R | PNG data buffer table (v94==3) |
| 005af634 | flt_5AF634 | R | audio filter coefficient |
| 005af638 | flt_5AF638 | R | audio resample coefficient 2 |
| 005af63c | flt_5AF63C | R | audio resample coefficient |
| 005d79bc | flt_5D79BC | R | BVH min bounds / color space scale X |
| 005d79c0 | flt_5D79C0 | R | audio 3D position float / color space scale Y |
| 005d79c4 | flt_5D79C4 | R | render surface scale / color space scale Z |
| 005d79cc | flt_5D79CC | R | unknown float render / endpoint scale factor |
| 005d79d0 | flt_5D79D0 | R | texture quant scale |
| 005d79d4 | flt_5D79D4 | R | texture proc constant |
| 008b00a0 | dword_8B00A0 | R | FPU control word store |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00513d63 | F_16BitColorToFloat4Decoder | decode 16-bit 5:6:5 color back to float4 |
| 00513e5d | FPUControlWordMerger | set FPU rounding mode for quantization |
| 00513e80 | sub_513E80 | float3 RGB → 16-bit 5:6:5 packed format |
| 0051427f | OBBFittingAndProjection | compute optimal projection bounds for 16 color samples |

**Guard conditions (deterministic — field vs literal):**

| Condition | Value | Meaning |
|-----------|-------|---------|
| param a3 | != 0 | enable alpha test mode (count transparent pixels) |
| this+0xC (alpha) | < 0.5 | counted as transparent pixel |
| transparent count | == 16 | all pixels transparent → early exit with fully transparent block |
| transparent count | != 0 | mixed transparency → v94=3 (3-color mode) |
| param a3 | == 0 | no alpha test → v94=4 (4-color mode) |

**Guard interpretation:** If a3 != 0 and all 16 pixels have alpha<0.5 → early return with fully transparent block (all -1). If a3 != 0 and some transparent → 3-color mode (v94=3). If a3 == 0 → 4-color mode (v94=4). Otherwise always execute full compression pipeline.
