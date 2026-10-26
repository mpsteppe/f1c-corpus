## LinkedListDestructor_1db0_00491db0 — Destroy linked list and free all nodes

**Summary:** Iterates linked list, frees each node's data payload (if ownership flag at node+0x8 is set), frees each node, then zeros list header fields (head, tail, iterator, count).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiListDestruction (00490b90), CollisionBroadphaseBuilder (00490ee0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x4) | 0x4 | R | — | Node next pointer |
| obj | 0x0 | R | — | Node data payload pointer |
| obj | 0x8 | R | — | Node ownership/valid flag |
| this | 0x0 | RW | 0 | List head pointer (zeroed after destruction) |
| this | 0x4 | RW | 0 | List tail pointer (zeroed) |
| this | 0x8 | RW | 0 | List cached iterator pointer (zeroed) |
| this | 0xC | RW | 0 | List node count (zeroed) |

**Written-by note (persistence):**
- this 0x0: unconditional, set to 0 after all nodes freed
- this 0x4: unconditional, set to 0 after all nodes freed
- this 0x8: unconditional, set to 0 after all nodes freed
- this 0xC: unconditional, set to 0 after all nodes freed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Frees node allocation and optionally its data payload |

**Guard conditions:** If list head (this[0]) is null, loop body never executes. Each iteration checks node+0x8 flag and *node (data pointer) before freeing data payload.
