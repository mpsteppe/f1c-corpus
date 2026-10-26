## FunctionCallWrapper_8bc0_00478bc0 — ConstructorWithVTable_5A4970

**Summary:** Constructor: calls sub-constructor (Constructor_e070), zeroes fields at 0xF0 and 0xF8, sets field at 0xF4 to -1 (max/limit), assigns vtable off_5A4970.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5A4970 | vtable pointer for this object type |
| this | 0xF0 | RW | 0 | counter/state field initialized to zero |
| this | 0xF4 | RW | 18446744073709551615 | limit/max field initialized to -1 (all/unlimited) |
| this | 0xF8 | RW | 0 | counter/state field initialized to zero |

**Written-by note (persistence):**
- this 0x0: once per call, set to off_5A4970 (vtable init)
- this 0xF0: once per call, set to 0
- this 0xF4: once per call, set to -1
- this 0xF8: once per call, set to 0

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a4970 | off_5A4970 | R | vtable pointer assigned to object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048e070 | Constructor_e070 | sub-constructor called on this object before field init |

**Guard conditions:** none (no branches — unconditional initialization)
