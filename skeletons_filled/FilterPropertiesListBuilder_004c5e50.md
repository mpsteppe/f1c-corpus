## FilterPropertiesListBuilder_004c5e50 — Build filter property list matching criteria

**Summary:** Iterates scene registry entries, skips those in exclusion list, builds a filter property name from scene name, checks against filter criteria. For matching entries, allocates and initializes a filter property struct (via sub_4C5C80), appends to result linked list.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneFileFilterBuilder (004c6330)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | Head pointer of result linked list |
| this | 0xC | RW | — | Tail pointer for appending nodes |
| this | 0x10 | RW | — | Permanent first-node pointer |
| this | 0x14 | RW | — | Count of items in result list |

**Written-by note (persistence):**
- this 0x8: set on first insertion; updated if head changes
- this 0xC: set to each new node on every insertion
- this 0x10: set once to first node
- this 0x14: incremented per match

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d31ec | aFilterProperti | R | FilterPropertiesString [DERIVED] (also: ` — "Filter Properties" string constant) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac488 | dword_8AC488 | R | SceneFileCount [DERIVED] |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c4cb0 | LinkedListKeySearch | Check if scene index is in exclusion keyed list (skip if present) |
| 004c58a0 | StringCopyWithValidation | Build filter property name from "Filter Properties" prefix and scene name |
| 004c5c80 | sub_4C5C80 | Initialize filter property struct with scene index and name |
| 00566810 | sub_566810 | Compare filter property name against criterion value; 0 on match |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate filter property struct (16 bytes) and linked list node (12 bytes) |

**Guard conditions:** Entry blocked if `*a2` (first filter) is zero, `a3` (filter count) <= 0, or `dword_8AC488` (scene count) <= 0. Per-scene: skipped if already in exclusion list (`LinkedListKeySearch` returns nonzero) or scene entry null. Scene included only when `sub_566810` returns 0 for all `a3` filter comparisons AND `StringCopyWithValidation` returns 0 (success).
