## DoublyLinkedListAppend_00434030 — DoublyLinkedListAppend

**Summary:** Appends a new node to a singly-linked list with head/tail tracking. Allocates 12-byte node, sets data pointer and flag, updates head/tail/first/count.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NameListBuilderFromVehicleArray (004159b0), DirectoryFileEnumerator (00431db0), NetCommSessionMessageDispatcher (0045d890), ResourcePoolNodeAllocDealloc (00490940), CollisionBroadphaseBuilder (00490ee0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | pHead: list head pointer (written only on first append) |
| this | 0x4 | RW | — | pTail: list tail pointer (written every append) |
| this | 0x8 | RW | — | pFirst: first node reference (written on first append only) |
| this | 0xC | R | — | nCount: entry count (incremented each append) |

**Written-by note (persistence):**
- this 0x0: written once on first node insertion only. Survives.
- this 0x4: written every insertion. Last write is final tail. Survives.
- this 0x8: written once on first node insertion. Survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | allocate 12-byte node (4 data + 4 next + 1 flag + padding) |

**Guard conditions:** If `a2` (data pointer) is null, function returns 0 immediately without allocation. Node allocation via OperatorNewNhMallocWrapper: if returns null (allocation failure), node pointer is set to 0 and append still proceeds (appends null node). Head pointer `*this` check determines whether to link new node after tail or set as first node.
