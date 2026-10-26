## ConstructorWithRangeInitAndVTable_00479790 — ConstructorWithRangeInitAndVTable

**Summary:** Constructor with symmetric range: calls VtableSetWithInitCall with min=-1.0f (-1082130432), max=1.0f (1065353216), sets vtable to off_5A4F28.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5A4F28 | vtable pointer for this object type |

**Written-by note (persistence):**
- this 0x0: once per call, set to off_5A4F28 (vtable init, overrides VtableSetWithInitCall)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a4f28 | off_5A4F28 | R | vtable pointer assigned to object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466980 | VtableSetWithInitCall | base constructor with float range params (-1.0f, 1.0f) |

**Guard conditions:** none (no branches — unconditional initialization)
