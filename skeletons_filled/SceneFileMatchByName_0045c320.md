## SceneFileMatchByName_0045c320 — SceneFileMatchByName

**Summary:** Searches linked list of file entries for a match against the filename portion of a path. Returns associated data value and updates iterator position. Part of terrain/scene file resolution.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TerrainIniParser (00460a10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xC) | 0x8 | R | — | Match result data stored at current node (copied to output a3) |
| this | 0x4 | R | — | Head pointer of file entry linked list |
| this | 0xC | RW | — | Current iterator position in linked list (advances on mismatch) |
| this | 0x10 | R | — | unknown — read but not used in visible decompilation |

**Written-by note (persistence):**
- this 0xC: overwritten each time iterator advances to next node. External poke survives only until next advance.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Fallback directory path when node string pointer is null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | String comparison function; returns 0 on match |

**Guard conditions:** Head pointer (this+0x4) must be non-null and its first dereference non-zero to enter search loop. Loop continues while sub_588410 returns non-zero (no match); breaks on match (returns 0). If next node pointer is null, exits with no match (returns 0, *a3=0).
