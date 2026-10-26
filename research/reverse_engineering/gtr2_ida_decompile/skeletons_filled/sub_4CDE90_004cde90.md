## sub_4CDE90_004cde90 — GetCounterProgressRatio

**Summary:** Computes the counter at 0x10C as a fraction of the span between two virtual getters: (limit at vtable+0xC) minus (step/offset at vtable+4). Returns 0.0 when the span is non-positive, otherwise this[67] / span as a double.

**Called by:** sub_4A2550 (004a2550)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | Virtual method (vtable+4) supplying the lower offset subtracted from the upper bound |
| obj | 0xC | R | — | Virtual method (vtable+0xC) supplying the upper bound/limit |
| this | 0x0 | R | — | Vtable pointer used to reach both virtual getters |
| this | 0x10C | R | — | Counter/accumulator (this[67]) used as the numerator of the ratio |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00731ce8 | String2 | R | unknown — not visibly used in the provided code (likely adjacent data/name table entry picked up by extraction) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** span = (vtable+0xC getter) - (vtable+4 getter), converted to double. If span <= 0.0 → PASS returns 0.0 (division blocked). If span > 0.0 → returns (double)this[0x10C] / span (the progress fraction). No early exit; it is a single conditional return.
