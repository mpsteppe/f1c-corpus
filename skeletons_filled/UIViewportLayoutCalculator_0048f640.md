## UIViewportLayoutCalculator_0048f640 — TileGridLayoutCalculator

**Summary:** Computes tile grid layout dimensions for a viewport: reads available width/height, iterates child linked list to find max tile dimensions, calculates row and column counts based on layout mode (0=vertical, 1=horizontal), and handles overflow by invoking state reset virtual method. Calls UITileGrid to update tile positions.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ObjectNameComparison (00477280), GameFilterSetup (00477830), ProfileBitmapBrowser (00477cb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xF0) | 0xC | R | — | child node width |
| *(this+0xF0) | 0x10 | R | — | child node height |
| obj | 0x2C | R | — | virtual method offset for state reset |
| obj | 0x40 | R | — | virtual method offset for reset with arg |
| this | 0x0 | R | — | vtable pointer |
| this | 0xF0 | R | — | linked list head pointer |
| this | 0xF8 | RW | — | linked list iteration cursor |
| this | 0xFC | R | — | total element count |
| this | 0x100 | R | — | layout mode (0=vertical, 1=horizontal) |
| this | 0x104 | RW | 0 | state flag, reset to 0 on overflow |
| this | 0x120 | R | — | viewport available width |
| this | 0x124 | R | — | viewport available height |
| this | 0x140 | R | — | horizontal spacing / padding |
| this | 0x144 | R | — | vertical spacing / padding |
| this | 0x150 | R | — | tile width per element |
| this | 0x154 | R | — | tile height per element |
| this | 0x158 | RW | 0 | computed columns count |
| this | 0x15C | RW | 0 | computed rows count |
| this | 0x160 | RW | 0 | computed visible columns |
| this | 0x164 | RW | 0 | computed visible rows |
| this | 0x16C | RW | 0 | computed total / scroll offset |

**Written-by note (persistence):**
- this 0xF8: updated during iteration; survives until next traversal
- this 0x104: set to 0 on overflow; survives until next reset or set
- this 0x158: computed column count; survives until next layout
- this 0x15C: computed row count; survives until next layout
- this 0x160: computed visible columns; survives until next layout
- this 0x164: computed visible rows; survives until next layout
- this 0x16C: computed total / scroll offset; survives until next layout

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048f870 | UITileGrid | update tile positions in grid layout |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x16C | < | 0 | computed total / scroll offset |

**Guard interpretation:**
- Tile dimensions: iterates linked list to find max tile width (stored at 0x158) and height (at 0x15C)
- Layout mode at offset 0x100: 0 = vertical fill, 1 = horizontal fill
- Overflow check: if (columns * (tileW + spacingX) > availableW) OR (rows * (tileH + spacingY) > availableH) → reset state flag at 0x104 and call virtual method at vtable+64 with arg 0
- Scroll offset at 0x16C: if < 0 → clamp to 0 (PASS: clamp; BLOCKED state: already handled by computation)
- Always calls UITileGrid then virtual method at vtable+44 with arg 1
