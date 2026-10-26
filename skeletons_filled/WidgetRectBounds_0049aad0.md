## WidgetRectBounds_0049aad0 — WidgetBoundsCalculator

**Summary:** Computes output bounding rectangle for a widget. If widget dimensions are zero/negative, outputs raw dword rect stored at 0x4-0x10; otherwise computes pixel-accurate bounds from 16-bit position and size fields.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Raw dword left edge |
| this | 0x8 | R | — | Raw dword top edge |
| this | 0xC | R | — | Raw dword right edge |
| this | 0x10 | R | — | Raw dword bottom edge |
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

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x28 | <= | 0 | 16-bit height |
| this | 0x2A | <= | 0 | 16-bit width |

**Guard interpretation:** If height <= 0 OR width <= 0, PASSES to raw-dword rect path (outputs fields 0x4-0x10 directly). BLOCKED from using 16-bit computed path — uses fallback raw rect instead.
