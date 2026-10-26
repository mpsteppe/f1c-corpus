## PriorityQueueRecursiveProcess_00544db0 — PriorityQueueRecursiveProcess

**Summary:** Recursively processes a priority queue/scene graph structure. Checks child nodes at offsets 0x44 and 0x4C (recursing when non-null), then iterates a linked list at offset 0x204 (with next pointer at +16), calling sub_54CA00 on each element.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_544740 (00544740)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x214) | 0x10 | R | — | next pointer (+16) on linked list node at this[133] |
| this | 0x44 | R | — | child node pointer A (recursive if non-zero) |
| this | 0x4C | R | — | child node pointer B (recursive if non-zero AND a2 is true) |
| this | 0x204 | R | — | linked list head (this[129]) for sub_54CA00 iteration |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00544db0 | PriorityQueueRecursiveProcess | recursive self-call for child nodes |
| 0054ca00 | sub_54CA00 | test/process function on linked list node; returns 0 = continue, non-zero = stop |

**Guard conditions:** BLOCKED child A recursion when this[44] is 0 (skipped). BLOCKED child B recursion when this[4C] is 0 or a2 is 0 (skipped). BLOCKED linked list iteration when this[204] is 0 (return 0). Returns -1 (error/stop) if any sub_54CA00 returns non-zero.
