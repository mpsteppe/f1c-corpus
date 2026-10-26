## PositionOrderNameDisplay_004db6f0 — PositionGearTextRenderer

**Summary:** Renders position or gear indicator text at screen coordinates. Shows localized "Error" for -1, "N" for 0, or numeric value for positive numbers. Colors change to red when driver appearance flags indicate failure state. Part of HUD system.

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
| 005c36fc | aN | R | StringN [DERIVED] — localized "N" string (neutral/neutral gear) |
| 005ccec4 | byte_5CCEC4 | R | aError_CEC4 [DERIVED] — localized "Error" string |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] — checked for bitmask 0xF to determine red text |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | Looks up localized string in string table |
| 0049b7a0 | sub_49B7A0 | Processes DriverAppearanceFlag, returns flags for color decision |
| 004d7e40 | UITextRenderWithScale | Renders text at screen coordinates with color/alignment/scale |
| 00587dd0 | sub_587DD0 | Safe string copy with max length (9 bytes) |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe string formatting (%d) for numeric position value |

**Guard conditions:**
- Line 12: `a1 == -1` (error/invalid position). PASS: show localized "Error" string. BLOCK: check a1 == 0.
- Line 29: `a1 == 0` (neutral/no gear). PASS: show localized "N" string. BLOCK: format as numeric "%d".
- Line 45: `(sub_49B7A0(&unk_7CE234) & 0xF) == 0xF` (all four driver appearance flag bits set). PASS: use red color (16711680). BLOCK: use yellow color (16776960).
