## EngineSoundWaveTableGenerator_00513482 — EngineSoundWaveTableGenerator

**Summary:** Generate PCM wave tables for engine sound synthesis. Two paths: mono 256-entry linear ramp table, or multi-channel 16-bit wave table array with configurable quantization based on input amplitude profile.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextureImageColorTransform (0051378b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | R | — | flags word — bit 0x480 selects direct vs interpolated table fill |
| this | 0x61 | R | — | flags byte — bit 0x4 forces minimum shift to 5 |
| this | 0x116 | R | — | flags byte — bit 0x2 selects max-channel amplitude vs mean |
| this | 0x117 | R | — | bit-depth / quality selector — >8 selects multi-channel path |
| this | 0x12C | RW | — | quantization shift value (0-8) written by multi-channel path |
| this | 0x130 | R | — | float enable flag — must be non-zero for execution |
| this | 0x138 | RW | — | mono wave table pointer (256 bytes, allocated via sub_517E92) |
| this | 0x144 | RW | — | multi-channel wave table array pointer (allocated via sub_517E92) |
| this | 0x150 | R | — | channel 0 amplitude (unsigned byte) |
| this | 0x151 | R | — | channel 1 amplitude |
| this | 0x152 | R | — | channel 2 amplitude |
| this | 0x153 | R | — | mean amplitude value (used when bit 2 of 0x116 is clear) |

**Written-by note (persistence):**
- this 0x12C: written once — quantization shift; persists until overwritten
- this 0x138: written once — allocated mono table pointer; persists
- this 0x144: written once — allocated multi-channel array pointer; persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | 1.0 constant for normalization |
| 0059e430 | dbl_59E430 | R | near-zero sentinel for floating-point edge cases |
| 0059e880 | dbl_59E880 | R | lower threshold constant for quantization |
| 005adb58 | dbl_5ADB58 | R | unknown audio synthesis constant |
| 005adb60 | dbl_5ADB60 | R | unknown audio input constant |
| 005adb68 | dbl_5ADB68 | R | audio codec scaling constant |
| 005af430 | dbl_5AF430 | R | D3D device flag threshold |
| 005af438 | dbl_5AF438 | R | audio compression scaling double |
| 005af440 | dbl_5AF440 | R | audio quantization threshold |
| 005af448 | dbl_5AF448 | R | timer frequency scaling constant |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00517e92 | sub_517E92 | audio heap memory allocator |
| 00587bdc | CRTFtol | CRT floor-to-long (float-to-int conversion) |
| 005881f0 | sub_5881F0 | audio synthesis trig function (sine/cos) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x130 | != | 0.0 | float enable — entire function skipped if zero |
| this | 0x117 | > | 8 | bit-depth selector — >8 = multi-channel wave table array; <=8 = mono 256-entry table |

**Guard interpretation:** First guard: this+0x130 float must be non-zero or function returns immediately. Second guard: this+0x117 > 8 → multi-channel path (allocate 0x144 array, generate quantized 16-bit PCM tables). BLOCKED (early return from outer guard) when this+0x130 == 0.0. BLOCKED (mono path) when this+0x117 <= 8 → allocate 0x138 mono table with linear ramp.
