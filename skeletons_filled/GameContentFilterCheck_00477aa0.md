## GameContentFilterCheck_00477aa0 — ContentFilterCheckWithSettingsLookup

**Summary:** Checks a content string at offset 0x180 against the game filter. If content matches the filter, skips processing; otherwise invokes virtual callback at offset 160. Always follows up with a settings path comparison that may trigger a scene list search.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xA0 | R | — | unknown |
| this | 0x0 | R | — | vtable pointer (virtual call at offset 160) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c7130 | aGameFilter | R | GameFilterString [DERIVED] (also: ` — "Game Filter" string constant) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00477ba0 | SceneListSearchByPath | searches scene list matching settings file path |
| 0048f590 | LinkedListIndexedAccessor_f590 | retrieves an indexed element from a linked list |
| 0049a2b0 | StringPointerDereference | dereferences string pointer at given address |
| 005681f0 | ConditionalDispatch_81f0 | gets game filter string |
| 00588410 | sub_588410 | string comparison (returns 0 for match) |

**Guard conditions:** filter active AND content string matches filter → skip virtual callback (BLOCKED); filter active AND content != filter → call virtual callback (PASSES); filter NOT active AND content string non-empty → call virtual callback (PASSES); filter NOT active AND content empty/null → skip (BLOCKED); settings `dword_7CE5EC` differs from list entry string at offset 0x104 → call SceneListSearchByPath
