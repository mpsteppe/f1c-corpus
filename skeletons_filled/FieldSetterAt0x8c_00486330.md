## FieldSetterAt0x8c_00486330 — FieldSetterAt0x8c

**Summary:** Simple inline setter that stores an integer parameter into this+0x8C and returns the value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_486340 (00486340), ObjectRegistration (00499360)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8C | RW | — | integer field written with the passed argument |

**Written-by note (persistence):**
- this 0x8C: unconditional write per call; external writes before next call survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** unconditional — no branches, no null checks. Always writes this[35] = a2.
