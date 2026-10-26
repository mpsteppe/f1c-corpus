## BitFlagSetter_2319_00512319 — Set bit 0 on flags DWORD

**Summary:** Sets the lowest bit (0x1) on a flags DWORD at offset 0x60 unconditionally.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_50210E (0050210e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | RW | — | flags DWORD; bit 0 set by this function |

**Written-by note (persistence):**
- this 0x60: OR-write sets bit 0 each call; persists until cleared by another writer

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional bit-set.
