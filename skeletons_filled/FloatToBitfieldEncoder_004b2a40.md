## FloatToBitfieldEncoder_004b2a40 — Bitfield 7-bit biased insert (bits 0-6)

**Summary:** Multiplies float by 63.0, subtracts 64 bias, and inserts 7-bit signed value into low 7 bits (0-6) of bitfield at offset 0x2C. Packs signed color/audio channel data as biased offset.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SetupCarLightingAndRender (004c71c0), AudioSampleCrossFadeInterpolation (004ff8f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | RW | — | Bitfield dword (bits 0-6 hold 7-bit biased signed value, * 63) |

**Written-by note (persistence):**
- this 0x2C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005accd8 | flt_5ACCD8 | R | DXT_GreenChannelScale [DERIVED] (also: ` — G channel scale factor (different precision) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No explicit guard — float converted to int and biased by 64 for signed encoding.
