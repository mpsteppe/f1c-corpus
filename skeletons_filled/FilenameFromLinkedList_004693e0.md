## FilenameFromLinkedList_004693e0 — FilenameFromLinkedList

**Summary:** Retrieves a filename string from a linked list by index, copies it to a buffer, then strips the file extension and path prefix to return just the bare filename. Belongs to profile/scene file management system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ProfileIconBmpLoader (004692b0), PlayerNameNeverUsedProfileNameUniquenessCheck (00469550), SetupFileLoadAndFinalize (00469630), ThreeCallChain (00469857), SceneLoadAndNameMatch (00475920)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x444)+0x4)+0x0) | 0x0 | R | — | leaf node's string pointer (after following list and inner pointer) |
| *(*(this+0x444)+0x4) | 0x0 | R | — | inner struct's string pointer from the linked list node |
| *(*(this+0x444)+0x4) | 0x4 | R | — | inner struct's next pointer from the linked list node |
| this | 0x444 | R | — | linked list head pointer (this[273]) |
| this | 0x450 | R | — | element count / max index (this[276]); used for bounds check |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks a2 (index) against this[276] (element count at offset 0x450) for bounds — if out of range, returns byte_5EA438 (BLOCKED). Walks linked list at this[273] (offset 0x444) by following next pointers until index reached or list exhausted — if node not found, returns byte_5EA438 (BLOCKED). Checks inner pointers dereferenced from node for null — if null, returns default. After copy, finds '.' extension and null-terminates to strip it; then finds '\\' path delimiter and returns pointer to character after it.
