## BoundedIndexSetter_0040ad90 — Bounded Index Setter

**Summary:** Sets this[5] (offset 0x14) to a2 only if 0 <= a2 < this[4] (the upper bound). Returns a2 unchanged.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LookupWithOptionalCallback (0040b450)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | Upper bound for index validation |
| this | 0x14 | RW | — | Index field (set to a2 when within bounds) |

**Written-by note (persistence):**
- this 0x14: Written conditionally (only when 0 <= a2 < this[4]). External poke survives when condition fails (out-of-bounds a2).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 must be >= 0 AND a2 < this[4] (offset 0x10) for the write to this+0x14 to execute. If either condition fails, no write occurs.
