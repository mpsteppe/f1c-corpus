## sub_48BEA0_0048bea0 — set flag byte at this+0x11C to 1

**Summary:** One-line setter that writes 1 to the byte at this+0x11C and returns 0. Likely enables a boolean state/mode flag.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x11C | RW | 1 | Boolean flag byte set to 1 (enabled state) |

**Written-by note (persistence):**
- this 0x11C: written unconditionally to 1 on each call — an external poke set to 0 survives until this setter runs again.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None. Always writes 1 and returns 0.
