## UtilityFunction_b9a0_004db9a0 — SpeedValueRenderer

**Summary:** Converts float speed value to integer, formats as decimal string ("%d"), and renders at screen coordinates in yellow (16776960) with center alignment. Part of HUD speed display.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UILayoutDispatchWithDataPrep (004db550)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7e40 | UITextRenderWithScale | Renders speed text at screen coordinates in yellow |
| 00587bdc | CRTFtol | Converts float speed to integer (floor truncation) |
| 0058815f | StringFormatWithBufferOverflowCheck | Formats integer speed as "%d" string |

**Guard conditions:** None — single unconditional render sequence.
