## AccumulatorWithFixedArray_004bbed0 — AccumulateByteValueWithFixedArray

**Summary:** Accumulates byte values from input object into fixed-size 4-slot array; when fewer than 4 entries exist stores new entry (type=3, value=byte), when 4+ entries adds byte to existing slot's value field. Called by sub_4B3400 for pit/event accumulation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | pointer to parent/container object (used to access comparison target at container+13004) |
| this | 0x3C | R | — | entry count for the fixed-size accumulator array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — no early return or branch that blocks execution; always processes input
