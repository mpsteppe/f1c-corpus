## sub_4D2FE0_004d2fe0 — AccumulateTrackedOffset

**Summary:** If a tracked object pointer is present at 0x34, optionally pre-resets it (via sub_4E29F0, using its +0x84 field, when its +0xF4 flag is set) and then feeds the two arguments a2, a3 into the offset accumulator sub_4E2AF0; returns 0 when no tracked object exists.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34 | R | — | tracked object pointer; null → whole body skipped, returns 0 |
| this | 0xB8 | R | — | descriptor's +0x84 value (0x34+0x84), passed to sub_4E29F0 |
| this | 0x128 | R | — | descriptor's +0xF4 flag (0x34+0xF4); non-zero gates the sub_4E29F0 call |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e29f0 | sub_4E29F0 | reset/reinitialise helper invoked on the tracked descriptor's +0x84 value before accumulating |
| 004e2af0 | OffsetAccumulator [exact] | accumulates the two supplied values a2, a3 and returns the result |

**Guard conditions:** this+0x34 == 0 → BLOCKED: returns 0 without any call. this+0x34 != 0 → PASSES; inner guard *(descriptor+0xF4) != 0 → sub_4E29F0(descriptor+0x84) is called, == 0 skips it; sub_4E2AF0(a2, a3) always runs on this path and its result is returned.
