## TripleFieldSetter_0040acc6 — Triple Field Setter

**Summary:** Sets three consecutive fields (offsets 0xC, 0x10, 0x14) to the same value a2. Simple bulk-assignment function.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | Field 0 (first of three consecutive slots set to a2) |
| this | 0x10 | RW | — | Field 1 (second of three) |
| this | 0x14 | RW | — | Field 2 (third of three) |

**Written-by note (persistence):**
- this 0xC: Written unconditionally every call. External poke does NOT survive.
- this 0x10: Written unconditionally every call. External poke does NOT survive.
- this 0x14: Written unconditionally every call. External poke does NOT survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — all writes execute unconditionally.
