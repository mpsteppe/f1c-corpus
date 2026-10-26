## StructFieldSetterAt0x4c_00550300 — FieldSetterAt0x4c

**Summary:** Simple inline setter that stores an integer value at this+0x4C and returns it. No guards or side effects.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_546450 (00546450), sub_546AA0 (00546aa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4C | RW | — | Generic integer field set by caller value |

**Written-by note (persistence):**
- this 0x4C: Written unconditionally on every call; external poke always overwritten.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always writes this[19] = a2, no branches.
