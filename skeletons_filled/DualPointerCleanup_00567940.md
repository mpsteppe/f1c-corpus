## DualPointerCleanup_00567940 — free two pointers

**Summary:** Frees pointer at offset 0x18 first (if non-null), then frees pointer at offset 0x10 (if non-null). Returns result of last free. Tree/node cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RecursiveTreeTraversalFree (00567a90), sub_567CC0 (00567cc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | pointer at offset 0x10 (freed second) |
| this | 0x18 | R | — | pointer at offset 0x18 (freed first) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | memory deallocation (free equivalent) |

**Guard conditions:** If pointer at offset 0x18 is NULL → skip first free. If pointer at offset 0x10 is NULL → skip second free.
