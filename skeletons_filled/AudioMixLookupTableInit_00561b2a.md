## AudioMixLookupTableInit_00561b2a — LookupTableInitAll

**Summary:** Initialize four lookup tables used by audio mixing / pixel processing. Fills MultiplyLUT (256x32, 8-bit), MulLookupTable (256x64, 8-bit), SoundMixClipTable (32x32, clipped sum), and AlphaBlendSumTable (64x64, clipped sum).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x53 | R | — | Argument field (byte) used in initial computation |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005dd8cc | byte_5DD8CC | W | SoundMixClipTable [DERIVED] |
| 005ddccc | byte_5DDCCC | W | AlphaBlendSumTable [DERIVED] |
| 005deccc | byte_5DECCC | W | MultiplyLUT_8x32 [DERIVED] |
| 005e0ccc | byte_5E0CCC | W | MulLookupTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None
