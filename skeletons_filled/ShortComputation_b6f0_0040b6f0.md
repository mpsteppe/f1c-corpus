## ShortComputation_b6f0_0040b6f0 — Bounded Index Setter With Callback

**Summary:** If 0 <= a2 < this[4] (offset 0x10), sets this[5] (offset 0x14) = a2 and calls virtual callback at vtable+16. Returns a2.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceLookupWithOptionalVTableDispatch (0040bcd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x10 | R | — | Bound field (this forwarded as obj for consistency) |
| this | 0x0 | R | — | Vtable pointer (calls vtable+16 for callback) |
| this | 0x10 | R | — | Upper bound for index validation |
| this | 0x14 | RW | — | Index field (set to a2 when within bounds) |

**Written-by note (persistence):**
- this 0x14: Written conditionally (only when 0 <= a2 < this[4]). External poke survives when condition fails.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 must be >= 0 AND a2 < this[4] (offset 0x10) for index write and vtable callback to execute. If either condition fails, function returns a2 unchanged.
