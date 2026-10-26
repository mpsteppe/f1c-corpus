## ShortComputation_8690_00478690 — ConditionalSubObjectSelector

**Summary:** Conditional branch based on this[78] (flag at offset 0x138): if set, calls vtable method at +60 with arg 1 and returns pointer to sub-object (this+70); if clear, calls vtable method with arg 0 and returns null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3C | R | — | unknown field read from sub-object |
| this | 0x0 | R | — | vtable pointer (method at +60 called) |
| this | 0x138 | R | — | boolean flag controlling which branch to take |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks this[78] (offset 0x138): if truthy, enable sub-object path (passes); if zero, disable path (blocks).
