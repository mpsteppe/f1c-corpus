## sub_4ADD50_004add50 — SaveFileCopyWithMetadata

**Summary:** Copies a save/settings file from source path to destination path, then overwrites the destination filename portion with metadata bytes from global renderer/UI state variables. Uses CopyFileA with overwrite enabled.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextFileReader (004b09a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e19c | CopyFileA | R | kernel32 CopyFileA import for file copy |
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005c5e60 | dword_5C5E60 | R | MenuResourcePtr [DERIVED] |
| 005c5e64 | dword_5C5E64 | R | Int_RenderState_5E64 [DERIVED] |
| 005c5e68 | dword_5C5E68 | R | Unknown_Renderer_5C5E68 [DERIVED] |
| 005c5e6c | dword_5C5E6C | R | Unknown_Dword_5C5E6C [DERIVED] |
| 005c5e70 | word_5C5E70 | R | Word_UIDataBuffer [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec440 | dword_5EC440 | R | SettingsDirectory [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0220 | PathTruncationUtility | truncates/fixes destination path to max 238 chars |
| 0058815f | StringFormatWithBufferOverflowCheck | safe sprintf, builds source path from directory + resource name |

**Guard conditions:** None — straight-line. Always copies file and overwrites destination metadata.
