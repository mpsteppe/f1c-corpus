## UIEventShortcutHandler_0048b600 — TextFieldEditHandler

**Summary:** Handles keyboard input for text edit field. Processes virtual key codes: inserts filtered chars at cursor, handles backspace (v7==14) and enter (v7==28), truncates text if exceeds render width. Calls vtable render/update via StringReverseCopyLookup after each modification.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x2F4) | 0x0 | RW | 0 | Byte at cursor position in edit buffer |
| *(this+0x2F4) | 0x1 | RW | 0 | Next byte after cursor (terminator overwrite) |
| *(this+0xC8) | 0x40 | R | — | String pointer from sub-object for font/text measurement |
| obj | 0x2C | R | — | unknown |
| obj | 0xB0 | R | — | unknown |
| this | 0x0 | R | — | VTable pointer |
| this | 0x40 | R | — | Render surface / string buffer pointer for text rendering |
| this | 0xA0 | R | — | String pointer for path lookup fallback |
| this | 0xC8 | R | — | Pointer to sub-object containing font/text properties |
| this | 0xE5 | R | — | Enable flag for enter-key action |
| this | 0x2EC | R | — | Master enable/disable flag for edit handler |
| this | 0x2F0 | R | — | Buffer start pointer (cursor anchor) |
| this | 0x2F4 | RW | — | Cursor position pointer (current insertion point) |
| this | 0x2F8 | R | — | Buffer end limit pointer (max chars) |
| this | 0x2FC | R | — | Text render target surface pointer |

**Written-by note (persistence):**
- *(this+0x2F4) 0x0: once per char insertion — written with filtered char. Survives as part of edit buffer.
- *(this+0x2F4) 0x1: once per char insertion — written with null terminator. Buffer state.
- this 0x2F4: cursor position advanced after each insertion. Buffer state.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Fallback application directory path when sub-object string is null |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00455b30 | TranslateVirtualKey | Converts virtual key code to ASCII character |
| 0048b560 | sub_48B560 | InputCharFilterByFieldType — validates if char is allowed in current field mode |
| 0048b910 | SetterVTableIDCheck | Sets vtable/type ID for enter-key confirmation action |
| 004983b0 | TextRenderToSurface | Measures rendered text width on surface for overflow truncation |
| 00498560 | sub_498560 | unknown — sets font/path on render surface |
| 0049a490 | StringReverseCopyLookup | Copies edit buffer to display surface with path lookup |

**Guard conditions:**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x2EC | == | 0 | Master enable flag (byte at +748) |
| this | 0xE5 | == | 0 | Enter-action flag (byte at +229) — checked on v7==28 |

**Guard interpretation:** If this+0x2EC == 0 → early return 0 (all input BLOCKED). Otherwise, processes each vkey in `a2[]`: v7==14 (backspace) always PASSES (deletes char). v7==28 (enter) PASSES only if this+0xE5 != 0, else calls SetterVTableIDCheck(0) then vtable[44]. Normal chars PASS through TranslateVirtualKey + sub_48B560 filter; if sub_48B560 returns 0, char is BLOCKED (not inserted). Additional guard: insertion only happens if cursor position < buffer end limit - 1. Post-insertion width check: if v18 > v19 (text too wide), last char is removed.
