## sub_4CE8F0_004ce8f0 — VectorFieldNonZeroCheck

**Summary:** Returns TRUE if any of three float fields (at offsets 0x00, 0x14, 0x28) in the input struct are non-zero. Simple presence check for velocity/magnitude channels.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4EE2D0 (004ee2d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | first velocity/magnitude field |
| this | 0x14 | R | — | second velocity/magnitude field |
| this | 0x28 | R | — | third velocity/magnitude field |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — pure comparison, always returns result.
