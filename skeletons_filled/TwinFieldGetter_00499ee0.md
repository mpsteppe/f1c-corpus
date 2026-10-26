## TwinFieldGetter_00499ee0 — TwinFieldGetter

**Summary:** Reads the two fields at offsets 0x60 and 0x64 and stores them into output pointers `a2` and `a3` respectively. Returns the value of field 0x64.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalMultiParamDispatch (004861a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | R | — | field value copied to *a2 |
| this | 0x64 | R | — | field value copied to *a3 and returned |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — straight-line reads and writes.
