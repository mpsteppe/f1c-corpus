## LinkedListTailAppend_00486500 — List3AppendToTail

**Summary:** Appends a node to the tail of linked list 3 (head at this+0xD4). Traverses nodes using next pointer at offset 0x18; if list empty, sets head directly.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_493480 (00493480)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xEC)+0x18) | 0x18 | RW | — | next-pointer (offset 0x18) of the tail node, set to new node |
| this | 0xD4 | RW | — | head pointer of linked list 3 (this[53]) |
| this | 0xEC | R | — | indirect base used for tail-node next-pointer access |

**Written-by note (persistence):**
- *(*(this+0xEC)+0x18) 0x18: conditionally set to new node; external writes before append survive on other nodes
- this 0xD4: conditionally set when list was empty; external writes before next append survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** checks this[53] (offset 0xD4, list head) != NULL → if non-null, walks nodes via next-pointer at node+0x18 until reaching null, then links new node as tail->next (PASSES). If head is null, sets head = a2 directly (PASSES). Null tail traversal terminates gracefully.
