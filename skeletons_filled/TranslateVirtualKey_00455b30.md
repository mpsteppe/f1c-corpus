## TranslateVirtualKey_00455b30 — VirtualKeyToCharTranslate

**Summary:** Translates a Windows virtual-key code to a character using ToAsciiEx/MapVirtualKeyExA. Initializes keyboard layout on first call, maps a special key (32825→57), returns translated result via sub_455580.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIEventShortcutHandler (0048b600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e2b4 | ToAsciiEx | R | ToAsciiEx API pointer |
| 0059e2b8 | MapVirtualKeyExA | R | MapVirtualKeyExA API pointer |
| 0059e2bc | GetKeyboardState | R | GetKeyboardState API pointer |
| 0059e2c0 | GetKeyboardLayout | R | GetKeyboardLayout API pointer |
| 007ca508 | dwhkl | RW | cached keyboard layout handle (initialized once) |
| 007ccab0 | KeyState | R | 256-byte keyboard state buffer for GetKeyboardState |
| 007ccbc0 | word_7CCBC0 | W | output character word buffer |
| 007ccc04 | byte_7CCC04 | RW | layout init flag (bit 0) |
| 007ccfc0 | Char | RW | Unicode character buffer for ToAsciiEx output |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00455580 | sub_455580 | post-processes translated character result |

**Guard conditions:** if GetKeyboardState fails (returns 0), function returns 0 immediately.
