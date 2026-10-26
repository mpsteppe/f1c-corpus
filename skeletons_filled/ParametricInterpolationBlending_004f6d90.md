## ParametricInterpolationBlending_004f6d90 — ParametricInterpolationBlending

**Summary:** Finds which range segment a parameter `a2` falls into, then computes sqrt-based blending weights between adjacent segments and invokes virtual callbacks with scaled values. Used for suspension force blending.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SuspensionForceComputationWithPerCornerVirtualDi (004f8440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Number of range segments in interpolation table |
| this | 0x4 | R | — | First segment minimum bound (range low) |
| this | 0x8 | R | — | First segment maximum bound (range high) |
| this | 0x40 | R | — | Pointer to array of per-segment callback object pointers |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | > | 0 | Range count check |

**Guard interpretation:** PASSES if range count > 0 (segments exist). BLOCKED entirely if count <= 0 (empty table, return immediately).
