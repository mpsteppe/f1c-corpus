## SuspensionRatioClamp_004e8780 — suspension compression ratio clamp

**Summary:** Computes negated ratio of two suspension travel values and clamps to [0,1]. Yields normalized compression ratio for suspension dynamics.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISteeringCorrection (00426cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x39A8 | R | — | suspension current travel or displacement numerator |
| this | 0x39AC | R | — | suspension max travel or reference denominator |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** this[3691] (0x39AC) == 0.0 → BLOCKED (returns 0 to avoid division by zero). PASSES: denominator non-zero, compute ratio and clamp to [0,1].
