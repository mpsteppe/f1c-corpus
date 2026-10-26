## F_4FieldSetter_0048ea40 — QuadFieldSetter

**Summary:** Stores four input parameters into struct fields at offsets 0x1C, 0x20, 0x24, and 0x28 with argument reordering (a4→0x1C, a5→0x20, a2→0x24, a3→0x28). Returns the first parameter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | RW | — | padding / margin value (fourth param) |
| this | 0x20 | RW | — | padding / margin value (fifth param) |
| this | 0x24 | RW | — | x position / dimension (second param) |
| this | 0x28 | RW | — | y position / dimension (third param) |

**Written-by note (persistence):**
- this 0x1C: set unconditionally; survives until next call
- this 0x20: set unconditionally; survives until next call
- this 0x24: set unconditionally; survives until next call
- this 0x28: set unconditionally; survives until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional field assignment with no branches.
