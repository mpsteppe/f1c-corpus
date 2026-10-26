## ShortComputation_81e0_004781e0 — ObjectInitWithVTable_5A4810

**Summary:** Object initializer: sets vtable to off_5A4810, initializes field at 0xE8 to -1 (max/limit), calls sub-initializer. Constructor variant.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5A4810 | vtable pointer for this object type |
| this | 0xE8 | RW | 18446744073709551615 | limit/max field initialized to -1 (all/unlimited) |

**Written-by note (persistence):**
- this 0x0: once per call, set to off_5A4810 (vtable init)
- this 0xE8: once per call, set to -1

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a4810 | off_5A4810 | R | vtable pointer assigned to object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048fb70 | ShortComputation_fb70 | sub-initializer called on this object before field init |

**Guard conditions:** none (no branches — unconditional initialization)
