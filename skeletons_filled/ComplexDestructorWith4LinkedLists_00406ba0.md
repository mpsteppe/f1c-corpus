## ComplexDestructorWith4LinkedLists_00406ba0 — MultiListDestructorWithVTableSwitch

**Summary:** Destructor/cleanup for an object containing 4 independent linked lists (audio objects, stream objects, and two generic object lists). Frees all nodes, calls virtual destructors where applicable, then zeros all list pointers. Audio system; swaps vtable at end.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalDestructor (00406b80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x18)+0x0) | 0x0 | R | — | dereferenced node pointer of list 3 (first DWORD of node) |
| *(*(this+0x8)+0x0) | 0x0 | R | — | dereferenced node pointer of list 1 (first DWORD of node) |
| *(this+0x18) | 0x0 | R | — | list 3 head pointer (iteration start) |
| *(this+0x1C) | 0x4 | R | — | list 3 node's flag byte at +0x8 (within node via next ptr) |
| *(this+0x2C) | 0x4 | R | — | list 2 node's flag byte at +0x8 |
| *(this+0x8) | 0x0 | R | — | list 1 head pointer (iteration start) |
| *(this+0xC) | 0x4 | R | — | list 1 node's flag byte at +0x8 |
| this | 0x0 | RW | — | vtable pointer (set to off_59E530, later off_59E598) |
| this | 0x8 | RW | 0 | list 1 head (zeroed after free walk) |
| this | 0xC | RW | 0 | list 1 tail/count (zeroed) |
| this | 0x10 | RW | 0 | list 1 sentinel (zeroed) |
| this | 0x14 | RW | 0 | list 1 sentinel (zeroed) |
| this | 0x18 | RW | 0 | list 3 head (zeroed after free walk) |
| this | 0x1C | RW | 0 | list 3 tail/count (zeroed) |
| this | 0x20 | RW | 0 | list 3 sentinel (zeroed) |
| this | 0x24 | RW | 0 | list 3 sentinel (zeroed) |
| this | 0x28 | RW | 0 | list 2 head (zeroed after free walk) |
| this | 0x2C | RW | 0 | list 2 tail/count (zeroed) |
| this | 0x30 | RW | 0 | list 2 sentinel (zeroed) |
| this | 0x34 | RW | 0 | list 2 sentinel (zeroed) |
| this | 0x38 | RW | 0 | list 4 (simple) head (zeroed after free walk) |
| this | 0x3C | RW | 0 | list 4 tail/count (zeroed) |
| this | 0x40 | RW | 0 | list 4 sentinel (zeroed) |
| this | 0x44 | RW | 0 | list 4 sentinel (zeroed) |

**Written-by note (persistence):**
- this 0x0: written once (destructor vtable swap) — external poke does NOT survive final state
- this 0x8: written once (zeroed) — external poke does NOT survive
- this 0xC: written once (zeroed) — external poke does NOT survive
- this 0x10: written once (zeroed) — external poke does NOT survive
- this 0x14: written once (zeroed) — external poke does NOT survive
- this 0x18: written once (zeroed) — external poke does NOT survive
- this 0x1C: written once (zeroed) — external poke does NOT survive
- this 0x20: written once (zeroed) — external poke does NOT survive
- this 0x24: written once (zeroed) — external poke does NOT survive
- this 0x28: written once (zeroed) — external poke does NOT survive
- this 0x2C: written once (zeroed) — external poke does NOT survive
- this 0x30: written once (zeroed) — external poke does NOT survive
- this 0x34: written once (zeroed) — external poke does NOT survive
- this 0x38: written once (zeroed) — external poke does NOT survive
- this 0x3C: written once (zeroed) — external poke does NOT survive
- this 0x40: written once (zeroed) — external poke does NOT survive
- this 0x44: written once (zeroed) — external poke does NOT survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e530 | off_59E530 | R | VTable_StreamObject [DERIVED] |
| 0059e598 | off_59E598 | R | VTable_FUN_00406ba0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f70 | ConditionalFreeWithBit0Flag | conditionally frees a node if bit-0 flag is set (list 2 nodes) |
| 00406e50 | AudioSystemShutdown | shuts down the audio subsystem before freeing audio-related objects |
| 004081e0 | UtilityFunction | per-node cleanup/preprocessing before freeing list 4 nodes |
| 00587bcf | FreeWrapper_7bcf | generic memory free for list nodes after cleanup |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | == | 0 | list 1 node's flag byte at +0x8 within iteration — if zero BLOCKED (skip free) |
| this | 0x20 | == | 0 | list 3 node's flag byte at +0x8 within iteration — if zero BLOCKED (skip free) |
| this | 0x30 | == | 0 | list 2 node's flag byte at +0x8 within iteration — if zero BLOCKED (skip free) |

**Guard interpretation:** Each of the 4 for-loops walks a linked list. The loop itself is guarded by the list head being non-NULL (implicit in `for (ptr = head; ptr; ptr = ptr->next)`). Within lists 1-3, each node has a flag byte at offset +0x8: if that byte is zero (==0), BLOCKED — skip freeing/destroying that node (it passes through without action). If non-zero AND the node's first DWORD pointer is non-NULL, PASSES — the node is freed/destroyed. List 4 has no inner flag check; all nodes pass through UtilityFunction then FreeWrapper_7bcf unconditionally.
