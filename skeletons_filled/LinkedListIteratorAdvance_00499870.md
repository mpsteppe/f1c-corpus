## LinkedListIteratorAdvance_00499870 — Iterator advance to next linked-list node

**Summary:** Advances linked-list iterator: loads next node from current, updates iterator state, returns success. If current node is NULL, returns false (end of list). Part of linked-list iteration utility.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_499910 (00499910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x18) | 0x0 | R | — | first field of pointer stored at this+0x18 — new current node |
| *(this+0x18) | 0x4 | R | — | second field (offset 4) of pointer at this+0x18 — traversal link |
| this | 0xC | R | — | container pointer used for traversal state |
| this | 0x10 | RW | — | current node pointer — replaced with next node on advance |
| this | 0x14 | RW | — | current value/data — updated from new node via FieldGetter_8e30 |
| this | 0x18 | RW | — | temporary traversal pointer (next-candidate chain) |

**Written-by note (persistence):**
- this 0x10: updated destructively each call — persists as iterator position
- this 0x14: updated destructively each call — persists as current value
- this 0x18: written temporarily during traversal; holds intermediate pointer

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00498e30 | FieldGetter_8e30 | extracts value/data field from a linked-list node |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | == | 0 | current node — NULL when iterator exhausted |

**Guard interpretation:** PASSES when `this+0x10 != 0` — advances iterator to next node, updates current value, returns true. BLOCKED when `this+0x10 == 0` — returns false (no advance, end of list reached).
