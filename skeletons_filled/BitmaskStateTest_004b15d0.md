## BitmaskStateTest_004b15d0 — Bitmask state test

**Summary:** Tests whether a given bit index is set in a bitmask field, with an early-exit guard based on a state field value. Returns true if state field is not 5, or if the specific bit is set in the bitmask.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIShiftPattern (0042b8d0), BrakeBiasSetup (00438cc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1F78 | R | — | State field guard (early return true when != 5) |
| this | 0x2AB4 | R | — | Bitmask field (bits tested when state == 5) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1F78 | != | 5 | State field guard |

**Guard interpretation:** When this+0x1F78 != 5, PASSES — returns true immediately without bitmask check. When == 5, BLOCKED from immediate true — must check if bit (1 << a2) is set in this+0x2AB4 bitmask to return true.
