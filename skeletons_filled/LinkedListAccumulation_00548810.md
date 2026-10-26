## LinkedListAccumulation_00548810 — AccumulateNodeValuesIntoCounters

**Summary:** Walks a linked list starting from this[0x24], calls a per-node cleanup/reset function, then accumulates two DWORD fields from each node (offsets 0xDC and 0xE0) into this[0] and this[4].

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VertexBufferResourceAllocation (00543fa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Accumulated sum of node field at offset 0xDC |
| this | 0x4 | RW | 0 | Accumulated sum of node field at offset 0xE0 |
| this | 0x24 | R | — | Head pointer to the linked list to traverse |

**Written-by note (persistence):**
- this 0x0: Written to 0 at start, then incremented per node; external poke survives after execution
- this 0x4: Written to 0 at start, then incremented per node; external poke survives after execution

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00546430 | FAILCallChainSaysAccumulatesButFunctionZEROS0x94 | Clears/resets data at offset 0x94 in each node before accumulation |

**Guard conditions:** this[0x24] (head pointer) must be non-null for loop body to execute. If null, function returns 0 immediately with accumulators zeroed.
