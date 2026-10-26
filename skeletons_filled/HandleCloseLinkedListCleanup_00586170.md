## HandleCloseLinkedListCleanup_00586170 — HandleCloseAndLinkedListFree

**Summary:** Closes handle at offset 0x10 if flag at offset 0x18 is set and CloseHandle succeeds, then destroys linked list rooted at offset 0x0 by freeing each node's data pointer (with SEHGuardedFunctionWithExceptionHandling call if node flag at +8 is set) and freeing the node itself. Zeroes all head/tail fields after cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | Data pointer stored in linked list node |
| obj | 0x8 | R | — | Flag byte in node: if non-zero, node data pointer is valid |
| this | 0x0 | RW | 0 | Linked list head pointer |
| this | 0x4 | RW | 0 | Linked list auxiliary/tail pointer |
| this | 0x8 | RW | 0 | Auxiliary field |
| this | 0xC | RW | 0 | Auxiliary field |
| this | 0x10 | RW | 0 | Handle to close (e.g., thread/event handle) |
| this | 0x18 | R | — | Flag byte: if non-zero, handle at 0x10 should be closed |

**Written-by note (persistence):**
- this 0x0: set to 0 at end; survives as external write until destruct
- this 0x4: set to 0 at end
- this 0x8: set to 0 at end
- this 0xC: set to 0 at end
- this 0x10: set to 0 if CloseHandle succeeds

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a8 | CloseHandle | R | Close handle at offset 0x10 if flag at 0x18 is set |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005867b0 | SEHGuardedFunctionWithExceptionHandling | SEH-protected call on node data before freeing |
| 00587bcf | FreeWrapper_7bcf | Free heap-allocated node and node data pointer |

**Guard conditions:** Handle close: flag byte at offset 0x18 must be non-zero AND CloseHandle must succeed to clear handle at offset 0x10. List iteration: processes node only if node flag at +8 is non-zero AND node data pointer at node+0 is non-null.
