## ColorAlphaUpdateFlagSet_004e21d0 — ColorAlphaUpdateFlagSet

**Summary:** Computes ARGB color value from alpha parameter (a2 * 254), writes it to all packed array elements' color field (offset 24), and sets dirty flag bit 0x10000000 at offset 0x14. Part of color/visibility update system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleStateUpdate_19d0 (004e19d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | — | Flag word — bit 0x10000000 set to mark color alpha updated |

**Written-by note (persistence):**
- this 0x14: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005acec4 | flt_5ACEC4 | R | Flt_TrackSegmentFade_SCEC4 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054e100 | PackedArrayTotalSize | Returns element count of packed color data array |
| 0054e120 | PackedArrayIndexLookup | Returns pointer to element by index (to write color) |
| 00587bdc | CRTFtol | Float-to-integer truncation for alpha value quantization |

**Guard conditions:** None — always writes alpha color to all packed array entries and sets flag.
