## CollisionProxyListBuilder_00491ad0 — RebuildCollisionProxyList

**Summary:** Rebuilds collision proxy working list at header offset 28: clears it, then iterates two source lists (ring buffer slot + embedded list at offset 44), copies each node's AABB into a pool node and appends to working list. Then calls BroadphasePairPartition between working list and list at offset 12.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_496E90 (00496e90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x2C)+0x0) | 0x0 | R | — | AABB x1 (short) from first node in embedded source list at offset 44 |
| *(*(obj+0x2C)+0x0) | 0x2 | R | — | AABB y1 (short) from first node in embedded source list |
| *(*(obj+0x2C)+0x0) | 0x4 | R | — | AABB x2 (short) from first node in embedded source list |
| *(*(obj+0x2C)+0x0) | 0x6 | R | — | AABB y2 (short) from first node in embedded source list |
| *(*(obj+0x34)+0x4) | 0x0 | R | — | Next pointer from current node of embedded source list |
| *(obj+0x2C) | 0x0 | R | — | Head pointer of embedded source list at offset 44 (read for iteration) |
| *(obj+0x34) | 0x4 | R | — | Next pointer of current iteration node in embedded source list |
| obj | 0x4 | R | — | Current ring buffer index (used to select ring slot) |
| obj | 0x8 | R | — | Ring buffer base pointer (array of 16-byte list sentinels) |
| obj | 0x1C | RW | — | Head of working list at offset 28 — written when appending first node |
| obj | 0x20 | RW | — | Tail of working list at offset 28 — written each append |
| obj | 0x24 | RW | — | Current pointer of working list — written when appending first node |
| obj | 0x28 | R | — | Count of working list — incremented each append |
| obj | 0x2C | R | — | Head pointer of embedded source list at offset 44 (guard check) |
| obj | 0x34 | RW | — | Current pointer of embedded source list — advanced during iteration |
| this | 0x0 | R | — | Pointer to header struct (*this has all state) |

**Written-by note (persistence):**
- obj 0x1C: written once if working list was empty (set to new first node)
- obj 0x20: written each append
- obj 0x24: written once if working list was empty
- obj 0x34: written each advance through source list iteration

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490940 | ResourcePoolNodeAllocDealloc | Get pool node for each source AABB during copy |
| 00490d00 | sub_490D00 | BroadphasePairPartition between working list (+28) and list at +12 |
| 004910d0 | ListIteratorFullDestruction | Clear/destroy working list at offset 28 before rebuild |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate 12-byte list node for each copied AABB entry |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x2C | == | 0 | Head of embedded source list — BLOCKED: skip iterating that source |

**Guard interpretation:** Loop runs twice (v2=0, v2=1). v2=0: source is ring buffer element at `base + 16*index`. v2=1: source is embedded list at header+44. If source list head is null or first value is null → skip source. For each non-null source node: pool alloc, wrap in 12-byte node, append to working list at +28. After loop, call sub_490D00(+28, +12).
