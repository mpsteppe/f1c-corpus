## WarningHandler_004bbc60 — WarningMessageDisplay

**Summary:** Formats and displays a "Warning <message>" text to the HUD using string table lookup and text rendering, guarded by penalty state flags.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4BCCC0 (004bccc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | penalty state flag (checked == 0) |
| this | 0x0 | R | — | pointer to penalty state object |
| this | 0x30 | R | — | warning pending flag (checked != 0 blocks) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5d30 | aSS_2 | R | Str_DriverSettingsSuffix [DERIVED] |
| 005d2568 | aWarning | R | WarningString [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | look up string in message table |
| 0045bd10 | TextLineWrappingAndRendering | render message text to HUD |
| 00587dd0 | sub_587DD0 | string copy with length limit |
| 0058815f | StringFormatWithBufferOverflowCheck | format warning message string |

**Guard conditions:** BLOCKED when this[12] (offset 0x30) is non-zero (message already shown). BLOCKED when a2 is NULL. BLOCKED when obj+0x32C8 is non-zero (state not ready).
