## WalkLinkedListCallDestructorFreeNodes_005833e0 — LinkedListDestroyWithSEHCleanupDirect

**Summary:** Destroys a linked list by walking each flagged node, calling SEHGuardedFunctionWithExceptionHandling on its data, then freeing both data and node. Zeros all list fields after completion.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_583AE0 (00583ae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | Node's data pointer (first DWORD of 12-byte node) |
| obj | 0x8 | R | — | Flag byte — non-zero means call SEH cleanup on data before freeing |
| this | 0x0 | RW | 0 | Head pointer of linked list |
| this | 0x4 | RW | 0 | Tail pointer of linked list |
| this | 0x8 | RW | 0 | Current/iterator pointer |
| this | 0xC | RW | 0 | Node count |

**Written-by note (persistence):**
- this 0x0: cleared to 0 at end.
- this 0x4: cleared to 0 at end.
- this 0x8: cleared to 0 at end.
- this 0xC: cleared to 0 at end.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005867b0 | SEHGuardedFunctionWithExceptionHandling | Call cleanup callback on flagged node's data |
| 00587bcf | FreeWrapper_7bcf | Free node memory and optionally data memory |

**Guard conditions:** Checks *this (head pointer, offset 0x0) — if null, skips iteration and goes to zeroing fields.
