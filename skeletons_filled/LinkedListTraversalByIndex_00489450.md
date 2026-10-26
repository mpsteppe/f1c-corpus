## LinkedListTraversalByIndex_00489450 — ListIndexLookup

**Summary:** Walks linked list starting at offset 0x90, following next pointers at offset 0x8C in each node, up to index count at offset 0x168. Returns node at that index or null if out of bounds.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIScreenTextAccessor (00489920), UIScreenTextAccessor_9950 (00489950)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x11C) | 0x8C | R | — | Next pointer field within each linked list node |
| this | 0x90 | R | — | Linked list head pointer |
| this | 0x168 | R | — | Index/count to traverse (number of steps) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If index at 0x168 < 0, returns null immediately. Loop aborts when next pointer is null (end of list).
