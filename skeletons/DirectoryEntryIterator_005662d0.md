## DirectoryEntryIterator_005662d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceListCleanup (00404d50), Game_Enter (0042d370), sub_45C0C0 (0045c0c0), PlayerProfileScanner (00468ee0), ProfileBitmapBrowser (00477cb0), PlayerNameNeverUsedProfileFileCreateRead (004b03f0), TGATextureFileScanner (004c3a00), VehicleFileLoader (004c3d80), SceneFileLoader (004c52c0), sub_4C84A0 (004c84a0), TireBrandLoader (004d7660), ReversePathSearchForBackslashSeparator (00565ef0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x8)+0x0) | 0x144 | R | — | [LLM] |
| *(obj+0x8) | 0x0 | R | — | [LLM] |
| obj | 0x8 | R | — | [LLM] |
| obj | 0x210 | R | — | [LLM] |
| obj | 0x218 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566810 | sub_566810 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
