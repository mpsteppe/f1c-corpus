## IndexedListLookup_004bfd40 — Linked list index accessor

**Summary:** Walks a linked list to the Nth node and returns the first DWORD of the node's data. Generic list accessor returning stored integer value at index.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AIDriverCountSetup (004bfd90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x0 | R | — | data pointer from current list node |
| this | 0x0 | R | — | head of linked list |
| this | 0x8 | RW | 0 | current/iter node pointer for list walking |
| this | 0xC | R | — | count of elements in linked list |

**Written-by note (persistence):**
- this 0x8: set to head then walked a2 steps, or set to 0 for negative index; external poke corrupts iteration

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Returns 0 if a2 >= this[3] (list count). Returns 0 if current node pointer is null during walk. Returns 0 if current node's data pointer is null. Returns 0 if data pointer's first DWORD is null.
