## SortedListSeekByValue_004b84f0 — SortedListSeekForwardFromHead

**Summary:** Walks the sorted linked list forward from head, advancing past nodes whose float value <= threshold (this+0xF38). Sets the cursor (this+0x6C8) to the first node exceeding the threshold, and copies its float value back to this+0xF38. Part of sorted list navigation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuActionDispatch (004b9da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x6C0)+0x0) | 0x0 | R | — | head node's float data value |
| *(*(this+0x6C8)+0x0) | 0x0 | R | — | cursor node's float data value (read back to threshold) |
| *(this+0x6C0) | 0x0 | R | — | head node's data pointer |
| *(this+0x6C8) | 0x0 | R | — | cursor node's data pointer |
| *(this+0x6C8) | 0x4 | R | — | cursor node's next pointer (used for forward traversal) |
| this | 0x6C0 | R | — | linked list head pointer |
| this | 0x6C8 | RW | 0 | cursor pointer (updated to seek position) |
| this | 0x6CC | R | — | element count (guard: <=0 skips) |
| this | 0xF38 | RW | — | threshold float key (written with node value at seek position) |

**Written-by note (persistence):**
- this 0x6C8: updated each call; persists as cursor position until next seek
- this 0xF38: overwritten with node's float value at seek position; persists as current threshold

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x6CC | <= | 0 | element count — skip when empty |

**Guard interpretation:** If element count <= 0, returns 0 immediately — list empty, nothing to seek. Otherwise walks forward past nodes with float <= threshold.
