## ShortComputation_8090_00468090 — ObjectInitWithVTableAndDefault

**Summary:** Initializes an object by calling sub_466090, setting a vtable pointer, and writing -1 to this[74]. Acts as a simple constructor. Belongs to object initialization system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_59F668) |
| this | 0x128 | RW | 18446744073709551615 | default sentinel value (-1 as unsigned) written to this[74] |

**Written-by note (persistence):**
- this 0x0: set to off_59F668 on every call.
- this 0x128: set to -1 (0xFFFFFFFF) on every call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f668 | off_59F668 | R | vtable pointer assigned to this object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466090 | sub_466090 | performs base initialization of the object |

**Guard conditions:** No guard conditions — unconditional initialization of all fields.
