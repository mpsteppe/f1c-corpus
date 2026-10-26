## TextInputRender_0048b9c0 — TextInputFieldRender

**Summary:** Renders text input field with password masking and scroll. Copies edit buffer (optionally masking chars as '*'), appends cursor glyph when visible, measures text width, scrolls if text overflows available space, and draws via BitmapDraw_81f0. Calls vtable[11] update after render.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xC8) | 0x40 | R | — | Font path string pointer from sub-object |
| obj | 0x18 | R | — | unknown (from ConditionalDelegation_6460 result) |
| obj | 0x1C | R | — | unknown (from ConditionalDelegation_6460 result) |
| obj | 0x20 | R | — | Child object pointer from layout results (v10[8]) |
| obj | 0x24 | R | — | unknown (from ConditionalDelegation_6460 result) |
| obj | 0x2C | R | — | unknown (from ConditionalDelegation_6460 result) |
| this | 0x0 | R | — | VTable pointer |
| this | 0x4 | R | — | Width/position parameter passed to F_10ParamForwarder |
| this | 0xC | R | — | Height/position parameter passed to F_10ParamForwarder |
| this | 0xC8 | R | — | Pointer to sub-object with font settings |
| this | 0xE0 | R | — | Widget visibility flag — if 0, text not rendered |
| this | 0xE1 | R | — | Cursor visibility flag — if 1, cursor glyph appended |
| this | 0xE2 | R | — | Password mask flag — if 1, chars rendered as '*' |
| this | 0x2F0 | R | — | Text buffer pointer (source string to render) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005cc214 | word_5CC214 | R | Cursor glyph character (appended to end of visible text) |
| 005cc218 | unk_5CC218 | R | Reference string for text measurement initialization |
| 005ea438 | byte_5EA438 | R | Fallback font directory path when sub-object string is null |
| 007cde00 | unk_7CDE00 | R | Global context passed to F_10ParamForwarder positioning |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486460 | ConditionalDelegation_6460 | Gets layout/positioning object for render area |
| 00494a30 | F_10ParamForwarder | Sets up rendering area with position and dimensions |
| 00495150 | GlobalAccessor_5150 | Retrieves global render context from unk_7CDE00 |
| 004981f0 | BitmapDraw_81f0 | Draws the text bitmap onto the surface |
| 004983b0 | TextRenderToSurface | Measures text width for overflow/scroll calculation |
| 00498560 | sub_498560 | Sets font path on render surface |
| 00587dd0 | sub_587DD0 | Copies string from buffer to local buffer with length limit |

**Guard conditions:** If sub-object at this+0xC8 is null → BLOCKED: font setup skipped. If ConditionalDelegation_6460 returns null → BLOCKED: layout setup skipped. If this+0xE2 (password flag) is 1 → PASSES: chars replaced with '*'. If this+0xE0 (visibility) AND this+0xE1 (cursor) both 1 → PASSES: cursor glyph appended. Text scroll loop: while rendered width exceeds available vtable[8]-vtable[6] width, start pointer advances until text fits (max 255 iterations). If strlen(start) == 0 after scrolling → BLOCKED: BitmapDraw_81f0 skipped.
