## LinkedListDestructorChain_00583360 — LinkedListDestroyWithTimerCallbackCleanup84

**Summary:** Destroys a linked list, calling NTimeCallbackLoopWithSEH (84-byte entries, SEHGuardedFunctionWithExceptionHandling callback) on each flagged node's data before freeing. Frees intermediate data blocks and nodes, zeros all list fields.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x0 | R | — | First DWORD of data block (entry count for NTimeCallbackLoopWithSEH) |
| obj | 0x0 | R | — | Node's data pointer (first DWORD of 12-byte node) |
| obj | 0x8 | R | — | Flag byte — non-zero means process callback entries before freeing |
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
| 005867b0 | SEHGuardedFunctionWithExceptionHandling | R | Callback passed to NTimeCallbackLoopWithSEH for per-entry cleanup |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free nodes, data blocks, and callback blocks |
| 0058a5f7 | NTimeCallbackLoopWithSEH | Process callback entries (84 bytes each) with SEH protection |

**Guard conditions:** Checks *this (head pointer, offset 0x0) — if null, skips iteration and zeros fields.
