## PlayerNameNeverUsedProfileNameUniquenessCheck_00469550 — PlayerNameUniquenessCheck

**Summary:** Checks whether a given profile name is unique by scanning a linked list of existing profile filenames. Returns true if the name is unique (no matching entry found), with special handling for the "PlayerNameNever" string. Belongs to profile creation/validation system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ProfileAlreadyExistsPageHandler (0046cb50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x450 | R | — | number of profile entries to check (this[276]); iteration limit |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c6970 | aPlayernameneve | R | Str_UI_PlayerNameNever [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007d2e41 | byte_7D2E41 | R | Byte_SeasonScoringFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004693e0 | FilenameFromLinkedList | retrieves a profile filename from linked list at given index |
| 00568910 | sub_568910 | copies filename into local buffer for comparison |
| 00588410 | sub_588410 | compares two strings; returns non-zero when equal |

**Guard conditions:** If a2 is NULL or empty string, returns false (0) immediately (BLOCKED). If this[276] (profile count, offset 0x450) is <= 0, returns true (1) — unique, no profiles exist (PASSES). Iterates through linked list: for each index calls FilenameFromLinkedList then sub_588410 to compare. If name does NOT match any entry after checking all, returns true (1) — unique (PASSES). If a mismatch is found before exhaustion, exits loop and returns byte_7D2E41 AND name != "PlayerNameNever" condition.
