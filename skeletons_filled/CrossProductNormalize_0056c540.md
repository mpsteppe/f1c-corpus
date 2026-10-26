## CrossProductNormalize_0056c540 — CrossProductNormalized

**Summary:** Computes cross product a1 × a2, stores in a3, then scales by dot(a1,a2)/|cross| factor (cosine of angle over sine). Skips normalization if cross product is zero. Used for constraint axis vector computation.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_56A5D0 (0056a5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | input vector 1 x component |
| this | 0x8 | R | — | input vector 1 y component |
| this | 0x10 | R | — | input vector 1 z component |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005894a0 | FloatFunctionPassThrough | floating-point value passthrough / type conversion |

**Guard conditions:** If cross product vector is all zeros (|cross| == 0): skip normalization, leave result zero. If non-zero: compute dot product, clamp to 1.0, normalize by dot/|cross| factor.
