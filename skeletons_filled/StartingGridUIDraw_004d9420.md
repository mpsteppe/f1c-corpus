## StartingGridUIDraw_004d9420 — Starting grid UI render

**Summary:** Renders the starting grid HUD. When participant count (this[5]) is non-zero, draws grid car positions in two columns via sub_4D95D0. When zero, renders "Starting Grid" title text and 4 position marker labels at computed Y positions.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | Grid participant count: non-zero → grid draw mode; zero → title/label mode |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acf64 | flt_5ACF64 | R | DisplayYSpacing [DERIVED] |
| 005ccef0 | aC | R | FormatString [DERIVED] |
| 005d4aef | byte_5D4AEF | R | Gear/position character displayed 4 times as labels |
| 005d4b00 | aGrid_0 | R | "Grid" string for title |
| 005d4b08 | aStarting | R | "Starting" string for title |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] — base buffer for string search |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] — working buffer for rendered text |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | Checks if string exists in buffer; used to init text on first call |
| 004d7e40 | UITextRenderWithScale | Renders UI text at position with color, scale, alpha |
| 004d95d0 | sub_4D95D0 | Draws grid car position at given screen coordinates |
| 00587bdc | CRTFtol | Float-to-int truncation for Y position arithmetic |
| 00587dd0 | sub_587DD0 | String wrapping/line-break formatting with max length 63 |
| 0058815f | StringFormatWithBufferOverflowCheck | Formats single character into buffer for position labels |

**Guard conditions:** `this[5]` (offset 0x14) == 0 → BLOCKED from grid draw path, enters title/label mode instead. `this[5]` != 0 → grid draw mode (2 columns via sub_4D95D0). `BinarySearchInStringTable` returning false triggers string copy init for "Starting"/"Grid" text. Position label loop runs exactly 4 iterations (i=0..3).
