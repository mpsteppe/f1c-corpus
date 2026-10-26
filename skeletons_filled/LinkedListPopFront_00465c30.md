## LinkedListPopFront_00465c30 — LinkedListPopFront

**Summary:** Pops front node from linked list at this+0xE5C8, returns its data via a2. Returns 1 on success, 0 if list empty or node data is zero.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** InputCommandDispatchToEntities (0045f4a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0xE5C8) | 0x0 | R | — | node data value (first dword of linked list node) |
| *(obj+0xE5C8) | 0x4 | R | — | next pointer (second dword of linked list node) |
| obj | 0xE5C8 | RW | — | head pointer of linked list |
| this | 0x0 | R | — | base/self pointer of enclosing struct |

**Written-by note (persistence):**
- obj 0xE5C8: conditional — rewritten when list non-empty (head advances to next node). External poke survives (pointer field, stable storage).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks if head pointer at this+0xE5C8 is NULL → return 0 (list empty, blocked). Then checks if node's first dword (*head) is 0 → return 0 (invalid/empty node, blocked). If both pass, pops node and returns 1.
