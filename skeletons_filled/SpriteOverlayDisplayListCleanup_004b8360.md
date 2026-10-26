## SpriteOverlayDisplayListCleanup_004b8360 — DisplayListNodeRemoveByFloatKey

**Summary:** Walks a sorted doubly-linked overlay display list and removes the first node whose float value matches a reference key within epsilon (2.0). Frees both the node frame and its inner data if the byte flag is set. Part of overlay/sprite display list management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SortedLinkedListInsert (004b81a0), MenuActionDispatch (004b9da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x6C0)+0x0) | 0x0 | R | — | inner data struct (contains float key at offset 0) |
| *(*(this+0x6C0)+0x4) | 0x4 | R | — | inner data string pointer (freed if byte flag set) |
| *(this+0x6C0) | 0x0 | R | — | node's inner data pointer |
| *(this+0x6C0) | 0x4 | R | — | node's next pointer |
| *(this+0x6C0) | 0x8 | R | — | node's prev pointer |
| *(this+0x6C0) | 0xC | R | — | byte flag indicating if inner data should be freed |
| *(this+0x6C0) | 0x10 | RW | — | unknown field beyond 16-byte node frame |
| *(this+0x6C8) | 0x0 | R | — | cursor node's data pointer |
| *(this+0x6C8) | 0x4 | R | — | cursor node's next pointer |
| this | 0x6C0 | RW | — | linked list head pointer |
| this | 0x6C4 | RW | — | linked list tail pointer |
| this | 0x6C8 | RW | — | search cursor during cleanup traversal |
| this | 0x6CC | R | — | element count |
| this | 0x6D0 | RW | 1 | dirty/sorted flag (set to 1 after removal) |
| this | 0xF38 | R | — | reference float key to match for removal |

**Written-by note (persistence):**
- *(this+0x6C0) 0x10: set during node relocation; survives as long as node exists
- this 0x6C0: updated if removed node was head; persists across calls
- this 0x6C4: updated if removed node was tail; persists across calls
- this 0x6C8: updated each call during traversal; overwritten next call
- this 0x6D0: set to 1 each call; persists as sorted flag

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acd20 | flt_5ACD20 | R | SilenceClippingThreshold [DERIVED] (also: ` — search epsilon tolerance) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees inner data and node frame |

**Guard conditions:** If head pointer (this+0x6C0) is null or inner data pointer is null, returns 1 immediately — empty list. Nodes with float value > reference + 2.0 cause early return 1 (past sorted range). Nodes with float value < reference - 2.0 are skipped (cursor advances). Only nodes within epsilon 2.0 of reference are removed.
