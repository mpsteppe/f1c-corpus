## CollisionObjectListManagement_004b4b50 — CollisionObjectListFilterProcess

**Summary:** Manages 4 collision object sub-lists: rebuilds/sorts lists, finds global minimum float threshold, removes entries within ±0.02 tolerance of minimum, processes removed entries through collision dispatch pipeline, returns count processed. Called from sub_4B7860 for per-frame collision management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B7860 (004b7860)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x70)+0x0) | 0x4 | R | — | Float value at head of sub-list (compared against threshold) |
| *(this+0x70) | 0x0 | R | — | Head pointer of first sub-list |
| *(this+0x70) | 0x4 | RW | — | Tail pointer of first sub-list (updated during sort) |
| *(this+0x70) | 0x8 | R | — | Anchor pointer of first sub-list (used for traversal) |
| this | 0x0 | RW | 0 | Enable flag — set to 0 after list rebuild (disables re-sort) |
| this | 0x70 | RW | — | Sub-list head pointer array entry 0 (sorted each frame) |
| this | 0x74 | RW | — | Sub-list head pointer array entry 1 |
| this | 0x78 | RW | — | Sub-list head pointer array entry 2 |
| this | 0x7C | R | — | Sub-list count array entry 0 (must be >0 for processing) |

**Written-by note (persistence):**
- *(this+0x70) 0x4: written during list rebuild (tail updated)
- this 0x0: written to 0 after initial rebuild (one-shot guard)
- this 0x70: written each frame via sub_4BAB20 sort
- this 0x74: written each frame via sub_4BAB20 sort
- this 0x78: written each frame via sub_4BAB20 sort

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acd0c | flt_5ACD0C | R | AudioMergeTolerance — threshold tolerance (±0.02 check) |
| 008ab700 | dword_8AB700 | R | FreeListHead — used during allocation/recycle |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004646f0 | ConditionalDestructor_46f0 | Destroy/cleanup filtered list node buffer |
| 0049af30 | LinkedListFree | Free entire temporary filtered list |
| 004b42e0 | FAILWRONGDESCRIPTION_42e0 | Dispatch collision data for each filtered entry |
| 004b4470 | FileHandleCloseRegistration | Register/handle collision data output via dispatch |
| 004ba790 | sub_4BA790 | Advance to next entry in filtered list iteration |
| 004bab20 | sub_4BAB20 | Sort/rebuild a single sub-list |
| 004bac20 | ShortComputation_ac20 | Allocate/initialize new node buffer for filtered list |
| 004bb490 | sub_4BB490 | Unlink/remove processed entry from filtered list |
| 00582290 | ConditionalFreeByFlagCheck | Free node with type-aware conditional logic |
| 00587bcf | FreeWrapper_7bcf | Free removed node struct memory |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate node struct for filtered list entries |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x70 | == | 0 | First sub-list head pointer — if null, list is empty |
| this | 0x7C | > | 0 | Any sub-list count must be positive — if all 4 counts ≤ 0, return 0 |

**Guard interpretation:** If *this (enable flag) is non-zero at entry: rebuild/sort all 4 sub-lists and clear flag. Then: if all 4 sub-list counters (at this+0x7C, +0x80, +0x84, +0x88) are ≤ 0, return 0 (nothing to process). Otherwise: find global minimum float across all list heads, filter out entries within ±0.02 tolerance, process filtered entries through dispatch pipeline, free temporary list.
