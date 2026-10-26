## WeightedSumComparatorWithBinaryAdjustment_0042e4a0 — WeightedBalanceAdjuster

**Summary:** Adjusts index values in two struct objects to satisfy weighted sum inequality. While a2's weighted sum exceeds a1's by 0.01% tolerance, decrements a2's index (if flag set and index > 0) or increments a1's index (if within bounds).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TrackConfig (0042e530)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | baseValue (double) |
| this | 0x8 | R | — | coefficient (double) |
| this | 0x10 | R | — | maxIndex |
| this | 0x14 | RW | — | currentIndex |

**Written-by note (persistence):**
- this 0x14: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e9f0 | dbl_59E9F0 | R | IntersectionMultiplier [DERIVED] (also: ` — tolerance/multiplier for comparison) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Decrement path: requires a3 (flag) set AND v3 (a2's currentIndex) > 0. Increment path: requires i (a1's currentIndex) < a1's maxIndex - 1, else return (no further adjustment possible).
