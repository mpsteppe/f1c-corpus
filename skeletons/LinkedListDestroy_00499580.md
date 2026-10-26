## LinkedListDestroy_00499580 — Linked-list node destruction with conditional vtable call

**Summary:** Walks a linked list freeing each node; conditionally calls virtual destructor (vtable[0]) on nodes with flag at offset 0xC set and valid vtable pointer. Zeros list fields after loop. Part of list/container teardown.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_495300 (00495300)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x0)+0x0) | 0x0 | R | — | vtable slot 0 of node — virtual destructor |
| *(obj+0x0) | 0x0 | R | — | first field of node (vtable pointer) |
| *(obj+0x4) | 0x4 | R | — | next linked-list node pointer |
| obj | 0x0 | R | — | vtable pointer of node |
| obj | 0xC | R | — | destructor flag byte — if set, calls virtual dtor before free |
| this | 0x0 | RW | 0 | list head pointer — zeroed after destruction |
| this | 0x4 | RW | 0 | list field — zeroed after destruction |
| this | 0x8 | RW | 0 | list field — zeroed after destruction |
| this | 0xC | RW | 0 | list field — zeroed after destruction |

**Written-by note (persistence):**
- this 0x0: written to 0 once after all nodes freed; list becomes empty
- this 0x4: written to 0 once after destruction
- this 0x8: written to 0 once after destruction
- this 0xC: written to 0 once after destruction

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees each node from heap |

**Guard conditions:** Per-node guard: byte at `obj+0xC` must be non-zero AND `*obj` (vtable pointer) must be non-NULL — PASSES calls virtual destructor at vtable[0]; BLOCKED skips destructor. Node always freed via FreeWrapper_7bcf regardless.
