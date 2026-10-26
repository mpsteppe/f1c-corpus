## ZeroVectorCheck_00404030 — Non-zero vector check

**Summary:** Tests whether two vectors (one 2-component XY, one 3-component XYZ) contain any non-zero element. Returns TRUE if any of the 5 tested float components is non-zero, indicating the compound data structure is not zero-initialized.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4C6F10 (004c6f10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | first vector X component |
| this | 0x8 | R | — | first vector Z component (Y at 0x4 is not checked) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:** none

**Guard conditions:** No early-return guards. Pure boolean expression: returns TRUE if any of the checked components (a1[0], a1[2], a2[0], a2[1], a2[2]) != 0.0; returns FALSE only if all 5 are exactly 0.0.
