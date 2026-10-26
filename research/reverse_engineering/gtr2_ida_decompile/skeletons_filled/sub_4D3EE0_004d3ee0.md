## sub_4D3EE0_004d3ee0 — StepProgressUp

**Summary:** Adds the step value at 0x244 to the counter at 0x22C, clamps the result to the ceiling at 0x240, runs sub_4D0B20(this), and recomputes the progress value 0x230 as round(0x22C / 0x240 × 0x234) — or 0 when 0x240 is zero; always returns 0.

**Called by:** sub_4D4540 (004d4540)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x22C | RW | — | counter: increased by the 0x244 step, then clamped down to the 0x240 ceiling |
| this | 0x230 | RW | 0 | computed progress value: 0 when 0x240 is 0, else rounded 0x22C/0x240 × 0x234 |
| this | 0x234 | R | — | multiplier applied to the 0x22C/0x240 ratio |
| this | 0x240 | R | — | divisor and upper clamp for the 0x22C counter; zero → 0x230 forced to 0 |
| this | 0x244 | R | — | step amount added to the 0x22C counter |

**Written-by note (persistence):**
- this 0x22C: rewritten on every call (increment + clamp to the 0x240 ceiling); an external poke is overwritten by the next call.
- this 0x230: recalculated on every call (or zeroed when the divisor is 0); poke survives only until the next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16c8 | flt_6F16C8 | R | float constant involved in the 0x230 progress computation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d0b20 | sub_4D0B20 | update step run on this before the progress value is recomputed |
| 0063099c | __ftol2 | compiler runtime helper converting the rounded double result to int for storage at 0x230 |

**Guard conditions:** Clamp: v2 = 0x244 + 0x22C; if 0x240 < v2 then v2 = 0x240; that value is stored to 0x22C. Then if this+0x240 == 0 → 0x230 stays 0 (division skipped); non-zero → 0x230 = ftol(0x22C/0x240 × 0x234 + 0.5). No early returns; always returns 0.
