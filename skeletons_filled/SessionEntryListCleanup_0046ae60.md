## SessionEntryListCleanup_0046ae60 — TeamEntryListReset

**Summary:** Cleans up and rebuilds team entry linked list. Frees old list nodes and their sub-objects if release flag set, zeros list pointers, then iterates team entries (dword_7D1424) to rebuild list with current module references via LinkedListInsertWithNodeAllocation and MessageNameBufferUpdate.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DualCallWrapper_af00 (0046af00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x0 | R | — | node's sub-object pointer to free |
| *(this+0x48) | 0x4 | R | — | linked list next pointer (traversal) |
| this | 0x44 | RW | 0 | linked list head pointer, cleared after cleanup |
| this | 0x48 | RW | 0 | list pointer, zeroed after cleanup |
| this | 0x4C | RW | 0 | list pointer, zeroed after cleanup |
| this | 0x50 | RW | 0 | list pointer/counter, zeroed after cleanup |

**Written-by note (persistence):**
- this 0x44: set to 0 after freeing list; survives
- this 0x48: set to 0 after cleanup; survives
- this 0x4C: set to 0 after cleanup; survives
- this 0x50: set to 0 after cleanup; survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007d1424 | dword_7D1424 | R | TeamEntryCount [DERIVED] — number of team entries to iterate |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00455560 | ArrayIndexedAccessor | indexes into ppvOut array by team index |
| 0046ad50 | MessageNameBufferUpdate | builds display name buffer for team entry |
| 00486f30 | LinkedListInsertWithNodeAllocation | appends node to rebuilt linked list |
| 00489cb0 | StateCleanupNotification | state cleanup notification callback |
| 00587bcf | FreeWrapper_7bcf | frees node sub-object and node itself |

**Guard conditions:** First loop checks each node's byte flag at +8 (v5). PASSES if non-zero AND node's sub-object pointer (*v4) non-null → frees sub-object and node. BLOCKED if flag is zero or sub-object null → skips free for that node.
