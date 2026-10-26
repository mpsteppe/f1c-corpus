## ShortGetterCopy_004b1fb0 — Short copy from +0x16 to +0x14

**Summary:** Simple short copy: reads short from this+0x16, writes it to this+0x14, returns the short value. No branches or guards.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | — | Destination short — receives value from +0x16 |
| this | 0x16 | R | — | Source short — copied to +0x14 |

**Written-by note (persistence):**
- this 0x14: written unconditionally with value from +0x16; overwrites previous value

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional short copy with no branches.
