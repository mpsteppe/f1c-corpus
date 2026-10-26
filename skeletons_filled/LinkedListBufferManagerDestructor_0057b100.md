## LinkedListBufferManagerDestructor_0057b100 — DoubleLinkedListBufferManagerDestructor

**Summary:** Frees two embedded linked lists (heads at offsets 0x8 and 0x18). For each node with flag at +8 set, frees data pointer at node+0. Frees nodes via FreeWrapper_7bcf. Zeroes all list fields (head, tail, tail2, counter for each list) and byte flag at offset 4.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x18)+0x4) | 0x4 | R | — | list 2 node->next pointer (node+4); read during traversal |
| *(*(this+0x8)+0x4) | 0x4 | R | — | list 1 node->next pointer (node+4); read during traversal |
| *(this+0x18) | 0x0 | R | — | list 2 node data pointer (node+0); freed if flag set |
| *(this+0x18) | 0x8 | R | — | list 2 node flag byte (node+8); checked for free decision |
| *(this+0x8) | 0x0 | R | — | list 1 node data pointer (node+0); freed if flag set |
| *(this+0x8) | 0x8 | R | — | list 1 node flag byte (node+8); checked for free decision |
| this | 0x4 | RW | 0 | byte flag, cleared |
| this | 0x8 | RW | 0 | list 1 head pointer, zeroed after traversal |
| this | 0xC | RW | 0 | list 1 tail pointer, zeroed |
| this | 0x10 | RW | 0 | list 1 secondary tail pointer, zeroed |
| this | 0x14 | RW | 0 | list 1 counter, zeroed |
| this | 0x18 | RW | 0 | list 2 head pointer, zeroed after traversal |
| this | 0x1C | RW | 0 | list 2 tail pointer, zeroed |
| this | 0x20 | RW | 0 | list 2 secondary tail pointer, zeroed |
| this | 0x24 | RW | 0 | list 2 counter, zeroed |

**Written-by note (persistence):**
- this 0x4: written once per call (0); survives
- this 0x8-0x14: written once per call (0); survives
- this 0x18-0x24: written once per call (0); survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees node data (if flag set) and node |

**Guard conditions:** none — for loops terminate naturally on null node pointer; no early return

