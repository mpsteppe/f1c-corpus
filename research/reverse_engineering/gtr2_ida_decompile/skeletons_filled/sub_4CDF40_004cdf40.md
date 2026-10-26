## sub_4CDF40_004cdf40 — AdvanceProgressCounter

**Summary:** When state 0x84 == 1 and the enable byte 0x118 is set, advances the progress counter 0x10C by (limit - step) * rate / 100 (i.e. one percent-step forward), then clamps via sub_4CDE30 and fires the virtual notification at vtable+0xA8. Returns 0.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | Virtual method (vtable+4) supplying the lower bound/step subtracted from the limit |
| obj | 0xC | R | — | Virtual method (vtable+0xC) supplying the upper bound/limit |
| obj | 0xA8 | R | — | Virtual method (vtable+0xA8) invoked after the counter update (notification/refresh) |
| this | 0x0 | R | — | Vtable pointer used to reach all virtual methods |
| this | 0x84 | R | — | State word (this[33]); only the value 1 permits the update |
| this | 0x10C | RW | — | Progress counter (this[67]) increased by (limit - step) * rate / 100 |
| this | 0x118 | R | — | Enable byte (this+280) gating the update; must be nonzero |
| this | 0x11C | R | — | Rate/percent factor (this[71]) scaled into the increment |

**Written-by note (persistence):**
- this 0x10C: Conditional — updated with += only when this[0x84]==1 and this[0x118]!=0; no write otherwise, so an external poke survives until the next qualifying call, after which the delta is added on top

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cde30 | sub_4CDE30 | Clamps/refresh the counter at 0x10C against the step and limit virtuals (see its entry) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x84 | == | 1 | State word must equal 1 to allow the advance |

**Guard interpretation:** PASS requires both conditions: this[0x84] == 1 AND this[0x118] != 0 → the counter is advanced, clamped and the vtable+0xA8 notify runs. If either fails → BLOCKED: no side effects, returns 0 immediately. The second operand (0x118 byte) is the finer gate; the equality on 0x84 selects the "running" state.
