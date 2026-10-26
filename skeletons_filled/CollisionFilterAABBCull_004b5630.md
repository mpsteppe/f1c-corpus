## CollisionFilterAABBCull_004b5630 — AABB Cull Filter

**Summary:** Walks an active collision linked list, filtering nodes by field comparison and Z-distance threshold. Nodes that fail the check are removed from the active list and appended to a separate output list (culled). Allocates new entries for culled nodes.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B9000 (004b9000)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x20)+0x0) | 0x370 | R | — | Node Z-position or distance value |
| *(this+0x20) | 0x0 | R | — | Active list head node pointer |
| *(this+0x20) | 0x4 | RW | — | Node next link for list traversal |
| *(this+0x20) | 0x8 | R | — | Node flag byte (allocator/free indicator) |
| *(this+0x20) | 0xC | R | — | Node data payload pointer |
| *(this+0x28) | 0x0 | R | — | Cull list head node pointer |
| *(this+0x28) | 0x4 | R | — | Cull list count |
| this | 0x10 | RW | — | Output cull list head (appended culled nodes) |
| this | 0x14 | RW | — | Output cull list tail |
| this | 0x18 | RW | — | Output cull list iterator current |
| this | 0x1C | RW | — | Next link of newly inserted cull entry |
| this | 0x20 | RW | — | Active list head (modified when first node culled) |
| this | 0x24 | RW | — | Active list tail |
| this | 0x28 | RW | — | Output cull linked list head |
| this | 0x2C | R | — | Active list count (decremented on cull) |
| this | 0x30 | R | — | Z-distance threshold for culling |

**Written-by note (persistence):**
- *(this+0x20) 0x4: Updated when node is culled (next link adjusted); persists.
- this 0x10: Written with newly allocated entry on first cull; persists.
- this 0x14: Written with newly allocated entry as tail; persists.
- this 0x18: Written with current entry from cull list traversal; per-call.
- this 0x1C: Written as next link of new entry (set to previous head); persists.
- this 0x20: Written when head node is culled; persists.
- this 0x24: Written with first cull entry; persists.
- this 0x28: Written with incremented count; persists.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acd30 | dbl_5ACD30 | R | DoubleDistThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | No-op or debug stub before free |
| 004bac20 | ShortComputation_ac20 | Initialize/set up new cull entry node |
| 005001d0 | FieldCompareConstant | Test node field against constant (keep condition) |
| 005001f0 | FloatComparisonCheck | Test node float field against threshold (keep condition) |
| 00587bcf | FreeWrapper_7bcf | Free node or payload memory |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate 12-byte cull entry structure |

**Guard conditions:** If this+0x20 (active list head) is NULL, return immediately — empty list. For each node: keep if FieldCompareConstant AND FloatComparisonCheck both pass, OR if |node[0x370] - this[0x30]| <= 2.5. Otherwise cull: remove from active list (adjust prev/next links, decrement count), optionally free payload if flag byte at offset 0x8 is set, then allocate new 12-byte entry and append to output cull list at this+0x10.
