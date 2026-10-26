## NetworkBufferSearch_00581600 — Linked list search by ID with buffer write

**Summary:** Searches mutex-protected linked list for node matching a2 via ReadFieldAtOffset0x14. On match, writes data to output buffer at a3+4 via BufferWriteWithParams and optionally increments counter via CounterIncrementDecrementByFlag. Returns 1 if found, 0 if not.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xAC8) | 0x0 | R | — | First dword of head node (next/link pointer) used to start traversal |
| this | 0xAC8 | R | — | Linked list head pointer (offset 2760). Null when list empty |
| this | 0xAD0 | RW | — | Walk/iteration pointer (offset 2768). Set to head on init, advanced during search |
| this | 0xAD4 | R | — | Element count (offset 2772) |
| this | 0xAD8 | R | — | Mutex handle (offset 2776) for thread safety |
| this | 0xADC | R | — | Wait timeout (offset 2780) for mutex acquisition via WaitForSingleObject |

**Written-by note (persistence):**
- this 0xAD0: Updated per call during list walk (advance to next node). Ephemeral.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | Acquire mutex before list traversal |
| 0059e1a4 | ReleaseMutex | R | Release mutex after list traversal completes |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005871f0 | ReadFieldAtOffset0x14 | Read node identifier at offset 0x14 from each node during search; compared against a2 |
| 00587230 | CounterIncrementDecrementByFlag | Increment counter on match when flag a4 is set (optional logging/metric) |
| 00587620 | BufferWriteWithParams | Write matched node data into output buffer at a3+4 |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xAC8 | == | 0 | Linked-list head pointer — null when list empty |

**Guard interpretation:** When this+0xAC8 is 0 (list empty), the search loop is skipped entirely and function returns 0 (not found). When non-null, walks list comparing each node's offset-0x14 field against a2.
