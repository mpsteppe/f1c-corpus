## VehicleFilteringSelection_004c4990 — Filter vehicles by criteria, build result list

**Summary:** Filters vehicles from global vehicle array by matching all specified criteria, excluding vehicles already present in a keyed exclusion list, and builds a linked list of matching vehicle indices in the output structure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4C4D50 (004c4d50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | Head pointer of result linked list (list of matching vehicle index nodes) |
| this | 0xC | RW | — | Tail pointer for O(1) appends to linked list |
| this | 0x10 | RW | — | Permanent first-node pointer (set once on first insertion) |
| this | 0x14 | RW | — | Count of items in result linked list |

**Written-by note (persistence):**
- this 0x8: set to first node on first match; updated if head changes on removal by external caller
- this 0xC: set to each new node's address on every match; overwritten each time
- this 0x10: set once to first node; survives unless external code clears it
- this 0x14: incremented for each match; persists until external reset

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ac390 | dword_8AC390 | R | VehicleFileCount [DERIVED] |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c4cb0 | LinkedListKeySearch | Check if vehicle index is already in an exclusion keyed list; returns 1 if present (skip) |
| 00566810 | sub_566810 | Compare vehicle field at offset 0x1BC against a filter value; returns 0 on match |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate memory for linked list node (4-byte int + 12-byte node struct) |

**Guard conditions:** Entry blocked if `*a2` (first filter value) is zero; or `a3` (filter count) <= 0; or `dword_8AC390` (vehicle count) <= 0. Per-vehicle: skipped if `LinkedListKeySearch(v6)` returns nonzero (vehicle in exclusion list) or vehicle entry pointer at `dword_8AC394 + stride*v6` is null. Vehicle included only when `sub_566810` returns 0 for all `a3` filter comparisons (all criteria match).
