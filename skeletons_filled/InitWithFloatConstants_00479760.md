## InitWithFloatConstants_00479760 — InitWithFloatConstants

**Summary:** Constructor with float range: calls VtableSetWithInitCall with min=0.5f (1056964608), max=1.0f (1065353216), sets vtable to off_5A4E70.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5A4E70 | vtable pointer for this object type |

**Written-by note (persistence):**
- this 0x0: once per call, set to off_5A4E70 (vtable init, overrides VtableSetWithInitCall)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a4e70 | off_5A4E70 | R | vtable pointer assigned to object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466980 | VtableSetWithInitCall | base constructor with float range params (0.5f, 1.0f) |

**Guard conditions:** none (no branches — unconditional initialization)
