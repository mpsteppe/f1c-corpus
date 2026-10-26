## TwoIterationCleanup_00516853 — TwoPassCleanup

**Summary:** Runs sub_516772 cleanup for categories 1 and 0 in two iterations, then frees the base pointer at this+0x4 and clears it to 0. Delegates final return value to EmptyStub_7b96.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 0 | base pointer for allocator state, freed via FreeWrapper_9351 then set to NULL |

**Written-by note (persistence):**
- this 0x4: freed and set to 0 during cleanup (permanent reset)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00516772 | sub_516772 | cleanup free lists for category index i (1 then 0) |
| 00519351 | FreeWrapper_9351 | frees the allocator state base block |
| 00587b96 | EmptyStub_7b96 | final operation, result returned as function result |

**Guard conditions:** No conditional branches — always cleans up categories 1 and 0 then frees base pointer.
