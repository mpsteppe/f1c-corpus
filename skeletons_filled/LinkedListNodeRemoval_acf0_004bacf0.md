## LinkedListNodeRemoval_acf0_004bacf0 — Head node pop and return

**Summary:** Removes the head node from a singly-linked list, returns its data pointer, and frees the node but not its attached data. Updates head/tail/current/count bookkeeping.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionObjectInsertion (004b48e0), ModelSceneFileLoader (004b6c90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | Node data pointer (return value) |
| obj | 0x4 | RW | — | Node next pointer (used for unlinking) |
| obj | 0x8 | RW | 0 | Node byte flag (cleared; prevents data free) |
| obj | 0xC | R | — | unknown — referenced in binary but not in decompiled logic |
| this | 0x0 | RW | — | List head pointer (updated to next node) |
| this | 0x4 | RW | — | List tail pointer (updated if removing last node) |
| this | 0x8 | RW | — | List current/iterator pointer (set to old head) |
| this | 0xC | RW | — | List node count (decremented) |

**Written-by note (persistence):**
- obj 0x4: overwritten during unlink; persists in node memory until freed
- obj 0x8: cleared to 0; persists in node until freed
- this 0x0: updated to next node; persists across calls
- this 0x4: updated if tail removed; persists across calls
- this 0x8: updated each call; persists across calls
- this 0xC: decremented each removal; persists across calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Memory deallocation (node only) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x0 | == | 0 | Node data pointer null check |
| this | 0x0 | == | 0 | List head null check |

**Guard interpretation:** BLOCKS (returns 0) when list head is null OR head node's data pointer is null. PASSES when list non-empty and data non-null.
