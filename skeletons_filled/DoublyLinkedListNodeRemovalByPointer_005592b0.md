## DoublyLinkedListNodeRemovalByPointer_005592b0 — DoublyLinkedListNodeRemovalByPointer

**Summary:** Remove a specific node from doubly-linked list by pointer comparison. Unlink target (update prev->next and next->prev), call ResourceNodeCleanup, free node, update head and decrement count.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiFieldFree (004cb4f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x144 | R | — | Node count, decremented on removal; if was 1, head zeroed |
| this | 0x148 | RW | 0 | List head pointer, updated if target was head |
| this | 0x214 | R | — | unknown |
| this | 0x218 | R | — | unknown |
| this | 0x27C | RW | — | unknown |

**Written-by note (persistence):**
- this 0x148: Updated if target node was the list head (set to target->next)
- this 0x27C: unknown

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00557470 | EmptyStub_7470 | No-op stub called before freeing |
| 005574b0 | sub_5574B0 | ResourceNodeCleanup — free sub-resources of the removed node |
| 00587bcf | FreeWrapper_7bcf | Heap free the removed node |

**Guard conditions:**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x148 | != | 0 | List head pointer — non-null means list has nodes |
| (walk) | v3[26] | != | a2 | Next pointer per node — loop continues while not matching target |

**Guard interpretation:** PASS if list head non-null (walk list looking for target). PASS per iteration while current node != target a2. BLOCKED (early exit) if head null or walk reaches end without finding target — cleanup still runs (count decrement).
