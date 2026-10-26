## BufferPointerAdjust_00501711 — BufferReadPointerAdvance

**Summary:** Advances a buffer read pointer by `a2` bytes and decreases the remaining byte count by `a2`. Classic buffer read tracking structure update.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x0 | RW | — | Current buffer read position (pointer/offset, incremented by a2) |
| *(this+0x14) | 0x4 | RW | — | Remaining byte count (decremented by a2) |
| this | 0x14 | R | — | Pointer to buffer tracking struct |

**Written-by note (persistence):**
- *(this+0x14) 0x0: Written each call — advanced by a2; persists until next advance
- *(this+0x14) 0x4: Written each call — reduced by a2; persists until next advance

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None. Always advances pointer and decrements remaining count.
