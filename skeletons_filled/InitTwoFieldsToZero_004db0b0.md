## InitTwoFieldsToZero_004db0b0 — TwoFieldZeroInitializer

**Summary:** Zeros two integer fields at offsets 0x10 and 0x14 of the object. Likely a sub-object initializer or reset function.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | 0 | Counter/index field, cleared on init/reset |
| this | 0x14 | RW | 0 | Counter/index field, cleared on init/reset |

**Written-by note (persistence):**
- this 0x10: Written unconditionally to 0; persists until explicitly changed
- this 0x14: Written unconditionally to 0; persists until explicitly changed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — both writes unconditional.
