## SceneSortComparator_004c5d30 — Compare two filter properties for sorting

**Summary:** Comparison function for sorting filter property nodes. Primary key is the SceneOrder position (field 0xC); ties broken by scene name comparison (offset 0x104 in scene array), falling back to filter property name strings (field 0x4). Returns true if first argument sorts before second.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneFileFilterBuilder (004c6330), MergeSortLinkedList (004c6810)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Scene index in global scene array (used to locate scene entry) |
| this | 0x4 | R | — | Filter property name string pointer (fallback comparison key) |
| this | 0xC | R | — | SceneOrder position (primary sort key) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | Compare two strings; returns negative if first < second (lexicographic) |

**Guard conditions:** Primary comparison: if `this[3]` != `a2[3]`, return difference sign. Secondary: if both scene entries exist (`dword_8AC490 + 396*idx` non-null), compare scene names at offset 0x104. Fallback: compare `this[1]` vs `a2[1]` name strings, using `byte_5EA438` default path if either is null.
