## SceneLoadAndNameMatch_00475920 — FindMatchingSceneEntry

**Summary:** Loads current scene filename from game command dispatch, then iterates a linked list of filename entries to find which one matches the loaded scene; stores matching entry index in field 0xFC.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xE8)+0x0) | 0x0 | R | — | Filename string pointer from linked list node (char*) |
| *(*(this+0xE8)+0x0) | 0x1 | R | — | Second byte of filename string (for comparison) |
| *(this+0xE8) | 0x0 | R | — | Pointer to first linked list node head |
| *(this+0xEC) | 0x4 | R | — | Next-node pointer in linked list |
| this | 0xE8 | R | — | Pointer to linked list of filename entries |
| this | 0xF4 | R | — | Entry count limit for bounds checking |
| this | 0xF8 | R | — | Number of entries to search |
| this | 0xFC | RW | — | Matched entry index (set when filename equal to current scene) |

**Written-by note (persistence):**
- this 0xFC: set conditionally (only when match found); external poke survives until next scene load

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] — fallback string (empty/default) |
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] — interface to query current scene |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004693e0 | FilenameFromLinkedList | Extracts filename string at given index from linked list |
| 0048d360 | GuardedAccessor | Returns safe/validated access index for the list |

**Guard conditions:** Main search loop (lines 25-68) PASSES only when this[0xF8] > 0 (at least one entry to search). If 0, loop BLOCKED — function returns early without setting match.