## ValueClampRange_004ff040 — AudioParamRangeClamp

**Summary:** Computes a clamped range [low, high] from two audio parameter inputs. Low = 1-a2 clamped to [0,1], high = 1-a3 forced >= low and clamped to <= 1.0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_402690 (00402690), sub_4FCAA0 (004fcaa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xFC | RW | — | Range low bound (1 - a2, clamped [0,1]) |
| this | 0x100 | RW | — | Range high bound (1 - a3, forced >= low, clamped <= 1) |

**Written-by note (persistence):**
- this 0xFC: Written once per call to clamped low bound
- this 0x100: Written once per call to clamped high bound

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** this[63] (low = 1-a2): if < 0.0 → clamped to 0.0; if > 1.0 → clamped to 1.0. this[64] (high = 1-a3): if < this[63] → forced equal to this[63]; if > 1.0 → clamped to 1.0. No bottom clamp on this[64] below this[63].
