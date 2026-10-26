## ConditionalSetter0x30_004980c0 — Conditional Field Setter (offset 0x30)

**Summary:** Conditionally stores a non-zero value into `this[12]` (offset 0x30) and returns the value. Skipped entirely when the input is zero/NULL.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_492160 (00492160)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x30 | RW | — | Field conditionally set when parameter a2 is non-zero (likely a pointer or handle) |

**Written-by note (persistence):**
- this 0x30: Written once per call when a2 != 0; persists until overwritten by another non-zero value. Zero/NULL input leaves field unchanged.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**
- `a2 == 0` → skip write, return 0 (BLOCKED: null/zero value, field unchanged)
- `a2 != 0` → write a2 to `this[12]` (PASSES: store the non-zero value)
