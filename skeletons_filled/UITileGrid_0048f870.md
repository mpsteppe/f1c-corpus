## UITileGrid_0048f870 — tile grid layout calculator

**Summary:** Computes screen positions for tiles in a grid-based UI layout. Iterates over row/column counts, walks a linked list of tile nodes to find valid tiles, calculates X/Y positions accounting for alignment (left/center/right), and calls sub_48EA20 to place each tile.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_48F1A0 (0048f1a0), UIViewportLayoutCalculator (0048f640), DecrementCounterWithClamp (0048faf0), sub_48FB30 (0048fb30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xF4) | 0x0 | R | — | unknown (indirect pointer accessed during linked list traversal) |
| *(this+0xF4) | 0x4 | R | — | unknown (indirect pointer accessed during linked list traversal) |
| obj | 0x2C | R | — | related UI object dimension for layout calculations |
| this | 0x0 | R | — | vtable pointer |
| this | 0xE0 | R | — | alignment mode: 1=center, 2=right, else left |
| this | 0xF0 | R | — | linked list head pointer for tile nodes (traversed via offset 4 to next) |
| this | 0xFC | R | — | max column count cap |
| this | 0x100 | R | — | alignment sub-type: 0=no offset, 1=use Y offset, else combination |
| this | 0x120 | R | — | grid start X position |
| this | 0x124 | R | — | grid end X boundary |
| this | 0x140 | R | — | grid start Y position |
| this | 0x150 | R | — | cell width |
| this | 0x154 | R | — | cell height |
| this | 0x158 | R | — | row count |
| this | 0x15C | R | — | column count per row |
| this | 0x160 | R | — | horizontal spacing between cells |
| this | 0x164 | R | — | vertical spacing between cells |
| this | 0x168 | R | — | alignment X/Y offset adjustment |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048ea20 | sub_48EA20 | places/repositions tile node at computed X,Y coordinates |
| 00498880 | DualFieldRead | reads two input/cursor fields used for grid interaction state |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xE0 | != | 2 | alignment is not right-justified → falls through to center/left path |
| this | 0xE0 | == | 1 | center alignment → adds half remaining space to X position |
| this | 0x158 | > | 0 | row count positive → enters main layout loop; if 0 or less, skips to finalize call |

**Guard interpretation:** Row count (0x158) must be > 0 to enter layout loop, otherwise returns via vtable method immediately. Alignment mode (0xE0): 1 = centered within remaining space, 2 = right-aligned, else left-aligned (no offset adjustment). Tile cell index validated against this[0xFC] (max columns) before accessing linked list.
