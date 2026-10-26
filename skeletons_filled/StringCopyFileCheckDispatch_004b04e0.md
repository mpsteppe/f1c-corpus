## StringCopyFileCheckDispatch_004b04e0 — StringCopyFileCheckDispatch

**Summary:** Copies input filename string to internal buffer at this+20, determines target directory (settings dir or default), checks if path matches settings directory, builds full path if needed, then calls PlayerFileInit to initialize player file.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PathStringUtility (00404850), SetupFileLoadAndFinalize (00469630), PlayerNameNeverUsedProfileFileCreateRead (004b03f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec440 | dword_5EC440 | R | SettingsDirectory [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b01b0 | sub_4B01B0 | builds full directory path from name + settings dir |
| 004b0540 | PlayerFileInit | initializes player file data structure |
| 00566810 | sub_566810 | compares path against directory prefix (returns position of match) |

**Guard conditions:** No early-exit guards. Always copies string, builds path, calls PlayerFileInit.
