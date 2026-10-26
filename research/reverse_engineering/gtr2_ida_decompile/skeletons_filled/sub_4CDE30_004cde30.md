## sub_4CDE30_004cde30 — ClampCounterAndQuery

**Summary:** Maintains the dword counter at 0x10C (this[67]): a negative value is reset to 0, otherwise the value plus a step from virtual (vtable+4) is clamped to a maximum from virtual (vtable+0xC) by storing max - step. Finishes by returning the result of the virtual query at vtable+0xA0.

**Called by:** sub_48BD20 (0048bd20), sub_4CDF40 (004cdf40), sub_4CDFB0 (004cdfb0), sub_4CED00 (004ced00), sub_4CEE20 (004cee20), sub_4CEED0 (004ceed0), sub_4CEF60 (004cef60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | Virtual method (vtable+4) supplying the step/increment value |
| obj | 0xC | R | — | Virtual method (vtable+0xC) supplying the maximum/limit value |
| obj | 0xA0 | R | — | Virtual method (vtable+0xA0) query whose result is returned |
| this | 0x0 | R | — | Vtable pointer used to reach all three virtual methods |
| this | 0x10C | RW | 0 | Counter/accumulator (this[67]) clamped against step and limit |

**Written-by note (persistence):**
- this 0x10C: Conditional — written only when the value is negative (set to 0) or when value + step overshoots the limit (set to limit - step); a nonnegative value within bounds is left untouched, so an external poke survives in that case

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10C | >= | 0 | Counter is nonnegative → take the add-and-clamp path; negative → reset path |

**Guard interpretation:** If this[0x10C] >= 0 → PASS into the normal path: v2 = counter + step(vtable+4); if v2 > limit(vtable+0xC) the counter is written as limit - step (clamped), else no write. If this[0x10C] < 0 → BLOCKED from that path: counter is simply set to 0. Either way the function returns the value of the virtual query at vtable+0xA0.
