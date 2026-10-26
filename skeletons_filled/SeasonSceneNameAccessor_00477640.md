## SeasonSceneNameAccessor_00477640 — SeasonSceneNameTableCopier

**Summary:** Copies season scene name strings from a global linked list entry's pointer table into managed buffers. Reads entry at index 0 and index 47 from the string table.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CopyProfileIconBMP (0046cd20), GameMode (0046d6d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce64c | dword_7CE64C | R | GameFilterDataPath [DERIVED] |
| 007ce668 | dword_7CE668 | R | TrackNameStringPtr [DERIVED] (also: ` � track name display string) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048f590 | LinkedListIndexedAccessor_f590 | retrieves an indexed element from a linked list |
| 00566650 | StringCopyWithBufferRealloc | copies a string with automatic buffer reallocation |

**Guard conditions:** `LinkedListIndexedAccessor_f590()` must return non-null; pointer table at offset 0x3C of result must be non-null
