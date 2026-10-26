## ShortComputation_97f0_004797f0 — ConstructorWithRange_5A5098

**Summary:** Constructor with float range: calls VtableSetWithInitCall with min=0.0f (0), max=0.4f (1051931443), sets vtable to off_5A5098.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5A5098 | vtable pointer for this object type |

**Written-by note (persistence):**
- this 0x0: once per call, set to off_5A5098 (vtable init, overrides VtableSetWithInitCall)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a5098 | off_5A5098 | R | vtable pointer assigned to object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466980 | VtableSetWithInitCall | base constructor with float range params (0.0f, 0.4f) |

**Guard conditions:** none (no branches — unconditional initialization)
