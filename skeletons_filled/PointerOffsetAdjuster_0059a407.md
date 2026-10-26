## PointerOffsetAdjuster_0059a407 — Buffer pointer putback/ungetc adjustment

**Summary:** Reverses one wide-character read: increments remaining character count (via double-indirect at this+0x2C) and moves buffer position back by 2 bytes (via this+0x1C). Implements putback/ungetc operation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FileOffsetPositionValidation (0059a01e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | RW | — | pointer to buffer position (decremented by 2 on putback) |
| this | 0x2C | R | — | pointer to remaining character count (incremented on putback) |

**Written-by note (persistence):**
- this 0x1C: decremented by 2 each call; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional.
