## CollisionBroadphaseTraversal_00491170 — BroadphaseRecursiveTraversal

**Summary:** Recursive broadphase AABB traversal: walks list testing overlap via AABBOverlapTest; if no direct hit but sub_491680 filter passes, clips rectangle and recurses on subdivisions. Returns 1 on any overlap, 0 if list exhausted.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_1c70 (00491c70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x8)+0x4)+0x0) | 0x0 | R | — | Short AABB value (x1) from next node in iteration |
| *(*(*(this+0x8)+0x4)+0x0) | 0x2 | R | — | Short AABB value (y1) from next node in iteration |
| *(*(*(this+0x8)+0x4)+0x0) | 0x4 | R | — | Short AABB value (x2) from next node in iteration |
| *(*(*(this+0x8)+0x4)+0x0) | 0x6 | R | — | Short AABB value (y2) from next node in iteration |
| *(*(this+0x8)+0x4) | 0x0 | R | — | Next node pointer from current iteration position |
| *(obj+0x0) | 0x0 | R | — | AABB x1 coordinate (short) |
| *(obj+0x0) | 0x2 | R | — | AABB y1 coordinate (short) |
| *(obj+0x0) | 0x4 | R | — | AABB x2 coordinate (short) |
| *(obj+0x0) | 0x6 | R | — | AABB y2 coordinate (short) |
| *(this+0x8) | 0x4 | R | — | Next pointer of node at current iteration position |
| obj | 0x0 | R | — | Current node's value pointer (__int16[4] AABB) |
| this | 0x0 | R | — | List head pointer |
| this | 0x8 | RW | — | Current iteration pointer (advances through list) |

**Written-by note (persistence):**
- this 0x8: written each iteration step (advance to next); persists within traversal call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490aa0 | LinkedListNodePrepend | Prepend clip-result nodes to output list after recursive traversal |
| 00491170 | CollisionBroadphaseTraversal | Recursive self-call for each clipping subdivision |
| 00491350 | RectangleClipping | Clip rectangle against boundary, returning subdivision list |
| 004915a0 | AABBOverlapTest | Test if current node's AABB overlaps target |
| 00491680 | sub_491680 | Secondary broadphase filter test to decide if clipping is needed |

**Guard conditions:** If list head `*(_DWORD*)a1` is null → return 0. If first node value `*v2` is null → return 0. If AABBOverlapTest returns true → return 1 immediately. If sub_491680 returns false → advance to next node; if no more nodes → return 0. If sub_491680 returns true → clip rectangle, recurse on each subdivision; if recursion finds overlap → return 1; else prepend clip nodes and return 0.
