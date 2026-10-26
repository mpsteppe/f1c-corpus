## PointerAdjustment_0059a3f3 — Buffer pointer adjustment after read/write

**Summary:** After reading or writing `a2` wide characters, decrements remaining character count (via double-indirect pointer at this+0x2C) and advances buffer position (via double-indirect pointer at this+0x1C) by 2*a2 bytes.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StreamCharReaderWithBufferFillGetcFallback (00599d52)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x0 | RW | — | current buffer position (advanced by 2*a2 bytes) |
| *(this+0x2C) | 0x0 | RW | — | remaining character count (decremented by a2) |
| this | 0x1C | R | — | pointer to buffer position variable |
| this | 0x2C | R | — | pointer to remaining count variable |

**Written-by note (persistence):**
- *(this+0x1C) 0x0: updated each call; persists until overwritten
- *(this+0x2C) 0x0: updated each call; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional.
