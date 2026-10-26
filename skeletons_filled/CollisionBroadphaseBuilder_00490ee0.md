## CollisionBroadphaseBuilder_00490ee0 — BroadphaseListBuilder

**Summary:** Builds/updates broadphase collision list: takes input list a1 and new AABB (a2-a5), filters existing entries via sub_491680, clips overlapping entries into subdivisions, calls BroadphasePairPartition (sub_490D00) to finalize partitioning. Core broadphase update step.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderSurfaceFillCopy (004918d0), DualDispatchWithGuard (00491960)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | Node's value/data pointer (first field of list node) |
| obj | 0x4 | RW | — | Node's next pointer (written during list unlink/link) |
| obj | 0x8 | R | — | Node's flags byte at +8 |
| this | 0x0 | RW | — | Input list head pointer |
| this | 0x4 | RW | — | Input list tail pointer |
| this | 0x8 | RW | — | Input list current/tail iteration pointer |
| this | 0xC | RW | — | Input list node count |

**Written-by note (persistence):**
- obj 0x4: written during link/unlink, persists until node freed
- this 0x0: written on init, remove, and append; persists until next mutation
- this 0x4: written on append and remove; persists until next mutation
- this 0x8: written on advance and remove; persists until next mutation
- this 0xC: decremented on remove, incremented on append; persists until next mutation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00434030 | DoublyLinkedListAppend | Append nodes from local list back to a1 after partition |
| 00490940 | ResourcePoolNodeAllocDealloc | Get pool node for input AABB coordinates (a2-a5) |
| 00490aa0 | LinkedListNodePrepend | Prepend removed a1 node to another list after clip replacement |
| 00490d00 | sub_490D00 | BroadphasePairPartition — partition pairs between local list and a1 |
| 00491350 | RectangleClipping | Clip rectangle coordinates when AABB fails filter test |
| 00491680 | sub_491680 | Secondary broadphase filter test on AABB pair |
| 00491db0 | LinkedListDestructor_1db0 | Destroy local temporary list after use |
| 00491e10 | ConditionalResourceCleanup | Decrement resource refcount when removing a node |
| 004bac20 | ShortComputation_ac20 | Initialize local list node from pool node values |
| 00581780 | LinkedListNodeAdvance | Iterate nodes in local list after partition |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate new list nodes for clip subdivisions |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 0 | Input list head — BLOCKED: empty list, skip filter/clip loop |

**Guard interpretation:** If `*a1` (input list head) is null or `*v6` (first node value) is null → skip main iteration. Inner loop: if `sub_491680` passes → clip AABB, create new nodes, append to a1, remove current node, prepend it elsewhere. If fails → advance to next `a1` node. After loop: create local list from pool node, call sub_490D00 to partition, then append local list nodes back to a1.
