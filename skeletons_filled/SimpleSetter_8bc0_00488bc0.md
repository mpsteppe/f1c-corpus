## SimpleSetter_8bc0_00488bc0 — ScrollOffsetWriter

**Summary:** Stores parameter a2 into offset 0xE0 (scroll delta). Direct setter with no guards.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConstructorDualSubInit (0048d660)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE0 | RW | — | Scroll offset / delta value field |

**Written-by note (persistence):**
- this 0xE0: Written unconditionally every call with parameter value. Not persistent.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional setter.
