## StringListLookup_004ce860 — StringListLookup

**Summary:** Searches a strided string table array (108 bytes per entry) for a given normalized string. Calls StringTableLookup for each entry and returns the matching entry's index, or -1 if not found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AnimationPlaybackSequence (0044acb0), sub_4CEF30 (004cef30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | entry count (this[2]) |
| this | 0xC | R | — | pointer to first string entry in table (this[3]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cdbf0 | StringTableLookup | check if entry matches target string |
| 00589901 | sub_589901 | normalize/uppercase the search string for case-insensitive comparison |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | <= | 0 | entry count |

**Guard interpretation:** PASSES (entry count > 0): iterate through table and search for match. BLOCKED (count <= 0): return -1 immediately (empty list).
