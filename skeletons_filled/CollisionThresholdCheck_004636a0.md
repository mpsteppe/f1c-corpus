## CollisionThresholdCheck_004636a0 — Collision Threshold Comparison by State

**Summary:** Reads float value at +0x388 from this object, compares against threshold (20.0 or 1.25 depending on StateCheckWrapper result). Returns true if float exceeds threshold, false otherwise.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_f070 (0049f070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x388 | R | — | float value compared against threshold |
| this | 0x0 | R | — | vtable/primary pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e8ec | flt_59E8EC | R | SpeedDeadzone [DERIVED] |
| 0059f124 | flt_59F124 | R | UILayoutOffset [DERIVED] (also: ` � layout constants) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461dc0 | StateCheckWrapper | checks object state; determines which threshold to use |

**Guard conditions:** No early return. If StateCheckWrapper returns true (state active), threshold is 20.0; else threshold is 1.25. Returns true when float at +0x388 > threshold, false when <= threshold.
