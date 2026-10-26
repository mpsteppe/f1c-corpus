## ShortComputation_6270_00466270 — SetFlagByteF5

**Summary:** Sets flag byte at this+0xF5 to 1 and calls FieldSetterCall with argument 3.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | R | — | pointer passed to FieldSetterCall |
| this | 0xF5 | RW | 1 | flag byte set to 1 (active) |

**Written-by note (persistence):**
- this 0xF5: overwritten to 1 every call. External poke survives (byte field).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004988a0 | FieldSetterCall | set field state on sub-object at this+0x40, param 3 |

**Guard conditions:** None — unconditional.
