## LinkedListNodeInsert_00407520 — FileResourceLinkedListInsertByKey

**Summary:** Inserts a file-backed resource node into a linked list by integer key, skipping if a node with that key already exists. Part of a file resource caching system that loads file data into memory and manages file handles per node.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x0 | R | — | key value of the first node pointed by cursor |
| this | 0x38 | RW | — | head pointer of linked list |
| this | 0x3C | RW | — | tail pointer of linked list |
| this | 0x40 | RW | — | traversal cursor into linked list |
| this | 0x44 | R | — | count of nodes in linked list |

**Written-by note (persistence):**
- this 0x38: set once on first insertion when list was empty (this[14] = v16)
- this 0x3C: updated on every successful insertion (this[15] = v16)
- this 0x40: set to head at function start, advanced during traversal

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be828 | aRb | R | FileModeRb [DERIVED] (also: ` — string comparison template) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004053e0 | ShortComputation_53e0 | initializes the allocated 116-byte file resource node structure |
| 00405410 | MultiStageCleanupWithFree | releases resources within a file resource node before freeing |
| 004080f0 | MemoryAllocationWithBufferRead | reads file content into an allocated buffer; returns non-zero on success |
| 005665b0 | sub_5665B0 | processes the second element of the a2 parameter pair |
| 00566650 | StringCopyWithBufferRealloc | copies a string into a buffer with reallocation |
| 00587bcf | FreeWrapper_7bcf | memory deallocation wrapper |
| 00587c03 | OperatorNewNhMallocWrapper | memory allocation wrapper (allocates 12-byte or 116-byte blocks) |
| 00587d02 | FileCloseWithLock | closes file handle with synchronization |
| 00587db0 | sub_587DB0 | opens a file (takes path and mode string), returns file handle |
| 00588410 | sub_588410 | compares two strings; returns non-zero on match |
| 0059b758 | StructFieldGetterAt0x10 | retrieves file size (or position) from file handle's offset 0x10 |

**Guard conditions:** If input `a2` is null, function returns 0 immediately. If a node with key `a3` already exists in the list (traversal match), insertion is skipped and function returns 0. If 116-byte resource node allocation fails, or ShortComputation_53e0 initialization fails, function returns 0. If the file opens successfully and MemoryAllocationWithBufferRead succeeds (reads all data), the file handle is closed and the node is freed (no insertion). Insertion only occurs when MemoryAllocationWithBufferRead returns 0 (failure).
