## ByteFieldSetter_004888f0 — ByteFieldStorer

**Summary:** Stores a byte parameter into offset 0xEC of the UI widget and returns it. Likely sets a boolean/visibility flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xEC | RW | — | Boolean/flag field for widget state (e.g., active/enabled) |

**Written-by note (persistence):**
- this 0xEC: Written unconditionally every call with caller-provided value. Not persistent.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no conditional logic.
