## TwoFieldSetters_004dd010 — Two-field setter (scale X and scale Y)

**Summary:** Sets two object fields at offsets +0x30 (this[12]) and +0x34 (this[13]) with provided parameters a2 and a3; returns a2 as the function result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_45B950 (0045b950)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x30 | RW | — | Scale X field (this[12]); updated to a2 each call |
| this | 0x34 | RW | — | Scale Y field (this[13]); updated to a3 each call |

**Written-by note (persistence):**
- this 0x30: written each call to a2; persists until overwritten
- this 0x34: written each call to a3; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — function executes unconditionally.
