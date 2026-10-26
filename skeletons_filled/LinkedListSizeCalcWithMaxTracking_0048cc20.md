## LinkedListSizeCalcWithMaxTracking_0048cc20 — LinkedListMaxSizeCalc

**Summary:** Walks linked list at this+0x31C, computes maximum dimensions from each node's sub-object child struct (offsets 28 and 32 plus padding). Initializes default maxes to 5, tracks running max in this+0x32C and this+0x330.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListNodeAppend (0048d2b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x31C)+0x0)+0x10) | 0x1C | R | — | Child struct offset 28 (dimension 1 + 2 padding) from node's sub-object chain |
| *(*(*(this+0x31C)+0x0)+0x10) | 0x20 | R | — | Child struct offset 32 (dimension 2) from node's sub-object chain |
| *(*(this+0x31C)+0x0) | 0x0 | R | — | First linked list node's next pointer (node[0]) |
| *(*(this+0x31C)+0x0) | 0x4 | R | — | First linked list node's sub-object pointer (node[1]) |
| *(*(this+0x31C)+0x0) | 0x10 | R | — | First linked list node's offset 0x10 (iterator tracking) |
| *(this+0x31C) | 0x0 | R | — | List head pointer (head of linked list) |
| this | 0x31C | R | — | Linked list head pointer (this[199]) |
| this | 0x324 | RW | result | List walk pointer (this[201]) — updated as nodes are traversed |
| this | 0x32C | RW | 5 | Max dimension 1 (this[203]) — running max of child offset 28 + 2 |
| this | 0x330 | RW | 5 | Max dimension 2 (this[204]) — running max of child offset 32 |

**Written-by note (persistence):**
- this 0x324: updated during walk as iterator advances. Volatile — per-call state.
- this 0x32C: initialized to 5, updated with max(prev, child_dim1+2). Persists after call.
- this 0x330: initialized to 5, updated with max(prev, child_dim2). Persists after call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If this+0x31C (head) is null → BLOCKED: loop skipped, this[203] and this[204] remain at 5. If any node's sub-object pointer (node[1]) is null → BLOCKED: that node skipped. If sub-object's child pointer (subobj+12) is null → BLOCKED: dimension update skipped for that node.
