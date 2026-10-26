## ShortComputation_a110_0049a110 — LinkedSkipAndCountChildren

**Summary:** Walks a linked list anchored at this+0x08, skipping up to `a2` nodes by following next-sibling pointers (offset 0x24), then switches to child pointers (offset 0x28) and counts remaining nodes. Returns count of nodes reachable via child links after the skip.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x30)+0x24)+0x28) | 0x28 | R | — | unknown — not directly traceable in C code |
| *(*(this+0x30)+0x24) | 0x24 | R | — | unknown — not directly traceable in C code |
| *(this+0x30) | 0x28 | R | — | unknown — not directly traceable in C code |
| this | 0x8 | R | — | linked list head pointer (this[2]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 <= 0 skips the forward-walk loop entirely, jumps directly to child-switch. v2 (node pointer) checked NULL after each step — traversal stops at NULL. Each step increments counter; once v3 >= a2, switches to child traversal mode.
