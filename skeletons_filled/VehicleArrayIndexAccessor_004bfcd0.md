## VehicleArrayIndexAccessor_004bfcd0 — Indexed vehicle file pointer lookup

**Summary:** Walks a linked list to find the Nth node, then uses its data pointer to index into the global vehicle file array. Returns pointer to the vehicle file entry or 0 if index out of range.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameFilterDataLoader (004c0db0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x0 | R | — | data pointer from the current list node |
| this | 0x0 | R | — | head of linked list |
| this | 0x8 | RW | 0 | current/iter node pointer for list walking |
| this | 0xC | R | — | count of elements in linked list |

**Written-by note (persistence):**
- this 0x8: set to head then walked a2 steps, or set to 0 for negative index; external poke corrupts iteration

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ac390 | dword_8AC390 | R | count of vehicle file entries |
| 008ac394 | dword_8AC394 | R | pointer to vehicle file entry array (stride 0x424) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Returns 0 if a2 >= this[3] (list count). Returns 0 if inner index v7 >= dword_8AC390 (vehicle file count). Returns 0 if list is empty or walk finds null node before reaching step a2.
