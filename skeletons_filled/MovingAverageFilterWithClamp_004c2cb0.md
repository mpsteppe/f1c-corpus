## MovingAverageFilterWithClamp_004c2cb0 — MovingAverageWithClamp

**Summary:** Computes an incremental moving average of input values, storing result at this+0x48. Uses sample count at this+0x28 for weighting. Similar to RunningAverageFilter but writes to a different field (0x48 vs 0x44). Clamps result to [1.0, 22.0] range.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonScoringInfoUpdater (004c2a80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x28 | R | — | sample count, used as weighting denominator |
| this | 0x48 | RW | 1102053376 → 22.0f | moving average value, updated and clamped to [1.0, 22.0] |

**Written-by note (persistence):**
- this 0x48: set each call (average or clamp) — external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] |
| 0059e85c | flt_59E85C | R | RunningAverageMaxClamp [DERIVED] — max threshold (22.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No early-return guard. If count at this+0x28 is 0, stores input directly then falls through to division-based update (assuming count >= 1). If count is 1, reuses old average as base. For count > 1, computes weighted average. Final result clamped to [1.0, 22.0].
