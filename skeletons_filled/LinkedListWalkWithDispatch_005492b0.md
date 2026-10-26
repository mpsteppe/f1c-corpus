## LinkedListWalkWithDispatch_005492b0 — Walk linked list and dispatch found entries to buffer

**Summary:** Walks linked list starting at this+0xF0 via next pointer at node+0x34. For each node, looks up string (at node data base + 0x58) via sub_5456B0; if found, removes entry from source doubly linked list and inserts into byte buffer via LinkedListByteBufferInsert. Part of audio engine initialization/dispatch system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioEngineInitialization (00546010)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Manager context handle passed to list operations and lookup |
| this | 0xF0 | R | — | Head pointer of linked list being walked |
| this | 0x124 | R | — | Byte buffer list state modified by LinkedListByteBufferInsert |
| this | 0x158 | R | — | Byte buffer list state modified by LinkedListByteBufferInsert |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005455f0 | DoublyLinkedListRemove | Remove entry from source doubly linked list after lookup match |
| 005456b0 | sub_5456B0 | Look up string in dispatch table; returns entry pointer or null |
| 00549250 | LinkedListByteBufferInsert | Append matched entry to byte buffer list for further processing |

**Guard conditions:** No early-exit guard — loop always walks full list from head (this+0xF0) following node+0x34 next pointers until null. Inner `if (v3)` BLOCKS remove+insert when sub_5456B0 returns null (string not found in dispatch table). Only matched entries are removed from source list and inserted into byte buffer.
