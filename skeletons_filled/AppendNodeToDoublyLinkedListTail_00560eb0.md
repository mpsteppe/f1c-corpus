## AppendNodeToDoublyLinkedListTail_00560eb0 — DoublyLinkedListTailAppend

**Summary:** Appends a node to the tail of a doubly linked list, updating prev/next pointers between old tail and new node, setting bit 2 in node flags.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** DoublyLinkedListNodeMover (0054ba00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x60)+0x34) | 0x34 | RW | — | next pointer (offset 0x34) of tail node in secondary list |
| this | 0x2C | RW | — | list head pointer (this[11], set if list was empty) |
| this | 0x60 | R | — | pointer to list descriptor |

**Written-by note (persistence):**
- *(*(this+0x60)+0x34) 0x34: recalc every frame — external poke does NOT persist
- this 0x2C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If list head (this[11]) is null → set head to new node (PASS: first node). Otherwise → traverse to tail via next pointers (offset 0x34) and append (PASS: append to existing list). Always updates node prev/next and sets flag bit 2 (active/in-list).
