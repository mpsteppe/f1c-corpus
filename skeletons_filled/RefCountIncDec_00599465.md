## RefCountIncDec_00599465 — BufferPositionIncDec

**Summary:** Adjusts buffer position counters: increments value at this+0x2C (remaining/available count) and decrements value at this+0x1C (read pointer offset). Returns decremented value. Used for putback operation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CharValidationAgainstEncodingTableWithLocaleFall (00598fd4)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | pointer to read position offset — decremented (putback) |
| this | 0x2C | R | — | pointer to remaining/available count — incremented (putback) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional increment and decrement.
