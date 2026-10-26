## IntArrayAllocation_00560b60 — IntArrayAllocate

**Summary:** Initialize struct with zero count and allocate integer array of size a2. Stores count=0 at this[0], pointer to allocated array at this[1].

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_560C10 (00560c10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Array element count (initialized to 0) |
| this | 0x4 | RW | — | Pointer to allocated int array |

**Written-by note (persistence):**
- this 0x0: set to 0 on init; modified by callers for count tracking
- this 0x4: set once to allocated array; freed externally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | Allocate memory for int array (4 * a2 bytes) |

**Guard conditions:** None
