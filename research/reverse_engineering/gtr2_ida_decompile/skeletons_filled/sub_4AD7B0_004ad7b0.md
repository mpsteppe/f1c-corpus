## sub_4AD7B0_004ad7b0 — Timed threshold accumulator with virtual callback

**Summary:** Accumulates the value returned by sub_4DE460 for the handle at this+0x30 into a float accumulator at this+0x254; when the accumulated value exceeds 2.0 it resets the accumulator, advances a counter at this+0x258 by 2 (wrapping at dword_B7628C) and invokes the object's virtual method at vtable slot 0x98. Periodic timing/update helper.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x98 | R | — | Vtable slot 0x98 (152) resolved via the object's vtable; the virtual callback invoked when the threshold trips |
| this | 0x0 | R | — | Object vtable pointer, read to fetch the slot-0x98 method for the callback call |
| this | 0x30 | R | — | Dword argument passed to sub_4DE460 (context/parameter whose return feeds the accumulator) |
| this | 0x254 | RW | — | Float accumulator (this[149]); receives the sub_4DE460 return, reset to 0.0 when it exceeds 2.0 |
| this | 0x258 | RW | — | Step counter (this[150]); incremented by 2 per threshold trip, wrapped to 0.0 when it reaches dword_B7628C |

**Written-by note (persistence):**
- this 0x254: updated on every call (existing value + sub_4DE460 return); reset to 0.0 whenever the sum exceeds 2.0 — an external poke just becomes the new starting point for the accumulation.
- this 0x258: written only on threshold trips (increment by 2, or wrap to 0.0 at the dword_B7628C limit); untouched on ordinary calls, so a poke survives until the next 2.0 crossing.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f3154 | flt_6F3154 | R | Float threshold participating in the accumulator comparison (decompile shows the 2.0 test) |
| 00b7628c | dword_B7628C | R | Wrap limit for the step counter; when the incremented counter >= this value it is reset to 0.0 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004de460 | sub_4DE460 | Produces the increment added to the accumulator for the handle at this+0x30 (returns a double consumed by the accumulation) |

**Guard conditions:** v2 > 2.0 → the block runs: counter at 0x258 += 2, accumulator 0x254 = 0.0, and if the new counter >= dword_B7628C the counter wraps to 0.0; then the virtual slot-0x98 method is called on this. When v2 <= 2.0, only the updated accumulator is left stored and the function returns 0 with no callback.
