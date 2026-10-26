## ImageBufferStrideFill_0051e2ba — ImageBufferStrideFill

**Summary:** Fills image buffer with stride-based per-channel gradient values. Calls CombinatorialPermutationGenerator to determine layout, allocates output buffer, fills each channel with division-interpolated byte values across the stride.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ObjectSetupWithBoundsCheck (0051eb6e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | object vtable pointer |
| obj | 0x14 | RW | 94 | status code for non-3-channel mode |
| obj | 0x18 | RW | — | total permutation count |
| obj | 0x1C | RW | — | channel 0 stride value (mode 3 only) |
| obj | 0x20 | RW | — | channel 1 stride value (mode 3 only) |
| obj | 0x24 | RW | — | channel 2 stride value (mode 3 only) |
| this | 0x0 | R | — | object vtable pointer |
| this | 0x4 | R | — | allocator pointer |
| this | 0xC | R | — | object field |
| this | 0x64 | R | — | channel count |
| this | 0x1A4 | R | — | context pointer |
| this | 0x1B4 | RW | — | output buffer pointer (written to context) |
| this | 0x1B8 | RW | — | step-size field (written to context) |
| this | 0x1C4 | R | — | channel array pointer |
| this | 0x1C8 | R | — | context field |
| this | 0x1CC | R | — | context field |

**Written-by note (persistence):**
- obj 0x14: set to 94 for non-3-channel; 93 for 3-channel
- obj 0x18: set to total count; survives until overwritten
- obj 0x1C: set for 3-channel mode only
- obj 0x20: set for 3-channel mode only
- obj 0x24: set for 3-channel mode only
- this 0x1B4: set to output buffer pointer; survives until freed
- this 0x1B8: set to total permutation count; survives until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051e1ef | CombinatorialPermutationGenerator | generates permutation array for channel index layout |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x64 | == | 3 | channel count = 3 (store per-channel stride to obj fields) |
| this | 0x64 | > | 0 | channel count > 0 (proceed with buffer fill) |
| this | 0x1C4 | > | 0 | stride per channel > 0 (inner fill loop) |

**Guard interpretation:** When this+0x64 == 3, store individual channel strides to obj fields 0x1C-0x24 with status 93. When this+0x64 != 3, store total count only to obj+0x18 with status 94. When this+0x64 <= 0, skip fill entirely. When this+0x1C4 > 0, execute inner per-pixel fill loop. PASSES: valid channel count and stride enable buffer fill. BLOCKED: zero stride skips inner loop.
