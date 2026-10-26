## DrawableObjectNodeManager_005454d0 — Drawable object node append and flat array rebuild

**Summary:** Appends drawable object node `a2` to a category-specific singly-linked list, updates category counters, then rebuilds a flat array of 56-byte zero-initialized entries sized to the total count. Frees the old array before allocating the new one.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_545430 (00545430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x128)+0x6C)+0x6C) | 0x6C | RW | — | Next-node pointer at tail — written when appending to non-empty tail |
| *(this+0x128) | 0x6C | R | — | Next-node pointer in category-4 linked list (forward link) |
| this | 0x60 | RW | — | Total count = sum of category 4 and category 2 counters |
| this | 0x124 | R | — | Counter for category 4 objects |
| this | 0x128 | RW | — | Head of category-4 singly-linked list |
| this | 0x12C | R | — | Counter for category 2 objects |
| this | 0x134 | RW | 0 | Flag cleared when flat array is freed/rebuilt |
| this | 0x138 | RW | 0 | Pointer to flat array of 56-byte drawable entry slots |

**Written-by note (persistence):**
- *(*(*(this+0x128)+0x6C)+0x6C) 0x6C: Once — set to `a2` on non-empty list append (tail's next pointer)
- this 0x60: Once per call — recomputed as sum of category counters
- this 0x128: Conditional — set to `a2` when category-4 list was empty; unchanged otherwise
- this 0x134: Cleared when old array is freed
- this 0x138: Updated with new allocation on success; set to 0 on failure

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | Per-entry cleanup during old array teardown (empty stub) |
| 0055d200 | StructZeroInitWithBaseCall | Zero-initialize each 56-byte entry in new array |
| 00587bcf | FreeWrapper_7bcf | Free old flat array allocation |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate new flat array (56 * count + 4 bytes) |

**Guard conditions:** `a3` switch: selects category list (1/2/4) by value. List head null check: PASSES (walk to tail, append) when non-null; BLOCKED (set as new head) when null. `this[78]` non-null: PASSES (free old array) when existing allocation exists; BLOCKED (skip cleanup) when null. `OperatorNewNhMallocWrapper` return: PASSES (use new array) when non-null; BLOCKED (set pointer null, return 0) when null.
