## RunningAverageFilter_004c2c40 — RunningAverageFilter

**Summary:** Computes an incremental running average of input values. Uses sample count at this+0x28 to weight the running average at this+0x44 via formula: new_avg = ((n-1)*old_avg + new_val)/n. Clamps result to [1.0, 22.0] range. First sample initializes the average directly.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4C29F0 (004c29f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x28 | R | — | sample count, used as weighting denominator |
| this | 0x44 | RW | 1102053376 → 22.0f | running average value, updated each call and clamped to [1.0, 22.0] |

**Written-by note (persistence):**
- this 0x44: set conditionally each call (average or clamp) — external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] |
| 0059e85c | flt_59E85C | R | RunningAverageMaxClamp [DERIVED] — max threshold (22.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Sample count at this+0x28 must be > 0 to compute. If 0, no-op. If 1, average = input directly. For count > 1, weighted average is computed then clamped to [1.0, 22.0].
