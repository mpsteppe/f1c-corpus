## FieldSetterWithVTableDispatch_0048f330 — StateSentinelResetDispatch

**Summary:** Zeroes byte flag at offset 0x17F, sets dword at offset 0x170 to -1 (sentinel), and invokes virtual method at vtable+44 with argument 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | virtual method offset for dispatch |
| this | 0x0 | R | — | vtable pointer |
| this | 0x170 | RW | 18446744073709551615 | sentinel field set to -1 |
| this | 0x17F | RW | 0 | flag byte reset to 0 |

**Written-by note (persistence):**
- this 0x170: set to -1 unconditionally; survives until next write
- this 0x17F: set to 0 unconditionally; survives until next write

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional field assignment and virtual dispatch, no branches.
