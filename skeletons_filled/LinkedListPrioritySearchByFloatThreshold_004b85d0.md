## LinkedListPrioritySearchByFloatThreshold_004b85d0 — SortedListSeekBackwardFromTail

**Summary:** Walks the sorted linked list backward from the tail, seeking the last node whose float value is within a threshold window (reference - 2.0). Sets cursor to that node and reads its float back to the threshold field. Part of priority-based sorted list navigation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuActionDispatch (004b9da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x6C8)+0x0) | 0x0 | R | — | cursor node's float data value |
| *(this+0x6C4) | 0x0 | R | — | tail node's data pointer |
| *(this+0x6C8) | 0x0 | R | — | cursor node's data pointer |
| *(this+0x6C8) | 0x4 | R | — | cursor node's next pointer |
| *(this+0x6C8) | 0x8 | R | — | cursor node's prev pointer (used for backward traversal) |
| this | 0x6C0 | R | — | linked list head pointer |
| this | 0x6C4 | R | — | linked list tail pointer (starting point for backward walk) |
| this | 0x6C8 | RW | 0 | cursor pointer (updated to seek position) |
| this | 0x6CC | R | — | element count (guard: <=0 skips) |
| this | 0xF38 | RW | — | threshold float key (written with node value at seek position) |

**Written-by note (persistence):**
- this 0x6C8: updated each call; persists as cursor position until next seek
- this 0xF38: overwritten with node's float value at seek position; persists as current threshold

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acd20 | flt_5ACD20 | R | SilenceClippingThreshold [DERIVED] (also: ` — search epsilon tolerance) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If element count <= 0, returns 0 immediately. If tail pointer or its data pointer is null, goes to fallback forward walk from head. Walks backward while (threshold - 2.0) <= node_float; stops at first node below threshold.
