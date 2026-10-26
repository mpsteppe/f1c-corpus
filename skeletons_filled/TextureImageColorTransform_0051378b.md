## TextureImageColorTransform_0051378b — TextureColorTransformAndWaveTableGen

**Summary:** Two-pass texture/audio processing on shared state: generate engine sound wave tables and remap texture RGB pixels via lookup table (if format==3), then apply per-channel bit-shift color reduction (if flag bit 3 set and format==3).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioBufferSizeCalc (0051868c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x104) | 0x2 | RW | — | B channel of first pixel in buffer — read during shift, written during lookup remap |
| this | 0x60 | R | — | flags dword — bitmask test via 0x602000 enables pass 1; bit 3 enables pass 2 |
| this | 0x104 | R | — | pointer to pixel/audio data buffer |
| this | 0x108 | R | — | pixel count (WORD) |
| this | 0x116 | R | — | format indicator — must be 3 for both passes |
| this | 0x138 | R | — | palette/lookup table pointer (set by wave table generator) |
| this | 0x150 | R | — | red channel bit-shift amount (8 - amplitude) |
| this | 0x151 | R | — | green channel bit-shift amount |
| this | 0x152 | R | — | blue channel bit-shift amount |

**Written-by note (persistence):**
- *(this+0x104) 0x2: overwritten each call if passes activate; external poke survives (buffer is shared pixel data)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00602000 | unk_602000 | R | bitmask constant (address value used as flag mask 0x602000) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00513482 | EngineSoundWaveTableGenerator | generate PCM wave tables for engine sound synthesis |

**Guard conditions (deterministic — field vs literal):**

| Condition | Value | Meaning |
|-----------|-------|---------|
| (0x602000 & this+0x60 flags) | != 0 | pass 1 enabled — generate wave tables and lookup remap |
| this+0x116 | == 3 | format indicator — required for both passes |
| (this+0x60 byte 3) & 8 | != 0 | pass 2 enabled — per-channel bit-shift reduction |

**Guard interpretation:** PASS 1: when (0x602000 & flags) != 0 → call wave table generator, then if format==3 do lookup remap. PASS 2: when (flags byte & 8) != 0 && format==3 → per-channel right-shift. BLOCKED when flags mask fails (pass 1 skipped) or format != 3 (both passes skip).
