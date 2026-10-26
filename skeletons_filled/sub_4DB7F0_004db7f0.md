## sub_4DB7F0_004db7f0 — SymmetricalGhostCharacterRenderer

**Summary:** Renders a single character (from byte_5D4AE9) at 8 symmetrical positions around center X, with 4 color variants selected by bitmask in a1. Creates ghost/shadow HUD effect.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UILayoutDispatchWithDataPrep (004db550)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00444444 | loc_444444 | R | Base address for color table lookup (data interleaved at this address) |
| 005ccef0 | aC | R | FormatString [DERIVED] |
| 005d4ae9 | byte_5D4AE9 | R | FmtStr_5D4AE9 [DERIVED] — character to render (ghost symbol) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7e40 | UITextRenderWithScale | Renders character at screen coordinates (8 calls for symmetrical positions) |
| 0058815f | StringFormatWithBufferOverflowCheck | Formats single character from byte_5D4AE9 with "%c" |

**Guard conditions:**
- Line 10: `a1 & 1` bit set. PASS: apply offset 0xFFBCBABC to color pointer v3 (outer pair at ±163px). BLOCK: no offset.
- Line 11: `a1 & 2` bit set. PASS: apply offset 0xBBBABC to color pointer v7 (mid-outer pair at ±136px). BLOCK: no offset.
- Line 12: `a1 & 4` bit set. PASS: apply offset 0xBB87BC to color pointer v8 (mid-inner pair at ±109px). BLOCK: no offset.
- Line 13: `a1 & 8` bit set. PASS: apply offset 0xBABBBC to color pointer v9 (inner pair at ±82px). BLOCK: no offset.
- Renders 8 total: 4 pairs × 2 sides (left/right alignment per pair).
