## DoublyLinkedListTailInsertion_00545030 — DoublyLinkedListTailInsertion

**Summary:** Inserts a node at the tail of a doubly linked list. Traverses the list from head (this[62], stored at offset 0xF8) using next pointers at +440 to find the end, then links the new node with previous/next pointers at +436/+440. If list is empty, sets the new node as head.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_55A060 (0055a060)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x2B0)+0x1B8) | 0x1B8 | RW | — | next pointer (+440) of the tail node; written with new node address |
| this | 0xF8 | RW | — | linked list head pointer (this[62]); set to new node when list is empty |
| this | 0x2B0 | R | — | starting node reference (this[172]); head of list to traverse |

**Written-by note (persistence):**
- *(*(this+0x2B0)+0x1B8): next pointer of tail node updated each insertion
- this 0xF8: overwritten with a2 when list was empty

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No explicit guard. When list head (this[62]) is 0, new node becomes head directly. Otherwise traverses until next pointer is 0 and appends.
