## SimpleSetter_79e0_004979e0 — ClearFieldAtOffset20

**Summary:** Sets field at offset 0x20 (this[8]) to 0. Simple reset/clear function for the same field that Setter_004979c0 writes to.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIWidgetVisibilityToggle (0048b91a)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | RW | 0 | Cleared to 0 — resetting a state/flag |

**Written-by note (persistence):**
- this 0x20: Written unconditionally to 0 each call. External poke does not survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — writes field and returns unconditionally.
