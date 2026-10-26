## FormatStringBatchDisplay_0049e170 — Batch format character display

**Summary:** Renders a 2-row batch of single-character values at fixed grid positions. Characters are read from indexed control/config mapping globals, formatted as "%c", and displayed via sub_553070.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49D5D0 (0049d5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | format context pointer (this[3]) |
| this | 0x14 | R | — | display context pointer (this[5]) |
| this | 0x68 | R | — | sub-struct pointer (steering input data) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ccef0 | aC | R | FormatString [DERIVED] ("%c" format) |
| 007ce6ac | dword_7CE6AC | R | character source — config/control slot 0 |
| 007ce6f4 | dword_7CE6F4 | R | BrakeDiffSettings [DERIVED] — character source slot 7 |
| 007ce718 | dword_7CE718 | R | FontRendererRef [DERIVED] — character source slot 2 |
| 007ce73c | dword_7CE73C | R | UnknownModuleInterface [DERIVED] — character source slot 8 |
| 007ce760 | dword_7CE760 | R | ControlMapping_Accel [DERIVED] — character source slot 4 |
| 007ce784 | dword_7CE784 | R | UITextDataReference [DERIVED] — character source slot 5 |
| 007ce7a8 | dword_7CE7A8 | R | BrakeDiffBlock [DERIVED] — character source slot 9 |
| 007ce7cc | dword_7CE7CC | R | ControlMapping_UI7 [DERIVED] — character source slot 1 |
| 007ce7f0 | dword_7CE7F0 | R | Unknown_Byte_7CE7F0 [DERIVED] — character source slot 3 |
| 007ce850 | dword_7CE850 | R | UI_RefStore_ed [DERIVED] — character source slot 10 |
| 007ce8a4 | dword_7CE8A4 | R | ConfigByte_PitSettings [DERIVED] — character source slot 6 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00553070 | sub_553070 | renders single character to HUD at position |
| 0058815f | StringFormatWithBufferOverflowCheck | formats character as "%c" string |

**Guard conditions:** Checks `this[3]` (0xC) non-null, `this[5]` (0x14) non-null, and `*(this[5]+84)` non-null — blocks entire batch if any null.
