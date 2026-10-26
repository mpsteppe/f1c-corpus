## DoubleIndirectCounterUpdate_0059a428 — Write buffer pointer adjustment after write

**Summary:** After writing `a2` wide characters to write buffer, decrements remaining space (via double-indirect pointer at this+0x30) and advances buffer position (via double-indirect pointer at this+0x20) by 2*a2 bytes.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_599DD9 (00599dd9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x0 | RW | — | write buffer current position (advanced by 2*a2 bytes) |
| *(this+0x30) | 0x0 | RW | — | remaining write buffer space (decremented by a2) |
| this | 0x20 | R | — | pointer to write buffer position variable |
| this | 0x30 | R | — | pointer to remaining space variable |

**Written-by note (persistence):**
- *(this+0x20) 0x0: updated each call; persists until overwritten
- *(this+0x30) 0x0: updated each call; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional.
