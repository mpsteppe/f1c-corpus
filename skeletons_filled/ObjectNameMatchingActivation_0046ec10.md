## ObjectNameMatchingActivation_0046ec10 — Object name matching activation

**Summary:** Compares input string against a global string reference; if match, activates object via vtable callback at offset 44 (param 1) and sets field at 0x174 to 1; otherwise resets field to 0. Object activation gated by name matching.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | vtable offset 44 — callback invoked with param 1 on successful name match |
| this | 0x0 | R | — | vtable pointer |
| this | 0x174 | RW | 0 | byte flag — set to 1 on match (activated), 0 on no match (deactivated) |

**Written-by note (persistence):**
- this 0x174: conditional — set to 1 or 0 each time function is called; persists until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c666c | off_5C666C | R | reference string array — first element compared against input a2 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No entry guard. If strcmp(off_5C666C[0], a2) == 0 (match, PASSES): sets flag=1, calls vtable callback offset 44 with param 1, returns 1. If no match (BLOCKED): sets flag=0, returns 0, skips callback.
