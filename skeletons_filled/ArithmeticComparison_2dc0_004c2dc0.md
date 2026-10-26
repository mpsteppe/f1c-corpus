## ArithmeticComparison_2dc0_004c2dc0 — IncrementalRunningAverage

**Summary:** Computes an incremental running average of AI difficulty slider values. Maintains a counter at this+0x2C (incremented each call) and a running average at this+0x50 (init 120.0f). Uses standard incremental formula: new_avg = (old_count * old_avg + input) / (old_count + 1). Clamps result to [~60.0, 120.0] range.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4C29F0 (004c29f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | RW | 1 | sample counter, incremented each call and used as denominator |
| this | 0x50 | RW | 1123024896 → 120.0f | running average value, updated each call and clamped |

**Written-by note (persistence):**
- this 0x2C: incremented unconditionally each call — external poke survives
- this 0x50: set each call (average or clamp) — external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e968 | flt_59E968 | R | AIQualifyPushFrequency [DERIVED] |
| 005acb00 | flt_5ACB00 | R | Threshold_LowerBound_5ACB00 [DERIVED] — clamp floor constant |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No early-return guard. If counter wraps (v7 == -1), resets to 1 then proceeds. Result always clamped to [~60.0, 120.0].
