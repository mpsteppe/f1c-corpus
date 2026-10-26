## BoundedArrayAccessor_0042dc80 — BoundedArrayAccessor

**Summary:** Bounds-checked array lookup. Returns element from 8-byte stride array at given index, or 0 if index out of range.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleSetupValueFormatter (0042f470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Array element count (upper bound) |
| this | 0x4 | R | — | Pointer to array data (8-byte stride elements) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Guard: a2 < 0 OR a2 >= this[0] (count) → BLOCKED (returns 0). Index in range [0, count) → PASSES (returns element at base + 8*index).
