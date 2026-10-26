## ProfileIconPathSetter_00478390 — ProfileIconPathSetter

**Summary:** Resolves profile icon bitmap path from resource linked list: walks list (LinkedListIndexedAccessor_f590), extracts path string from node, falls back to default directory if null, writes result to global lpExistingFileName.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceQueryAndStoredSetup (00478320), sub_478350 (00478350)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE0 | R | — | resource list pointer passed through for list access |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c6658 | lpExistingFileName | W | global output buffer for resolved profile icon BMP path |
| 005ea438 | byte_5EA438 | R | default directory/fallback path when node string is null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048f590 | LinkedListIndexedAccessor_f590 | traverses/indexes linked list to retrieve resource node |

**Guard conditions:** First: this[56] must be non-null (skip if no resource list). Second: LinkedListIndexedAccessor_f590 result must be non-null (skip if node not found).
