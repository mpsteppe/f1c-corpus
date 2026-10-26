## BoundsCheckedIndexSetter_0048d380 — BoundsCheckedSelectedIndexSetter

**Summary:** Sets the selected index (at this+0x338) with bounds checking against the list count (at this+0x328). The new index is only written if 0 <= a2 < count.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x328 | R | — | Item count (upper bound for index) |
| this | 0x338 | RW | — | Currently selected index (written if bounds check passes) |

**Written-by note (persistence):**
- this 0x338: conditional on bounds check; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** PASS: a2 >= 0 AND a2 < this[202] (count at 0x328). BLOCKED: a2 < 0 OR a2 >= count.
