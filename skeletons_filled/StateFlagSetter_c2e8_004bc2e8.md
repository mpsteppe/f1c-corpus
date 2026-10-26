## StateFlagSetter_c2e8_004bc2e8 — SetStateToOne

**Summary:** Sets single state field at this+0x60 to value 1. Unconditional setter with no parameters beyond this pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | RW | 1 | state/mode field (set to 1) |

**Written-by note (persistence):**
- this 0x60: written unconditionally to 1; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional set
