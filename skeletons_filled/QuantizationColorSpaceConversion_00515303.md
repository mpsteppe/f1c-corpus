## QuantizationColorSpaceConversion_00515303 — Bc3Dxt5BlockEncoder

**Summary:** Encode 4×4 float4 block to BC3/DXT5: quantize alpha to 4-bit nibbles with error diffusion, pack 16 nibbles into two DWORDs (MSB-first), then delegate color block compression to TextureFilterAndLayerCompositing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DelegationWithErrorCheck (005158af)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | DWORD — first 8 packed alpha nibbles (bits 31:28 = pixel 0, etc.) |
| this | 0x4 | W | 0 | DWORD — next 8 packed alpha nibbles |

**Written-by note (persistence):**
- this 0x0: overwritten each call; survives until overwritten
- this 0x4: overwritten each call; survives until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | degrees-to-radians constant |
| 0059e8d8 | flt_59E8D8 | R | braking speed threshold 3 |
| 0059e9e0 | flt_59E9E0 | R | color channel scale factor |
| 005ac108 | flt_5AC108 | R | 0.06666667 — alpha nibble decode inverse (1/15) |
| 005adb14 | flt_5ADB14 | R | 360.0 degree wrap |
| 005af634 | flt_5AF634 | R | audio filter coefficient |
| 005af638 | flt_5AF638 | R | audio resample coefficient 2 |
| 005af63c | flt_5AF63C | R | audio resample coefficient |
| 008b00a0 | dword_8B00A0 | R | FPU control word store |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00513e5d | FPUControlWordMerger | set FPU rounding mode for quantization |
| 005147ea | TextureFilterAndLayerCompositing | compress color block (endpoint colors + 2-bit selector) |

**Guard conditions (deterministic — field vs literal):**

No guard conditions — function always executes 16-pixel loop unconditionally, then calls TextureFilterAndLayerCompositing.
