## LinkedListAppend_004864c0 — List2AppendToTail

**Summary:** Appends a node to the tail of linked list 2 (head at this+0xD0). Traverses nodes using next pointer at offset 0x18; if list empty, sets head directly.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_493480 (00493480)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xE8)+0x18) | 0x18 | RW | — | next-pointer (offset 0x18) of the tail node, set to new node |
| this | 0xD0 | RW | — | head pointer of linked list 2 (this[52]) |
| this | 0xE8 | R | — | indirect base used for tail-node next-pointer access |

**Written-by note (persistence):**
- *(*(this+0xE8)+0x18) 0x18: conditionally set to new node; external writes before append survive on other nodes
- this 0xD0: conditionally set when list was empty; external writes before next append survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** checks this[52] (offset 0xD0, list head) != NULL → if non-null, walks nodes via next-pointer at node+0x18 until reaching null, then links new node as tail->next (PASSES). If head is null, sets head = a2 directly (PASSES). Null tail traversal terminates gracefully.
