## LinkedListWalker_004a1d10 — LinkedListWalker

**Summary:** Walks a singly-linked list and invokes FileSettingsScanner on each node. Tracks current position in iterator field (this+0x8). Used during player file initialization to process settings entries.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerFileInit (004b0540)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x0)+0x0) | 0x0 | R | — | next node pointer (linked list chain) |
| *(obj+0x0) | 0x0 | R | — | first node pointed to by list head |
| this | 0x0 | R | — | head of linked list |
| this | 0x8 | RW | — | current iterator position during walk |
| this | 0x10 | R | — | (unused in this function) |

**Written-by note (persistence):**
- this 0x8: written each iteration during walk; updated externally before walk begins

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a1b90 | FileSettingsScanner | Processes each linked list node's settings data |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 0 | head of linked list |

**Guard interpretation:** If list head (this[0]) is NULL, returns immediately (no walk). Otherwise, initializes iterator to head and walks nodes until a NULL pointer is encountered in the next-node chain.
