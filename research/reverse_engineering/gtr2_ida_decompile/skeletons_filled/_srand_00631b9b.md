## _srand_00631b9b — CRT srand

**Summary:** ANSI CRT `srand`: stores the given seed into the per-thread rand state (ptd + 20), resetting the sequence that `rand` will return. No return value.

**Called by:** sub_5E8910 (005e8910), sub_618460 (00618460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00636698 | __getptd | Returns the per-thread data block; the seed is written at offset +20 (the RNG state slot) |

**Guard conditions:** None — no branches. The seed is written unconditionally to the per-thread RNG state slot; no validation of Seed value in this function.
