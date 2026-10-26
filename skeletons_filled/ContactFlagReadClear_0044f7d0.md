## ContactFlagReadClear_0044f7d0 — Read and clear contact flag

**Summary:** Atomically reads the contact flag value at offset 0xBC (this[47]), then clears (zeroes) it. Returns the prior flag value. Called during viewport initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** InitViewportDimensions (00498740)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xBC | RW | 0 | Contact event flag — read and clear each check |

**Written-by note (persistence):**
- this 0xBC: read then zeroed unconditionally each call; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — single unconditional read-and-clear
