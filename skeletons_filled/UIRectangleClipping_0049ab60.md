## UIRectangleClipping_0049ab60 — RectangleClipAndDispatch

**Summary:** Clips an input rectangle against widget scroll/child bounds then delegates to ShortComputation_16e0. If widget has zero or negative dimensions, skips clipping entirely.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | 16-bit X origin |
| this | 0x26 | R | — | 16-bit Y origin |
| this | 0x28 | R | — | 16-bit height |
| this | 0x2A | R | — | 16-bit width |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004916e0 | ShortComputation_16e0 | Performs final short-integer rectangle computation after optional clipping |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x28 | <= | 0 | 16-bit height |
| this | 0x2A | <= | 0 | 16-bit width |

**Guard interpretation:** If height <= 0 OR width <= 0, clipping is BLOCKED — calls ShortComputation_16e0 with original unclipped input bounds. If both > 0, PASSES to clipping path: clips left/top/right/bottom against widget bounds then calls ShortComputation_16e0.
