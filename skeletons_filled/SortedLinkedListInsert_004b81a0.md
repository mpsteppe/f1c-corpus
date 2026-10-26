## SortedLinkedListInsert_004b81a0 — SortedLinkedListInsertByFloatKey

**Summary:** Allocates a new linked-list node with a float key from this+0xF38, appends it to the list, then performs a mergesort on the entire list by float value. Marks the list as sorted (dirty flag=1). Part of a display/overlay list system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuActionDispatch (004b9da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x6C0)+0x4)+0x4) | 0x4 | R | — | third node's next link (followed during merge) |
| *(*(*(this+0x6C0)+0x4)+0x4) | 0x8 | RW | — | third node's prev link (rewritten during re-link) |
| *(*(this+0x6C0)+0x4) | 0x4 | RW | 0 | second node's next link (rewritten during merge) |
| *(this+0x6C0) | 0x4 | R | — | first (head) node's next pointer |
| *(this+0x6C0) | 0x8 | RW | — | first (head) node's prev pointer (rewritten during re-link) |
| this | 0x6C0 | RW | — | linked list head pointer |
| this | 0x6C4 | RW | — | linked list tail pointer |
| this | 0x6C8 | RW | — | last node in traversal / end-of-list pointer |
| this | 0x6CC | R | — | element count (incremented on insert) |
| this | 0x6D0 | RW | 1 | sorted/dirty flag (set to 1 after sort) |
| this | 0xF38 | R | — | float sort key value |

**Written-by note (persistence):**
- *(*(*(this+0x6C0)+0x4)+0x4) 0x8: set during relink after merge sort; survives as long as list exists
- *(*(this+0x6C0)+0x4) 0x4: set during merge; survives as list ordering
- *(this+0x6C0) 0x8: set during relink; survives as list structure
- this 0x6C0: set once per call (head pointer); persists across calls
- this 0x6C4: set once per call (tail pointer); persists across calls
- this 0x6C8: set once per call (end pointer); persists across calls
- this 0x6D0: set to 1 each call; persists as sorted flag

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b8360 | SpriteOverlayDisplayListCleanup | clears overlay display list state before insert |
| 004bb2e0 | MergeSort_b2e0 | mergesort linked list by node float value |
| 00566650 | StringCopyWithBufferRealloc | copies string argument into node with reallocation |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 12-byte data node and 16-byte list frame |
| 0058815f | StringFormatWithBufferOverflowCheck | formats element count string for label |

**Guard conditions:** If a2 is NULL or strlen(a2)==0, generates default label from element count+1. If memory allocation fails (v4=NULL), entire insert is skipped (v5=0). If head is null after insert, skips mergesort entirely.
