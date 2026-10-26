## LinkedListDestructor_0048ca50 — LinkedListNodeListDestructor

**Summary:** Destroys linked list at this+0x31C. Walks nodes, calls vtable destructor on each non-terminal node, frees all nodes, zeros list fields, then restores HUDTimer vtable via VTableInit. Each node: offset 0x0=vtable, 0x4=next, 0xC=active flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListDestroyAt0x444 (0047fbd0), DestructorWithConditionalFree_ca30 (0048ca30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x31C)+0x0)+0x0) | 0x0 | R | — | VTable pointer of first node (indirect via node->vtable) |
| *(*(this+0x31C)+0x0) | 0x0 | R | — | First node's vtable pointer |
| *(*(this+0x31C)+0x4) | 0x4 | R | — | First node's next pointer |
| *(this+0x31C) | 0x0 | R | — | First node's vtable pointer (head of list) |
| *(this+0x31C) | 0xC | R | — | First node's active flag byte |
| this | 0x0 | RW | &off_5AC048 | VTable pointer set to UnknownVTable_B |
| this | 0x31C | RW | 0 | Linked list head pointer (zeroed after destruction) |
| this | 0x320 | RW | 0 | Linked list tail/end pointer (zeroed after destruction) |
| this | 0x324 | RW | 0 | Linked list count/size (zeroed after destruction) |
| this | 0x328 | RW | 0 | Linked list max/reserved (zeroed after destruction) |

**Written-by note (persistence):**
- this 0x0: written once (to off_5AC048), then overwritten by VTableInit to HUDTimer vtable. Final vtable persists.
- this 0x31C: zeroed after destruction. Persists.
- this 0x320: zeroed after destruction. Persists.
- this 0x324: zeroed after destruction. Persists.
- this 0x328: zeroed after destruction. Persists.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac048 | off_5AC048 | R | UnknownVTable_B — temp vtable during destruction |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Frees each linked list node from memory |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x31C) | 0xC | == | 0 | First node's flag — if 0, node is terminal (no vtable destructor) |

**Guard interpretation:** For each node in list: if byte at node+0xC == 0 (terminal/placeholder node) → BLOCKED: vtable destructor skipped, node is only freed. If byte != 0 AND node has vtable pointer → PASSES: vtable destructor called with arg 1 before freeing. After all nodes freed, list fields zeroed and vtable restored to HUDTimer.
