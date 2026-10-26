## LinkedBufferTransfer_004b5f60 — Doubly-Linked Buffer Transfer

**Summary:** Iterates a doubly-linked source list at this+0x714, removing each node and its data pointer, then reinitializing the data via SmallStructZeroInit and relinking into a singly-linked output list at this+0x30. Frees source node wrappers and creates new 12-byte wrappers for the output.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestroyUIWidgetHierarchy (004b5a30), ModelSceneFileLoader (004b6c90), BufferPoolAllocatorInitialization (004b71e0), GameDataFileIO (004b7300), sub_4B7500 (004b7500)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x718)+0x4) | 0x8 | RW | — | Node prev pointer (adjusted when node before tail removed) |
| *(*(this+0x718)+0x8) | 0x4 | RW | — | Node next pointer (adjusted when previous node removed) |
| *(this+0x718) | 0x0 | R | — | Node data pointer (freed if flag at +12 set) |
| *(this+0x718) | 0x4 | R | — | Node next link |
| *(this+0x718) | 0x8 | R | — | Node prev link |
| *(this+0x718) | 0xC | R | — | Node flag byte (if set, free data before freeing node) |
| this | 0x30 | RW | — | Output list head (prepended with new nodes) |
| this | 0x34 | RW | — | Output list tail (set on first insertion) |
| this | 0x38 | RW | — | Output list current/temp pointer |
| this | 0x3C | RW | — | Output list count (incremented per node) |
| this | 0x714 | RW | — | Source doubly-linked list head (adjusted on removal) |
| this | 0x718 | RW | — | Source list tail (adjusted when tail removed) |
| this | 0x71C | RW | — | Source list current/temp walk pointer |
| this | 0x720 | R | — | Source list count (decremented per removal) |

**Written-by note (persistence):**
- *(*(this+0x718)+0x4) 0x8: Tail node's next->prev updated when tail removed; persists.
- *(*(this+0x718)+0x8) 0x4: Non-tail prev node's next updated; persists.
- this 0x30: Prepend new node per iteration; persists.
- this 0x34: Written once for first new node; persists.
- this 0x38: Updated per new node; per-call.
- this 0x3C: Incremented per new node; persists.
- this 0x714: Updated as head nodes removed; persists.
- this 0x718: Updated when tail node removed; persists.
- this 0x71C: Updated as current pointer moves; per-call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b4460 | SmallStructZeroInit | Zero-initialize/reinitialize data structure |
| 00587bcf | FreeWrapper_7bcf | Free node data payload or node wrapper |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate 12-byte wrapper nodes for output list |

**Guard conditions:** If this+0x714 (source doubly-linked list head) is NULL, return immediately — no nodes to transfer. Each source node: if flag byte at +12 is non-zero, free the data pointer at +0 before freeing node wrapper.
