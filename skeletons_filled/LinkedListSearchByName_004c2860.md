## LinkedListSearchByName_004c2860 — LinkedListSearchByName

**Summary:** Walks a linked list starting from this+0x10, comparing each node's name string (at node+8) against a target string a2 using string comparison. Returns the first matching node's address, or 0 if not found. Falls back to default path for null names.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerCareerStatsGameOptionsLoader (004c18b0), TrackSceneNodeAdd (004c28d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10) | 0x8 | R | — | node name string pointer, read for comparison |
| this | 0x10 | R | — | search list head pointer, starting point for walk |
| this | 0x18 | RW | — | list cursor pointer, updated to next node per iteration |
| this | 0x1C | R | — | list metadata (count or end marker) |

**Written-by note (persistence):**
- this 0x18: set to list head initially, then advanced per iteration — external poke survives (cursor position)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default directory path, fallback when node name is null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | string comparison function (returns 0 on match, non-zero on mismatch) |

**Guard conditions:** this+0x10 (list head) must be non-null. If any cursor advance produces null, returns 0 (end of list). PASSES: node whose name matches a2 (sub_588410 returns 0).
