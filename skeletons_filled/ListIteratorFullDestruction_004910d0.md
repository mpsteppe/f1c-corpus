## ListIteratorFullDestruction_004910d0 — ListDetachAndFreeAll

**Summary:** Full destruction of a doubly-linked list sentinel struct: first reparents each node's value elsewhere via LinkedListNodePrepend, then frees all node memory (calling EmptyStub_0170 on values if flags indicate active). Zeros the 4-DWORD struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiListDestruction (00490b90), sub_491770 (00491770), CircularBufferRingAdvance (004917c0), CollisionProxyListBuilder (00491ad0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x4 | R | — | Next pointer of the node at current/tail position |
| obj | 0x0 | R | — | Node's value/data pointer (checked before EmptyStub_0170) |
| obj | 0x8 | R | — | Node's flags byte (+8): if non-zero, value is active and needs cleanup |
| this | 0x0 | RW | 0 | List head pointer (zeroed after destruction) |
| this | 0x4 | RW | 0 | List tail pointer (zeroed after destruction) |
| this | 0x8 | RW | 0 | List current/tail pointer (zeroed after destruction) |
| this | 0xC | RW | 0 | List node count (zeroed after destruction) |

**Written-by note (persistence):**
- this 0x0: zeroed at end; destroyed
- this 0x4: zeroed at end; destroyed
- this 0x8: zeroed at end; destroyed
- this 0xC: zeroed at end; destroyed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490aa0 | LinkedListNodePrepend | Reparent each node's value to another list (detach before free) |
| 004b0170 | EmptyStub_0170 | Empty stub called on value pointer if node flags byte is non-zero |
| 00587bcf | FreeWrapper_7bcf | Free heap memory for node (and value if flags indicate active) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 0 | List head pointer — BLOCKED: empty list, skip both reparent and free phases |

**Guard interpretation:** Phase 1 (reparent): if head `*(_DWORD*)a1` is non-null → walk via head->next chain, calling LinkedListNodePrepend on each node's value; stop when current/tail pointer or its next field is null. Phase 2 (free): if head is non-null → walk all nodes, if node's byte at +8 is non-zero AND value at [0] is non-zero → call EmptyStub_0170 on value then free value; then free node. After both phases, zero all 4 fields.
