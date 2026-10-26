## LinkedListIndexScannerWithValidation_00415550 — LinkedListIndexScannerWithValidation

**Summary:** Scans a linked list (head at this[4], count at this[7]) to find the index of a node whose string matches a2. Returns matching index or -1 if not found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionStringNameLookup (004122c0), ScoringClassificationDisplay (0041e320), ConstructorStandingsParser (00420820), GdbSeasonSelector (00420cf0), VehicleSetupDriverNumber (004c7b50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10) | 0x0 | R | — | String pointer dereferenced from list node data for comparison |
| *(this+0x14) | 0x4 | R | — | Next pointer in linked list node for traversal |
| this | 0x10 | R | — | Head pointer of the linked list (this[4]) |
| this | 0x1C | R | — | Count of entries in the list (this[7]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default string fallback when list node string pointer is null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566810 | sub_566810 | String comparison function (returns 0 on match) |

**Guard conditions:** If a2 is null, returns -1 immediately. If this[7] (count) <= 0, returns -1. PASSES: matching string found — returns node index. BLOCKED: no match found, returns -1.
