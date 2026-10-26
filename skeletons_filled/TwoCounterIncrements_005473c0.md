## TwoCounterIncrements_005473c0 — Two-counter increment

**Summary:** Increments two adjacent counters at offsets 0x84 and 0x88 by 1 each.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TreeNodeAccumulator (00544c50), sub_557670 (00557670), sub_557CE0 (00557ce0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x84 | R | — | First counter, incremented unconditionally |
| this | 0x88 | R | — | Second counter, incremented unconditionally |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always increments both counters.
